#pragma once

namespace hmg
{	
	class cVECTOR_2D
	{
	public:
		cVECTOR_2D();
		cVECTOR_2D(double x, double y);
		~cVECTOR_2D();
		
		cVECTOR_2D operator+(const cVECTOR_2D& src);
		cVECTOR_2D operator-(const cVECTOR_2D& src);
		//cVECTOR_2D operator*(double val);
		void normalize();
		
		double getNomal_X(){ return nomal_x_; }
		double getNomal_Y(){ return nomal_y_; }
		POINT getNomal(){ return{ static_cast<LONG>(nomal_x_), static_cast<LONG>(nomal_y_) }; }
		double getDistance(){ return distance_; }
		
	private:
		double x_, y_;
		double distance_;
		double nomal_x_, nomal_y_;

	};
}

