#include "stdafx.h"
#include "cGRID.h"
#include "cMAIN_GAME.h"
#include <algorithm>

cGRID::cGRID()
{
	map_key_ = '0';
	map_data_index_ = 0;
}

cGRID::~cGRID()
{
	
}

void cGRID::initMap(std::vector<std::vector<sMAP_DATA>>& data_map,
	std::shared_ptr<cGAME_OBJECT>& player, int map_name)
{
	map_name_ = map_name;
	maps_ = data_map;
	current_map_ = maps_[map_name_];
	current_map_data_ = current_map_[map_data_index_];

	//tile map
	if (!obj_grid_.empty())
		obj_grid_.clear();

	std::vector<std::list<std::shared_ptr<cGAME_OBJECT>>> obj_row(current_map_data_.count_x);
	for (int i = 0; i < current_map_data_.count_y; i++)
	{
		obj_grid_.push_back(obj_row);
	}

	//카메라와 오브젝트의 한게 제한을 줌
	limits_grid_ = { 0, 0, current_map_data_.width*current_map_data_.count_x,
		current_map_data_.height* current_map_data_.count_y };
	
	if (player != nullptr)
		for (int x = 0; x < current_map_data_.count_x; x++)
			for (int y = 0; y < current_map_data_.count_y; y++)
			{
				if (current_map_data_.data_grid[y][x] == 'c')
				{
					player->setPos({ x* current_map_data_.width, y * current_map_data_.height });
					player->setCellPos({ x, y });
					obj_grid_[y][x].push_back(player);
					player->setLimits(limits_grid_);
				}				
			}
	
	cMAIN_GAME::getInstance()->camera_->setLimit(limits_grid_);
	cMAIN_GAME::getInstance()->resource_->loadImage(img_, eIMG_LIST::WORLD_BACKGROUND_1);
}

void cGRID::setMap(std::shared_ptr<cGAME_OBJECT>& player)
{
	current_map_data_ = current_map_[map_data_index_];
	if (!obj_grid_.empty())
		obj_grid_.clear();

	std::vector<std::list<std::shared_ptr<cGAME_OBJECT>>> obj_row(current_map_data_.count_x);
	for (int i = 0; i < current_map_data_.count_y; i++)
	{
		obj_grid_.push_back(obj_row);
	}

	limits_grid_ = { 0, 0, current_map_data_.width*current_map_data_.count_x,
		current_map_data_.height* current_map_data_.count_y };

	int x = player->getCellPos().x;
	int y = player->getCellPos().y;	
		
	player->setPos({ x* current_map_data_.width, y * current_map_data_.height });
	player->setLimits(limits_grid_);

	obj_grid_[y][x].push_back(player);	

	cMAIN_GAME::getInstance()->camera_->setLimit(limits_grid_);
}

void cGRID::update(double delta)
{
	
	insertMapObj();
	
	if (cMAIN_GAME::getInstance()->input_->getDownKey_once('O'))
	{
		current_map_[map_data_index_] = current_map_data_;
		maps_[map_name_] = current_map_;
		cMAIN_GAME::getInstance()->resource_->setMapData(maps_);		
	}

		
	/*for (int i = 0; i < current_map_data_.count_y; i++)
	{
		for (int j = 0; j < current_map_data_.count_x; j++)
		{
			if (!obj_grid_[i][j].empty())
				for (auto x : obj_grid_[i][j])
				{
					x->update(delta);
				}
		}
	}*/
}

void cGRID::render()
{	
	//test code
	cMAIN_GAME::getInstance()->renderer_->drawBitmapBack(0 - cMAIN_GAME::getInstance()->camera_->getPos().x, 0 - 470 - cMAIN_GAME::getInstance()->camera_->getPos().y, img_, RGB(255, 0, 255));
	
	int l, t, r, b;
	for (int x = 0; x < current_map_data_.count_x; x++)
		for (int y = 0; y < current_map_data_.count_y; y++)
		{
			l = x * current_map_data_.width -cMAIN_GAME::getInstance()->camera_->getPos().x;
			t = y * current_map_data_.height -cMAIN_GAME::getInstance()->camera_->getPos().y;
			r = l + current_map_data_.width;
			b = t + current_map_data_.height;
			if (current_map_data_.data_grid[y][x] == 'l'
				|| current_map_data_.data_grid[y][x] == 't'
				|| current_map_data_.data_grid[y][x] == 'r'
				|| current_map_data_.data_grid[y][x] == 'b')
			{
				cMAIN_GAME::getInstance()->renderer_->selectBrush(RGB(0, 0, 255));
				cMAIN_GAME::getInstance()->renderer_->rectangel(l, t, r, b);
				cMAIN_GAME::getInstance()->renderer_->deleteBrush();
			}
			else if (current_map_data_.data_grid[y][x] == 'e')
			{
				cMAIN_GAME::getInstance()->renderer_->selectBrush(RGB(0, 255, 0));
				cMAIN_GAME::getInstance()->renderer_->rectangel(l, t, r, b);
				cMAIN_GAME::getInstance()->renderer_->deleteBrush();
			}
			else if (current_map_data_.data_grid[y][x] == 'd')
			{
				cMAIN_GAME::getInstance()->renderer_->selectBrush(RGB(0, 255, 255));
				cMAIN_GAME::getInstance()->renderer_->rectangel(l, t, r, b);
				cMAIN_GAME::getInstance()->renderer_->deleteBrush();
			}

			else
			{
				//cMAIN_GAME::getInstance()->renderer_->rectangel(l, t, r, b);
			}
			if (!obj_grid_[y][x].empty())
			{
				for (auto i : obj_grid_[y][x])
					if (i)
					{
					cMAIN_GAME::getInstance()->renderer_->selectBrush(RGB(255, 0, 0));
					cMAIN_GAME::getInstance()->renderer_->rectangel(l, t, r, b);
					cMAIN_GAME::getInstance()->renderer_->deleteBrush();
					}
			}
		}

	for (int i = 0; i < current_map_data_.count_y; i++)
	{
		for (int j = 0; j < current_map_data_.count_x; j++)
		{
			if (!obj_grid_[i][j].empty())
				for (auto x : obj_grid_[i][j])
					x->render();
		}
	}	
}

