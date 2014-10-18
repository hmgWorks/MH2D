#pragma once
#include <vector>

#include "cGAME_OBJECT.h"
#include "iSCENE_BASE.h"
#include "cPLAYER_BASE.h"
#include "cMONSTER_BASE.h"
#include "cSELECT_MAP.h"
#include "cGRID.h"

class cSCENE_MAIN :
	public iSCENE_BASE
{
public:
	cSCENE_MAIN();
	~cSCENE_MAIN();

	void enter();
	void update(double delta);
	void render();
	void exit();

	void changeSceneState(int scene_state){ scene_state_ = scene_state; }

private:
/*
	scene_state_�� �⺻ ���۽ÿ� ������ ����ϸ� �÷��̾��� �ൿ�� ����
	���¸� �����Ѵ�.
*/
	int scene_state_;

	std::shared_ptr<cGAME_OBJECT> player_;
	std::vector<std::shared_ptr<cGAME_OBJECT>> v_monsters_;
	std::shared_ptr<cGRID> grid_;

	std::shared_ptr<cSELECT_MAP> select_map_;

	
};


