#pragma once	
#pragma comment(lib,"msimg32.lib") 
#include <Windows.h>
//#include "cSINGLETON.h"

#define WINDOW_WIDTH 1024
#define WINDOW_HEIGHT 768


class Renderer
	//: public cSINGLETON<Renderer>
{
	//friend cSINGLETON;
public:
	Renderer(){}
	~Renderer(){}

private:
	PAINTSTRUCT ps;
	HDC hdc;
	HWND hWnd;
	HDC FrontMemDC;
	HBITMAP hBlankBitMap;
	HBITMAP hOldBit;

public:	
	HDC GetDC(){
		return hdc;
	}
	void RenderToScreen(){
		BitBlt(hdc, 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, GetMemDC(), 0, 0, SRCCOPY);
	}

	void BeginRender(HWND hWnd){
		this->hWnd = hWnd;
		

		hdc = BeginPaint(hWnd, &ps);

		FrontMemDC = CreateCompatibleDC(hdc);

		hBlankBitMap = CreateCompatibleBitmap(hdc,
			WINDOW_WIDTH,
			WINDOW_HEIGHT);
		//빈 비트맵을 메모리 DC에 선택 (도화지)
		hOldBit = (HBITMAP)SelectObject(GetMemDC(), hBlankBitMap);
		
	}

	void DrawBitmap(RECT & destRct,RECT& srcRct,HBITMAP hBit,UINT tColor=0)
	{
		HDC BackDC = CreateCompatibleDC(GetDC());

		// BackDC에 비트맵 선택(BackDC에 비트맵그리기)
		//--- 배경 비트맵
		SelectObject(BackDC, hBit);
		if (tColor != 0)
		{
			TransparentBlt(
				GetMemDC(),
				destRct.left, destRct.top,   //스크린에 뿌릴 x,y 좌표
				destRct.right - destRct.left, //스크린에 뿌릴 넓이
				destRct.bottom - destRct.top,//스크린에 뿌릴 높이
				BackDC,
				srcRct.left, srcRct.top,  //소스 의 좌표
				srcRct.right - srcRct.left,  //소스의 넓이
				srcRct.bottom - srcRct.top, //소스의 높이
				tColor);
		}
		else
		{
			StretchBlt(
				GetMemDC(),
				destRct.left, destRct.top,   //스크린에 뿌릴 x,y 좌표
				destRct.right - destRct.left, //스크린에 뿌릴 넓이
				destRct.bottom - destRct.top,//스크린에 뿌릴 높이
				BackDC,
				srcRct.left, srcRct.top,  //소스 의 좌표
				srcRct.right - srcRct.left,  //소스의 넓이
				srcRct.bottom - srcRct.top, //소스의 높이
				SRCCOPY);
		}
		DeleteObject(BackDC);

	}

	void DrawBitmap(
		int x,
		int y,
		HBITMAP hBit ,
		UINT tColor=0)
	{
		BITMAP bm;
		GetObject(hBit, sizeof(BITMAP), &bm);

		// BackDC (MemDC전송용)
		HDC BackDC = CreateCompatibleDC(GetDC());

		// BackDC에 비트맵 선택(BackDC에 비트맵그리기)
		//--- 배경 비트맵
		SelectObject(BackDC, hBit);
		if (tColor != 0)
		{
			TransparentBlt(
				GetMemDC(),
				x, y,   //스크린에 뿌릴 x,y 좌표
				bm.bmWidth, //스크린에 뿌릴 넓이
				bm.bmHeight,//스크린에 뿌릴 높이
				BackDC, 
				0, 0,  //소스 의 좌표
				bm.bmWidth,  //소스의 넓이
				bm.bmHeight, //소스의 높이
				tColor);
			//tColor = RGB(255,255,255)
		}
		else
		{
			BitBlt(GetMemDC(),
				x, y,
				bm.bmWidth,
				bm.bmHeight,
				BackDC,
				0, 0,
				SRCCOPY);
		}

		DeleteObject(BackDC);
	}


	void Rectangle(int left,int top, int right, int bottom){
		::Rectangle(GetMemDC(), left, top, right, bottom);
	}
	//void TextOut(int )

	void EndRender(){
		RenderToScreen();

		SelectObject(GetMemDC(), hOldBit);
		DeleteObject(hBlankBitMap);
		DeleteObject(GetMemDC());
		EndPaint(hWnd, &ps);
	}

	HDC GetMemDC(){
		return FrontMemDC;
	}

};
