#include <iostream>
#include <windows.h> //console api functions
#include <cstdlib>
#include <ctime>
using namespace std;

/*
    CHAR_INFO .Attribute color codes:

    0   BLACK
    1   BLUE
    2   GREEN
    3   CYAN
    4   RED
    5   MAGENTA
    6   BROWN
    7   LIGHTGRAY
    8   DARKGRAY
    9   LIGHTBLUE
    10  LIGHTGREEN
    11  LIGHTCYAN
    12  LIGHTRED
    13  LIGHTMAGENTA
    14  YELLOW
    15  WHITE
*/

bool move_rect(
    int x,     int y,
    int new_x, int new_y,
    int width, int height
)
{
    HANDLE     hStdOut      = GetStdHandle( STD_OUTPUT_HANDLE );
    PCHAR_INFO buffer       = new CHAR_INFO[ width * height ];
    COORD      buffer_size  = { width, height };
    COORD      buffer_index = { 0, 0 };  // read/write rectangle has upper-right corner at upper-right corner of buffer
    SMALL_RECT read_rect    = { x,     y,     x     + width - 1, y     + height - 1 };
    SMALL_RECT write_rect   = { new_x, new_y, new_x + width - 1, new_y + height - 1 };

    bool result = ReadConsoleOutput(  hStdOut, buffer, buffer_size, buffer_index, &read_rect )
                  && WriteConsoleOutput( hStdOut, buffer, buffer_size, buffer_index, &write_rect );

    delete [] buffer;

    return result;
}

int RandomTextColor()
{
    int randomColor = (rand() % 5) + 10;
    return randomColor;
}

void SetWindowAndScreenBuffer(HANDLE hStdOut, int numX, int numY)
{
    SMALL_RECT windowSize = {0, 0, numX - 1, numY}; //declare and initialize window size
    SetConsoleWindowInfo(hStdOut, TRUE, &windowSize); //change console window size

    COORD bufferSize = {numX * 1.5, numY * 1.5}; //create a COORD to hold the buffer size; buffer wider than window
    SetConsoleScreenBufferSize(hStdOut, bufferSize); //change the internal buffer size
}

struct ObjectVariables
{
    COORD area;
    COORD fillCoord;
    WORD color;
    int length;
};

//fill object variable struct
void FillObjectVariables(ObjectVariables& objectVar, short areaX, short areaY, short fillCoordX, short fillCoordY, WORD color)
{
    objectVar.area.X = areaX; //width
    objectVar.area.Y = areaY; //height
    objectVar.fillCoord.X = fillCoordX; //x coord
    objectVar.fillCoord.Y = fillCoordY; //y coord
    objectVar.color = color; //color
    objectVar.length = objectVar.area.X * objectVar.area.Y;
}

void FillObjectCharArray(string object, CHAR_INFO objectArray[], ObjectVariables& objectVar)
{
    int arrayLength = objectVar.area.X * objectVar.area.Y;

    for (int i = 0; i < arrayLength; ++i) //fill objectArray and set attributes
    {
        objectArray[i].Char.AsciiChar = object[i];
        objectArray[i].Attributes = objectVar.color;
    }
}

void FillWatchFireWorksCharArrays(string object[], CHAR_INFO objectArray[][16 * 10], int numFrames, ObjectVariables& objectVar)
{
    //int arrayLength = objectVar.area.X * objectVar.area.Y;

    for (int i = 0; i < numFrames; ++i) //fill objectArray and set attributes
    {
        for (int j = 0; j < (16 * 10); ++j)
        {
            objectArray[i][j].Char.AsciiChar = object[i][j];
            objectArray[i][j].Attributes = objectVar.color;
        }
    }
}

void FillFireWorksCharArrays(string object[], CHAR_INFO objectArray[][17 * 8], int numFrames)
{
    //int arrayLength = objectVar.area.X * objectVar.area.Y;

    for (int i = 0; i < numFrames; ++i) //fill objectArray and set attributes
    {
        for (int j = 0; j < (17 * 8); ++j)
        {
            objectArray[i][j].Char.AsciiChar = object[i][j];
            objectArray[i][j].Attributes = RandomTextColor();
        }
    }
}

void FillStickManCharArrays(string object[], CHAR_INFO objectArray[][11 * 10], int numFrames, ObjectVariables& objectVar)
{
    for (int i = 0; i < numFrames; ++i) //fill objectArray and set attributes
    {
        for (int j = 0; j < (11 * 10); ++j)
        {
            objectArray[i][j].Char.AsciiChar = object[i][j];
            objectArray[i][j].Attributes = objectVar.color;
        }
    }
}

void FillCloudOneCharArrays(string object[], CHAR_INFO objectArray[][7 * 4], int numFrames, ObjectVariables& objectVar)
{
    for (int i = 0; i < numFrames; ++i) //fill objectArray and set attributes
    {
        for (int j = 0; j < (7 * 4); ++j)
        {
            objectArray[i][j].Char.AsciiChar = object[i][j];
            objectArray[i][j].Attributes = objectVar.color;
        }
    }
}


void FillCloudTwoCharArrays(string object[], CHAR_INFO objectArray[][24 * 8], int numFrames, ObjectVariables& objectVar)
{
    //int arrayLength = objectVar.area.X * objectVar.area.Y;

    for (int i = 0; i < numFrames; ++i) //fill objectArray and set attributes
    {
        for (int j = 0; j < (24 * 8); ++j)
        {
            objectArray[i][j].Char.AsciiChar = object[i][j];

            if (object[i][j] == '\\' || object[i][j] == '|' || object[i][j] == '/' ||
                object[i][j] == '.' || object[i][j] == '*')
            {
                objectArray[i][j].Attributes = 14;
            }
            else if ((j >= 48 && j <= 60 && object[i][j] == '-') ||
                     (j >= 72 && j <= 84 && object[i][j] == '_') ||
                     (j >= 120 && j <= 132 && object[i][j] == '-'))
            {
                objectArray[i][j].Attributes = 14;
            }
            else
                objectArray[i][j].Attributes = objectVar.color;
        }
    }
}

void FillTreeCharArray(string object, CHAR_INFO objectArray[], ObjectVariables& objectVar)
{
    int arrayLength = objectVar.area.X * objectVar.area.Y;

    for (int i = 0; i < arrayLength; ++i) //fill objectArray and set attributes
    {
        objectArray[i].Char.AsciiChar = object[i];

        if (object[i] == '|' || object[i] == 'V' || object[i] == 'H' || object[i] == 'A')
            objectArray[i].Attributes = 6;
        else if (object[i] == 'Q')
            objectArray[i].Attributes = 13;
        else if (object[i] == 'O')
            objectArray[i].Attributes = 12;
        else if (object[i] == 'o')
            objectArray[i].Attributes = 14;
        else
            objectArray[i].Attributes = 10;
    }
}

void FillLightSaberCharArray(string object, CHAR_INFO objectArray[], ObjectVariables& stickManLightSaberVar, ObjectVariables& stickManVar, int lightSaberColor)
{
    int arrayLength = stickManLightSaberVar.area.X * stickManLightSaberVar.area.Y;

    for (int i = 0; i < arrayLength; ++i) //fill objectArray and set attributes
    {
        objectArray[i].Char.AsciiChar = object[i];
        objectArray[i].Attributes = stickManVar.color;

        if (object[i] == '*')
            objectArray[i].Attributes = 6;

        if ((object[i] == '-' && i >= 0 && i <= 175) ||
                (object[i] == '\'' && i >= 0 && i <= 175) ||
                (object[i] == '.' && i >= 0 && i <= 175))
        {
            objectArray[i].Attributes = lightSaberColor;
        }

        if (object[i] == '=' || object[i] == '[')
            objectArray[i].Attributes = lightSaberColor;


        /**
        else if ((object[i] == '-' && i >= 270 && i <= 280) ||
                 (object[i] == '-' && i >= 305 && i <= 315) ||
                 (object[i] == '-' && i >= 340 && i <= 385))
            objectArray[i].Attributes = lightSaberColor;**/

    }
}

void FillSingleCharArray(string object, CHAR_INFO objectArray[], int arrayLength, WORD objectColor)
{
    for (int i = 0; i < arrayLength; ++i) //fill objectArray and set attributes
    {
        objectArray[i].Char.AsciiChar = object[0];
        objectArray[i].Attributes = objectColor;
    }
}

void AddObject(HANDLE hStdOut, const CHAR_INFO objectArray[], COORD objectSize, COORD fillCoord)
{
    COORD objectPos = {0, 0}; //starting print position of objectSize; x and y = 0 to print whole object
    SMALL_RECT printObjectTo = {fillCoord.X, fillCoord.Y, fillCoord.X + objectSize.X - 1, fillCoord.Y + objectSize.Y - 1}; //starting and ending coords to print object onto screen buffer; the dimensions will equal the objectSize

    WriteConsoleOutput(hStdOut, objectArray, objectSize, objectPos, &printObjectTo); //second argument points to array: CHAR_INFO value and attribute for each array element
}

void ClearArea(HANDLE hStdOut, CHAR_INFO clearSpaceArr[], COORD clearSpaceSize, COORD clearFillCoord, COORD areaSize)
{
    SMALL_RECT printObjectTo = {clearFillCoord.X, clearFillCoord.Y, clearFillCoord.X + areaSize.X - 1, clearFillCoord.Y + areaSize.Y - 1};
    COORD objectPos = {clearSpaceSize.X - areaSize.X, clearSpaceSize.Y - areaSize.Y};

    WriteConsoleOutput(hStdOut, clearSpaceArr, clearSpaceSize, objectPos, &printObjectTo);
}

void MoveStickManLeft(HANDLE hStdOut, ObjectVariables& stickManVar, CHAR_INFO standLeftArr[], CHAR_INFO leftOneArr[], CHAR_INFO leftTwoArr[], CHAR_INFO leftThreeArr[], CHAR_INFO leftFourArr[],
                      int frameSpaces, int moveSpaces, int moveDuration, CHAR_INFO clearSpaceArr[], COORD clearSpaceSize)
{
    COORD clearCol = {frameSpaces, stickManVar.area.Y};
    int counter = 0;

    do
    {
        ClearArea(hStdOut, clearSpaceArr, clearSpaceSize, (COORD)
        {
            stickManVar.fillCoord.X + stickManVar.area.X - frameSpaces, stickManVar.fillCoord.Y
        }, clearCol);
        stickManVar.fillCoord.X = stickManVar.fillCoord.X - frameSpaces;
        AddObject(hStdOut, leftOneArr, stickManVar.area, stickManVar.fillCoord);
        counter = counter + frameSpaces;
        Sleep(moveDuration);
        if (counter >= moveSpaces)
            break;

        ClearArea(hStdOut, clearSpaceArr, clearSpaceSize, (COORD)
        {
            stickManVar.fillCoord.X + stickManVar.area.X - frameSpaces, stickManVar.fillCoord.Y
        }, clearCol);
        stickManVar.fillCoord.X = stickManVar.fillCoord.X - frameSpaces;
        AddObject(hStdOut, leftTwoArr, stickManVar.area, stickManVar.fillCoord);
        counter = counter + frameSpaces;
        Sleep(moveDuration);
        if (counter >= moveSpaces)
            break;

        ClearArea(hStdOut, clearSpaceArr, clearSpaceSize, (COORD)
        {
            stickManVar.fillCoord.X + stickManVar.area.X - frameSpaces, stickManVar.fillCoord.Y
        }, clearCol);
        stickManVar.fillCoord.X = stickManVar.fillCoord.X - frameSpaces;
        AddObject(hStdOut, leftThreeArr, stickManVar.area, stickManVar.fillCoord);
        counter = counter + frameSpaces;
        Sleep(moveDuration);
        if (counter >= moveSpaces)
            break;

        ClearArea(hStdOut, clearSpaceArr, clearSpaceSize, (COORD)
        {
            stickManVar.fillCoord.X + stickManVar.area.X - frameSpaces, stickManVar.fillCoord.Y
        }, clearCol);
        stickManVar.fillCoord.X = stickManVar.fillCoord.X - frameSpaces;
        AddObject(hStdOut, leftFourArr, stickManVar.area, stickManVar.fillCoord);
        counter = counter + frameSpaces;
        Sleep(moveDuration);
        if (counter >= moveSpaces)
            break;

    }
    while(true);

    AddObject(hStdOut, standLeftArr, stickManVar.area, stickManVar.fillCoord);
    Sleep(moveDuration);

}

void MoveStickManRight(HANDLE hStdOut, ObjectVariables& stickManVar, CHAR_INFO standRightArr[], CHAR_INFO rightOneArr[], CHAR_INFO rightTwoArr[], CHAR_INFO rightThreeArr[], CHAR_INFO rightFourArr[],
                       int frameSpaces, int moveSpaces, int moveDuration, CHAR_INFO clearSpaceArr[], COORD clearSpaceSize)
{
    COORD clearCol = {frameSpaces, stickManVar.area.Y};
    int counter = 0;

    do
    {
        ClearArea(hStdOut, clearSpaceArr, clearSpaceSize, stickManVar.fillCoord, clearCol);
        stickManVar.fillCoord.X = stickManVar.fillCoord.X + frameSpaces;
        AddObject(hStdOut, rightOneArr, stickManVar.area, stickManVar.fillCoord);
        counter = counter + frameSpaces;
        Sleep(moveDuration);
        if (counter >= moveSpaces)
            break;

        ClearArea(hStdOut, clearSpaceArr, clearSpaceSize, stickManVar.fillCoord, clearCol);
        stickManVar.fillCoord.X = stickManVar.fillCoord.X + frameSpaces;
        AddObject(hStdOut, rightTwoArr, stickManVar.area, stickManVar.fillCoord);
        counter = counter + frameSpaces;
        Sleep(moveDuration);
        if (counter >= moveSpaces)
            break;

        ClearArea(hStdOut, clearSpaceArr, clearSpaceSize, stickManVar.fillCoord, clearCol);
        stickManVar.fillCoord.X = stickManVar.fillCoord.X + frameSpaces;
        AddObject(hStdOut, rightThreeArr, stickManVar.area, stickManVar.fillCoord);
        counter = counter + frameSpaces;
        Sleep(moveDuration);
        if (counter >= moveSpaces)
            break;

        ClearArea(hStdOut, clearSpaceArr, clearSpaceSize, stickManVar.fillCoord, clearCol);
        stickManVar.fillCoord.X = stickManVar.fillCoord.X + frameSpaces;
        AddObject(hStdOut, rightFourArr, stickManVar.area, stickManVar.fillCoord);
        counter = counter + frameSpaces;
        Sleep(moveDuration);
        if (counter >= moveSpaces)
            break;

    }
    while(true);

    AddObject(hStdOut, standRightArr, stickManVar.area, stickManVar.fillCoord);
    Sleep(moveDuration);

}

void MoveStickManInRandomDirection(HANDLE hStdOut, ObjectVariables& stickManVar, CHAR_INFO standLeftArr[], CHAR_INFO leftOneArr[], CHAR_INFO leftTwoArr[], CHAR_INFO leftThreeArr[], CHAR_INFO leftFourArr[],
                                   CHAR_INFO standRightArr[], CHAR_INFO rightOneArr[], CHAR_INFO rightTwoArr[], CHAR_INFO rightThreeArr[], CHAR_INFO rightFourArr[], int moveDuration, CHAR_INFO clearSpaceArr[], COORD clearSpaceSize)
{
    int frameSpaces = 0;
    int moveSpaces = 0;
    int moveDirection = 0;

    /**random frameSpaces, moveSpaces**/
    frameSpaces = rand() % 3 + 1;
    moveSpaces = (rand() % 10) + 10;

    /**change moveDirection if stickman walks off screen, otherwise random direction**/
    if (stickManVar.fillCoord.X >= clearSpaceSize.X * .65)
        moveDirection = 0;
    else if (stickManVar.fillCoord.X <= clearSpaceSize.X * .2)
        moveDirection = 1;
    else
        moveDirection = rand() % 2;

    /**stickman moves**/
    if (moveDirection == 0)
    {
        MoveStickManLeft(hStdOut, stickManVar, standLeftArr, leftOneArr, leftTwoArr, leftThreeArr, leftFourArr, frameSpaces, moveSpaces, moveDuration, clearSpaceArr, clearSpaceSize);
    }
    else if (moveDirection == 1)
    {
        MoveStickManRight(hStdOut, stickManVar, standRightArr, rightOneArr, rightTwoArr, rightThreeArr, rightFourArr, frameSpaces, moveSpaces, moveDuration, clearSpaceArr, clearSpaceSize);
    }
}

void JumpStickMan(HANDLE hStdOut, ObjectVariables& stickManVar, CHAR_INFO jumpOneArr[], CHAR_INFO jumpTwoArr[], CHAR_INFO standRightArr[], CHAR_INFO clearSpaceArr[], COORD clearSpaceSize)
{
    COORD clearArea = {stickManVar.area.X, 2};
    int sleepTime = 100;

    for (int i = 0; i < 2; ++i)
    {
        //squat
        AddObject(hStdOut, jumpOneArr, stickManVar.area, stickManVar.fillCoord);
        Sleep(sleepTime);

        //up from squat
        AddObject(hStdOut, jumpTwoArr, stickManVar.area, stickManVar.fillCoord);
        Sleep(sleepTime);

        //fly up
        ClearArea(hStdOut, clearSpaceArr, clearSpaceSize, (COORD)
        {
            stickManVar.fillCoord.X, stickManVar.fillCoord.Y + stickManVar.area.Y - 2
        }, clearArea);
        stickManVar.fillCoord.Y = stickManVar.fillCoord.Y - 2;
        AddObject(hStdOut, jumpTwoArr, stickManVar.area, stickManVar.fillCoord);
        Sleep(sleepTime);

        //fly up
        ClearArea(hStdOut, clearSpaceArr, clearSpaceSize, (COORD)
        {
            stickManVar.fillCoord.X, stickManVar.fillCoord.Y + stickManVar.area.Y - 2
        }, clearArea);
        stickManVar.fillCoord.Y = stickManVar.fillCoord.Y - 2;
        AddObject(hStdOut, jumpTwoArr, stickManVar.area, stickManVar.fillCoord);
        Sleep(sleepTime);

        //fall down
        ClearArea(hStdOut, clearSpaceArr, clearSpaceSize, stickManVar.fillCoord, clearArea);
        stickManVar.fillCoord.Y = stickManVar.fillCoord.Y + 2;
        AddObject(hStdOut, jumpTwoArr, stickManVar.area, stickManVar.fillCoord);
        Sleep(sleepTime);

        //fall down
        ClearArea(hStdOut, clearSpaceArr, clearSpaceSize, stickManVar.fillCoord, clearArea);
        stickManVar.fillCoord.Y = stickManVar.fillCoord.Y + 2;
        AddObject(hStdOut, jumpTwoArr, stickManVar.area, stickManVar.fillCoord);
        Sleep(sleepTime);
    }

    //squat
    AddObject(hStdOut, jumpOneArr, stickManVar.area, stickManVar.fillCoord);
    Sleep(sleepTime);

    //stand position
    AddObject(hStdOut, standRightArr, stickManVar.area, stickManVar.fillCoord);
    Sleep(sleepTime);

}

void ScratchHeadStickMan(HANDLE hStdOut, ObjectVariables& stickManVar, CHAR_INFO scratchHeadOneArr[], CHAR_INFO scratchHeadTwoArr[], CHAR_INFO scratchHeadThreeArr[], CHAR_INFO scratchHeadFourArr[], CHAR_INFO scratchHeadFiveArr[], CHAR_INFO standLeftArr[])
{
    int sleepTime = 150;

    AddObject(hStdOut, scratchHeadOneArr, stickManVar.area, stickManVar.fillCoord);
    Sleep(sleepTime);
    AddObject(hStdOut, scratchHeadTwoArr, stickManVar.area, stickManVar.fillCoord);
    Sleep(sleepTime);
    AddObject(hStdOut, scratchHeadThreeArr, stickManVar.area, stickManVar.fillCoord);
    Sleep(sleepTime);
    AddObject(hStdOut, scratchHeadFourArr, stickManVar.area, stickManVar.fillCoord);
    Sleep(sleepTime);
    AddObject(hStdOut, scratchHeadFiveArr, stickManVar.area, stickManVar.fillCoord);
    Sleep(sleepTime);
    AddObject(hStdOut, scratchHeadFourArr, stickManVar.area, stickManVar.fillCoord);
    Sleep(sleepTime);
    AddObject(hStdOut, scratchHeadFiveArr, stickManVar.area, stickManVar.fillCoord);
    Sleep(sleepTime);
    AddObject(hStdOut, scratchHeadFourArr, stickManVar.area, stickManVar.fillCoord);
    Sleep(sleepTime);
    AddObject(hStdOut, scratchHeadThreeArr, stickManVar.area, stickManVar.fillCoord);
    Sleep(sleepTime);
    AddObject(hStdOut, scratchHeadTwoArr, stickManVar.area, stickManVar.fillCoord);
    Sleep(sleepTime);
    AddObject(hStdOut, scratchHeadOneArr, stickManVar.area, stickManVar.fillCoord);
    Sleep(sleepTime);

    AddObject(hStdOut, standLeftArr, stickManVar.area, stickManVar.fillCoord);
}

void FlipLightSwitchStickMan(HANDLE hStdOut, ObjectVariables& stickManVar, CHAR_INFO lightSwitchOneArr[], CHAR_INFO lightSwitchTwoArr[], CHAR_INFO lightSwitchThreeArr[], CHAR_INFO lightSwitchFourArr[], CHAR_INFO standLeftArr[])
{
    int moveTime = 250;
    int flipTime = 250;

    AddObject(hStdOut, lightSwitchOneArr, stickManVar.area, stickManVar.fillCoord);
    Sleep(moveTime);
    AddObject(hStdOut, lightSwitchTwoArr, stickManVar.area, stickManVar.fillCoord);
    Sleep(moveTime);
    AddObject(hStdOut, lightSwitchThreeArr, stickManVar.area, stickManVar.fillCoord);
    Sleep(flipTime);
    AddObject(hStdOut, lightSwitchFourArr, stickManVar.area, stickManVar.fillCoord);
    Sleep(flipTime);
    AddObject(hStdOut, lightSwitchThreeArr, stickManVar.area, stickManVar.fillCoord);
    Sleep(flipTime);
    AddObject(hStdOut, lightSwitchFourArr, stickManVar.area, stickManVar.fillCoord);
    Sleep(flipTime);
    AddObject(hStdOut, lightSwitchThreeArr, stickManVar.area, stickManVar.fillCoord);
    Sleep(flipTime);
    //AddObject(hStdOut, lightSwitchTwoArr, stickManVar.area, stickManVar.fillCoord);
    //Sleep(moveTime);
    //AddObject(hStdOut, lightSwitchOneArr, stickManVar.area, stickManVar.fillCoord);
    //Sleep(moveTime);

    //AddObject(hStdOut, standLeftArr, stickManVar.area, stickManVar.fillCoord);
}

void CheckWatchStickMan(HANDLE hStdOut, ObjectVariables& stickManVar, CHAR_INFO checkWatchOneArr[], CHAR_INFO checkWatchTwoArr[], CHAR_INFO checkWatchThreeArr[])
{
    int standTime = 1000;
    int watchTime = 100;

    AddObject(hStdOut, checkWatchThreeArr, stickManVar.area, stickManVar.fillCoord);
    Sleep(standTime);
    AddObject(hStdOut, checkWatchOneArr, stickManVar.area, stickManVar.fillCoord);
    Sleep(watchTime);
    AddObject(hStdOut, checkWatchTwoArr, stickManVar.area, stickManVar.fillCoord);
    Sleep(standTime);
    AddObject(hStdOut, checkWatchOneArr, stickManVar.area, stickManVar.fillCoord);
    Sleep(watchTime);
    AddObject(hStdOut, checkWatchThreeArr, stickManVar.area, stickManVar.fillCoord);
    Sleep(standTime);
}

