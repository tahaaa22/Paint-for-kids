#include "ApplicationManager.h"
#include "Actions\AddRectAction.h"
#include "Actions\AddSquareAction.h"
#include "Actions\AddHexaAction.h"
#include "Actions\AddCircleAction.h"
#include "Actions\AddTriangleAction.h"

//Constructor
ApplicationManager::ApplicationManager()
{
	//Create Input and output
	pOut = new Output;
	pIn = pOut->CreateInput();

	FigCount = 0;

	//Create an array of figure pointers and set them to NULL		
	for (int i = 0; i < MaxFigCount; i++)
		FigList[i] = NULL;
}

//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//
ActionType ApplicationManager::GetUserAction() const
{
	//Ask the input to get the action from the user.
	return pIn->GetUserAction();
}
////////////////////////////////////////////////////////////////////////////////////
//Creates an action and executes it
void ApplicationManager::ExecuteAction(ActionType ActType)
{
	Action* pAct = NULL;

	//According to Action Type, create the corresponding action object

	switch (ActType)
	{
	case DRAW_RECT:
		pAct = new AddRectAction(this);
		break;
	case DRAW_Square:
		pAct = new AddSquareAction(this);
		break;
	case DRAW_Hexa:
		pAct = new AddHexaAction(this);
		break;
	case DRAW_Triangle:
		pAct = new AddTriangleAction(this);
		break;
	case DRAW_Circle:
		pAct = new AddCircleAction(this);
		break;
	case EXIT:
		///create ExitAction here

		break;
	case OUTLINE_COLOR:
		pOut->PrintMessage("Action: Outline color , Click anywhere");
		break;

	case FILL_COLOR:
		pOut->PrintMessage("Action: Fill color , Click anywhere");
		break;
	case BLACK_COLOR:
		pOut->PrintMessage("Action: BLACK color , Click anywhere");
		break;
	case YELLOW_COLOR:
		pOut->PrintMessage("Action: YELLOW color , Click anywhere");
		break;
	case ORANGE_COLOR:
		pOut->PrintMessage("Action: ORANGE color , Click anywhere");
		break;
	case RED_COLOR:
		pOut->PrintMessage("Action: RED color , Click anywhere");
		break;
	case GREEN_COLOR:
		pOut->PrintMessage("Action: GREEN color , Click anywhere");
		break;
	case BLUE_COLOR:
		pOut->PrintMessage("Action: BLUE color , Click anywhere");
		break;


	case UNDO_ACTION:
		pOut->PrintMessage("Action: UNDO LAST ACTION , Click anywhere");
		break;

	case REDO_ACTION:
		pOut->PrintMessage("Action: REDO LAST ACTION , Click anywhere");
		break;
	case CLEAR_ALL:
		pOut->PrintMessage("Action: CLEAR ALL ACTION , Click anywhere");
		break;
	case SAVE_GRAPH:
		pOut->PrintMessage("Action: SAVE THE CURRENT GRAPH , Click anywhere");
		break;
	case LOAD_GRAPH:
		pOut->PrintMessage("Action: LOAD A PREVIOS GRAPH , Click anywhere");
		break;
	case Stop_Record:
		pOut->PrintMessage("Action: Stop recording, Click anywhere");
		break;
	case Start_Record:
		pOut->PrintMessage("Action: start recording, Click anywhere");
		break;
	case delete_icon:
		pOut->PrintMessage("Action: delete figure, Click anywhere");
		break;

	case STATUS:
		pOut->PrintMessage("Action: a click on the Status Bar, Click anywhere");
		break;

	case DRAWING_AREA:
		pOut->PrintMessage("Action: a click on the Drawing Area, Click anywhere");
		break;

	case Play_Record:
		pOut->PrintMessage("Action: a click on the Play record, Click anywhere");
		break;

	case Move_FIGURE:
		pOut->PrintMessage("Action: a click on the Move Figure, Click anywhere");
		break;
	case TO_DRAW:
		pOut->PrintMessage("Action: Switch to Draw Mode, creating simualtion tool bar");
		pOut->ClearTOOLArea();
		pOut->CreateDrawToolBar();
		break;

	case TO_PLAY:
		pOut->PrintMessage("Action: Switch to Play Mode, creating Design tool bar");
		pOut->ClearTOOLArea();
		pOut->CreatePlayToolBar();
		break;

	case SELECTEDBYFIGURETYPE:
		pOut->PrintMessage("Action: select by figure type , Click anywhere");
		break;
	case SELECTBYFIGURECOLOR:
		pOut->PrintMessage("Action: Select by figure color , Click anywhere");
		break;
	case SELECTBYTYBECOLOR:
		pOut->PrintMessage("Action: Select by type and color , Click anywhere");
		break;
	case RESTART_PLAY:
		pOut->PrintMessage("Action: click to Restart , Click anywhere");
		break;
	case DRAWMODE:
		pOut->PrintMessage("Action: switch to Draw mode , Click anywhere");
		pOut->ClearTOOLArea();
		pOut->CreateDrawToolBar();
		break;
	case EXITPLAY:
		//z = 1;
		break;
	case EMPTY:
		pOut->PrintMessage("Action: a click on empty area in the Design Tool Bar, Click anywhere");
		break;

	}


	//Execute the created action
	if (pAct != NULL)
	{
		pAct->Execute();//Execute
		delete pAct;	//You may need to change this line depending to your implementation
		pAct = NULL;
	}
}

//==================================================================================//
//						Figures Management Functions								//
//==================================================================================//

//Add a figure to the list of figures
void ApplicationManager::AddFigure(CFigure* pFig)
{
	if (FigCount < MaxFigCount)
		FigList[FigCount++] = pFig;
}
////////////////////////////////////////////////////////////////////////////////////
CFigure* ApplicationManager::GetFigure(int x, int y) const
{
	return NULL;
}
//If a figure is found return a pointer to it.
//if this point (x,y) does not belong to any figure return NULL


//Add your code here to search for a figure given a point x,y	
//Remember that ApplicationManager only calls functions do NOT implement it.


//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

//Draw all figures on the user interface
void ApplicationManager::UpdateInterface() const
{
	for (int i = 0; i < FigCount; i++)
		FigList[i]->Draw(pOut);		//Call Draw function (virtual member fn)
}
////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the input
Input* ApplicationManager::GetInput() const
{
	return pIn;
}
//Return a pointer to the output
Output* ApplicationManager::GetOutput() const
{
	return pOut;
}
////////////////////////////////////////////////////////////////////////////////////
//Destructor
ApplicationManager::~ApplicationManager()
{
	for (int i = 0; i < FigCount; i++)
		delete FigList[i];
	delete pIn;
	delete pOut;

}
