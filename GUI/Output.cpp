#include "Output.h"


Output::Output()
{
	//Initialize user interface parameters
	UI.InterfaceMode = MODE_DRAW;
	
	UI.width = 1250;
	UI.height = 650;
	UI.wx = 5;
	UI.wy =5;

	
	UI.StatusBarHeight = 45;
	UI.ToolBarHeight = 45;
	UI.MenuItemWidth = 45;
	
	UI.DrawColor = BLUE;	//Drawing color
	UI.FillColor = GREEN;	//Filling color
	UI.MsgColor = RED;		//Messages color
	UI.BkGrndColor = LIGHTGOLDENRODYELLOW;	//Background color
	UI.HighlightColor = MAGENTA;	//This color should NOT be used to draw figures. use if for highlight only
	UI.StatusBarColor = TURQUOISE;
	UI.PenWidth = 3;	//width of the figures frames

	
	//Create the output window
	pWind = CreateWind(UI.width, UI.height, UI.wx, UI.wy);
	//Change the title
	pWind->ChangeTitle("Paint for Kids - Programming Techniques Project");
	
	CreateDrawToolBar();
	CreateStatusBar();
}


Input* Output::CreateInput() const
{
	Input* pIn = new Input(pWind);
	return pIn;
}

//======================================================================================//
//								Interface Functions										//
//======================================================================================//