void MoveToTreeLocationStickMan(HANDLE hStdOut, ObjectVariables& stickManVar, ObjectVariables& treeVar, CHAR_INFO standLeftArr[], CHAR_INFO leftOneArr[], CHAR_INFO leftTwoArr[], CHAR_INFO leftThreeArr[], CHAR_INFO leftFourArr[],
                                CHAR_INFO rightOneArr[], CHAR_INFO rightTwoArr[], CHAR_INFO rightThreeArr[], CHAR_INFO rightFourArr[], CHAR_INFO clearSpaceArr[], COORD clearSpaceSize)
{
    int moveDuration = 100;
    int waitTime = 500;

    /**move stick man to location of tree**/
    if (stickManVar.fillCoord.X > treeVar.fillCoord.X + 10) //move stick man left
    {
        MoveStickManLeft(hStdOut, stickManVar, standLeftArr, leftOneArr, leftTwoArr, leftThreeArr, leftFourArr,
                         1, stickManVar.fillCoord.X - (treeVar.fillCoord.X + 10), moveDuration, clearSpaceArr, clearSpaceSize);
    }
    else if (stickManVar.fillCoord.X < treeVar.fillCoord.X + 10) //move stick man right
    {
        MoveStickManRight(hStdOut, stickManVar, standLeftArr, rightOneArr, rightTwoArr, rightThreeArr, rightFourArr,
                          1, treeVar.fillCoord.X + 10 - stickManVar.fillCoord.X, moveDuration, clearSpaceArr, clearSpaceSize);
    }

    Sleep(waitTime);
}

void HungerStickMan(HANDLE hStdOut, ObjectVariables& stickManVar, CHAR_INFO hungerOneArr[], CHAR_INFO hungerTwoArr[], CHAR_INFO standArr[])
{
    Sleep(1000);
    AddObject(hStdOut, hungerOneArr, stickManVar.area, stickManVar.fillCoord);
    Sleep(150);
    AddObject(hStdOut, hungerTwoArr, stickManVar.area, stickManVar.fillCoord);
    Sleep(2000);
    AddObject(hStdOut, hungerOneArr, stickManVar.area, stickManVar.fillCoord);
    Sleep(150);
    AddObject(hStdOut, standArr, stickManVar.area, stickManVar.fillCoord);
    Sleep(1000);
}

void PlantTreeStickMan(HANDLE hStdOut, ObjectVariables& stickManVar, ObjectVariables& treeVar, CHAR_INFO plantTreeOneArr[], CHAR_INFO plantTreeTwoArr[],
                       CHAR_INFO plantTreeThreeArr[], CHAR_INFO plantTreeFourArr[], CHAR_INFO plantTreeFiveArr[], CHAR_INFO standLeftArr[])
{
    int sleepTime = 150;
    int waitTime = 500;

    /**stick man plants tree**/
    AddObject(hStdOut, plantTreeOneArr, stickManVar.area, stickManVar.fillCoord);
    Sleep(sleepTime);
    AddObject(hStdOut, plantTreeTwoArr, stickManVar.area, stickManVar.fillCoord);
    Sleep(sleepTime);
    AddObject(hStdOut, plantTreeThreeArr, stickManVar.area, stickManVar.fillCoord);
    Sleep(sleepTime);
    AddObject(hStdOut, plantTreeFourArr, stickManVar.area, stickManVar.fillCoord);
    Sleep(sleepTime);

    AddObject(hStdOut, plantTreeFiveArr, stickManVar.area, stickManVar.fillCoord);
    Sleep(waitTime);

    AddObject(hStdOut, plantTreeFourArr, stickManVar.area, stickManVar.fillCoord);
    Sleep(sleepTime);
    AddObject(hStdOut, plantTreeThreeArr, stickManVar.area, stickManVar.fillCoord);
    Sleep(sleepTime);
    AddObject(hStdOut, plantTreeTwoArr, stickManVar.area, stickManVar.fillCoord);
    Sleep(sleepTime);
    AddObject(hStdOut, plantTreeOneArr, stickManVar.area, stickManVar.fillCoord);
    Sleep(sleepTime);

    AddObject(hStdOut, standLeftArr, stickManVar.area, stickManVar.fillCoord);
    Sleep(waitTime);
}

void GrabFruitStickMan(HANDLE hStdOut, ObjectVariables& stickManVar, CHAR_INFO grabFruitOneArr[], CHAR_INFO grabFruitTwoArr[], CHAR_INFO grabFruitThreeArr[],
                       CHAR_INFO grabFruitFourArr[], CHAR_INFO grabFruitFiveArr[], CHAR_INFO clearSpaceArr[], COORD clearSpaceSize)
{
    int sleepTime = 150;

    AddObject(hStdOut, grabFruitOneArr, stickManVar.area, stickManVar.fillCoord);
    Sleep(sleepTime);
    AddObject(hStdOut, grabFruitTwoArr, stickManVar.area, stickManVar.fillCoord);
    Sleep(sleepTime);
    AddObject(hStdOut, grabFruitThreeArr, stickManVar.area, stickManVar.fillCoord);
    Sleep(sleepTime);
    AddObject(hStdOut, grabFruitFourArr, stickManVar.area, stickManVar.fillCoord);
    Sleep(sleepTime);
    AddObject(hStdOut, grabFruitFiveArr, stickManVar.area, stickManVar.fillCoord);
    Sleep(sleepTime);
    ClearArea(hStdOut, clearSpaceArr, clearSpaceSize, (COORD)
    {
        stickManVar.fillCoord.X - 1, stickManVar.fillCoord.Y + 1
    }, (COORD)
    {
        1, 1
    });
    AddObject(hStdOut, grabFruitFourArr, stickManVar.area, stickManVar.fillCoord);
    Sleep(sleepTime);
}

void EatFruitStickMan(HANDLE hStdOut, ObjectVariables& stickManVar, CHAR_INFO eatFruitOneArr[], CHAR_INFO eatFruitTwoArr[], CHAR_INFO eatFruitThreeArr[], CHAR_INFO eatFruitFourArr[], CHAR_INFO eatFruitFiveArr[], CHAR_INFO eatFruitSixArr[], CHAR_INFO standLeftArr[])
{
    int sleepTime = 150;
    int waitTime = 1000;

    AddObject(hStdOut, eatFruitOneArr, stickManVar.area, stickManVar.fillCoord);
    Sleep(sleepTime);
    AddObject(hStdOut, eatFruitTwoArr, stickManVar.area, stickManVar.fillCoord);
    Sleep(sleepTime);
    AddObject(hStdOut, eatFruitThreeArr, stickManVar.area, stickManVar.fillCoord);
    Sleep(sleepTime);
    AddObject(hStdOut, eatFruitTwoArr, stickManVar.area, stickManVar.fillCoord);
    Sleep(sleepTime);
    AddObject(hStdOut, eatFruitThreeArr, stickManVar.area, stickManVar.fillCoord);
    Sleep(sleepTime);
    AddObject(hStdOut, eatFruitTwoArr, stickManVar.area, stickManVar.fillCoord);
    Sleep(sleepTime);
    AddObject(hStdOut, eatFruitFourArr, stickManVar.area, stickManVar.fillCoord);
    Sleep(sleepTime);
    AddObject(hStdOut, eatFruitFiveArr, stickManVar.area, stickManVar.fillCoord);
    Sleep(sleepTime);
    AddObject(hStdOut, eatFruitSixArr, stickManVar.area, stickManVar.fillCoord);
    Sleep(sleepTime);
    AddObject(hStdOut, standLeftArr, stickManVar.area, stickManVar.fillCoord);
    Sleep(waitTime);
}

void LightSaberStickMan(HANDLE hStdOut, ObjectVariables& stickManLightSaberVar, ObjectVariables& stickManVar, CHAR_INFO lightSaber1Arr[], CHAR_INFO lightSaber2Arr[], CHAR_INFO lightSaber3Arr[], CHAR_INFO lightSaber4Arr[], CHAR_INFO lightSaber5Arr[],
                        CHAR_INFO lightSaber6Arr[], CHAR_INFO lightSaber7Arr[], CHAR_INFO lightSaber8Arr[], CHAR_INFO lightSaber9Arr[], CHAR_INFO lightSaber10Arr[], CHAR_INFO lightSaber11Arr[], CHAR_INFO lightSaber12Arr[], CHAR_INFO lightSaber13Arr[],
                        CHAR_INFO lightSaber14Arr[], CHAR_INFO lightSaber15Arr[], CHAR_INFO lightSaber16Arr[], CHAR_INFO lightSaber17Arr[], CHAR_INFO lightSaber18Arr[], CHAR_INFO lightSaber19Arr[], CHAR_INFO lightSaber20Arr[],
                        CHAR_INFO lightSaber21Arr[], CHAR_INFO lightSaber22Arr[], CHAR_INFO lightSaber23Arr[], CHAR_INFO lightSaber24Arr[], ObjectVariables& swordHandleVar, CHAR_INFO swordHandleArr[], CHAR_INFO standRightArr[],
                        CHAR_INFO clearSpaceArr[], COORD clearSpaceSize)
{
    int waitTime = 1000;
    int sleepTime = 100;

    stickManLightSaberVar.fillCoord.X = stickManVar.fillCoord.X - 12;
    stickManLightSaberVar.fillCoord.Y = stickManVar.fillCoord.Y - 5;
    swordHandleVar.fillCoord.X = stickManVar.fillCoord.X + 30;
    swordHandleVar.fillCoord.Y = stickManVar.fillCoord.Y + 2;

    //AddObject(hStdOut, standRightArr, stickManVar.area, stickManVar.fillCoord);
    AddObject(hStdOut, swordHandleArr, swordHandleVar.area, swordHandleVar.fillCoord);
    Sleep(1000);

    /**raise hand to pull lightsaber**/
    AddObject(hStdOut, lightSaber1Arr, stickManLightSaberVar.area, stickManLightSaberVar.fillCoord);
    Sleep(sleepTime);
    AddObject(hStdOut, lightSaber2Arr, stickManLightSaberVar.area, stickManLightSaberVar.fillCoord);
    Sleep(sleepTime);
    AddObject(hStdOut, lightSaber17Arr, stickManLightSaberVar.area, stickManLightSaberVar.fillCoord);
    Sleep(sleepTime);
    AddObject(hStdOut, lightSaber18Arr, stickManLightSaberVar.area, stickManLightSaberVar.fillCoord);
    Sleep(sleepTime);
    AddObject(hStdOut, lightSaber19Arr, stickManLightSaberVar.area, stickManLightSaberVar.fillCoord);
    Sleep(waitTime * .75);

    /**lightsaber moves to stick man**/
    for (int i = 0; i < (swordHandleVar.fillCoord.X - (stickManVar.fillCoord.X - 4)); ++i)
    {
        ClearArea(hStdOut, clearSpaceArr, clearSpaceSize, swordHandleVar.fillCoord, swordHandleVar.area);
        swordHandleVar.fillCoord.X--;
        AddObject(hStdOut, swordHandleArr, swordHandleVar.area, swordHandleVar.fillCoord);
        Sleep(50);
    }
    ClearArea(hStdOut, clearSpaceArr, clearSpaceSize, swordHandleVar.fillCoord, swordHandleVar.area);


    AddObject(hStdOut, lightSaber20Arr, stickManLightSaberVar.area, stickManLightSaberVar.fillCoord);
    Sleep(waitTime * .75);
    AddObject(hStdOut, lightSaber21Arr, stickManLightSaberVar.area, stickManLightSaberVar.fillCoord);
    Sleep(sleepTime);
    AddObject(hStdOut, lightSaber22Arr, stickManLightSaberVar.area, stickManLightSaberVar.fillCoord);
    Sleep(sleepTime);
    AddObject(hStdOut, lightSaber23Arr, stickManLightSaberVar.area, stickManLightSaberVar.fillCoord);
    Sleep(sleepTime);
    AddObject(hStdOut, lightSaber24Arr, stickManLightSaberVar.area, stickManLightSaberVar.fillCoord);
    Sleep(waitTime);
    AddObject(hStdOut, lightSaber9Arr, stickManLightSaberVar.area, stickManLightSaberVar.fillCoord);
    Sleep(sleepTime);
    AddObject(hStdOut, lightSaber10Arr, stickManLightSaberVar.area, stickManLightSaberVar.fillCoord);
    Sleep(sleepTime);
    AddObject(hStdOut, lightSaber11Arr, stickManLightSaberVar.area, stickManLightSaberVar.fillCoord);
    Sleep(waitTime);
    AddObject(hStdOut, lightSaber10Arr, stickManLightSaberVar.area, stickManLightSaberVar.fillCoord);
    Sleep(sleepTime);
    AddObject(hStdOut, lightSaber9Arr, stickManLightSaberVar.area, stickManLightSaberVar.fillCoord);
    Sleep(sleepTime);
    AddObject(hStdOut, lightSaber8Arr, stickManLightSaberVar.area, stickManLightSaberVar.fillCoord);
    Sleep(waitTime);
    AddObject(hStdOut, lightSaber12Arr, stickManLightSaberVar.area, stickManLightSaberVar.fillCoord);
    Sleep(sleepTime);
    AddObject(hStdOut, lightSaber13Arr, stickManLightSaberVar.area, stickManLightSaberVar.fillCoord);
    Sleep(sleepTime * .75);
    AddObject(hStdOut, lightSaber15Arr, stickManLightSaberVar.area, stickManLightSaberVar.fillCoord);
    Sleep(sleepTime * .75);
    AddObject(hStdOut, lightSaber16Arr, stickManLightSaberVar.area, stickManLightSaberVar.fillCoord);
    Sleep(waitTime * 1.5);
    AddObject(hStdOut, lightSaber15Arr, stickManLightSaberVar.area, stickManLightSaberVar.fillCoord);
    Sleep(sleepTime * .75);
    AddObject(hStdOut, lightSaber13Arr, stickManLightSaberVar.area, stickManLightSaberVar.fillCoord);
    Sleep(sleepTime * .75);
    AddObject(hStdOut, lightSaber12Arr, stickManLightSaberVar.area, stickManLightSaberVar.fillCoord);
    Sleep(sleepTime);
    AddObject(hStdOut, lightSaber8Arr, stickManLightSaberVar.area, stickManLightSaberVar.fillCoord);
    Sleep(waitTime);
    AddObject(hStdOut, lightSaber7Arr, stickManLightSaberVar.area, stickManLightSaberVar.fillCoord);
    Sleep(sleepTime);
    AddObject(hStdOut, lightSaber6Arr, stickManLightSaberVar.area, stickManLightSaberVar.fillCoord);
    Sleep(waitTime * .5);
    AddObject(hStdOut, lightSaber5Arr, stickManLightSaberVar.area, stickManLightSaberVar.fillCoord);
    Sleep(sleepTime);
    AddObject(hStdOut, lightSaber4Arr, stickManLightSaberVar.area, stickManLightSaberVar.fillCoord);
    Sleep(sleepTime);
    AddObject(hStdOut, lightSaber3Arr, stickManLightSaberVar.area, stickManLightSaberVar.fillCoord);
    Sleep(waitTime * .5);
    AddObject(hStdOut, lightSaber2Arr, stickManLightSaberVar.area, stickManLightSaberVar.fillCoord);
    Sleep(sleepTime);
    AddObject(hStdOut, lightSaber1Arr, stickManLightSaberVar.area, stickManLightSaberVar.fillCoord);
    Sleep(sleepTime);
    AddObject(hStdOut, standRightArr, stickManVar.area, stickManVar.fillCoord);
    Sleep(1000);
}

void CallDogStickMan(HANDLE hStdOut, ObjectVariables& stickManVar, CHAR_INFO callDog1Arr[], CHAR_INFO callDog2Arr[], CHAR_INFO callDog3Arr[], CHAR_INFO callDog4Arr[],
                     CHAR_INFO callDog5Arr[], CHAR_INFO callDog6Arr[], CHAR_INFO callDog7Arr[], CHAR_INFO standRightArr[])
{
    int sleepTime = 150;
    int waitTime = 500;

    AddObject(hStdOut, standRightArr, stickManVar.area, stickManVar.fillCoord);
    Sleep(1000);

    AddObject(hStdOut, callDog1Arr, stickManVar.area, stickManVar.fillCoord);
    Sleep(sleepTime);
    AddObject(hStdOut, callDog2Arr, stickManVar.area, stickManVar.fillCoord);
    Sleep(sleepTime);
    AddObject(hStdOut, callDog3Arr, stickManVar.area, stickManVar.fillCoord);
    Sleep(sleepTime);
    AddObject(hStdOut, callDog4Arr, stickManVar.area, stickManVar.fillCoord);
    Sleep(waitTime * 1.5);
    AddObject(hStdOut, callDog5Arr, stickManVar.area, stickManVar.fillCoord);
    Sleep(sleepTime);
    AddObject(hStdOut, callDog6Arr, stickManVar.area, stickManVar.fillCoord);
    Sleep(sleepTime);
    AddObject(hStdOut, callDog7Arr, stickManVar.area, stickManVar.fillCoord);
    Sleep(sleepTime);
    AddObject(hStdOut, callDog6Arr, stickManVar.area, stickManVar.fillCoord);
    Sleep(sleepTime);
    AddObject(hStdOut, callDog5Arr, stickManVar.area, stickManVar.fillCoord);
    Sleep(sleepTime);
    AddObject(hStdOut, callDog6Arr, stickManVar.area, stickManVar.fillCoord);
    Sleep(sleepTime);
    AddObject(hStdOut, callDog7Arr, stickManVar.area, stickManVar.fillCoord);
    Sleep(sleepTime);
    AddObject(hStdOut, callDog6Arr, stickManVar.area, stickManVar.fillCoord);
    Sleep(sleepTime);
    AddObject(hStdOut, callDog5Arr, stickManVar.area, stickManVar.fillCoord);
    Sleep(sleepTime);
    AddObject(hStdOut, callDog3Arr, stickManVar.area, stickManVar.fillCoord);
    Sleep(sleepTime);
    AddObject(hStdOut, callDog2Arr, stickManVar.area, stickManVar.fillCoord);
    Sleep(sleepTime);
    AddObject(hStdOut, callDog1Arr, stickManVar.area, stickManVar.fillCoord);
    Sleep(sleepTime);

    AddObject(hStdOut, standRightArr, stickManVar.area, stickManVar.fillCoord);
    Sleep(waitTime);
}

void PetDogStickMan(HANDLE hStdOut, ObjectVariables& stickManVar, CHAR_INFO callDog8Arr[], CHAR_INFO callDog9Arr[], CHAR_INFO callDog10Arr[], CHAR_INFO callDog11Arr[])
{
    int sleepTime = 150;
    int waitTime = 500;

    AddObject(hStdOut, callDog8Arr, stickManVar.area, stickManVar.fillCoord);
    Sleep(waitTime);
    AddObject(hStdOut, callDog9Arr, stickManVar.area, stickManVar.fillCoord);
    Sleep(sleepTime);
    AddObject(hStdOut, callDog10Arr, stickManVar.area, stickManVar.fillCoord);
    Sleep(waitTime);
    AddObject(hStdOut, callDog11Arr, stickManVar.area, stickManVar.fillCoord);
    Sleep(sleepTime);
    AddObject(hStdOut, callDog10Arr, stickManVar.area, stickManVar.fillCoord);
    Sleep(sleepTime);
    AddObject(hStdOut, callDog11Arr, stickManVar.area, stickManVar.fillCoord);
    Sleep(sleepTime);
    AddObject(hStdOut, callDog10Arr, stickManVar.area, stickManVar.fillCoord);
    Sleep(sleepTime);
}

void RandomStickManColor(ObjectVariables& stickManVar, CHAR_INFO standLeftArr[], CHAR_INFO leftOneArr[], CHAR_INFO leftTwoArr[], CHAR_INFO leftThreeArr[], CHAR_INFO leftFourArr[], CHAR_INFO standRightArr[], CHAR_INFO rightOneArr[], CHAR_INFO rightTwoArr[], CHAR_INFO rightThreeArr[], CHAR_INFO rightFourArr[],
                         string standLeft, string leftOne, string leftTwo, string leftThree, string leftFour, string standRight, string rightOne, string rightTwo, string rightThree, string rightFour)
{
    int temp = stickManVar.color;

    do
    {
        stickManVar.color = RandomTextColor();
    }
    while (stickManVar.color == temp);

    FillObjectCharArray(standLeft, standLeftArr, stickManVar);
    FillObjectCharArray(leftOne, leftOneArr, stickManVar);
    FillObjectCharArray(leftTwo, leftTwoArr, stickManVar);
    FillObjectCharArray(leftThree, leftThreeArr, stickManVar);
    FillObjectCharArray(leftFour, leftFourArr, stickManVar);

    FillObjectCharArray(standRight, standRightArr, stickManVar);
    FillObjectCharArray(rightOne, rightOneArr, stickManVar);
    FillObjectCharArray(rightTwo, rightTwoArr, stickManVar);
    FillObjectCharArray(rightThree, rightThreeArr, stickManVar);
    FillObjectCharArray(rightFour, rightFourArr, stickManVar);
}

void MoveDogLeft(HANDLE hStdOut, ObjectVariables& dogVar, CHAR_INFO dogOneArr[], CHAR_INFO dogTwoArr[], CHAR_INFO dogThreeArr[], CHAR_INFO dogFourArr[],
                 CHAR_INFO dogFiveArr[], int frameSpaces, int moveSpaces, int moveDuration, CHAR_INFO clearSpaceArr[], COORD clearSpaceSize)
{
    COORD clearCol = {frameSpaces, dogVar.area.Y};
    int counter = 0;

    do
    {
        ClearArea(hStdOut, clearSpaceArr, clearSpaceSize, (COORD)
        {
            dogVar.fillCoord.X + dogVar.area.X - frameSpaces, dogVar.fillCoord.Y
        }, clearCol);
        dogVar.fillCoord.X = dogVar.fillCoord.X - frameSpaces;
        AddObject(hStdOut, dogTwoArr, dogVar.area, dogVar.fillCoord);
        counter = counter + frameSpaces;
        Sleep(moveDuration);
        if (counter >= moveSpaces)
            break;

        ClearArea(hStdOut, clearSpaceArr, clearSpaceSize, (COORD)
        {
            dogVar.fillCoord.X + dogVar.area.X - frameSpaces, dogVar.fillCoord.Y
        }, clearCol);
        dogVar.fillCoord.X = dogVar.fillCoord.X - frameSpaces;
        AddObject(hStdOut, dogThreeArr, dogVar.area, dogVar.fillCoord);
        counter = counter + frameSpaces;
        Sleep(moveDuration);
        if (counter >= moveSpaces)
            break;

        ClearArea(hStdOut, clearSpaceArr, clearSpaceSize, (COORD)
        {
            dogVar.fillCoord.X + dogVar.area.X - frameSpaces, dogVar.fillCoord.Y
        }, clearCol);
        dogVar.fillCoord.X = dogVar.fillCoord.X - frameSpaces;
        AddObject(hStdOut, dogFourArr, dogVar.area, dogVar.fillCoord);
        counter = counter + frameSpaces;
        Sleep(moveDuration);
        if (counter >= moveSpaces)
            break;

        ClearArea(hStdOut, clearSpaceArr, clearSpaceSize, (COORD)
        {
            dogVar.fillCoord.X + dogVar.area.X - frameSpaces, dogVar.fillCoord.Y
        }, clearCol);
        dogVar.fillCoord.X = dogVar.fillCoord.X - frameSpaces;
        AddObject(hStdOut, dogFiveArr, dogVar.area, dogVar.fillCoord);
        counter = counter + frameSpaces;
        Sleep(moveDuration);
        if (counter >= moveSpaces)
            break;

    }
    while(true);

    AddObject(hStdOut, dogOneArr, dogVar.area, dogVar.fillCoord);
    Sleep(moveDuration);

}

