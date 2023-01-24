#include <iostream>
//#include <windows.h>
using namespace std;

typedef int *Pointer;
//typedef CHAR_INFO *CharInfoPtr;

int main()
{
    int rowSize(3);
    int colSize(10);
    Pointer *p;

    //declare rows pointer array
    p = new Pointer[rowSize]; //declare pointer array with 3 elements

    //declare columns pointer array
    for (int i = 0; i < rowSize; ++i)
    {
        p[i] = new int[colSize];
    }

    //fill 2-D array
    for (int r = 0; r < rowSize; ++r)
    {
        for (int c = 0; c < colSize; ++c)
        {
            p[r][c] = (r + 1) * c;
        }
    }

    //print 2-D array
    for (int r = 0; r < rowSize; ++r)
    {
        for (int c = 0; c < colSize; ++c)
        {
            cout << p[r][c] << " ";
        }
        cout << endl;
    }

    return 0;
}

/**
int main()
{
    CharInfoPtr *walkLeftArr;

    walkLeftArr = new CharInfoPtr[3];
    for (int i = 0; i < numFrames; ++i)
    {
        walkLeftArr[i] = new CHAR_INFO[walkLeftFrameSize];
    }

    return 0
}**/
