/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

#ifndef _RENDER_CONSTANS_H__
#define _RENDER_CONSTANS_H__

enum FILLMODE {
	FILLMODE_SOLID = 0,
	FILLMODE_WIREFRAME = 1
};

enum SHADEMODE {
	SHADEMODE_FLAT = 0,
	SHADEMODE_GOURAUD = 1
};

enum CULLMODE {
	CULLMODE_NONE = 0,
	CULLMODE_CW = 1,
	CULLMODE_CCW = 2
};

enum PRIMITIVETYPE {
	PRIMITIVETYPE_TRIANGLE_LIST = 0
};

enum LIGHTTYPE {
	LIGHTTYPE_DIRECTIONAL = 0,
	LIGHTTYPE_POINT = 1,
	LIGHTTYPE_SPOT = 2
};

#define VERTEXFORMAT_XYZ		(1)
#define VERTEXFORMAT_NORMAL		(2)
#define VERTEXFORMAT_TEXTURE	(4)
#define VERTEXFORMAT_COLOR		(8)
#endif