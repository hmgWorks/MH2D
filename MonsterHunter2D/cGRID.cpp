#include "stdafx.h"
#include "cGRID.h"
#include "cMAIN_GAME.h"
#include <algorithm>

cGRID::cGRID()
{
	grid_ = nullptr;
	tilemap_ = nullptr;

	map_key_ = '0';
}

cGRID::~cGRID()
{
	for (int i = 0; i < count_x_; i++)
	{
		delete[] grid_[i];
		grid_[i] = nullptr;
	}
	delete[] grid_;
	grid_ = nullptr;	

	for (int i = 0; i < count_x_; i++)
	{
		delete[] tilemap_[i];
		tilemap_[i] = nullptr;
	}
	delete[] tilemap_;
	tilemap_ = nullptr;
}
//void cGRID::initGrid(const sMAP_DATA& data)
////void cGRID::initGrid(int width, int height, int count_x, int count_y)
//{
//	if (grid_ != nullptr)
//	{
//		for (int i = 0; i < count_x_; i++)
//		{
//			delete[] grid_[i];
//			grid_[i] = nullptr;
//		}
//		delete[] grid_;
//		grid_ = nullptr;
//	}
//	if (tilemap_ != nullptr)
//	{
//		for (int i = 0; i < count_x_; i++)
//		{
//			delete[] tilemap_[i];
//			tilemap_[i] = nullptr;
//		}
//		delete[] tilemap_;
//		tilemap_ = nullptr;
//	}
//
//	width_ = data.width;
//	height_ = data.height;
//	count_x_ = data.count_x;
//	count_y_ = data.count_y;
//	file_name_ = data.filename;
//	
//	limits_grid_ = { 0, 0, width_*count_x_, height_* count_y_ };
//	grid_ = new char*[count_x_];
//	for (int i = 0; i < count_x_; i++)
//		grid_[i] = new char[count_y_];	
//	
//	loadMapData();
//	/*for (int x = 0; x < count_x_; x++)
//		for (int y = 0; y < count_y_; y++)
//		{
//			grid_[x][y] = 0;
//		}*/
//
//	/*
//		cGAME_OBJECT의 포인터를 담는 리스트의 2차 배열 의 종적 할당
//	*/	
//	if (tilemap_ != nullptr)
//	clearTileMap();
//
//	tilemap_ = new std::list<cGAME_OBJECT*>*[count_x_];
//	for (int i = 0; i < count_x_; i++)
//		tilemap_[i] = new std::list<cGAME_OBJECT*>[count_y_];
//}

void cGRID::setGrid(const sMAP_DATA& data)
//void cGRID::initGrid(int width, int height, int count_x, int count_y)
{
	/*clearMapTable();
	
	width_ = data.width;
	height_ = data.height;
	count_x_ = data.count_x;
	count_y_ = data.count_y;
	file_name_ = data.filename;
	potal_left_file_name_ = data.potal_L_filename;
	potal_top_file_name_ = data.potal_T_filename;
	potal_right_file_name_ = data.potal_R_filename;
	potal_bottom_file_name_ = data.potal_B_filename;

	limits_grid_ = { 0, 0, width_*count_x_, height_* count_y_ };
	
	cMAIN_GAME::getInstance()->resource_->saveMapFile(file_name_, *this);
	loadFileData();*/
	//loadMapData();
	/*for (int x = 0; x < count_x_; x++)
	for (int y = 0; y < count_y_; y++)
	{
	grid_[x][y] = 0;
	}*/

	/*
	cGAME_OBJECT의 포인터를 담는 리스트의 2차 배열 의 종적 할당
	*/
	//createMapTable();
	/*if (tilemap_ != nullptr)
		clearTileMap();

	tilemap_ = new std::list<cGAME_OBJECT*>*[count_x_];
	for (int i = 0; i < count_x_; i++)
		tilemap_[i] = new std::list<cGAME_OBJECT*>[count_y_];*/
}

void cGRID::update(double delta)
{
	
	/*insertMapObj();
	if (cMAIN_GAME::getInstance()->input_->getDownKey_once('O'))
		cMAIN_GAME::getInstance()->resource_->saveMapFile(file_name_, *this);
	if (cMAIN_GAME::getInstance()->input_->getDownKey_once('P'))
		cMAIN_GAME::getInstance()->resource_->readMapFile(file_name_, *this);

	for (int i = 0; i < count_y_; i++)
	{
		for (int j = 0; j < count_x_; j++)
		{
			if (!tilemap_[j][i].empty())
				for (auto x : tilemap_[j][i])
					x->update(delta);
		}
	}*/
}

