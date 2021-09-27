#include "Tools.h"
#include <iostream>
#include "WindowSettings.h"

namespace Tools
{
	void SetApplicationSettings()
	{
		SetRandomSeed();
		SetConsoleWindowTitle();
		SetFontSettings(30, L"Consolas");
		SetWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
		HideCursor();
		DisableScrollBars();
		DisableMaximizeButton();
		DisableWindowResizing();
	}

	void StopGame(unsigned milliseconds)
	{
		Sleep(milliseconds);
	}

	void ResetCursorPosition()
	{
		SetCursorPosition(0, 0);
	}

	void SetCursorPosition(size_t x, size_t y)
	{
		static HANDLE consoleWindow = GetStdHandle(STD_OUTPUT_HANDLE);
		std::cout.flush();
		COORD newCursorPosition = { static_cast<SHORT>(x), static_cast<SHORT>(y) };
		SetConsoleCursorPosition(consoleWindow, newCursorPosition);
	}

	void HideCursor()
	{
		static HANDLE consoleWindow = GetStdHandle(STD_OUTPUT_HANDLE);
		CONSOLE_CURSOR_INFO cursorInfo;
		cursorInfo.dwSize = 100;
		cursorInfo.bVisible = FALSE;
		SetConsoleCursorInfo(consoleWindow, &cursorInfo);
	}

	void SetWindowSize(SHORT width, SHORT height)
	{
		SMALL_RECT windowArea = { 0, 0, width, height };

		static HANDLE consoleWindow = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleWindowInfo(consoleWindow, TRUE, &windowArea);
	}

	void SetFontSettings(SHORT fontSize, const wchar_t* fontName)
	{
		CONSOLE_FONT_INFOEX cfi;
		cfi.cbSize = sizeof(cfi);
		cfi.nFont = 0;
		cfi.dwFontSize.X = 0;
		cfi.dwFontSize.Y = fontSize;
		cfi.FontFamily = FF_DONTCARE;
		cfi.FontWeight = FW_NORMAL;
		wcscpy_s(cfi.FaceName, sizeof(L"Consolas"), fontName);

		SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
	}

	void DisableScrollBars()
	{
		HANDLE consoleWindow = GetStdHandle(STD_OUTPUT_HANDLE);

		CONSOLE_SCREEN_BUFFER_INFO bufferInfo;
		GetConsoleScreenBufferInfo(consoleWindow, &bufferInfo);
		COORD newBuffetSize =
		{
			bufferInfo.srWindow.Right - bufferInfo.srWindow.Left + 1,
			bufferInfo.srWindow.Bottom - bufferInfo.srWindow.Top + 1
		};

		SetConsoleScreenBufferSize(consoleWindow, newBuffetSize);
	}

	void DisableMaximizeButton()
	{
		HWND consoleWindow = GetConsoleWindow();
		DWORD windowStyle = GetWindowLong(consoleWindow, GWL_STYLE);
		windowStyle &= ~WS_MAXIMIZEBOX;
		SetWindowLong(consoleWindow, GWL_STYLE, windowStyle);
		SetWindowPos(consoleWindow, NULL, 0, 0, 0, 0, SWP_NOSIZE | SWP_NOMOVE | SWP_FRAMECHANGED);
	}

	void DisableWindowResizing()
	{
		HWND consoleWindow = GetConsoleWindow();

		SetWindowLong(
			consoleWindow, 
			GWL_STYLE, 
			GetWindowLong(consoleWindow, GWL_STYLE) & ~WS_MAXIMIZEBOX & ~WS_SIZEBOX
		);
	}

	void SetConsoleWindowTitle()
	{
		SetConsoleTitle(L"Console Snake");
	}

	void ClearScreen()
	{
		system("cls");
	}

	void SetRandomSeed()
	{
		std::srand(static_cast<unsigned>(std::time(nullptr)));
	}

	void PauseApplication()
	{
		system("pause");
	}

	void ChangeColorTheme(const ColorTheme& theme)
	{
		switch (theme)
		{
		case ColorTheme::Black_Green:
			system("Color 02"); // Black background, Green text
			break;
		case ColorTheme::LightAqua_Black:
			system("Color B0"); // Light Aqua background, Black text
			break;
		case ColorTheme::LightYellow_Purple:
			system("Color E5"); // Light Yellow background, Purple text
			break;
		}
	}
}