#include <iostream>
#include <windows.h>
#include "textAnimation.h"
using namespace std;

typedef struct ObjectData_type
{
    int numFrames;
    COORD area;
    COORD coord;
    WORD color;
    int length;
} ObjectData;

void FillWalkLeft0(CHAR_INFO **objectArr, ObjectData objectData, int arrIndex)
{
    string stickMan9 = "     _     "; //x = 11; y = 10
    string stickMan8 = "    (\")    ";
    string stickMan7 = "    o-o    ";
    string stickMan6 = "   / | \\   ";
    string stickMan5 = "   \\ | /   ";
    string stickMan4 = "    O-O    ";
    string stickMan3 = "    / |    ";
    string stickMan2 = "   o  o    ";
    string stickMan1 = "    \\ |    ";
    string stickMan0 = "   oO O    ";

    string stickMan;
    stickMan.append(stickMan9);
    stickMan.append(stickMan8);
    stickMan.append(stickMan7);
    stickMan.append(stickMan6);
    stickMan.append(stickMan5);
    stickMan.append(stickMan4);
    stickMan.append(stickMan3);
    stickMan.append(stickMan2);
    stickMan.append(stickMan1);
    stickMan.append(stickMan0);

    for (int col = 0; col < objectData.length; ++col)
    {
        objectArr[arrIndex][col].Char.AsciiChar = stickMan[col];
        objectArr[arrIndex][col].Attributes = objectData.color;
    }
}

void FillWalkLeft1(CHAR_INFO **objectArr, ObjectData objectData, int arrIndex)
{
    string stickMan9 = "     _     "; //x = 11; y = 10
    string stickMan8 = "    { )    ";
    string stickMan7 = "     o     ";
    string stickMan6 = "     |\\    ";
    string stickMan5 = "     |/    ";
    string stickMan4 = "    OO     ";
    string stickMan3 = "    /|     ";
    string stickMan2 = "   o o     ";
    string stickMan1 = "    \\|     ";
    string stickMan0 = "    oO     ";

    string stickMan;
    stickMan.append(stickMan9);
    stickMan.append(stickMan8);
    stickMan.append(stickMan7);
    stickMan.append(stickMan6);
    stickMan.append(stickMan5);
    stickMan.append(stickMan4);
    stickMan.append(stickMan3);
    stickMan.append(stickMan2);
    stickMan.append(stickMan1);
    stickMan.append(stickMan0);

    for (int col = 0; col < objectData.length; ++col)
    {
        objectArr[arrIndex][col].Char.AsciiChar = stickMan[col];
        objectArr[arrIndex][col].Attributes = objectData.color;
    }
}

void FillWalkLeft2(CHAR_INFO **objectArr, ObjectData objectData, int arrIndex)
{
    string stickMan9 = "     _     "; //x = 11; y = 10
    string stickMan8 = "    { )    ";
    string stickMan7 = "     o     ";
    string stickMan6 = "     |\\    ";
    string stickMan5 = "    /||    ";
    string stickMan4 = "   O OO    ";
    string stickMan3 = "    /|     ";
    string stickMan2 = "   o o     ";
    string stickMan1 = "   | |     ";
    string stickMan0 = "  **oO     ";

    string stickMan;
    stickMan.append(stickMan9);
    stickMan.append(stickMan8);
    stickMan.append(stickMan7);
    stickMan.append(stickMan6);
    stickMan.append(stickMan5);
    stickMan.append(stickMan4);
    stickMan.append(stickMan3);
    stickMan.append(stickMan2);
    stickMan.append(stickMan1);
    stickMan.append(stickMan0);

    for (int col = 0; col < objectData.length; ++col)
    {
        objectArr[arrIndex][col].Char.AsciiChar = stickMan[col];
        objectArr[arrIndex][col].Attributes = objectData.color;
    }
}

