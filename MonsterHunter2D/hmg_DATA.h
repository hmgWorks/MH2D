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
	world = 0,
	map_jungle
};
enum eSCENE_STATE
{
	WORLD = 0, 
	SELECT, 
	DUNGEON, 
	END 
};

enum eIMG_LIST
{
	WORLD_BACKGROUND_1
};
