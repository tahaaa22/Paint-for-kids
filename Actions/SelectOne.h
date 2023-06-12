#pragma once
#include "Action.h"
class SelectOne: public Action
{
private:
	Point P;
public:
	SelectOne(ApplicationManager* pApp);
	virtual bool ActionParameter();
	//virtual void Execute();

};