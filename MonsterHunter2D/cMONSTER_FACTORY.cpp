#include "stdafx.h"
#include "cMONSTER_FACTORY.h"


cMONSTER_FACTORY::cMONSTER_FACTORY()
{
}
cMONSTER_FACTORY::~cMONSTER_FACTORY()
{
}


std::shared_ptr<cMONSTER_BASE> cMONSTER_FACTORY::createMonster(int index)
{
	switch (index)
	{
	case 1:
		return std::make_shared<cPANGGO>();	
	}
}
