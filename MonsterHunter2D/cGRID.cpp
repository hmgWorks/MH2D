#include "stdafx.h"
#include "cGRID.h"
#include "cMAIN_GAME.h"
#include <algorithm>

cGRID::cGRID()
{	
	//�ʼ��� ���� �����̶��� �������
	map_key_ = '0';
	/*
		���� ������ �ε���
		�����̸��� ���� ������ �ε���
	*/
	map_data_index_ = 0;
	
	/*
		�������� ������ ������ �ִ�.
		map_files_ ���� ������ ��� ��� �ִ�.
		�̹����� ���� ���
	*/
	map_world_file_names_ = {
			{ "Game Data/map_world_0.txt" }
	};
	map_jungle_file_names_ = {
			{ "Game Data/map_jungle_0.txt" },
			{ "Game Data/map_jungle_1.txt" },
			{ "Game Data/map_jungle_2.txt" },
			{ "Game Data/map_jungle_3.txt" },
			{ "Game Data/map_jungle_4.txt" },
			{ "Game Data/map_jungle_5.txt" },
			{ "Game Data/map_jungle_6.txt" },
			{ "Game Data/map_jungle_7.txt" }
	};
	
	map_files_.push_back(map_world_file_names_);
	map_files_.push_back(map_jungle_file_names_);

	
	
	//���콺 ������ ���߿� ����ų�
	tl = 0;
	tt = 0;
}

cGRID::~cGRID()
{
	
}

//���忡�� ���� �������� ����� ���� �� �� ȣ���ؼ� �ʱ�ȭ ���ش�.
void cGRID::initMap(std::shared_ptr<cGAME_OBJECT>& player, int map_name)
{
	//0��° ������ ĳ������ �ʱ� ��ġ�� �ִ�.
	map_data_index_ = 0;
	
	//������ �������ش�
	map_name_ = map_name;
	
	//���� ����� �ѹ� ȣ�� �ϹǷ� �����̳� �ʱ�ȭ�� ���⼭
	if (!current_map_.empty())
		current_map_.clear();

	//tile map
	if (!obj_grid_.empty())
		obj_grid_.clear();
	

	//������ ���� �ε��ؼ� �����̳ʿ�
	cMAIN_GAME::getInstance()->resource_->loadMapData(map_files_[map_name_], current_map_);
	current_map_data_ = current_map_[map_data_index_];

	std::vector<std::list<std::shared_ptr<cGAME_OBJECT>>> obj_row(current_map_data_.count_x);
	for (int i = 0; i < current_map_data_.count_y; i++)
	{
		obj_grid_.push_back(obj_row);
	}
	//ī�޶�� ������Ʈ�� �Ѱ� ������ ��
	limits_grid_ = { 0, 0, current_map_data_.width * current_map_data_.count_x,
		current_map_data_.height * current_map_data_.count_y };

	//�÷��̾� ����ġ �ʱ�ȭ
	player->setCellPos({ -1, 0 });

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

	//�׸��� ���鶼 test code
	if (player->getCellPos().x == -1)
	{
		player->setPos({ 3* current_map_data_.width, 3 * current_map_data_.height });
		player->setCellPos({ 3, 3 });
		obj_grid_[3][3].push_back(player);
		player->setLimits(limits_grid_);
	}

	cMAIN_GAME::getInstance()->camera_->setLimit(limits_grid_);
		
	if (current_map_data_.background_img != "noimg")
		cMAIN_GAME::getInstance()->resource_->loadImage(img_bg1_, current_map_data_.background_img);
		
	if (current_map_data_.background_img2 != "noimg")
		cMAIN_GAME::getInstance()->resource_->loadImage(img_bg2_, current_map_data_.background_img2);		
		
	if (current_map_data_.floor_img != "noimg")
		cMAIN_GAME::getInstance()->resource_->loadImage(img_floor_, current_map_data_.floor_img);
}

//���̵��� �� �� ȣ��
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

	if (current_map_data_.background_img != "noimg")
		cMAIN_GAME::getInstance()->resource_->loadImage(img_bg1_, current_map_data_.background_img);

	if (current_map_data_.background_img2 != "noimg")
		cMAIN_GAME::getInstance()->resource_->loadImage(img_bg2_, current_map_data_.background_img2);

	if (current_map_data_.floor_img != "noimg")
		cMAIN_GAME::getInstance()->resource_->loadImage(img_floor_, current_map_data_.floor_img);	
}

