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
	
	map_jungle_file_names_ = {
			{ "Game Data/map_jungle_1.txt" },
			{ "Game Data/map_jungle_2.txt" },
			{ "Game Data/map_jungle_3.txt" },
			{ "Game Data/map_jungle_4.txt" },
			{ "Game Data/map_jungle_5.txt" },
	};
	
	loadMapData(map_jungle_file_names_, map_jungle_);
	maps_.push_back(map_jungle_);
}
cRESOURCE_MANAGER::~cRESOURCE_MANAGER()
{
	saveMapData(map_jungle_file_names_, maps_[0]);
	maps_.clear();
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
				>> data_.floor_img
				>> data_.background_img
				>> data_.background_img2;
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

void cRESOURCE_MANAGER::saveMapData(std::vector<std::string>& file_names,
	std::vector<sMAP_DATA>& map)
{
	for (int i = 0; i < file_names.size(); i++)
	{
		std::ofstream ofile(file_names[i]);
		{
			//sMAP_DATA data_;
			for (auto data_ : map)
			{
				ofile << data_.width << " "
				<< data_.height << " "
				<< data_.count_x << " "
				<< data_.count_y << " "
				<< data_.potal_L_filename << std::endl
				<< data_.potal_T_filename << std::endl
				<< data_.potal_R_filename << std::endl
				<< data_.potal_B_filename << std::endl
				<< data_.floor_img << std::endl
				<< data_.background_img << std::endl
				<< data_.background_img2 << std::endl;
		
				for (auto col : data_.data_grid)
				{
					for (auto row : col)
					{
						ofile << row <<" ";
					}
					ofile << std::endl;
				}
			}
			/*for (int y = 0; y < data_.count_y; y++)
			{
				for (int x = 0; x < data_.count_x; x++)
				{
					ofile << data_.data_grid[y][x] << " ";
				}
				ofile << std::endl;
			}*/
		}
		ofile.close();
	}
}

std::vector<sMAP_DATA>& cRESOURCE_MANAGER::getMapData(eMAP_NAME map_name)
{
	return maps_[map_name];
}
void cRESOURCE_MANAGER::setMapData(eMAP_NAME map_name, std::vector<sMAP_DATA> map_data)
{
	maps_[map_name] = map_data;
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
	/*std::ofstream ofile;
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
	ofile.close();*/
}

void cRESOURCE_MANAGER::readMapFile(std::string filename, cGRID& grid)
{
	//std::ifstream ifile;
	//ifile.open(filename);
	//{
	//	sMAP_DATA data_;
	//	ifile >> data_.width
	//		>> data_.height
	//		>> data_.count_x
	//		>> data_.count_y
	//		//>> data_.filename
	//		>> data_.potal_L_filename
	//		>> data_.potal_T_filename
	//		>> data_.potal_R_filename
	//		>> data_.potal_B_filename
	//		>> data_.floor_img
	//		>> data_.background_img
	//		>> data_.background_img2;
	//	map_data1_.push_back(data_);

	//	if (ifile.fail())
	//	{
	//		for (int x = 0; x < grid.getCountX(); x++)
	//			for (int y = 0; y < grid.getCountY(); y++)
	//			{
	//				grid.getGridMap()[x][y] = 0;
	//			}
	//	}
	//	else
	//	{
	//		for (int x = 0; x < grid.getCountX(); x++)
	//		{
	//			for (int y = 0; y < grid.getCountY(); y++)
	//			{
	//				ifile.get(grid.getGridMap()[x][y]);
	//			}
	//		}
	//	}
	//}
	//ifile.close();
}

void cRESOURCE_MANAGER::loadImage()
{
	//::LoadImage(hInst_,)
}

