#include "DXUT.h"
#include "UtillMgr.h"

int UtillMgr::INT(int min, int max)
{
	return (*(new uniform_int_distribution<int>(min, max)))(gen);
}

V2 UtillMgr::Vec2(V2 origin)
{
	V2 dir;
	dir = { float(INT(L + 1, R - 1) - origin.x),float(INT(T + 1, B - 1) - origin.y) };
	D3DXVec2Normalize(&dir, &dir);
	return dir;
}

void UtillMgr::Reflex(V2* dir_out, V2 side)
{
	(*dir_out) = (*dir_out) + 2 * side * D3DXVec2Dot(&-(*dir_out), &side);
}