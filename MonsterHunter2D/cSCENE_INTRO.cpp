#include "stdafx.h"
#include "cSCENE_INTRO.h"


cSCENE_INTRO::cSCENE_INTRO()
{
	state_ = 0;
}

cSCENE_INTRO::~cSCENE_INTRO()
{
}

void cSCENE_INTRO::enter()
{
	cMAIN_GAME::getInstance()->resource_->loadImage(intro_title_, eIMG_LIST::INTRO_TITLE);
	cMAIN_GAME::getInstance()->resource_->loadImage(intro_button_play_, eIMG_LIST::INTRO_PLAY);
	cMAIN_GAME::getInstance()->resource_->loadImage(intro_button_continue_, eIMG_LIST::INTRO_CONTINUE);
	cMAIN_GAME::getInstance()->resource_->loadImage(intro_button_exit_, eIMG_LIST::INTRO_EXIT);
}

void cSCENE_INTRO::update(double delta)
{
	if (cMAIN_GAME::getInstance()->input_->getDownKey_once(VK_DOWN)
		|| cMAIN_GAME::getInstance()->input_->getDownKey_once(VK_RIGHT))
	{
		if (state_ < 2)
			state_++;
		else
			state_ = 0;
	}
	if (cMAIN_GAME::getInstance()->input_->getDownKey_once(VK_UP)
		|| cMAIN_GAME::getInstance()->input_->getDownKey_once(VK_LEFT))
	{
		if (state_ > 0)
			state_--;
		else
			state_ = 2;
	}
	//if (cMAIN_GAME::getInstance()->input_->getDownKey_once(VK_ESCAPE))
	
	if (cMAIN_GAME::getInstance()->input_->getDownKey_once(VK_RETURN))
	{
		switch (state_)
		{
		case 0:
		cMAIN_GAME::getInstance()->changeScene(SCENE_ID::START);
		break;
		
		case 2:
		::DestroyWindow(cMAIN_GAME::getInstance()->hWnd_);
		break;
		}
	}


}

void cSCENE_INTRO::render()
{
	cMAIN_GAME::getInstance()->renderer_->drawBitmapBack(0, 0, intro_title_);
	switch (state_)
	{
	case 0:
		cMAIN_GAME::getInstance()->renderer_->drawBitmapBack(421, 454, intro_button_play_);
		break;
	case 1:
		cMAIN_GAME::getInstance()->renderer_->drawBitmapBack(421, 482, intro_button_continue_);
		break;
	case 2:
		cMAIN_GAME::getInstance()->renderer_->drawBitmapBack(421, 509, intro_button_exit_);
		break;
	}
	cMAIN_GAME::getInstance()->renderer_->textout(25, 25, L"scene: intro");	
}

void cSCENE_INTRO::exit()
{
	//delete this;
}
