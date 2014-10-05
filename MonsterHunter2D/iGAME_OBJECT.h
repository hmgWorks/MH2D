#pragma once

__interface iGAME_OBJECT	
{
	void update(double delta);
	void render();

	POINT getPosition();
	void setPosition(int x, int y);
	//�浹ó���� ��û
	void checkCollision(iGAME_OBJECT* object);
	//�ڽ��� �浹ó��
	void procCollision();
	//tile map
	void setCellPos(POINT cell_pos);
	POINT getCellPos();
};