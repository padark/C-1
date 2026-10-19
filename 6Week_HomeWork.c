#include <stdio.h>
int returnMaxValue(int num1, int num2, int num3);
int returnMinValue(int num1, int num2, int num3);

int main()
{

	int value1 = 0;
	int value2 = 0;
	int value3 = 0;

	int result_MaxValue = 0;
	int result_MinValue = 0;

	scanf_s("%d %d %d", &value1, &value2, &value3);

	result_MaxValue = returnMaxValue(value1, value2, value3);

	result_MinValue = returnMinValue(value1, value2, value3);

	printf("%d %d %d (max = %d) (min = %d)\n", value1, value2, value3, result_MaxValue, result_MinValue);

	return 0;
}

int returnMaxValue(int num1, int num2, int num3)
{
	int MaxValue = num1;
	if (num2 > MaxValue)
		MaxValue = num2;
	if (num3 > MaxValue)
		MaxValue = num3;
	return MaxValue;
}

int returnMinValue(int num1, int num2, int num3)
{
	int MinValue = num1;
	if (num2 < MinValue)
		MinValue = num2;
	if (num3 < MinValue)
		MinValue = num3;
	return MinValue;
}