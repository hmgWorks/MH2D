#pragma once
#include <memory>
#include <functional>
#include "cGAME_OBJECT.h"
#include "iSTATE.h"

class cMONSTER_BASE :
	public cGAME_OBJECT
{
public:
	cMONSTER_BASE();
	cMONSTER_BASE(POINT pos);
	virtual ~cMONSTER_BASE();
	
	virtual void update(double delta);
	virtual void render();
	virtual void checkCollision(cGAME_OBJECT* enemy);
	
	BOOL isAlive(){ return alive_; }
	void changeState(std::shared_ptr<iSTATE> state);

	BOOL isSearchOn(){ return search_on_; }

	void moveLeft(int speed = 1);
	void moveRight(int speed = 1);
	void moveUp(int	 speed = 1);
	void moveDown(int speed = 1);
	
	int getMoveNum(){ return move_num_; }
	//void(cMONSTER_BASE::*func)(int);
protected:
	RECT collision_;
	BOOL alive_;
	//스테이터스
	int hp_, hp_max_;	
	int attack_damage_;//공격력 추가
	int defense_;//방어력 추가
	int move_speed_;
	std::shared_ptr<iSTATE> state_;

	//test code
	int width_, height_;
	int offset_x_, offset_y_;
	int hp_bar_w_, hp_bar_h_;
	BOOL search_on_;
	int move_destance_;
	POINT old_pos_;
	int move_num_;
	int temp_num_;
};

