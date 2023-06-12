#ifndef DEFS_H
#define DEFS_H

#include "CMUgraphicsLib\CMUgraphics.h"

//This file contains some global constants and definitions to be used in the project.
enum ActionType //The actions supported (you can add more if needed)
{
	DRAW_RECT,		//Draw Rectangle
	DRAW_Square,
	DRAW_Hexa,
	DRAW_Triangle,
	DRAW_Circle,
	OUTLINE_COLOR,	//OUTLINE COLOR
	FILL_COLOR, 	//FILL COLOR

	BLACK_COLOR,
	YELLOW_COLOR,
	ORANGE_COLOR,
	RED_COLOR,
	GREEN_COLOR,
	BLUE_COLOR,

	UNDO_ACTION,	//UNDO ACTION
	REDO_ACTION,	//REDO ACTION
	CLEAR_ALL,		//CLEAR ALL THINGS ON SCREEN
	SAVE_GRAPH,     //SAVE ALL THE SKETCH PAGE
	LOAD_GRAPH,     //LOAD A PREIVIOUS  THE SKETCH PAGE
	delete_icon,
	EXIT,			//Exit
	Start_Record,
	Stop_Record,
	Play_Record,
	Move_FIGURE,
	DRAWING_COLOR,
	FILLING_COLOR,
	TO_DRAW,		//Switch interface to Draw mode
	TO_PLAY,		//Switch interface to Play mode
	EMPTY,			//A click on empty place in the toolbar
	DRAWING_AREA,  	//A click on the drawing area
	FIGURE_TYBE,
	FIGURE_COLOR,
	TYBE_COLOR,
	RESTART1,
	TO_DRAW_MODE,
	EXIT_PLAY1,
	SELECTEDBYFIGURETYPE,
	SELECTBYFIGURECOLOR,
	SELECTBYTYBECOLOR,
	RESTART_PLAY,
	DRAWMODE,
	EXITPLAY,

	STATUS			//A click on the status bar

	///TODO: Add the other action types of the two modes
};

struct Point	//To be used for figures points
{ int x,y; };

struct GfxInfo	//Graphical info of each figure (you may add more members)
{
	color DrawClr;	//Draw color of the figure
	color FillClr;	//Fill color of the figure
	bool isFilled;	//Figure Filled or not
	int BorderWdth;	//Width of figure borders

};

#endif