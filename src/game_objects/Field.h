#pragma once
#include <memory>
#include "../tools/Vector2.h"
#include "../tools/WindowSettings.h"

class Walls;
class Apple;
class Snake;

class Field
{
public:
	Field(const Vector2<size_t>& size = Vector2<size_t>{ WINDOW_WIDTH, WINDOW_HEIGHT });
	~Field();

	void Render() const;
	size_t GetRows() const;
	size_t GetColumns() const;

	void Set(const std::unique_ptr<Walls>& walls);
	void Set(const std::unique_ptr<Apple>& apple);
	void Set(const std::unique_ptr<Snake>& snake);

	void Clear();

	Vector2<unsigned> GetRandomEmptyPoint() const;

private:
	void AllocateField();
	void DeallocateField();

	char** field;
	Vector2<size_t> size; // rows & columns
};