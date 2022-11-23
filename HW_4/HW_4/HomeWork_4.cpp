#include <iostream>
using namespace std;

int main() {
    int rows;
    int cols;
    int i, j;
    int k = 1;
    int odds = 0;

    cout << "Enter rows" << endl;
    cin >> rows;
    cout << "Enter cols" << endl;
    cin >> cols;

    int** arr = new int* [cols]; 
    for (int i = 0; i < cols; i++)
    {
        arr[i] = new int[rows];
    }

    for (i = cols - 1; i >= 0; i--)
    {
        if (cols % 2 == 0) {
            odds = 1;
        }
        else {
            odds = 0;
        }

        if (i % 2 == odds) {
            for (j = 0; j < rows; j++)
            {
                arr[i][j] = k;
                k++;
            }
        }
        else {
            for (j = rows - 1; j >= 0; j--)
            {
                arr[i][j] = k;
                k++;
            }
        }
    }

    for (i = 0; i < cols; i++)
    {
        for (j = 0; j < rows; j++)
        {
            printf("%2i ", arr[i][j]);
        }
        printf("\r\n");
    }

    for (int i = 0; i < rows; i++) {
        delete[] arr[i];
    }
    delete[] arr;
}