#pragma once
#include <vector>
#include <memory>
#include "../tools/Vector2.h"
#include "../game/GameEnumerations.h"

class Apple;
class Walls;

class Snake
{
public:
	Snake(const Vector2<unsigned>& initialPosition);

	bool IsAlive() const;
	bool DoTouch(const std::unique_ptr<Apple>& apple) const;
	bool DoTouch(const std::unique_ptr<Walls>& walls) const;
	bool DoTouchItself() const;
	void Move(double deltaTime, bool isClassicMode);
	const std::vector<Vector2<unsigned>>& GetBodyParts() const;
	void SetHeadDirection(const Direction& direction);
	void Kill();
	void Increase();
	bool CanChangeDirection() const;

private:
	bool DoNeedToMove(double deltaTime);

	std::vector<Vector2<unsigned>> bodyParts;
	bool isAlive = true;
	Direction headDirection = Direction::None;
	int speed = 8; // cells per second
	double passedDistance = 0;
	int cellsToPass = 1;
	bool canChangeDirection = true;
};