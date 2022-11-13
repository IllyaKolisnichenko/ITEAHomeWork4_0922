#include <iostream>

int main()
{
    int rows{};
    int columns{};
    int row{}, col{}, diag{};

    std::cout << "Enter count of rows:";
    std::cin >> rows;
    std::cout << "Enter count of columns:";
    std::cin >> columns;

    if( rows <= 0 || columns <= 0 )
    {
        std::cout << "Incorrect size of array!";
        return 1;
    }

    int matrix[rows][columns];
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < columns; j++)
        {
            matrix[i][j] = 1;
        }
    }

    for (int i = 1; i < rows * columns; i++)
    {
        col--;
        row++;
        if (col < 0 or row == rows)
        {
            diag++;
            if (diag < columns)
                col = diag;
            else
                col = columns - 1;

            row = diag - col;
        }
        matrix[row][col] += i;
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            std::cout << " " << matrix[i][j];
        }
        std::cout << std::endl;
    }

    return 0;
}
