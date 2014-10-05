#include "stdafx.h"
#include "cSCENE_INTRO.h"


cSCENE_INTRO::cSCENE_INTRO()
{
}

cSCENE_INTRO::~cSCENE_INTRO()
{
}

void cSCENE_INTRO::enter()
{

}

void cSCENE_INTRO::update(double delta)
{
	if (cMAIN_GAME::getInstance()->input_->getDownKey_once(VK_ESCAPE))
		::DestroyWindow(cMAIN_GAME::getInstance()->hWnd_);
	
	if (cMAIN_GAME::getInstance()->input_->getDownKey_once(VK_RETURN))
		cMAIN_GAME::getInstance()->changeScene(SCENE_ID::START);
}

void cSCENE_INTRO::render()
{
	cMAIN_GAME::getInstance()->renderer_->textout(25, 25, L"scene: intro");	
}

void cSCENE_INTRO::exit()
{
	//delete this;
}