void MoveDogRight(HANDLE hStdOut, ObjectVariables& dogVar, CHAR_INFO dogStandRightArr[], CHAR_INFO dogRight1Arr[], CHAR_INFO dogRight2Arr[], CHAR_INFO dogRight3Arr[],
                  CHAR_INFO dogRight4Arr[], int frameSpaces, int moveSpaces, int moveDuration, CHAR_INFO clearSpaceArr[], COORD clearSpaceSize)
{
    COORD clearCol = {frameSpaces, dogVar.area.Y};
    int counter = 0;

    do
    {
        ClearArea(hStdOut, clearSpaceArr, clearSpaceSize, dogVar.fillCoord, clearCol);
        dogVar.fillCoord.X = dogVar.fillCoord.X + frameSpaces;
        AddObject(hStdOut, dogRight1Arr, dogVar.area, dogVar.fillCoord);
        counter = counter + frameSpaces;
        Sleep(moveDuration);
        if (counter >= moveSpaces)
            break;

        ClearArea(hStdOut, clearSpaceArr, clearSpaceSize, dogVar.fillCoord, clearCol);
        dogVar.fillCoord.X = dogVar.fillCoord.X + frameSpaces;
        AddObject(hStdOut, dogRight2Arr, dogVar.area, dogVar.fillCoord);
        counter = counter + frameSpaces;
        Sleep(moveDuration);
        if (counter >= moveSpaces)
            break;

        ClearArea(hStdOut, clearSpaceArr, clearSpaceSize, dogVar.fillCoord, clearCol);
        dogVar.fillCoord.X = dogVar.fillCoord.X + frameSpaces;
        AddObject(hStdOut, dogRight3Arr, dogVar.area, dogVar.fillCoord);
        counter = counter + frameSpaces;
        Sleep(moveDuration);
        if (counter >= moveSpaces)
            break;

        ClearArea(hStdOut, clearSpaceArr, clearSpaceSize, dogVar.fillCoord, clearCol);
        dogVar.fillCoord.X = dogVar.fillCoord.X + frameSpaces;
        AddObject(hStdOut, dogRight4Arr, dogVar.area, dogVar.fillCoord);
        counter = counter + frameSpaces;
        Sleep(moveDuration);
        if (counter >= moveSpaces)
            break;

    }
    while(true);

    AddObject(hStdOut, dogStandRightArr, dogVar.area, dogVar.fillCoord);
    Sleep(moveDuration);

}

void DogJump(HANDLE hStdOut, ObjectVariables& dogVar, ObjectVariables& stickManVar, CHAR_INFO dogJump1Arr[], CHAR_INFO dogJump2Arr[], CHAR_INFO dogStandLeftArr[],
                 CHAR_INFO callDog14Arr[], CHAR_INFO clearSpaceArr[], COORD clearSpaceSize)
{
    int sleepTime = 150;
    COORD clearSize = {dogVar.area.X, 1};

    AddObject(hStdOut, dogJump1Arr, dogVar.area, dogVar.fillCoord);
    Sleep(500);

    for (int i = 0; i < 2; ++i)
    {
        ClearArea(hStdOut, clearSpaceArr, clearSpaceSize, (COORD)
        {
            dogVar.fillCoord.X, dogVar.fillCoord.Y + dogVar.area.Y - 1
        }, clearSize);
        dogVar.fillCoord.Y = dogVar.fillCoord.Y - 1;
        AddObject(hStdOut, dogJump2Arr, dogVar.area, dogVar.fillCoord);
        Sleep(sleepTime * .65);

        ClearArea(hStdOut, clearSpaceArr, clearSpaceSize, (COORD)
        {
            dogVar.fillCoord.X, dogVar.fillCoord.Y + dogVar.area.Y - 1
        }, clearSize);
        dogVar.fillCoord.Y = dogVar.fillCoord.Y - 1;
        AddObject(hStdOut, dogJump2Arr, dogVar.area, dogVar.fillCoord);
        AddObject(hStdOut, callDog14Arr, stickManVar.area, stickManVar.fillCoord);
        Sleep(sleepTime * .65);

        ClearArea(hStdOut, clearSpaceArr, clearSpaceSize, dogVar.fillCoord, clearSize);
        dogVar.fillCoord.Y = dogVar.fillCoord.Y + 1;
        AddObject(hStdOut, dogJump2Arr, dogVar.area, dogVar.fillCoord);
        AddObject(hStdOut, callDog14Arr, stickManVar.area, stickManVar.fillCoord);
        Sleep(sleepTime * .65);

        ClearArea(hStdOut, clearSpaceArr, clearSpaceSize, dogVar.fillCoord, clearSize);
        dogVar.fillCoord.Y = dogVar.fillCoord.Y + 1;
        AddObject(hStdOut, dogJump2Arr, dogVar.area, dogVar.fillCoord);
        Sleep(sleepTime * .65);

        AddObject(hStdOut, dogJump1Arr, dogVar.area, dogVar.fillCoord);
        Sleep(500);
    }

    AddObject(hStdOut, dogStandLeftArr, dogVar.area, dogVar.fillCoord);
    Sleep(sleepTime);
}

void DogWagsTail(HANDLE hStdOut, ObjectVariables& dogVar, CHAR_INFO dogOneArr[], CHAR_INFO dogWagTailOneArr[], int wagTimes)
{
    for (int i = 0; i < wagTimes; ++i)
    {
        AddObject(hStdOut, dogWagTailOneArr, dogVar.area, dogVar.fillCoord);
        Sleep(100);
        AddObject(hStdOut, dogOneArr, dogVar.area, dogVar.fillCoord);
        Sleep(100);

    }
}

void TreeGrow(HANDLE hStdOut, ObjectVariables& treeVar, CHAR_INFO tree1Arr[], CHAR_INFO tree2Arr[], CHAR_INFO tree3Arr[], CHAR_INFO tree4Arr[], CHAR_INFO tree5Arr[], CHAR_INFO tree6Arr[], CHAR_INFO tree7Arr[], CHAR_INFO tree8Arr[], CHAR_INFO tree9Arr[], CHAR_INFO tree10Arr[],
              CHAR_INFO tree11Arr[], CHAR_INFO tree12Arr[], CHAR_INFO tree13Arr[], CHAR_INFO tree14Arr[], CHAR_INFO tree15Arr[], CHAR_INFO tree16Arr[], CHAR_INFO tree17Arr[], CHAR_INFO tree18Arr[], CHAR_INFO tree19Arr[], CHAR_INFO tree20Arr[], CHAR_INFO tree21Arr[], CHAR_INFO tree22Arr[],
              CHAR_INFO tree23Arr[], CHAR_INFO tree24Arr[], CHAR_INFO tree25Arr[], CHAR_INFO tree26Arr[], CHAR_INFO tree27Arr[], CHAR_INFO tree28Arr[], CHAR_INFO tree29Arr[], CHAR_INFO tree30Arr[], CHAR_INFO tree31Arr[], CHAR_INFO tree32Arr[], CHAR_INFO tree33Arr[], CHAR_INFO tree34Arr[],
              CHAR_INFO tree35Arr[], CHAR_INFO tree36Arr[], CHAR_INFO tree37Arr[], CHAR_INFO tree38Arr[], CHAR_INFO tree39Arr[], CHAR_INFO tree40Arr[])
{
    int fastTime = 150;
    int slowTime = 250;
    int waitTime = 1000;

    AddObject(hStdOut, tree1Arr, treeVar.area, treeVar.fillCoord);
    Sleep(fastTime);
    AddObject(hStdOut, tree2Arr, treeVar.area, treeVar.fillCoord);
    Sleep(fastTime);
    AddObject(hStdOut, tree3Arr, treeVar.area, treeVar.fillCoord);
    Sleep(fastTime);
    AddObject(hStdOut, tree4Arr, treeVar.area, treeVar.fillCoord);
    Sleep(fastTime);
    AddObject(hStdOut, tree5Arr, treeVar.area, treeVar.fillCoord);
    Sleep(fastTime);
    AddObject(hStdOut, tree6Arr, treeVar.area, treeVar.fillCoord);
    Sleep(fastTime);
    AddObject(hStdOut, tree7Arr, treeVar.area, treeVar.fillCoord);
    Sleep(fastTime);
    AddObject(hStdOut, tree8Arr, treeVar.area, treeVar.fillCoord);
    Sleep(fastTime);
    AddObject(hStdOut, tree9Arr, treeVar.area, treeVar.fillCoord);
    Sleep(fastTime);
    AddObject(hStdOut, tree10Arr, treeVar.area, treeVar.fillCoord);
    Sleep(fastTime);
    AddObject(hStdOut, tree11Arr, treeVar.area, treeVar.fillCoord);
    Sleep(fastTime);
    AddObject(hStdOut, tree12Arr, treeVar.area, treeVar.fillCoord);
    Sleep(fastTime);
    AddObject(hStdOut, tree13Arr, treeVar.area, treeVar.fillCoord);
    Sleep(fastTime);
    AddObject(hStdOut, tree14Arr, treeVar.area, treeVar.fillCoord);
    Sleep(fastTime);
    AddObject(hStdOut, tree15Arr, treeVar.area, treeVar.fillCoord);
    Sleep(fastTime);
    AddObject(hStdOut, tree16Arr, treeVar.area, treeVar.fillCoord);
    Sleep(fastTime);
    AddObject(hStdOut, tree17Arr, treeVar.area, treeVar.fillCoord);
    Sleep(fastTime);
    AddObject(hStdOut, tree18Arr, treeVar.area, treeVar.fillCoord);
    Sleep(fastTime);
    AddObject(hStdOut, tree19Arr, treeVar.area, treeVar.fillCoord);
    Sleep(fastTime);
    AddObject(hStdOut, tree20Arr, treeVar.area, treeVar.fillCoord);
    Sleep(fastTime);
    AddObject(hStdOut, tree21Arr, treeVar.area, treeVar.fillCoord);
    Sleep(fastTime);
    AddObject(hStdOut, tree22Arr, treeVar.area, treeVar.fillCoord);
    Sleep(slowTime);
    AddObject(hStdOut, tree23Arr, treeVar.area, treeVar.fillCoord);
    Sleep(slowTime);
    AddObject(hStdOut, tree24Arr, treeVar.area, treeVar.fillCoord);
    Sleep(slowTime);
    AddObject(hStdOut, tree25Arr, treeVar.area, treeVar.fillCoord);
    Sleep(slowTime);
    AddObject(hStdOut, tree26Arr, treeVar.area, treeVar.fillCoord);
    Sleep(slowTime);
    AddObject(hStdOut, tree27Arr, treeVar.area, treeVar.fillCoord);
    Sleep(slowTime);
    AddObject(hStdOut, tree28Arr, treeVar.area, treeVar.fillCoord);
    Sleep(slowTime);
    AddObject(hStdOut, tree29Arr, treeVar.area, treeVar.fillCoord);
    Sleep(slowTime);
    AddObject(hStdOut, tree30Arr, treeVar.area, treeVar.fillCoord);
    Sleep(slowTime);
    AddObject(hStdOut, tree31Arr, treeVar.area, treeVar.fillCoord);
    Sleep(slowTime);
    AddObject(hStdOut, tree32Arr, treeVar.area, treeVar.fillCoord);
    Sleep(slowTime);
    AddObject(hStdOut, tree33Arr, treeVar.area, treeVar.fillCoord);
    Sleep(slowTime);
    AddObject(hStdOut, tree34Arr, treeVar.area, treeVar.fillCoord);
    Sleep(slowTime);
    AddObject(hStdOut, tree35Arr, treeVar.area, treeVar.fillCoord);
    Sleep(slowTime);
    AddObject(hStdOut, tree36Arr, treeVar.area, treeVar.fillCoord);
    Sleep(slowTime);
    AddObject(hStdOut, tree37Arr, treeVar.area, treeVar.fillCoord);
    Sleep(slowTime);
    AddObject(hStdOut, tree38Arr, treeVar.area, treeVar.fillCoord);
    Sleep(slowTime);
    AddObject(hStdOut, tree39Arr, treeVar.area, treeVar.fillCoord);
    Sleep(slowTime);
    AddObject(hStdOut, tree40Arr, treeVar.area, treeVar.fillCoord);
    Sleep(waitTime);
}

/****************************************************************/
/**Stickman center axis (torso) is X coord position 6 (index 5)**/
/****************************************************************/

void FillStandLeft(string& stickMan)
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
}

void FillStandRight(string& stickMan)
{
    string stickMan9 = "     _     "; //x = 11; y = 10
    string stickMan8 = "    (\")    ";
    string stickMan7 = "    o-o    ";
    string stickMan6 = "   / | \\   ";
    string stickMan5 = "   \\ | /   ";
    string stickMan4 = "    O-O    ";
    string stickMan3 = "    | \\    ";
    string stickMan2 = "    o  o   ";
    string stickMan1 = "    | /    ";
    string stickMan0 = "    O Oo   ";

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
}

void FillLeftOne(string& stickMan)
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
}

void FillRightOne(string& stickMan)
{
    string stickMan9 = "     _     "; //x = 11; y = 10
    string stickMan8 = "    ( }    ";
    string stickMan7 = "     o     ";
    string stickMan6 = "    /|     ";
    string stickMan5 = "    \\|     ";
    string stickMan4 = "     OO    ";
    string stickMan3 = "     |\\    ";
    string stickMan2 = "     o o   ";
    string stickMan1 = "     |/    ";
    string stickMan0 = "     Oo    ";

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
}

void FillLeftTwo(string& stickMan)
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
}

void FillRightTwo(string& stickMan)
{
    string stickMan9 = "     _     "; //x = 11; y = 10
    string stickMan8 = "    ( }    ";
    string stickMan7 = "     o     ";
    string stickMan6 = "    /|     ";
    string stickMan5 = "    ||\\    ";
    string stickMan4 = "    OO O   ";
    string stickMan3 = "     |\\    ";
    string stickMan2 = "     o o   ";
    string stickMan1 = "     | |   ";
    string stickMan0 = "     **Oo  ";

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
}

void FillLeftThree(string& stickMan)
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
}

void FillRightThree(string& stickMan)
{
    string stickMan9 = "     _     "; //x = 11; y = 10
    string stickMan8 = "    ( }    ";
    string stickMan7 = "     o     ";
    string stickMan6 = "    /|\\    ";
    string stickMan5 = "   / | \\   ";
    string stickMan4 = "  O  O  O  ";
    string stickMan3 = "     |\\    ";
    string stickMan2 = "     o o   ";
    string stickMan1 = "    /   \\  ";
    string stickMan0 = "    Oo   Oo";

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
}

void FillLeftFour(string& stickMan)
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
}

void FillRightFour(string& stickMan)
{
    string stickMan9 = "     _     "; //x = 11; y = 10
    string stickMan8 = "    ( }    ";
    string stickMan7 = "     o     ";
    string stickMan6 = "    /|     ";
    string stickMan5 = "    ||\\    ";
    string stickMan4 = "    OO O   ";
    string stickMan3 = "     |\\    ";
    string stickMan2 = "     o o   ";
    string stickMan1 = "    /  |   ";
    string stickMan0 = "   **  Oo  ";

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
}

void FillLightSaber1(string& stickMan)
{
    string stickMan14 = "                                   "; //x = 35; y = 15
    string stickMan13 = "                                   ";
    string stickMan12 = "                                   ";
    string stickMan11 = "                                   ";
    string stickMan10 = "                                   ";
    string stickMan9 = "                 _                 ";
    string stickMan8 = "                (\")                ";
    string stickMan7 = "                o-o                ";
    string stickMan6 = "               / | |               ";
    string stickMan5 = "               | | |               ";
    string stickMan4 = "               O O O               ";
    string stickMan3 = "                | \\                ";
    string stickMan2 = "                o  o               ";
    string stickMan1 = "                | /                ";
    string stickMan0 = "                O Oo               ";

    stickMan.append(stickMan14);
    stickMan.append(stickMan13);
    stickMan.append(stickMan12);
    stickMan.append(stickMan11);
    stickMan.append(stickMan10);
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
}

void FillLightSaber2(string& stickMan)
{
    string stickMan14 = "                                   "; //x = 35; y = 15
    string stickMan13 = "                                   ";
    string stickMan12 = "                                   ";
    string stickMan11 = "                                   ";
    string stickMan10 = "                                   ";
    string stickMan9 = "                 _                 ";
    string stickMan8 = "                ( }                ";
    string stickMan7 = "                o-o                ";
    string stickMan6 = "               / | |               ";
    string stickMan5 = "               | |  \\              ";
    string stickMan4 = "               O O   O             ";
    string stickMan3 = "                | \\                ";
    string stickMan2 = "                o  o               ";
    string stickMan1 = "                | /                ";
    string stickMan0 = "                O Oo               ";

    stickMan.append(stickMan14);
    stickMan.append(stickMan13);
    stickMan.append(stickMan12);
    stickMan.append(stickMan11);
    stickMan.append(stickMan10);
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
}

void FillLightSaber3(string& stickMan)
{
    string stickMan14 = "                                   "; //x = 35; y = 15
    string stickMan13 = "                                   ";
    string stickMan12 = "                                   ";
    string stickMan11 = "                                   ";
    string stickMan10 = "                                   ";
    string stickMan9 = "                 _                 ";
    string stickMan8 = "                ( }                ";
    string stickMan7 = "                o-o                ";
    string stickMan6 = "               / | |               ";
    string stickMan5 = "               | |  \\              ";
    string stickMan4 = "               O O  *O*            ";
    string stickMan3 = "                | \\                ";
    string stickMan2 = "                o  o               ";
    string stickMan1 = "                | /                ";
    string stickMan0 = "                O Oo               ";

    stickMan.append(stickMan14);
    stickMan.append(stickMan13);
    stickMan.append(stickMan12);
    stickMan.append(stickMan11);
    stickMan.append(stickMan10);
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
}

void FillLightSaber4(string& stickMan)
{
    string stickMan14 = "                                   "; //x = 35; y = 15
    string stickMan13 = "                                   ";
    string stickMan12 = "                                   ";
    string stickMan11 = "                                   ";
    string stickMan10 = "                                   ";
    string stickMan9 = "                 _                 ";
    string stickMan8 = "                ( }                ";
    string stickMan7 = "                o-o                ";
    string stickMan6 = "               / | |               ";
    string stickMan5 = "               | |  \\              ";
    string stickMan4 = "               O O  *O*===         ";
    string stickMan3 = "                | \\                ";
    string stickMan2 = "                o  o               ";
    string stickMan1 = "                | /                ";
    string stickMan0 = "                O Oo               ";

    stickMan.append(stickMan14);
    stickMan.append(stickMan13);
    stickMan.append(stickMan12);
    stickMan.append(stickMan11);
    stickMan.append(stickMan10);
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
}

void FillLightSaber5(string& stickMan)
{
    string stickMan14 = "                                   "; //x = 35; y = 15
    string stickMan13 = "                                   ";
    string stickMan12 = "                                   ";
    string stickMan11 = "                                   ";
    string stickMan10 = "                                   ";
    string stickMan9 = "                 _                 ";
    string stickMan8 = "                ( }                ";
    string stickMan7 = "                o-o                ";
    string stickMan6 = "               / | |               ";
    string stickMan5 = "               | |  \\              ";
    string stickMan4 = "               O O  *O*======      ";
    string stickMan3 = "                | \\                ";
    string stickMan2 = "                o  o               ";
    string stickMan1 = "                | /                ";
    string stickMan0 = "                O Oo               ";

    stickMan.append(stickMan14);
    stickMan.append(stickMan13);
    stickMan.append(stickMan12);
    stickMan.append(stickMan11);
    stickMan.append(stickMan10);
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
}

void FillLightSaber6(string& stickMan)
{
    string stickMan14 = "                                   "; //x = 35; y = 15
    string stickMan13 = "                                   ";
    string stickMan12 = "                                   ";
    string stickMan11 = "                                   ";
    string stickMan10 = "                                   ";
    string stickMan9 = "                 _                 ";
    string stickMan8 = "                ( }                ";
    string stickMan7 = "                o-o                ";
    string stickMan6 = "               / | |               ";
    string stickMan5 = "               | |  \\              ";
    string stickMan4 = "               O O  *O*=========   ";
    string stickMan3 = "                | \\                ";
    string stickMan2 = "                o  o               ";
    string stickMan1 = "                | /                ";
    string stickMan0 = "                O Oo               ";

    stickMan.append(stickMan14);
    stickMan.append(stickMan13);
    stickMan.append(stickMan12);
    stickMan.append(stickMan11);
    stickMan.append(stickMan10);
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
}

void FillLightSaber7(string& stickMan)
{
    string stickMan14 = "                                   "; //x = 35; y = 15
    string stickMan13 = "                                   ";
    string stickMan12 = "                                   ";
    string stickMan11 = "                                   ";
    string stickMan10 = "                                   ";
    string stickMan9 = "                 _                 ";
    string stickMan8 = "                ( }                ";
    string stickMan7 = "                o-o                ";
    string stickMan6 = "               / | \\               ";
    string stickMan5 = "               | |  '--O*========= ";
    string stickMan4 = "               O O                 ";
    string stickMan3 = "                | \\                ";
    string stickMan2 = "                o  o               ";
    string stickMan1 = "                | /                ";
    string stickMan0 = "                O Oo               ";

    stickMan.append(stickMan14);
    stickMan.append(stickMan13);
    stickMan.append(stickMan12);
    stickMan.append(stickMan11);
    stickMan.append(stickMan10);
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
}

void FillLightSaber8(string& stickMan)
{
    string stickMan14 = "                                   "; //x = 35; y = 15
    string stickMan13 = "                                   ";
    string stickMan12 = "                                   ";
    string stickMan11 = "                                   ";
    string stickMan10 = "                                   ";
    string stickMan9 = "                 _                 ";
    string stickMan8 = "                ( }                ";
    string stickMan7 = "                o-o ----O*=========";
    string stickMan6 = "               / |                 ";
    string stickMan5 = "               | |                 ";
    string stickMan4 = "               O O                 ";
    string stickMan3 = "                | \\                ";
    string stickMan2 = "                o  o               ";
    string stickMan1 = "                | /                ";
    string stickMan0 = "                O Oo               ";

    stickMan.append(stickMan14);
    stickMan.append(stickMan13);
    stickMan.append(stickMan12);
    stickMan.append(stickMan11);
    stickMan.append(stickMan10);
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
}