void cGRID::render()
{
	/*int l, t, r, b;
	for (int x = 0; x < count_x_; x++)
		for (int y = 0; y < count_y_; y++)
		{
			l = x * width_ - cMAIN_GAME::getInstance()->camera_->getPostion().x;
			t = y * height_ - cMAIN_GAME::getInstance()->camera_->getPostion().y;
			r = l + width_;
			b = t + height_;
			if (grid_[x][y] == '1')
			{
				cMAIN_GAME::getInstance()->renderer_->selectBrush(RGB(100, 0, 0));
				cMAIN_GAME::getInstance()->renderer_->rectangel(l, t, r, b);
				cMAIN_GAME::getInstance()->renderer_->deleteBrush();
			}
			else if (grid_[x][y] == '2')
			{
				cMAIN_GAME::getInstance()->renderer_->selectBrush(RGB(100, 0, 255));
				cMAIN_GAME::getInstance()->renderer_->rectangel(l, t, r, b);
				cMAIN_GAME::getInstance()->renderer_->deleteBrush();				
			}
			else if (grid_[x][y] == '3')
			{
				cMAIN_GAME::getInstance()->renderer_->selectBrush(RGB(255, 0, 0));
				cMAIN_GAME::getInstance()->renderer_->rectangel(l, t, r, b);
				cMAIN_GAME::getInstance()->renderer_->deleteBrush();				
			}
			else if (grid_[x][y] == '4')
			{
				cMAIN_GAME::getInstance()->renderer_->selectBrush(RGB(0, 0, 255));
				cMAIN_GAME::getInstance()->renderer_->rectangel(l, t, r, b);
				cMAIN_GAME::getInstance()->renderer_->deleteBrush();				
			}
			else if (grid_[x][y] == '8')
			{
				cMAIN_GAME::getInstance()->renderer_->selectBrush(RGB(200, 200, 200));
				cMAIN_GAME::getInstance()->renderer_->rectangel(l, t, r, b);
				cMAIN_GAME::getInstance()->renderer_->deleteBrush();
			}
			else if (grid_[x][y] == '9')
			{
				cMAIN_GAME::getInstance()->renderer_->selectBrush(RGB(50, 50, 50));
				cMAIN_GAME::getInstance()->renderer_->rectangel(l, t, r, b);
				cMAIN_GAME::getInstance()->renderer_->deleteBrush();
			}
			else if (grid_[x][y] == 'l')
			{
				cMAIN_GAME::getInstance()->renderer_->selectBrush(RGB(0, 0, 255));
				cMAIN_GAME::getInstance()->renderer_->rectangel(l, t, r, b);
				cMAIN_GAME::getInstance()->renderer_->deleteBrush();
			}
			else if (grid_[x][y] == 't')
			{
				cMAIN_GAME::getInstance()->renderer_->selectBrush(RGB(0, 0, 255));
				cMAIN_GAME::getInstance()->renderer_->rectangel(l, t, r, b);
				cMAIN_GAME::getInstance()->renderer_->deleteBrush();
			}
			else if (grid_[x][y] == 'r')
			{
				cMAIN_GAME::getInstance()->renderer_->selectBrush(RGB(0, 0, 255));
				cMAIN_GAME::getInstance()->renderer_->rectangel(l, t, r, b);
				cMAIN_GAME::getInstance()->renderer_->deleteBrush();
			}
			else if (grid_[x][y] == 'b')
			{
				cMAIN_GAME::getInstance()->renderer_->selectBrush(RGB(0, 0, 255));
				cMAIN_GAME::getInstance()->renderer_->rectangel(l, t, r, b);
				cMAIN_GAME::getInstance()->renderer_->deleteBrush();
			}
			else
			{
				cMAIN_GAME::getInstance()->renderer_->rectangel(l, t, r, b);
			}
			if (!tilemap_[x][y].empty())
			{
				for (auto i : tilemap_[x][y])
					if (i)
					{
						cMAIN_GAME::getInstance()->renderer_->selectBrush(RGB(255, 0, 0));
						cMAIN_GAME::getInstance()->renderer_->rectangel(l, t, r, b);
						cMAIN_GAME::getInstance()->renderer_->deleteBrush();						
					}
			}
		}
	for (int i = 0; i < count_y_; i++)
	{
		for (int j = 0; j < count_x_; j++)
		{
			if (!tilemap_[j][i].empty())
				for (auto x : tilemap_[j][i])
					x->render();
		}
	}*/
}

RECT cGRID::getGridLimits()
{
	//return limits_grid_;
	return{0,0,0,0};
}

void cGRID::initPlayer1(cGAME_OBJECT* object)
{
	/*for (int x = 0; x < count_x_; x++)
	{
		for (int y = 0; y < count_y_; y++)
		{			
			if (grid_[x][y] == '9')
			{
				object->setPos({ x * width_, y * height_ });
				return;
			}

		}
	}*/
}
void cGRID::initPlayer2(cGAME_OBJECT* object)
{
	/*for (int x = 0; x < count_x_; x++)
	{
		for (int y = 0; y < count_y_; y++)
		{
			if (grid_[x][y] == '8')
			{
				object->setPos({ x * width_, y * height_ });
				return;
			}

		}
	}*/
}

