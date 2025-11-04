#include <iostream>
#include <string>
#include <string.h>

const int ERROR = 0xFFFF;

struct Equation
{
	int X;
	int Y;
	int Z;
	int Result;
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
	eq.X = ParseCoefficient(valueX);

	std::string valueY = strtok(NULL, "Yy");
	eq.Y = ParseCoefficient(valueY);

	std::string valueZ = strtok(NULL, "Zz");
	eq.Z = ParseCoefficient(valueZ);

	std::string result = strtok(NULL, "=");
	eq.Result = ParseCoefficient(result);

	return eq;
}

void SolveEquations()
{

	Equation equations[3]{};

	for (int i = 0; i < 3; ++i)
	{
		std::string source;

		std::string request[3]
		{ 
			{ "Enter first equation" },
			{ "\nEnter second equation" },
			{ "\nEnter third equation" } 
		};

		std::cout<<request[i]<<"\n";

		InputEquation(source);
		equations[i] = ParseEquation(source);
	}

	int dX = (equations[0].Result * equations[1].Y * equations[2].Z) 
		+ 
		(equations[0].Y * equations[1].Z * equations[2].Result)
		+ 
		(equations[0].Z * equations[1].Result * equations[2].Y)
		-
		(equations[0].Z * equations[1].Y * equations[2].Result)
		-
		(equations[0].Result * equations[1].Z * equations[2].Y)
		- 
		(equations[0].Y * equations[1].Result * equations[2].Z);


	int dY = (equations[1].Result * equations[0].X * equations[2].Z)
		+ 
		(equations[2].X * equations[1].Z * equations[0].Result)
		+ 
		(equations[0].Z * equations[2].Result * equations[1].X)
		- 
		(equations[0].Z * equations[2].X * equations[1].Result)
		- 
		(equations[2].Result * equations[0].X * equations[1].Z)
		- 
		(equations[1].X * equations[0].Result * equations[2].Z);


	int dZ = (equations[2].Result * equations[0].X * equations[1].Y)
		+ 
		(equations[0].Y * equations[2].X * equations[1].Result)
		+ 
		(equations[1].X * equations[0].Result * equations[2].Y)
		- 
		(equations[1].Y * equations[2].X * equations[0].Result)
		-
		(equations[1].Result * equations[0].X * equations[2].Y)
		-
		(equations[0].Y * equations[2].Result * equations[1].X);


	int D = (equations[0].X * equations[1].Y * equations[2].Z)
		+
		(equations[0].Y * equations[1].Z * equations[2].X)
		+
		(equations[0].Z * equations[1].X * equations[2].Y)
		-
		(equations[0].Z * equations[1].Y * equations[2].X)
		-
		(equations[0].Y * equations[1].X * equations[2].Z)
		-
		(equations[0].X * equations[1].Z * equations[2].Y);

	int x = dX / D;
	int y = dY / D;
	int z = dZ / D;

	printf("\nSolving a system of equations:\nX = %d\nY = %d\nZ = %d\n\n", x, y, z);

}

int main()
{
	while (true)
	{
		SolveEquations();
	}
	return 0;
}
 
