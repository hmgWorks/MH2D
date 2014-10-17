#pragma once
#include "cGAME_OBJECT.h"
#include "cWEAPONS.h"
#include <memory>
#include <unordered_map>
enum class MODE { IDLE, ATTACT };

class cPLAYER_BASE :
	public cGAME_OBJECT
{
public:
	cPLAYER_BASE();
	virtual ~cPLAYER_BASE();

	virtual void update(double delta);
	virtual void render();

	//collision	
	virtual void checkCollision(cGAME_OBJECT* enemy);
	//void procCollision(){};

	//mode
	void changeMode();

	//Űó��
	void moveLeft();
	void moveRight();
	void moveUp();
	void moveDown();
	void attackA();
	void attackS();
	void attackD();
	
private:
	RECT collision_;
	BOOL collision_on;
	MODE mode_;
	std::unique_ptr<cWEAPONS> unique_weapon_;
	
	//�������ͽ�
	int hp_;
	int strong_;
	int attack_damage_;//���ݷ� �߰�
	int defense_;//���� �߰�
	int move_speed_;//�̼� �߰�	

	//����Ʈ
	std::vector<int> monsters_;
	std::unordered_map<int, std::vector<int>> list_of_monster_;
	

};

