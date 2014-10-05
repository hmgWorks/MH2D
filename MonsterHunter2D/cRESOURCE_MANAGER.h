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
	std::string filename;
	std::string potal_L_filename;
	std::string potal_T_filename;
	std::string potal_R_filename;
	std::string potal_B_filename;
	std::string floor_img;
	std::string background_img;
	std::string background_img2;
};
enum eMAP_DATA
{
	MAP1_1, MAP1_2, MAP1_3,
	MAP2_1, MAP2_2, MAP2_3
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
//private:
	std::vector<sMAP_DATA> map_data_;
private:
	HINSTANCE hInst_;
};