void FillLightSaber9(string& stickMan)
{
    string stickMan14 = "                            .'     "; //x = 35; y = 15
    string stickMan13 = "                          .'       ";
    string stickMan12 = "                        .'         ";
    string stickMan11 = "                      .'           ";
    string stickMan10 = "                     O             ";
    string stickMan9 = "                 _   /             ";
    string stickMan8 = "                ( } /              ";
    string stickMan7 = "                o-o                ";
    string stickMan6 = "               / |                 ";
    string stickMan5 = "               | |                 ";
    string stickMan4 = "               O O                 ";
    string stickMan3 = "                | \\                ";
    string stickMan2 = "                o  o               ";
    string stickMan1 = "                | /                ";
    string stickMan0 = "                O Oo               ";

    stickMan.append(stickMan14);
    stickMan.append(stickMan13);
    stickMan.append(stickMan12);
    stickMan.append(stickMan11);
    stickMan.append(stickMan10);
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
}

void FillLightSaber10(string& stickMan)
{
    string stickMan14 = "             '.                    "; //x = 35; y = 15
    string stickMan13 = "               '.                  ";
    string stickMan12 = "                 '.                ";
    string stickMan11 = "                   '.              ";
    string stickMan10 = "                     O             ";
    string stickMan9 = "                 _   /             ";
    string stickMan8 = "                ( } /              ";
    string stickMan7 = "                o-o                ";
    string stickMan6 = "               / |                 ";
    string stickMan5 = "               | |                 ";
    string stickMan4 = "               O O                 ";
    string stickMan3 = "                | \\                ";
    string stickMan2 = "                o  o               ";
    string stickMan1 = "                | /                ";
    string stickMan0 = "                O Oo               ";

    stickMan.append(stickMan14);
    stickMan.append(stickMan13);
    stickMan.append(stickMan12);
    stickMan.append(stickMan11);
    stickMan.append(stickMan10);
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
}

void FillLightSaber11(string& stickMan)
{
    string stickMan14 = "                                   "; //x = 35; y = 15
    string stickMan13 = "                                   ";
    string stickMan12 = "                                   ";
    string stickMan11 = "                                   ";
    string stickMan10 = "        =========*O*               ";
    string stickMan9 = "                 _  \\              ";
    string stickMan8 = "                ( } /              ";
    string stickMan7 = "                o-o                ";
    string stickMan6 = "               / |                 ";
    string stickMan5 = "               | |                 ";
    string stickMan4 = "               O O                 ";
    string stickMan3 = "                | \\                ";
    string stickMan2 = "                o  o               ";
    string stickMan1 = "                | /                ";
    string stickMan0 = "                O Oo               ";

    stickMan.append(stickMan14);
    stickMan.append(stickMan13);
    stickMan.append(stickMan12);
    stickMan.append(stickMan11);
    stickMan.append(stickMan10);
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
}

void FillLightSaber12(string& stickMan)
{
    string stickMan14 = "                                   "; //x = 35; y = 15
    string stickMan13 = "                                   ";
    string stickMan12 = "                                   ";
    string stickMan11 = "                                   ";
    string stickMan10 = "                                   ";
    string stickMan9 = "                 _                 ";
    string stickMan8 = "                ( }                ";
    string stickMan7 = "                o-o ----O*=========";
    string stickMan6 = "               / |                 ";
    string stickMan5 = "              /  |                 ";
    string stickMan4 = "             O   O                 ";
    string stickMan3 = "                | \\                ";
    string stickMan2 = "                o  o               ";
    string stickMan1 = "                | /                ";
    string stickMan0 = "                O Oo               ";

    stickMan.append(stickMan14);
    stickMan.append(stickMan13);
    stickMan.append(stickMan12);
    stickMan.append(stickMan11);
    stickMan.append(stickMan10);
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
}

void FillLightSaber13(string& stickMan)
{
    string stickMan14 = "                                   "; //x = 35; y = 15
    string stickMan13 = "                                   ";
    string stickMan12 = "                                   ";
    string stickMan11 = "                                   ";
    string stickMan10 = "                                   ";
    string stickMan9 = "                                   ";
    string stickMan8 = "                 _                 ";
    string stickMan7 = "                ( }                ";
    string stickMan6 = "                o-o ----O*=========";
    string stickMan5 = "               / |                 ";
    string stickMan4 = "              /  |                 ";
    string stickMan3 = "             O ,o-o,               ";
    string stickMan2 = "              o     o              ";
    string stickMan1 = "               '. .'               ";
    string stickMan0 = "               oO Oo               ";

    stickMan.append(stickMan14);
    stickMan.append(stickMan13);
    stickMan.append(stickMan12);
    stickMan.append(stickMan11);
    stickMan.append(stickMan10);
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
}

void FillLightSaber14(string& stickMan)
{
    string stickMan14 = "                                   "; //x = 35; y = 15
    string stickMan13 = "                                   ";
    string stickMan12 = "                                   ";
    string stickMan11 = "                                   ";
    string stickMan10 = "                                   ";
    string stickMan9 = "                                   ";
    string stickMan8 = "                 _                 ";
    string stickMan7 = "                ( }                ";
    string stickMan6 = "                o-o ----O*=========";
    string stickMan5 = "               / |                 ";
    string stickMan4 = "             O'  |                 ";
    string stickMan3 = "               ,o-o,               ";
    string stickMan2 = "              o     o              ";
    string stickMan1 = "               '. .'               ";
    string stickMan0 = "               oO Oo               ";

    stickMan.append(stickMan14);
    stickMan.append(stickMan13);
    stickMan.append(stickMan12);
    stickMan.append(stickMan11);
    stickMan.append(stickMan10);
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
}

void FillLightSaber15(string& stickMan)
{
    string stickMan14 = "                                   "; //x = 35; y = 15
    string stickMan13 = "                                   ";
    string stickMan12 = "                                   ";
    string stickMan11 = "                                   ";
    string stickMan10 = "                                   ";
    string stickMan9 = "                                   ";
    string stickMan8 = "                 _                 ";
    string stickMan7 = "                ( }                ";
    string stickMan6 = "                o-o ----O*=========";
    string stickMan5 = "            O__/ |                 ";
    string stickMan4 = "                 |                 ";
    string stickMan3 = "               ,o-o,               ";
    string stickMan2 = "              o     o              ";
    string stickMan1 = "               '. .'               ";
    string stickMan0 = "               oO Oo               ";

    stickMan.append(stickMan14);
    stickMan.append(stickMan13);
    stickMan.append(stickMan12);
    stickMan.append(stickMan11);
    stickMan.append(stickMan10);
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
}

void FillLightSaber16(string& stickMan)
{
    string stickMan14 = "                                   "; //x = 35; y = 15
    string stickMan13 = "                                   ";
    string stickMan12 = "                                   ";
    string stickMan11 = "                                   ";
    string stickMan10 = "                                   ";
    string stickMan9 = "                                   ";
    string stickMan8 = "                                   ";
    string stickMan7 = "                 _                 ";
    string stickMan6 = "                ( }                ";
    string stickMan5 = "             O  o-o ----O*=========";
    string stickMan4 = "              \\/ |                 ";
    string stickMan3 = "                 |                 ";
    string stickMan2 = "               ,o-o,               ";
    string stickMan1 = "              o - - o              ";
    string stickMan0 = "               oO Oo               ";

    stickMan.append(stickMan14);
    stickMan.append(stickMan13);
    stickMan.append(stickMan12);
    stickMan.append(stickMan11);
    stickMan.append(stickMan10);
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
}

void FillLightSaber17(string& stickMan)
{
    string stickMan14 = "                                   "; //x = 35; y = 15
    string stickMan13 = "                                   ";
    string stickMan12 = "                                   ";
    string stickMan11 = "                                   ";
    string stickMan10 = "                                   ";
    string stickMan9 = "                 _                 ";
    string stickMan8 = "                ( }                ";
    string stickMan7 = "                o-o                ";
    string stickMan6 = "               / | \\__O            ";
    string stickMan5 = "               | |                 ";
    string stickMan4 = "               O O                 ";
    string stickMan3 = "                | \\                ";
    string stickMan2 = "                o  o               ";
    string stickMan1 = "                | /                ";
    string stickMan0 = "                O Oo               ";

    stickMan.append(stickMan14);
    stickMan.append(stickMan13);
    stickMan.append(stickMan12);
    stickMan.append(stickMan11);
    stickMan.append(stickMan10);
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
}

void FillLightSaber18(string& stickMan)
{
    string stickMan14 = "                                   "; //x = 35; y = 15
    string stickMan13 = "                                   ";
    string stickMan12 = "                                   ";
    string stickMan11 = "                                   ";
    string stickMan10 = "                                   ";
    string stickMan9 = "                 _                 ";
    string stickMan8 = "                ( }                ";
    string stickMan7 = "                o-o ----O          ";
    string stickMan6 = "               / |                 ";
    string stickMan5 = "               | |                 ";
    string stickMan4 = "               O O                 ";
    string stickMan3 = "                | \\                ";
    string stickMan2 = "                o  o               ";
    string stickMan1 = "                | /                ";
    string stickMan0 = "                O Oo               ";

    stickMan.append(stickMan14);
    stickMan.append(stickMan13);
    stickMan.append(stickMan12);
    stickMan.append(stickMan11);
    stickMan.append(stickMan10);
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
}

void FillLightSaber19(string& stickMan)
{
    string stickMan14 = "                                   "; //x = 35; y = 15
    string stickMan13 = "                                   ";
    string stickMan12 = "                                   ";
    string stickMan11 = "                                   ";
    string stickMan10 = "                                   ";
    string stickMan9 = "                 _                 ";
    string stickMan8 = "                ( }                ";
    string stickMan7 = "                o-o ----E          ";
    string stickMan6 = "               / |                 ";
    string stickMan5 = "               | |                 ";
    string stickMan4 = "               O O                 ";
    string stickMan3 = "                | \\                ";
    string stickMan2 = "                o  o               ";
    string stickMan1 = "                | /                ";
    string stickMan0 = "                O Oo               ";

    stickMan.append(stickMan14);
    stickMan.append(stickMan13);
    stickMan.append(stickMan12);
    stickMan.append(stickMan11);
    stickMan.append(stickMan10);
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
}

void FillLightSaber20(string& stickMan)
{
    string stickMan14 = "                                   "; //x = 35; y = 15
    string stickMan13 = "                                   ";
    string stickMan12 = "                                   ";
    string stickMan11 = "                                   ";
    string stickMan10 = "                                   ";
    string stickMan9 = "                 _                 ";
    string stickMan8 = "                ( }                ";
    string stickMan7 = "                o-o ----O          ";
    string stickMan6 = "               / |      *          ";
    string stickMan5 = "               | |                 ";
    string stickMan4 = "               O O                 ";
    string stickMan3 = "                | \\                ";
    string stickMan2 = "                o  o               ";
    string stickMan1 = "                | /                ";
    string stickMan0 = "                O Oo               ";

    stickMan.append(stickMan14);
    stickMan.append(stickMan13);
    stickMan.append(stickMan12);
    stickMan.append(stickMan11);
    stickMan.append(stickMan10);
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
}

void FillLightSaber21(string& stickMan)
{
    string stickMan14 = "                                   "; //x = 35; y = 15
    string stickMan13 = "                                   ";
    string stickMan12 = "                                   ";
    string stickMan11 = "                                   ";
    string stickMan10 = "                                   ";
    string stickMan9 = "                 _                 ";
    string stickMan8 = "                ( }     [          ";
    string stickMan7 = "                o-o ----O          ";
    string stickMan6 = "               / |      *          ";
    string stickMan5 = "               | |                 ";
    string stickMan4 = "               O O                 ";
    string stickMan3 = "                | \\                ";
    string stickMan2 = "                o  o               ";
    string stickMan1 = "                | /                ";
    string stickMan0 = "                O Oo               ";

    stickMan.append(stickMan14);
    stickMan.append(stickMan13);
    stickMan.append(stickMan12);
    stickMan.append(stickMan11);
    stickMan.append(stickMan10);
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
}

void FillLightSaber22(string& stickMan)
{
    string stickMan14 = "                                   "; //x = 35; y = 15
    string stickMan13 = "                                   ";
    string stickMan12 = "                                   ";
    string stickMan11 = "                                   ";
    string stickMan10 = "                                   ";
    string stickMan9 = "                 _      [          ";
    string stickMan8 = "                ( }     [          ";
    string stickMan7 = "                o-o ----O          ";
    string stickMan6 = "               / |      *          ";
    string stickMan5 = "               | |                 ";
    string stickMan4 = "               O O                 ";
    string stickMan3 = "                | \\                ";
    string stickMan2 = "                o  o               ";
    string stickMan1 = "                | /                ";
    string stickMan0 = "                O Oo               ";

    stickMan.append(stickMan14);
    stickMan.append(stickMan13);
    stickMan.append(stickMan12);
    stickMan.append(stickMan11);
    stickMan.append(stickMan10);
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
}

void FillLightSaber23(string& stickMan)
{
    string stickMan14 = "                                   "; //x = 35; y = 15
    string stickMan13 = "                                   ";
    string stickMan12 = "                                   ";
    string stickMan11 = "                        [          ";
    string stickMan10 = "                        [          ";
    string stickMan9 = "                 _      [          ";
    string stickMan8 = "                ( }     [          ";
    string stickMan7 = "                o-o ----O          ";
    string stickMan6 = "               / |      *          ";
    string stickMan5 = "               | |                 ";
    string stickMan4 = "               O O                 ";
    string stickMan3 = "                | \\                ";
    string stickMan2 = "                o  o               ";
    string stickMan1 = "                | /                ";
    string stickMan0 = "                O Oo               ";

    stickMan.append(stickMan14);
    stickMan.append(stickMan13);
    stickMan.append(stickMan12);
    stickMan.append(stickMan11);
    stickMan.append(stickMan10);
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
}

void FillLightSaber24(string& stickMan)
{
    string stickMan14 = "                                   "; //x = 35; y = 15
    string stickMan13 = "                                   ";
    string stickMan12 = "                                   ";
    string stickMan11 = "                        [          ";
    string stickMan10 = "                        [          ";
    string stickMan9 = "                 _      [          ";
    string stickMan8 = "                ( }     [          ";
    string stickMan7 = "                o-o ----O          ";
    string stickMan6 = "               / |      *          ";
    string stickMan5 = "               | |                 ";
    string stickMan4 = "               O O                 ";
    string stickMan3 = "                | \\                ";
    string stickMan2 = "                o  o               ";
    string stickMan1 = "                | /                ";
    string stickMan0 = "                O Oo               ";

    stickMan.append(stickMan14);
    stickMan.append(stickMan13);
    stickMan.append(stickMan12);
    stickMan.append(stickMan11);
    stickMan.append(stickMan10);
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
}

void FillJumpOne(string& stickMan)
{
    string stickMan9 = "           "; //x = 11; y = 10
    string stickMan8 = "     _     ";
    string stickMan7 = "    (\")    ";
    string stickMan6 = "    o-o    ";
    string stickMan5 = "   / | \\   ";
    string stickMan4 = "   \\ | /   ";
    string stickMan3 = "   _O-O_   ";
    string stickMan2 = "  O     O  ";
    string stickMan1 = "   \\   /   ";
    string stickMan0 = "   oO Oo   ";

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
}

void FillJumpTwo(string& stickMan)
{
    string stickMan9 = "     _     "; //x = 11; y = 10
    string stickMan8 = "    (\")    ";
    string stickMan7 = " .--o-o--. ";
    string stickMan6 = " |   |   | ";
    string stickMan5 = " O   |   O ";
    string stickMan4 = "    O-O    ";
    string stickMan3 = "    | |    ";
    string stickMan2 = "    o o    ";
    string stickMan1 = "    | |    ";
    string stickMan0 = "   oO Oo   ";

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
}

void FillScratchHeadOne(string& stickMan)
{
    string stickMan9 = "     _     "; //x = 11; y = 10
    string stickMan8 = "    (\")    ";
    string stickMan7 = "    o-o    ";
    string stickMan6 = "   / | \\   ";
    string stickMan5 = "   \\ | O   ";
    string stickMan4 = "    O-O    ";
    string stickMan3 = "    / |    ";
    string stickMan2 = "   o  o    ";
    string stickMan1 = "    \\ |    ";
    string stickMan0 = "   oO O    ";

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
}

void FillScratchHeadTwo(string& stickMan)
{
    string stickMan9 = "     _     "; //x = 11; y = 10
    string stickMan8 = "    (\")    ";
    string stickMan7 = "    o-o    ";
    string stickMan6 = "   / | \\O  ";
    string stickMan5 = "   \\ |     ";
    string stickMan4 = "    O-O    ";
    string stickMan3 = "    / |    ";
    string stickMan2 = "   o  o    ";
    string stickMan1 = "    \\ |    ";
    string stickMan0 = "   oO O    ";

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
}

void FillScratchHeadThree(string& stickMan)
{
    string stickMan9 = "     _     "; //x = 11; y = 10
    string stickMan8 = "    (\")    ";
    string stickMan7 = "    o-o O  ";
    string stickMan6 = "   / | \\/  ";
    string stickMan5 = "   \\ |     ";
    string stickMan4 = "    O-O    ";
    string stickMan3 = "    / |    ";
    string stickMan2 = "   o  o    ";
    string stickMan1 = "    \\ |    ";
    string stickMan0 = "   oO O    ";

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
}

void FillScratchHeadFour(string& stickMan)
{
    string stickMan9 = "     _     "; //x = 11; y = 10
    string stickMan8 = "    (\")O   ";
    string stickMan7 = "    o-o_\\  ";
    string stickMan6 = "   / |     ";
    string stickMan5 = "   \\ |     ";
    string stickMan4 = "    O-O    ";
    string stickMan3 = "    / |    ";
    string stickMan2 = "   o  o    ";
    string stickMan1 = "    \\ |    ";
    string stickMan0 = "   oO O    ";

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
}

void FillScratchHeadFive(string& stickMan)
{
    string stickMan9 = "     _     "; //x = 11; y = 10
    string stickMan8 = "    (\")3   ";
    string stickMan7 = "    o-o_\\  ";
    string stickMan6 = "   / |     ";
    string stickMan5 = "   \\ |     ";
    string stickMan4 = "    O-O    ";
    string stickMan3 = "    / |    ";
    string stickMan2 = "   o  o    ";
    string stickMan1 = "    \\ |    ";
    string stickMan0 = "   oO O    ";

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
}

void FillLightSwitchOne(string& stickMan)
{
    string stickMan9 = "   _       "; //x = 11; y = 10
    string stickMan8 = "  ( }      ";
    string stickMan7 = "   o       ";
    string stickMan6 = "  /|\\    \\|";
    string stickMan5 = " | | |    |";
    string stickMan4 = " O O O     ";
    string stickMan3 = "   |\\      ";
    string stickMan2 = "   o o     ";
    string stickMan1 = "   |/      ";
    string stickMan0 = "   Oo      ";

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
}

void FillLightSwitchTwo(string& stickMan)
{
    string stickMan9 = "   _       "; //x = 11; y = 10
    string stickMan8 = "  ( }      ";
    string stickMan7 = "   o       ";
    string stickMan6 = "  /|\\    \\|";
    string stickMan5 = " | | O    |";
    string stickMan4 = " O O       ";
    string stickMan3 = "   |\\      ";
    string stickMan2 = "   o o     ";
    string stickMan1 = "   |/      ";
    string stickMan0 = "   Oo      ";

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
}

void FillLightSwitchThree(string& stickMan)
{
    string stickMan9 = "   _       "; //x = 11; y = 10
    string stickMan8 = "  ( }      ";
    string stickMan7 = "   o       ";
    string stickMan6 = "  /|\\__O \\|";
    string stickMan5 = " | |      |";
    string stickMan4 = " O O       ";
    string stickMan3 = "   |\\      ";
    string stickMan2 = "   o o     ";
    string stickMan1 = "   |/      ";
    string stickMan0 = "   Oo      ";

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
}

void FillLightSwitchFour(string& stickMan)
{
    string stickMan9 = "   _       "; //x = 11; y = 10
    string stickMan8 = "  ( }      ";
    string stickMan7 = "   o       ";
    string stickMan6 = "  /| \\    |";
    string stickMan5 = " | |  \\O /|";
    string stickMan4 = " O O       ";
    string stickMan3 = "   |\\      ";
    string stickMan2 = "   o o     ";
    string stickMan1 = "   |/      ";
    string stickMan0 = "   Oo      ";

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
}

void FillCheckWatchOne(string& stickMan)
{
    string stickMan9 = "     _     "; //x = 11; y = 10
    string stickMan8 = "    (\")    ";
    string stickMan7 = "    o-o    ";
    string stickMan6 = "   / | \\   ";
    string stickMan5 = "   \\ |O'   ";
    string stickMan4 = "    O-O    ";
    string stickMan3 = "    | |    ";
    string stickMan2 = "    o o    ";
    string stickMan1 = "    | |    ";
    string stickMan0 = "   oO Oo   ";

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
}

void FillCheckWatchTwo(string& stickMan)
{
    string stickMan9 = "     _     "; //x = 11; y = 10
    string stickMan8 = "    (\")    ";
    string stickMan7 = "    o-o_   ";
    string stickMan6 = "   / O--'  ";
    string stickMan5 = "   \\ |     ";
    string stickMan4 = "    O-O    ";
    string stickMan3 = "    | |    ";
    string stickMan2 = "    o o    ";
    string stickMan1 = "    | |    ";
    string stickMan0 = "   oO Oo   ";

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
}

void FillCheckWatchThree(string& stickMan)
{
    string stickMan9 = "     _     "; //x = 11; y = 10
    string stickMan8 = "    (\")    ";
    string stickMan7 = "    o-o    ";
    string stickMan6 = "   / | \\   ";
    string stickMan5 = "   \\ | /   ";
    string stickMan4 = "    O-O    ";
    string stickMan3 = "    | |    ";
    string stickMan2 = "    o o    ";
    string stickMan1 = "    | |    ";
    string stickMan0 = "   oO Oo   ";

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
}

void FillHungerOne(string& stickMan)
{
    string stickMan9 = "     _     "; //x = 11; y = 10
    string stickMan8 = "    (\")    ";
    string stickMan7 = "    o-o    ";
    string stickMan6 = "   / | \\   ";
    string stickMan5 = "   'O|O'   ";
    string stickMan4 = "    O-O    ";
    string stickMan3 = "    / |    ";
    string stickMan2 = "   o  o    ";
    string stickMan1 = "    \\ |    ";
    string stickMan0 = "   oO O    ";

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
}

void FillHungerTwo(string& stickMan)
{
    string stickMan9 = "     _     "; //x = 11; y = 10
    string stickMan8 = "    (\")    ";
    string stickMan7 = "    o-o    ";
    string stickMan6 = "   / | \\   ";
    string stickMan5 = "   '.O.'   ";
    string stickMan4 = "    O-O    ";
    string stickMan3 = "    / |    ";
    string stickMan2 = "   o  o    ";
    string stickMan1 = "    \\ |    ";
    string stickMan0 = "   oO O    ";

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
}

void FillPlantTreeOne(string& stickMan)
{
    string stickMan9 = "     _     "; //x = 11; y = 10
    string stickMan8 = "    { )    ";
    string stickMan7 = "     o     ";
    string stickMan6 = "    /|\\    ";
    string stickMan5 = "   / |/    ";
    string stickMan4 = "  O  O     ";
    string stickMan3 = "    /|     ";
    string stickMan2 = "   o o     ";
    string stickMan1 = "    \\|     ";
    string stickMan0 = "    oO     ";

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
}

void FillPlantTreeTwo(string& stickMan)
{
    string stickMan9 = "   _       "; //x = 11; y = 10
    string stickMan8 = "  { )      ";
    string stickMan7 = "   o       ";
    string stickMan6 = "   /\\      ";
    string stickMan5 = "  / /\\     ";
    string stickMan4 = " O o O     ";
    string stickMan3 = "    /      ";
    string stickMan2 = "   o       ";
    string stickMan1 = "    \\      ";
    string stickMan0 = "    oO     ";

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
}

