#pragma once
#include <string>
#include <vector>

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
enum eMAP_NAME
{
	map_jungle = 0
};
