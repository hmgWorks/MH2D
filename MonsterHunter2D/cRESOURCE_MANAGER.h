#pragma once
#include <fstream>
#include <string>
#include <vector>
#include "cGRID.h"

struct sMAP_DATA
{
	int width;
	int height;
	int count_x;
	int count_y;
	std::string potal_L_filename;
	std::string potal_T_filename;
	std::string potal_R_filename;
	std::string potal_B_filename;
	std::string floor_img;
	std::string background_img;
	std::string background_img2;
	std::vector<std::vector<char>> data_grid;
};

enum eMAP_DATA
{
	world_start, world_left, world_top,
	world_right, world_bottom
};

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

	void loadImage();

	//grid 관련 다시
	void loadMapData(std::vector<std::string>& file_names, 
		std::vector<sMAP_DATA>& map);
	

private:
	HINSTANCE hInst_;
	std::vector<std::string>map_jungle_file_names_;
	std::vector<sMAP_DATA> map_jungle_;
};

