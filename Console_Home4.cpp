#include <iostream>
#include <vector>

class Matrix
{
private:
    int * array;
    int size;
public:
    Matrix(int row, int col){
        size = row; 
        array = new int[row * col];
    }

    ~Matrix(){
        delete[] array;
        array = nullptr;
    }

    int& at(int row, int col){
        return array[row * size + col]; 
    }
};

int main()
{
    std::cout << "Enter 2d array size(row,col). Possible values: 1..5" << std::endl;
    int rows{}, cols{};
    std::cin >> rows;
    std::cin >> cols;

    if (cols > 5 || cols <= 0) return 1;
    if (rows > 5 || rows <= 0) return 1;

    Matrix arr2d( rows, cols);

    //figure 19
    std::vector<std::pair<int, bool>> rules;
    rules.push_back(std::make_pair(21, true));
    rules.push_back(std::make_pair(20, false));
    rules.push_back(std::make_pair(11, true));
    rules.push_back(std::make_pair(10, false));
    rules.push_back(std::make_pair(1, true));

    for (int i = 0; i < cols; i++)
    {
        int k = rules[i].first;
        for (int j = 0; j < rows; j++)
        {
            arr2d.at(i,j) = k;
            if (!rules[i].second) k--;
            else k++;  
        }
    }


    for (int i = 0; i < cols; i++)
    {
        for (int j = 0; j < rows; j++)
        {
            std::cout << "array[" << i << "][" << j << "]:" << arr2d.at(i,j) << std::endl;
        }
        std::cout << ("\r\n");
    } 
}







