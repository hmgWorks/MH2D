#pragma once
#include "cGAME_OBJECT.h"
#include <memory>
class cCAMERA
{
public:
	cCAMERA();
	~cCAMERA();

	void initCamera(const RECT& rt);	
	void setLimit(const RECT& limit);
	void setPos(POINT pos){ pos_x_ = pos.x; pos_y_ = pos.y; }
	POINT getPos(){ return{ pos_x_, pos_y_ }; }
	
	//void setTarget(cGAME_OBJECT* target);
	void setTarget(std::shared_ptr<cGAME_OBJECT> target);
	void update(double delta);
	//진동 스위치를 켜고 끈다.
	void vibrateSwitch();

private:	
	int pos_x_, pos_y_;
	int width_, height_;
	RECT limits_;

	std::shared_ptr<cGAME_OBJECT> target_;
	//int screen_x_, screen_y_;
	BOOL  vibrate_;
	//진동을 위한 임시 맴버
	POINT ctemp[7];
	int frame = 0;
	double temp = 0;

};

