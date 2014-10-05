#pragma once
class cINPUT_MANAGER
{
public:
	cINPUT_MANAGER();
	~cINPUT_MANAGER();

	void keyDown(WPARAM dw_key);
	void KeyUp(WPARAM dw_key);
	BOOL getDownKey_once(WPARAM dw_key);
	BOOL getDownKey(WPARAM dw_key);
	
	POINT getMouse(){ return mouse_position_; }
	void setMouse(LPARAM mousePos);
	void mouseDown(){ mouse_down_ = TRUE; }
	void mouseUp(){ mouse_down_ = FALSE; }
	BOOL getMouseDown(){ return mouse_down_; }

private:
	BOOL key_code_[256];
	BOOL key_down_once_[256];
	POINT mouse_position_;
	BOOL mouse_down_;
};

