#pragma once
#pragma comment(lib,"msimg32.lib") 
class cRENDERER
{
public:
	cRENDERER();
	~cRENDERER();

	void beginRender(HDC hdc, int width, int height);
	void endRender();

	void rectangel(int left, int top, int right, int bottom);
	void textout(int pos_x, int pos_y, WCHAR* str);
	void selectBrush(COLORREF color);
	void deleteBrush();
	
	//void drawBitmap(int x, int y, HBITMAP hBit, UINT tColor = 0);
	void drawBitmapBack(int pos_x, int pos_y, HBITMAP hBit, UINT color_key = 0);
	void renderToscreen();
	HDC getFrontDc(){
		return front_hdc_;
	}

private:
	HDC hdc_, front_hdc_;
	int client_width_, client_height_;
	HBITMAP backBit_, old_backBit_;
	HBRUSH hBr_, oldBr_;
};