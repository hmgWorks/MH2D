#include "stdafx.h"
#include "cSCENE_MAIN.h"
#include "cMAIN_GAME.h"
#include "cPANGGO.h"

cSCENE_MAIN::cSCENE_MAIN()
{
	//grid_ = new cGRID;
	grid_ = std::make_shared<cGRID>();
	player_ = new cPLAYER_BASE;

}
cSCENE_MAIN::~cSCENE_MAIN()
{
	delete player_;
	player_ = nullptr;
	/*delete grid_;
	grid_ = nullptr;*/
}

void cSCENE_MAIN::enter()
{		
	grid_->initGrid(cMAIN_GAME::getInstance()->resource_->map_data_[eMAP_DATA::MAP1_1]);

	/*
		�÷��̾��� ��ġ�� �Ѱ��� ������ �׸��忡 ���� �Ǿ�� ��.
		�׸���(����)����� �÷��̾��� ��ġ�� �Ѱ谡 ���� �ž�� ��.
		ī�޶�� �÷��̾ ���ӵ�
	*/
	grid_->initPlayer1(player_);	
	player_->setLimits(grid_->getGridLimits());	
	cMAIN_GAME::getInstance()->camera_->setLimit(grid_->getGridLimits());	
	cMAIN_GAME::getInstance()->camera_->setTarget(player_);
}

void cSCENE_MAIN::update(double delta)
{
	//���α׷� ����
	if (cMAIN_GAME::getInstance()->input_->getDownKey_once(VK_ESCAPE))
		::DestroyWindow(cMAIN_GAME::getInstance()->hWnd_);	
	if (cMAIN_GAME::getInstance()->input_->getDownKey_once(VK_INSERT))
		v_monster_.push_back(new cPANGGO(cMAIN_GAME::getInstance()->input_->getMouse(),grid_->getGridLimits()));
		
	if (cMAIN_GAME::getInstance()->input_->getDownKey_once('W'))
		cMAIN_GAME::getInstance()->camera_->vibrateSwitch();
	
	grid_->update(delta);
	//player_->update(delta);	

	/*if (!v_monster_.empty())
		for (auto x : v_monster_)
			if (dynamic_cast<cMONSTER_BASE*>(x)->isAlive())				
				x->update(delta);*/
	
	cMAIN_GAME::getInstance()->camera_->update(delta);	

	grid_->setTileMap(player_);
	
	//����ȯ �� ��ü ����
	if (!v_monster_.empty())
		for (auto x : v_monster_)
			grid_->setTileMap(x);
	grid_->checkCollision(player_);
	
}

void cSCENE_MAIN::render()
{
	grid_->render();
	//player_->render();
	
	/*if (!v_monster_.empty())
	for (auto x : v_monster_)
		if (dynamic_cast<cMONSTER_BASE*>(x)->isAlive())
			x->render();*/
	
	WCHAR ch[100];
	wsprintf(ch, L"camera: %d, %d", 
		cMAIN_GAME::getInstance()->camera_->getPostion().x,
		cMAIN_GAME::getInstance()->camera_->getPostion().y);
	
	cMAIN_GAME::getInstance()->renderer_->textout(25, 25, L"scene: main");
	cMAIN_GAME::getInstance()->renderer_->textout(25, 50, ch);
}

void cSCENE_MAIN::exit()
{
	//delete this;	
}

