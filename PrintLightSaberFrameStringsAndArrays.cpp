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
             << objectVar << ", "
             << "stickManVar, "
             << "lightSaberColor);" << endl;
    }

    cout << endl;

    for (int i = startFrames; i < endFrames + 1; ++i)
    {
        cout << "CHAR_INFO " << stringName << i << "Arr[], ";
    }
}

int main()
{
    int startFrames = 17;
    int endFrames = 24;
    string stringName = "lightSaber";
    string fillName = "FillLightSaber";
    string objectVar = "stickManLightSaberVar";
    string fillCharArray = "FillLightSaberCharArray";

    PrintStringsAndArrays(startFrames, endFrames, stringName, fillName, objectVar, fillCharArray);

    return 0;
}