void cGRID::checkCollision(std::shared_ptr<cGAME_OBJECT>& obj, cSCENE_MAIN* scene)
{
	if (current_map_data_.data_grid[obj->getCellPos().y][obj->getCellPos().x] == 'l')
	{
		map_data_index_ = current_map_data_.potal_L_filename;		
		int y = obj->getCellPos().y;
		obj->setCellPos({ current_map_[map_data_index_].count_x - 2, y });
		setMap(obj);
	}
	if (current_map_data_.data_grid[obj->getCellPos().y][obj->getCellPos().x] == 't')
	{
		map_data_index_ = current_map_data_.potal_T_filename;
		int x = obj->getCellPos().x;
		obj->setCellPos({ x, current_map_[map_data_index_].count_y - 2 });
		setMap(obj);
	}
	if (current_map_data_.data_grid[obj->getCellPos().y][obj->getCellPos().x] == 'r')
	{
		map_data_index_ = current_map_data_.potal_R_filename;
		int y = obj->getCellPos().y;
		obj->setCellPos({ 1, y });
		setMap(obj);
	}
	if (current_map_data_.data_grid[obj->getCellPos().y][obj->getCellPos().x] == 'b')
	{
		map_data_index_ = current_map_data_.potal_B_filename;
		int x = obj->getCellPos().x;
		obj->setCellPos({ x, 1 });
		setMap(obj);
	}
	if (current_map_data_.data_grid[obj->getCellPos().y][obj->getCellPos().x] == 'd')
	{
		scene->changeSceneState(eSCENE_STATE::SELECT);
		int x = obj->getCellPos().x - 1;
		int y = obj->getCellPos().y;
		obj->setCellPos({ x, y });
		obj->setPos({ x* current_map_data_.width, y * current_map_data_.height });
	}
	
}

void cGRID::setTileMap(std::shared_ptr<cGAME_OBJECT>& object)
{
	if (object->getCellPos().x != -1)
	{
		//remove는 넘겨진 값을 찾아 삭제한다.
		obj_grid_[object->getCellPos().y][object->getCellPos().x].remove(object);
	}

	int x = object->getPos().x / current_map_data_.width;
	int y = object->getPos().y / current_map_data_.height;

	if (x >= current_map_data_.count_x)
		x = current_map_data_.count_x - 1;
	if (y >= current_map_data_.count_y)
		y = current_map_data_.count_y - 1;

	object->setCellPos({ x, y });
	obj_grid_[y][x].push_back(object);
}

void cGRID::insertMapObj()
{
	if (cMAIN_GAME::getInstance()->input_->getDownKey_once('0'))
		map_key_ = '0';
	if (cMAIN_GAME::getInstance()->input_->getDownKey_once('L'))
		map_key_ = 'l';
	if (cMAIN_GAME::getInstance()->input_->getDownKey_once('T'))
		map_key_ = 't';
	if (cMAIN_GAME::getInstance()->input_->getDownKey_once('R'))
		map_key_ = 'r';
	if (cMAIN_GAME::getInstance()->input_->getDownKey_once('B'))
		map_key_ = 'b';
	if (cMAIN_GAME::getInstance()->input_->getDownKey_once('E'))
		map_key_ = 'e';
	if (cMAIN_GAME::getInstance()->input_->getDownKey_once('D'))
		map_key_ = 'd';
	
	if (cMAIN_GAME::getInstance()->input_->getMouseDown())
	{
		int x = (cMAIN_GAME::getInstance()->input_->getMouse().x + cMAIN_GAME::getInstance()->camera_->getPos().x) / current_map_data_.width;
		int y = (cMAIN_GAME::getInstance()->input_->getMouse().y + cMAIN_GAME::getInstance()->camera_->getPos().y) / current_map_data_.height;
		current_map_data_.data_grid[y][x] = map_key_;
	}
}