void cGRID::setTileMap(cGAME_OBJECT* object)
{
	//if (object->getCellPos().x != -1)
	//{		
	//	//remove는 넘겨진 값을 찾아 삭제한다.
	//	tilemap_[object->getCellPos().x][object->getCellPos().y].remove(object);	
	//}

	//int x = object->getPos().x /*+ cMAIN_GAME::getInstance()->camera_->getPostion().x)*/ / width_;
	//int y = object->getPos().y /*+ cMAIN_GAME::getInstance()->camera_->getPostion().y)*/ / height_;
	//
	//if (x >= count_x_)
	//	x = count_x_-1;
	//if (y >= count_y_)
	//	y = count_y_-1;
	//
	//object->setCellPos({ x, y });
	//tilemap_[x][y].push_back(object);	
}

void cGRID::clearTileMap()
{
	/*for (int y = 0; y < count_y_; y++)
	{
		for (int x = 0; x < count_x_; x++)
		{
			if (!tilemap_[x][y].empty())
				tilemap_[x][y].clear();					
		}
	}
	for (int i = 0; i < count_x_; i++)
	{
		delete[] tilemap_[i];
		tilemap_[i] = nullptr;
	}
	delete[] tilemap_;
	tilemap_ = nullptr;*/
}

void cGRID::insertMapObj()
{
	//if (cMAIN_GAME::getInstance()->input_->getDownKey_once('1'))
	//	map_key_ = '1';
	//if (cMAIN_GAME::getInstance()->input_->getDownKey_once('2'))
	//	map_key_ = '2';
	//if (cMAIN_GAME::getInstance()->input_->getDownKey_once('3'))
	//	map_key_ = '3';//입구
	//if (cMAIN_GAME::getInstance()->input_->getDownKey_once('4'))
	//	map_key_ = '4';//출구
	//
	//플래이어 시작 위치
	//if (cMAIN_GAME::getInstance()->input_->getDownKey_once('8'))
	//	map_key_ = '8';
	//if (cMAIN_GAME::getInstance()->input_->getDownKey_once('9'))
	//	map_key_ = '9';

	////potal
	//if (cMAIN_GAME::getInstance()->input_->getDownKey_once('L'))
	//	map_key_ = 'l';
	//if (cMAIN_GAME::getInstance()->input_->getDownKey_once('T'))
	//	map_key_ = 't';
	//if (cMAIN_GAME::getInstance()->input_->getDownKey_once('R'))
	//	map_key_ = 'r';
	//if (cMAIN_GAME::getInstance()->input_->getDownKey_once('B'))
	//	map_key_ = 'b';

	//if (cMAIN_GAME::getInstance()->input_->getMouseDown())
	//{
	//	int x = (cMAIN_GAME::getInstance()->input_->getMouse().x + cMAIN_GAME::getInstance()->camera_->getPostion().x) / width_;
	//	int y = (cMAIN_GAME::getInstance()->input_->getMouse().y + cMAIN_GAME::getInstance()->camera_->getPostion().y) / height_;
	//	grid_[x][y] = map_key_;
	//}
}

void cGRID::loadMapData()
{
	//cMAIN_GAME::getInstance()->resource_->readMapFile(file_name_, *this);
}

void cGRID::checkCollision(cGAME_OBJECT* object)
{
	/*if (grid_[object->getCellPos().x][object->getCellPos().y] == 'l')
	{
		initGrid(cMAIN_GAME::getInstance()->resource_->map_data_[eMAP_DATA::world_left]);
		initPlayer1(object);
	}
	if (grid_[object->getCellPos().x][object->getCellPos().y] == 'r')
	{
		initGrid(cMAIN_GAME::getInstance()->resource_->map_data_[eMAP_DATA::world_right]);
		initPlayer2(object);
	}*/	
}

void cGRID::clearMapTable()
{
	/*if (!data_table_.empty())
		for (auto x : data_table_)
			x.clear();
		data_table_.clear();

	if (!obj_table_.empty())
		for (auto x : obj_table_)
			x.clear();
		obj_table_.clear();*/

	/*if (obj_table_ != nullptr)
	{
		for (int i = 0; i < count_x_; i++)
		{
		for (int j = 0; j < count_y_; j++)
		{
			obj_table_[i][j].clear();
		}
		}
	
		for (int i = 0; i < count_x_; i++)
		{
			delete[] obj_table_[i];
			obj_table_[i] = nullptr;
		}
		delete[] obj_table_;
		obj_table_ = nullptr;
	}*/
}
void cGRID::createMapTable()
{
	/*data_row_.resize(count_x_, '0');
	data_table_.resize(count_y_, data_row_);

	obj_row_.resize(count_x_);
	obj_table_.resize(count_y_);*/
	
	/*obj_table_ = new std::list<cGAME_OBJECT*>*[count_x_];
	for (int i = 0; i < count_y_; i++)
		obj_table_[i] = new std::list<cGAME_OBJECT*>[count_y_];*/
}

void cGRID::loadFileData()
{
	//cMAIN_GAME::getInstance()->resource_->readMapFile(file_name_, *this);
}