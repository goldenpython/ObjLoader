/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

#include "SimpleMesh.h"

CString CSimpleMesh::sDelimiters(" \t\n/");

CSimpleMesh::CSimpleMesh(CDisplayDevice *device) {
	m_poDisplayDevice = device;

	m_poIB = NULL;
	m_poVB = NULL;
}

CSimpleMesh::~CSimpleMesh() {
	DELETE_OBJECT(m_poVB);
	DELETE_OBJECT(m_poIB);

	FreeTexureArray();
}

bool CSimpleMesh::LoadMaterials(CString szFileName) {
	TArray<CString> m_oTextureNames;

	FILE *file = fopen(szFileName, "rt");
	if (!file)
		return false;

	char szLine[MAX_LINE_LEN];
	CString *ppsTokens;
	int iNumTokens;
	int iNumMaterials = 0;
	while (fgets(szLine, MAX_LINE_LEN, file)) {
		CString sLine(szLine);
		sLine.ToUpper();

		if (sLine.StartsWith("NEWMTL")) {
			CMaterial oMaterial;
			m_oMaterials.Append(oMaterial);

			sLine.Tokenize(&ppsTokens, &iNumTokens, sDelimiters);
			m_oMaterialNames.Append(ppsTokens[1]);
			SAFE_DELETE_ARRAY(ppsTokens);
			iNumMaterials++;

			//m_oTextureNames.Append(NULL);
			m_oMaterialsTextureIndex.Append(NO_TEXTURE);
		} else if (sLine.StartsWith("KA")) {
			sLine.Tokenize(&ppsTokens, &iNumTokens, sDelimiters);
			CMaterial *oMaterial = &m_oMaterials[m_oMaterials.GetSize() - 1];
			CColor *poColor = oMaterial->GetAmbientColor();
			poColor->red = ppsTokens[1].ToFloat();
			poColor->green = ppsTokens[2].ToFloat();
			poColor->blue = ppsTokens[3].ToFloat();

			SAFE_DELETE_ARRAY(ppsTokens);
		} else if (sLine.StartsWith("KD")) {
			sLine.Tokenize(&ppsTokens, &iNumTokens, sDelimiters);
			CMaterial *oMaterial = &m_oMaterials[m_oMaterials.GetSize() - 1];
			CColor *poColor = oMaterial->GetDiffuseColor();
			poColor->red = ppsTokens[1].ToFloat();
			poColor->green = ppsTokens[2].ToFloat();
			poColor->blue = ppsTokens[3].ToFloat();

			SAFE_DELETE_ARRAY(ppsTokens);
		} else if (sLine.StartsWith("KS")) {
			sLine.Tokenize(&ppsTokens, &iNumTokens, sDelimiters);
			CMaterial *oMaterial = &m_oMaterials[m_oMaterials.GetSize() - 1];
			CColor *poColor = oMaterial->GetSpecularColor();
			poColor->red = ppsTokens[1].ToFloat();
			poColor->green = ppsTokens[2].ToFloat();
			poColor->blue = ppsTokens[3].ToFloat();

			SAFE_DELETE_ARRAY(ppsTokens);
		} else if (sLine.StartsWith("NS")) {
			sLine.Tokenize(&ppsTokens, &iNumTokens, sDelimiters);
			CMaterial *oMaterial = &m_oMaterials[m_oMaterials.GetSize() - 1];

			oMaterial->SetPower(ppsTokens[1].ToFloat());

			SAFE_DELETE_ARRAY(ppsTokens);
		} else if (sLine.StartsWith("MAP_KD") || sLine.StartsWith("MAP_KA")) {
			sLine.Tokenize(&ppsTokens, &iNumTokens, sDelimiters);
			CString sTextureName(ppsTokens[1].StartsWith(".\\") ? ppsTokens[1].GetBuffer() + 2 : ppsTokens[1]);

			int index = m_oTextureNames.Find(sTextureName);

			if (index == -1) {
				m_oTextureNames.Append(sTextureName);
				m_oMaterialsTextureIndex[m_oMaterials.GetSize() - 1] = m_oTextureNames.GetSize() - 1;
			} else {
				m_oMaterialsTextureIndex[m_oMaterials.GetSize() - 1] = index;
			}

			SAFE_DELETE_ARRAY(ppsTokens);
		}
	}

	fclose(file);

	for (int i = 0; i < m_oTextureNames.GetSize(); i++)
		m_oTextures.Append(new CTexture(m_poDisplayDevice, m_oTextureNames[i].GetBuffer()));

	return true;
}

