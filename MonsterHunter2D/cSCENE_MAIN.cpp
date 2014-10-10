#include "stdafx.h"
#include "cSCENE_MAIN.h"
#include "cMAIN_GAME.h"
#include "cPANGGO.h"

cSCENE_MAIN::cSCENE_MAIN()
{	
	grid_ = nullptr;
	player_ = nullptr;	
	scene_state_ = eSCENE_STATE::WORLD;	
}
cSCENE_MAIN::~cSCENE_MAIN()
{

}

void cSCENE_MAIN::enter()
{	
	

	grid_ = std::make_shared<cGRID>();
	player_ = std::make_shared<cPLAYER_BASE>();
	grid_->initMap(cMAIN_GAME::getInstance()->resource_->getMapData(), player_, eMAP_NAME::world);
	
	select_map_ = std::make_shared<cSELECT_MAP>();
	/*
		플래이어의 위치와 한계의 설정은 그리드에 종속 되어야 함.
		그리드(맵의)변경시 플래이어의 우치와 한계가 셋팅 돼어야 함.
		카메라는 플래이어에 종속돼
	*/

	/*grid_->initPlayer1(player_);	
	player_->setLimits(grid_->getGridLimits());	
	cMAIN_GAME::getInstance()->camera_->setLimit(grid_->getGridLimits());	
	cMAIN_GAME::getInstance()->camera_->setTarget(player_);*/
	cMAIN_GAME::getInstance()->camera_->setTarget(player_);
}

void cSCENE_MAIN::update(double delta)
{
	//프로그램 종료
	if (cMAIN_GAME::getInstance()->input_->getDownKey_once(VK_ESCAPE))
		::DestroyWindow(cMAIN_GAME::getInstance()->hWnd_);	
	/*if (cMAIN_GAME::getInstance()->input_->getDownKey_once(VK_INSERT))
		v_monster_.push_back(new cPANGGO(cMAIN_GAME::getInstance()->input_->getMouse(),grid_->getGridLimits()));*/
		
	if (cMAIN_GAME::getInstance()->input_->getDownKey_once('W'))
		cMAIN_GAME::getInstance()->camera_->vibrateSwitch();
	
	if (scene_state_ == eSCENE_STATE::SELECT)
	{
		select_map_->update(delta, scene_state_);		
		if (scene_state_ == eSCENE_STATE::DUNGEON)
		{
			grid_->initMap(cMAIN_GAME::getInstance()->resource_->getMapData(), player_, eMAP_NAME::map_jungle);
		}
	}
	else
	{
		grid_->update(delta);
		player_->update(delta);
		grid_->checkCollision(player_, this);
		grid_->setTileMap(player_);	
		
		cMAIN_GAME::getInstance()->camera_->update(delta);	
	}

	//
	////맵전환 시 객체 정리
	//if (!v_monster_.empty())
	//	for (auto x : v_monster_)
	//		grid_->setTileMap(x);
	//grid_->checkCollision(player_);
	
}

void cSCENE_MAIN::render()
{
	if (scene_state_ == eSCENE_STATE::SELECT)
	{
		select_map_->render();		
	}
	else
	{
		grid_->render();
	}
	
	WCHAR ch[100];
	wsprintf(ch, L"camera: %d, %d", 
		cMAIN_GAME::getInstance()->camera_->getPos().x,
		cMAIN_GAME::getInstance()->camera_->getPos().y);
	
	cMAIN_GAME::getInstance()->renderer_->textout(25, 25, L"scene: main");
	cMAIN_GAME::getInstance()->renderer_->textout(25, 50, ch);
}

void cSCENE_MAIN::exit()
{
	//delete this;	
}

