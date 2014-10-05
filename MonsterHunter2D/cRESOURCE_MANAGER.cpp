#include "stdafx.h"
#include "cRESOURCE_MANAGER.h"
#include <io.h>
#include <stdlib.h>

cRESOURCE_MANAGER::cRESOURCE_MANAGER()
{

}
cRESOURCE_MANAGER::cRESOURCE_MANAGER(HINSTANCE hInst)
{
	hInst_ = hInst;
	map_data_ = {
			{ 30, 20, 60, 20, "Game Data/map1_1.txt" },
			{ 30, 20, 60, 20, "Game Data/map1_2.txt" },
	};
	map_file_names_ = {
			{ "Game Data/world_start.txt" },
			{ "Game Data/world_l.txt" },
			{ "Game Data/world_t.txt" },
			{ "Game Data/world_r.txt" },
			{ "Game Data/world_b.txt" },
	};
	loadMap();
}
cRESOURCE_MANAGER::~cRESOURCE_MANAGER()
{
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

void cRESOURCE_MANAGER::saveMapFile(std::string filename, cGRID& grid)
{
	std::ofstream ofile;
	ofile.open(filename);
	{
		ofile
			<< grid.getWidth()
			<< grid.getHeight()
			<< grid.getCountX()
			<< grid.getCountY() << std::endl
			<< grid.file_name_ << std::endl
			<< grid.potal_left_file_name_ << std::endl
			<< grid.potal_top_file_name_ << std::endl
			<< grid.potal_right_file_name_ << std::endl
			<< grid.potal_bottom_file_name_ << std::endl
			<< grid.floor_img_file_ << std::endl
			<< grid.background_img_file_ << std::endl
			<< grid.background_img2_file_ << std::endl;
		for (int x = 0; x < grid.getCountX(); x++)
		{
			for (int y = 0; y < grid.getCountY(); y++)
			{
				ofile.put(grid.getGridMap()[x][y]);
			}
			ofile << std::endl;
		}
	}
	ofile.close();
}

void cRESOURCE_MANAGER::readMapFile(std::string filename, cGRID& grid)
{
	std::ifstream ifile;
	ifile.open(filename);
	{
		sMAP_DATA data_;
		ifile >> data_.width
			>> data_.height
			>> data_.count_x
			>> data_.count_y
			>> data_.filename
			>> data_.potal_L_filename
			>> data_.potal_T_filename
			>> data_.potal_R_filename
			>> data_.potal_B_filename
			>> data_.floor_img
			>> data_.background_img
			>> data_.background_img2;
		map_data1_.push_back(data_);

		if (ifile.fail())
		{
			for (int x = 0; x < grid.getCountX(); x++)
				for (int y = 0; y < grid.getCountY(); y++)
				{
					grid.getGridMap()[x][y] = 0;
				}
		}
		else
		{
			for (int x = 0; x < grid.getCountX(); x++)
			{
				for (int y = 0; y < grid.getCountY(); y++)
				{
					ifile.get(grid.getGridMap()[x][y]);
				}
			}
		}
	}
	ifile.close();
}

void cRESOURCE_MANAGER::loadImage()
{
	//::LoadImage(hInst_,)
}

void cRESOURCE_MANAGER::loadMap()
{
	for (int i = 0; i < map_file_names_.size(); i++)
	{
		std::ifstream ifile(map_file_names_[i]);
		{
			sMAP_DATA data_;
			ifile >> data_.width
				>> data_.height
				>> data_.count_x
				>> data_.count_y
				>> data_.filename
				>> data_.potal_L_filename
				>> data_.potal_T_filename
				>> data_.potal_R_filename
				>> data_.potal_B_filename
				>> data_.floor_img
				>> data_.background_img
				>> data_.background_img2;
			map_data1_.push_back(data_);
		}
		ifile.close();
	}
}