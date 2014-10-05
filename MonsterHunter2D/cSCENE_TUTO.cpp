#include "stdafx.h"
#include "cSCENE_TUTO.h"


cSCENE_TUTO::cSCENE_TUTO()
{
}
cSCENE_TUTO::~cSCENE_TUTO()
{
}

void cSCENE_TUTO::enter()
{

}

void cSCENE_TUTO::update(double delta)
{
	if (cMAIN_GAME::getInstance()->input_->getDownKey_once(VK_ESCAPE))
		::DestroyWindow(cMAIN_GAME::getInstance()->hWnd_);
	
	if (cMAIN_GAME::getInstance()->input_->getDownKey_once(VK_RETURN))
		cMAIN_GAME::getInstance()->changeScene(SCENE_ID::MAIN);

}

void cSCENE_TUTO::render()
{
	cMAIN_GAME::getInstance()->renderer_->textout(25, 25, L"scene: tuto");	
}

void cSCENE_TUTO::exit()
{
	//delete this;
}