void FillPlantTreeThree(string& stickMan)
{
    string stickMan9 = "           "; //x = 11; y = 10
    string stickMan8 = "   _       ";
    string stickMan7 = "  { )      ";
    string stickMan6 = "   o       ";
    string stickMan5 = "   /\\      ";
    string stickMan4 = "  / /\\     ";
    string stickMan3 = " O o.O     ";
    string stickMan2 = "  o'       ";
    string stickMan1 = "   '.      ";
    string stickMan0 = "    oO     ";

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
}

void FillPlantTreeFour(string& stickMan)
{
    string stickMan9 = "           "; //x = 11; y = 10
    string stickMan8 = "           ";
    string stickMan7 = "   _       ";
    string stickMan6 = "  { )      ";
    string stickMan5 = "   o       ";
    string stickMan4 = "   /\\      ";
    string stickMan3 = "  / /\\     ";
    string stickMan2 = " O o.O     ";
    string stickMan1 = "  '-.      ";
    string stickMan0 = "    oO     ";

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
}

void FillPlantTreeFive(string& stickMan)
{
    string stickMan9 = "           "; //x = 11; y = 10
    string stickMan8 = "           ";
    string stickMan7 = "           ";
    string stickMan6 = " _         ";
    string stickMan5 = "{ )        ";
    string stickMan4 = "  o._      ";
    string stickMan3 = " /  /\\     ";
    string stickMan2 = "/  o.O     ";
    string stickMan1 = "O '-.      ";
    string stickMan0 = "    oO     ";

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
}

void FillGrabFruitOne(string& stickMan)
{
    string stickMan9 = "     _     "; //x = 11; y = 10
    string stickMan8 = "    (\")    ";
    string stickMan7 = "    o-o    ";
    string stickMan6 = "   / | \\   ";
    string stickMan5 = "   O | /   ";
    string stickMan4 = "    O-O    ";
    string stickMan3 = "    / |    ";
    string stickMan2 = "   o  o    ";
    string stickMan1 = "    \\ |    ";
    string stickMan0 = "   oO O    ";

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
}

void FillGrabFruitTwo(string& stickMan)
{
    string stickMan9 = "     _     "; //x = 11; y = 10
    string stickMan8 = "    (\")    ";
    string stickMan7 = "    o-o    ";
    string stickMan6 = "  O/ | \\   ";
    string stickMan5 = "     | /   ";
    string stickMan4 = "    O-O    ";
    string stickMan3 = "    / |    ";
    string stickMan2 = "   o  o    ";
    string stickMan1 = "    \\ |    ";
    string stickMan0 = "   oO O    ";

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
}

void FillGrabFruitThree(string& stickMan)
{
    string stickMan9 = "     _     "; //x = 11; y = 10
    string stickMan8 = "    (\")    ";
    string stickMan7 = " O  o-o    ";
    string stickMan6 = "  \\/ | \\   ";
    string stickMan5 = "     | /   ";
    string stickMan4 = "    O-O    ";
    string stickMan3 = "    / |    ";
    string stickMan2 = "   o  o    ";
    string stickMan1 = "    \\ |    ";
    string stickMan0 = "   oO O    ";

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
}

void FillGrabFruitFour(string& stickMan)
{
    string stickMan9 = "     _     "; //x = 11; y = 10
    string stickMan8 = "O   (\")    ";
    string stickMan7 = " \\__o-o    ";
    string stickMan6 = "     | \\   ";
    string stickMan5 = "     | /   ";
    string stickMan4 = "    O-O    ";
    string stickMan3 = "    / |    ";
    string stickMan2 = "   o  o    ";
    string stickMan1 = "    \\ |    ";
    string stickMan0 = "   oO O    ";

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
}

void FillGrabFruitFive(string& stickMan)
{
    string stickMan9 = "     _     "; //x = 11; y = 10
    string stickMan8 = "3   (\")    ";
    string stickMan7 = " \\__o-o    ";
    string stickMan6 = "     | \\   ";
    string stickMan5 = "     | /   ";
    string stickMan4 = "    O-O    ";
    string stickMan3 = "    / |    ";
    string stickMan2 = "   o  o    ";
    string stickMan1 = "    \\ |    ";
    string stickMan0 = "   oO O    ";

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
}

void FillEatFruitOne(string& stickMan)
{
    string stickMan9 = "     _     "; //x = 11; y = 10
    string stickMan8 = " O  (\")    ";
    string stickMan7 = " |__o-o    ";
    string stickMan6 = "     | \\   ";
    string stickMan5 = "     | /   ";
    string stickMan4 = "    O-O    ";
    string stickMan3 = "    / |    ";
    string stickMan2 = "   o  o    ";
    string stickMan1 = "    \\ |    ";
    string stickMan0 = "   oO O    ";

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
}

void FillEatFruitTwo(string& stickMan)
{
    string stickMan9 = "     _     "; //x = 11; y = 10
    string stickMan8 = "   O{ )    ";
    string stickMan7 = "  /_o-o    ";
    string stickMan6 = "     | \\   ";
    string stickMan5 = "     | /   ";
    string stickMan4 = "    O-O    ";
    string stickMan3 = "    / |    ";
    string stickMan2 = "   o  o    ";
    string stickMan1 = "    \\ |    ";
    string stickMan0 = "   oO O    ";

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
}

void FillEatFruitThree(string& stickMan)
{
    string stickMan9 = "     _     "; //x = 11; y = 10
    string stickMan8 = "   O> )    ";
    string stickMan7 = "  /_o-o    ";
    string stickMan6 = "     | \\   ";
    string stickMan5 = "     | /   ";
    string stickMan4 = "    O-O    ";
    string stickMan3 = "    / |    ";
    string stickMan2 = "   o  o    ";
    string stickMan1 = "    \\ |    ";
    string stickMan0 = "   oO O    ";

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
}

void FillEatFruitFour(string& stickMan)
{
    string stickMan9 = "     _     "; //x = 11; y = 10
    string stickMan8 = "    (\")    ";
    string stickMan7 = "  O o-o    ";
    string stickMan6 = "   V | \\   ";
    string stickMan5 = "     | /   ";
    string stickMan4 = "    O-O    ";
    string stickMan3 = "    / |    ";
    string stickMan2 = "   o  o    ";
    string stickMan1 = "    \\ |    ";
    string stickMan0 = "   oO O    ";

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
}

void FillEatFruitFive(string& stickMan)
{
    string stickMan9 = "     _     "; //x = 11; y = 10
    string stickMan8 = "    (\")    ";
    string stickMan7 = "    o-o    ";
    string stickMan6 = "  O/ | \\   ";
    string stickMan5 = "     | /   ";
    string stickMan4 = "    O-O    ";
    string stickMan3 = "    / |    ";
    string stickMan2 = "   o  o    ";
    string stickMan1 = "    \\ |    ";
    string stickMan0 = "   oO O    ";

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
}

void FillEatFruitSix(string& stickMan)
{
    string stickMan9 = "     _     "; //x = 11; y = 10
    string stickMan8 = "    (\")    ";
    string stickMan7 = "    o-o    ";
    string stickMan6 = "   / | \\   ";
    string stickMan5 = "   O | /   ";
    string stickMan4 = "    O-O    ";
    string stickMan3 = "    / |    ";
    string stickMan2 = "   o  o    ";
    string stickMan1 = "    \\ |    ";
    string stickMan0 = "   oO O    ";

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
}

void FillWatchFireWorks1(string& stickMan)
{
    string stickMan9 = "          _     "; //x = 16; y = 10
    string stickMan8 = "         ( }    ";
    string stickMan7 = "          o     ";
    string stickMan6 = "         /|     ";
    string stickMan5 = "        | |     ";
    string stickMan4 = "        O O     ";
    string stickMan3 = "           \\    ";
    string stickMan2 = "            o   ";
    string stickMan1 = "           /    ";
    string stickMan0 = "          Oo    ";

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
}

void FillWatchFireWorks2(string& stickMan)
{
    string stickMan9 = "                "; //x = 16; y = 10
    string stickMan8 = "         _      ";
    string stickMan7 = "        ( }     ";
    string stickMan6 = "         o      ";
    string stickMan5 = "        /|      ";
    string stickMan4 = "       | |      ";
    string stickMan3 = "       O O.     ";
    string stickMan2 = "           'o   ";
    string stickMan1 = "          .'    ";
    string stickMan0 = "          Oo    ";

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
}

void FillWatchFireWorks3(string& stickMan)
{
    string stickMan9 = "                "; //x = 16; y = 10
    string stickMan8 = "                ";
    string stickMan7 = "         _      ";
    string stickMan6 = "        ( }     ";
    string stickMan5 = "         o      ";
    string stickMan4 = "        /|      ";
    string stickMan3 = "       | |      ";
    string stickMan2 = "       O O..o   ";
    string stickMan1 = "          .'    ";
    string stickMan0 = "          Oo    ";

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
}

void FillWatchFireWorks4(string& stickMan)
{
    string stickMan9 = "                "; //x = 16; y = 10
    string stickMan8 = "                ";
    string stickMan7 = "                ";
    string stickMan6 = "     _          ";
    string stickMan5 = "    ( }         ";
    string stickMan4 = "     o          ";
    string stickMan3 = "    / \\         ";
    string stickMan2 = "   |   \\ .o     ";
    string stickMan1 = "   O    O |     ";
    string stickMan0 = "          Oo    ";

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
}

void FillWatchFireWorks5(string& stickMan)
{
    string stickMan9 = "                "; //x = 16; y = 10
    string stickMan8 = "                ";
    string stickMan7 = "                ";
    string stickMan6 = "                ";
    string stickMan5 = "   _            ";
    string stickMan4 = "  ( }           ";
    string stickMan3 = "   o            ";
    string stickMan2 = "  / \\   o       ";
    string stickMan1 = " |   \\ / \\      ";
    string stickMan0 = " O    O   Oo    ";

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
}

void FillWatchFireWorks6(string& stickMan)
{
    string stickMan9 = "                "; //x = 16; y = 10
    string stickMan8 = "                ";
    string stickMan7 = "                ";
    string stickMan6 = "                ";
    string stickMan5 = "   _            ";
    string stickMan4 = "  ( }           ";
    string stickMan3 = "   o            ";
    string stickMan2 = "  / \\   o       ";
    string stickMan1 = " /   \\ / \\      ";
    string stickMan0 = "O     O   Oo    ";

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
}

void FillWatchFireWorks7(string& stickMan)
{
    string stickMan9 = "                "; //x = 16; y = 10
    string stickMan8 = "                ";
    string stickMan7 = "                ";
    string stickMan6 = "                ";
    string stickMan5 = "   _            ";
    string stickMan4 = "  ( }           ";
    string stickMan3 = "   o            ";
    string stickMan2 = "  / \\   o --O'  ";
    string stickMan1 = " /   \\ / \\      ";
    string stickMan0 = "O     O   Oo    ";

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
}

void FillCallDog1(string& stickMan)
{
    string stickMan9 = "     _     "; //x = 11; y = 10
    string stickMan8 = "    (\")    ";
    string stickMan7 = "    o-o    ";
    string stickMan6 = "   / | \\   ";
    string stickMan5 = "   \\ | O   ";
    string stickMan4 = "    O-O    ";
    string stickMan3 = "    | \\    ";
    string stickMan2 = "    o  o   ";
    string stickMan1 = "    | /    ";
    string stickMan0 = "    O Oo   ";

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
}

void FillCallDog2(string& stickMan)
{
    string stickMan9 = "     _     "; //x = 11; y = 10
    string stickMan8 = "    (\")    ";
    string stickMan7 = "    o-o    ";
    string stickMan6 = "   / | \\O  ";
    string stickMan5 = "   \\ |     ";
    string stickMan4 = "    O-O    ";
    string stickMan3 = "    | \\    ";
    string stickMan2 = "    o  o   ";
    string stickMan1 = "    | /    ";
    string stickMan0 = "    O Oo   ";

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
}

void FillCallDog3(string& stickMan)
{
    string stickMan9 = "     _     "; //x = 11; y = 10
    string stickMan8 = "    (\")    ";
    string stickMan7 = "    o-o O  ";
    string stickMan6 = "   / | V   ";
    string stickMan5 = "   \\ |     ";
    string stickMan4 = "    O-O    ";
    string stickMan3 = "    | \\    ";
    string stickMan2 = "    o  o   ";
    string stickMan1 = "    | /    ";
    string stickMan0 = "    O Oo   ";

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
}

void FillCallDog4(string& stickMan)
{
    string stickMan9 = "     _     "; //x = 11; y = 10
    string stickMan8 = "    ( }3   ";
    string stickMan7 = "    o-o_\\  ";
    string stickMan6 = "   / |     ";
    string stickMan5 = "   \\ |     ";
    string stickMan4 = "    O-O    ";
    string stickMan3 = "    | \\    ";
    string stickMan2 = "    o  o   ";
    string stickMan1 = "    | /    ";
    string stickMan0 = "    O Oo   ";

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
}

void FillCallDog5(string& stickMan)
{
    string stickMan9 = "     _     "; //x = 11; y = 10
    string stickMan8 = "    (\") O  ";
    string stickMan7 = "    o-o__\\ ";
    string stickMan6 = "   / |     ";
    string stickMan5 = "   \\ |     ";
    string stickMan4 = "    O-O    ";
    string stickMan3 = "    | \\    ";
    string stickMan2 = "    o  o   ";
    string stickMan1 = "    | /    ";
    string stickMan0 = "    O Oo   ";

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
}

void FillCallDog6(string& stickMan)
{
    string stickMan9 = "     _     "; //x = 11; y = 10
    string stickMan8 = "    (\")  O ";
    string stickMan7 = "    o-o__| ";
    string stickMan6 = "   / |     ";
    string stickMan5 = "   \\ |     ";
    string stickMan4 = "    O-O    ";
    string stickMan3 = "    | \\    ";
    string stickMan2 = "    o  o   ";
    string stickMan1 = "    | /    ";
    string stickMan0 = "    O Oo   ";

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
}

void FillCallDog7(string& stickMan)
{
    string stickMan9 = "     _     "; //x = 11; y = 10
    string stickMan8 = "    (\")   O";
    string stickMan7 = "    o-o__/ ";
    string stickMan6 = "   / |     ";
    string stickMan5 = "   \\ |     ";
    string stickMan4 = "    O-O    ";
    string stickMan3 = "    | \\    ";
    string stickMan2 = "    o  o   ";
    string stickMan1 = "    | /    ";
    string stickMan0 = "    O Oo   ";

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
}

void FillCallDog8(string& stickMan)
{
    string stickMan9 = "     _     "; //x = 11; y = 10
    string stickMan8 = "    ( }    ";
    string stickMan7 = "     o     ";
    string stickMan6 = "    /|     ";
    string stickMan5 = "    \\|     ";
    string stickMan4 = "     OO    ";
    string stickMan3 = "     |\\    ";
    string stickMan2 = "     o o   ";
    string stickMan1 = "     |/    ";
    string stickMan0 = "     Oo    ";

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
}

void FillCallDog9(string& stickMan)
{
    string stickMan9 = "     _     "; //x = 11; y = 10
    string stickMan8 = "    ( }    ";
    string stickMan7 = "     o     ";
    string stickMan6 = "    /|\\    ";
    string stickMan5 = "    \\| \\   ";
    string stickMan4 = "     O  O  ";
    string stickMan3 = "     |\\    ";
    string stickMan2 = "     o o   ";
    string stickMan1 = "     |/    ";
    string stickMan0 = "     Oo    ";

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
}

void FillCallDog10(string& stickMan)
{
    string stickMan9 = "       _   "; //x = 11; y = 10
    string stickMan8 = "      ( }  ";
    string stickMan7 = "       o   ";
    string stickMan6 = "      / \\  ";
    string stickMan5 = "     /\\  \\ ";
    string stickMan4 = "     O O  O";
    string stickMan3 = "      \\    ";
    string stickMan2 = "       o   ";
    string stickMan1 = "      /    ";
    string stickMan0 = "     Oo    ";

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
}

void FillCallDog11(string& stickMan)
{
    string stickMan9 = "       _   "; //x = 11; y = 10
    string stickMan8 = "      ( }  ";
    string stickMan7 = "       o   ";
    string stickMan6 = "      / \\  ";
    string stickMan5 = "     /\\  \\ ";
    string stickMan4 = "     O O  E";
    string stickMan3 = "      \\    ";
    string stickMan2 = "       o   ";
    string stickMan1 = "      /    ";
    string stickMan0 = "     Oo    ";

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
}

void FillCallDog12(string& stickMan)
{
    string stickMan9 = "     _     "; //x = 11; y = 10
    string stickMan8 = "    ( }    ";
    string stickMan7 = "     o     ";
    string stickMan6 = "    /|\\__O ";
    string stickMan5 = "    \\|     ";
    string stickMan4 = "     O     ";
    string stickMan3 = "     |\\    ";
    string stickMan2 = "     o o   ";
    string stickMan1 = "     |/    ";
    string stickMan0 = "     Oo    ";

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
}

void FillCallDog13(string& stickMan)
{
    string stickMan9 = "     _     "; //x = 11; y = 10
    string stickMan8 = "    ( }    ";
    string stickMan7 = "     o----O";
    string stickMan6 = "    /|     ";
    string stickMan5 = "    \\|     ";
    string stickMan4 = "     O     ";
    string stickMan3 = "     |\\    ";
    string stickMan2 = "     o o   ";
    string stickMan1 = "     |/    ";
    string stickMan0 = "     Oo    ";

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
}

void FillCallDog14(string& stickMan)
{
    string stickMan9 = "     _    O"; //x = 11; y = 10
    string stickMan8 = "    ( } .' ";
    string stickMan7 = "     o /   ";
    string stickMan6 = "    /|     ";
    string stickMan5 = "    \\|     ";
    string stickMan4 = "     O     ";
    string stickMan3 = "     |\\    ";
    string stickMan2 = "     o o   ";
    string stickMan1 = "     |/    ";
    string stickMan0 = "     Oo    ";

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
}

void FillPushCloud1(string& stickMan)
{
    string stickMan9 = "     _     "; //x = 11; y = 10
    string stickMan8 = "    (\")    ";
    string stickMan7 = "    o-o    ";
    string stickMan6 = "   / | \\   ";
    string stickMan5 = "   \\ | /   ";
    string stickMan4 = "    O-OO   ";
    string stickMan3 = "    | \\    ";
    string stickMan2 = "    o  o   ";
    string stickMan1 = "    | /    ";
    string stickMan0 = "    O Oo   ";

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
}

void FillPushCloud2(string& stickMan)
{
    string stickMan9 = "     _     "; //x = 11; y = 10
    string stickMan8 = "    (\")    ";
    string stickMan7 = "    o-o    ";
    string stickMan6 = "   / | \\   ";
    string stickMan5 = "   \\ |  O  ";
    string stickMan4 = "    O-O    ";
    string stickMan3 = "    | \\    ";
    string stickMan2 = "    o  o   ";
    string stickMan1 = "    | /    ";
    string stickMan0 = "    O Oo   ";

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
}

void FillPushCloud3(string& stickMan)
{
    string stickMan9 = "     _     "; //x = 11; y = 10
    string stickMan8 = "    (\")    ";
    string stickMan7 = "    o-o    ";
    string stickMan6 = "   / | \\_O ";
    string stickMan5 = "   \\ |     ";
    string stickMan4 = "    O-O    ";
    string stickMan3 = "    | \\    ";
    string stickMan2 = "    o  o   ";
    string stickMan1 = "    | /    ";
    string stickMan0 = "    O Oo   ";

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
}

void FillPushCloud4(string& stickMan)
{
    string stickMan9 = "     _     "; //x = 11; y = 10
    string stickMan8 = "    (\")    ";
    string stickMan7 = "    o-o    ";
    string stickMan6 = "   / | \\__O";
    string stickMan5 = "   \\ |     ";
    string stickMan4 = "    O-O    ";
    string stickMan3 = "    | \\    ";
    string stickMan2 = "    o  o   ";
    string stickMan1 = "    | /    ";
    string stickMan0 = "    O Oo   ";

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
}


/****************************************************************/
/****Dog center axis (torso) is X coord position 8 (index 7)*****/
/****************************************************************/

void FillDogStandLeft(string& dog)
{
    string dog7 = "               "; //x = 15; y = 8
    string dog6 = "               ";
    string dog5 = "  __O          ";
    string dog4 = " {__)        o ";
    string dog3 = "     \\      /  ";
    string dog2 = "      o----o   ";
    string dog1 = "     /|   /|   ";
    string dog0 = "    O O  O O   ";

    dog.append(dog7);
    dog.append(dog6);
    dog.append(dog5);
    dog.append(dog4);
    dog.append(dog3);
    dog.append(dog2);
    dog.append(dog1);
    dog.append(dog0);
}

void FillDogStandRight(string& dog)
{
    string dog7 = "               "; //x = 15; y = 8
    string dog6 = "               ";
    string dog5 = "         O__   ";
    string dog4 = " o       (__}  ";
    string dog3 = "  \\      /     ";
    string dog2 = "   o----o      ";
    string dog1 = "   |\\   |\\     ";
    string dog0 = "   O O  O O    ";

    dog.append(dog7);
    dog.append(dog6);
    dog.append(dog5);
    dog.append(dog4);
    dog.append(dog3);
    dog.append(dog2);
    dog.append(dog1);
    dog.append(dog0);
}

void FillDogLeft1(string& dog)
{
    string dog7 = "               "; //x = 15; y = 8
    string dog6 = "               ";
    string dog5 = "  __O          ";
    string dog4 = " {__)        o ";
    string dog3 = "     \\      /  ";
    string dog2 = "      o----o   ";
    string dog1 = "    .'|    |   ";
    string dog0 = "      O   oO   ";

    dog.append(dog7);
    dog.append(dog6);
    dog.append(dog5);
    dog.append(dog4);
    dog.append(dog3);
    dog.append(dog2);
    dog.append(dog1);
    dog.append(dog0);
}

void FillDogRight1(string& dog)
{
    string dog7 = "               "; //x = 15; y = 8
    string dog6 = "               ";
    string dog5 = "         O__   ";
    string dog4 = " o       (__}  ";
    string dog3 = "  \\      /     ";
    string dog2 = "   o----o      ";
    string dog1 = "   |    |'.    ";
    string dog0 = "   Oo   O      ";

    dog.append(dog7);
    dog.append(dog6);
    dog.append(dog5);
    dog.append(dog4);
    dog.append(dog3);
    dog.append(dog2);
    dog.append(dog1);
    dog.append(dog0);
}

void FillDogLeft2(string& dog)
{
    string dog7 = "               "; //x = 15; y = 8
    string dog6 = "               ";
    string dog5 = "  __O          ";
    string dog4 = " {__)        o ";
    string dog3 = "     \\      /  ";
    string dog2 = "      o----o   ";
    string dog1 = "      |  .'|   ";
    string dog0 = "     oO    O   ";

    dog.append(dog7);
    dog.append(dog6);
    dog.append(dog5);
    dog.append(dog4);
    dog.append(dog3);
    dog.append(dog2);
    dog.append(dog1);
    dog.append(dog0);
}

