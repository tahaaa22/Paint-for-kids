
#include "SelectOne.h"
#include "..\Figures\CFigure.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"
 SelectOne::SelectOne(ApplicationManager* pApp) : Action(pApp)
 {
	 P.x = 0;
	 P.y = 0;
 }
 bool SelectOne::ActionParameter()
 {
	 Output* pOut = pManager->GetOutput();
	 Input* pIn = pManager->GetInput();

	 pOut->PrintMessage("Select Figure : Click at any Figure");

	 //Read Point Parameters
	 pIn->GetPointClicked(P.x, P.y);
	 if (P.y < UI.ToolBarHeight || P.y >(UI.height - UI.StatusBarHeight))
	 {
		 pOut->PrintMessage("Invalid Point");
		 return false;
	 }

	 pOut->ClearStatusBar();
	 return true;
 }

 