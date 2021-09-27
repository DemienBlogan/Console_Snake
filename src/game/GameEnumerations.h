#pragma once

enum class GameWindow
{
	StartScreen,
	Menu,
	GameScene
};

enum class GameMode
{
	Classic,
	Company,
	None
};

enum class MenuType
{
	MainMenu,
	Tutorials,
	OptionsMenu,
	GraphicsMenu,
	GameModesMenu,
	ClassicGameOverMenu,
	CompanyGameOverMenu,
	BestScoresMenu,
	ConfirmationMenu,
	CompanyLevelsMenu,
	WinLevelMenu
};

// First color - background, second color - foreground
enum class ColorTheme
{
	Black_Green,
	LightAqua_Black,
	LightYellow_Purple
};

enum class OperationToConfirm
{
	DeleteScores,
	DeleteCompanyProgress,
	None
};

enum class Direction
{
	Up,
	Right,
	Left,
	Down,
	None
};

// ------------------------------
// ---- DIFFERENT MENU ITEMS ----

enum class MainMenuItem
{
	StartGame,
	Scores,
	Tutorials,
	Options,
	Exit
};

enum class OptionsMenuItem
{
	Graphics,
	DeleteScores,
	DeleteSaves,
	BackToMainMenu
};

enum class GraphicsMenuItem
{
	ColorScheme1,
	ColorScheme2,
	ColorScheme3,
	BackToOptionsMenu
};

enum class GameModesMenuItem
{
	Classic,
	Company,
	BackToMainMenu
};

enum class ConfirmationMenuItem
{
	Yes,
	No
};

enum class CompanyLevelsMenuItem
{
	Level1,
	Level2,
	Level3,
	Level4,
	Level5,
	BackToMainMenu
};