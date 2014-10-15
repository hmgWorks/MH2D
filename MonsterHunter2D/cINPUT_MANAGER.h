#pragma once
class cINPUT_MANAGER
{
public:
	cINPUT_MANAGER();
	~cINPUT_MANAGER();

	//kebode input
	void keyDown(WPARAM dw_key);
	void KeyUp(WPARAM dw_key);
	BOOL getDownKey_once(WPARAM dw_key);
	BOOL getDownKey(WPARAM dw_key);
	
	//mouse input
	BOOL isMouseDown(){ return mouse_down_; }
	
	void mouseDown(){ mouse_down_ = TRUE; }
	void mouseUp(){ mouse_down_ = FALSE; }
	POINT getMousePos(){ return mouse_position_; }
	void setMousePos(LPARAM mousePos);

	//void setChar(WPARAM wparam);
	
	//WCHAR* buf_;
private:
	BOOL key_code_[256];
	BOOL key_down_once_[256];
	POINT mouse_position_;
	BOOL mouse_down_;	

	int len_;
};