void FillWalkLeft3(CHAR_INFO **objectArr, ObjectData objectData, int arrIndex)
{
    string stickMan9 = "     _     "; //x = 11; y = 10
    string stickMan8 = "    { )    ";
    string stickMan7 = "     o     ";
    string stickMan6 = "    /|\\    ";
    string stickMan5 = "   / | \\   ";
    string stickMan4 = "  O  O  O  ";
    string stickMan3 = "    /|     ";
    string stickMan2 = "   o o     ";
    string stickMan1 = "  /   \\    ";
    string stickMan0 = "oO   oO    ";

    string stickMan;
    stickMan.append(stickMan9);
    stickMan.append(stickMan8);
    stickMan.append(stickMan7);
    stickMan.append(stickMan6);
    stickMan.append(stickMan5);
    stickMan.append(stickMan4);
    stickMan.append(stickMan3);
    stickMan.append(stickMan2);
    stickMan.append(stickMan1);
    stickMan.append(stickMan0);

    for (int col = 0; col < objectData.length; ++col)
    {
        objectArr[arrIndex][col].Char.AsciiChar = stickMan[col];
        objectArr[arrIndex][col].Attributes = objectData.color;
    }
}

void FillWalkLeft4(CHAR_INFO **objectArr, ObjectData objectData, int arrIndex)
{
    string stickMan9 = "     _     "; //x = 11; y = 10
    string stickMan8 = "    { )    ";
    string stickMan7 = "     o     ";
    string stickMan6 = "     |\\    ";
    string stickMan5 = "    /||    ";
    string stickMan4 = "   O OO    ";
    string stickMan3 = "    /|     ";
    string stickMan2 = "   o o     ";
    string stickMan1 = "   |  \\    ";
    string stickMan0 = "  oO  **   ";

    string stickMan;
    stickMan.append(stickMan9);
    stickMan.append(stickMan8);
    stickMan.append(stickMan7);
    stickMan.append(stickMan6);
    stickMan.append(stickMan5);
    stickMan.append(stickMan4);
    stickMan.append(stickMan3);
    stickMan.append(stickMan2);
    stickMan.append(stickMan1);
    stickMan.append(stickMan0);

    for (int col = 0; col < objectData.length; ++col)
    {
        objectArr[arrIndex][col].Char.AsciiChar = stickMan[col];
        objectArr[arrIndex][col].Attributes = objectData.color;
    }
}

void FillObjectData(ObjectData& objectData, int numFrames, short areaX, short areaY, short coordX, short coordY, WORD color)
{
    objectData.numFrames = numFrames; //number of frames
    objectData.area.X = areaX; //width
    objectData.area.Y = areaY; //height
    objectData.coord.X = coordX; //x coord
    objectData.coord.Y = coordY; //y coord
    objectData.color = color; //color
    objectData.length = objectData.area.X * objectData.area.Y; //length of frame
}

void Define2DArr(CHAR_INFO **objectArr, ObjectData objectData)
{
    for (int row = 0; row < objectData.numFrames; ++row)
    {
        objectArr[row] = new CHAR_INFO[objectData.length];
    }
}

void PrintCharInfoArr(CHAR_INFO **objectArr, ObjectData objectData)
{
    /**print looks like string**/
    for (int row = 0; row < objectData.numFrames; ++row)
    {
        for (int col = 0; col < objectData.length; ++col)
        {
            cout << objectArr[row][col].Char.AsciiChar;
        }
        cout << endl;
    }

    /**print looks like picture frame**/
    for (int i = 0; i < objectData.numFrames; ++i)
    {
        for (int j = 0; j < objectData.length; ++j)
        {
            if (j % objectData.area.X == 0)
                cout << endl;
            cout << objectArr[i][j].Char.AsciiChar;
        }
    }
}

