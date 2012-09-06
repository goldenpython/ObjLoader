/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

//
// WinMain
//

#include "WinMain.h"
#include "..\\Render\\Render.h"
#include "..\\math\\me.h"

#include "..\\Render\\simplemesh.h"
#include "..\\Render\\Font.h"

CDisplayDevice *g_Display = new CDisplayDevice();
int Width = 800;
int Height = 600;

HWND CreateAppWindow(HINSTANCE hInstance, int iWidth, int iHeight) {
	//
	// Create the main application window.
	//

	WNDCLASS wc;

	wc.style         = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc   = (WNDPROC)WndProc; 
	wc.cbClsExtra    = 0;
	wc.cbWndExtra    = 0;
	wc.hInstance     = hInstance;
	wc.hIcon         = LoadIcon(0, IDI_APPLICATION);
	wc.hCursor       = LoadCursor(0, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wc.lpszMenuName  = 0;
	wc.lpszClassName = "App";

	if( !RegisterClass(&wc) ) 
	{
		::MessageBox(0, "RegisterClass() - FAILED", 0, 0);
		return false;
	}

	HWND hwnd = 0;
	hwnd = ::CreateWindow("App", "App", 
		WS_EX_TOPMOST,
		0, 0, iWidth, iHeight,
		0 /*parent hwnd*/, 0 /* menu */, hInstance, 0 /*extra*/); 

	if (!hwnd) {
		::MessageBox(0, "CreateWindow() - FAILED", 0, 0);
		return false;
	}

	::ShowWindow(hwnd, SW_SHOW);
	::UpdateWindow(hwnd);

	return hwnd;
}

int WINAPI WinMain(HINSTANCE hinstance,
				   HINSTANCE prevInstance, 
				   PSTR cmdLine,
				   int showCmd)
{
	HWND hwnd = CreateAppWindow(hinstance, 800, 600);

	g_Display->CreateDevice(hwnd, !false, 800, 600);

	EnterMsgLoop(Display);

	/* if(!d3d::InitD3D(hinstance,
		Width, Height, true, D3DDEVTYPE_HAL, &Device))
	{
		::MessageBox(0, "InitD3D() - FAILED", 0, 0);
		return 0;
	} */

	/* if(!Setup())
	{
		::MessageBox(0, "Setup() - FAILED", 0, 0);
		return 0;
	}

	d3d::EnterMsgLoop( Display );

	Cleanup();

	Device->Release();
*/

	return 0;
}

//
// WndProc
//
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	switch( msg ) {
		case WM_DESTROY:
			::PostQuitMessage(0);
			break;

		case WM_KEYDOWN:
			if( wParam == VK_ESCAPE )
				::DestroyWindow(hwnd);
			break;
	}

	return ::DefWindowProc(hwnd, msg, wParam, lParam);
}

DWORD FrameCnt; // The number of frames that have occurred.
float TimeElapsed; // The time that has elapsed so far.
float FPS; // The frames rendered per second.
CFont *font;

void ComputeFPS(float timeDelta)
{
	FrameCnt++;
	TimeElapsed += timeDelta;

	if(TimeElapsed >= 1.0f)
	{
		FPS = (float)FrameCnt / TimeElapsed;
		TimeElapsed = 0.0f;
		FrameCnt = 0;
	}
}

int EnterMsgLoop(bool (*ptr_display)(float timeDelta)) {
	MSG msg;
	::ZeroMemory(&msg, sizeof(MSG));

	static float lastTime = (float)timeGetTime(); 

	while(msg.message != WM_QUIT) {
		if(::PeekMessage(&msg, 0, 0, 0, PM_REMOVE)) {
			::TranslateMessage(&msg);
			::DispatchMessage(&msg);
		} else {	
			float currTime  = (float)timeGetTime();
			float timeDelta = (currTime - lastTime) * 0.001f;

			ptr_display(timeDelta);

			ComputeFPS(timeDelta);

			lastTime = currTime;
		}
	}

	return (int)msg.wParam;
}

