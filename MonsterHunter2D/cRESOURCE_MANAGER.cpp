#include "stdafx.h"
#include "cRESOURCE_MANAGER.h"
#include <io.h>
#include <stdlib.h>


cRESOURCE_MANAGER::cRESOURCE_MANAGER(HINSTANCE hInst)
{
	hInst_ = hInst;	
}
cRESOURCE_MANAGER::~cRESOURCE_MANAGER()
{
	
}

void cRESOURCE_MANAGER::loadMapData(std::vector<std::string>& file_names,
	std::vector<sMAP_DATA>& map)
{
	for (int i = 0; i < file_names.size(); i++)
	{
		std::ifstream ifile(file_names[i]);
		{
			sMAP_DATA data_;
			ifile >> data_.width
				>> data_.height
				>> data_.count_x
				>> data_.count_y
				>> data_.potal_L_filename
				>> data_.potal_T_filename
				>> data_.potal_R_filename
				>> data_.potal_B_filename
				>> data_.background_img
				>> data_.background_img2
				>> data_.floor_img;
			for (int y = 0; y < data_.count_y; y++)
			{
				std::vector<char> data_row;
				for (int x = 0; x < data_.count_x; x++)
				{
					char ch;
					ifile >> ch;
					data_row.push_back(ch);
				}
				data_.data_grid.push_back(data_row);
				data_row.clear();
			}
			map.push_back(data_);
		}
		ifile.close();
	}
}

void cRESOURCE_MANAGER::saveMapData(std::string file_name, sMAP_DATA data)
{
	std::ofstream ofile(file_name);
	{		
		ofile << data.width << " "
			<< data.height << " "
			<< data.count_x << " "
			<< data.count_y << " " << std::endl
			<< data.potal_L_filename << std::endl
			<< data.potal_T_filename << std::endl
			<< data.potal_R_filename << std::endl
			<< data.potal_B_filename << std::endl
			<< data.background_img << std::endl
			<< data.background_img2 << std::endl
			<< data.floor_img << std::endl;

		for (auto col : data.data_grid)
		{
			for (auto row : col)
			{
				ofile << row << " ";
			}
			ofile << std::endl;
		}		
	}
	ofile.close();
}

void cRESOURCE_MANAGER::createFile(std::string filename)
{

}

void cRESOURCE_MANAGER::createPlayerFile(std::string filename)
{
	//파일이 존재하면 0을 리턴
	if (access(filename.data(), 0) != 0)
	{
		std::ofstream ofile(filename);
		{

		}ofile.close();
	}
}

void cRESOURCE_MANAGER::loadImage(HBITMAP& hImg, WCHAR* img_name)
{
	hImg = (HBITMAP)LoadImage(hInst_, img_name, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
}

