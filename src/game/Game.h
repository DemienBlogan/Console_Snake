#pragma once
#include "../game_objects/GameObjects.h"
#include "GameException.h"

class Game
{
public:
	~Game();

	// Main game cycle methods:
	bool IsRunning() const;
	void HandleInput();
	void Update(double deltaTime);
	void Render();

	void HandleGameException(const GameException& exc);
	void HandleOtherException(const std::exception& exc);

	// Singlton pattern:
	static Game& GetInstance();
	Game(const Game& other) = delete;
	Game& operator=(const Game& other) = delete;

private:
	Game();

	// -------------------------------------------------------------------------
	// ---------------------- MAIN HANDLE INPUT METHODS ------------------------

	void HandleInputStartScreen();
	void HandleInputMenu();
	void HandleInputGameScene();

	// -------------------------------------------------------------------------
	// ------------------------- MAIN UPDATE METHODS ---------------------------

	void UpdateMenu();
	void UpdateGameScene(double deltaTime);

	// -------------------------------------------------------------------------
	// ------------------------- MAIN RENDER METHODS ---------------------------

	void RenderStartScreen() const;
	void RenderMenu() const;
	void RenderGameScene() const;

	// -------------------------------------------------------------------------
	// ------------------- INITIAL READING ALL DATA METHOD ---------------------

	void ReadGameDataFromFiles();

	// -------------------------------------------------------------------------
	// --------------------- MENUS HANDLE INPUT METHODS ------------------------

	void HandleInputMainMenu();
	void HandleInputTutorialsMenu();
	void HandleInputOptionsMenu();
	void HandleInputGraphicsMenu();
	void HandleInputGameModesMenu();
	void HandleInputGameOverMenu();
	void HandleInputBestScoresMenu();
	void HandleInputConfirmationMenu();
	void HandleInputCompanyLevelsMenu();
	void HandleInputWinLevelMenu();
	void HandleInputCompanyGameOverMenu();

	// -------------------------------------------------------------------------
	// ------------------------ MENUS UPDATE METHODS ---------------------------

	void UpdateMainMenu();
	void UpdateOptionsMenu();
	void UpdateGraphicsMenu();
	void UpdateGameModesMenu();
	void UpdateConfirmationMenu();
	void UpdateCompanyLevelsMenu();

	// -------------------------------------------------------------------------
	// ---------------------- UPDATE GAME SCENE METHODS -------------------------

	void UpdateGameSceneClassic(double deltaTime);
	void UpdateGameSceneCompany(double deltaTime);

	// -------------------------------------------------------------------------
	// ---------------------- MEMORY MANAGEMENT METHODS ------------------------

	void AllocateGameObjects();
	void DeallocateGameObjects();

	// -------------------------------------------------------------------------
	// ---------------------- SCORE MANAGEMENT METHODS -------------------------

	void SetScoresOnGameOverMenu();
	void CheckScoreBeating();
	void SetScoresOnBestScoresMenu();

	// -------------------------------------------------------------------------
	// --------------------------- APPLICATION DATA ----------------------------
	bool isRunning = true;

	// This field is mutable, because my 'Render...' methods are all const.
	// But after showing start screen game need to change this field
	// (switch to main menu). So method 'RenderStartScreen' changes this field.
	mutable GameWindow currentGameWindow = GameWindow::StartScreen;

	// -------------------------------------------------------------------------
	// ------------------------------- MENU DATA -------------------------------

	// - Current Menu Type - 
	MenuType currentMenu = MenuType::MainMenu;

	// - Company Logo -
	std::string companyLogoFilename = "res/logo/CompanyLogo.txt";
	std::string companyLogoContent;

	// - Game Logo -
	std::string gameLogoFilename = "res/logo/GameLogo.txt";
	std::string gameLogoContent;

	// - Main Menu -
	std::string mainMenuFilename = "res/menus/MainMenu.txt";
	std::string mainMenuContent;
	MainMenuItem mainMenuSelectedItem = MainMenuItem::StartGame;

