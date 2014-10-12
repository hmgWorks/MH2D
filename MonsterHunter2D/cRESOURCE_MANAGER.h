#pragma once
#include <fstream>
#include <string>
#include <vector>
#include "cGRID.h"
#include "hmg_DATA.h"

class cRESOURCE_MANAGER
{
public:
	cRESOURCE_MANAGER();
	cRESOURCE_MANAGER(HINSTANCE hInst);
	~cRESOURCE_MANAGER();

	void createFile(std::string filename);
	void saveFile(std::string filename);
	void readFile(std::string filename);

	void saveMapFile(std::string filename, cGRID& grid);
	void readMapFile(std::string filename, cGRID& grid);

	void createPlayerFile(std::string filename);


	//grid ���� �ٽ�
	void loadMapData(std::vector<std::string>& file_names, 
		std::vector<sMAP_DATA>& map);
	
	void saveMapData(std::vector<std::string>& file_names,
		std::vector<sMAP_DATA>& map);
	
	std::vector<std::vector<sMAP_DATA>>& getMapData();
	void setMapData(std::vector<std::vector<sMAP_DATA>> map_data);

	//image
	void loadImage(HBITMAP& hImg, int index);
	
	
	WCHAR hunter_name_[128];
private:
	HINSTANCE hInst_;
	
	std::vector<sMAP_DATA> map_world_;
	std::vector<std::string> map_world_file_names_;
	
	std::vector<sMAP_DATA> map_jungle_;
	std::vector<std::string> map_jungle_file_names_;
	
	std::vector<std::vector<sMAP_DATA>> maps_;

	//bitmap
	HBITMAP world_background_1_;
	std::vector<LPCWSTR> imgFileList_;

};

