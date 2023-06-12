#pragma once
#ifndef CHEXA_H
#define CHEXA_H

#include "CFigure.h"

class CHexa : public CFigure
{
private:
	Point P;
public:
	CHexa(Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
};

#endif