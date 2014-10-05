#pragma once

__interface iGAME_OBJECT	
{
	void update(double delta);
	void render();

	POINT getPosition();
	void setPosition(int x, int y);
	//面倒贸府甫 夸没
	void checkCollision(iGAME_OBJECT* object);
	//磊脚狼 面倒贸府
	void procCollision();
	//tile map
	void setCellPos(POINT cell_pos);
	POINT getCellPos();
};