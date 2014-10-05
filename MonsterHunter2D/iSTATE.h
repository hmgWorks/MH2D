#pragma once
class cMONSTER_BASE;
__interface iSTATE
{
	void enter(cMONSTER_BASE* monster);
	void excute(cMONSTER_BASE* monster);
	void exit(cMONSTER_BASE* monster);
};