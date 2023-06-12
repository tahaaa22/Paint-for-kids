#include "Input.h"
#include "Output.h"


Input::Input(window* pW) 
{
	pWind = pW; //point to the passed window
}

void Input::GetPointClicked(int &x, int &y) const
{
	pWind->WaitMouseClick(x, y);	//Wait for mouse click
}
				////////////////RETURN IF NEEDED

/*bool Input::InDrawingArea(int x, int y) const
{
	return (y > UI.ToolBarHeight && y < (UI.height - UI.StatusBarHeight));
}*/  

					

string Input::GetSrting(Output *pO) const 
{
	string Label;
	char Key;
	while (1)
	{
		pWind->WaitKeyPress(Key);
		if (Key == 27)	//ESCAPE key is pressed
			return "";	//returns nothing as user has cancelled label
		if (Key == 13)	//ENTER key is pressed
		{
			return Label;
			break;
		}
		if((Key == 8) && (Label.size() >= 1))	//BackSpace is pressed
			Label.resize(Label.size() -1 );			
		else
			Label += Key;
		if (pO)
			pO->PrintMessage(Label);
	}
}

//This function reads the position where the user clicks to determine the desired action
ActionType Input::GetUserAction() const
{	
	int x,y;
	pWind->WaitMouseClick(x, y);	//Get the coordinates of the user click

	if(UI.InterfaceMode == MODE_DRAW)	//GUI in the DRAW mode
	{
		//[1] If user clicks on the Toolbar
		if ( y >= 0 && y < UI.ToolBarHeight)
		{	
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
			case ITM_RECT: return DRAW_RECT;
			case ITM_Square:return DRAW_Square;
			case ITM_Hexa:return DRAW_Hexa;
			case ITM_Triangle:return DRAW_Triangle;
			case ITM_Circle:return DRAW_Circle;
			case OUTLINECOLOR: return OUTLINE_COLOR;
			case FILLCOLOR: return FILL_COLOR;
			case BLACKCOLOR: return BLACK_COLOR;
			case YELLOWCOLOR: return YELLOW_COLOR;
			case ORANGECOLOR: return ORANGE_COLOR;
			case REDCOLOR: return RED_COLOR;
			case GREENCOLOR: return GREEN_COLOR;
			case BLUECOLOR: return BLUE_COLOR;
			case UNDOACTION: return UNDO_ACTION;
			case REDOACTION: return REDO_ACTION;
			case CLEARALL: return CLEAR_ALL;
			case SAVEGRAPH: return SAVE_GRAPH;
			case LOADGRAPH: return LOAD_GRAPH;
			case DELETE_ICON: return delete_icon;
			case ITM_EXIT: return EXIT;
			case ITM_Start_Record:return Start_Record;
			case ITM_Stop_Record:return Stop_Record;
			case ITM_Play_Record:return Play_Record;
			case MOVE_FIGURE:return Move_FIGURE;
			case ITM_to_draw:return TO_DRAW;
			case ITM_to_play:return TO_PLAY;
			case DRAWING_AREA: return DRAWING_AREA;
			case FIGURE_TYBE: return FIGURE_TYBE;
	
			default: return EMPTY;	//A click on empty place in desgin toolbar
			}
		}

		//[2] User clicks on the drawing area
		if ( y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return DRAWING_AREA;	
		}
		
		//[3] User clicks on the status bar
		return STATUS;
	}
	else	//GUI is in PLAY mode
	{
		if (y >= 0 && y < UI.ToolBarHeight)
		{
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
			case SELECT_BY_FIGURE_TYPE:return SELECTEDBYFIGURETYPE;
			case SELECT_BY_FIGURE_COLOR:return SELECTBYFIGURECOLOR;
			case SELECT_BY_TYBE_COLOR:return SELECTBYTYBECOLOR;
			case RESTART:return RESTART_PLAY;
			case DRAW_MODE:return DRAWMODE;
			case EXIT_PLAY: return EXITPLAY;
			

			default: return EMPTY;	//A click on empty place in desgin toolbar
			}
			///TODO:
			//perform checks similar to Draw mode checks above
			//and return the correspoding action
			return TO_PLAY;	//just for now. This should be updated
		}

	}
}
/////////////////////////////////
	
Input::~Input()
{
}
