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
		for (int x = 0; x < grid.getCountX(); x++)
		{
			for (int y = 0; y < grid.getCountY(); y++)
			{
				ofile.put(grid.getGridMap()[x][y]);
			}
		}
	}
	ofile.close();
}

void cRESOURCE_MANAGER::readMapFile(std::string filename, cGRID& grid)
{
	std::ifstream ifile;
	ifile.open(filename);
	{
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