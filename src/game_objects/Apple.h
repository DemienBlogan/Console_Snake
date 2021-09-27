#pragma once
#include "../tools/Vector2.h"

class Apple
{
public:
	Apple(const Vector2<unsigned>& initialPosition);

	Vector2<unsigned> GetPosition() const;
	void SetPosition(const Vector2<unsigned>& newPosition);

private:
	Vector2<unsigned> position;
};