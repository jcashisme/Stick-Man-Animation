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

class PrintFrames
{
private:

public:

    int numFrames;
    COORD area;
    COORD coord;
    WORD color;
    int frameLength;

    COORD bgCoord;

    CHAR_INFO *backGround = NULL; //full screen buffer
    CHAR_INFO **bgFrame = NULL; //background frames
    CHAR_INFO **printFrame = NULL; //merge object frames and background frames

    //constructor initialize data variables
    void StoreData(int numframes, ObjectClass objectClass)
    {
        numFrames = numframes + 1; //move spaces plus one for fill current coord
        area = objectClass.area;
        coord = objectClass.coord;
        color = objectClass.color;
        frameLength = objectClass.area.X * objectClass.area.Y;

        bgCoord = objectClass.coord;
    }

    //read in full screen buffer before adding moving objects to buffer
    void ReadInScreenBackGround (HANDLE hStdOut, COORD screenSize)
    {
        backGround = new CHAR_INFO [screenSize.X * screenSize.Y];
        COORD buffer_index = {0, 0};
        COORD backGroundCoord = {0, 0};
        SMALL_RECT smallRct = {backGroundCoord.X, backGroundCoord.Y, backGroundCoord.X + screenSize.X - 1,
                               backGroundCoord.Y + screenSize.Y - 1
                              };

        ReadConsoleOutput(hStdOut, backGround, screenSize, buffer_index, &smallRct);
    }

    //define bgFrames and printFrames
    void DefinePrintFrames()
    {
        bgFrame = new CHAR_INFO *[numFrames];
        printFrame = new CHAR_INFO *[numFrames];

        for (int i = 0; i < numFrames; ++i)
        {
            bgFrame[i] = new CHAR_INFO [frameLength];
            printFrame[i] = new CHAR_INFO [frameLength];
        }
    }

    //initialize bgFrames from hidden screen buffer that stores the backGround before moving objects are added
    void InitializeBGFrames(HANDLE hStdOut, int moveDirection)
    {
        COORD buffer_index = {0, 0};

        //initialize bgFrames
        for (int i = 0; i < numFrames; ++i) //move spaces
        {
            SMALL_RECT smallRct = {bgCoord.X, bgCoord.Y, bgCoord.X + area.X - 1,
                                   bgCoord.Y + area.Y - 1
                                  };
            ReadConsoleOutput(hStdOut, bgFrame[i], area, buffer_index, &smallRct);

            if (moveDirection == 7)
                bgCoord.X--;
            else if (moveDirection == 3)
                bgCoord.X++;
        }
    }

    //initialize printFrames
    void InitializePrintFrames(HANDLE hStdOut, ObjectClass objectClass, int objStandFrame, int objStartFrame, int objEndFrame)
    {
        //initialize printFrames
        int counter = objStartFrame;

        for (int j = 0; j < numFrames; ++j) //dependent on move spaces
        {
            if (counter > objEndFrame)
                counter = objStartFrame; //start objectClass.frame = start frame; end objectClass.frame = end frame
            for (int i = 0; i < frameLength; ++i)
            {
                if (objectClass.frame[counter][i].Char.AsciiChar != ' ')
                {
                    printFrame[j][i].Char.AsciiChar = objectClass.frame[counter][i].Char.AsciiChar;
                    printFrame[j][i].Attributes = objectClass.color;
                }
                else
                {
                    printFrame[j][i].Char.AsciiChar = bgFrame[j][i].Char.AsciiChar;
                    printFrame[j][i].Attributes = bgFrame[j][i].Attributes;
                }
                if (j == 0 || j == numFrames - 1) // first and last frame is stand position: objectClass.frame index 0
                {
                    if (objectClass.frame[objStandFrame][i].Char.AsciiChar != ' ')
                    {
                        printFrame[j][i].Char.AsciiChar = objectClass.frame[objStandFrame][i].Char.AsciiChar; //input stand frame into function
                        printFrame[j][i].Attributes = objectClass.color;
                    }
                    else
                    {
                        printFrame[j][i].Char.AsciiChar = bgFrame[j][i].Char.AsciiChar;
                        printFrame[j][i].Attributes = bgFrame[j][i].Attributes;
                    }
                }
            }
            counter++;
        }
    }

    void MoveLeft(HANDLE hStdOut, ObjectClass &objectClass, int moveDuration)
    {
        COORD buffer_index = {0, 0};

        for (int i = 1; i < numFrames; ++i) //dependent on move spaces
        {
            objectClass.coord.X--;
            SMALL_RECT printObjectTo = {objectClass.coord.X, objectClass.coord.Y,
                                objectClass.coord.X + area.X - 1, objectClass.coord.Y + area.Y - 1};
            WriteConsoleOutput(hStdOut, printFrame[i], area, buffer_index, &printObjectTo);
            Sleep(moveDuration);
        }
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
    COORD screenCoord = {0, 0};
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


    /**prepare print class**/
    PrintFrames printFrame;
    printFrame.StoreData(42, stickMan); //print class; input move spaces

    //create hidden screen buffer and fill with backGround char_info
    printFrame.ReadInScreenBackGround(hStdOut, screenSize); //read background before adding moving objects to screen
    HANDLE hiddenStdOut = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
    AddObject(hiddenStdOut, printFrame.backGround, screenSize, screenCoord);

    //define and initialize print frames
    printFrame.DefinePrintFrames();
    printFrame.InitializeBGFrames(hiddenStdOut, 7); //read from hidden backGround screen buffer
    printFrame.InitializePrintFrames(hStdOut, stickMan, 0, 1, 4);

    //test object movement
    AddObject(hStdOut, printFrame.printFrame[0], stickMan.area, stickMan.coord);
    Sleep(1000);

    printFrame.MoveLeft(hStdOut, stickMan, 100);
    Sleep(1000);


    //test second move
    printFrame.StoreData(38, stickMan); //print class; input move spaces
    printFrame.DefinePrintFrames();
    printFrame.InitializeBGFrames(hiddenStdOut, 7); //read from hidden backGround screen buffer
    printFrame.InitializePrintFrames(hStdOut, stickMan, 0, 1, 4);

    printFrame.MoveLeft(hStdOut, stickMan, 100);
    Sleep(1000);


    Sleep(900000);


    return 0;
}