#ifdef USE_HASHTABLE_FOR_VE6RTEX_SEARCH
int GetKey(FACE_STRUCT v) {
	int key = (v.NormalIndex + v.TextureIndex + v.VertexIndex) % NUM_KEYS;
	return key;
}
#endif //USE_HASHTABLE_FOR_VERTEX_SEARCH

bool CSimpleMesh::LoadFromObjFile(char *szFileName) {
	TArray<VECTOR3Df> m_oVertexArray;
	TArray<VECTOR3Df> m_oNormalArray;
	TArray<VECTOR2Df> m_oTextureCoordArray;

	m_oMaterials.RemoveAll();
	m_oMaterialNames.RemoveAll();

	m_oSubsetsStartIndex.RemoveAll();
	m_oSubsetsMaterialIndex.RemoveAll();

	FreeTexureArray();
	m_oMaterialsTextureIndex.RemoveAll();

	TArray<FACE_STRUCT> oFaceBuffer;

#ifdef USE_HASHTABLE_FOR_VERTEX_SEARCH
	THashTable<FACE_STRUCT> oFaceHash(NUM_KEYS, FACE_STRUCT::GetKey);
#endif //USE_HASHTABLE_FOR_VERTEX_SEARCH

	TArray<unsigned short> oIndexBuffer;

	DELETE_OBJECT(m_poVB);
	DELETE_OBJECT(m_poIB);

	FILE *file = fopen(szFileName, "rt");
	if (!file)
		return false;

	char szLine[MAX_LINE_LEN];
	CString *ppsTokens;
	int iNumTokens;
	int iNumIndexes = 0;

	while (fgets(szLine, MAX_LINE_LEN, file)) {
		CString sLine(szLine);
		sLine.ToUpper();

		sLine.Tokenize(&ppsTokens, &iNumTokens, sDelimiters);

		if (iNumTokens == 0)
			continue;

		if (ppsTokens[0].Equals("MTLLIB")) {
			LoadMaterials(ppsTokens[1]);
		} else if (ppsTokens[0].Equals("VN")) {
			m_oNormalArray.Append(VECTOR3Df(ppsTokens[1].ToFloat(), ppsTokens[2].ToFloat(), ppsTokens[3].ToFloat()));
		} else if (ppsTokens[0].Equals("VT")) {
			m_oTextureCoordArray.Append(VECTOR2Df(ppsTokens[1].ToFloat(), ppsTokens[2].ToFloat()));
		} else if (ppsTokens[0].Equals("V")) {
			m_oVertexArray.Append(VECTOR3Df(ppsTokens[1].ToFloat(), ppsTokens[2].ToFloat(), ppsTokens[3].ToFloat()));
		} else if (ppsTokens[0].Equals("USEMTL")) {
			int iMaterialIndex = m_oMaterialNames.Find(ppsTokens[1]);
			m_oSubsetsMaterialIndex.Append(iMaterialIndex);
			m_oSubsetsStartIndex.Append(oIndexBuffer.GetSize());
		} else if (ppsTokens[0].Equals("F")) {
			struct FACE_STRUCT face;

			for (int i = 0; i < 3; i++) {
				face.iVertexIndex = ppsTokens[i * 3 + 1].ToInt() - 1;
				face.iTextureIndex = ppsTokens[i * 3 + 2].ToInt() - 1;
				face.iNormalIndex = ppsTokens[i * 3 + 3].ToInt() - 1;

#ifndef USE_HASHTABLE_FOR_VERTEX_SEARCH
				int index = oFaceBuffer.Find(face);
				if (index == -1) {
					oIndexBuffer.Append(oFaceBuffer.GetSize());
					oFaceBuffer.Append(face);
				} else {
					oIndexBuffer.Append(index);
				} 
#else
				FACE_STRUCT *found = oFaceHash.Find(face);
				if (found) {
					int index = found->iIndex;

					oIndexBuffer.Append(index);
				} else {
					face.iIndex = iNumIndexes++;
					oFaceHash.Insert(face);

					oIndexBuffer.Append(oFaceBuffer.GetSize());
					oFaceBuffer.Append(face);
				} 
#endif //USE_HASHTABLE_FOR_VERTEX_SEARCH
			}
		}

		SAFE_DELETE_ARRAY(ppsTokens);
	}


	m_oSubsetsStartIndex.Append(oIndexBuffer.GetSize());

	fclose(file);

	m_poIB = new CIndexBuffer(oIndexBuffer.GetSize());
	memcpy(m_poIB->GetIndexBuffer(), &oIndexBuffer[0], oIndexBuffer.GetSize() * sizeof(unsigned short));

	m_bHasTextures = m_oTextures.GetSize() > 0;
	m_bHasMaterials = m_oMaterials.GetSize() > 0;
	int iFormat = VERTEXFORMAT_XYZ | VERTEXFORMAT_NORMAL | (m_bHasTextures ? VERTEXFORMAT_TEXTURE : 0);

	m_poVB = new CVertexBuffer(iFormat, oFaceBuffer.GetSize());
	int iIndex = 0, iNumVertex = oFaceBuffer.GetSize();
	for (int i = 0; i < iNumVertex; i++) {
		float *pVertex = (float *)m_poVB->GetVertexAtIndex(i);

		memcpy(pVertex, &m_oVertexArray[oFaceBuffer[i].iVertexIndex], 3 * sizeof(float));
		memcpy(pVertex + 3, &m_oNormalArray[oFaceBuffer[i].iNormalIndex], 3 * sizeof(float));

		if (m_bHasTextures) 
			memcpy(pVertex + 6, &m_oTextureCoordArray[oFaceBuffer[i].iTextureIndex], 2 * sizeof(float));
	}

	return true;
}