void FillDogRight2(string& dog)
{
    string dog7 = "               "; //x = 15; y = 8
    string dog6 = "               ";
    string dog5 = "         O__   ";
    string dog4 = " o       (__}  ";
    string dog3 = "  \\      /     ";
    string dog2 = "   o----o      ";
    string dog1 = "   |'.  |      ";
    string dog0 = "   O    Oo     ";

    dog.append(dog7);
    dog.append(dog6);
    dog.append(dog5);
    dog.append(dog4);
    dog.append(dog3);
    dog.append(dog2);
    dog.append(dog1);
    dog.append(dog0);
}

void FillDogLeft3(string& dog)
{
    string dog7 = "               "; //x = 15; y = 8
    string dog6 = "               ";
    string dog5 = "  __O          ";
    string dog4 = " {__)        o ";
    string dog3 = "     \\      /  ";
    string dog2 = "      o----o   ";
    string dog1 = "     /'.   |   ";
    string dog0 = "    O     oO   ";

    dog.append(dog7);
    dog.append(dog6);
    dog.append(dog5);
    dog.append(dog4);
    dog.append(dog3);
    dog.append(dog2);
    dog.append(dog1);
    dog.append(dog0);
}

void FillDogRight3(string& dog)
{
    string dog7 = "               "; //x = 15; y = 8
    string dog6 = "               ";
    string dog5 = "         O__   ";
    string dog4 = " o       (__}  ";
    string dog3 = "  \\      /     ";
    string dog2 = "   o----o      ";
    string dog1 = "   |   .'\\     ";
    string dog0 = "   Oo     O    ";

    dog.append(dog7);
    dog.append(dog6);
    dog.append(dog5);
    dog.append(dog4);
    dog.append(dog3);
    dog.append(dog2);
    dog.append(dog1);
    dog.append(dog0);
}

void FillDogLeft4(string& dog)
{
    string dog7 = "               "; //x = 15; y = 8
    string dog6 = "               ";
    string dog5 = "  __O          ";
    string dog4 = " {__)        o ";
    string dog3 = "     \\      /  ";
    string dog2 = "      o----o   ";
    string dog1 = "      |   /'.  ";
    string dog0 = "     oO  O     ";

    dog.append(dog7);
    dog.append(dog6);
    dog.append(dog5);
    dog.append(dog4);
    dog.append(dog3);
    dog.append(dog2);
    dog.append(dog1);
    dog.append(dog0);
}

void FillDogRight4(string& dog)
{
    string dog7 = "               "; //x = 15; y = 8
    string dog6 = "               ";
    string dog5 = "         O__   ";
    string dog4 = " o       (__}  ";
    string dog3 = "  \\      /     ";
    string dog2 = "   o----o      ";
    string dog1 = "  .'\\   |      ";
    string dog0 = "     O  Oo     ";

    dog.append(dog7);
    dog.append(dog6);
    dog.append(dog5);
    dog.append(dog4);
    dog.append(dog3);
    dog.append(dog2);
    dog.append(dog1);
    dog.append(dog0);
}

void FillDogWagTailOne(string& dog)
{
    string dog7 = "               "; //x = 15; y = 8
    string dog6 = "               ";
    string dog5 = "  __O          ";
    string dog4 = " {__)      o   ";
    string dog3 = "     \\     |   ";
    string dog2 = "      o----o   ";
    string dog1 = "     /|   /|   ";
    string dog0 = "    O O  O O   ";

    dog.append(dog7);
    dog.append(dog6);
    dog.append(dog5);
    dog.append(dog4);
    dog.append(dog3);
    dog.append(dog2);
    dog.append(dog1);
    dog.append(dog0);
}

void FillDogJump1(string& dog)
{
    string dog7 = "               "; //x = 15; y = 8
    string dog6 = "  ,,           ";
    string dog5 = "  \\ \\          ";
    string dog4 = "  (,OO       o ";
    string dog3 = "     \\      /  ";
    string dog2 = "      o----o   ";
    string dog1 = "     /|   /|   ";
    string dog0 = "    O O  O O   ";

    dog.append(dog7);
    dog.append(dog6);
    dog.append(dog5);
    dog.append(dog4);
    dog.append(dog3);
    dog.append(dog2);
    dog.append(dog1);
    dog.append(dog0);
}

void FillDogJump2(string& dog)
{
    string dog7 = "     ,,        "; //x = 15; y = 8
    string dog6 = "     \\ \\       ";
    string dog5 = "     (,OO      ";
    string dog4 = "        o      ";
    string dog3 = "      .' \\  .'o";
    string dog2 = "     O O  'o   ";
    string dog1 = "          /|   ";
    string dog0 = "         O O   ";

    dog.append(dog7);
    dog.append(dog6);
    dog.append(dog5);
    dog.append(dog4);
    dog.append(dog3);
    dog.append(dog2);
    dog.append(dog1);
    dog.append(dog0);
}

void FillDogBendHead(string& dog)
{
    string dog7 = "               "; //x = 15; y = 8
    string dog6 = "               ";
    string dog5 = "               ";
    string dog4 = "             o ";
    string dog3 = "            /  ";
    string dog2 = "  OO,-o----o   ";
    string dog1 = " / / /|   /|   ";
    string dog0 = " '' O O  O O   ";

    dog.append(dog7);
    dog.append(dog6);
    dog.append(dog5);
    dog.append(dog4);
    dog.append(dog3);
    dog.append(dog2);
    dog.append(dog1);
    dog.append(dog0);
}


/****************************************************************/
/***Tree center axis (torso) is X coord position 10 (index 9)****/
/****************************************************************/

void FillTree1(string& tree)
{
    string tree16 = "                   "; //x= 19; y = 17
    string tree15 = "                   ";
    string tree14 = "                   ";
    string tree13 = "                   ";
    string tree12 = "                   ";
    string tree11 = "                   ";
    string tree10 = "                   ";
    string tree9 = "                   ";
    string tree8 = "                   ";
    string tree7 = "                   ";
    string tree6 = "                   ";
    string tree5 = "                   ";
    string tree4 = "                   ";
    string tree3 = "                   ";
    string tree2 = "                   ";
    string tree1 = "                   ";
    string tree0 = "         .         ";

    tree.append(tree16);
    tree.append(tree15);
    tree.append(tree14);
    tree.append(tree13);
    tree.append(tree12);
    tree.append(tree11);
    tree.append(tree10);
    tree.append(tree9);
    tree.append(tree8);
    tree.append(tree7);
    tree.append(tree6);
    tree.append(tree5);
    tree.append(tree4);
    tree.append(tree3);
    tree.append(tree2);
    tree.append(tree1);
    tree.append(tree0);
}

void FillTree2(string& tree)
{
    string tree16 = "                   "; //x= 19; y = 17
    string tree15 = "                   ";
    string tree14 = "                   ";
    string tree13 = "                   ";
    string tree12 = "                   ";
    string tree11 = "                   ";
    string tree10 = "                   ";
    string tree9 = "                   ";
    string tree8 = "                   ";
    string tree7 = "                   ";
    string tree6 = "                   ";
    string tree5 = "                   ";
    string tree4 = "                   ";
    string tree3 = "                   ";
    string tree2 = "                   ";
    string tree1 = "                   ";
    string tree0 = "         |         ";

    tree.append(tree16);
    tree.append(tree15);
    tree.append(tree14);
    tree.append(tree13);
    tree.append(tree12);
    tree.append(tree11);
    tree.append(tree10);
    tree.append(tree9);
    tree.append(tree8);
    tree.append(tree7);
    tree.append(tree6);
    tree.append(tree5);
    tree.append(tree4);
    tree.append(tree3);
    tree.append(tree2);
    tree.append(tree1);
    tree.append(tree0);
}

void FillTree3(string& tree)
{
    string tree16 = "                   "; //x= 19; y = 17
    string tree15 = "                   ";
    string tree14 = "                   ";
    string tree13 = "                   ";
    string tree12 = "                   ";
    string tree11 = "                   ";
    string tree10 = "                   ";
    string tree9 = "                   ";
    string tree8 = "                   ";
    string tree7 = "                   ";
    string tree6 = "                   ";
    string tree5 = "                   ";
    string tree4 = "                   ";
    string tree3 = "                   ";
    string tree2 = "                   ";
    string tree1 = "         V         ";
    string tree0 = "         |         ";

    tree.append(tree16);
    tree.append(tree15);
    tree.append(tree14);
    tree.append(tree13);
    tree.append(tree12);
    tree.append(tree11);
    tree.append(tree10);
    tree.append(tree9);
    tree.append(tree8);
    tree.append(tree7);
    tree.append(tree6);
    tree.append(tree5);
    tree.append(tree4);
    tree.append(tree3);
    tree.append(tree2);
    tree.append(tree1);
    tree.append(tree0);
}

void FillTree4(string& tree)
{
    string tree16 = "                   "; //x= 19; y = 17
    string tree15 = "                   ";
    string tree14 = "                   ";
    string tree13 = "                   ";
    string tree12 = "                   ";
    string tree11 = "                   ";
    string tree10 = "                   ";
    string tree9 = "                   ";
    string tree8 = "                   ";
    string tree7 = "                   ";
    string tree6 = "                   ";
    string tree5 = "                   ";
    string tree4 = "                   ";
    string tree3 = "                   ";
    string tree2 = "        . .        ";
    string tree1 = "         V         ";
    string tree0 = "         |         ";

    tree.append(tree16);
    tree.append(tree15);
    tree.append(tree14);
    tree.append(tree13);
    tree.append(tree12);
    tree.append(tree11);
    tree.append(tree10);
    tree.append(tree9);
    tree.append(tree8);
    tree.append(tree7);
    tree.append(tree6);
    tree.append(tree5);
    tree.append(tree4);
    tree.append(tree3);
    tree.append(tree2);
    tree.append(tree1);
    tree.append(tree0);
}

void FillTree5(string& tree)
{
    string tree16 = "                   "; //x= 19; y = 17
    string tree15 = "                   ";
    string tree14 = "                   ";
    string tree13 = "                   ";
    string tree12 = "                   ";
    string tree11 = "                   ";
    string tree10 = "                   ";
    string tree9 = "                   ";
    string tree8 = "                   ";
    string tree7 = "                   ";
    string tree6 = "                   ";
    string tree5 = "                   ";
    string tree4 = "                   ";
    string tree3 = "                   ";
    string tree2 = "        \\ .        ";
    string tree1 = "         V         ";
    string tree0 = "         |         ";

    tree.append(tree16);
    tree.append(tree15);
    tree.append(tree14);
    tree.append(tree13);
    tree.append(tree12);
    tree.append(tree11);
    tree.append(tree10);
    tree.append(tree9);
    tree.append(tree8);
    tree.append(tree7);
    tree.append(tree6);
    tree.append(tree5);
    tree.append(tree4);
    tree.append(tree3);
    tree.append(tree2);
    tree.append(tree1);
    tree.append(tree0);
}

void FillTree6(string& tree)
{
    string tree16 = "                   "; //x= 19; y = 17
    string tree15 = "                   ";
    string tree14 = "                   ";
    string tree13 = "                   ";
    string tree12 = "                   ";
    string tree11 = "                   ";
    string tree10 = "                   ";
    string tree9 = "                   ";
    string tree8 = "                   ";
    string tree7 = "                   ";
    string tree6 = "                   ";
    string tree5 = "                   ";
    string tree4 = "                   ";
    string tree3 = "                   ";
    string tree2 = "        \\ /        ";
    string tree1 = "         V         ";
    string tree0 = "         |         ";

    tree.append(tree16);
    tree.append(tree15);
    tree.append(tree14);
    tree.append(tree13);
    tree.append(tree12);
    tree.append(tree11);
    tree.append(tree10);
    tree.append(tree9);
    tree.append(tree8);
    tree.append(tree7);
    tree.append(tree6);
    tree.append(tree5);
    tree.append(tree4);
    tree.append(tree3);
    tree.append(tree2);
    tree.append(tree1);
    tree.append(tree0);
}

void FillTree7(string& tree)
{
    string tree16 = "                   "; //x= 19; y = 17
    string tree15 = "                   ";
    string tree14 = "                   ";
    string tree13 = "                   ";
    string tree12 = "                   ";
    string tree11 = "                   ";
    string tree10 = "                   ";
    string tree9 = "                   ";
    string tree8 = "                   ";
    string tree7 = "                   ";
    string tree6 = "                   ";
    string tree5 = "                   ";
    string tree4 = "                   ";
    string tree3 = "        \\ /        ";
    string tree2 = "         V         ";
    string tree1 = "         |         ";
    string tree0 = "         |         ";

    tree.append(tree16);
    tree.append(tree15);
    tree.append(tree14);
    tree.append(tree13);
    tree.append(tree12);
    tree.append(tree11);
    tree.append(tree10);
    tree.append(tree9);
    tree.append(tree8);
    tree.append(tree7);
    tree.append(tree6);
    tree.append(tree5);
    tree.append(tree4);
    tree.append(tree3);
    tree.append(tree2);
    tree.append(tree1);
    tree.append(tree0);
}

void FillTree8(string& tree)
{
    string tree16 = "                   "; //x= 19; y = 17
    string tree15 = "                   ";
    string tree14 = "                   ";
    string tree13 = "                   ";
    string tree12 = "                   ";
    string tree11 = "                   ";
    string tree10 = "                   ";
    string tree9 = "                   ";
    string tree8 = "                   ";
    string tree7 = "                   ";
    string tree6 = "                   ";
    string tree5 = "                   ";
    string tree4 = "                   ";
    string tree3 = "        \\ /        ";
    string tree2 = "         V         ";
    string tree1 = "        \\|         ";
    string tree0 = "         |         ";

    tree.append(tree16);
    tree.append(tree15);
    tree.append(tree14);
    tree.append(tree13);
    tree.append(tree12);
    tree.append(tree11);
    tree.append(tree10);
    tree.append(tree9);
    tree.append(tree8);
    tree.append(tree7);
    tree.append(tree6);
    tree.append(tree5);
    tree.append(tree4);
    tree.append(tree3);
    tree.append(tree2);
    tree.append(tree1);
    tree.append(tree0);
}

void FillTree9(string& tree)
{
    string tree16 = "                   "; //x= 19; y = 17
    string tree15 = "                   ";
    string tree14 = "                   ";
    string tree13 = "                   ";
    string tree12 = "                   ";
    string tree11 = "                   ";
    string tree10 = "                   ";
    string tree9 = "                   ";
    string tree8 = "                   ";
    string tree7 = "                   ";
    string tree6 = "                   ";
    string tree5 = "                   ";
    string tree4 = "        /          ";
    string tree3 = "        \\ /        ";
    string tree2 = "         V         ";
    string tree1 = "        \\|         ";
    string tree0 = "         |         ";

    tree.append(tree16);
    tree.append(tree15);
    tree.append(tree14);
    tree.append(tree13);
    tree.append(tree12);
    tree.append(tree11);
    tree.append(tree10);
    tree.append(tree9);
    tree.append(tree8);
    tree.append(tree7);
    tree.append(tree6);
    tree.append(tree5);
    tree.append(tree4);
    tree.append(tree3);
    tree.append(tree2);
    tree.append(tree1);
    tree.append(tree0);
}

void FillTree10(string& tree)
{
    string tree16 = "                   "; //x= 19; y = 17
    string tree15 = "                   ";
    string tree14 = "                   ";
    string tree13 = "                   ";
    string tree12 = "                   ";
    string tree11 = "                   ";
    string tree10 = "                   ";
    string tree9 = "                   ";
    string tree8 = "                   ";
    string tree7 = "                   ";
    string tree6 = "                   ";
    string tree5 = "                   ";
    string tree4 = "       \\/          ";
    string tree3 = "        \\ /        ";
    string tree2 = "         V         ";
    string tree1 = "        \\|         ";
    string tree0 = "         |         ";

    tree.append(tree16);
    tree.append(tree15);
    tree.append(tree14);
    tree.append(tree13);
    tree.append(tree12);
    tree.append(tree11);
    tree.append(tree10);
    tree.append(tree9);
    tree.append(tree8);
    tree.append(tree7);
    tree.append(tree6);
    tree.append(tree5);
    tree.append(tree4);
    tree.append(tree3);
    tree.append(tree2);
    tree.append(tree1);
    tree.append(tree0);
}

void FillTree11(string& tree)
{
    string tree16 = "                   "; //x= 19; y = 17
    string tree15 = "                   ";
    string tree14 = "                   ";
    string tree13 = "                   ";
    string tree12 = "                   ";
    string tree11 = "                   ";
    string tree10 = "                   ";
    string tree9 = "                   ";
    string tree8 = "                   ";
    string tree7 = "                   ";
    string tree6 = "                   ";
    string tree5 = "         /         ";
    string tree4 = "       \\/          ";
    string tree3 = "        \\ /        ";
    string tree2 = "         V         ";
    string tree1 = "        \\|         ";
    string tree0 = "         |         ";

    tree.append(tree16);
    tree.append(tree15);
    tree.append(tree14);
    tree.append(tree13);
    tree.append(tree12);
    tree.append(tree11);
    tree.append(tree10);
    tree.append(tree9);
    tree.append(tree8);
    tree.append(tree7);
    tree.append(tree6);
    tree.append(tree5);
    tree.append(tree4);
    tree.append(tree3);
    tree.append(tree2);
    tree.append(tree1);
    tree.append(tree0);
}

void FillTree12(string& tree)
{
    string tree16 = "                   "; //x= 19; y = 17
    string tree15 = "                   ";
    string tree14 = "                   ";
    string tree13 = "                   ";
    string tree12 = "                   ";
    string tree11 = "                   ";
    string tree10 = "                   ";
    string tree9 = "                   ";
    string tree8 = "                   ";
    string tree7 = "                   ";
    string tree6 = "         /         ";
    string tree5 = "       \\/          ";
    string tree4 = "        \\ /        ";
    string tree3 = "         V         ";
    string tree2 = "        \\|         ";
    string tree1 = "         |         ";
    string tree0 = "         |         ";

    tree.append(tree16);
    tree.append(tree15);
    tree.append(tree14);
    tree.append(tree13);
    tree.append(tree12);
    tree.append(tree11);
    tree.append(tree10);
    tree.append(tree9);
    tree.append(tree8);
    tree.append(tree7);
    tree.append(tree6);
    tree.append(tree5);
    tree.append(tree4);
    tree.append(tree3);
    tree.append(tree2);
    tree.append(tree1);
    tree.append(tree0);
}

void FillTree13(string& tree)
{
    string tree16 = "                   "; //x= 19; y = 17
    string tree15 = "                   ";
    string tree14 = "                   ";
    string tree13 = "                   ";
    string tree12 = "                   ";
    string tree11 = "                   ";
    string tree10 = "                   ";
    string tree9 = "                   ";
    string tree8 = "                   ";
    string tree7 = "                   ";
    string tree6 = "         /         ";
    string tree5 = "       \\/          ";
    string tree4 = "        \\ /        ";
    string tree3 = "       _ V         ";
    string tree2 = "        \\|         ";
    string tree1 = "         |         ";
    string tree0 = "         |         ";

    tree.append(tree16);
    tree.append(tree15);
    tree.append(tree14);
    tree.append(tree13);
    tree.append(tree12);
    tree.append(tree11);
    tree.append(tree10);
    tree.append(tree9);
    tree.append(tree8);
    tree.append(tree7);
    tree.append(tree6);
    tree.append(tree5);
    tree.append(tree4);
    tree.append(tree3);
    tree.append(tree2);
    tree.append(tree1);
    tree.append(tree0);
}

void FillTree14(string& tree)
{
    string tree16 = "                   "; //x= 19; y = 17
    string tree15 = "                   ";
    string tree14 = "                   ";
    string tree13 = "                   ";
    string tree12 = "                   ";
    string tree11 = "                   ";
    string tree10 = "                   ";
    string tree9 = "                   ";
    string tree8 = "                   ";
    string tree7 = "                   ";
    string tree6 = "         /         ";
    string tree5 = "       \\/  _       ";
    string tree4 = "        \\ /        ";
    string tree3 = "       _ V _       ";
    string tree2 = "        \\|         ";
    string tree1 = "         |         ";
    string tree0 = "         |         ";

    tree.append(tree16);
    tree.append(tree15);
    tree.append(tree14);
    tree.append(tree13);
    tree.append(tree12);
    tree.append(tree11);
    tree.append(tree10);
    tree.append(tree9);
    tree.append(tree8);
    tree.append(tree7);
    tree.append(tree6);
    tree.append(tree5);
    tree.append(tree4);
    tree.append(tree3);
    tree.append(tree2);
    tree.append(tree1);
    tree.append(tree0);
}

void FillTree15(string& tree)
{
    string tree16 = "                   "; //x= 19; y = 17
    string tree15 = "                   ";
    string tree14 = "                   ";
    string tree13 = "                   ";
    string tree12 = "                   ";
    string tree11 = "                   ";
    string tree10 = "                   ";
    string tree9 = "                   ";
    string tree8 = "                   ";
    string tree7 = "                   ";
    string tree6 = "         /         ";
    string tree5 = "       \\/  _       ";
    string tree4 = "        \\ /        ";
    string tree3 = "      __ V _       ";
    string tree2 = "        \\|         ";
    string tree1 = "         |         ";
    string tree0 = "         |         ";

    tree.append(tree16);
    tree.append(tree15);
    tree.append(tree14);
    tree.append(tree13);
    tree.append(tree12);
    tree.append(tree11);
    tree.append(tree10);
    tree.append(tree9);
    tree.append(tree8);
    tree.append(tree7);
    tree.append(tree6);
    tree.append(tree5);
    tree.append(tree4);
    tree.append(tree3);
    tree.append(tree2);
    tree.append(tree1);
    tree.append(tree0);
}

void FillTree16(string& tree)
{
    string tree16 = "                   "; //x= 19; y = 17
    string tree15 = "                   ";
    string tree14 = "                   ";
    string tree13 = "                   ";
    string tree12 = "                   ";
    string tree11 = "                   ";
    string tree10 = "                   ";
    string tree9 = "                   ";
    string tree8 = "                   ";
    string tree7 = "                   ";
    string tree6 = "         /         ";
    string tree5 = "       \\/  _       ";
    string tree4 = "        \\ /        ";
    string tree3 = "     \\__ V _/      ";
    string tree2 = "        \\|         ";
    string tree1 = "         |         ";
    string tree0 = "         |         ";

    tree.append(tree16);
    tree.append(tree15);
    tree.append(tree14);
    tree.append(tree13);
    tree.append(tree12);
    tree.append(tree11);
    tree.append(tree10);
    tree.append(tree9);
    tree.append(tree8);
    tree.append(tree7);
    tree.append(tree6);
    tree.append(tree5);
    tree.append(tree4);
    tree.append(tree3);
    tree.append(tree2);
    tree.append(tree1);
    tree.append(tree0);
}

void FillTree17(string& tree)
{
    string tree16 = "                   "; //x= 19; y = 17
    string tree15 = "                   ";
    string tree14 = "                   ";
    string tree13 = "                   ";
    string tree12 = "                   ";
    string tree11 = "                   ";
    string tree10 = "                   ";
    string tree9 = "                   ";
    string tree8 = "                   ";
    string tree7 = "                   ";
    string tree6 = "         /         ";
    string tree5 = "       \\/  _/      ";
    string tree4 = "        \\ /        ";
    string tree3 = "     \\__ V _/      ";
    string tree2 = "        \\|         ";
    string tree1 = "         |         ";
    string tree0 = "         |         ";

    tree.append(tree16);
    tree.append(tree15);
    tree.append(tree14);
    tree.append(tree13);
    tree.append(tree12);
    tree.append(tree11);
    tree.append(tree10);
    tree.append(tree9);
    tree.append(tree8);
    tree.append(tree7);
    tree.append(tree6);
    tree.append(tree5);
    tree.append(tree4);
    tree.append(tree3);
    tree.append(tree2);
    tree.append(tree1);
    tree.append(tree0);
}

