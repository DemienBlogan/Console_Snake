#pragma once
#include <string>
#include <Windows.h>
#include "../game/GameEnumerations.h"

namespace Tools
{
	// All these functions use WINAPI:

	void SetApplicationSettings();
	void StopGame(unsigned milliseconds);
	void ResetCursorPosition();
	void SetCursorPosition(size_t x, size_t y);
	void HideCursor();
	void SetWindowSize(SHORT width, SHORT height);
	void SetFontSettings(SHORT fontSize, const wchar_t* fontName);
	void DisableScrollBars();
	void DisableMaximizeButton();
	void DisableWindowResizing();
	void SetConsoleWindowTitle();

	// Other helpful functions:

	void ClearScreen();
	void SetRandomSeed();
	void PauseApplication();
	void ChangeColorTheme(const ColorTheme& theme);

	template <typename MenuItemType>
	void ChangeMenuItemUp(MenuItemType& item, const MenuItemType& firstItem, const MenuItemType& lastItem)
	{
		item = (item == firstItem) ? lastItem : static_cast<MenuItemType>(static_cast<int>(item) - 1);
	}

	template <typename MenuItemType>
	void ChangeMenuItemDown(MenuItemType& item, const MenuItemType& firstItem, const MenuItemType& lastItem)
	{
		item = (item == lastItem) ? firstItem : static_cast<MenuItemType>(static_cast<int>(item) + 1);
	}
}