#pragma once
//#include <Windows.h>
template<typename T>
class cSINGLETON
{
public:
	cSINGLETON(){};
	virtual ~cSINGLETON(){};

public:
	static T* getInstance()
	{
		if (singleton_ == nullptr)
		{
			singleton_ = new T();
			atexit(destroy);
		}
		return singleton_;
	}
	/*static T* getInstance_ptr()
	{
		if (singleton_ == nullptr)
		{
			singleton_ = new T();
			atexit(destroy);
		}
		return singleton_;
	}*/
	static void destroy()
	{
		delete singleton_;
		singleton_ = nullptr;
	}
private:
	static T* singleton_;
};
template<typename T> T* cSINGLETON<T>::singleton_ = nullptr;