void CSimpleMesh::FreeTexureArray() {
	for (int i = 0; i < m_oTextures.GetSize(); i++) {
		if (m_oTextures[i])
			delete m_oTextures[i];
	}

	m_oTextures.RemoveAll();
}

void CSimpleMesh::DrawSubset(int iSubset) {
	if (m_bHasMaterials)
		m_poDisplayDevice->SetMaterial(&m_oMaterials[m_oSubsetsMaterialIndex[iSubset]]);
	
	if (m_bHasTextures) {
		int iTextureIndex = m_oMaterialsTextureIndex[m_oSubsetsMaterialIndex[iSubset]];
		
		if (iTextureIndex != -1) {
			m_poDisplayDevice->SetTexture(m_oTextures[iTextureIndex]);
		} else {
			m_poDisplayDevice->SetTexture(NULL);
		}
	}

	m_poDisplayDevice->DrawIndexedPrimitive(PRIMITIVETYPE_TRIANGLE_LIST, m_poVB, m_poIB, m_oSubsetsStartIndex[iSubset], (m_oSubsetsStartIndex[iSubset + 1] - m_oSubsetsStartIndex[iSubset]) / 3);
}

void CSimpleMesh::Draw() {
	int iNumSubsets = m_oSubsetsMaterialIndex.GetSize();
	for (int i = 0; i < iNumSubsets; i++)
		DrawSubset(i);
}

void CSimpleMesh::Cache() {
	m_poVB->Cache(m_poDisplayDevice);
	m_poIB->Cache(m_poDisplayDevice);
}