void FillTree18(string& tree)
{
    string tree16 = "                   "; //x= 19; y = 17
    string tree15 = "                   ";
    string tree14 = "                   ";
    string tree13 = "                   ";
    string tree12 = "                   ";
    string tree11 = "                   ";
    string tree10 = "                   ";
    string tree9 = "                   ";
    string tree8 = "                   ";
    string tree7 = "                   ";
    string tree6 = "      _  /         ";
    string tree5 = "       \\/  _/      ";
    string tree4 = "        \\ /        ";
    string tree3 = "     \\__ V _/      ";
    string tree2 = "        \\|         ";
    string tree1 = "         |         ";
    string tree0 = "         |         ";

    tree.append(tree16);
    tree.append(tree15);
    tree.append(tree14);
    tree.append(tree13);
    tree.append(tree12);
    tree.append(tree11);
    tree.append(tree10);
    tree.append(tree9);
    tree.append(tree8);
    tree.append(tree7);
    tree.append(tree6);
    tree.append(tree5);
    tree.append(tree4);
    tree.append(tree3);
    tree.append(tree2);
    tree.append(tree1);
    tree.append(tree0);
}

void FillTree19(string& tree)
{
    string tree16 = "                   "; //x= 19; y = 17
    string tree15 = "                   ";
    string tree14 = "                   ";
    string tree13 = "                   ";
    string tree12 = "                   ";
    string tree11 = "                   ";
    string tree10 = "                   ";
    string tree9 = "                   ";
    string tree8 = "                   ";
    string tree7 = "                   ";
    string tree6 = "     \\_  /         ";
    string tree5 = "       \\/  _/      ";
    string tree4 = "        \\ /        ";
    string tree3 = "     \\__ V _/      ";
    string tree2 = "        \\|         ";
    string tree1 = "         |         ";
    string tree0 = "         |         ";

    tree.append(tree16);
    tree.append(tree15);
    tree.append(tree14);
    tree.append(tree13);
    tree.append(tree12);
    tree.append(tree11);
    tree.append(tree10);
    tree.append(tree9);
    tree.append(tree8);
    tree.append(tree7);
    tree.append(tree6);
    tree.append(tree5);
    tree.append(tree4);
    tree.append(tree3);
    tree.append(tree2);
    tree.append(tree1);
    tree.append(tree0);
}

void FillTree20(string& tree)
{
    string tree16 = "                   "; //x= 19; y = 17
    string tree15 = "                   ";
    string tree14 = "                   ";
    string tree13 = "                   ";
    string tree12 = "                   ";
    string tree11 = "                   ";
    string tree10 = "                   ";
    string tree9 = "                   ";
    string tree8 = "                   ";
    string tree7 = "         \\         ";
    string tree6 = "     \\_  /         ";
    string tree5 = "       \\/  _/      ";
    string tree4 = "        \\ /        ";
    string tree3 = "     \\__ V _/      ";
    string tree2 = "        \\|         ";
    string tree1 = "         |         ";
    string tree0 = "         |         ";

    tree.append(tree16);
    tree.append(tree15);
    tree.append(tree14);
    tree.append(tree13);
    tree.append(tree12);
    tree.append(tree11);
    tree.append(tree10);
    tree.append(tree9);
    tree.append(tree8);
    tree.append(tree7);
    tree.append(tree6);
    tree.append(tree5);
    tree.append(tree4);
    tree.append(tree3);
    tree.append(tree2);
    tree.append(tree1);
    tree.append(tree0);
}

void FillTree21(string& tree)
{
    string tree16 = "                   "; //x= 19; y = 17
    string tree15 = "                   ";
    string tree14 = "                   ";
    string tree13 = "                   ";
    string tree12 = "                   ";
    string tree11 = "                   ";
    string tree10 = "                   ";
    string tree9 = "                   ";
    string tree8 = "                   ";
    string tree7 = "         \\/        ";
    string tree6 = "     \\_  /         ";
    string tree5 = "       \\/  _/      ";
    string tree4 = "        \\ /        ";
    string tree3 = "     \\__ V _/      ";
    string tree2 = "        \\|         ";
    string tree1 = "         |         ";
    string tree0 = "         |         ";

    tree.append(tree16);
    tree.append(tree15);
    tree.append(tree14);
    tree.append(tree13);
    tree.append(tree12);
    tree.append(tree11);
    tree.append(tree10);
    tree.append(tree9);
    tree.append(tree8);
    tree.append(tree7);
    tree.append(tree6);
    tree.append(tree5);
    tree.append(tree4);
    tree.append(tree3);
    tree.append(tree2);
    tree.append(tree1);
    tree.append(tree0);
}

void FillTree22(string& tree)
{
    string tree16 = "                   "; //x= 19; y = 17
    string tree15 = "                   ";
    string tree14 = "                   ";
    string tree13 = "                   ";
    string tree12 = "                   ";
    string tree11 = "                   ";
    string tree10 = "                   ";
    string tree9 = "        _   )      ";
    string tree8 = "    (    \\/        ";
    string tree7 = "   ( \\_  /   )     ";
    string tree6 = "       \\/  _/      ";
    string tree5 = "        \\ /        ";
    string tree4 = "     \\__ V _/      ";
    string tree3 = "        \\|         ";
    string tree2 = "         |         ";
    string tree1 = "         |         ";
    string tree0 = "         H         ";

    tree.append(tree16);
    tree.append(tree15);
    tree.append(tree14);
    tree.append(tree13);
    tree.append(tree12);
    tree.append(tree11);
    tree.append(tree10);
    tree.append(tree9);
    tree.append(tree8);
    tree.append(tree7);
    tree.append(tree6);
    tree.append(tree5);
    tree.append(tree4);
    tree.append(tree3);
    tree.append(tree2);
    tree.append(tree1);
    tree.append(tree0);
}

void FillTree23(string& tree)
{
    string tree16 = "                   "; //x= 19; y = 17
    string tree15 = "                   ";
    string tree14 = "                   ";
    string tree13 = "                   ";
    string tree12 = "                   ";
    string tree11 = "       --          ";
    string tree10 = "    (     )        ";
    string tree9 = "       \\_   )      ";
    string tree8 = "    (    \\/        ";
    string tree7 = "   ( \\_  /   )     ";
    string tree6 = "       \\/  _/      ";
    string tree5 = "    (   \\ /  )     ";
    string tree4 = "     \\__ V _/      ";
    string tree3 = "        \\|         ";
    string tree2 = "         |         ";
    string tree1 = "         H         ";
    string tree0 = "         H         ";

    tree.append(tree16);
    tree.append(tree15);
    tree.append(tree14);
    tree.append(tree13);
    tree.append(tree12);
    tree.append(tree11);
    tree.append(tree10);
    tree.append(tree9);
    tree.append(tree8);
    tree.append(tree7);
    tree.append(tree6);
    tree.append(tree5);
    tree.append(tree4);
    tree.append(tree3);
    tree.append(tree2);
    tree.append(tree1);
    tree.append(tree0);
}

void FillTree24(string& tree)
{
    string tree16 = "                   "; //x= 19; y = 17
    string tree15 = "                   ";
    string tree14 = "                   ";
    string tree13 = "                   ";
    string tree12 = "                   ";
    string tree11 = "     .---.         ";
    string tree10 = "    (     )        ";
    string tree9 = "    (  \\_   )      ";
    string tree8 = "   (     \\/ )      ";
    string tree7 = "   ( \\_  /   )     ";
    string tree6 = "    ( _\\/  _/)     ";
    string tree5 = "    (   \\ /  )     ";
    string tree4 = "     (__ V __)     ";
    string tree3 = "        \\|         ";
    string tree2 = "         H         ";
    string tree1 = "         H         ";
    string tree0 = "         H         ";

    tree.append(tree16);
    tree.append(tree15);
    tree.append(tree14);
    tree.append(tree13);
    tree.append(tree12);
    tree.append(tree11);
    tree.append(tree10);
    tree.append(tree9);
    tree.append(tree8);
    tree.append(tree7);
    tree.append(tree6);
    tree.append(tree5);
    tree.append(tree4);
    tree.append(tree3);
    tree.append(tree2);
    tree.append(tree1);
    tree.append(tree0);
}

void FillTree25(string& tree)
{
    string tree16 = "                   "; //x= 19; y = 17
    string tree15 = "                   ";
    string tree14 = "                   ";
    string tree13 = "                   ";
    string tree12 = "                   ";
    string tree11 = "     .---.         ";
    string tree10 = "    (      )       ";
    string tree9 = "    (  \\_    )     ";
    string tree8 = "   (     \\/_ )     ";
    string tree7 = "   ( \\_  /   )     ";
    string tree6 = "    ( _\\/  _/)     ";
    string tree5 = "    (   \\ /  )     ";
    string tree4 = "     (__ V __)     ";
    string tree3 = "        \\A         ";
    string tree2 = "         H         ";
    string tree1 = "         H         ";
    string tree0 = "         H         ";

    tree.append(tree16);
    tree.append(tree15);
    tree.append(tree14);
    tree.append(tree13);
    tree.append(tree12);
    tree.append(tree11);
    tree.append(tree10);
    tree.append(tree9);
    tree.append(tree8);
    tree.append(tree7);
    tree.append(tree6);
    tree.append(tree5);
    tree.append(tree4);
    tree.append(tree3);
    tree.append(tree2);
    tree.append(tree1);
    tree.append(tree0);
}

void FillTree26(string& tree)
{
    string tree16 = "                   "; //x= 19; y = 17
    string tree15 = "                   ";
    string tree14 = "                   ";
    string tree13 = "                   ";
    string tree12 = "                   ";
    string tree11 = "     .---.         ";
    string tree10 = "    (      )       ";
    string tree9 = "   (   \\_/    )    ";
    string tree8 = "   (\\    \\/__/     ";
    string tree7 = "  (  \\_  /    )    ";
    string tree6 = "  (  \\_\\/  _/)     ";
    string tree5 = "   (    \\ /  )     ";
    string tree4 = "    (\\__ V __)     ";
    string tree3 = "        \\A         ";
    string tree2 = "         H         ";
    string tree1 = "         H         ";
    string tree0 = "         H         ";

    tree.append(tree16);
    tree.append(tree15);
    tree.append(tree14);
    tree.append(tree13);
    tree.append(tree12);
    tree.append(tree11);
    tree.append(tree10);
    tree.append(tree9);
    tree.append(tree8);
    tree.append(tree7);
    tree.append(tree6);
    tree.append(tree5);
    tree.append(tree4);
    tree.append(tree3);
    tree.append(tree2);
    tree.append(tree1);
    tree.append(tree0);
}

void FillTree27(string& tree)
{
    string tree16 = "                   "; //x= 19; y = 17
    string tree15 = "                   ";
    string tree14 = "                   ";
    string tree13 = "                   ";
    string tree12 = "        __         ";
    string tree11 = "      (   )        ";
    string tree10 = "    (_   / )       ";
    string tree9 = "   (   \\_/ /  )    ";
    string tree8 = "   (\\    \\/__/     ";
    string tree7 = "  (  \\_  /    )    ";
    string tree6 = "  (  \\_\\/  _/)     ";
    string tree5 = "   (    \\ /  )     ";
    string tree4 = "    (\\__ V __)     ";
    string tree3 = "        \\A         ";
    string tree2 = "         H         ";
    string tree1 = "         H         ";
    string tree0 = "         H         ";

    tree.append(tree16);
    tree.append(tree15);
    tree.append(tree14);
    tree.append(tree13);
    tree.append(tree12);
    tree.append(tree11);
    tree.append(tree10);
    tree.append(tree9);
    tree.append(tree8);
    tree.append(tree7);
    tree.append(tree6);
    tree.append(tree5);
    tree.append(tree4);
    tree.append(tree3);
    tree.append(tree2);
    tree.append(tree1);
    tree.append(tree0);
}

void FillTree28(string& tree)
{
    string tree16 = "                   "; //x= 19; y = 17
    string tree15 = "                   ";
    string tree14 = "                   ";
    string tree13 = "                   ";
    string tree12 = "      (   )        ";
    string tree11 = "    (_   / )       ";
    string tree10 = "   (  \\_/ /  )    ";
    string tree9 = "   (\\    \\/__/     ";
    string tree8 = "  (  \\_  /    )    ";
    string tree7 = "   (\\__\\/  _/)     ";
    string tree6 = "   (    \\ /  )     ";
    string tree5 = "    (\\__ V __)     ";
    string tree4 = "        \\A         ";
    string tree3 = "         H         ";
    string tree2 = "         H         ";
    string tree1 = "         H         ";
    string tree0 = "         H         ";

    tree.append(tree16);
    tree.append(tree15);
    tree.append(tree14);
    tree.append(tree13);
    tree.append(tree12);
    tree.append(tree11);
    tree.append(tree10);
    tree.append(tree9);
    tree.append(tree8);
    tree.append(tree7);
    tree.append(tree6);
    tree.append(tree5);
    tree.append(tree4);
    tree.append(tree3);
    tree.append(tree2);
    tree.append(tree1);
    tree.append(tree0);
}

void FillTree29(string& tree)
{
    string tree16 = "                   "; //x= 19; y = 17
    string tree15 = "                   ";
    string tree14 = "                   ";
    string tree13 = "    .--.---.       ";
    string tree12 = "   (        )      ";
    string tree11 = "  ( \\_/  / _ )     ";
    string tree10 = " (_   \\_/ /  _)    ";
    string tree9 = " (  \\    \\/__/ )   ";
    string tree8 = " (__ \\_  /     )   ";
    string tree7 = " (  \\__\\/  _/_)    ";
    string tree6 = "  ( _   \\ /   )    ";
    string tree5 = "   ( \\__ H __)     ";
    string tree4 = "        \\H         ";
    string tree3 = "         H         ";
    string tree2 = "         H         ";
    string tree1 = "         H         ";
    string tree0 = "         H         ";

    tree.append(tree16);
    tree.append(tree15);
    tree.append(tree14);
    tree.append(tree13);
    tree.append(tree12);
    tree.append(tree11);
    tree.append(tree10);
    tree.append(tree9);
    tree.append(tree8);
    tree.append(tree7);
    tree.append(tree6);
    tree.append(tree5);
    tree.append(tree4);
    tree.append(tree3);
    tree.append(tree2);
    tree.append(tree1);
    tree.append(tree0);
}

void FillTree30(string& tree)
{
    string tree16 = "                   "; //x= 19; y = 17
    string tree15 = "                   ";
    string tree14 = "                   ";
    string tree13 = "    .--' )-.       ";
    string tree12 = "   (     \\  )      ";
    string tree11 = "  ( \\_/  / _ )     ";
    string tree10 = " (_   \\_/ /  _)    ";
    string tree9 = "(   \\    \\/__/  )  ";
    string tree8 = "( __ \\_  /   __ )  ";
    string tree7 = " (  \\__\\/  _/__)   ";
    string tree6 = "  ( _   \\ /  _ )   ";
    string tree5 = "   ( \\__ H _/ )    ";
    string tree4 = "        \\H         ";
    string tree3 = "         H         ";
    string tree2 = "         H         ";
    string tree1 = "         H         ";
    string tree0 = "         H         ";

    tree.append(tree16);
    tree.append(tree15);
    tree.append(tree14);
    tree.append(tree13);
    tree.append(tree12);
    tree.append(tree11);
    tree.append(tree10);
    tree.append(tree9);
    tree.append(tree8);
    tree.append(tree7);
    tree.append(tree6);
    tree.append(tree5);
    tree.append(tree4);
    tree.append(tree3);
    tree.append(tree2);
    tree.append(tree1);
    tree.append(tree0);
}

void FillTree31(string& tree)
{
    string tree16 = "                   "; //x= 19; y = 17
    string tree15 = "    .--.-'-.       ";
    string tree14 = "   (        )      ";
    string tree13 = "  (   \\  \\/  )     ";
    string tree12 = " (  \\_/  / _/ )    ";
    string tree11 = " (_   \\_/ /   _)   ";
    string tree10 = "(   \\   \\/__/  )   ";
    string tree9 = "( __ \\_  /   _/  ) ";
    string tree8 = " (  \\__\\/  _/   _) ";
    string tree7 = " ( __   \\ /  __/ ) ";
    string tree6 = "  (  \\__ H _/   )  ";
    string tree5 = "        \\H         ";
    string tree4 = "         H         ";
    string tree3 = "         H         ";
    string tree2 = "         H         ";
    string tree1 = "         H         ";
    string tree0 = "         H         ";

    tree.append(tree16);
    tree.append(tree15);
    tree.append(tree14);
    tree.append(tree13);
    tree.append(tree12);
    tree.append(tree11);
    tree.append(tree10);
    tree.append(tree9);
    tree.append(tree8);
    tree.append(tree7);
    tree.append(tree6);
    tree.append(tree5);
    tree.append(tree4);
    tree.append(tree3);
    tree.append(tree2);
    tree.append(tree1);
    tree.append(tree0);
}

void FillTree32(string& tree)
{
    string tree16 = "    .--.-'-.       "; //x = 19; y = 17
    string tree15 = "   (        )      ";
    string tree14 = "  (   \\  \\/  )     ";
    string tree13 = " (  \\_/  / _/ )    ";
    string tree12 = " (_   \\_/ /   _)   ";
    string tree11 = "(   \\   \\/__/  _)  ";
    string tree10 = "( __ \\_  /   _/  ) ";
    string tree9 = " (  \\__\\/  _/   _) ";
    string tree8 = " ( __   \\-/  __/ ) ";
    string tree7 = "  (  \\__ H _/   )  ";
    string tree6 = "   (    \\H     )   ";
    string tree5 = "         H         ";
    string tree4 = "         H         ";
    string tree3 = "         H         ";
    string tree2 = "         H         ";
    string tree1 = "         H         ";
    string tree0 = "         H         ";

    tree.append(tree16);
    tree.append(tree15);
    tree.append(tree14);
    tree.append(tree13);
    tree.append(tree12);
    tree.append(tree11);
    tree.append(tree10);
    tree.append(tree9);
    tree.append(tree8);
    tree.append(tree7);
    tree.append(tree6);
    tree.append(tree5);
    tree.append(tree4);
    tree.append(tree3);
    tree.append(tree2);
    tree.append(tree1);
    tree.append(tree0);
}

void FillTree33(string& tree)
{
    string tree16 = "    .--.-'-.       "; //x = 19; y = 17
    string tree15 = "   (        )      ";
    string tree14 = "  (   \\  \\/  )     ";
    string tree13 = " (  \\_/  / _/ )    ";
    string tree12 = " (_   \\_/ /  _ )   ";
    string tree11 = "(   \\   \\/__/  _)  ";
    string tree10 = "( __ \\_  /   _/ O) ";
    string tree9 = " (  \\__\\/  _/   _) ";
    string tree8 = " ( __   \\-/  __/ ) ";
    string tree7 = "  (  \\__ H _/   )  ";
    string tree6 = "   (    \\H     )   ";
    string tree5 = "         H         ";
    string tree4 = "         H         ";
    string tree3 = "         H         ";
    string tree2 = "         H         ";
    string tree1 = "         H         ";
    string tree0 = "         H         ";

    tree.append(tree16);
    tree.append(tree15);
    tree.append(tree14);
    tree.append(tree13);
    tree.append(tree12);
    tree.append(tree11);
    tree.append(tree10);
    tree.append(tree9);
    tree.append(tree8);
    tree.append(tree7);
    tree.append(tree6);
    tree.append(tree5);
    tree.append(tree4);
    tree.append(tree3);
    tree.append(tree2);
    tree.append(tree1);
    tree.append(tree0);
}

void FillTree34(string& tree)
{
    string tree16 = "    .--.-'-.       "; //x = 19; y = 17
    string tree15 = "   (        )      ";
    string tree14 = "  (O  \\  \\/  )     ";
    string tree13 = " (  \\_/  / _/ )    ";
    string tree12 = " (_   \\_/ /  _ )   ";
    string tree11 = "(   \\   \\/__/  _)  ";
    string tree10 = "( __ \\_  /   _/ O) ";
    string tree9 = " (  \\__\\/  _/   _) ";
    string tree8 = " ( __   \\-/  __/ ) ";
    string tree7 = "  (  \\__ H _/   )  ";
    string tree6 = "   (o   \\H     )   ";
    string tree5 = "         H         ";
    string tree4 = "         H         ";
    string tree3 = "         H         ";
    string tree2 = "         H         ";
    string tree1 = "         H         ";
    string tree0 = "         H         ";

    tree.append(tree16);
    tree.append(tree15);
    tree.append(tree14);
    tree.append(tree13);
    tree.append(tree12);
    tree.append(tree11);
    tree.append(tree10);
    tree.append(tree9);
    tree.append(tree8);
    tree.append(tree7);
    tree.append(tree6);
    tree.append(tree5);
    tree.append(tree4);
    tree.append(tree3);
    tree.append(tree2);
    tree.append(tree1);
    tree.append(tree0);
}

void FillTree35(string& tree)
{
    string tree16 = "    .--.-'-.       "; //x = 19; y = 17
    string tree15 = "   ( o      )      ";
    string tree14 = "  (O  \\  \\/  )     ";
    string tree13 = " (  \\_/  / _/ )    ";
    string tree12 = " (_   \\_/ /  _O)   ";
    string tree11 = "(   \\   \\/__/  _)  ";
    string tree10 = "( __ \\_  /   _/ O) ";
    string tree9 = " (  \\__\\/  _/   _) ";
    string tree8 = " ( __ Q \\-/ O__/ ) ";
    string tree7 = "  (  \\__ H _/   )  ";
    string tree6 = "   (o   \\H     )   ";
    string tree5 = "         H         ";
    string tree4 = "         H         ";
    string tree3 = "         H         ";
    string tree2 = "         H         ";
    string tree1 = "         H         ";
    string tree0 = "         H         ";

    tree.append(tree16);
    tree.append(tree15);
    tree.append(tree14);
    tree.append(tree13);
    tree.append(tree12);
    tree.append(tree11);
    tree.append(tree10);
    tree.append(tree9);
    tree.append(tree8);
    tree.append(tree7);
    tree.append(tree6);
    tree.append(tree5);
    tree.append(tree4);
    tree.append(tree3);
    tree.append(tree2);
    tree.append(tree1);
    tree.append(tree0);
}

void FillTree36(string& tree)
{
    string tree16 = "    .--.-'-.       "; //x = 19; y = 17
    string tree15 = "   ( o      )      ";
    string tree14 = "  (O  \\  \\/ O)     ";
    string tree13 = " (  \\_/  / _/ )    ";
    string tree12 = " (_   \\_/ /  _O)   ";
    string tree11 = "(   \\   \\/__/  _)  ";
    string tree10 = "( __O\\_  /   _/ O) ";
    string tree9 = " (  \\__\\/  _/   _) ";
    string tree8 = " ( __ Q \\-/ O__/ ) ";
    string tree7 = "  (  \\__ H _/   )  ";
    string tree6 = "   (o   \\H    Q)   ";
    string tree5 = "         H         ";
    string tree4 = "         H         ";
    string tree3 = "         H         ";
    string tree2 = "         H         ";
    string tree1 = "         H         ";
    string tree0 = "         H         ";

    tree.append(tree16);
    tree.append(tree15);
    tree.append(tree14);
    tree.append(tree13);
    tree.append(tree12);
    tree.append(tree11);
    tree.append(tree10);
    tree.append(tree9);
    tree.append(tree8);
    tree.append(tree7);
    tree.append(tree6);
    tree.append(tree5);
    tree.append(tree4);
    tree.append(tree3);
    tree.append(tree2);
    tree.append(tree1);
    tree.append(tree0);
}

