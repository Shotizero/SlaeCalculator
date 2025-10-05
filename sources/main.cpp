#include <stdio.h>

int FindSlaeResult()
{
	char firstEquation[256], secondEquation[256], thirdEquation[256];

	printf("Enter first equation:\n");
	scanf("%s", firstEquation);

	printf("Enter second equation:\n");
	scanf("%s", secondEquation);

	printf("Enter third equation:\n");
	scanf("%s", thirdEquation);

	printf("\nThe system of equations:\n%s\n%s\n%s\n\n", firstEquation, secondEquation, thirdEquation);

	return 0;
}

int main()
{
	while (true)
	{
		FindSlaeResult();
	}

	return 0;
}
 
