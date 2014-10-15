#pragma once
#include <string>
#include <vector>

struct sMAP_DATA
{
	int width;
	int height;
	int count_x;
	int count_y;
	int potal_L_filename;
	int potal_T_filename;
	int potal_R_filename;
	int potal_B_filename;
	int background_img;
	int background_img2;
	int floor_img;
	std::vector<std::vector<char>> data_grid;
};

enum eSCENE_STATE
{
	WORLD = 0, 
	SELECT, 
	DUNGEON, 
	END 
};

enum eMAP_NAME
{
	world = 0,
	map_jungle
};
