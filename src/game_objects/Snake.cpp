#include "Snake.h"

#include <memory>
#include "Apple.h"
#include "Walls.h"
#include "../tools/WindowSettings.h"

Snake::Snake(const Vector2<unsigned>& initialPosition)
{
	bodyParts.push_back(initialPosition);
}

bool Snake::IsAlive() const
{
	return isAlive;
}

bool Snake::DoTouch(const std::unique_ptr<Apple>& apple) const
{
	const Vector2<unsigned>& headPosition = bodyParts[0];
	const Vector2<unsigned>& applePosition = apple->GetPosition();

	return headPosition == applePosition;
}

bool Snake::DoTouch(const std::unique_ptr<Walls>& walls) const
{
	const Vector2<unsigned>& headPosition = bodyParts[0];

	const std::vector<Vector2<unsigned>>& wallPositions = walls->GetWallPositions();
	size_t wallSize = wallPositions.size();

	for (size_t i = 0; i < wallSize; i++)
	{
		if (headPosition == wallPositions[i])
		{
			return true;
		}
	}

	return false;
}

bool Snake::DoTouchItself() const
{
	size_t partCount = bodyParts.size();

	// Snake can't touch itself, if its length <= 4.
	if (partCount <= 4)
	{
		return false;
	}

	const Vector2<unsigned>& headPosition = bodyParts[0];
	for (size_t i = 4; i < partCount; i++)
	{
		if (headPosition == bodyParts[i])
		{
			return true;
		}
	}

	return false;
}

void Snake::Move(double deltaTime, bool isClassicMode)
{
	if (headDirection == Direction::None || !DoNeedToMove(deltaTime))
	{
		return;
	}

	// Move other part toward the head.
	size_t partsCount = bodyParts.size();
	for (int i = partsCount - 1; i >= 1; i--)
	{
		bodyParts[i] = bodyParts[i - 1];
	}

	// Move head onto new position.
	Vector2<unsigned>& head = bodyParts[0];

	switch (headDirection)
	{
	case Direction::Up:
		head.y--;
		break;
	case Direction::Right:
		head.x++;
		break;
	case Direction::Left:
		head.x--;
		break;
	case Direction::Down:
		head.y++;
		break;
	}

	if (isClassicMode)
	{
		// If snake's head touches walls, set it on the opposite side.

		if (head.x == 0)
		{
			head.x = WINDOW_WIDTH - 2;
		}
		else if (head.x == WINDOW_WIDTH - 1)
		{
			head.x = 1;
		}
		else if (head.y == 0)
		{
			head.y = WINDOW_HEIGHT - 2;
		}
		else if (head.y == WINDOW_HEIGHT - 1)
		{
			head.y = 1;
		}
	}
}

const std::vector<Vector2<unsigned>>& Snake::GetBodyParts() const
{
	return bodyParts;
}

void Snake::SetHeadDirection(const Direction& direction)
{
	// Snake can't move to back of its direction. So we need to check
	// if user wants to go to this direction.
	if ((headDirection == Direction::Up && direction == Direction::Down) ||
		(headDirection == Direction::Right && direction == Direction::Left) ||
		(headDirection == Direction::Down && direction == Direction::Up) ||
		(headDirection == Direction::Left && direction == Direction::Right) ||
		direction == Direction::None)
	{
		return;
	}

	headDirection = direction;
	canChangeDirection = false;
}

void Snake::Kill()
{
	isAlive = false;
}

void Snake::Increase()
{
	bodyParts.push_back(bodyParts[bodyParts.size() - 1]);
}

bool Snake::CanChangeDirection() const
{
	return canChangeDirection;
}

bool Snake::DoNeedToMove(double deltaTime)
{
	passedDistance += speed * deltaTime;

	if (passedDistance >= cellsToPass)
	{
		cellsToPass++;
		canChangeDirection = true;
		return true;
	}

	return false;
}