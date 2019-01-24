#include<stdio.h> 
#include<locale.h> 
#include<iostream> 

void task1()
{
	/*1.	Дано целое число в двоичной системе счисления, т.е. последовательность цифр  0 и 1. 
	Составить программу перевода этого числа в восьмеричную систему счисления.*/
	int i, A[6] = { 0 }, B[6] = { 0 }, C[6] = { 0 };

	int power = -1;
	printf("Binary numer: ");
	for (i = 0; i < 6; i++)
	{
		power++;
		A[i] = 0 + rand() % 2;
		printf("%d", A[i]);
	}

	int sum = 0;
	printf("\nDecimal number: ");
	for (i = 0; i < 6; i++)
	{
		B[i] = A[i] * pow(2, power);
		sum += B[i];
		power--;
	}
	printf("%d", sum);

	power = 0;
	int ost = 0, num = sum, oct = 0;
	printf("\nOctal number: ");
	do
	{
		ost = num % 8;
		num /= 8;
		oct += ost * pow(10, power);
		power++;
	} while (num >= 8);
	
	oct += num * pow(10, power);
	printf("%d\n", oct);
	system("pause");
}


void task2()

{
	int i, A[7] = { 0 }, B[9] = { 0 }, C[16] = { 0 };

	printf("First array: \n");
	for (i = 0; i < 7; i++)
	{
		A[i] = 10 + rand() % 90;
		printf("A[%d] = %d\n", i, A[i]);
	}

	printf("\nSecond array: \n");
	for (i = 0; i < 9; i++)
	{
		B[i] = 10 + rand() % 90;
		printf("B[%d] = %d\n", i, B[i]);
	}
	
	printf("\nNew array: \n");
	for (i = 0; i < 7; i++)
	{
		C[i] = A[i];
	}

	int j = 0;
	for (i = 7; i < 16; i++)
	{
		C[i] = B[j];
		j++;
	}

	int c = 0;
	for (i = 0; i < 15; i++)
	{
		for (j = 14; j >= i; j--)
		{
			if (C[j] < C[j + 1])
			{
				c = C[j];
				C[j] = C[j + 1];
				C[j + 1] = c;
			}
		}
	}

	for (i = 0; i < 16; i++)
	{
		printf("C[%d] = %d\n", i, C[i]);
	}
	system("pause");
}

void task3()
{

	int A[10] = { 0 }, i;
	int j = 0, sim = 0, ind1, ind2;

	printf("Given array:\n");
	do
	{
		for (i = 0; i < 10; i++)
		{
			A[i] = 0 + rand() % 20;
		}


		for (i = 0; i < 10; i++)
		{
			for (j = 9; j >= i; j--)
			{
				if (i != j)
				{
					if ((A[j] == A[i]) && (sim > 0))
					{
						do
						{
							A[j] = 0 + rand() % 20;
						} while (A[j] == A[i]);
					}

					if ((A[j] == A[i]) && (sim == 0))
					{
						sim++;
						ind1 = i;
						ind2 = j;
					}
				}
			}
		}
	} while (sim == 0);
	
	for (i = 0; i < 10; i++)
	{
		printf("A[%d] = %d\n", i, A[i]);
	}

	printf("Similar numbers are A[%d] and A[%d]\n", ind1, ind2);
	system("pause");
}



void task4()
{
	int A[10] = { 0 }, i;

	for (i = 0; i < 10; i++)
	{
		A[i] = 0 + rand() % 20;
		printf("A[%d] = %d\n", i, A[i]);
	}

	int q, count = 0;
	for (i = 1; i < 9; i++)
	{
		if ((A[i] / A[i + 1]) == (A[i - 1] / A[i + 1]))
		{
			count++;
		}
	}
	if (count == 8)
	{
		q = A[4] / A[3];
		printf("It is a geometric progression\nThe denominator is %d\n", q);
	}
	

	else
		printf("It is not a geometric progression\n");

	system("pause");
}


void task5()
{
	int A[5][4] = { { 0 },{ 0 } }, i, j, count = 0;

	printf("Given array:\n");
	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 4; j++)
		{
			A[i][j] = 0 + rand() % 20;
			printf("A[%d][%d] = %d\n", i, j, A[i][j]);
		}
		printf("\n");
	}

	int c = 0;
	printf("\nSorted array:\n");
	for (i = 0; i < 4; i++)
	{
		for (j = 3; j >= i; j--)
		{
			if (A[j][3] < A[j + 1][3])
			{
				c = A[j][3];
				A[j][3] = A[j + 1][3];
				A[j + 1][3] = c;
			}
		}
	}
	
	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 4; j++)
		{
			printf("A[%d][%d] = %d\n", i, j, A[i][j]);
		}
		printf("\n");
	}
	system("pause");
}

