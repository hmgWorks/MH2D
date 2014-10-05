#pragma once
#include "cMONSTER_BASE.h"
#include "iSTATE.h"
class cPANGGO :
	public cMONSTER_BASE
{
public:
	cPANGGO();
	cPANGGO(POINT pos, RECT limit);
	virtual ~cPANGGO();
	virtual void update(double delta);
	virtual void render();
	virtual void checkCollision(cGAME_OBJECT* enemy);
	
private:
	
};

