#pragma once
#include "iSTATE.h"
class cSTATE_IDLE :
	public iSTATE
{
public:
	cSTATE_IDLE();
	virtual ~cSTATE_IDLE();

	void enter(cMONSTER_BASE* monster);
	void excute(cMONSTER_BASE* monster);
	void exit(cMONSTER_BASE* monster);
};