#include "..\\Math\\me.h"

#include "..\\stream\\stream.h"
CTexture *texture1 = NULL;
CStreamReader *sreader = new CFileStreamReader("2.bmp");
static int timer = 0;

#include "../collection/THashTable.h"
#include "../Image/CBmp.h"

int GetKey(CString *s) {
	int k = (*s)[0] * 15 + (*s)[1];
	return k;
}

bool IsEqual(CString *s1, CString *s2) {
	return *s1 == *s2;
}

bool Display(float timeDelta) {
	//ff(vct);

/*	THashTable<CString *> hash(5, GetKey, IsEqual);
	CString *s1 = new CString("gigel are mere");
	CString *s2 = new CString("mama are mere");
	CString *s3 = new CString("mama lui gigel are mere");


	hash.Insert(s1);
	hash.Insert(s2);
	hash.Insert(s3);

	s2 = new CString("mama are mere");
	bool ggg = hash.Find(s2);

	int (*f)(CString *) = GetKey;

	int k = sizeof(float);
	int k1 = sizeof(DWORD); */

	CString *s3 = new CString("mama lui gigel are mere");
	delete s3;

	//g_Display->ClearViewport(0xFF00001F);
	g_Display->ClearViewport(0xFF00FF00);

	g_Display->SetFillMode(FILLMODE_SOLID);

	if (timer++ == 0)
	{
		g_Display->SetProjection((float)PI / 2, 800.0f / 600.0f, 1.0f, 1000.0f);
		g_Display->SetCamera(&VECTOR3Df(0.0f, 0.0f, -30.0f), &VECTOR3Df(0.0f, 0.0f, 0.0f), &VECTOR3Df(0.0f, 1.0f, 0.0f));
	}


	static CBmp	*image;
	if (!image) {
		image = new CBmp();
		image->Load(sreader);
	}




	/* g_Display->SetTexture(NULL);

	struct vert {
		float x, y, z;
		DWORD color;
	};
	CVertexBuffer vb(VERTEXFORMAT_XYZ | VERTEXFORMAT_COLOR, 6);
	struct vert *v = (struct vert *)vb.GetVertexAtIndex(0);
	v->x = 10; v->y = 10, v->z = 0; v->color = 0xFF00FF00;

	v = (struct vert *)vb.GetVertexAtIndex(1);
	v->x = 10; v->y = 0, v->z = 0; v->color = 0xFF0000FF;

	v = (struct vert *)vb.GetVertexAtIndex(2);
	v->x = 1; v->y = 0, v->z = 0; v->color = 0xFFFF0000;

	v = (struct vert *)vb.GetVertexAtIndex(3);
	v->x = -10; v->y = 10, v->z = 0; v->color = 0xFFFF0000;

	v = (struct vert *)vb.GetVertexAtIndex(4);
	v->x = -10; v->y = 0, v->z = 0; v->color = 0xFF00FF00;

	v = (struct vert *)vb.GetVertexAtIndex(5);
	v->x = -20; v->y = 0, v->z = 0; v->color = 0xFF0000FF; 

	//ca vb.Cache((CDisplayDevice *)g_Display);

	CIndexBuffer ib(6);
	unsigned short *buff = ib.GetIndexBuffer();
	buff[0] = 4; buff[1] = 1; buff[2] = 0;
	buff[3] = 3; buff[4] = 0; buff[5] = 1;  */

	g_Display->BeginScene();

	g_Display->EnableLighting();
	g_Display->EnableSpecular();

	g_Display->SetCullMode(CULLMODE_CCW);
	g_Display->SetFillMode(FILLMODE_SOLID);

	g_Display->SetShadeMode(SHADEMODE_GOURAUD);
	g_Display->EnableNormalizeNormals();

	static float xxx = -150.0;
	//xxx += 0.1f;
	xxx += 0.05f;

	CLight light1, light2;
	//CLight::CreateDirectionalLight(&VECTOR3Df(1.0, 1.0, 0*1), &CColor(1.0f, 1.0f, 1.0f), &light1);	
	//CLight::CreateDirectionalLight(&VECTOR3Df(0.0, 0, 1.0f), &CColor(1.0f, 1.0f, 1.0f), &light1);	
	//CLight::CreateSpotLight(&VECTOR3Df(xxx, 0.0f, 0.0f), &VECTOR3Df(0.0f, 0.0f, 1.0f), &CColor(1.0f, 1.0f, 1.0f), 0.4f, 1.2f, &light1);
	//CLight::CreatePointLight(&VECTOR3Df(xxx, 0, 0), &CColor(1, 1, 1), &light1);
	//g_Display->SetLight(0, &light1);
	//g_Display->SetLight(1, &light2);

	//vb.DrawPrimitive(g_Display, PRIMITIVETYPE_TRIANGLE_LIST, 0, 1);
	//vb.DrawPrimitive(g_Display, PRIMITIVETYPE_TRIANGLE_LIST, 3, 1);

	//ca vb.DrawPrimitive(g_Display, PRIMITIVETYPE_TRIANGLE_LIST, 1, 1);

	//MATRIX4x4f matr;
	//matr.FillIdentity(&matr);
	//g_Display->SetWorldTransform(&matr);

	//CMaterial material1(&CColor(0xFFFF00FF), &CColor(0xFFFF00FF), &CColor(0xFF0000FF), &CColor(0x0000A000), 2.0);
	//g_Display->SetMaterial(&material1);

	//vb.Cache((CDisplayDevice *)g_Display);
	//ib.Cache((CDisplayDevice *)g_Display);
	//g_Display->DrawIndexedPrimitive(PRIMITIVETYPE_TRIANGLE_LIST, &vb, &ib, 0, 2);
	//ib.FreeCacheData();
	//vb.FreeCacheData();

	//matr.FillMatrixTranslation(-10, 0, 0, &matr);
	//MATRIX4x4f m1, m2, m3;
	//static float angle = 0;
	//MATRIX4x4f::FillMatrixRotationOZ(angle += (float)(PI / 180 / 20), &m1);
	//MATRIX4x4f::FillMatrixTranslation(10, 0, 0, &m2);
	//MATRIX4x4f::FillMatrixScale(0.5, 0.5, 0.5, &m3);
	//matr *= m1;
	//matr *= m3;
	//matr *= m2;


	////matr *= m2;

	//g_Display->SetWorldTransform(&matr);

	//g_Display->DrawIndexedPrimitive(PRIMITIVETYPE_TRIANGLE_LIST, &vb, &ib, 3, 1);


	//vb.Cache((CDisplayDevice *)g_Display);
	//MATRIX4x4f::FillMatrixTranslation(0, 10, 0, &matr);
	//g_Display->SetWorldTransform(&matr);
	//g_Display->DrawPrimitive(PRIMITIVETYPE_TRIANGLE_LIST, &vb, 0, 2);
	//vb.FreeCacheData();


	//CMaterial material(&CColor(0xFFFF00FF), &CColor(0xFFFF00FF), &CColor(0xFFFF00FF), &CColor(0xFFA00000), 2.0);
	//g_Display->SetMaterial(&material);

	//MATRIX4x4f::FillMatrixTranslation(0, -10, 0, &matr);
	//g_Display->SetWorldTransform(&matr);
	//g_Display->DrawPrimitive(PRIMITIVETYPE_TRIANGLE_LIST, &vb, 0, 2);

	//MATRIX4x4f matr1, matr2;
	//MATRIX4x4f::FillIdentity(&matr1);
	//static float angl = 0;
	//MATRIX4x4f::FillMatrixRotationOZ(angl/* += 0.01f*/, &matr1);
	//MATRIX4x4f::FillMatrixTranslation(-25, 0, 0, &matr2);

	//g_Display->SetWorldTransform(&(matr1 * matr2));

	//CVertexBuffer vb1(VERTEXFORMAT_XYZ | VERTEXFORMAT_TEXTURE | VERTEXFORMAT_NORMAL, 4);
	//struct vert1 {
	//	float x, y, z;
	//	float nx, ny, nz;
	//	float u, v;
	//};

	//struct vert1 *vertexx = (struct vert1 *)vb1.GetVertexAtIndex(0);	
	//vertexx->x = -20; vertexx->y = -20; vertexx->z = 30; vertexx->u = 0; vertexx->v = 1.0;
	//vertexx->nx = 0; vertexx->ny = 0; vertexx->nz = -+1;

	//vertexx = (struct vert1 *)vb1.GetVertexAtIndex(1);	
	//vertexx->x = 20; vertexx->y = -20; vertexx->z = 30; vertexx->u = 1; vertexx->v = 1.0;
	//vertexx->nx = 0; vertexx->ny = 0; vertexx->nz = -+1;

	//vertexx = (struct vert1 *)vb1.GetVertexAtIndex(2);	
	//vertexx->x = 20; vertexx->y = 20; vertexx->z = 30; vertexx->u = 1; vertexx->v = 0.0;
	//vertexx->nx = 0; vertexx->ny = 0; vertexx->nz = -+1;

	//vertexx = (struct vert1 *)vb1.GetVertexAtIndex(3);	
	//vertexx->x = -20; vertexx->y = 20; vertexx->z = 30; vertexx->u = 0; vertexx->v = 0.0;
	//vertexx->nx = 0; vertexx->ny = 0; vertexx->nz = -+1;

	//CIndexBuffer ib1(6);
	///* *ib1.GetIndexAtIndex(0) = 0;
	//*ib1.GetIndexAtIndex(1) = 1;
	//*ib1.GetIndexAtIndex(2) = 2;
	//*ib1.GetIndexAtIndex(3) = 0;
	//*ib1.GetIndexAtIndex(4) = 2;
	//*ib1.GetIndexAtIndex(5) = 3; */
	//ib1[0] = 0;
	//ib1[1] = 1;
	//ib1[2] = 2;
	//ib1[3] = 0;
	//ib1[4] = 2;
	//ib1[5] = 3;

	//static CTexture texture(g_Display, "1.bmp");

	//g_Display->SetTexture(&texture);
	//g_Display->DrawIndexedPrimitive(PRIMITIVETYPE_TRIANGLE_LIST, &vb1, &ib1, 0, 2);

	//if (texture1 == NULL) {
	//	char *buffer = new char[360054];
	//	sreader->ReadBytes(buffer, 360054);
	//	texture1 = new CTexture(g_Display, buffer, 360054);
	//	delete []buffer;
	//}

	//MATRIX4x4f::FillMatrixRotationOZ(angl, &matr1);
	//MATRIX4x4f::FillMatrixTranslation(+25, 0, 10, &matr2);
	//g_Display->SetWorldTransform(&(matr1 * matr2));

	//g_Display->SetTexture(texture1);
	//g_Display->DrawIndexedPrimitive(PRIMITIVETYPE_TRIANGLE_LIST, &vb1, &ib1, 0, 2); 

	static CSimpleMesh *mesh = NULL;
	static CSimpleMesh *mesh2 = NULL;
	static CSimpleMesh *mesh3 = NULL;
	
	if (mesh == NULL) {
		font = new CFont(g_Display, "times new roman", 8, 16, !true);

		mesh = new CSimpleMesh(g_Display);
		//mesh->LoadFromObjFile("box.obj");
		//mesh->LoadFromObjFile("complex.obj");
		mesh->LoadFromObjFile("sfera.obj");
		mesh->Cache();

		mesh2 = new CSimpleMesh(g_Display);
		//mesh2->LoadFromObjFile("testsf.obj");
		mesh2->LoadFromObjFile("indy2.obj");
		//mesh2->LoadFromObjFile("cup.obj");
		mesh2->Cache();

		mesh3 = new CSimpleMesh(g_Display);
		mesh3->LoadFromObjFile("cup.obj");
		mesh3->Cache();
	}

	g_Display->EnableSpecular(true);
	g_Display->EnableNormalizeNormals(true);


	MATRIX4x4f matr1, matr2, matr3;
	static float angl = 0.0f;

	MATRIX3x3f matr23;
	MATRIX3x3f::FillMatrixRotationOZ(angl, &matr23);

	CLight::CreateSpotLight(&VECTOR3Df(0, 0, -10 - 80 + xxx), &(VECTOR3Df(0.0f, 1.0f, 5.0f) /** matr23*/), &CColor(1.0f, 1.0f, 1.0f), 0.4f, .9f, 900, &light1);	
	//CLight::CreatePointLight(&VECTOR3Df(0.0f, 0 * -30.0f, angl * 0 * 10 + -5.0f), &CColor(1.0f, 1.0f, 1.0f), 90, &light1);
	g_Display->SetLight(0, &light1);

 	MATRIX4x4f::FillMatrixRotationOY(0.0f * (angl += (3.1415f / 180.0f) * 0.3f), &matr1);
/*	MATRIX4x4f::FillMatrixTranslation(+35, -3*0, 70, &matr2);
	g_Display->SetWorldTransform(&(matr1 * matr2));
	mesh->Draw(); */


	g_Display->EnableSpecular(true);
	g_Display->EnableNormalizeNormals(true);

	MATRIX4x4f matr0;
	MATRIX4x4f::FillMatrixScale(.50, .50, .50, &matr0);
	MATRIX4x4f::FillMatrixRotationOY(angl, &matr1);
	MATRIX4x4f::FillMatrixTranslation(-45, -3, 70, &matr2);
	g_Display->SetWorldTransform(&(matr0 * matr1 * matr2));
	g_Display->SetCullMode(CULLMODE_NONE);
	mesh2->Draw();

	g_Display->SetShadeMode(SHADEMODE_GOURAUD);
	g_Display->EnableSpecular(true);
	g_Display->EnableNormalizeNormals(true);
	MATRIX4x4f::FillMatrixScale(1, 1, 1, &matr0);
	MATRIX4x4f::FillMatrixRotationOY(angl, &matr1);
	MATRIX4x4f::FillMatrixTranslation(45, -3, 70, &matr2);
	g_Display->SetWorldTransform(&(matr0 * matr1 * matr2));
	mesh->Draw();

	//MATRIX4x4f::FillMatrixRotationOX(angl, &matr1);
	//MATRIX4x4f::FillMatrixTranslation(-35 + 50, -30, 70, &matr2);
	//g_Display->SetWorldTransform(&(matr1 * matr2));
	//mesh2->DrawSubset(4);

	MATRIX4x4f::FillIdentity(&matr1);
	MATRIX4x4f::FillMatrixTranslation(0, -30, 170, &matr2);
	g_Display->SetWorldTransform(&(matr1 * matr2));
	mesh->Draw(); 

	MATRIX4x4f::FillMatrixTranslation(-100, 30, 170, &matr2);
	g_Display->SetWorldTransform(&(matr1 * matr2));
	mesh->Draw();  


	MATRIX4x4f::FillMatrixRotationOX(angl, &matr1);
	MATRIX4x4f::FillMatrixTranslation(-35 + 50 - 15, -30 + 30 + 1, 70 - 97, &matr2);
	MATRIX4x4f::FillMatrixRotationOY(angl / 5, &matr3);
	g_Display->SetWorldTransform(&(matr3 * matr1 * matr2));
	//mesh3->DrawSubset(4);
	mesh3->Draw();  


	RECT rect = {0, 0, 200, 100};
	char szFPS[20];
	extern float FPS;
	sprintf(szFPS, "%f FPS", FPS);
	//font->DrawText(NULL, szFPS, -1, &rect, DT_TOP | DT_LEFT, 0xFF000000);
	font->DrawText(CString(szFPS), 0, 0, 0xFFFF0000);

	g_Display->EndScene();
	g_Display->Present();


	/* CMatrix4x4<float> a;
	CMatrix4x4<float>::FillIdentity(&a);
	CVector4D<float> v;
	v *= a; */

	return true;
}
