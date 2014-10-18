#include "stdafx.h"
#include "cSELECT_MAP.h"
#include "cMAIN_GAME.h"

cSELECT_MAP::cSELECT_MAP()
{
	
}

cSELECT_MAP::~cSELECT_MAP()
{

}

void cSELECT_MAP::update(double delta, int& scene_state)
{
	if (cMAIN_GAME::getInstance()->input_->getDownKey_once('1'))
	{
		scene_state = eSCENE_STATE::WORLD;
	}
	if (cMAIN_GAME::getInstance()->input_->getDownKey_once('2'))
	{
		scene_state = eSCENE_STATE::DUNGEON;
	}
}

void cSELECT_MAP::render()
{
	cMAIN_GAME::getInstance()->renderer_->textout(25, 25, L"scene: select map");
}

