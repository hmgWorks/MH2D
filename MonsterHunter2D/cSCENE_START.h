#pragma once
#include <string>
#include "iSCENE_BASE.h"
#include "cMAIN_GAME.h"

#define ID_EIDT 101
#define ID_BUTTON 102
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


	POINT create_button_pos_;
	int create_button_w_, create_button_h_;
	BOOL create_button_;

	POINT input_name_window_pos_;
	int input_name_window_w_, input_name_window_h_;

	HWND edit_, button_;
	//WCHAR buf[100];

	int l, t, r, b;
	RECT draw_window_;

	HBITMAP start_bg_;
	HBITMAP start_button1_;
	HBITMAP start_button2_;
	HBITMAP start_popup_;
	BOOL popup_window_;
	int button_state_;

};

