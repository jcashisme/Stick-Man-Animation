#include <iostream>
using namespace std;

void PrintStringsAndArrays(int numFrames, string stringName, string fillName, string objectVar, string fillCharArray)
{
    /**
    for (int i = startFrames; i < endFrames + 1; ++i)
    {
        cout << "string " << stringName << i << ";" << endl;
    }
    for (int i = startFrames; i < endFrames + 1; ++i)
    {
        cout << "CHAR_INFO " << stringName << i << "Arr[" << objectVar << ".length];" << endl;
    }

    cout << endl;**/


    cout << "int " << stringName << "NumFrames = " << numFrames << ";" << endl << endl;


    for (int i = 0; i < numFrames; ++i)
    {
        cout << fillName << i + 1 << "(" << stringName << "[" << i << "]);" << endl;
    }

    cout << endl;
}

int main()
{
    int numFrames = 9;

    string stringName = "fireWorks";
    string fillName = "FillFireWorks";
    string objectVar = "fireWorksVar";
    string fillCharArray = "FillFireWorksCharArray";

    PrintStringsAndArrays(numFrames, stringName, fillName, objectVar, fillCharArray);

    return 0;
}
