#include "stdafx.h"
#include "cMONSTER_BASE.h"
#include "cMAIN_GAME.h"

cMONSTER_BASE::cMONSTER_BASE()
{

}

cMONSTER_BASE::cMONSTER_BASE(POINT pos)
{	
	//screen_x_ = pos.x;
	//screen_y_ = pos.y;
	//pos_x_ = screen_x_ + cMAIN_GAME::getInstance()->camera_->getPostion().x;
	//pos_y_ = screen_y_ + cMAIN_GAME::getInstance()->camera_->getPostion().y;
	//hp_ = 100;
	//hp_max_ = 100;
	//alive_ = TRUE;
	//cell_pos_ = { -1, };
	////test code
	//hp_bar_w_ = 50;
	//hp_bar_h_ = 5;
	
}

cMONSTER_BASE::~cMONSTER_BASE()
{
}

void cMONSTER_BASE::update(double delta)
{
	//setScreenPos(cMAIN_GAME::getInstance()->camera_->getPostion());	
	//
	////test code	
	//(hp_ > 0) ? hp_ : alive_ = FALSE;
}

void cMONSTER_BASE::render()
{
	////test code
	//if (alive_)
	//{
	//	int hp;
	//	hp = hp_bar_w_ - ((hp_bar_w_ * (hp_max_ - hp_)) / hp_max_);
	//	
	//	cMAIN_GAME::getInstance()->renderer_->rectangel(screen_x_ - 15, screen_y_ - 100, screen_x_ + 15, screen_y_);
	//
	//	cMAIN_GAME::getInstance()->renderer_->selectBrush(RGB(255, 0, 0));
	//	cMAIN_GAME::getInstance()->renderer_->rectangel(screen_x_ - hp_bar_w_ / 2, screen_y_ - 110,
	//		screen_x_ - (hp_bar_w_ / 2) + hp, screen_y_ - 105);
	//	cMAIN_GAME::getInstance()->renderer_->deleteBrush();	
	//}
}

void cMONSTER_BASE::changeState(std::shared_ptr<iSTATE> state)
{
	if (state_ == nullptr)
	{
		state_ = state;
		state_->enter(this);
	}
	else
	{
		state_->exit(this);
		state_ = state;
		state_->enter(this);
	}
}

void cMONSTER_BASE::moveLeft(int speed)
{
	int temp = pos_x_;
	temp -= (move_speed_ * speed);
	if (temp > limits_.left)
		pos_x_ = temp;
	//pos_x_ -= (move_speed_ * speed);
}

void cMONSTER_BASE::moveRight(int speed)
{
	int temp = pos_x_;
	temp += (move_speed_ * speed);
	if (temp < limits_.right)
		pos_x_ = temp;
	//pos_x_ += (move_speed_ * speed);
}

void cMONSTER_BASE::moveUp(int speed)
{
	int temp = pos_y_;
	temp -= (move_speed_ * speed);
	if (temp > limits_.top)
		pos_y_ = temp;
	//pos_y_ -= (move_speed_ * speed);
}

void cMONSTER_BASE::moveDown(int speed)
{
	int temp = pos_y_;
	temp += (move_speed_ * speed);
	if (temp < limits_.bottom)
		pos_y_ = temp;
	//pos_y_ += (move_speed_ * speed);
}

void cMONSTER_BASE::checkCollision(cGAME_OBJECT* enemy)
{
	
}