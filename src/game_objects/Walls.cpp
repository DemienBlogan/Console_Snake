#include <iostream>
#include <algorithm>
#include "Walls.h"
#include "../tools/Tools.h"
#include "../tools/FileManager.h"

bool Walls::ReadFromFile(const std::string& filename)
{
	std::string content;

	if (!FileManager::ReadTextFromFile(filename, content))
	{
		return false;
	}

	size_t contentSize = content.size();
	int columnIndex = 0;
	int rowIndex = 0;

	for (size_t i = 0; i < contentSize; i++)
	{
		if (content[i] == '\n')
		{
			rowIndex++;
			columnIndex = -1;
		}
		else if (content[i] == '*')
		{
			Vector2<unsigned> position = 
			{ 
				static_cast<unsigned>(columnIndex), 
				static_cast<unsigned>(rowIndex)
			};

			wallPositions.push_back(position);
		}

		columnIndex++;
	}

	return true;
}

const std::vector<Vector2<unsigned>>& Walls::GetWallPositions() const
{
	return wallPositions;
}