#ifndef UI_INFO_H
#define UI_INFO_H

#include "..\CMUgraphicsLib\CMUgraphics.h"

//User Interface information file.
//This file contains info that is needed by Input and Output classes to
//handle the user interface

enum GUI_MODE	//Graphical user interface mode
{
	MODE_DRAW,	//Drawing mode (startup mode)
	MODE_PLAY	//Playing mode
};

enum DrawMenuItem //The items of the Draw menu (you should add more items)
{
	//Note: Items are **(ordered)** here as they appear in menu
	//If you want to change the menu items order, change the order here
	ITM_RECT,//Recangle item in menu
	ITM_Square,
	ITM_Triangle,
	ITM_Hexa,
	ITM_Circle,
	OUTLINECOLOR,
	FILLCOLOR,		 //FILL COLOR OF THE SHAPE
	BLACKCOLOR,
	YELLOWCOLOR,
	ORANGECOLOR,
	REDCOLOR,
	GREENCOLOR,
	BLUECOLOR,
	UNDOACTION,		//UNDO ACTION
	REDOACTION,     	//REDO ACTION
	SAVEGRAPH,      //SAVE ALL THINGS ON THE SCREEN
	LOADGRAPH,      //LOAD A PREVIOS GRAPH
	DELETE_ICON,
	CLEARALL,		//DELETE ALL ITEMS ON SCREEN
	ITM_Start_Record,
	ITM_Stop_Record,
	ITM_Play_Record,
	ITM_to_play,
	ITM_to_draw,
	MOVE_FIGURE,

	//TODO: Add more items names here

	ITM_EXIT,		//Exit item
	
	DRAW_ITM_COUNT		//no. of menu items ==> This should be the last line in this enum
	
};

enum PlayMenuItem //The items of the Play menu (you should add more items)
{
	//Note: Items are **(ordered)** here as they appear in menu
	//If you want to change the menu items order, change the order here
	
	//TODO: Add more items names here
	SELECT_BY_FIGURE_TYPE,
	SELECT_BY_FIGURE_COLOR,
	SELECT_BY_TYBE_COLOR,
	RESTART,
	DRAW_MODE,
	EXIT_PLAY,
	PLAY_ITM_COUNT		//no. of menu items ==> This should be the last line in this enum
	
};





__declspec(selectany) //This line to prevent "redefinition error"

struct UI_Info	//User Interface Info.
{
	GUI_MODE InterfaceMode;
	
	int	width, height,	    //Window width and height
		wx , wy,			//Window starting coordinates
		StatusBarHeight,	//Status Bar Height
		ToolBarHeight,		//Tool Bar Height (distance from top of window to bottom line of toolbar)
		MenuItemWidth;		//Width of each item in toolbar menu
	

	color DrawColor;		//Drawing color
	color FillColor;		//Filling color
	color HighlightColor;	//Highlighting color
	color MsgColor;			//Messages color
	color BkGrndColor;		//Background color
	color StatusBarColor;	//Status bar color
	int PenWidth;			//width of the pen that draws shapes

	/// Add more members if needed
	
}UI;	//create a global object UI

#endif