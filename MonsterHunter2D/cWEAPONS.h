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
	int hp_;//������ 
	int attack_damage_;//���ݷ� �߰�
	int defense_;//���� �߰�
	int move_speed_;//�̼� �߰�

	RECT collision_;

};

