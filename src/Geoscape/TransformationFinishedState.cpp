/*
 * Copyright 2010-2020 OpenXcom Developers.
 *
 * This file is part of OpenXcom.
 *
 * OpenXcom is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * OpenXcom is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with OpenXcom.  If not, see <http://www.gnu.org/licenses/>.
 */
#include "TransformationFinishedState.h"
#include "../Engine/Game.h"
#include "../Engine/LocalizedText.h"
#include "../Engine/Unicode.h"
#include "../Mod/Mod.h"
#include "../Mod/RuleSoldierTransformation.h"
#include "../Interface/TextButton.h"
#include "../Interface/Window.h"
#include "../Interface/Text.h"
#include "../Interface/TextList.h"
#include "../Savegame/Base.h"
#include "../Savegame/Soldier.h"
#include "../Basescape/SoldiersState.h"
#include "../Engine/Options.h"
#include "../Basescape/SoldierInfoState.h"

namespace OpenXcom
{
/**
* Initializes all the elements in the TransformationFinished screen.
* @param base Pointer to the base to get info from.
* @param list List of soldiers who finished their training
*/
TransformationFinishedState::TransformationFinishedState(Base* base, std::vector<std::pair<Soldier*, RuleSoldierTransformation*>>&& list) : _base(base), _soldiersList(std::move(list))
{
	_screen = false;

	// Create objects
	_window = new Window(this, 288, 180, 16, 10);
	_btnOk = new TextButton(160, 14, 80, 149);
	_btnOpen = new TextButton(160, 14, 80, 165);
	_txtTitle = new Text(288, 33, 16, 20);
	_lstPossibilities = new TextList(271, 87, 25, 60);

	// Set palette
	setInterface("trainingFinished");

	add(_window, "window", "trainingFinished");
	add(_btnOk, "button", "trainingFinished");
	add(_btnOpen, "button", "trainingFinished");
	add(_txtTitle, "text1", "trainingFinished");
	add(_lstPossibilities, "text2", "trainingFinished");

	centerAllSurfaces();

	// Set up objects
	setWindowBackground(_window, "trainingFinished");

	_btnOk->setText(tr("STR_OK"));
	_btnOk->onMouseClick((ActionHandler)&TransformationFinishedState::btnOkClick);
	_btnOk->onKeyboardPress((ActionHandler)&TransformationFinishedState::btnOkClick, Options::keyCancel);
	_btnOpen->setText(tr("STR_SOLDIERS"));
	_btnOpen->onMouseClick((ActionHandler)&TransformationFinishedState::btnOpenClick);
	_btnOpen->onKeyboardPress((ActionHandler)&TransformationFinishedState::btnOpenClick, Options::keyOk);
	_txtTitle->setBig();
	_txtTitle->setAlign(ALIGN_CENTER);
	_txtTitle->setText(tr("STR_TRANSFORMING_FINISHED").arg(base->getName()));

	_lstPossibilities->setColumns(2, 133, 138);
	_lstPossibilities->setMargin(2);
	_lstPossibilities->setWordWrap(true);
	_lstPossibilities->setSelectable(true);
	_lstPossibilities->setBackground(_window);
	_lstPossibilities->setDot(true);
	_lstPossibilities->setScrolling(true, 0);
	for (auto line : _soldiersList)
	{
		_lstPossibilities->addRow(2, line.first->getName().c_str(), tr(line.second->getName()).c_str());
	}
	_lstPossibilities->onMouseClick((ActionHandler)&TransformationFinishedState::onSelectSoldier, SDL_BUTTON_LEFT);
}

/**
* Closes the screen.
* @param action Pointer to an action.
*/
void TransformationFinishedState::btnOkClick(Action*)
{
	_game->popState();
}

/**
* Opens the AllocateTrainingState/AllocatePsiTrainingState.
* @param action Pointer to an action.
*/
void TransformationFinishedState::btnOpenClick(Action*)
{
	_game->popState();
	_game->pushState(new SoldiersState(_base));
}

/**
 * Displays SoldierInfoState of selected soldier.
 * @param action Pointer to an action.
 */
void TransformationFinishedState::onSelectSoldier(Action* action)
{
	/*auto selSol = _soldiersList.at(_lstPossibilities->getSelectedRow()).first;
	int id = selSol->getId() - 1;
	_game->pushState(new SoldierInfoState(_base, id));*/
}

}
