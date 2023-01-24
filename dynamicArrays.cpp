#include <iostream>
#include <cstring>
using namespace std;

//typedef int* IntPtr;

typedef struct ObjectArea_type
{
    int rowSize;
    int colSize;
} ObjectArea;

void Define2DArr(int **arr, ObjectArea area)
{
    for (int row = 0; row < area.rowSize; ++row)
    {
        arr[row] = new int[area.colSize];
    }
}

void Fill2DArr(int **arr, ObjectArea area)
{
    for (int row = 0; row < area.rowSize; ++row)
    {
        for (int col = 0; col < area.colSize; ++col)
        {
            arr[row][col] = (row + 1) * col;
        }
    }
}

void Print2DArr(int **arr, ObjectArea area)
{
    for (int row = 0; row < area.rowSize; ++row)
    {
        for (int col = 0; col < area.colSize; ++col)
        {
            cout << arr[row][col] << " ";
        }
        cout << endl;
    }
}

int main(void)
{
    ObjectArea objectArea = {5, 10};
    int **array2D = new int* [objectArea.rowSize]; //define first dimension of 2D pointer array

    Define2DArr(array2D, objectArea); //define second dimension of 2D pointer array
    Fill2DArr(array2D, objectArea); //assign 2D pointer array elements
    Print2DArr(array2D, objectArea); //print 2D pointer array elements



    /**fill and print single dimensional dynamic array**
    int *array1D;
    array1D = new int[5];
    for (int i = 0; i < 5; ++i)
    {
        array1D[i] = i;
    }

    for (int i = 0; i < 5; ++i)
    {
        cout << array1D[i] << " ";
    }**/



    return 0;
}
