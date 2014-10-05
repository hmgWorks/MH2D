#include "stdafx.h"
#include "cSCENE_START.h"


cSCENE_START::cSCENE_START()
{
}
cSCENE_START::~cSCENE_START()
{
}

void cSCENE_START::enter()
{

}

void cSCENE_START::update(double delta)
{
	//종료키
	if (cMAIN_GAME::getInstance()->input_->getDownKey_once(VK_ESCAPE))
		::DestroyWindow(cMAIN_GAME::getInstance()->hWnd_);
	
	if (cMAIN_GAME::getInstance()->input_->getDownKey_once(VK_RETURN))
	cMAIN_GAME::getInstance()->changeScene(SCENE_ID::TUTO);
	
	if (cMAIN_GAME::getInstance()->input_->getDownKey_once(VK_BACK))
	cMAIN_GAME::getInstance()->changeScene(SCENE_ID::INTRO);

	//플래이어 이름의 파일을 만든다.
	if (cMAIN_GAME::getInstance()->input_->getDownKey_once(0x41))
		createPlayer();
}

void cSCENE_START::render()
{
	cMAIN_GAME::getInstance()->renderer_->textout(25, 25, L"scene: start");	
}

void cSCENE_START::exit()
{
	//delete this;
}

void cSCENE_START::createPlayer()
{
	cMAIN_GAME::getInstance()->resource_->createPlayerFile(path_ + player_name_+".txt");
}