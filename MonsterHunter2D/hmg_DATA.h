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
	std::string background_img;
	std::string background_img2;
	std::string floor_img;
	int background_img_pos_x;
	int background_img_pos_y;
	int background_img2_pos_x;
	int background_img2_pos_y;
	int floor_img_pos_x;
	int floor_img_pos_y;
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
