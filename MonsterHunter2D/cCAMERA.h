#pragma once
#include "cGAME_OBJECT.h"

class cCAMERA
{
public:
	cCAMERA();
	~cCAMERA();

	void initCamera(const RECT& rt);	
	POINT getPostion();
	void setLimit(const RECT& limit);
	void setTarget(cGAME_OBJECT* target);
	void update(double delta);
	//���� ����ġ�� �Ѱ� ����.
	void vibrateSwitch();

private:
	int pos_x_, pos_y_;
	int width_, height_;
	RECT limits_;
	cGAME_OBJECT* target_;
	
	BOOL  vibrate_;
	//������ ���� �ӽ� �ɹ�
	POINT ctemp[7];
	int frame = 0;
	double temp = 0;

};