void FillTree37(string& tree)
{
    string tree16 = "    .--.-'-.       "; //x = 19; y = 17
    string tree15 = "   ( o      )      ";
    string tree14 = "  (O  \\  \\/ O)     ";
    string tree13 = " (  \\_/  / _/ )    ";
    string tree12 = " (_Q  \\_/ /o _O)   ";
    string tree11 = "(   \\   \\/__/  _)  ";
    string tree10 = "( __O\\_  /   _/ O) ";
    string tree9 = " (  \\__\\/  _/   _) ";
    string tree8 = " (O__ Q \\-/ O__/ ) ";
    string tree7 = "  (  \\__ H _/   )  ";
    string tree6 = "   (o   \\H    Q)   ";
    string tree5 = "         H         ";
    string tree4 = "         H         ";
    string tree3 = "         H         ";
    string tree2 = "         H         ";
    string tree1 = "         H         ";
    string tree0 = "         H         ";

    tree.append(tree16);
    tree.append(tree15);
    tree.append(tree14);
    tree.append(tree13);
    tree.append(tree12);
    tree.append(tree11);
    tree.append(tree10);
    tree.append(tree9);
    tree.append(tree8);
    tree.append(tree7);
    tree.append(tree6);
    tree.append(tree5);
    tree.append(tree4);
    tree.append(tree3);
    tree.append(tree2);
    tree.append(tree1);
    tree.append(tree0);
}

void FillTree38(string& tree)
{
    string tree16 = "    .--.-'-.       "; //x = 19; y = 17
    string tree15 = "   ( o  O   )      ";
    string tree14 = "  (O  \\  \\/ O)     ";
    string tree13 = " (  \\_/  / _/ )    ";
    string tree12 = " (_Q  \\_/ /o _O)   ";
    string tree11 = "(o  \\   \\/__/  _)  ";
    string tree10 = "( __O\\_  /  Q_/ O) ";
    string tree9 = " (  \\__\\/  _/   _) ";
    string tree8 = " (O__ Q \\-/ O__/ ) ";
    string tree7 = "  (  \\__ H _/   )  ";
    string tree6 = "   (o   \\H    Q)   ";
    string tree5 = "         H         ";
    string tree4 = "         H         ";
    string tree3 = "         H         ";
    string tree2 = "         H         ";
    string tree1 = "         H         ";
    string tree0 = "         H         ";

    tree.append(tree16);
    tree.append(tree15);
    tree.append(tree14);
    tree.append(tree13);
    tree.append(tree12);
    tree.append(tree11);
    tree.append(tree10);
    tree.append(tree9);
    tree.append(tree8);
    tree.append(tree7);
    tree.append(tree6);
    tree.append(tree5);
    tree.append(tree4);
    tree.append(tree3);
    tree.append(tree2);
    tree.append(tree1);
    tree.append(tree0);
}

void FillTree39(string& tree)
{
    string tree16 = "    .--.-'-.       "; //x = 19; y = 17
    string tree15 = "   ( o  O   )      ";
    string tree14 = "  (O  \\  \\/ O)     ";
    string tree13 = " (  \\_/ O/ _/ )    ";
    string tree12 = " (_Q  \\_/ /o _O)   ";
    string tree11 = "(o  \\ O \\/__/  _)  ";
    string tree10 = "( __O\\_  /  Q_/ O) ";
    string tree9 = " (  \\__\\/  _/  o_) ";
    string tree8 = " (O__ Q \\-/ O__/ ) ";
    string tree7 = "  (  \\__ H _/   )  ";
    string tree6 = "   (o   \\H    Q)   ";
    string tree5 = "         H         ";
    string tree4 = "         H         ";
    string tree3 = "         H         ";
    string tree2 = "         H         ";
    string tree1 = "         H         ";
    string tree0 = "         H         ";

    tree.append(tree16);
    tree.append(tree15);
    tree.append(tree14);
    tree.append(tree13);
    tree.append(tree12);
    tree.append(tree11);
    tree.append(tree10);
    tree.append(tree9);
    tree.append(tree8);
    tree.append(tree7);
    tree.append(tree6);
    tree.append(tree5);
    tree.append(tree4);
    tree.append(tree3);
    tree.append(tree2);
    tree.append(tree1);
    tree.append(tree0);
}

void FillTree40(string& tree)
{
    string tree16 = "    .--.-'-.       "; //x = 19; y = 17
    string tree15 = "   ( o  O  Q)      ";
    string tree14 = "  (O  \\  \\/ O)     ";
    string tree13 = " (  \\_/ O/ _/ )    ";
    string tree12 = " (_Q  \\_/ /o _O)   ";
    string tree11 = "(o  \\ O \\/__/  _)  ";
    string tree10 = "( __O\\_  /  Q_/ O) ";
    string tree9 = " (  \\__\\/o _/  o_) ";
    string tree8 = " (O__ Q \\-/ O__/ )O";
    string tree7 = "  (  \\__ H _/   )  ";
    string tree6 = "   (o   \\H    Q)   ";
    string tree5 = "         H         ";
    string tree4 = "         H         ";
    string tree3 = "         H         ";
    string tree2 = "         H         ";
    string tree1 = "         H         ";
    string tree0 = "         H         ";

    tree.append(tree16);
    tree.append(tree15);
    tree.append(tree14);
    tree.append(tree13);
    tree.append(tree12);
    tree.append(tree11);
    tree.append(tree10);
    tree.append(tree9);
    tree.append(tree8);
    tree.append(tree7);
    tree.append(tree6);
    tree.append(tree5);
    tree.append(tree4);
    tree.append(tree3);
    tree.append(tree2);
    tree.append(tree1);
    tree.append(tree0);
}

void FillFireWorks1(string& tree)
{
    string tree7 = "                 "; //x = 17, y = 8
    string tree6 = "                 ";
    string tree5 = "                 ";
    string tree4 = "      _\\|/_      ";
    string tree3 = "      '/|\\'      ";
    string tree2 = "                 ";
    string tree1 = "                 ";
    string tree0 = "                 ";

    tree.append(tree7);
    tree.append(tree6);
    tree.append(tree5);
    tree.append(tree4);
    tree.append(tree3);
    tree.append(tree2);
    tree.append(tree1);
    tree.append(tree0);
}

void FillFireWorks2(string& tree)
{
    string tree7 = "                 "; //x = 17, y = 8
    string tree6 = "                 ";
    string tree5 = "    '\\\\'|'//'    ";
    string tree4 = "    '_\\\\|//_'    ";
    string tree3 = "    .'//|\\\\'.    ";
    string tree2 = "    .//.|.\\\\.    ";
    string tree1 = "                 ";
    string tree0 = "                 ";

    tree.append(tree7);
    tree.append(tree6);
    tree.append(tree5);
    tree.append(tree4);
    tree.append(tree3);
    tree.append(tree2);
    tree.append(tree1);
    tree.append(tree0);
}

void FillFireWorks3(string& tree)
{
    string tree7 = "                 "; //x = 17, y = 8
    string tree6 = "    .\\'.|.'/ .   ";
    string tree5 = "    '\\\\'|'//'    ";
    string tree4 = "    '_\\.'./_'    ";
    string tree3 = "    .'/'.'\\'.    ";
    string tree2 = "    .//.|.\\\\.    ";
    string tree1 = "     /.'|'.\\     ";
    string tree0 = "                 ";

    tree.append(tree7);
    tree.append(tree6);
    tree.append(tree5);
    tree.append(tree4);
    tree.append(tree3);
    tree.append(tree2);
    tree.append(tree1);
    tree.append(tree0);
}

void FillFireWorks4(string& tree)
{
    string tree7 = "  . \\. '|' ./  . "; //x = 17, y = 8
    string tree6 = "'. '\\\\'.|.'//.'.'";
    string tree5 = "'.'\\'..'.'..'/'.'";
    string tree4 = "...-'_'.'.'_'-...";
    string tree3 = "'''/.'.'.'.'.\\'''";
    string tree2 = ".'.'.''.'.''.'.'.";
    string tree1 = ".'.'//.'|'.\\\\'.'.";
    string tree0 = "  ' /' .|. '\\  ' ";

    tree.append(tree7);
    tree.append(tree6);
    tree.append(tree5);
    tree.append(tree4);
    tree.append(tree3);
    tree.append(tree2);
    tree.append(tree1);
    tree.append(tree0);
}

void FillFireWorks5(string& tree)
{
    string tree7 = "  .\\\\. '|' .// . "; //x = 17, y = 8
    string tree6 = "'.\\'..'.'.'.'./.'";
    string tree5 = "'.' ' .'.'. ' '.'";
    string tree4 = ".-- '. .'. .' --.";
    string tree3 = "''' .' '.' '. '''";
    string tree2 = ".'/'.  . .  .'\\'.";
    string tree1 = ".'.'.'.'.'.'.'.'.";
    string tree0 = "  '//' .|. '\\\\ ' ";

    tree.append(tree7);
    tree.append(tree6);
    tree.append(tree5);
    tree.append(tree4);
    tree.append(tree3);
    tree.append(tree2);
    tree.append(tree1);
    tree.append(tree0);
}

void FillFireWorks6(string& tree)
{
    string tree7 = "  '\\'.''.''.'/'  "; //x = 17, y = 8
    string tree6 = "'. '  '. .'  ' .'";
    string tree5 = "'.' '  ' '  ' '.'";
    string tree4 = "-.. ' . ' . ' ..-";
    string tree3 = "''. . ' . ' . .''";
    string tree2 = ".' '.  . .  .' '.";
    string tree1 = "./.'  .' '.  '.\\.";
    string tree0 = "  '/ '..'..' \\ ' ";

    tree.append(tree7);
    tree.append(tree6);
    tree.append(tree5);
    tree.append(tree4);
    tree.append(tree3);
    tree.append(tree2);
    tree.append(tree1);
    tree.append(tree0);
}

void FillFireWorks7(string& tree)
{
    string tree7 = "  '  .' . '.  '  "; //x = 17, y = 8
    string tree6 = " . ' . . . . ' . ";
    string tree5 = "' '    ' '    ' '";
    string tree4 = " ..  .  '  .  .. ";
    string tree3 = "' .  '  .  '  . '";
    string tree2 = ".' '   . .   ' '.";
    string tree1 = "  .' . ' ' . '.  ";
    string tree0 = " '   '. ' .'   ' ";

    tree.append(tree7);
    tree.append(tree6);
    tree.append(tree5);
    tree.append(tree4);
    tree.append(tree3);
    tree.append(tree2);
    tree.append(tree1);
    tree.append(tree0);
}

void FillFireWorks8(string& tree)
{
    string tree7 = "     .'   '.     "; //x = 17, y = 8
    string tree6 = " . '   . .   ' . ";
    string tree5 = "' '     '     ' '";
    string tree4 = " .   .  '  .   . ";
    string tree3 = "' .  '  .  '  . '";
    string tree2 = " ' '   . .   ' ' ";
    string tree1 = "  .' .  '  . '.  ";
    string tree0 = "     '.   .'     ";

    tree.append(tree7);
    tree.append(tree6);
    tree.append(tree5);
    tree.append(tree4);
    tree.append(tree3);
    tree.append(tree2);
    tree.append(tree1);
    tree.append(tree0);
}

void FillFireWorks9(string& tree)
{
    string tree7 = "     .     .     "; //x = 17, y = 8
    string tree6 = " . '   . .   ' . ";
    string tree5 = "                 ";
    string tree4 = " .   .  '  .   . ";
    string tree3 = "  .  '     '  .  ";
    string tree2 = " '     . .     ' ";
    string tree1 = "  .  .     .  .  ";
    string tree0 = "      .   .      ";

    tree.append(tree7);
    tree.append(tree6);
    tree.append(tree5);
    tree.append(tree4);
    tree.append(tree3);
    tree.append(tree2);
    tree.append(tree1);
    tree.append(tree0);
}

void FillCloud1(string& cloud)
{
    string cloud3 = "       "; //x = 7, y = 4
    string cloud2 = " (     ";
    string cloud1 = "       ";
    string cloud0 = "       ";

    cloud.append(cloud3);
    cloud.append(cloud2);
    cloud.append(cloud1);
    cloud.append(cloud0);
}

void FillCloud2(string& cloud)
{
    string cloud3 = "  ___  "; //x = 7, y = 4
    string cloud2 = " (     ";
    string cloud1 = "       ";
    string cloud0 = "       ";

    cloud.append(cloud3);
    cloud.append(cloud2);
    cloud.append(cloud1);
    cloud.append(cloud0);
}

void FillCloud3(string& cloud)
{
    string cloud3 = "  ___  "; //x = 7, y = 4
    string cloud2 = " (   ) ";
    string cloud1 = "       ";
    string cloud0 = "       ";

    cloud.append(cloud3);
    cloud.append(cloud2);
    cloud.append(cloud1);
    cloud.append(cloud0);
}

void FillCloud4(string& cloud)
{
    string cloud3 = "  ___  "; //x = 7, y = 4
    string cloud2 = " (   ) ";
    string cloud1 = "      )";
    string cloud0 = "       ";

    cloud.append(cloud3);
    cloud.append(cloud2);
    cloud.append(cloud1);
    cloud.append(cloud0);
}

void FillCloud5(string& cloud)
{
    string cloud3 = "  ___  "; //x = 7, y = 4
    string cloud2 = " (   ) ";
    string cloud1 = "      )";
    string cloud0 = "     ) ";

    cloud.append(cloud3);
    cloud.append(cloud2);
    cloud.append(cloud1);
    cloud.append(cloud0);
}

void FillCloud6(string& cloud)
{
    string cloud3 = "  ___  "; //x = 7, y = 4
    string cloud2 = " (   ) ";
    string cloud1 = "      )";
    string cloud0 = "  ___) ";

    cloud.append(cloud3);
    cloud.append(cloud2);
    cloud.append(cloud1);
    cloud.append(cloud0);
}

void FillCloud7(string& cloud)
{
    string cloud3 = "  ___  "; //x = 7, y = 4
    string cloud2 = " (   ) ";
    string cloud1 = "      )";
    string cloud0 = " (___) ";

    cloud.append(cloud3);
    cloud.append(cloud2);
    cloud.append(cloud1);
    cloud.append(cloud0);
}

void FillCloud8(string& cloud)
{
    string cloud3 = "  ___  "; //x = 7, y = 4
    string cloud2 = " (   ) ";
    string cloud1 = "(     )";
    string cloud0 = " (___) ";

    cloud.append(cloud3);
    cloud.append(cloud2);
    cloud.append(cloud1);
    cloud.append(cloud0);
}

void FillCloud9(string& cloud)
{
    string cloud7 = "                        "; //x = 24, y = 8
    string cloud6 = "                        ";
    string cloud5 = "            ___         ";
    string cloud4 = "           (    )       ";
    string cloud3 = "          (      )      ";
    string cloud2 = "            (___)       ";
    string cloud1 = "                        ";
    string cloud0 = "                        ";

    cloud.append(cloud7);
    cloud.append(cloud6);
    cloud.append(cloud5);
    cloud.append(cloud4);
    cloud.append(cloud3);
    cloud.append(cloud2);
    cloud.append(cloud1);
    cloud.append(cloud0);
}

void FillCloud10(string& cloud)
{
    string cloud7 = "                        "; //x = 24, y = 8
    string cloud6 = "                        ";
    string cloud5 = "             ___        ";
    string cloud4 = "           (     )      ";
    string cloud3 = "          (       )     ";
    string cloud2 = "            (____)      ";
    string cloud1 = "                        ";
    string cloud0 = "                        ";

    cloud.append(cloud7);
    cloud.append(cloud6);
    cloud.append(cloud5);
    cloud.append(cloud4);
    cloud.append(cloud3);
    cloud.append(cloud2);
    cloud.append(cloud1);
    cloud.append(cloud0);
}

void FillCloud11(string& cloud)
{
    string cloud7 = "                        "; //x = 24, y = 8
    string cloud6 = "                        ";
    string cloud5 = "             ___        ";
    string cloud4 = "           (     )      ";
    string cloud3 = "          (       ))    ";
    string cloud2 = "            (____))     ";
    string cloud1 = "                        ";
    string cloud0 = "                        ";

    cloud.append(cloud7);
    cloud.append(cloud6);
    cloud.append(cloud5);
    cloud.append(cloud4);
    cloud.append(cloud3);
    cloud.append(cloud2);
    cloud.append(cloud1);
    cloud.append(cloud0);
}

void FillCloud12(string& cloud)
{
    string cloud7 = "                        "; //x = 24, y = 8
    string cloud6 = "                        ";
    string cloud5 = "             ___- __    ";
    string cloud4 = "           (     )  )   ";
    string cloud3 = "          (       )  )  ";
    string cloud2 = "            (____)  )   ";
    string cloud1 = "             ------'    ";
    string cloud0 = "                        ";

    cloud.append(cloud7);
    cloud.append(cloud6);
    cloud.append(cloud5);
    cloud.append(cloud4);
    cloud.append(cloud3);
    cloud.append(cloud2);
    cloud.append(cloud1);
    cloud.append(cloud0);
}

void FillCloud13(string& cloud)
{
    string cloud7 = "                        "; //x = 24, y = 8
    string cloud6 = "                        ";
    string cloud5 = "             ___-- __   ";
    string cloud4 = "           (      )  )  ";
    string cloud3 = "          (        )  ) ";
    string cloud2 = "            (__-__)  )  ";
    string cloud1 = "             --'----'   ";
    string cloud0 = "                        ";

    cloud.append(cloud7);
    cloud.append(cloud6);
    cloud.append(cloud5);
    cloud.append(cloud4);
    cloud.append(cloud3);
    cloud.append(cloud2);
    cloud.append(cloud1);
    cloud.append(cloud0);
}

void FillCloud14(string& cloud)
{
    string cloud7 = "                        "; //x = 24, y = 8
    string cloud6 = "                        ";
    string cloud5 = "             ___--- __  ";
    string cloud4 = "           (       )  ) ";
    string cloud3 = "          (         )  )";
    string cloud2 = "            (__--__)  ) ";
    string cloud1 = "             --''----'  ";
    string cloud0 = "                        ";

    cloud.append(cloud7);
    cloud.append(cloud6);
    cloud.append(cloud5);
    cloud.append(cloud4);
    cloud.append(cloud3);
    cloud.append(cloud2);
    cloud.append(cloud1);
    cloud.append(cloud0);
}

void FillCloud15(string& cloud)
{
    string cloud7 = "                        "; //x = 24, y = 8
    string cloud6 = "                        ";
    string cloud5 = "           . ___--- __  ";
    string cloud4 = "          /(       )  ) ";
    string cloud3 = "          (         )  )";
    string cloud2 = "            (__--__)  ) ";
    string cloud1 = "             --''----'  ";
    string cloud0 = "                        ";

    cloud.append(cloud7);
    cloud.append(cloud6);
    cloud.append(cloud5);
    cloud.append(cloud4);
    cloud.append(cloud3);
    cloud.append(cloud2);
    cloud.append(cloud1);
    cloud.append(cloud0);
}

void FillCloud16(string& cloud)
{
    string cloud7 = "                        "; //x = 24, y = 8
    string cloud6 = "        \\               ";
    string cloud5 = "          .- ___--- __  ";
    string cloud4 = "     ___ / (       )  ) ";
    string cloud3 = "         |(         )  )";
    string cloud2 = "          *-(__--__)  ) ";
    string cloud1 = "         /   --''----'  ";
    string cloud0 = "                        ";

    cloud.append(cloud7);
    cloud.append(cloud6);
    cloud.append(cloud5);
    cloud.append(cloud4);
    cloud.append(cloud3);
    cloud.append(cloud2);
    cloud.append(cloud1);
    cloud.append(cloud0);
}

void FillCloud17(string& cloud)
{
    string cloud7 = "           |            "; //x = 24, y = 8
    string cloud6 = "       \\   |            ";
    string cloud5 = "         .-* ___--- __  ";
    string cloud4 = "    ___ /  (       )  ) ";
    string cloud3 = "        | (         )  )";
    string cloud2 = "         *-.(__--__)  ) ";
    string cloud1 = "        /    --''----'  ";
    string cloud0 = "                        ";

    cloud.append(cloud7);
    cloud.append(cloud6);
    cloud.append(cloud5);
    cloud.append(cloud4);
    cloud.append(cloud3);
    cloud.append(cloud2);
    cloud.append(cloud1);
    cloud.append(cloud0);
}

void FillCloud18(string& cloud)
{
    string cloud7 = "          |             "; //x = 24, y = 8
    string cloud6 = "      \\   |   /         ";
    string cloud5 = "        .-** ___--- __  ";
    string cloud4 = "   ___ /   (       )  ) ";
    string cloud3 = "       |  (         )  )";
    string cloud2 = "        *-..(__--__)  ) ";
    string cloud1 = "       /   | --''----'  ";
    string cloud0 = "           |            ";

    cloud.append(cloud7);
    cloud.append(cloud6);
    cloud.append(cloud5);
    cloud.append(cloud4);
    cloud.append(cloud3);
    cloud.append(cloud2);
    cloud.append(cloud1);
    cloud.append(cloud0);
}

void FillCloud19(string& cloud)
{
    string cloud7 = "         |              "; //x = 24, y = 8
    string cloud6 = "     \\   |   /          ";
    string cloud5 = "       .-**- ___--- __  ";
    string cloud4 = "  ___ /    (       )  ) ";
    string cloud3 = "      |   (         )  )";
    string cloud2 = "       *-..-(__--__)  ) ";
    string cloud1 = "      /   |  --''----'  ";
    string cloud0 = "          |             ";

    cloud.append(cloud7);
    cloud.append(cloud6);
    cloud.append(cloud5);
    cloud.append(cloud4);
    cloud.append(cloud3);
    cloud.append(cloud2);
    cloud.append(cloud1);
    cloud.append(cloud0);
}

void FillCloud20(string& cloud)
{
    string cloud7 = "        |               "; //x = 24, y = 8
    string cloud6 = "    \\   |   /           ";
    string cloud5 = "      .-**-. ___--- __  ";
    string cloud4 = " ___ /     (       )  ) ";
    string cloud3 = "     |    (         )  )";
    string cloud2 = "      *-..-*(__--__)  ) ";
    string cloud1 = "     /   |   --''----'  ";
    string cloud0 = "         |              ";

    cloud.append(cloud7);
    cloud.append(cloud6);
    cloud.append(cloud5);
    cloud.append(cloud4);
    cloud.append(cloud3);
    cloud.append(cloud2);
    cloud.append(cloud1);
    cloud.append(cloud0);
}

void FillCloud21(string& cloud)
{
    string cloud7 = "       |                "; //x = 24, y = 8
    string cloud6 = "   \\   |   /            ";
    string cloud5 = "     .-**-.  ___--- __  ";
    string cloud4 = "___ /      (       )  ) ";
    string cloud3 = "    |     (         )  )";
    string cloud2 = "     *-..-* (__--__)  ) ";
    string cloud1 = "    /   |   \\--''----'  ";
    string cloud0 = "        |               ";

    cloud.append(cloud7);
    cloud.append(cloud6);
    cloud.append(cloud5);
    cloud.append(cloud4);
    cloud.append(cloud3);
    cloud.append(cloud2);
    cloud.append(cloud1);
    cloud.append(cloud0);
}




