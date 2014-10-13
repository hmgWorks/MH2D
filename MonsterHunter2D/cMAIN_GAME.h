#pragma once
#include <unordered_map>
#include <memory>
#include "cSINGLETON.h"
#include "iSCENE_BASE.h"
#include "cSCENE_INTRO.h"
#include "cSCENE_START.h"
#include "cSCENE_TUTO.h"
#include "cSCENE_MAIN.h"
#include "cCAMERA.h"
#include "cINPUT_MANAGER.h"
#include "cRESOURCE_MANAGER.h"
#include "cRENDERER.h"

//매니져 스마트 포인터
using unique_input = std::unique_ptr<cINPUT_MANAGER>;
using unique_resource = std::unique_ptr<cRESOURCE_MANAGER>;
using unique_camera = std::unique_ptr < cCAMERA > ;
using unique_render = std::unique_ptr<cRENDERER>;
//scene를위한 열거형과 스마트 포인터 그리도 stl unoered_map
enum SCENE_ID { INTRO, START, TUTO, MAIN };

using shared_scene = std::shared_ptr<iSCENE_BASE>;
using scene_map = std::unordered_map<SCENE_ID, shared_scene>;


class cMAIN_GAME
	:public cSINGLETON<cMAIN_GAME>
{
	friend cSINGLETON;
private:
	cMAIN_GAME();
	~cMAIN_GAME();

public:
	//window
	const int time_id = 1;
	const int time_interval = 30;	
	RECT client_rt_;
	HDC hdc_;
	HWND hWnd_;
	HINSTANCE hInst_;
 
	//manager
	unique_input	input_;
	unique_resource	resource_;
	unique_camera camera_;
	unique_render	renderer_;

private:
	shared_scene current_scene_;
	scene_map scene_map_;

	//screen
	//원하는 화면 크기
	//int width_, height_;
	int screen_width_;
	int screen_height_;

	void fullScreen(int width, int height);
public:	
	HWND createGameWindow(LPCWSTR sz_window_class, LPCWSTR sz_tile, HINSTANCE& inst);
	void enter(HWND hWnd, HINSTANCE hInst);
	void update();
	void render(HDC hdc);
	void changeScene(SCENE_ID id);

	void text_client_rt();

};

