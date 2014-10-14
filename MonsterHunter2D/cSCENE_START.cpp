#include "stdafx.h"
#include "cSCENE_START.h"


cSCENE_START::cSCENE_START()
{
	l = 0;
	t = 0;
	r = 0;
	b = 0;
	draw_window_ = { 0, 0, 0, 0 };

	//memset(buf, 0, lstrlen(buf));
}
cSCENE_START::~cSCENE_START()
{
}

void cSCENE_START::enter()
{
	cMAIN_GAME::getInstance()->resource_->loadImage(start_bg_, L"Image/set_name.bmp");
	//edit_ = ::CreateWindow(L"edit", NULL, WS_CHILD | /*WS_VISIBLE |*/ WS_BORDER | ES_CENTER,
	//	left_ + 100, top_ + 100, 200, 25, cMAIN_GAME::getInstance()->hWnd_, (HMENU)ID_EIDT, cMAIN_GAME::getInstance()->hInst_, NULL);

	//button_ = ::CreateWindow(L"button", L"Ȯ ��", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
	//	left_ + 100, top_ + 150, 200, 25, cMAIN_GAME::getInstance()->hWnd_, (HMENU)ID_BUTTON, cMAIN_GAME::getInstance()->hInst_, NULL);
}

void cSCENE_START::update(double delta)
{	
	//����Ű
	if (cMAIN_GAME::getInstance()->input_->getDownKey_once(VK_ESCAPE))
		::DestroyWindow(cMAIN_GAME::getInstance()->hWnd_);
	
	if (cMAIN_GAME::getInstance()->input_->getDownKey_once(VK_RETURN))
		//::ShowWindow(edit_, SW_SHOW);
		
	
	if (cMAIN_GAME::getInstance()->input_->getDownKey_once(VK_BACK))
	cMAIN_GAME::getInstance()->changeScene(SCENE_ID::INTRO);

	//�÷��̾� �̸��� ������ �����.
	if (cMAIN_GAME::getInstance()->input_->getDownKey_once(0x41))
		createPlayer();

	//if (cMAIN_GAME::getInstance()->input_->getDownKey_once('R'))
	//	draw_st_ = !draw_st_;
	//
	if (cMAIN_GAME::getInstance()->input_->isMouseDown())
	{
		l = cMAIN_GAME::getInstance()->input_->getMousePos().x;
		t = cMAIN_GAME::getInstance()->input_->getMousePos().y;		
	}
	//
	//if (!cMAIN_GAME::getInstance()->input_->isMouseDown() && draw_st_)
	//{
	//	r = cMAIN_GAME::getInstance()->input_->getMousePos().x;
	//	b = cMAIN_GAME::getInstance()->input_->getMousePos().y;
	//	draw_window_.left = l;
	//	draw_window_.top = t;
	//	draw_window_.right = r;
	//	draw_window_.bottom = b;		
	//}	

}

void cSCENE_START::render()
{
	WCHAR ch[100];
	wsprintf(ch, L"%d, %d", l, t);
	/*cMAIN_GAME::getInstance()->renderer_->rectangel(left_, top_, left_ + width_, top_ + height_);
	cMAIN_GAME::getInstance()->renderer_->rectangel(left_, top_, left_ + width_, top_ + 30);*/
	//cMAIN_GAME::getInstance()->renderer_->textout(left_, top_, ch);
//	cMAIN_GAME::getInstance()->renderer_->textout(490, 335, cMAIN_GAME::getInstance()->resource_->hunter_name_);
	
	cMAIN_GAME::getInstance()->renderer_->drawBitmapBack(0, 0, start_bg_);
	

	cMAIN_GAME::getInstance()->renderer_->textout(25, 50, ch);
	cMAIN_GAME::getInstance()->renderer_->textout(25, 25, L"scene: start");	
}

void cSCENE_START::exit()
{
	//delete this;
	::DestroyWindow(edit_);
}

void cSCENE_START::createPlayer()
{
	cMAIN_GAME::getInstance()->resource_->createPlayerFile(path_ + player_name_+".txt");
}