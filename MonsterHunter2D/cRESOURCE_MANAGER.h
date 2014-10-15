#pragma once
#include <fstream>
#include <string>
#include <vector>
#include "cGRID.h"

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


	//grid 관련 다시
	void loadMapData(std::vector<std::string>& file_names, 
		std::vector<sMAP_DATA>& map);
	
	void saveMapData(std::vector<std::string>& file_names,
		std::vector<sMAP_DATA>& map);	

	//image
	void loadImage(HBITMAP& hImg, WCHAR* img_name);
	
	WCHAR hunter_name_[128];

private:
	HINSTANCE hInst_;

};

