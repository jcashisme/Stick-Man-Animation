#include <iostream>
#include <windows.h>
#include "textAnimation.h"
using namespace std;

class ObjectClass
{
private:

public:

    int numFrames;
    COORD area;
    COORD coord;
    WORD color;
    int frameLength;
    CHAR_INFO **frame;

    ObjectClass(int numframes, short areaX, short areaY, short coordX, short coordY, WORD clr)
    {
        numFrames = numframes;
        area.X = areaX;
        area.Y = areaY;
        coord.X = coordX;
        coord.Y = coordY;
        color = clr;
        frameLength = areaX * areaY;

        frame = new CHAR_INFO *[numFrames]; //define CHAR_INFO 2D dynamic array
        for (int i = 0; i < numFrames; ++i)
        {
            frame[i] = new CHAR_INFO[frameLength];
        }
    }

    void PrintFrame(HANDLE hStdOut, int arrIndex)
    {
        COORD objectPos = {0, 0}; //starting print position of objectSize; x and y = 0 to print whole object
        SMALL_RECT printObjectTo = {coord.X, coord.Y, coord.X + area.X - 1, coord.Y + area.Y - 1}; //starting and ending coords to print object onto screen buffer; the dimensions will equal the objectSize

        WriteConsoleOutput(hStdOut, frame[arrIndex], area, objectPos, &printObjectTo); //second argument points to array: CHAR_INFO value and attribute for each array element
    }

    void WalkLeft(HANDLE hStdOut, int moveSpaces, int moveSpeed, int startFrame, int endFrame)
    {
        COORD objectPos = {0, 0}; //starting print position of objectSize; x and y = 0 to print whole object
        int counter = 0;

        for (int i = 0; i < moveSpaces; ++i)
        {
            for (int f = startFrame; f < endFrame + 1; ++f)
            {
                if (counter == moveSpaces)
                    break;
                SMALL_RECT printObjectTo = {coord.X, coord.Y, coord.X + area.X - 1, coord.Y + area.Y - 1}; //starting and ending coords to print object onto screen buffer; the dimensions will equal the objectSize
                coord.X--;
                WriteConsoleOutput(hStdOut, frame[f], area, objectPos, &printObjectTo); //second argument points to array: CHAR_INFO value and attribute for each array element
                Sleep(moveSpeed);
                counter++;
            }
        }
        SMALL_RECT printObjectTo = {coord.X, coord.Y, coord.X + area.X - 1, coord.Y + area.Y - 1};
        WriteConsoleOutput(hStdOut, frame[0], area, objectPos, &printObjectTo);
    }
};

void FillWalkLeft0(ObjectClass objectClass, int arrIndex)
{
    //CHAR_INFO **pointer in data structure
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

    for (int col = 0; col < objectClass.frameLength; ++col)
    {
        objectClass.frame[arrIndex][col].Char.AsciiChar = stickMan[col];
        objectClass.frame[arrIndex][col].Attributes = objectClass.color;
    }
}

void FillWalkLeft1(ObjectClass objectClass, int arrIndex)
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

    for (int col = 0; col < objectClass.frameLength; ++col)
    {
        objectClass.frame[arrIndex][col].Char.AsciiChar = stickMan[col];
        objectClass.frame[arrIndex][col].Attributes = objectClass.color;
    }
}

void FillWalkLeft2(ObjectClass objectClass, int arrIndex)
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

    for (int col = 0; col < objectClass.frameLength; ++col)
    {
        objectClass.frame[arrIndex][col].Char.AsciiChar = stickMan[col];
        objectClass.frame[arrIndex][col].Attributes = objectClass.color;
    }
}

void FillWalkLeft3(ObjectClass objectClass, int arrIndex)
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

    for (int col = 0; col < objectClass.frameLength; ++col)
    {
        objectClass.frame[arrIndex][col].Char.AsciiChar = stickMan[col];
        objectClass.frame[arrIndex][col].Attributes = objectClass.color;
    }
}

void FillWalkLeft4(ObjectClass objectClass, int arrIndex)
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

    for (int col = 0; col < objectClass.frameLength; ++col)
    {
        objectClass.frame[arrIndex][col].Char.AsciiChar = stickMan[col];
        objectClass.frame[arrIndex][col].Attributes = objectClass.color;
    }
}

void FillBackground(CHAR_INFO arr[]) //testing stick man print over background
{
    string stickMan9 = "QQQQQQQQQQQQQQQQQQQQQQQQPPPPPPPPPPPPPPPPPPPPPPPPPP"; //x = 50; y = 10
    string stickMan8 = "QQQQQQQQQQQQQQQQQQQQQQQQPPPPPPPPPPPPPPPPPPPPPPPPPP";
    string stickMan7 = "QQQQQQQQQQQQQQQQQQQQQQQQPPPPPPPPPPPPPPPPPPPPPPPPPP";
    string stickMan6 = "QQQQQQQQQQQQQQQQQQQQQQQQPPPPPPPPPPPPPPPPPPPPPPPPPP";
    string stickMan5 = "QQQQQQQQQQQQQQQQQQQQQQQQPPPPPPPPPPPPPPPPPPPPPPPPPP";
    string stickMan4 = "QQQQQQQQQQQQQQQQQQQQQQQQPPPPPPPPPPPPPPPPPPPPPPPPPP";
    string stickMan3 = "QQQQQQQQQQQQQQQQQQQQQQQQPPPPPPPPPPPPPPPPPPPPPPPPPP";
    string stickMan2 = "QQQQQQQQQQQQQQQQQQQQQQQQPPPPPPPPPPPPPPPPPPPPPPPPPP";
    string stickMan1 = "QQQQQQQQQQQQQQQQQQQQQQQQPPPPPPPPPPPPPPPPPPPPPPPPPP";
    string stickMan0 = "QQQQQQQQQQQQQQQQQQQQQQQQPPPPPPPPPPPPPPPPPPPPPPPPPP";

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

    for (int col = 0; col < stickMan.size(); ++col)
    {
        arr[col].Char.AsciiChar = stickMan[col];
        arr[col].Attributes = 14;
    }
}

