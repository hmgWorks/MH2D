#include "stdafx.h"
#include "cPLAYER_BASE.h"
#include "cMAIN_GAME.h"

cPLAYER_BASE::cPLAYER_BASE()
{	
	unique_weapon_ = std::unique_ptr<cWEAPONS>(new cWEAPONS);
	mode_ = MODE::IDLE;
	collision_on = FALSE;
	cell_pos_ = { -1, };
	//스텟
	hp_ = 100;
	strong_ = 100;
	attack_damage_ = 10 + unique_weapon_->getAttackDamage();
	defense_ = 30;
	move_speed_ = 5;
}
cPLAYER_BASE::~cPLAYER_BASE()
{

}

void cPLAYER_BASE::update(double delta)
{
	
	if (cMAIN_GAME::getInstance()->input_->getDownKey(VK_LEFT))
		moveLeft();
	if (cMAIN_GAME::getInstance()->input_->getDownKey(VK_RIGHT))
		moveRight();
	if (cMAIN_GAME::getInstance()->input_->getDownKey(VK_UP))
		moveUp();
	if (cMAIN_GAME::getInstance()->input_->getDownKey(VK_DOWN))
		moveDown();
	if (cMAIN_GAME::getInstance()->input_->getDownKey_once('Q'))
		changeMode();
	//카메라는 플래이어의 위치를 따라감(옵저버를 쓰면 좋을것 같은데
//	cMAIN_GAME::getInstance()->camera_->update();
	

	//스크린 좌표
	setScreenPos(cMAIN_GAME::getInstance()->camera_->getPostion());
	collision_ = { pos_x_ - 15, pos_y_ - 100, pos_x_ + 15, pos_y_ };
}

void cPLAYER_BASE::render()
{
	WCHAR ch[100];
	wsprintf(ch, L"%d, %d", pos_x_, pos_y_);
	
	cMAIN_GAME::getInstance()->renderer_->rectangel(
		collision_.left - cMAIN_GAME::getInstance()->camera_->getPostion().x,
		collision_.top - cMAIN_GAME::getInstance()->camera_->getPostion().y,
		collision_.right - cMAIN_GAME::getInstance()->camera_->getPostion().x,
		collision_.bottom - cMAIN_GAME::getInstance()->camera_->getPostion().y);
	
	cMAIN_GAME::getInstance()->renderer_->textout(screen_x_, screen_y_, ch);	
}

void cPLAYER_BASE::checkCollision(cGAME_OBJECT* enemy)
{

}

void cPLAYER_BASE::changeMode()
{
	(mode_ == MODE::IDLE) ? mode_ = MODE::ATTACT : mode_ = MODE::IDLE;
	if (mode_ == MODE::ATTACT)
	{
		move_speed_ += unique_weapon_->getMoveSpeed();
	}
	else
	{
		move_speed_ -= unique_weapon_->getMoveSpeed();
	}
}

//키처리
void cPLAYER_BASE::moveLeft()
{
	int temp = pos_x_;
	temp -= move_speed_;

	if (temp <= limits_.left)
		pos_x_ = limits_.left;
	else
		pos_x_ = temp;	
}
void cPLAYER_BASE::moveRight()
{
	int temp = pos_x_;
	temp += move_speed_;

	if (temp > limits_.right)
		pos_x_ = limits_.right;
	else
		pos_x_ = temp;
}
void cPLAYER_BASE::moveUp()
{
	int temp = pos_y_;
	temp -= move_speed_;

	if (temp < limits_.top)
		pos_y_ = limits_.top;
	else
		pos_y_ = temp;
}
void cPLAYER_BASE::moveDown()
{
	int temp = pos_y_;
	temp += move_speed_;

	if (temp > limits_.bottom)
		pos_y_ = limits_.bottom;
	else
		pos_y_ = temp;
}
void cPLAYER_BASE::attackA()
{

}
void cPLAYER_BASE::attackS()
{

}
void cPLAYER_BASE::attackD()
{

}

//void cPLAYER_BASE::setScreenPos(POINT screenPos)
//{
//	screen_x_ = pos_x_ - screenPos.x;
//	screen_y_ = pos_y_ - screenPos.y;
//}

//void cPLAYER_BASE::setLimits(const RECT& limits)
//{
//	limits_ = limits;
//}