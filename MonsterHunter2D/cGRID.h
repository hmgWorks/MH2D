#pragma once
#include <list>
#include <memory>
#include "cGAME_OBJECT.h"
#include "hmg_DATA.h"
//#include "cSCENE_MAIN.h"
class cSCENE_MAIN;
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
	//void initMap(std::vector<std::vector<sMAP_DATA>>& data_map,
	//	std::shared_ptr<cGAME_OBJECT>& player, int map_name);
	void initMap(std::shared_ptr<cGAME_OBJECT>& player, int map_name);

	void setMap(std::shared_ptr<cGAME_OBJECT>& obj);
	void checkCollision(std::shared_ptr<cGAME_OBJECT>& obj, cSCENE_MAIN* scene);

private:
	
	RECT limits_grid_;
	//맵제작할떼 쓴거
	char map_key_;
		
	std::vector<std::string> map_world_file_names_;
	std::vector<std::string> map_jungle_file_names_;
	std::vector<std::vector<std::string>> map_files_;

	//cGRID 다시
	sMAP_DATA current_map_data_;
	std::vector<sMAP_DATA> current_map_;
	
	//obj출력 순서를 위해 obj 를 담아둔다.
	std::vector<std::vector<std::list<std::shared_ptr<cGAME_OBJECT>>>> obj_grid_;

	int map_data_index_;
	int map_name_;

	//background img
	HBITMAP world_background_1_;
	HBITMAP world_floor_1_;
	std::vector<WCHAR*> bg_imgs_world_;
	std::vector<WCHAR*> bg_imgs_jungle_;
	std::vector<std::vector<WCHAR*>> bg_img_maps_;
		
	int tl, tt;
};