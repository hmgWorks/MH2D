#include "stdafx.h"
#include "cRENDERER.h"


cRENDERER::cRENDERER()
{
}

cRENDERER::~cRENDERER()
{
}

void cRENDERER::beginRender(HDC hdc, int width, int height)
{
	hdc_ = hdc;
	client_width_ = width;
	client_height_ = height;
	front_hdc_ = CreateCompatibleDC(hdc_);
	backBit_ = CreateCompatibleBitmap(hdc_, client_width_, client_height_);
	old_backBit_ = (HBITMAP) SelectObject(front_hdc_, backBit_);
}

void cRENDERER::endRender()
{
	renderToscreen();
	DeleteObject(SelectObject(front_hdc_, old_backBit_));
	DeleteObject(backBit_);
	DeleteDC(front_hdc_);
}

void cRENDERER::renderToscreen()
{
	BitBlt(hdc_, 0, 0, client_width_, client_height_, front_hdc_, 0, 0, SRCCOPY);
}

void cRENDERER::rectangel(int left, int top, int right, int bottom)
{
	::Rectangle(front_hdc_, left, top, right, bottom);
}

void cRENDERER::textout(int pos_x, int pos_y, WCHAR* str)
{
	::TextOut(front_hdc_, pos_x, pos_y, str, lstrlen(str));
}

void cRENDERER::selectBrush(COLORREF color)
{	
	hBr_ = ::CreateSolidBrush(color);
	oldBr_ = (HBRUSH)::SelectObject(front_hdc_, hBr_);
}

void cRENDERER::deleteBrush()
{
	DeleteObject(SelectObject(front_hdc_, oldBr_));
}

void cRENDERER::drawBitmapBack(int pos_x, int pos_y, HBITMAP hBit, UINT color_key)
{
	BITMAP bm;
	
	::GetObject(hBit, sizeof(BITMAP), &bm);
	// backdc (memdc전송용)
	HDC back_dc = ::CreateCompatibleDC(front_hdc_);

	// backdc에 비트맵 선택(backdc에 비트맵그리기)
	//--- 배경 비트맵
	::SelectObject(back_dc, hBit);
	if (color_key != 0)
	{
		::TransparentBlt(
			front_hdc_,
			pos_x, pos_y,   //스크린에 뿌릴 x,y 좌표
			bm.bmWidth, //스크린에 뿌릴 넓이
			bm.bmHeight,//스크린에 뿌릴 높이
			back_dc,
			0, 0,  //소스 의 좌표
			bm.bmWidth,  //소스의 넓이
			bm.bmHeight, //소스의 높이
			color_key);
		//color_key = rgb(255,255,255)
	}
	else
	{ 
		::BitBlt(
			front_hdc_,
			pos_x, pos_y,
			bm.bmWidth,
			bm.bmHeight,
			back_dc,
			0, 0,
			SRCCOPY);
	}

	::DeleteObject(back_dc);
}
/*
	class cBitmap
		position
		rect
		offset
		hbitmap
		
*/
//void crenderer::drawbitmap(int x, int y, hbitmap hbit, uint tcolor = 0)
//{
//	bitmap bm;
//	getobject(hbit, sizeof(bitmap), &bm);
//
//	// backdc (memdc전송용)
//	hdc backdc = createcompatibledc(front_hdc_);
//
//	// backdc에 비트맵 선택(backdc에 비트맵그리기)
//	//--- 배경 비트맵
//	selectobject(backdc, hbit);
//	if (tcolor != 0)
//	{
//		transparentblt(
//			front_hdc_,
//			x, y,   //스크린에 뿌릴 x,y 좌표
//			bm.bmwidth, //스크린에 뿌릴 넓이
//			bm.bmheight,//스크린에 뿌릴 높이
//			backdc,
//			0, 0,  //소스 의 좌표
//			bm.bmwidth,  //소스의 넓이
//			bm.bmheight, //소스의 높이
//			tcolor);
//		//tcolor = rgb(255,255,255)
//	}
//	else
//	{
//		bitblt(front_hdc_,
//			x, y,
//			bm.bmwidth,
//			bm.bmheight,
//			backdc,
//			0, 0,
//			srccopy);
//	}
//
//	deleteobject(backdc);
//}
//void cRENDERER::drawBitmapBack(HBITMAP hBit, int pos_x, int pos_y, UINT color_key = 0)
//{
//
//}