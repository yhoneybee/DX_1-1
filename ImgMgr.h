#pragma once
struct Texture
{
	LPDIRECT3DTEXTURE9 p;
	D3DXIMAGE_INFO info;
	Texture(LPDIRECT3DTEXTURE9 p, D3DXIMAGE_INFO info)
		:p(p), info(info) {}

	void Render(V2 pos = CENTER, RECT rt = ZERO, V2 size = ONE, float rot = 0, float depth = 1, D3DXCOLOR color = D3DCOLOR_RGBA(255, 255, 255, 255), bool center = true);
	void Release() { SAFE_RELEASE(p); }
};
class ImgMgr :
	public st<ImgMgr>
{
public:
	ImgMgr();
	~ImgMgr();

	Texture* Add(const string& key);

	void Begin();
	void Render(Texture* p, V2 pos = CENTER, RECT rt = ZERO, V2 size = ONE, float rot = 0, float depth = 1, D3DXCOLOR color = D3DCOLOR_RGBA(255, 255, 255, 255), bool center = true);
	void Write(const string& str, V2 pos = CENTER, float size = 50, D3DXCOLOR color = D3DCOLOR_RGBA(255, 255, 255, 255), bool center = true);
	void End();

	void Lost();
	void Reset();

	LPD3DXSPRITE sprite;
	LPD3DXFONT font;
	map<string, Texture*>textures;
};

#define IMG ImgMgr::G()