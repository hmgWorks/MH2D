#pragma once
#include <list>
#include "cGAME_OBJECT.h"
#include "hmg_DATA.h"
#include <memory>
//struct sMAP_DATA;

class cGRID
{
public:
	cGRID();	
	~cGRID();

	void update(double delta);
	void render();
		
	void setMap(std::shared_ptr<cGAME_OBJECT>& obj);
	
	RECT getGridLimits();
	int getWidth(){ return width_; }
	int getHeight(){ return height_; }
	int getCountX(){ return count_x_; }
	int getCountY(){ return count_y_; }
//	char** getGridMap(){ return grid_; }

	//충돌처리를 요청
	void checkCollision(std::shared_ptr<cGAME_OBJECT>& obj);
	//자신의 충돌처리
	//void procCollision(){};

	/*void setCellPos(POINT cell_pos){}
	POINT getCellPos(){ return{ 0, }; }
	*/
	void setTileMap(std::shared_ptr<cGAME_OBJECT>& object);
	void clearTileMap();
	void initPlayer1(cGAME_OBJECT* object);
	void initPlayer2(cGAME_OBJECT* object);

	void insertMapObj();
	void loadMapData();

	//그리드 다시
	void initMap(std::vector<std::vector<sMAP_DATA>>& data_map,
		std::shared_ptr<cGAME_OBJECT>& player);

private:
	void clearMapTable();
	void createMapTable();
	void loadFileData();

private:
	int pos_x_, pos_y_;
	int width_, height_;
	int count_x_, count_y_;
	RECT limits_grid_;
	//char** grid_;
	char map_key_;

	//cGRID 다시
	sMAP_DATA current_map_data_;
	std::vector<sMAP_DATA> current_map_;
	std::vector<std::vector<sMAP_DATA>> maps_;
	std::vector<std::vector<std::list<std::shared_ptr<cGAME_OBJECT>>>> obj_grid_;
	int map_data_index_;
	
};