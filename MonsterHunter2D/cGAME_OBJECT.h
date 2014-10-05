#pragma once

class cGAME_OBJECT
{
public:
	cGAME_OBJECT();
	virtual ~cGAME_OBJECT();

	virtual void update(double delta) = 0;
	virtual void render() = 0;	
	virtual void checkCollision(cGAME_OBJECT* enemy) = 0;
	//오브젝트의 위치
	void setPos(POINT pos){ pos_x_ = pos.x; pos_y_ = pos.y; }
	POINT getPos(){ return{ pos_x_, pos_y_ }; }
	//위치를 샐단위로
	void setCellPos(POINT cell_pos){ cell_pos_ = cell_pos; }
	POINT getCellPos(){ return cell_pos_; }
	//화면 출력을 위한
	void setScreenPos(POINT screenPos);
	void setLimits(const RECT& limits){ limits_ = limits; }
	
protected:
	int pos_x_, pos_y_;
	int screen_x_, screen_y_;
	
	RECT limits_;
	POINT cell_pos_;
};

