#include<iostream>
using namespace std;

void moveDown(int& i, int& j, int& rows, int& numb, int** arr)
{
	for (; i < rows - 1; )
	{
		if (i == 0 && j == 0)
		{
			numb -= 1;
			break;
		}
		i += 1;
		j -= 1;
		arr[i][j] = numb;
		numb++;
		if (j == 0)
		{
			break;
		}
	}
}
void moveUp(int& i, int& j, int& cols, int& numb, int** arr)
{
	for (; j < cols - 1;)
	{
		if (i == 0 && j == 0)
		{
			numb -= 1;
			break;
		}
		j += 1;
		i -= 1;
		arr[i][j] = numb;
		numb++;
		if (i == 0)
		{
			if (j == 1)
			{
				j -= 1;
				arr[i][j] = numb;
			}
			break;
		}
	}
}
int main()
{
	int rows;
	int cols;
	int numb = 1;

	cout << "Enter rows length: ";
	cin >> rows;
	cout << "Enter columns length: ";
	cin >> cols;

	int** arr = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new int[cols];
	}
	int i = rows - 1, j = cols - 1;
	arr[i][j] = numb;
	numb++;

	//second picture
	
	do
	{
		if (i == 0 && j == 0)
		{
			arr[i][j] = numb;
			break;
		}
		if (i > 0)
		{
			i -= 1;
			arr[i][j] = numb;
			numb++;
		}
		else
		{
			j -= 1;
			arr[i][j] = numb;
			numb++;
		}
		moveDown(i, j, rows, numb, arr);
		if (j > 0)
		{
			j -= 1;
			arr[i][j] = numb;
			numb++;
		}
		else
		{
			i -= 1;
			arr[i][j] = numb;
			numb++;
		}
		moveUp(i, j, cols, numb, arr);
		if (i == 0 && j == 0)
		{
			arr[i][j] = numb;
			break;
		}
	} while (numb != (rows * cols) );

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			printf("%2i ", arr[i][j]);
		}
		printf("\r\n");
	}
	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
		arr[i] = nullptr;
	}
	delete[] arr;
	arr = nullptr;
	return 0;
}