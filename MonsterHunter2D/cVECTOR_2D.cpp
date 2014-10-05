#include "stdafx.h"
#include "cVECTOR_2D.h"
#include <cmath>
namespace hmg
{
	cVECTOR_2D::cVECTOR_2D()
	{
	}
	
	cVECTOR_2D::cVECTOR_2D(double x, double y)
	{
		x_ = x;
		y_ = y;
	}	

	cVECTOR_2D::~cVECTOR_2D()
	{
	}
	
	cVECTOR_2D cVECTOR_2D::operator+(const cVECTOR_2D& vec)
	{
		return cVECTOR_2D(x_ + vec.x_, y_ + vec.y_);
	}
	
	cVECTOR_2D cVECTOR_2D::operator-(const cVECTOR_2D& vec)
	{
		return cVECTOR_2D(x_ - vec.x_, y_ - vec.y_);
	}	
	//백터가 1일때의 x,y 를 nomalize
	void cVECTOR_2D::normalize()
	{
		distance_ = sqrt(x_ * x_ + y_ * y_);
		nomal_x_ = x_ / distance_;
		nomal_y_ = y_ / distance_;
	}
	
	/*cVECTOR_2D cVECTOR_2D::operator*(double val)
	{
		return cVECTOR_2D(x_*val, y_*val);
	}*/	
}
