#pragma once
#include <Windows.h>
class cWEAPONS
{
public:
	cWEAPONS();
	~cWEAPONS();

	//
	int getHp(){ return hp_; }
	int getAttackDamage(){ return attack_damage_; }
	int getDefense(){ return defense_; }
	int getMoveSpeed(){ return move_speed_; }

private:
	int hp_;//예리도 
	int attack_damage_;//공격력 추가
	int defense_;//방어력 추가
	int move_speed_;//이속 추가

	RECT collision_;

};