window* Output::CreateWind(int w, int h, int x, int y) const
{ 
	window* pW = new window(w, h, x, y);
	pW->SetBrush(UI.BkGrndColor);
	pW->SetPen(UI.BkGrndColor, 1);
	pW->DrawRectangle(0, UI.ToolBarHeight, w, h);	
	return pW;
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateStatusBar() const
{
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearStatusBar() const
{
	//Clear Status bar by drawing a filled white rectangle
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateDrawToolBar() const
{
	UI.InterfaceMode = MODE_DRAW;

	//You can draw the tool bar icons in any way you want.
	//Below is one possible way
	
	//First prepare List of images for each menu item
	//To control the order of these images in the menu, 
	//reoder them in UI_Info.h ==> enum DrawMenuItem
	string MenuItemImages[DRAW_ITM_COUNT];
	MenuItemImages[ITM_RECT] = "images\\MenuItems\\Menu_Rect.jpg";
	MenuItemImages[ITM_Square] = "images\\MenuItems\\Menu_Square.jpg";
	MenuItemImages[ITM_Triangle] = "images\\MenuItems\\Menu_Triangle.jpg";
	MenuItemImages[ITM_Hexa] = "images\\MenuItems\\Menu_Hexa.jpg";
	MenuItemImages[ITM_Circle] = "images\\MenuItems\\Menu_Circ.jpg";
	MenuItemImages[OUTLINECOLOR] = "images\\MenuItems\\shape_outline.jpg";
	MenuItemImages[FILLCOLOR] = "images\\MenuItems\\shape_fill.jpg";
	MenuItemImages[BLACKCOLOR] = "images\\MenuItems\\black_color.jpg";
	MenuItemImages[YELLOWCOLOR] = "images\\MenuItems\\yellow_color.jpg";
	MenuItemImages[ORANGECOLOR] = "images\\MenuItems\\orange_color.jpg";
	MenuItemImages[REDCOLOR] = "images\\MenuItems\\red_color.jpg";
	MenuItemImages[GREENCOLOR] = "images\\MenuItems\\green_color.jpg";
	MenuItemImages[BLUECOLOR] = "images\\MenuItems\\blue_color.jpg";
	MenuItemImages[UNDOACTION] = "images\\MenuItems\\undo_shape.jpg";
	MenuItemImages[REDOACTION] = "images\\MenuItems\\redo_shape.jpg";
	MenuItemImages[SAVEGRAPH] = "images\\MenuItems\\save_graph.jpg";
	MenuItemImages[LOADGRAPH] = "images\\MenuItems\\load_graph.jpg";
	MenuItemImages[DELETE_ICON] = "images\\MenuItems\\deleteicon.jpg";
	MenuItemImages[CLEARALL] = "images\\MenuItems\\clear_all.jpg";
	MenuItemImages[ITM_Start_Record] = "images\\MenuItems\\Menu_Start_Record.jpg";
	MenuItemImages[ITM_Stop_Record] = "images\\MenuItems\\Menu_Stop_Record.jpg";
	MenuItemImages[ITM_Play_Record] = "images\\MenuItems\\Menu_Play_Record.jpg";
	MenuItemImages[ITM_to_play] = "images\\MenuItems\\Menu_to_play.jpg";
	MenuItemImages[ITM_to_draw] = "images\\MenuItems\\Menu_to_draw.jpg";
    MenuItemImages[MOVE_FIGURE] = "images\\MenuItems\\Menu_MOVE_FIGURE.jpg";
	MenuItemImages[ITM_EXIT] = "images\\MenuItems\\Menu_Exit.jpg";

	//TODO: Prepare images for each menu item and add it to the list

	//Draw menu item one image at a time
	for(int i=0; i<DRAW_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i*UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);

	//Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);	

}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::CreatePlayToolBar() const

{
	UI.InterfaceMode = MODE_PLAY;
	string PlayItemImages[PLAY_ITM_COUNT];
	PlayItemImages[SELECT_BY_FIGURE_TYPE] = "images\\MenuItems\\Menu_SELECT_BY_FIGURE_TYPE.jpg";
	PlayItemImages[SELECT_BY_FIGURE_COLOR] = "images\\MenuItems\\Menu_SELECT_BY_FIGURE_COLOR.jpg";
	PlayItemImages[SELECT_BY_TYBE_COLOR] = "images\\MenuItems\\Menu_SELECT_BY_TYPE_COLOR.jpg";
	PlayItemImages[RESTART] = "images\\MenuItems\\Menu_RESTART.jpg";
	PlayItemImages[DRAW_MODE] = "images\\MenuItems\\Menu_DRAW_MODE.jpg";
	PlayItemImages[EXIT_PLAY] = "images\\MenuItems\\Menu_EXIT_PLAY.jpg";
	
	for (int i = 0; i < PLAY_ITM_COUNT; i++)

	pWind->DrawImage(PlayItemImages[i], i * UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);
	
//Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);
	
}
	///TODO: write code to create Play mode menu
//////////////////////////////////////////////////////////////////////////////////////////

void Output::ClearDrawArea() const
{
	pWind->SetPen(UI.BkGrndColor, 1);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(0, UI.ToolBarHeight, UI.width, UI.height - UI.StatusBarHeight);
	
}
void Output::ClearTOOLArea() const
{
	pWind->SetPen(UI.BkGrndColor, 1);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(0, 0, UI.width, UI.height - UI.StatusBarHeight);

}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::PrintMessage(string msg) const	//Prints a message on status bar
{
	ClearStatusBar();	//First clear the status bar
	
	pWind->SetPen(UI.MsgColor, 50);
	pWind->SetFont(20, BOLD , BY_NAME, "Arial");   
	pWind->DrawString(10, UI.height - (int)(UI.StatusBarHeight/1.5), msg);
}
//////////////////////////////////////////////////////////////////////////////////////////

color Output::getCrntDrawColor() const	//get current drawing color
{	return UI.DrawColor;	}
//////////////////////////////////////////////////////////////////////////////////////////

color Output::getCrntFillColor() const	//get current filling color
{	return UI.FillColor;	}
//////////////////////////////////////////////////////////////////////////////////////////
	
int Output::getCrntPenWidth() const		//get current pen width
{	return UI.PenWidth;	}

//======================================================================================//
//								Figures Drawing Functions								//
//======================================================================================//

void Output::DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected) const
{
	color DrawingClr;
	if(selected)	
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else			
		DrawingClr = RectGfxInfo.DrawClr;
	
	pWind->SetPen(DrawingClr,1);
	drawstyle style;
	if (RectGfxInfo.isFilled)	
	{
		style = FILLED;		
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else	
		style = FRAME;

	
	pWind->DrawRectangle(P1.x, P1.y, P2.x, P2.y, style);
	
}
void Output::DrawHexa(Point P1, GfxInfo HexaGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = HexaGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (HexaGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(HexaGfxInfo.FillClr);
	}
	else
		style = FRAME;
	int p1[6];
	int p2[6];
	p1[0] = P1.x - 100/2;
	p1[1] = P1.x + 100/2;
	p1[2] = P1.x + 100;
	p1[3] = P1.x + 100/2;
	p1[4] = P1.x - 100/2;
	p1[5] = P1.x - 100;


	p2[0] = P1.y - sqrt(3) * 100 / 2;
	p2[1] = P1.y - sqrt(3) * 100 / 2;
	p2[2] = P1.y ;
	p2[3] = P1.y + +sqrt(3) * 100 / 2;
	p2[4] = P1.y + sqrt(3) * 100/2;
	p2[5] = P1.y ;

	pWind->DrawPolygon(p1, p2,6, style);


}
void Output::DrawCircle(Point P1,Point P2, GfxInfo circleGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = circleGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (circleGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(circleGfxInfo.FillClr);
	}
	else
		style = FRAME;
	int r = sqrt((P2.y - P1.y) * (P2.y - P1.y) + (P2.x - P1.x) * (P2.x - P1.x));

	pWind->DrawCircle(P1.x, P1.y,r, style);
}
void Output::DrawTriangle(Point P1,Point P2,Point P3, GfxInfo triangleGfxInfo, bool selected) const 
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = triangleGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (triangleGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(triangleGfxInfo.FillClr);
	}
	else
		style = FRAME;


	pWind->DrawTriangle(P1.x,P1.y,P2.x,P2.y,P3.x,P3.y, style);
}
void Output::DrawSquare(Point P1, GfxInfo squareGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = squareGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (squareGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(squareGfxInfo.FillClr);
	}
	else
		style = FRAME;

	int p1[4];
	int p2[4];
	p1[0] = P1.x - 100;
	p1[1] = P1.x + 100;
	p1[2] = P1.x + 100;
	p1[3] = P1.x - 100;



	p2[0] = P1.y - 100;
	p2[1] = P1.y - 100;
	p2[2] = P1.y + 100;
	p2[3] = P1.y + 100;


	pWind->DrawPolygon(p1, p2, 4, style);
}


//////////////////////////////////////////////////////////////////////////////////////////
Output::~Output()
{
	delete pWind;
}

