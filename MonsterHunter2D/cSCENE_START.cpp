#include "stdafx.h"
#include "cSCENE_START.h"


cSCENE_START::cSCENE_START()
{
	left_ = 330;
	top_ = 330;
	width_ = 400;
	height_ = 200;
}
cSCENE_START::~cSCENE_START()
{
}

void cSCENE_START::enter()
{
	edit_ = ::CreateWindow(L"edit", NULL, WS_CHILD | WS_VISIBLE | WS_BORDER | ES_CENTER
		, left_ + 100, top_ + 100, 200, 25, cMAIN_GAME::getInstance()->hWnd_, (HMENU)ID_EIDT, cMAIN_GAME::getInstance()->hInst_, NULL);
}

void cSCENE_START::update(double delta)
{
	//종료키
	if (cMAIN_GAME::getInstance()->input_->getDownKey_once(VK_ESCAPE))
		::DestroyWindow(cMAIN_GAME::getInstance()->hWnd_);
	
	if (cMAIN_GAME::getInstance()->input_->getDownKey_once(VK_RETURN))
	cMAIN_GAME::getInstance()->changeScene(SCENE_ID::MAIN);
	
	if (cMAIN_GAME::getInstance()->input_->getDownKey_once(VK_BACK))
	cMAIN_GAME::getInstance()->changeScene(SCENE_ID::INTRO);

	//플래이어 이름의 파일을 만든다.
	if (cMAIN_GAME::getInstance()->input_->getDownKey_once(0x41))
		createPlayer();

	if (cMAIN_GAME::getInstance()->input_->getMouseDown())
	{
		left_ = cMAIN_GAME::getInstance()->input_->getMouse().x;
		top_ = cMAIN_GAME::getInstance()->input_->getMouse().y;
	}
}

void cSCENE_START::render()
{
	WCHAR ch[100];
	wsprintf(ch, L"%d, %d", left_, top_);
	cMAIN_GAME::getInstance()->renderer_->rectangel(left_, top_, left_ + width_, top_ + height_);
	cMAIN_GAME::getInstance()->renderer_->rectangel(left_, top_, left_ + width_, top_ + 30);
	//cMAIN_GAME::getInstance()->renderer_->textout(left_, top_, ch);
//	cMAIN_GAME::getInstance()->renderer_->textout(490, 335, cMAIN_GAME::getInstance()->resource_->hunter_name_);
	
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