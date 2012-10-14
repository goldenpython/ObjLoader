/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

#ifndef __SIMPLE_MESH_H__
#define __SIMPLE_MESH_H__

#include "DisplayDevice.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "Material.h"
#include "..\\util\\util.h"
#include "..\\mem\\memory.h"
#include "..\\String\\String.h"
#include "..\\Collection\\collection.h"

#define MAX_LINE_LEN		500

#define NO_TEXTURE			(-1)


#define USE_HASHTABLE_FOR_VERTEX_SEARCH

#ifdef USE_HASHTABLE_FOR_VERTEX_SEARCH
	#define NUM_KEYS 301
#endif //USE_HASHTABLE_FOR_VERTEX_SEARCH


class CSimpleMesh {
	public:
		CSimpleMesh(CDisplayDevice *device);
		~CSimpleMesh();

		bool LoadFromObjFile(char *szFileName);

		void DrawSubset(int iSubset);
		void Draw();
		void Cache();

	private:
		bool LoadMaterials(CString szFileName);
		void FreeTexureArray();

		CVertexBuffer *m_poVB;
		CIndexBuffer *m_poIB;
		bool m_bHasTextures, m_bHasMaterials;

		CDisplayDevice *m_poDisplayDevice;

		TArray<CMaterial> m_oMaterials;
		TArray<CString> m_oMaterialNames;

		TArray<CTexture *> m_oTextures;
		TArray<int> m_oMaterialsTextureIndex;

		TArray<int> m_oSubsetsStartIndex, m_oSubsetsMaterialIndex;

		static CString sDelimiters;
};

struct FACE_STRUCT {
	int iVertexIndex, iNormalIndex, iTextureIndex;

	bool operator == (const struct FACE_STRUCT &o) {
		return iVertexIndex == o.iVertexIndex && iNormalIndex == o.iNormalIndex && iTextureIndex == o.iTextureIndex;
	}

#ifdef USE_HASHTABLE_FOR_VERTEX_SEARCH
	int iIndex;

	static int GetKey(FACE_STRUCT &v) {
		int key = (v.iNormalIndex + v.iTextureIndex + v.iVertexIndex) % NUM_KEYS;
		return key;
	}
#endif //USE_HASHTABLE_FOR_VERTEX_SEARCH
};

#endif //__SIMPLE_MESH_H__