	// - Options Menu -
	std::string optionsMenuFilename = "res/menus/OptionsMenu.txt";
	std::string optionsMenuContent;
	OptionsMenuItem optionsMenuSelectedItem = OptionsMenuItem::Graphics;

	// - Graphics Menu -
	std::string graphicsMenuFilename = "res/menus/GraphicsMenu.txt";
	std::string graphicsMenuContent;
	GraphicsMenuItem graphicsMenuSelectedItem = GraphicsMenuItem::BackToOptionsMenu;

	// - Game Modes Menu -
	std::string gameModesMenuFilename = "res/menus/GameModesMenu.txt";
	std::string gameModesMenuContent;
	GameModesMenuItem gameModesMenuSelectedItem = GameModesMenuItem::Classic;
	GameMode selectedGameMode = GameMode::None;

	// - Best Scores Menu -
	std::string bestScoresMenuFilename = "res/menus/BestScoresMenu.txt";
	std::string bestScoresMenuContent;

	// - Company Levels Menu -
	std::string companyLevelsMenuFilename = "res/menus/CompanyLevelsMenu.txt";
	std::string companyLevelsMenuContent;
	CompanyLevelsMenuItem companyLevelsMenuSelecetedItem = CompanyLevelsMenuItem::Level1;

	// - Win Level Menu -
	std::string winLevelMenuFilename = "res/menus/WinLevelMenu.txt";
	std::string winLevelMenuContent;

	// - Confirmation Menu -
	std::string confirmationMenuFilename = "res/menus/ConfirmationMenu.txt";
	std::string confirmationMenuContent;
	ConfirmationMenuItem confirmationMenuSelectedItem = ConfirmationMenuItem::No;
	OperationToConfirm operationToConfirm = OperationToConfirm::None;

	// - Classic Game Over Menu -
	std::string classicGameOverMenuFilename = "res/menus/ClassicGameOverMenu.txt";
	std::string classicGameOverMenuContent;

	// - Company Game Over Menu -
	std::string companyGameOverMenuFilename = "res/menus/CompanyGameOverMenu.txt";
	std::string companyGameOverMenuContent;

	// - Tutorials Pages -
	static const size_t TUTORIAL_PAGES_COUNT = 3;
	std::string tutorialPagesNames[TUTORIAL_PAGES_COUNT] =
	{
		"res/menus/TutorialPage1.txt",
		"res/menus/TutorialPage2.txt",
		"res/menus/TutorialPage3.txt"
	};
	std::string tutorialPagesContents[TUTORIAL_PAGES_COUNT];
	size_t currentTutorialPageIndex = 0;

	// -------------------------------------------------------------------------
	// ------------------------------- GAME DATA -------------------------------

	// - Scores -
	std::string bestScoresFilename = "res/data/BestScores.bin";
	static const size_t BEST_SCORES_COUNT = 5;
	Score bestScoresTable[BEST_SCORES_COUNT];
	Score playerScore;

	// - Company Progress -
	std::string companyProgressFilename = "res/data/CompanyProgress.bin";

	// - Color Scheme -
	std::string colorThemeFilename = "res/data/ColorTheme.bin";
	ColorTheme currentColorTheme;

	// - Levels -
	std::string classicLevelFilename = "res/levels/ClassicLevel.txt";
	static const size_t COMPANY_LEVELS_COUNT = 5;
	Level companyLevels[COMPANY_LEVELS_COUNT] =
	{
		Level{ "res/levels/CompanyLevel1.txt", "", true,  10 }, // first level is always open
		Level{ "res/levels/CompanyLevel2.txt", "", false, 10 },
		Level{ "res/levels/CompanyLevel3.txt", "", false, 10 },
		Level{ "res/levels/CompanyLevel4.txt", "", false, 10 },
		Level{ "res/levels/CompanyLevel5.txt", "", false, 10 }
	};
	size_t currentCompanyLevelIndex;

	// - Scene Objects -
	mutable std::unique_ptr<Field> field;
	std::unique_ptr<Walls> walls;
	std::unique_ptr<Apple> apple;
	std::unique_ptr<Snake> snake;
};