void task6()
{
	/*6.	В матрице А(3-строки,4-столбца) поменять местами наименьшие элементы в первой и третей строке.*/
	int A[3][4] = { { 0 },{ 0 } }, i, j, count = 0;

	printf("Given array:\n");
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 4; j++)
		{
			A[i][j] = 0 + rand() % 20;
			printf("A[%d][%d] = %d\n", i, j, A[i][j]);
		}
		printf("\n");
	}

	int min1 = 40, min2 = 40, ind1, ind2;
	
	for (i = 0; i < 4; i++)
	{
		if (A[0][i] < min1)
		{
			min1 = A[0][i];
			ind1 = i;
		}
		if (A[2][i] < min2)
		{
			min2 = A[2][i];
			ind2 = i;
		}
	}

	printf("Min number in the first row is %d\n", min1);
	printf("Min number in the third row is %d\n", min2);
	A[0][ind1] = min2;
	A[2][ind2] = min1;

	printf("\nSorted array:\n");
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 4; j++)
		{
			printf("A[%d][%d] = %d\n", i, j, A[i][j]);
		}
		printf("\n");
	}

	system("pause");
}

void task7()
{
	int A[5][6] = { { 0 },{ 0 } }, i, j;

	printf("Given array:\n");
	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 6; j++)
		{
			A[i][j] = 0 + rand() % 20;
			printf("A[%d][%d] = %d\n", i, j, A[i][j]);
		}
		printf("\n");
	}

	int sum = 0, min = 50, max = 0;
	float av = 0;

	for (i = 0; i < 5; i++)
	{
		max = 0;
		min = 50;
		for (j = 0; j < 6; j++)
		{
			if (A[i][j] > max)
				max = A[i][j];
		
			if (A[i][j] < min)
				min = A[i][j];
		}
		printf("Max number in the row %d is %d\n", i, max);
		printf("Min number in the row %d is %d\n\n", i, min);
	}

	for (i = 0; i < 6; i++)
	{
		sum = 0;
		for (j = 0; j < 5; j++)
		{
			sum += A[j][i];
		}
		av = float(sum) / float(5);
		printf("Sum in the cololumn %d is %d\n", i, sum);
		printf("Average in the coloumn %d is %.1f\n\n", i, av);
	}
	system("pause");
}

void task8()
{
	int A[5][6] = { { 0 },{ 0 } }, i, j;

	printf("Given array:\n");
	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 6; j++)
		{
			A[i][j] = 0 + rand() % 20;
			printf("A[%d][%d] = %d\n", i, j, A[i][j]);
		}
		printf("\n");
	}
		
	int countOdd = 0, countEven = 0;
	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 6; j++)
		{
			if (A[i][j] % 2 == 0)
				countEven++;

			else
				countOdd++;
		}
	}

	printf("There are %d even elements in the array\n", countEven);
	printf("There are %d odd elements in the array\n", countOdd);
	system("pause");
}


void task9()
{
	int A[5][6] = { { 0 },{ 0 } }, i, j;

	printf("Given array:\n");
	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 6; j++)
		{
			A[i][j] = 0 + rand() % 20;
			printf("A[%d][%d] = %d\n", i, j, A[i][j]);
		}
		printf("\n");
	}

	int count = 0;
	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 6; j++)
		{
			if (A[i][j] == 7)
				count++;
		}
	}
	if (count > 0)
		printf("Number 7 is found in the array %d times\n", count);

	else
		printf("There is no number 7 in array\n");
	system("pause");
}

void task10()
{
	int A[5][6] = { { 0 },{ 0 } }, i, j, min = 50;

	printf("Given array:\n");
	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 6; j++)
		{
			A[i][j] = 0 + rand() % 7;
			printf("A[%d][%d] = %d\n", i, j, A[i][j]);
		}
		printf("\n");
	}

	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 6; j++)
		{
			if (A[i][j] < min)
				min = A[i][j];
		}
	}
	
	int R, C, found = 0;
	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 6; j++)
		{
			if (A[i][j] == min)
			{
				R = i;
				C = j;
				found++;
				break;
			}
		}
		if (found > 0)
			break;
	}

	printf("The first min number is A[%d][%d] = %d\n", R, C, min);
	system("pause");
}


int main()

{
	setlocale(LC_ALL, "");

	int task, flag;

start:

	printf("Введите номер задания: ");
	scanf_s("%d", &task);

	switch (task)
	{
	case 1:
	{
		task1();

		break;
	}
	case 2:
	{
		task2();

		break;
	}
	case 3:
	{
		task3();

		break;
	}
	case 4:
	{
		task4();
	}
	case 5:
	{
		task5();

		break;
	}
	case 6:
	{
		task6();

		break;
	}
	case 7:
	{
		task7();

		break;
	}
	case 8:
	{
		task8();

		break;
	}
	case 9:
	{
		task9();

		break;
	}
	case 10:
	{
		task10();

		break;
	}
	}

	printf("Хотите продолжить 1 или 0?\n");
	scanf_s("%d", &flag);
	if (flag == 1)
	{
		goto start;
	}
	system("pause");
}