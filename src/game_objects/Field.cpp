#include "Field.h"

#include <iostream>
#include "../tools/Tools.h"
#include "GameObjects.h"

Field::Field(const Vector2<size_t>& size)
	: size(size), field(nullptr)
{
	AllocateField();
	Clear();
}

Field::~Field()
{
	DeallocateField();
}

void Field::Render() const
{
	Tools::ResetCursorPosition();

	size_t rows = size.y, columns = size.x;
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < columns; j++)
		{
			std::cout << field[i][j];
		}
		std::cout << '\n';
	}
}

size_t Field::GetRows() const
{
	return size.y;
}

size_t Field::GetColumns() const
{
	return size.x;
}

void Field::Set(const std::unique_ptr<Walls>& walls)
{
	const std::vector<Vector2<unsigned>>& wallPositions = walls->GetWallPositions();

	size_t wallSize = wallPositions.size();
	for (size_t i = 0; i < wallSize; i++)
	{
		field[wallPositions[i].y][wallPositions[i].x] = '*';
	}
}

void Field::Set(const std::unique_ptr<Apple>& apple)
{
	const Vector2<unsigned>& applePosition = apple->GetPosition();
	field[applePosition.y][applePosition.x] = 'A';
}

void Field::Set(const std::unique_ptr<Snake>& snake)
{
	const std::vector<Vector2<unsigned>>& snakeBodyParts = snake->GetBodyParts();
	size_t snakeBodyPartsSize = snakeBodyParts.size();

	if (snakeBodyPartsSize == 0)
	{
		return;
	}

	// Set head:
	const Vector2<unsigned>& headPosition = snakeBodyParts[0];
	field[headPosition.y][headPosition.x] = 'O';

	// Set other parts:
	for (size_t i = 1; i < snakeBodyPartsSize; i++)
	{
		const Vector2<unsigned>& partPosition = snakeBodyParts[i];
		field[partPosition.y][partPosition.x] = 'o';
	}
}

void Field::Clear()
{
	size_t rows = size.y, columns = size.x;
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < columns; j++)
		{
			field[i][j] = ' ';
		}
	}
}

Vector2<unsigned> Field::GetRandomEmptyPoint() const
{
	Vector2<unsigned> randomPosition;
	size_t rows = size.y, columns = size.x;

	do
	{
		// 0 and (columns - 1)/(rows - 1) are walls.
		// So the range of search is between this range.
		randomPosition.x = std::rand() % (columns - 2) + 1;
		randomPosition.y = std::rand() % (rows - 2) + 1;

	} while (field[randomPosition.y][randomPosition.x] != ' ');

	return randomPosition;
}

void Field::AllocateField()
{
	size_t rows = size.y, columns = size.x;

	field = new char* [rows];
	for (size_t i = 0; i < rows; i++)
	{
		field[i] = new char[columns];
	}
}

void Field::DeallocateField()
{
	size_t rows = size.y;
	for (size_t i = 0; i < rows; i++)
	{
		delete[] field[i];
	}

	delete[] field;
	field = nullptr;
}