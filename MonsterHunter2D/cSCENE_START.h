#pragma once
#include <string>
#include "iSCENE_BASE.h"
#include "cMAIN_GAME.h"

#define ID_EIDT 101
class cSCENE_START :
	public iSCENE_BASE
{
public:
	cSCENE_START();
	~cSCENE_START();

	void enter();
	void update(double delta);
	void render();
	void exit();

	void createPlayer();

private:
	std::string path_ = "player\\";
	std::string player_name_ = "hmg";

	int left_, top_;
	int width_, height_;
	HWND edit_;
};

