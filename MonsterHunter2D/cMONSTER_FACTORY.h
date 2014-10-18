#pragma once
#include "cPANGGO.h"

class cMONSTER_BASE;
class cMONSTER_FACTORY
{
public:
	cMONSTER_FACTORY();
	~cMONSTER_FACTORY();

	
	std::shared_ptr<cMONSTER_BASE> createMonster(int index);
};

