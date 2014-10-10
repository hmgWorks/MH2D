#pragma once
#include <list>
#include <memory>
#include "cGAME_OBJECT.h"
#include "hmg_DATA.h"
#include "cSCENE_MAIN.h"

class cGRID
{
public:
	cGRID();	
	~cGRID();

	void update(double delta);
	void render();

	void setTileMap(std::shared_ptr<cGAME_OBJECT>& object);

	void insertMapObj();

	//그리드 다시
	void initMap(std::vector<std::vector<sMAP_DATA>>& data_map,
		std::shared_ptr<cGAME_OBJECT>& player, int map_name);
	void setMap(std::shared_ptr<cGAME_OBJECT>& obj);
	void checkCollision(std::shared_ptr<cGAME_OBJECT>& obj, cSCENE_MAIN* scene);

private:
	
	RECT limits_grid_;
	char map_key_;

	//cGRID 다시
	sMAP_DATA current_map_data_;
	std::vector<sMAP_DATA> current_map_;
	std::vector<std::vector<sMAP_DATA>> maps_;
	std::vector<std::vector<std::list<std::shared_ptr<cGAME_OBJECT>>>> obj_grid_;
	int map_data_index_;
	int map_name_;
		
};