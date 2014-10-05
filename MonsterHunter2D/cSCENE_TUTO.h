#pragma once
#include "iSCENE_BASE.h"
#include "cMAIN_GAME.h"
class cSCENE_TUTO :
	public iSCENE_BASE
{
public:
	cSCENE_TUTO();
	~cSCENE_TUTO();

	void enter();
	void update(double delta);
	void render();
	void exit();
};

