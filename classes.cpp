#include <iostream>
#include <windows.h>
#include "textAnimation.h"
using namespace std;

typedef CHAR_INFO *CharInfoPtr;

class StickMan //generic name
{
private:

public:

    int walkLeftFrameSize; //generic name
    CharInfoPtr *walkLeftArr; //generic name
    ObjectVariables variables; //update struct

    StickMan(short areaX, short areaY, short coordX, short coordY, WORD color)
    { //add numFrames and CHAR_INFO array double pointer
        variables.area.X = areaX; //width
        variables.area.Y = areaY; //height
        variables.fillCoord.X = coordX; //x coord
        variables.fillCoord.Y = coordY; //y coord
        variables.color = color; //color
        variables.length = variables.area.X * variables.area.Y;
    }

    void FillWalkLeftFrames(int numFrames, string strings[])
    {
        walkLeftFrameSize = strings[0].size();

        /**create dynamic two-d arrays for char_info structs**/
        walkLeftArr = new CharInfoPtr[numFrames]; //reinitialize array size
        for (int i = 0; i < numFrames; ++i)
        {
            walkLeftArr[i] = new CHAR_INFO[walkLeftFrameSize];
        }

        /**fill char_info arrays**/
        for (int i = 0; i < numFrames; ++i) //fill objectArray and set attributes
        {
            for (int j = 0; j < walkLeftFrameSize; ++j)
            {
                walkLeftArr[i][j].Char.AsciiChar = strings[i][j];
                walkLeftArr[i][j].Attributes = 14;
            }
        }
    }
};

int main()
{
    int numWalkLeftFrames = 2;
    string walkLeftStrings[2] = {"test string", "gnirts tset"}; //no need for strings
    StickMan stickMan(11, 10, 40, 20, 11);

    stickMan.FillWalkLeftFrames(numWalkLeftFrames, walkLeftStrings);

    for (int i = 0; i < numWalkLeftFrames; ++i)
    {
        for (int j = 0; j < stickMan.walkLeftFrameSize; ++j)

        {
            cout << stickMan.walkLeftArr[i][j].Char.AsciiChar;
        }
        cout << endl;

    }

    return 0;
}







/**

class StickMan
{
private:

public:

    int walkLeftFrameSize;
    CHAR_INFO *walkLeftArr;
    ObjectVariables variables;

    StickMan(short areaX, short areaY, short coordX, short coordY, WORD color)
    {
        variables.area.X = areaX; //width
        variables.area.Y = areaY; //height
        variables.fillCoord.X = coordX; //x coord
        variables.fillCoord.Y = coordY; //y coord
        variables.color = color; //color
        variables.length = variables.area.X * variables.area.Y;
    }

    void FillWalkLeftFrames(string str)
    {
        walkLeftFrameSize = str.size();
        walkLeftArr = new CHAR_INFO[walkLeftFrameSize]; //reinitialize array size

        for (int i = 0; i < walkLeftFrameSize; ++i)
        {
            walkLeftArr[i].Char.AsciiChar = str[i];
            walkLeftArr[i].Attributes = 14;
        }
    }
};

int main()
{
    string walkLeftStrings = "test string";
    StickMan stickMan(11, 10, 40, 20, 11);

    stickMan.FillWalkLeftFrames(walkLeftStrings);

    for (int i = 0; i < stickMan.walkLeftFrameSize; ++i)
    {
        cout << stickMan.walkLeftArr[i].Char.AsciiChar;
    }



    return 0;
}**/
