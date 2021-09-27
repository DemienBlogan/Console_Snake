#pragma once

template <typename T>
struct Vector2
{
	T x;
	T y;
};

template <typename T>
inline bool operator==(const Vector2<T>& left, const Vector2<T>& right)
{
	return left.x == right.x && left.y == right.y;
}