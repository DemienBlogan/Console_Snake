#include "Apple.h"

Apple::Apple(const Vector2<unsigned>& initialPosition)
	: position(initialPosition)
{ }

Vector2<unsigned> Apple::GetPosition() const
{
	return position;
}

void Apple::SetPosition(const Vector2<unsigned>& newPosition)
{
	position = newPosition;
}