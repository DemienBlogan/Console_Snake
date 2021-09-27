#pragma once
#include <vector>
#include <string>
#include "../tools/Vector2.h"

class Walls
{
public:
	bool ReadFromFile(const std::string& filename);
	const std::vector<Vector2<unsigned>>& GetWallPositions() const;

private:
	std::vector<Vector2<unsigned>> wallPositions;
};