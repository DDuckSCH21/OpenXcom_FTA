#pragma once
/*
 * Copyright 2010-2022 OpenXcom Developers.
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
#include "../Engine/State.h"
#include <vector>

namespace OpenXcom
{
class Base;
class Surface;
class TextButton;
class Text;
class TextEdit;
class ComboBox;
class Bar;
class Soldier;
enum SoldierRole : int;

/**
 * Soldier Info screen that shows all the
 * info of a specific soldier.
 */
class SoldierInfoStateFtA : public State
{
private:
	Base *_base;
	size_t _soldierId;
	Soldier *_soldier;
	std::vector<Soldier*> *_list;
	SoldierRole _role;

	Surface *_bg, *_rank;
	InteractiveSurface *_flag;
	TextButton *_btnOk, *_btnPrev, *_btnNext, *_btnArmor, *_btnSack, *_btnDiary, *_btnBonuses;
	Text *_txtRank, *_txtMissions, *_txtKills, *_txtCraft, *_txtRecovery, *_txtPsionic, *_txtDead, *_txtOperation;
	Text *_txtStuns;
	TextEdit *_edtSoldier;
	ComboBox *_cbxRoles;
	std::vector<std::string> _rolesList;
	bool _ftaUI, _localChange;

	Text *_txtTimeUnits, *_txtStamina, *_txtHealth, *_txtBravery, *_txtReactions, *_txtFiring, *_txtThrowing, *_txtMelee, *_txtStrength, *_txtPsiStrength, *_txtPsiSkill, *_txtMana;
	Text *_numTimeUnits, *_numStamina, *_numHealth, *_numBravery, *_numReactions, *_numFiring, *_numThrowing, *_numMelee, *_numStrength, *_numPsiStrength, *_numPsiSkill, *_numMana;
	Bar *_barTimeUnits, *_barStamina, *_barHealth, *_barBravery, *_barReactions, *_barFiring, *_barThrowing, *_barMelee, *_barStrength, *_barPsiStrength, *_barPsiSkill, *_barMana;
	Text *_txtManeuvering, *_txtMissiles, *_txtDogfight, *_txtTracking, *_txtCooperation, *_txtBeams, *_txtSynaptic, *_txtGravity;
	Text *_numManeuvering, *_numMissiles, *_numDogfight, *_numTracking, *_numCooperation, *_numBeams, *_numSynaptic, *_numGravity;
	Bar *_barManeuvering, *_bartMissiles, *_barDogfight, *_barTracking, *_barCooperation, *_barBeams, *_barSynaptic, *_barGravity;
	Text* _txtStealth, * _txtPerseption, * _txtCharisma, * _txtInvestigation, * _txtDeception, * _txtInterrogation;
	Text* _numStealth, * _numPerseption, * _numCharisma, * _numInvestigation, * _numDeception, * _numInterrogation;
	Bar* _barStealth, * _barPerseption, * _barCharisma, * _barInvestigation, * _barDeception, * _barInterrogation;
	Text *_txtPhysics, *_txtChemistry, *_txtBiology, *_txtInsight, *_txtData, *_txtComputers, *_txtTactics, *_txtMaterials, *_txtDesigning, *_txtAlienTech, *_txtPsionics, *_txtXenolinguistics;
	Text *_numPhysics, *_numChemistry, *_numBiology, *_numInsight, *_numData, *_numComputers, *_numTactics, *_numMaterials, *_numDesigning, *_numAlienTech, *_numPsionics, *_numXenolinguistics;
	Bar *_barPhysics, *_barChemistry, *_barBiology, *_barInsight, *_barData, *_barComputers, *_barTactics, *_barMaterials, *_barDesigning, *_barAlienTech, *_barPsionics, *_barXenolinguistics;
	Text *_txtWeaponry, *_txtExplosives, *_txtMicroelectronics, *_txtMetallurgy, *_txtProcessing, *_txtEfficiency, *_txtDiligence, *_txtHacking, *_txtConstruction, *_txtReverseEngineering;
	Text *_numWeaponry, *_numExplosives, *_numMicroelectronics, *_numMetallurgy, *_numProcessing, *_numEfficiency, *_numDiligence, *_numHacking, *_numConstruction, *_numReverseEngineering;
	Bar *_barWeaponry, *_barExplosives, *_barMicroelectronics, *_barMetallurgy, *_barProcessing, *_barEfficiency, *_barDiligence, *_barHacking, *_barConstruction, *_barReverseEngineering;
	void defineStatLines();
	void addStatLines();
	void nameBars();
	void updateVisibility();
	void hideAllStats();
	void fillNumbers();
	void displayPsionic(SoldierRole selected);

  public:
	/// Creates the Soldier Info state.
	SoldierInfoStateFtA(Base *base, size_t soldierId);
	/// Cleans up the Soldier Info state.
	~SoldierInfoStateFtA();
	/// Updates the soldier info.
	void init() override;
	/// Set the soldier Id.
	void setSoldierId(size_t soldier);
	/// Handler for pressing on the Name edit.
	void edtSoldierPress(Action *action);
	/// Handler for changing text on the Name edit.
	void edtSoldierChange(Action *action);
	/// Handler for clicking the OK button.
	void btnOkClick(Action *action);
	/// Handler for clicking the Previous button.
	void btnPrevClick(Action *action);
	/// Handler for clicking the Next button.
	void btnNextClick(Action *action);
	/// Handler for clicking the Armor button.
	void btnArmorClick(Action *action);
	/// Handler for clicking the Bonuses button.
	void btnBonusesClick(Action *action);
	/// Handler for clicking the Sack button.
	void btnSackClick(Action *action);
	/// Handler for clicking the Diary button.
	void btnDiaryClick(Action *action);
	/// Handler for changing the roles actions combo box.
	void cbxRolesChange(Action *action);
	/// Handler for clicking the flag.
	void btnFlagClick(Action *action);
};

}