void cGRID::update(double delta)
{
	
	
	//�� ���� ���� �ڵ�
	
	//insertMapObj();
	if (cMAIN_GAME::getInstance()->input_->getDownKey_once('O'))
	{		
		cMAIN_GAME::getInstance()->resource_->saveMapData(map_files_[map_name_][map_data_index_], 
			current_map_data_);		
		current_map_[map_data_index_] = current_map_data_;
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
	if (cMAIN_GAME::getInstance()->input_->isMouseDown())
	{
		tl = cMAIN_GAME::getInstance()->input_->getMousePos().x;
		tt = cMAIN_GAME::getInstance()->input_->getMousePos().y;
	}

}

void cGRID::render()
{	
	//bg �� ���� ������ �� �ؾ���
	if (current_map_data_.background_img2 != "noimg")
		cMAIN_GAME::getInstance()->renderer_->drawBitmapBack(current_map_data_.background_img2_pos_x - cMAIN_GAME::getInstance()->camera_->getPos().x * 0.3,
		current_map_data_.background_img2_pos_y - cMAIN_GAME::getInstance()->camera_->getPos().y, img_bg2_, RGB(255, 0, 255));
		
	if (current_map_data_.floor_img != "noimg")
		cMAIN_GAME::getInstance()->renderer_->drawBitmapBack(current_map_data_.floor_img_pos_x - cMAIN_GAME::getInstance()->camera_->getPos().x,
		current_map_data_.floor_img_pos_y - cMAIN_GAME::getInstance()->camera_->getPos().y, img_floor_, RGB(255, 0, 255));

	if (current_map_data_.background_img != "noimg")
		cMAIN_GAME::getInstance()->renderer_->drawBitmapBack(current_map_data_.background_img_pos_x - cMAIN_GAME::getInstance()->camera_->getPos().x,
		current_map_data_.background_img_pos_y - cMAIN_GAME::getInstance()->camera_->getPos().y, img_bg1_, RGB(255, 0, 255));
		
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
				|| current_map_data_.data_grid[y][x] == 'b'
				|| current_map_data_.data_grid[y][x] == 'c')
			{
				cMAIN_GAME::getInstance()->renderer_->selectBrush(RGB(0, 0, 255));
				cMAIN_GAME::getInstance()->renderer_->rectangel(l, t, r, b);
				cMAIN_GAME::getInstance()->renderer_->deleteBrush();
			}
			else if (current_map_data_.data_grid[y][x] == 'e'
				|| current_map_data_.data_grid[y][x] == '1'
				|| current_map_data_.data_grid[y][x] == '2')
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
			else if (current_map_data_.data_grid[y][x] == 'x')
			{
				cMAIN_GAME::getInstance()->renderer_->selectBrush(RGB(100, 100, 100));
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
	
	// test code
	WCHAR test_ch[100];	
	wsprintf(test_ch, L"%d, %d", tl, tt);
	//cMAIN_GAME::getInstance()->renderer_->rectangel(tl, tt, tl + 100, tt + 200);
	cMAIN_GAME::getInstance()->renderer_->textout(0, 70, test_ch);
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
	if (current_map_data_.data_grid[obj->getCellPos().y][obj->getCellPos().x] == 'x')
	{
		//map_data_index_ = current_map_data_.potal_R_filename;
		int y = obj->getCellPos().y;
		obj->setCellPos({ 1, y });
		setMap(obj);
	}
	
}

void cGRID::setTileMap(std::shared_ptr<cGAME_OBJECT>& object)
{
	if (object->getCellPos().x != -1)
	{
		//remove�� �Ѱ��� ���� ã�� �����Ѵ�.
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
	if (cMAIN_GAME::getInstance()->input_->getDownKey_once('1'))
		map_key_ = '1';
	if (cMAIN_GAME::getInstance()->input_->getDownKey_once('2'))
		map_key_ = '2';
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
	//�����Ա�
	if (cMAIN_GAME::getInstance()->input_->getDownKey_once('D'))
		map_key_ = 'd';
	//�����°�
	if (cMAIN_GAME::getInstance()->input_->getDownKey_once('X'))
		map_key_ = 'x';
	if (cMAIN_GAME::getInstance()->input_->getDownKey_once('C'))
		map_key_ = 'c';
	
	if (cMAIN_GAME::getInstance()->input_->isMouseDown())
	{
		int x = (cMAIN_GAME::getInstance()->input_->getMousePos().x + cMAIN_GAME::getInstance()->camera_->getPos().x) / current_map_data_.width;
		int y = (cMAIN_GAME::getInstance()->input_->getMousePos().y + cMAIN_GAME::getInstance()->camera_->getPos().y) / current_map_data_.height;
		current_map_data_.data_grid[y][x] = map_key_;
	}
}