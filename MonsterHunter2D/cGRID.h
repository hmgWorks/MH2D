#pragma once
#include <list>
#include "cGAME_OBJECT.h"
#include "hmg_DATA.h"
struct sMAP_DATA;

class cGRID
{
public:
	cGRID();	
	~cGRID();

	void update(double delta);
	void render();
	
	
	//POINT getPosition(){ return{ pos_x_, pos_y_ }; };
	//void setPosition(int x, int y){ pos_x_ = x, pos_y_ = y; };
	
	void initMap(std::vector<sMAP_DATA> map);
	
	void setMap();
	
	RECT getGridLimits();
	int getWidth(){ return width_; }
	int getHeight(){ return height_; }
	int getCountX(){ return count_x_; }
	int getCountY(){ return count_y_; }
	char** getGridMap(){ return grid_; }

	//面倒贸府甫 夸没
	void checkCollision(cGAME_OBJECT* object);
	//磊脚狼 面倒贸府
	//void procCollision(){};

	/*void setCellPos(POINT cell_pos){}
	POINT getCellPos(){ return{ 0, }; }
	*/
	void setTileMap(cGAME_OBJECT* object);
	void clearTileMap();
	void initPlayer1(cGAME_OBJECT* object);
	void initPlayer2(cGAME_OBJECT* object);

	void insertMapObj();
	void loadMapData();

private:
	void clearMapTable();
	void createMapTable();
	void loadFileData();

private:
	int pos_x_, pos_y_;
	int width_, height_;
	int count_x_, count_y_;
	RECT limits_grid_;
	char** grid_;
	char map_key_;

public:
	sMAP_DATA current_map_data_;
	std::vector<sMAP_DATA> current_map_;
	std::list<cGAME_OBJECT*>** obj_grid_;
	
};