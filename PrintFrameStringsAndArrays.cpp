#include <iostream>
using namespace std;

void PrintStringsAndArrays(int startFrames, int endFrames, string stringName, string fillName, string objectVar, string fillCharArray)
{
    for (int i = startFrames; i < endFrames + 1; ++i)
    {
        cout << "string " << stringName << i << ";" << endl;
    }
    for (int i = startFrames; i < endFrames + 1; ++i)
    {
        cout << "CHAR_INFO " << stringName << i << "Arr[" << objectVar << ".length];" << endl;
    }

    cout << endl;

    for (int i = startFrames; i < endFrames + 1; ++i)
    {
        cout << fillName << i << "(" << stringName << i << ");" << endl;
    }
    for (int i = startFrames; i < endFrames + 1; ++i)
    {
        cout << fillCharArray << "(" << stringName << i << ", "
             << stringName << i << "Arr, "
             << objectVar << ");" << endl;
    }

    cout << endl;

    for (int i = startFrames; i < endFrames + 1; ++i)
    {
        cout << "CHAR_INFO " << stringName << i << "Arr[], ";
    }

    cout << endl << endl;

    for (int i = startFrames; i < endFrames + 1; ++i)
    {
        cout << stringName << i << "Arr, ";
    }

    cout << endl;
}

int main()
{
    int startFrames = 0;
    int endFrames = 9;
    string stringName = "fireWorks";
    string fillName = "FillFireWorks";
    string objectVar = "fireWorksVar";
    string fillCharArray = "FillFireWorksCharArray";

    PrintStringsAndArrays(startFrames, endFrames, stringName, fillName, objectVar, fillCharArray);

    return 0;
}
