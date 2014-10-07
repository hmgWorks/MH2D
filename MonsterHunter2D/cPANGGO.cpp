#include "stdafx.h"
#include "cPANGGO.h"
#include "cMAIN_GAME.h"
#include "cSTATE_IDLE.h"
#include <ctime>

cPANGGO::cPANGGO()
{
}

cPANGGO::cPANGGO(POINT pos, RECT limit)
{
	screen_x_ = pos.x;
	screen_y_ = pos.y;
	pos_x_ = screen_x_ + cMAIN_GAME::getInstance()->camera_->getPos().x;
	pos_y_ = screen_y_ + cMAIN_GAME::getInstance()->camera_->getPos().y;

	hp_ = 100;
	hp_max_ = 100;
	alive_ = TRUE;
	cell_pos_ = { -1, };
	move_speed_ = 2;
	limits_ = limit;
	state_ = nullptr;
	changeState(std::make_shared<cSTATE_IDLE>());
	//test code
	hp_bar_w_ = 50;
	hp_bar_h_ = 5;
	search_on_ = FALSE;
	move_destance_ = 300;
	old_pos_.x = pos_x_;
	old_pos_.y = pos_y_;
	srand(time(NULL));
	move_num_ = rand() % 4;
	temp_num_ = 0;
}

cPANGGO::~cPANGGO()
{
}
void cPANGGO::update(double delta)
{	
	setScreenPos(cMAIN_GAME::getInstance()->camera_->getPos());
	/*if (abs(old_pos_.x - pos_x_) < move_destance_)	
		func = &cPANGGO::moveLeft;
	else
		func = &cPANGGO::moveRight;*/
	temp_num_ += 1;
	if (temp_num_ >= 50)
	{
		temp_num_ = 0;
		move_num_ = rand() % 6;
	}
	state_->excute(this);
	//test code	
	(hp_ > 0) ? hp_ : alive_ = FALSE;
}

void cPANGGO::render()
{
	//test code
	if (alive_)
	{
		int hp;
		hp = hp_bar_w_ - ((hp_bar_w_ * (hp_max_ - hp_)) / hp_max_);

		cMAIN_GAME::getInstance()->renderer_->rectangel(screen_x_ - 15, screen_y_ - 100, screen_x_ + 15, screen_y_);

		cMAIN_GAME::getInstance()->renderer_->selectBrush(RGB(255, 0, 0));
		cMAIN_GAME::getInstance()->renderer_->rectangel(screen_x_ - hp_bar_w_ / 2, screen_y_ - 110,
			screen_x_ - (hp_bar_w_ / 2) + hp, screen_y_ - 105);
		cMAIN_GAME::getInstance()->renderer_->deleteBrush();
	}
}

void cPANGGO::checkCollision(cGAME_OBJECT* enemy)
{
	if (abs(enemy->getPos().x - pos_x_) < 300)
		search_on_ = TRUE;
	else
	{
		search_on_ = FALSE;
	}

}
