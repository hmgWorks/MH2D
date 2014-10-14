#include "stdafx.h"
#include "cMAIN_GAME.h"

cMAIN_GAME::cMAIN_GAME()
	:screen_width_(1024), screen_height_(768)
{
	input_ = unique_input(new cINPUT_MANAGER);
	resource_ = unique_resource(new cRESOURCE_MANAGER(hInst_));
	camera_ = unique_camera(new cCAMERA);
	//renderer_ = unique_render(new Renderer);
	renderer_ = unique_render(new cRENDERER);
	current_scene_ = nullptr;

	scene_map_.insert({ SCENE_ID::INTRO, shared_scene(new cSCENE_INTRO) });
	scene_map_.insert({ SCENE_ID::START, shared_scene(new cSCENE_START) });
	//scene_map_.insert({ SCENE_ID::TUTO, shared_scene(new cSCENE_TUTO) });
	scene_map_.insert({ SCENE_ID::MAIN, shared_scene(new cSCENE_MAIN) });
	 
}
cMAIN_GAME::~cMAIN_GAME()
{
	
}

//화면 사이즈 지정
HWND cMAIN_GAME::createGameWindow(LPCWSTR sz_window_class, LPCWSTR sz_tile, HINSTANCE& inst)
{	
	fullScreen(screen_width_, screen_height_);
	//::AdjustWindowRect(&rt, WS_OVERLAPPEDWINDOW, TRUE);
	return ::CreateWindow(sz_window_class, sz_tile, WS_POPUP,
		CW_USEDEFAULT, 0, client_rt_.right - client_rt_.left, client_rt_.bottom - client_rt_.top, NULL, NULL, inst, NULL);
}
void cMAIN_GAME::enter(HWND hWnd, HINSTANCE hInst)
{
	hWnd_ = hWnd;	
	hInst_ = hInst;

	::GetClientRect(hWnd_, &client_rt_);	
	changeScene(SCENE_ID::INTRO);
	
	camera_->initCamera(client_rt_);
}
void cMAIN_GAME::update()
{
	if (input_->getDownKey_once(VK_F1))
		fullScreen(screen_width_, screen_height_);				
	
	if (input_->getDownKey_once(VK_F2))
		windowMode();

	current_scene_->update(30.0 / 1000.0);
}
void cMAIN_GAME::render(HDC hdc)
{		
	renderer_->beginRender(hdc,
		client_rt_.right - client_rt_.left,
		client_rt_.bottom - client_rt_.top);
	
	current_scene_->render();
	
	//hdc_ = hdc;
	//Rectangle(hdc, 100, 100, 200, 200);
	text_client_rt();
	renderer_->endRender();
}

void cMAIN_GAME::text_client_rt()
{
	WCHAR ch[30];
	wsprintf(ch, L"%d, %d", client_rt_.right - client_rt_.left, client_rt_.bottom - client_rt_.top);
	TextOut(hdc_, client_rt_.right - 100, client_rt_.top + 100,ch,lstrlen(ch));	
}

void cMAIN_GAME::changeScene(SCENE_ID id)
{
	if (current_scene_ != nullptr)
	current_scene_->exit();
	current_scene_ = scene_map_.find(id)->second;
	current_scene_->enter();	
}

void cMAIN_GAME::fullScreen(int width, int height)
{

	DEVMODE sDevMode;
	sDevMode.dmSize = sizeof(DEVMODE);
	sDevMode.dmPelsWidth = width;
	sDevMode.dmPelsHeight = height;
	sDevMode.dmFields = DM_PELSWIDTH | DM_PELSHEIGHT;
	::ChangeDisplaySettings(&sDevMode, CDS_FULLSCREEN);	
	
	::SetWindowLongPtr(hWnd_, GWL_STYLE, WS_POPUP);
	::SetWindowPos(hWnd_, HWND_TOP, 0, 0, width, height, SWP_SHOWWINDOW);
	
	SetRect(&client_rt_, 0, 0, width, height);
	
	AdjustWindowRect(&client_rt_, WS_BORDER, FALSE);
	SetWindowPos(hWnd_, HWND_TOP, 0, 0, client_rt_.right - client_rt_.left,
		client_rt_.bottom - client_rt_.top, SWP_SHOWWINDOW);
}
void cMAIN_GAME::windowMode()
{
	::ChangeDisplaySettings(NULL, 0);
	::SetWindowLongPtr(hWnd_, GWL_STYLE, WS_OVERLAPPEDWINDOW);
	::SetWindowPos(hWnd_, HWND_TOP, 0, 0, screen_width_, screen_height_, SWP_SHOWWINDOW);
}