void StickManMoveLeft(HANDLE hStdOut, CHAR_INFO **objectArr, ObjectData &objectData, int moveSpaces, int moveSpeed, int startFrame, int endFrame)
{
    COORD objectPos = {0, 0}; //starting print position of objectSize; x and y = 0 to print whole object

    int counter = 0;

    for (int i = 0; i < moveSpaces; ++i)
    {
        for (int f = startFrame; f < endFrame + 1; ++f)
        {
            if (counter == moveSpaces) break;
            SMALL_RECT printObjectTo = {objectData.coord.X, objectData.coord.Y, objectData.coord.X + objectData.area.X - 1, objectData.coord.Y + objectData.area.Y - 1}; //starting and ending coords to print object onto screen buffer; the dimensions will equal the objectSize
            objectData.coord.X--;
            WriteConsoleOutput(hStdOut, objectArr[f], objectData.area, objectPos, &printObjectTo); //second argument points to array: CHAR_INFO value and attribute for each array element
            Sleep(moveSpeed);
            counter++;
        }
    }
    SMALL_RECT printObjectTo = {objectData.coord.X, objectData.coord.Y, objectData.coord.X + objectData.area.X - 1, objectData.coord.Y + objectData.area.Y - 1};
    WriteConsoleOutput(hStdOut, objectArr[0], objectData.area, objectPos, &printObjectTo);
}

int main(void)
{
    SetConsoleTitle(TEXT("Stickman Animation")); //window title
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE); //declare and initialize HANDLE

    /**Hide cursor**/
    CONSOLE_CURSOR_INFO info; // = {1, 0}; <---alternative to the next two lines
    info.dwSize = 1;
    info.bVisible = 0;
    SetConsoleCursorInfo(hStdOut, &info);

    short numX = 120; //   <<<<<-------------------CONTROL
    short numY = 30; //   <<<<<-------------------CONTROL
    COORD screenSize = {numX, numY};
    SetWindowAndScreenBuffer(hStdOut, numX, numY); //Set window size and screen buffer size

    /**store data for object**/
    ObjectData stickManWalkLeftData;
    FillObjectData(stickManWalkLeftData, 5, 11, 10, 90, 20, 11);

    /**declare and define 2D array**/
    CHAR_INFO **stickManWalkLeftArr = new CHAR_INFO* [stickManWalkLeftData.numFrames]; //define first dimension of 2D pointer array
    Define2DArr(stickManWalkLeftArr, stickManWalkLeftData); //define second dimension of 2D pointer array

    /**fill CHAR_INFO arrays**/
    FillWalkLeft0(stickManWalkLeftArr, stickManWalkLeftData, 0);
    FillWalkLeft1(stickManWalkLeftArr, stickManWalkLeftData, 1);
    FillWalkLeft2(stickManWalkLeftArr, stickManWalkLeftData, 2);
    FillWalkLeft3(stickManWalkLeftArr, stickManWalkLeftData, 3);
    FillWalkLeft4(stickManWalkLeftArr, stickManWalkLeftData, 4);

    /**print CHAR_INFO arrays**/
    //PrintCharInfoArr(stickManWalkLeftArr, stickManWalkLeftData); //print 2D pointer array elements

    /**move stick man left**/
    AddObject(hStdOut, stickManWalkLeftArr[0], stickManWalkLeftData.area, stickManWalkLeftData.coord);
    Sleep(1000);
    StickManMoveLeft(hStdOut, stickManWalkLeftArr, stickManWalkLeftData, 30, 100, 1, 4);


    return 0;
}



/**used to fill string array then char_info array**/

/**
void FillObjectCharArray(string object[], CHAR_INFO **objectArr, ObjectData objectData)
{
    for (int row = 0; row < objectData.frames; ++row) //fill objectArray and set attributes
    {
        for (int col = 0; col < objectData.length; ++col)
        {
            objectArr[row][col].Char.AsciiChar = object[row][col];
            objectArr[row][col].Attributes = objectData.color;
        }
    }
}**/

/**fill string frames**
    string stickManWalkLeft[stickManWalkLeftData.frames];
    FillStandLeft(stickManWalkLeft[0]);
    FillLeftOne(stickManWalkLeft[1]);
    FillLeftTwo(stickManWalkLeft[2]);
    FillLeftThree(stickManWalkLeft[3]);
    FillLeftFour(stickManWalkLeft[4]);

    /**fill array with CHAR_INFO structs**
    FillObjectCharArray(stickManWalkLeft, stickManWalkLeftArr, stickManWalkLeftData); //assign 2D pointer array elements
    **/
