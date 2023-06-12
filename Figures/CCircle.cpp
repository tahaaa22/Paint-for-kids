#include "CCircle.h"

CCircle::CCircle(Point P1, Point P2,GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	a = P1;
	b = P2;
}


void CCircle::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawCircle(a, b, FigGfxInfo, Selected);
}