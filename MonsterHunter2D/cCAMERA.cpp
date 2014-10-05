#include "stdafx.h"
#include "cCAMERA.h"


cCAMERA::cCAMERA()
{
	limits_ = { -1, };
	vibrate_ = FALSE;

	ctemp[0] = { 0, -3 };
	ctemp[1] = { 3, 0 };
	ctemp[2] = { 0, 3 };
	ctemp[3] = { 0, 0 };
	ctemp[4] = { -3, 0 };
	ctemp[5] = { 0, 0 };
	ctemp[6] = { 3, 0 };
}

cCAMERA::~cCAMERA()
{
}

void cCAMERA::initCamera(const RECT& rt)
{
	width_ = rt.right - rt.left;
	height_ = rt.bottom - rt.top;
}

POINT cCAMERA::getPostion()
{
	return{ pos_x_, pos_y_ }; 
}

void cCAMERA::update(double delta)
{ 	
	if (limits_.left == -1)
	{
		pos_x_ = target_->getPos().x - (width_ / 2);
		pos_y_ = target_->getPos().y - (height_ / 4 * 3);
	}
	else
	{
		int temp_x = pos_x_, temp_y = pos_y_;
		temp_x = target_->getPos().x - (width_ / 2);
		temp_y = target_->getPos().y - (height_ / 4 * 3);
		
		if (temp_x <= limits_.left)
			pos_x_ = limits_.left;
		else if (temp_x >= limits_.right)
			pos_x_ = limits_.right;
		else
			pos_x_ = temp_x;

		/*if (temp_y < limit_.top)
			pos_y_ = limit_.top;*/
		if (temp_y >= limits_.bottom)
			pos_y_ = limits_.bottom;
		else
			pos_y_ = temp_y;		
	}	

	if (vibrate_)
	{
		temp += delta;
		if (temp < 0.5)
		{
			temp = 0;
			frame++;
			if (frame > 6)
				frame = 0;
		}

		pos_x_ += ctemp[frame].x;
		pos_y_ += ctemp[frame].y;
	}
	
}

void cCAMERA::setLimit(const RECT& limit)
{
	limits_ = { 
		limit.left, 
		limit.top, 
		limit.right - width_, 
		limit.bottom - height_ 
	};

}
void cCAMERA::setTarget(cGAME_OBJECT* target)
{
	target_ = target;
}
void cCAMERA::vibrateSwitch()
{
	vibrate_ = !vibrate_;

}