int main()
{
    SetConsoleTitle(TEXT("Stickman Animation")); //window title
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE); //declare and initialize HANDLE

    /**Hide cursor**/
    CONSOLE_CURSOR_INFO info; // = {1, 0}; <---alternative to the next two lines
    info.dwSize = 1;
    info.bVisible = 0;
    SetConsoleCursorInfo(hStdOut, &info);

    /**Set window and screen buffer size**/
    short numX = 120; //   <<<<<-------------------CONTROL
    short numY = 30; //   <<<<<-------------------CONTROL
    COORD screenSize = {numX, numY};
    SetWindowAndScreenBuffer(hStdOut, numX, numY); //Set window size and screen buffer size

    /**Define class object and fill CHAR_INFO array with frames**/
    ObjectClass stickMan(5, 11, 10, 30, 20, 11);

    FillWalkLeft0(stickMan, 0); //stand left frame
    FillWalkLeft1(stickMan, 1); //1 - 4 are walk left frames
    FillWalkLeft2(stickMan, 2);
    FillWalkLeft3(stickMan, 3);
    FillWalkLeft4(stickMan, 4);

    stickMan.PrintFrame(hStdOut, 0);
    stickMan.coord.X = stickMan.coord.X + 20;
    stickMan.PrintFrame(hStdOut, 0);
    stickMan.coord.X = stickMan.coord.X + 20;
    stickMan.PrintFrame(hStdOut, 0);
    stickMan.coord.X = stickMan.coord.X + 20;
    //Sleep(1000);
    //stickMan.WalkLeft(hStdOut, 20, 100, 1, 4);

    /**print background to test**
    CHAR_INFO BG[50 * 10];
    COORD BGarea = {50, 10};
    COORD BGcoord = {stickMan.coord.X - 40, stickMan.coord.Y};
    FillBackground(BG);

    AddObject(hStdOut, BG, BGarea, BGcoord);**/

    /**read screen from console before adding moving objects**/
    CHAR_INFO backGround[screenSize.X * screenSize.Y];
    COORD buffer_index = {0, 0};
    COORD backGroundCoord = {0, 0};
    SMALL_RECT smallRct = {backGroundCoord.X, backGroundCoord.Y, backGroundCoord.X + screenSize.X - 1,
                           backGroundCoord.Y + screenSize.Y - 1};

    ReadConsoleOutput(hStdOut, backGround, screenSize, buffer_index, &smallRct);

    /**read in background frames to merge with object frames**/
    CHAR_INFO inStr[80 + 1][stickMan.frameLength]; //move spaces
    COORD inStrCoord = stickMan.coord;
    //SMALL_RECT smallRct1 = {inStrCoord.X, inStrCoord.Y, inStrCoord.X + stickMan.area.X - 1,
    //                       inStrCoord.Y + stickMan.area.Y - 1};

    for (int i = 0; i < 80 + 1; ++i) //move spaces
    {
        SMALL_RECT smallRct1 = {inStrCoord.X, inStrCoord.Y, inStrCoord.X + stickMan.area.X - 1,
                           inStrCoord.Y + stickMan.area.Y - 1};
        ReadConsoleOutput(hStdOut, inStr[i], stickMan.area, buffer_index, &smallRct1);
        inStrCoord.X--; //dependent on move direction
    }

    /**fill new frame (object and background) to print**/
    CHAR_INFO newFrame[80 + 1][stickMan.frameLength]; //first dimension dependent on move spaces
    int counter = 1;
    int objectColor = 14;

    for (int j = 0; j < 80 + 1; ++j) //dependent on move spaces
    {
        if (counter == 5)
            counter = 1; //start stick man frame = 1; end stick man frame = 4
        for (int i = 0; i < stickMan.frameLength; ++i)
        {
            if (stickMan.frame[counter][i].Char.AsciiChar != ' ')
            {
                newFrame[j][i].Char.AsciiChar = stickMan.frame[counter][i].Char.AsciiChar;
                newFrame[j][i].Attributes = objectColor;
            }
            else
            {
                newFrame[j][i].Char.AsciiChar = inStr[j][i].Char.AsciiChar;
                newFrame[j][i].Attributes = inStr[j][i].Attributes;
            }
            if (j == 0 || j == 80) // first and last frame is stand position: stick man index 0
            {
                if (stickMan.frame[0][i].Char.AsciiChar != ' ')
                {
                    newFrame[j][i].Char.AsciiChar = stickMan.frame[0][i].Char.AsciiChar; //input stand frame into function
                    newFrame[j][i].Attributes = objectColor;
                }
                else
                {
                    newFrame[j][i].Char.AsciiChar = inStr[j][i].Char.AsciiChar;
                    newFrame[j][i].Attributes = inStr[j][i].Attributes;
                }
            }
        }
        counter++;
    }

    /**print new frame**/

    AddObject(hStdOut, newFrame[0], stickMan.area, stickMan.coord);
    Sleep(1000);

    //stickMan.coord.X--; //change stick man coord.X after stand print
    for (int i = 1; i < 80 + 1; ++i) //dependent on move spaces
    {
        stickMan.coord.X--;
        AddObject(hStdOut, newFrame[i], stickMan.area, stickMan.coord);
        Sleep(100);
    }


    return 0;
}


