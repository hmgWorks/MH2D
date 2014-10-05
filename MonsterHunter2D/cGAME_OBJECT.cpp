#include "stdafx.h"
#include "cGAME_OBJECT.h"


cGAME_OBJECT::cGAME_OBJECT()
{
}

cGAME_OBJECT::~cGAME_OBJECT()
{
}

void cGAME_OBJECT::setScreenPos(POINT screenPos)
{
	screen_x_ = pos_x_ - screenPos.x;
	screen_y_ = pos_y_ - screenPos.y;
}
