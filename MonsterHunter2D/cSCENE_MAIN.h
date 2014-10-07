#pragma once
#include <vector>

#include "cGAME_OBJECT.h"
#include "iSCENE_BASE.h"
#include "cPLAYER_BASE.h"
#include "cMONSTER_BASE.h"
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

private:	
	
	std::shared_ptr<cGAME_OBJECT> player_;
	std::vector<std::shared_ptr<cGAME_OBJECT>> v_monster_;
	std::shared_ptr<cGRID> grid_;

};


