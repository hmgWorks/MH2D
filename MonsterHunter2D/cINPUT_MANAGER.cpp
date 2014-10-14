#include "stdafx.h"
#include "cINPUT_MANAGER.h"


cINPUT_MANAGER::cINPUT_MANAGER()
{
	memset(key_code_, 0, sizeof(key_code_));
	memset(key_down_once_, 0, sizeof(key_down_once_));
	mouse_down_ = FALSE;
}
cINPUT_MANAGER::~cINPUT_MANAGER()
{

}
void cINPUT_MANAGER::keyDown(WPARAM dw_key)
{
	key_code_[dw_key] = TRUE; 	
}

void cINPUT_MANAGER::KeyUp(WPARAM dw_key)
{
	key_code_[dw_key] = FALSE; 
	key_down_once_[dw_key] = FALSE;
}

BOOL cINPUT_MANAGER::getDownKey(WPARAM dw_key)
{
	if (key_code_[dw_key])
		return TRUE;
	return FALSE;
}

BOOL cINPUT_MANAGER::getDownKey_once(WPARAM dw_key)
{
	if (key_code_[dw_key] == TRUE)
	{
		if (key_down_once_[dw_key] == FALSE)
		{
			key_down_once_[dw_key] = TRUE;
			return TRUE;
		}		
	}
	return FALSE;
}

void cINPUT_MANAGER::setMousePos(LPARAM mousePos)
{
	mouse_position_.x = LOWORD(mousePos);
	mouse_position_.y = HIWORD(mousePos);
}