#include "stdafx.h"
#include "cSTATE_IDLE.h"
#include "cMONSTER_BASE.h"
#include <ctime>

cSTATE_IDLE::cSTATE_IDLE()
{
}

cSTATE_IDLE::~cSTATE_IDLE()
{
}

void cSTATE_IDLE::enter(cMONSTER_BASE* monster)
{
	
}

void cSTATE_IDLE::excute(cMONSTER_BASE* monster)
{ 
	
//	(monster->* func)(1);
	if (!monster->isSearchOn())
	{
		switch (monster->getMoveNum())
		{
		case 0:
			monster->moveLeft();
		break;
		case 1:
			monster->moveRight();
			break;
		case 2:
			monster->moveUp();
			break;
		case 3:
			monster->moveDown();
			break;
		default:
			break;
		}
		
	}
	else
	{
		//monster->changeState(std::ma)
	}
}

void cSTATE_IDLE::exit(cMONSTER_BASE* monster)
{

}
