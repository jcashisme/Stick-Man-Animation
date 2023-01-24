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

    void AddFrame(HANDLE hStdOut, int arrIndex)
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
    string stickMan9 = "PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP"; //x = 50; y = 10
    string stickMan8 = "PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP";
    string stickMan7 = "PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP";
    string stickMan6 = "PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP";
    string stickMan5 = "PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP";
    string stickMan4 = "PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP";
    string stickMan3 = "PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP";
    string stickMan2 = "PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP";
    string stickMan1 = "PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP";
    string stickMan0 = "PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP";

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
    ObjectClass stickMan(5, 11, 10, 90, 20, 11);

    FillWalkLeft0(stickMan, 0); //stand left frame
    FillWalkLeft1(stickMan, 1); //1 - 4 are walk left frames
    FillWalkLeft2(stickMan, 2);
    FillWalkLeft3(stickMan, 3);
    FillWalkLeft4(stickMan, 4);

    //stickMan.AddFrame(hStdOut, 0);
    //Sleep(1000);
    //stickMan.WalkLeft(hStdOut, 20, 100, 1, 4);

    /**print background to test**/
    CHAR_INFO BG[50 * 10];
    COORD BGarea = {50, 10};
    COORD BGcoord = {stickMan.coord.X - 40, stickMan.coord.Y};
    FillBackground(BG);

    AddObject(hStdOut, BG, BGarea, BGcoord);

    /**read from console**/
    CHAR_INFO inStr[50 * 10]; //dependent on how many spaces the object will move
    COORD buffer_index = {0, 0};
    SMALL_RECT smallRct = {BGcoord.X, BGcoord.Y, BGcoord.X + BGarea.X - 1, BGcoord.Y + BGarea.Y - 1};
    ReadConsoleOutput(hStdOut, inStr, BGarea, buffer_index, &smallRct);

    /**fill new frame (object and background) to print**/

    CHAR_INFO newFrame[50 - 11 + 2][stickMan.frameLength]; //first dimensional dependent on move spaces
    int counter = 1;

    for (int j = 0; j < 50 - 11 + 2; ++j) //dependent on move spaces
    {
        if (counter == 5)
            counter = 1; //start stick man frame = 1; end stick man frame = 4
        for (int i = 0; i < stickMan.frameLength; ++i)
        {
            if (stickMan.frame[counter][i].Char.AsciiChar != ' ')
            {
                newFrame[j][i].Char.AsciiChar = stickMan.frame[counter][i].Char.AsciiChar;
                newFrame[j][i].Attributes = stickMan.frame[counter][i].Attributes;
            }
            else
            {
                newFrame[j][i].Char.AsciiChar = inStr[i].Char.AsciiChar;
                newFrame[j][i].Attributes = inStr[i].Attributes;
            }
            if (j == 0 || j == 50 - 11 + 1) // first and last frame is stand position: stick man index 0
            {
                if (stickMan.frame[0][i].Char.AsciiChar != ' ')
                {
                    newFrame[j][i].Char.AsciiChar = stickMan.frame[0][i].Char.AsciiChar;
                    newFrame[j][i].Attributes = stickMan.frame[0][i].Attributes;
                }
                else
                {
                    newFrame[j][i].Char.AsciiChar = inStr[i].Char.AsciiChar;
                    newFrame[j][i].Attributes = inStr[i].Attributes;
                }
            }
        }
        counter++;
    }

    /**print new frame**/

    AddObject(hStdOut, newFrame[0], stickMan.area, stickMan.coord);
    Sleep(1000);

    for (int i = 1; i < 50 - 11 + 2; ++i) //dependent on move spaces
    {
        AddObject(hStdOut, newFrame[i], stickMan.area, stickMan.coord);
        stickMan.coord.X--;
        Sleep(100);
    }


    return 0;
}


