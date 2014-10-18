#pragma once
#include <fstream>
#include <string>
#include <vector>
#include "hmg_DATA.h"
//#include "cGRID.h"

class cRESOURCE_MANAGER
{
public:
	cRESOURCE_MANAGER(HINSTANCE hInst);
	~cRESOURCE_MANAGER();

	void createFile(std::string filename);
	void saveFile(std::string filename);
	void readFile(std::string filename);

	//void createPalyerFile(std::string filename);

	//grid 관련 다시
	void loadMapData(std::vector<std::string>& file_names, 
		std::vector<sMAP_DATA>& map);

	void saveMapData(std::string file_name, sMAP_DATA data);

	//image
	//void loadImage(HBITMAP& hImg, const WCHAR* img_name);
	void loadImage(HBITMAP& hImg, std::string img_name);

private:
	HINSTANCE hInst_;
	WCHAR hunter_name_[128];

};

