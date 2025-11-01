#include <iostream>
#include <string>
#include <string.h>

const int ERROR = 0xFFFF;

struct Equation
{
	int x;
	int y;
	int z;
	int Result;;
};

void InputEquation(std::string& buffer)
{
	std::getline(std::cin, buffer);
}

int ParseCoefficient(const std::string& coefficient)
{
	if (coefficient.empty())
	{
		printf("Error: empty coefficient");
		return ERROR;
	}

	if (coefficient == "+")
	{
		return 1;
	}

	if (coefficient == "-")
	{
		return -1;
	}

	return atoi(coefficient.c_str());
}

Equation ParseEquation(std::string& equationStr)
{
	Equation eq{};

	if (equationStr.empty())
	{
		printf("Error: invalid equation!");
		return eq;
	}

	std::string valueX = strtok(&equationStr[0], "Xx");
	eq.x = ParseCoefficient(valueX);

	std::string valueY = strtok(NULL, "Yy");
	eq.y = ParseCoefficient(valueY);

	std::string valueZ = strtok(NULL, "Zz");
	eq.z = ParseCoefficient(valueZ);

	std::string result = strtok(NULL, "=");
	eq.Result = ParseCoefficient(result);

	return eq;
}

int main()
{
	Equation equations[3]{};

	for(int i=0; i < 3; ++i)
	{
		std::string source;

		InputEquation(source);
		equations[i] = ParseEquation(source);
	}

	return 0;
}
 
