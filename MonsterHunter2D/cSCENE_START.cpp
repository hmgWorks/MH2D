#include "stdafx.h"
#include "cSCENE_START.h"


cSCENE_START::cSCENE_START()
{
	l = 0;
	t = 0;
	r = 0;
	b = 0;
	draw_window_ = { 0, 0, 0, 0 };
	button_state_ = 0;
	popup_window_ = FALSE;
	//memset(buf, 0, lstrlen(buf));
}
cSCENE_START::~cSCENE_START()
{
}

void cSCENE_START::enter()
{
	cMAIN_GAME::getInstance()->resource_->loadImage(start_bg_, L"Image/set_name.bmp");
	cMAIN_GAME::getInstance()->resource_->loadImage(start_create_, L"Image/set_name_select.bmp");
	cMAIN_GAME::getInstance()->resource_->loadImage(start_button1_, L"Image/start_button1.bmp");
	cMAIN_GAME::getInstance()->resource_->loadImage(start_button2_, L"Image/start_button2.bmp");
	cMAIN_GAME::getInstance()->resource_->loadImage(start_popup_, L"Image/start_popup.bmp");
	//edit_ = ::CreateWindow(L"edit", NULL, WS_CHILD | /*WS_VISIBLE |*/ WS_BORDER | ES_CENTER,
	//	375, 395, 200, 25, cMAIN_GAME::getInstance()->hWnd_, (HMENU)ID_EIDT, cMAIN_GAME::getInstance()->hInst_, NULL);

	//button_ = ::CreateWindow(L"button", L"확 인", WS_CHILD | /*WS_VISIBLE |*/ BS_PUSHBUTTON,
	//	365, 450, 200, 25, cMAIN_GAME::getInstance()->hWnd_, (HMENU)ID_BUTTON, cMAIN_GAME::getInstance()->hInst_, NULL);
}

void cSCENE_START::update(double delta)
{	
	//종료키
	if (cMAIN_GAME::getInstance()->input_->getDownKey_once(VK_ESCAPE))
		::DestroyWindow(cMAIN_GAME::getInstance()->hWnd_);
	
	if (cMAIN_GAME::getInstance()->input_->getDownKey_once(VK_RETURN))
	{
		if (button_state_ == 0)
		{
			popup_window_ = TRUE;

			//ShowWindow(edit_, SW_SHOW);
			//ShowWindow(button_, SW_SHOW);
		}
		else
		{
			cMAIN_GAME::getInstance()->changeScene(SCENE_ID::MAIN);
		}
	}
	if (cMAIN_GAME::getInstance()->input_->getDownKey_once(VK_BACK))
	cMAIN_GAME::getInstance()->changeScene(SCENE_ID::INTRO);

	//플래이어 이름의 파일을 만든다.
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

	if (cMAIN_GAME::getInstance()->input_->getDownKey_once(VK_DOWN)
		|| cMAIN_GAME::getInstance()->input_->getDownKey_once(VK_RIGHT))
	{
		if (button_state_ < 1)
			button_state_++;
		else
			button_state_ = 0;
	}
	if (cMAIN_GAME::getInstance()->input_->getDownKey_once(VK_UP)
		|| cMAIN_GAME::getInstance()->input_->getDownKey_once(VK_LEFT))
	{
		if (button_state_ > 0)
			button_state_--;
		else
			button_state_ = 1;
	}
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

	switch (button_state_)
	{
	case 0:
		cMAIN_GAME::getInstance()->renderer_->drawBitmapBack(215, 647, start_button1_);
		break;
	case 1:
		cMAIN_GAME::getInstance()->renderer_->drawBitmapBack(559, 646, start_button2_);
		break;	
	}

	if (popup_window_)
		cMAIN_GAME::getInstance()->renderer_->drawBitmapBack(400, 250, start_create_);
	//	cMAIN_GAME::getInstance()->renderer_->drawBitmapBack(300, 290, start_popup_);
	//cMAIN_GAME::getInstance()->renderer_->textout(25, 70, cMAIN_GAME::getInstance()->input_->buf_);
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