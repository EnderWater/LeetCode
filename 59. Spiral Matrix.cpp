#include <iostream>
#include <vector>

void fillVector(std::vector<std::vector<int>>& vec, int lowerBound, int upperBound, int &nextNumber)
{
    int row = lowerBound, column = lowerBound;
    // Right horizontal
    while (column < upperBound)
    {
        if (vec[row][column] == -1)
        {
            vec[row][column] = nextNumber;
            nextNumber++;
        }
        column++;
    }
    column--;
    // Down vertical
    while (row < upperBound)
    {
        if (vec[row][column] == -1)
        {
            vec[row][column] = nextNumber;
            nextNumber++;
        }
        row++;
    }
    row--;
    // Left horizontal
    while (column >= lowerBound)
    {
        if (vec[row][column] == -1)
        {
            vec[row][column] = nextNumber;
            nextNumber++;
        }
        column--;
    }
    column++;
    // Up vertical
    while (row >= lowerBound)
    {
        if (vec[row][column] == -1)
        {
            vec[row][column] = nextNumber;
            nextNumber++;
        }
        row--;
    }
    row++;
}


int main()
{
    // std::vector<std::vector<int>> x = {{1,2,3},{8,9,4},{7,6,5}};
    int n = 10;
    int nextNumber = 1;
    // A 2d vector filled with -1's so I can check what has been visited already
    std::vector<std::vector<int>> vec(n, std::vector<int>(n, -1));
    for (int i=0; i<n; i=i+1, n=n-1)
    {
        fillVector(vec, i, n, nextNumber);
    }
}