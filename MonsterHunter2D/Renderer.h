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
		//�� ��Ʈ���� �޸� DC�� ���� (��ȭ��)
		hOldBit = (HBITMAP)SelectObject(GetMemDC(), hBlankBitMap);
		
	}

	void DrawBitmap(RECT & destRct,RECT& srcRct,HBITMAP hBit,UINT tColor=0)
	{
		HDC BackDC = CreateCompatibleDC(GetDC());

		// BackDC�� ��Ʈ�� ����(BackDC�� ��Ʈ�ʱ׸���)
		//--- ��� ��Ʈ��
		SelectObject(BackDC, hBit);
		if (tColor != 0)
		{
			TransparentBlt(
				GetMemDC(),
				destRct.left, destRct.top,   //��ũ���� �Ѹ� x,y ��ǥ
				destRct.right - destRct.left, //��ũ���� �Ѹ� ����
				destRct.bottom - destRct.top,//��ũ���� �Ѹ� ����
				BackDC,
				srcRct.left, srcRct.top,  //�ҽ� �� ��ǥ
				srcRct.right - srcRct.left,  //�ҽ��� ����
				srcRct.bottom - srcRct.top, //�ҽ��� ����
				tColor);
		}
		else
		{
			StretchBlt(
				GetMemDC(),
				destRct.left, destRct.top,   //��ũ���� �Ѹ� x,y ��ǥ
				destRct.right - destRct.left, //��ũ���� �Ѹ� ����
				destRct.bottom - destRct.top,//��ũ���� �Ѹ� ����
				BackDC,
				srcRct.left, srcRct.top,  //�ҽ� �� ��ǥ
				srcRct.right - srcRct.left,  //�ҽ��� ����
				srcRct.bottom - srcRct.top, //�ҽ��� ����
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

		// BackDC (MemDC���ۿ�)
		HDC BackDC = CreateCompatibleDC(GetDC());

		// BackDC�� ��Ʈ�� ����(BackDC�� ��Ʈ�ʱ׸���)
		//--- ��� ��Ʈ��
		SelectObject(BackDC, hBit);
		if (tColor != 0)
		{
			TransparentBlt(
				GetMemDC(),
				x, y,   //��ũ���� �Ѹ� x,y ��ǥ
				bm.bmWidth, //��ũ���� �Ѹ� ����
				bm.bmHeight,//��ũ���� �Ѹ� ����
				BackDC, 
				0, 0,  //�ҽ� �� ��ǥ
				bm.bmWidth,  //�ҽ��� ����
				bm.bmHeight, //�ҽ��� ����
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
