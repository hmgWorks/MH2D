#pragma once
#include "iSCENE_BASE.h"
#include "cMAIN_GAME.h"
#include "cPLAYER_BASE.h"

class cSCENE_INTRO :
	public iSCENE_BASE
{
public:
	cSCENE_INTRO();
	~cSCENE_INTRO();

public:
	void enter();
	void update(double delta);
	void render();
	void exit();

private:
	//cPLAYER_BASE* player_;
	
};

