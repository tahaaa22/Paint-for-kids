#include "CHexa.h"

CHexa::CHexa(Point P1, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	P = P1;
}


void CHexa::Draw(Output* pOut) const
{
	//Call Output::DrawHexa to draw a hexagon on the screen	
	pOut->DrawHexa(P, FigGfxInfo, Selected);
}