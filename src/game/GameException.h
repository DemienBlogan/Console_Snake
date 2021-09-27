#pragma once
#include <string>

class GameException
{
public:
	GameException(
		const std::string& errorMessage = "Error",
		const std::string& functionName = "", 
		int lineNumber = 0
	);

	const std::string& GetErrorMessage() const;
	const std::string& GetFunctionName() const;
	int GetLineNumber() const;

private:
	std::string errorMessage;
	std::string functionName;
	int lineNumber;
};