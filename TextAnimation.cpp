#include "textAnimation.h"
#include <cstring>

int main()
{
    srand(time(0));

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

    /**fill clear space area**/
    string clearSpace = " "; //no build needed
    COORD clearSpaceSize = {numX, numY};
    CHAR_INFO clearSpaceArr[clearSpaceSize.X * clearSpaceSize.Y];
    WORD clearSpaceColor = 0;
    FillSingleCharArray(clearSpace, clearSpaceArr, clearSpaceSize.X * clearSpaceSize.Y, clearSpaceColor);

    /**data structure for object variables and object frames**/
    ObjectVariables stickManVar; //stickMan
    FillObjectVariables(stickManVar, 11, 10, 40, 20, 11);
    //(structName, width, height, fillCoordX, fillCoordY, color)

    ObjectVariables stickManLightSaberVar; //stickMan
    FillObjectVariables(stickManLightSaberVar, 35, 15, 40, 20, 11);
    //(structName, width, height, fillCoordX, fillCoordY, color)

    ObjectVariables swordHandleVar; //stickMan
    FillObjectVariables(swordHandleVar, 1, 2, 40, 20, 6);
    //(structName, width, height, fillCoordX, fillCoordY, color)

    ObjectVariables stickManWatchFireWorksVar; //stickMan
    FillObjectVariables(stickManWatchFireWorksVar, 16, 10, 40, 20, 11);
    //(structName, width, height, fillCoordX, fillCoordY, color)

    ObjectVariables dogVar; //dog
    FillObjectVariables(dogVar, 15, 8, 90, 22, 14);
    //(structName, width, height, fillCoordX, fillCoordY, color)

    ObjectVariables treeVar; //tree
    FillObjectVariables(treeVar, 19, 17, 50, 13, 10);
    //(structName, width, height, fillCoordX, fillCoordY, color)

    ObjectVariables fireWorksVar; //tree
    FillObjectVariables(fireWorksVar, 17, 8, 50, 3, 10);
    //(structName, width, height, fillCoordX, fillCoordY, color)

    ObjectVariables cloudOneVar; //tree
    FillObjectVariables(cloudOneVar, 7, 4, 50, 3, 15);
    //(structName, width, height, fillCoordX, fillCoordY, color)

    ObjectVariables cloudTwoVar; //tree
    FillObjectVariables(cloudTwoVar, 24, 8, 50, 3, 15);
    //(structName, width, height, fillCoordX, fillCoordY, color)

    /**left movement string and array frames**/
    string standLeft;
    CHAR_INFO standLeftArr[stickManVar.length];
    string leftOne;
    CHAR_INFO leftOneArr[stickManVar.length];
    string leftTwo;
    CHAR_INFO leftTwoArr[stickManVar.length];
    string leftThree;
    CHAR_INFO leftThreeArr[stickManVar.length];
    string leftFour;
    CHAR_INFO leftFourArr[stickManVar.length];

    FillStandLeft(standLeft);
    FillLeftOne(leftOne);
    FillLeftTwo(leftTwo);
    FillLeftThree(leftThree);
    FillLeftFour(leftFour);

    FillObjectCharArray(standLeft, standLeftArr, stickManVar);
    FillObjectCharArray(leftOne, leftOneArr, stickManVar);
    FillObjectCharArray(leftTwo, leftTwoArr, stickManVar);
    FillObjectCharArray(leftThree, leftThreeArr, stickManVar);
    FillObjectCharArray(leftFour, leftFourArr, stickManVar);

    /**right movement string and array frames**/
    string standRight;
    CHAR_INFO standRightArr[stickManVar.length];
    string rightOne;
    CHAR_INFO rightOneArr[stickManVar.length];
    string rightTwo;
    CHAR_INFO rightTwoArr[stickManVar.length];
    string rightThree;
    CHAR_INFO rightThreeArr[stickManVar.length];
    string rightFour;
    CHAR_INFO rightFourArr[stickManVar.length];

    FillStandRight(standRight);
    FillRightOne(rightOne);
    FillRightTwo(rightTwo);
    FillRightThree(rightThree);
    FillRightFour(rightFour);

    FillObjectCharArray(standRight, standRightArr, stickManVar);
    FillObjectCharArray(rightOne, rightOneArr, stickManVar);
    FillObjectCharArray(rightTwo, rightTwoArr, stickManVar);
    FillObjectCharArray(rightThree, rightThreeArr, stickManVar);
    FillObjectCharArray(rightFour, rightFourArr, stickManVar);

    /**lightsaber string**/
    string swordHandle = "**";
    CHAR_INFO swordHandleArr[2];

    FillObjectCharArray(swordHandle, swordHandleArr, swordHandleVar);

    /**pull out lightsaber string and array frames**/
    string lightSaber1;
    string lightSaber2;
    string lightSaber3;
    string lightSaber4;
    string lightSaber5;
    string lightSaber6;
    string lightSaber7;
    string lightSaber8;
    string lightSaber9;
    string lightSaber10;
    string lightSaber11;
    string lightSaber12;
    string lightSaber13;
    string lightSaber14;
    string lightSaber15;
    string lightSaber16;
    string lightSaber17;
    string lightSaber18;
    string lightSaber19;
    string lightSaber20;
    string lightSaber21;
    string lightSaber22;
    string lightSaber23;
    string lightSaber24;
    CHAR_INFO lightSaber1Arr[stickManLightSaberVar.length];
    CHAR_INFO lightSaber2Arr[stickManLightSaberVar.length];
    CHAR_INFO lightSaber3Arr[stickManLightSaberVar.length];
    CHAR_INFO lightSaber4Arr[stickManLightSaberVar.length];
    CHAR_INFO lightSaber5Arr[stickManLightSaberVar.length];
    CHAR_INFO lightSaber6Arr[stickManLightSaberVar.length];
    CHAR_INFO lightSaber7Arr[stickManLightSaberVar.length];
    CHAR_INFO lightSaber8Arr[stickManLightSaberVar.length];
    CHAR_INFO lightSaber9Arr[stickManLightSaberVar.length];
    CHAR_INFO lightSaber10Arr[stickManLightSaberVar.length];
    CHAR_INFO lightSaber11Arr[stickManLightSaberVar.length];
    CHAR_INFO lightSaber12Arr[stickManLightSaberVar.length];
    CHAR_INFO lightSaber13Arr[stickManLightSaberVar.length];
    CHAR_INFO lightSaber14Arr[stickManLightSaberVar.length];
    CHAR_INFO lightSaber15Arr[stickManLightSaberVar.length];
    CHAR_INFO lightSaber16Arr[stickManLightSaberVar.length];
    CHAR_INFO lightSaber17Arr[stickManLightSaberVar.length];
    CHAR_INFO lightSaber18Arr[stickManLightSaberVar.length];
    CHAR_INFO lightSaber19Arr[stickManLightSaberVar.length];
    CHAR_INFO lightSaber20Arr[stickManLightSaberVar.length];
    CHAR_INFO lightSaber21Arr[stickManLightSaberVar.length];
    CHAR_INFO lightSaber22Arr[stickManLightSaberVar.length];
    CHAR_INFO lightSaber23Arr[stickManLightSaberVar.length];
    CHAR_INFO lightSaber24Arr[stickManLightSaberVar.length];

    FillLightSaber1(lightSaber1);
    FillLightSaber2(lightSaber2);
    FillLightSaber3(lightSaber3);
    FillLightSaber4(lightSaber4);
    FillLightSaber5(lightSaber5);
    FillLightSaber6(lightSaber6);
    FillLightSaber7(lightSaber7);
    FillLightSaber8(lightSaber8);
    FillLightSaber9(lightSaber9);
    FillLightSaber10(lightSaber10);
    FillLightSaber11(lightSaber11);
    FillLightSaber12(lightSaber12);
    FillLightSaber13(lightSaber13);
    FillLightSaber14(lightSaber14);
    FillLightSaber15(lightSaber15);
    FillLightSaber16(lightSaber16);
    FillLightSaber17(lightSaber17);
    FillLightSaber18(lightSaber18);
    FillLightSaber19(lightSaber19);
    FillLightSaber20(lightSaber20);
    FillLightSaber21(lightSaber21);
    FillLightSaber22(lightSaber22);
    FillLightSaber23(lightSaber23);
    FillLightSaber24(lightSaber24);

    int lightSaberColor = RandomTextColor();
    FillLightSaberCharArray(lightSaber1, lightSaber1Arr, stickManLightSaberVar, stickManVar, lightSaberColor);
    FillLightSaberCharArray(lightSaber2, lightSaber2Arr, stickManLightSaberVar, stickManVar, lightSaberColor);
    FillLightSaberCharArray(lightSaber3, lightSaber3Arr, stickManLightSaberVar, stickManVar, lightSaberColor);
    FillLightSaberCharArray(lightSaber4, lightSaber4Arr, stickManLightSaberVar, stickManVar, lightSaberColor);
    FillLightSaberCharArray(lightSaber5, lightSaber5Arr, stickManLightSaberVar, stickManVar, lightSaberColor);
    FillLightSaberCharArray(lightSaber6, lightSaber6Arr, stickManLightSaberVar, stickManVar, lightSaberColor);
    FillLightSaberCharArray(lightSaber7, lightSaber7Arr, stickManLightSaberVar, stickManVar, lightSaberColor);
    FillLightSaberCharArray(lightSaber8, lightSaber8Arr, stickManLightSaberVar, stickManVar, lightSaberColor);
    FillLightSaberCharArray(lightSaber9, lightSaber9Arr, stickManLightSaberVar, stickManVar, lightSaberColor);
    FillLightSaberCharArray(lightSaber10, lightSaber10Arr, stickManLightSaberVar, stickManVar, lightSaberColor);
    FillLightSaberCharArray(lightSaber11, lightSaber11Arr, stickManLightSaberVar, stickManVar, lightSaberColor);
    FillLightSaberCharArray(lightSaber12, lightSaber12Arr, stickManLightSaberVar, stickManVar, lightSaberColor);
    FillLightSaberCharArray(lightSaber13, lightSaber13Arr, stickManLightSaberVar, stickManVar, lightSaberColor);
    FillLightSaberCharArray(lightSaber14, lightSaber14Arr, stickManLightSaberVar, stickManVar, lightSaberColor);
    FillLightSaberCharArray(lightSaber15, lightSaber15Arr, stickManLightSaberVar, stickManVar, lightSaberColor);
    FillLightSaberCharArray(lightSaber16, lightSaber16Arr, stickManLightSaberVar, stickManVar, lightSaberColor);
    FillLightSaberCharArray(lightSaber17, lightSaber17Arr, stickManLightSaberVar, stickManVar, lightSaberColor);
    FillLightSaberCharArray(lightSaber18, lightSaber18Arr, stickManLightSaberVar, stickManVar, lightSaberColor);
    FillLightSaberCharArray(lightSaber19, lightSaber19Arr, stickManLightSaberVar, stickManVar, lightSaberColor);
    FillLightSaberCharArray(lightSaber20, lightSaber20Arr, stickManLightSaberVar, stickManVar, lightSaberColor);
    FillLightSaberCharArray(lightSaber21, lightSaber21Arr, stickManLightSaberVar, stickManVar, lightSaberColor);
    FillLightSaberCharArray(lightSaber22, lightSaber22Arr, stickManLightSaberVar, stickManVar, lightSaberColor);
    FillLightSaberCharArray(lightSaber23, lightSaber23Arr, stickManLightSaberVar, stickManVar, lightSaberColor);
    FillLightSaberCharArray(lightSaber24, lightSaber24Arr, stickManLightSaberVar, stickManVar, lightSaberColor);

    /**jump string and array frames**/
    string jumpOne;
    CHAR_INFO jumpOneArr[stickManVar.length];
    string jumpTwo;
    CHAR_INFO jumpTwoArr[stickManVar.length];

    FillJumpOne(jumpOne);
    FillJumpTwo(jumpTwo);

    FillObjectCharArray(jumpOne, jumpOneArr, stickManVar);
    FillObjectCharArray(jumpTwo, jumpTwoArr, stickManVar);

    /**scratch head string and array frames**/
    string scratchHeadOne;
    CHAR_INFO scratchHeadOneArr[stickManVar.length];
    string scratchHeadTwo;
    CHAR_INFO scratchHeadTwoArr[stickManVar.length];
    string scratchHeadThree;
    CHAR_INFO scratchHeadThreeArr[stickManVar.length];
    string scratchHeadFour;
    CHAR_INFO scratchHeadFourArr[stickManVar.length];
    string scratchHeadFive;
    CHAR_INFO scratchHeadFiveArr[stickManVar.length];

    FillScratchHeadOne(scratchHeadOne);
    FillScratchHeadTwo(scratchHeadTwo);
    FillScratchHeadThree(scratchHeadThree);
    FillScratchHeadFour(scratchHeadFour);
    FillScratchHeadFive(scratchHeadFive);

    FillObjectCharArray(scratchHeadOne, scratchHeadOneArr, stickManVar);
    FillObjectCharArray(scratchHeadTwo, scratchHeadTwoArr, stickManVar);
    FillObjectCharArray(scratchHeadThree, scratchHeadThreeArr, stickManVar);
    FillObjectCharArray(scratchHeadFour, scratchHeadFourArr, stickManVar);
    FillObjectCharArray(scratchHeadFive, scratchHeadFiveArr, stickManVar);

    /**light switch string and array frames**/
    string lightSwitchOne;
    CHAR_INFO lightSwitchOneArr[stickManVar.length];
    string lightSwitchTwo;
    CHAR_INFO lightSwitchTwoArr[stickManVar.length];
    string lightSwitchThree;
    CHAR_INFO lightSwitchThreeArr[stickManVar.length];
    string lightSwitchFour;
    CHAR_INFO lightSwitchFourArr[stickManVar.length];

    FillLightSwitchOne(lightSwitchOne);
    FillLightSwitchTwo(lightSwitchTwo);
    FillLightSwitchThree(lightSwitchThree);
    FillLightSwitchFour(lightSwitchFour);

    FillObjectCharArray(lightSwitchOne, lightSwitchOneArr, stickManVar);
    FillObjectCharArray(lightSwitchTwo, lightSwitchTwoArr, stickManVar);
    FillObjectCharArray(lightSwitchThree, lightSwitchThreeArr, stickManVar);
    FillObjectCharArray(lightSwitchFour, lightSwitchFourArr, stickManVar);

    /**check watch string and array frames**/
    string checkWatchOne;
    string checkWatchTwo;
    string checkWatchThree;
    FillCheckWatchOne(checkWatchOne);
    FillCheckWatchTwo(checkWatchTwo);
    FillCheckWatchThree(checkWatchThree);

    CHAR_INFO checkWatchOneArr[stickManVar.length];
    CHAR_INFO checkWatchTwoArr[stickManVar.length];
    CHAR_INFO checkWatchThreeArr[stickManVar.length];
    FillObjectCharArray(checkWatchOne, checkWatchOneArr, stickManVar);
    FillObjectCharArray(checkWatchTwo, checkWatchTwoArr, stickManVar);
    FillObjectCharArray(checkWatchThree, checkWatchThreeArr, stickManVar);

    /**stick man hunger string and array frames**/
    string hungerOne;
    string hungerTwo;
    FillHungerOne(hungerOne);
    FillHungerTwo(hungerTwo);

    CHAR_INFO hungerOneArr[stickManVar.length];
    CHAR_INFO hungerTwoArr[stickManVar.length];
    FillObjectCharArray(hungerOne, hungerOneArr, stickManVar);
    FillObjectCharArray(hungerTwo, hungerTwoArr, stickManVar);

    /**stick man plant tree string and array frames**/
    string plantTreeOne;
    string plantTreeTwo;
    string plantTreeThree;
    string plantTreeFour;
    string plantTreeFive;
    FillPlantTreeOne(plantTreeOne);
    FillPlantTreeTwo(plantTreeTwo);
    FillPlantTreeThree(plantTreeThree);
    FillPlantTreeFour(plantTreeFour);
    FillPlantTreeFive(plantTreeFive);

    CHAR_INFO plantTreeOneArr[stickManVar.length];
    CHAR_INFO plantTreeTwoArr[stickManVar.length];
    CHAR_INFO plantTreeThreeArr[stickManVar.length];
    CHAR_INFO plantTreeFourArr[stickManVar.length];
    CHAR_INFO plantTreeFiveArr[stickManVar.length];
    FillObjectCharArray(plantTreeOne, plantTreeOneArr, stickManVar);
    FillObjectCharArray(plantTreeTwo, plantTreeTwoArr, stickManVar);
    FillObjectCharArray(plantTreeThree, plantTreeThreeArr, stickManVar);
    FillObjectCharArray(plantTreeFour, plantTreeFourArr, stickManVar);
    FillObjectCharArray(plantTreeFive, plantTreeFiveArr, stickManVar);

    /**stick man grab fruit string and array frames**/
    string grabFruitOne;
    string grabFruitTwo;
    string grabFruitThree;
    string grabFruitFour;
    string grabFruitFive;
    FillGrabFruitOne(grabFruitOne);
    FillGrabFruitTwo(grabFruitTwo);
    FillGrabFruitThree(grabFruitThree);
    FillGrabFruitFour(grabFruitFour);
    FillGrabFruitFive(grabFruitFive);

    CHAR_INFO grabFruitOneArr[stickManVar.length];
    CHAR_INFO grabFruitTwoArr[stickManVar.length];
    CHAR_INFO grabFruitThreeArr[stickManVar.length];
    CHAR_INFO grabFruitFourArr[stickManVar.length];
    CHAR_INFO grabFruitFiveArr[stickManVar.length];
    FillObjectCharArray(grabFruitOne, grabFruitOneArr, stickManVar);
    FillObjectCharArray(grabFruitTwo, grabFruitTwoArr, stickManVar);
    FillObjectCharArray(grabFruitThree, grabFruitThreeArr, stickManVar);
    FillObjectCharArray(grabFruitFour, grabFruitFourArr, stickManVar);
    FillObjectCharArray(grabFruitFive, grabFruitFiveArr, stickManVar);

    /**stick man eat fruit string and array frames**/
    string eatFruitOne;
    string eatFruitTwo;
    string eatFruitThree;
    string eatFruitFour;
    string eatFruitFive;
    string eatFruitSix;
    FillEatFruitOne(eatFruitOne);
    FillEatFruitTwo(eatFruitTwo);
    FillEatFruitThree(eatFruitThree);
    FillEatFruitFour(eatFruitFour);
    FillEatFruitFive(eatFruitFive);
    FillEatFruitSix(eatFruitSix);

    CHAR_INFO eatFruitOneArr[stickManVar.length];
    CHAR_INFO eatFruitTwoArr[stickManVar.length];
    CHAR_INFO eatFruitThreeArr[stickManVar.length];
    CHAR_INFO eatFruitFourArr[stickManVar.length];
    CHAR_INFO eatFruitFiveArr[stickManVar.length];
    CHAR_INFO eatFruitSixArr[stickManVar.length];
    FillObjectCharArray(eatFruitOne, eatFruitOneArr, stickManVar);
    FillObjectCharArray(eatFruitTwo, eatFruitTwoArr, stickManVar);
    FillObjectCharArray(eatFruitThree, eatFruitThreeArr, stickManVar);
    FillObjectCharArray(eatFruitFour, eatFruitFourArr, stickManVar);
    FillObjectCharArray(eatFruitFive, eatFruitFiveArr, stickManVar);
    FillObjectCharArray(eatFruitSix, eatFruitSixArr, stickManVar);

    /**stick man watches fire works strings and array frames**/
    int watchFireWorksNumFrames = 7; //increment with new frame additions
    string watchFireWorks[watchFireWorksNumFrames];
    CHAR_INFO watchFireWorksArr[watchFireWorksNumFrames][16 * 10];

    FillWatchFireWorks1(watchFireWorks[0]);
    FillWatchFireWorks2(watchFireWorks[1]);
    FillWatchFireWorks3(watchFireWorks[2]);
    FillWatchFireWorks4(watchFireWorks[3]);
    FillWatchFireWorks5(watchFireWorks[4]);
    FillWatchFireWorks6(watchFireWorks[5]);
    FillWatchFireWorks7(watchFireWorks[6]);
    FillWatchFireWorksCharArrays(watchFireWorks, watchFireWorksArr, watchFireWorksNumFrames, stickManVar); //fill all CHAR-INFO structs (frames)

    /**stick man call dog**/
    string callDog1;
    string callDog2;
    string callDog3;
    string callDog4;
    string callDog5;
    string callDog6;
    string callDog7;
    string callDog8;
    string callDog9;
    string callDog10;
    string callDog11;
    string callDog12;
    string callDog13;
    string callDog14;
    CHAR_INFO callDog1Arr[stickManVar.length];
    CHAR_INFO callDog2Arr[stickManVar.length];
    CHAR_INFO callDog3Arr[stickManVar.length];
    CHAR_INFO callDog4Arr[stickManVar.length];
    CHAR_INFO callDog5Arr[stickManVar.length];
    CHAR_INFO callDog6Arr[stickManVar.length];
    CHAR_INFO callDog7Arr[stickManVar.length];
    CHAR_INFO callDog8Arr[stickManVar.length];
    CHAR_INFO callDog9Arr[stickManVar.length];
    CHAR_INFO callDog10Arr[stickManVar.length];
    CHAR_INFO callDog11Arr[stickManVar.length];
    CHAR_INFO callDog12Arr[stickManVar.length];
    CHAR_INFO callDog13Arr[stickManVar.length];
    CHAR_INFO callDog14Arr[stickManVar.length];

    FillCallDog1(callDog1);
    FillCallDog2(callDog2);
    FillCallDog3(callDog3);
    FillCallDog4(callDog4);
    FillCallDog5(callDog5);
    FillCallDog6(callDog6);
    FillCallDog7(callDog7);
    FillCallDog8(callDog8);
    FillCallDog9(callDog9);
    FillCallDog10(callDog10);
    FillCallDog11(callDog11);
    FillCallDog12(callDog12);
    FillCallDog13(callDog13);
    FillCallDog14(callDog14);
    FillObjectCharArray(callDog1, callDog1Arr, stickManVar);
    FillObjectCharArray(callDog2, callDog2Arr, stickManVar);
    FillObjectCharArray(callDog3, callDog3Arr, stickManVar);
    FillObjectCharArray(callDog4, callDog4Arr, stickManVar);
    FillObjectCharArray(callDog5, callDog5Arr, stickManVar);
    FillObjectCharArray(callDog6, callDog6Arr, stickManVar);
    FillObjectCharArray(callDog7, callDog7Arr, stickManVar);
    FillObjectCharArray(callDog8, callDog8Arr, stickManVar);
    FillObjectCharArray(callDog9, callDog9Arr, stickManVar);
    FillObjectCharArray(callDog10, callDog10Arr, stickManVar);
    FillObjectCharArray(callDog11, callDog11Arr, stickManVar);
    FillObjectCharArray(callDog12, callDog12Arr, stickManVar);
    FillObjectCharArray(callDog13, callDog13Arr, stickManVar);
    FillObjectCharArray(callDog14, callDog14Arr, stickManVar);

    /**dog and his movement string and array frames**/
    string dogStandLeft;
    string dogLeft1;
    string dogLeft2;
    string dogLeft3;
    string dogLeft4;
    string dogStandRight;
    string dogRight1;
    string dogRight2;
    string dogRight3;
    string dogRight4;
    CHAR_INFO dogStandLeftArr[dogVar.length];
    CHAR_INFO dogLeft1Arr[dogVar.length];
    CHAR_INFO dogLeft2Arr[dogVar.length];
    CHAR_INFO dogLeft3Arr[dogVar.length];
    CHAR_INFO dogLeft4Arr[dogVar.length];
    CHAR_INFO dogStandRightArr[dogVar.length];
    CHAR_INFO dogRight1Arr[dogVar.length];
    CHAR_INFO dogRight2Arr[dogVar.length];
    CHAR_INFO dogRight3Arr[dogVar.length];
    CHAR_INFO dogRight4Arr[dogVar.length];

    FillDogStandLeft(dogStandLeft);
    FillDogLeft1(dogLeft1);
    FillDogLeft2(dogLeft2);
    FillDogLeft3(dogLeft3);
    FillDogLeft4(dogLeft4);
    FillDogStandLeft(dogStandRight);
    FillDogRight1(dogRight1);
    FillDogRight2(dogRight2);
    FillDogRight3(dogRight3);
    FillDogRight4(dogRight4);

    FillObjectCharArray(dogStandLeft, dogStandLeftArr, dogVar);
    FillObjectCharArray(dogLeft1, dogLeft1Arr, dogVar);
    FillObjectCharArray(dogLeft2, dogLeft2Arr, dogVar);
    FillObjectCharArray(dogLeft3, dogLeft3Arr, dogVar);
    FillObjectCharArray(dogLeft4, dogLeft4Arr, dogVar);
    FillObjectCharArray(dogStandRight, dogStandRightArr, dogVar);
    FillObjectCharArray(dogRight1, dogRight1Arr, dogVar);
    FillObjectCharArray(dogRight2, dogRight2Arr, dogVar);
    FillObjectCharArray(dogRight3, dogRight3Arr, dogVar);
    FillObjectCharArray(dogRight4, dogRight4Arr, dogVar);

    /**dog wag tail**/
    string dogWagTailOne;
    FillDogWagTailOne(dogWagTailOne);

    CHAR_INFO dogWagTailOneArr[dogVar.length];
    FillObjectCharArray(dogWagTailOne, dogWagTailOneArr, dogVar);

    /**dog jumps string and array frames**/
    string dogJump1;
    string dogJump2;
    CHAR_INFO dogJump1Arr[dogVar.length];
    CHAR_INFO dogJump2Arr[dogVar.length];

    FillDogJump1(dogJump1);
    FillDogJump2(dogJump2);
    FillObjectCharArray(dogJump1, dogJump1Arr, dogVar);
    FillObjectCharArray(dogJump2, dogJump2Arr, dogVar);

    /**tree string and array frames**/
    string tree1;
    string tree2;
    string tree3;
    string tree4;
    string tree5;
    string tree6;
    string tree7;
    string tree8;
    string tree9;
    string tree10;
    string tree11;
    string tree12;
    string tree13;
    string tree14;
    string tree15;
    string tree16;
    string tree17;
    string tree18;
    string tree19;
    string tree20;
    string tree21;
    string tree22;
    string tree23;
    string tree24;
    string tree25;
    string tree26;
    string tree27;
    string tree28;
    string tree29;
    string tree30;
    string tree31;
    string tree32;
    string tree33;
    string tree34;
    string tree35;
    string tree36;
    string tree37;
    string tree38;
    string tree39;
    string tree40;
    FillTree1(tree1);
    FillTree2(tree2);
    FillTree3(tree3);
    FillTree4(tree4);
    FillTree5(tree5);
    FillTree6(tree6);
    FillTree7(tree7);
    FillTree8(tree8);
    FillTree9(tree9);
    FillTree10(tree10);
    FillTree11(tree11);
    FillTree12(tree12);
    FillTree13(tree13);
    FillTree14(tree14);
    FillTree15(tree15);
    FillTree16(tree16);
    FillTree17(tree17);
    FillTree18(tree18);
    FillTree19(tree19);
    FillTree20(tree20);
    FillTree21(tree21);
    FillTree22(tree22);
    FillTree23(tree23);
    FillTree24(tree24);
    FillTree25(tree25);
    FillTree26(tree26);
    FillTree27(tree27);
    FillTree28(tree28);
    FillTree29(tree29);
    FillTree30(tree30);
    FillTree31(tree31);
    FillTree32(tree32);
    FillTree33(tree33);
    FillTree34(tree34);
    FillTree35(tree35);
    FillTree36(tree36);
    FillTree37(tree37);
    FillTree38(tree38);
    FillTree39(tree39);
    FillTree40(tree40);

    CHAR_INFO tree1Arr[treeVar.length];
    CHAR_INFO tree2Arr[treeVar.length];
    CHAR_INFO tree3Arr[treeVar.length];
    CHAR_INFO tree4Arr[treeVar.length];
    CHAR_INFO tree5Arr[treeVar.length];
    CHAR_INFO tree6Arr[treeVar.length];
    CHAR_INFO tree7Arr[treeVar.length];
    CHAR_INFO tree8Arr[treeVar.length];
    CHAR_INFO tree9Arr[treeVar.length];
    CHAR_INFO tree10Arr[treeVar.length];
    CHAR_INFO tree11Arr[treeVar.length];
    CHAR_INFO tree12Arr[treeVar.length];
    CHAR_INFO tree13Arr[treeVar.length];
    CHAR_INFO tree14Arr[treeVar.length];
    CHAR_INFO tree15Arr[treeVar.length];
    CHAR_INFO tree16Arr[treeVar.length];
    CHAR_INFO tree17Arr[treeVar.length];
    CHAR_INFO tree18Arr[treeVar.length];
    CHAR_INFO tree19Arr[treeVar.length];
    CHAR_INFO tree20Arr[treeVar.length];
    CHAR_INFO tree21Arr[treeVar.length];
    CHAR_INFO tree22Arr[treeVar.length];
    CHAR_INFO tree23Arr[treeVar.length];
    CHAR_INFO tree24Arr[treeVar.length];
    CHAR_INFO tree25Arr[treeVar.length];
    CHAR_INFO tree26Arr[treeVar.length];
    CHAR_INFO tree27Arr[treeVar.length];
    CHAR_INFO tree28Arr[treeVar.length];
    CHAR_INFO tree29Arr[treeVar.length];
    CHAR_INFO tree30Arr[treeVar.length];
    CHAR_INFO tree31Arr[treeVar.length];
    CHAR_INFO tree32Arr[treeVar.length];
    CHAR_INFO tree33Arr[treeVar.length];
    CHAR_INFO tree34Arr[treeVar.length];
    CHAR_INFO tree35Arr[treeVar.length];
    CHAR_INFO tree36Arr[treeVar.length];
    CHAR_INFO tree37Arr[treeVar.length];
    CHAR_INFO tree38Arr[treeVar.length];
    CHAR_INFO tree39Arr[treeVar.length];
    CHAR_INFO tree40Arr[treeVar.length];
    FillTreeCharArray(tree1, tree1Arr, treeVar);
    FillTreeCharArray(tree2, tree2Arr, treeVar);
    FillTreeCharArray(tree3, tree3Arr, treeVar);
    FillTreeCharArray(tree4, tree4Arr, treeVar);
    FillTreeCharArray(tree5, tree5Arr, treeVar);
    FillTreeCharArray(tree6, tree6Arr, treeVar);
    FillTreeCharArray(tree7, tree7Arr, treeVar);
    FillTreeCharArray(tree8, tree8Arr, treeVar);
    FillTreeCharArray(tree9, tree9Arr, treeVar);
    FillTreeCharArray(tree10, tree10Arr, treeVar);
    FillTreeCharArray(tree11, tree11Arr, treeVar);
    FillTreeCharArray(tree12, tree12Arr, treeVar);
    FillTreeCharArray(tree13, tree13Arr, treeVar);
    FillTreeCharArray(tree14, tree14Arr, treeVar);
    FillTreeCharArray(tree15, tree15Arr, treeVar);
    FillTreeCharArray(tree16, tree16Arr, treeVar);
    FillTreeCharArray(tree17, tree17Arr, treeVar);
    FillTreeCharArray(tree18, tree18Arr, treeVar);
    FillTreeCharArray(tree19, tree19Arr, treeVar);
    FillTreeCharArray(tree20, tree20Arr, treeVar);
    FillTreeCharArray(tree21, tree21Arr, treeVar);
    FillTreeCharArray(tree22, tree22Arr, treeVar);
    FillTreeCharArray(tree23, tree23Arr, treeVar);
    FillTreeCharArray(tree24, tree24Arr, treeVar);
    FillTreeCharArray(tree25, tree25Arr, treeVar);
    FillTreeCharArray(tree26, tree26Arr, treeVar);
    FillTreeCharArray(tree27, tree27Arr, treeVar);
    FillTreeCharArray(tree28, tree28Arr, treeVar);
    FillTreeCharArray(tree29, tree29Arr, treeVar);
    FillTreeCharArray(tree30, tree30Arr, treeVar);
    FillTreeCharArray(tree31, tree31Arr, treeVar);
    FillTreeCharArray(tree32, tree32Arr, treeVar);
    FillTreeCharArray(tree33, tree33Arr, treeVar);
    FillTreeCharArray(tree34, tree34Arr, treeVar);
    FillTreeCharArray(tree35, tree35Arr, treeVar);
    FillTreeCharArray(tree36, tree36Arr, treeVar);
    FillTreeCharArray(tree37, tree37Arr, treeVar);
    FillTreeCharArray(tree38, tree38Arr, treeVar);
    FillTreeCharArray(tree39, tree39Arr, treeVar);
    FillTreeCharArray(tree40, tree40Arr, treeVar);

    /**fireworks string and array frames**/
    int fireWorksNumFrames = 9;
    string fireWorks[fireWorksNumFrames];
    CHAR_INFO fireWorksArr[fireWorksNumFrames][17 * 8];

    FillFireWorks1(fireWorks[0]);
    FillFireWorks2(fireWorks[1]);
    FillFireWorks3(fireWorks[2]);
    FillFireWorks4(fireWorks[3]);
    FillFireWorks5(fireWorks[4]);
    FillFireWorks6(fireWorks[5]);
    FillFireWorks7(fireWorks[6]);
    FillFireWorks8(fireWorks[7]);
    FillFireWorks9(fireWorks[8]);
    FillFireWorksCharArrays(fireWorks, fireWorksArr, 9); //fill all CHAR-INFO structs (frames)

    /**stick man pushes cloud**/
    int pushCloudOneNumFrames = 4;
    string pushCloudOne[pushCloudOneNumFrames];
    CHAR_INFO pushCloudOneArr[pushCloudOneNumFrames][11 * 10]; //must equal fillCharArray declaration

    FillPushCloud1(pushCloudOne[0]);
    FillPushCloud2(pushCloudOne[1]);
    FillPushCloud3(pushCloudOne[2]);
    FillPushCloud4(pushCloudOne[3]);
    FillStickManCharArrays(pushCloudOne, pushCloudOneArr, pushCloudOneNumFrames, stickManVar); //fill all CHAR-INFO structs (frames)

    /**cloudOne string and array frames**/
    int cloudOneNumFrames = 8;
    string cloudOne[cloudOneNumFrames];
    CHAR_INFO cloudOneArr[cloudOneNumFrames][7 * 4];

    FillCloud1(cloudOne[0]);
    FillCloud2(cloudOne[1]);
    FillCloud3(cloudOne[2]);
    FillCloud4(cloudOne[3]);
    FillCloud5(cloudOne[4]);
    FillCloud6(cloudOne[5]);
    FillCloud7(cloudOne[6]);
    FillCloud8(cloudOne[7]);
    FillCloudOneCharArrays(cloudOne, cloudOneArr, cloudOneNumFrames, cloudOneVar); //fill all CHAR-INFO structs (frames)

    /**cloudTwo string and array frames**/
    int cloudTwoNumFrames = 13;
    string cloudTwo[cloudTwoNumFrames];
    CHAR_INFO cloudTwoArr[cloudTwoNumFrames][24 * 8];

    FillCloud9(cloudTwo[0]);
    FillCloud10(cloudTwo[1]);
    FillCloud11(cloudTwo[2]);
    FillCloud12(cloudTwo[3]);
    FillCloud13(cloudTwo[4]);
    FillCloud14(cloudTwo[5]);
    FillCloud15(cloudTwo[6]);
    FillCloud16(cloudTwo[7]);
    FillCloud17(cloudTwo[8]);
    FillCloud18(cloudTwo[9]);
    FillCloud19(cloudTwo[10]);
    FillCloud20(cloudTwo[11]);
    FillCloud21(cloudTwo[12]);
    FillCloudTwoCharArrays(cloudTwo, cloudTwoArr, cloudTwoNumFrames, cloudTwoVar); //fill all CHAR-INFO structs (frames)

    /*******************/
    /*****Main Loop*****/
    /*******************/


    /**user choose animation**/
    int userInput;
    COORD userInputFillCoord = {0, 0};
    COORD userInputSize = {30, 1};
    cout << "Choose animation: ";
    cin >> userInput;

    int randomVar = 0;
    int sleepTime = 100;
    int waitTime = 500;

    int eventCount = 0; //count number of iterations for case 0
    int eventLimit = 20; //case 0 iterations number limit

    COORD clearSize = {dogVar.area.X, 1};
    COORD clearCloudSizeA = {2, cloudOneVar.area.Y};
    COORD clearCloudSizeB = {cloudOneVar.area.X, 1};
    COORD clearCloudSizeC = {cloudTwoVar.area.X, 1};

    int lightSaberCount = 0;
    int lightSaberLimit = 1;
    int dogCount = 0;
    int dogLimit = 1;
    int treeCount = 0;
    int treeLimit = 1;
    int cloudCount = 0;
    int cloudLimit = 1;

    do
    {
        switch (userInput)
        {

        /**stickMan animation**/
        case 0:
            ClearArea(hStdOut, clearSpaceArr, clearSpaceSize, userInputFillCoord, userInputSize);

            cout << "Number of iterations: ";
            cin >> eventLimit;
            ClearArea(hStdOut, clearSpaceArr, clearSpaceSize, userInputFillCoord, (COORD)
            {
                userInputSize.X, 2
            });

            AddObject(hStdOut, standLeftArr, stickManVar.area, stickManVar.fillCoord);
            Sleep(1000);
            do
            {
                randomVar = rand() % 28;

                if (randomVar <= 6 || stickManVar.fillCoord.X < numX * .2 || stickManVar.fillCoord.X > numX * .65)
                {
                    /**random movement**/
                    MoveStickManInRandomDirection(hStdOut, stickManVar, standLeftArr, leftOneArr, leftTwoArr, leftThreeArr, leftFourArr,
                                                  standRightArr, rightOneArr, rightTwoArr, rightThreeArr, rightFourArr, 100, clearSpaceArr, clearSpaceSize);
                }




                else if (randomVar <= 9)
                {
                    /**random jump**/
                    JumpStickMan(hStdOut, stickManVar, jumpOneArr, jumpTwoArr, standRightArr, clearSpaceArr, clearSpaceSize);
                }




                else if (randomVar <= 12)
                {
                    /**scratch head**/
                    ScratchHeadStickMan(hStdOut, stickManVar, scratchHeadOneArr, scratchHeadTwoArr, scratchHeadThreeArr, scratchHeadFourArr, scratchHeadFiveArr, standLeftArr);
                }





                else if (randomVar <= 15)
                {
                    /**check watch**/
                    CheckWatchStickMan(hStdOut, stickManVar, checkWatchOneArr, checkWatchTwoArr, checkWatchThreeArr);
                }





                else if (randomVar <= 18 && lightSaberCount < lightSaberLimit)
                {
                    lightSaberCount++; //limit number of times this even occurs

                    /**use lightsaber**/
                    lightSaberColor = RandomTextColor();
                    bool changeColor = false;

                    do
                    {
                        if (lightSaberColor == stickManVar.color)
                        {
                            lightSaberColor = RandomTextColor();
                            changeColor = true;
                        }
                        else
                            changeColor = false;
                    }
                    while(changeColor);

                    FillLightSaberCharArray(lightSaber1, lightSaber1Arr, stickManLightSaberVar, stickManVar, lightSaberColor);
                    FillLightSaberCharArray(lightSaber2, lightSaber2Arr, stickManLightSaberVar, stickManVar, lightSaberColor);
                    FillLightSaberCharArray(lightSaber3, lightSaber3Arr, stickManLightSaberVar, stickManVar, lightSaberColor);
                    FillLightSaberCharArray(lightSaber4, lightSaber4Arr, stickManLightSaberVar, stickManVar, lightSaberColor);
                    FillLightSaberCharArray(lightSaber5, lightSaber5Arr, stickManLightSaberVar, stickManVar, lightSaberColor);
                    FillLightSaberCharArray(lightSaber6, lightSaber6Arr, stickManLightSaberVar, stickManVar, lightSaberColor);
                    FillLightSaberCharArray(lightSaber7, lightSaber7Arr, stickManLightSaberVar, stickManVar, lightSaberColor);
                    FillLightSaberCharArray(lightSaber8, lightSaber8Arr, stickManLightSaberVar, stickManVar, lightSaberColor);
                    FillLightSaberCharArray(lightSaber9, lightSaber9Arr, stickManLightSaberVar, stickManVar, lightSaberColor);
                    FillLightSaberCharArray(lightSaber10, lightSaber10Arr, stickManLightSaberVar, stickManVar, lightSaberColor);
                    FillLightSaberCharArray(lightSaber11, lightSaber11Arr, stickManLightSaberVar, stickManVar, lightSaberColor);
                    FillLightSaberCharArray(lightSaber12, lightSaber12Arr, stickManLightSaberVar, stickManVar, lightSaberColor);
                    FillLightSaberCharArray(lightSaber13, lightSaber13Arr, stickManLightSaberVar, stickManVar, lightSaberColor);
                    FillLightSaberCharArray(lightSaber14, lightSaber14Arr, stickManLightSaberVar, stickManVar, lightSaberColor);
                    FillLightSaberCharArray(lightSaber15, lightSaber15Arr, stickManLightSaberVar, stickManVar, lightSaberColor);
                    FillLightSaberCharArray(lightSaber16, lightSaber16Arr, stickManLightSaberVar, stickManVar, lightSaberColor);
                    FillLightSaberCharArray(lightSaber17, lightSaber17Arr, stickManLightSaberVar, stickManVar, lightSaberColor);
                    FillLightSaberCharArray(lightSaber18, lightSaber18Arr, stickManLightSaberVar, stickManVar, lightSaberColor);
                    FillLightSaberCharArray(lightSaber19, lightSaber19Arr, stickManLightSaberVar, stickManVar, lightSaberColor);
                    FillLightSaberCharArray(lightSaber20, lightSaber20Arr, stickManLightSaberVar, stickManVar, lightSaberColor);
                    FillLightSaberCharArray(lightSaber21, lightSaber21Arr, stickManLightSaberVar, stickManVar, lightSaberColor);
                    FillLightSaberCharArray(lightSaber22, lightSaber22Arr, stickManLightSaberVar, stickManVar, lightSaberColor);
                    FillLightSaberCharArray(lightSaber23, lightSaber23Arr, stickManLightSaberVar, stickManVar, lightSaberColor);
                    FillLightSaberCharArray(lightSaber24, lightSaber24Arr, stickManLightSaberVar, stickManVar, lightSaberColor);

                    LightSaberStickMan(hStdOut, stickManLightSaberVar, stickManVar, lightSaber1Arr, lightSaber2Arr, lightSaber3Arr, lightSaber4Arr, lightSaber5Arr, lightSaber6Arr,
                                       lightSaber7Arr, lightSaber8Arr, lightSaber9Arr, lightSaber10Arr, lightSaber11Arr, lightSaber12Arr, lightSaber13Arr, lightSaber14Arr, lightSaber15Arr,
                                       lightSaber16Arr, lightSaber17Arr, lightSaber18Arr, lightSaber19Arr, lightSaber20Arr, lightSaber21Arr, lightSaber22Arr, lightSaber23Arr, lightSaber24Arr,
                                       swordHandleVar, swordHandleArr, standRightArr, clearSpaceArr, clearSpaceSize);
                }





                else if (randomVar <= 20 && treeCount < treeLimit) /**grow tree and eat fruit**/
                {
                    treeCount++; //limit number of times this even occurs

                    /**stick man moves to tree location**/
                    treeVar.fillCoord.X = (rand() % static_cast<int>(numX * .4)) + (numX * .3); //randomize tree location
                    MoveToTreeLocationStickMan(hStdOut, stickManVar, treeVar, standLeftArr, leftOneArr, leftTwoArr, leftThreeArr, leftFourArr,
                                               rightOneArr, rightTwoArr, rightThreeArr, rightFourArr, clearSpaceArr, clearSpaceSize);

                    /**stick man is hungry**/
                    HungerStickMan(hStdOut, stickManVar, hungerOneArr, hungerTwoArr, standLeftArr);

                    /**stick man plants tree**/
                    PlantTreeStickMan(hStdOut, stickManVar, treeVar, plantTreeOneArr, plantTreeTwoArr, plantTreeThreeArr, plantTreeFourArr, plantTreeFiveArr, standLeftArr);

                    /**stick man moves to right side of tree**/
                    MoveStickManRight(hStdOut, stickManVar, standLeftArr, rightOneArr, rightTwoArr, rightThreeArr, rightFourArr,
                                      1, treeVar.fillCoord.X + treeVar.area.X - stickManVar.fillCoord.X, 100, clearSpaceArr, clearSpaceSize);

                    /**tree grows**/
                    TreeGrow(hStdOut, treeVar, tree1Arr, tree2Arr, tree3Arr, tree4Arr, tree5Arr, tree6Arr, tree7Arr, tree8Arr, tree9Arr,
                             tree10Arr, tree11Arr, tree12Arr, tree13Arr, tree14Arr, tree15Arr, tree16Arr, tree17Arr, tree18Arr, tree19Arr,
                             tree20Arr, tree21Arr, tree22Arr, tree23Arr, tree24Arr, tree25Arr, tree26Arr, tree27Arr, tree28Arr, tree29Arr,
                             tree30Arr, tree31Arr, tree32Arr, tree33Arr, tree34Arr, tree35Arr, tree36Arr, tree37Arr, tree38Arr, tree39Arr, tree40Arr);

                    /**stick man grabs fruit**/
                    GrabFruitStickMan(hStdOut, stickManVar, grabFruitOneArr, grabFruitTwoArr, grabFruitThreeArr, grabFruitFourArr, grabFruitFiveArr, clearSpaceArr, clearSpaceSize);

                    /**stick man eats fruit**/
                    EatFruitStickMan(hStdOut, stickManVar, eatFruitOneArr, eatFruitTwoArr, eatFruitThreeArr, eatFruitFourArr, eatFruitFiveArr, eatFruitSixArr, standLeftArr);

                    /**clear tree**/
                    ClearArea(hStdOut, clearSpaceArr, clearSpaceSize, treeVar.fillCoord, treeVar.area);
                }






                else if (randomVar <= 22 && dogCount < dogLimit) /**call dog**/
                {
                    dogCount++;

                    /**stick man calls dog**/
                    CallDogStickMan(hStdOut, stickManVar, callDog1Arr, callDog2Arr, callDog3Arr, callDog4Arr,
                                    callDog5Arr, callDog6Arr, callDog7Arr, standRightArr);

                    /**dog walks onto screen**/
                    dogVar.fillCoord.X = numX - 1 + 5;
                    MoveDogLeft(hStdOut, dogVar, dogStandLeftArr, dogLeft1Arr, dogLeft2Arr, dogLeft3Arr, dogLeft4Arr,
                                2, dogVar.fillCoord.X - stickManVar.fillCoord.X - 25, 100, clearSpaceArr, clearSpaceSize);
                    Sleep(500);

                    /**dog wags tail**/
                    DogWagsTail(hStdOut, dogVar, dogStandLeftArr, dogWagTailOneArr, 5);
                    Sleep(200);

                    /**dog moves to stick man**/
                    MoveDogLeft(hStdOut, dogVar, dogStandLeftArr, dogLeft1Arr, dogLeft2Arr, dogLeft3Arr, dogLeft4Arr,
                                1, dogVar.fillCoord.X - stickManVar.fillCoord.X - 10, 100, clearSpaceArr, clearSpaceSize);

                    /** stick man pets dog**/
                    PetDogStickMan(hStdOut, stickManVar, callDog8Arr, callDog9Arr, callDog10Arr, callDog11Arr);
                    Sleep(200);

                    /**dog jumps for stick man**/
                    AddObject(hStdOut, callDog9Arr, stickManVar.area, stickManVar.fillCoord);
                    Sleep(sleepTime);
                    AddObject(hStdOut, callDog12Arr, stickManVar.area, stickManVar.fillCoord);
                    Sleep(sleepTime);
                    AddObject(hStdOut, callDog13Arr, stickManVar.area, stickManVar.fillCoord);
                    Sleep(sleepTime);
                    AddObject(hStdOut, callDog14Arr, stickManVar.area, stickManVar.fillCoord);
                    Sleep(sleepTime);

                    /**jump**/
                    DogJump(hStdOut, dogVar, stickManVar, dogJump1Arr, dogJump2Arr, dogStandLeftArr,
                            callDog14Arr, clearSpaceArr, clearSpaceSize);

                    AddObject(hStdOut, callDog13Arr, stickManVar.area, stickManVar.fillCoord);
                    Sleep(sleepTime);
                    AddObject(hStdOut, callDog12Arr, stickManVar.area, stickManVar.fillCoord);
                    Sleep(sleepTime);
                    AddObject(hStdOut, callDog10Arr, stickManVar.area, stickManVar.fillCoord);
                    Sleep(500);

                    /**pet dog**/
                    for (int i = 0; i < 2; ++i)
                    {
                        AddObject(hStdOut, callDog11Arr, stickManVar.area, stickManVar.fillCoord);
                        Sleep(sleepTime);
                        AddObject(hStdOut, callDog10Arr, stickManVar.area, stickManVar.fillCoord);
                        Sleep(sleepTime);
                    }

                    Sleep(sleepTime * 2);
                    AddObject(hStdOut, callDog9Arr, stickManVar.area, stickManVar.fillCoord);
                    Sleep(sleepTime);
                    AddObject(hStdOut, callDog8Arr, stickManVar.area, stickManVar.fillCoord);
                    Sleep(sleepTime);
                    AddObject(hStdOut, standRightArr, stickManVar.area, stickManVar.fillCoord);
                    Sleep(500);

                    /**wag tail**/
                    DogWagsTail(hStdOut, dogVar, dogStandLeftArr, dogWagTailOneArr, 5);
                    Sleep(500);

                    /**dog runs off screen**/
                    MoveDogRight(hStdOut, dogVar, dogStandRightArr, dogRight1Arr, dogRight2Arr, dogRight3Arr, dogRight4Arr,
                                 3, numX - 1 - dogVar.fillCoord.X, 100, clearSpaceArr, clearSpaceSize);
                }




                else if (randomVar <= 25 && cloudCount < cloudLimit) /**cloud appears**/
                {
                    cloudCount++;

                    /**move stick man if too far to the right**/
                    if (stickManVar.fillCoord.X > 50)
                    {
                        MoveStickManLeft(hStdOut, stickManVar, standRightArr, leftOneArr, leftTwoArr, leftThreeArr, leftFourArr,
                                         1, stickManVar.fillCoord.X - 50, 100, clearSpaceArr, clearSpaceSize);
                    }
                    cloudOneVar.fillCoord.X = stickManVar.fillCoord.X + 11;
                    cloudOneVar.fillCoord.Y = stickManVar.fillCoord.Y + 1;

                    Sleep(1000);
                    /**cloud appears**/
                    AddObject(hStdOut, cloudOneArr[0], cloudOneVar.area, cloudOneVar.fillCoord);
                    Sleep(sleepTime * 2);
                    AddObject(hStdOut, cloudOneArr[1], cloudOneVar.area, cloudOneVar.fillCoord);
                    Sleep(sleepTime * 2);
                    AddObject(hStdOut, cloudOneArr[2], cloudOneVar.area, cloudOneVar.fillCoord);
                    Sleep(sleepTime * 2);
                    AddObject(hStdOut, cloudOneArr[3], cloudOneVar.area, cloudOneVar.fillCoord);
                    Sleep(sleepTime * 2);
                    AddObject(hStdOut, cloudOneArr[4], cloudOneVar.area, cloudOneVar.fillCoord);
                    Sleep(sleepTime * 2);
                    AddObject(hStdOut, cloudOneArr[5], cloudOneVar.area, cloudOneVar.fillCoord);
                    Sleep(sleepTime * 2);
                    AddObject(hStdOut, cloudOneArr[6], cloudOneVar.area, cloudOneVar.fillCoord);
                    Sleep(sleepTime * 2);
                    AddObject(hStdOut, cloudOneArr[7], cloudOneVar.area, cloudOneVar.fillCoord);
                    Sleep(1000);

                    /**stick man pushes cloud**/
                    AddObject(hStdOut, pushCloudOneArr[0], stickManVar.area, stickManVar.fillCoord);
                    Sleep(sleepTime * 1.5);
                    AddObject(hStdOut, pushCloudOneArr[1], stickManVar.area, stickManVar.fillCoord);
                    Sleep(sleepTime * 1.5);
                    AddObject(hStdOut, pushCloudOneArr[2], stickManVar.area, stickManVar.fillCoord);
                    Sleep(sleepTime * 1.5);
                    AddObject(hStdOut, pushCloudOneArr[3], stickManVar.area, stickManVar.fillCoord);
                    Sleep(sleepTime * 3);

                    /**cloud moves away from stick man**/
                    ClearArea(hStdOut, clearSpaceArr, clearSpaceSize, cloudOneVar.fillCoord, clearCloudSizeA);
                    ClearArea(hStdOut, clearSpaceArr, clearSpaceSize, (COORD)
                    {
                        cloudOneVar.fillCoord.X, cloudOneVar.fillCoord.Y + 3
                    }, clearCloudSizeB);
                    cloudOneVar.fillCoord.X = cloudOneVar.fillCoord.X + 2;
                    cloudOneVar.fillCoord.Y--;
                    AddObject(hStdOut, cloudOneArr[7], cloudOneVar.area, cloudOneVar.fillCoord);
                    Sleep(sleepTime * 1.5);
                    ClearArea(hStdOut, clearSpaceArr, clearSpaceSize, cloudOneVar.fillCoord, clearCloudSizeA);
                    ClearArea(hStdOut, clearSpaceArr, clearSpaceSize, (COORD)
                    {
                        cloudOneVar.fillCoord.X, cloudOneVar.fillCoord.Y + 3
                    }, clearCloudSizeB);
                    cloudOneVar.fillCoord.X = cloudOneVar.fillCoord.X + 2;
                    cloudOneVar.fillCoord.Y--;
                    AddObject(hStdOut, cloudOneArr[7], cloudOneVar.area, cloudOneVar.fillCoord);
                    Sleep(sleepTime * 1.5);
                    ClearArea(hStdOut, clearSpaceArr, clearSpaceSize, cloudOneVar.fillCoord, clearCloudSizeA);
                    ClearArea(hStdOut, clearSpaceArr, clearSpaceSize, (COORD)
                    {
                        cloudOneVar.fillCoord.X, cloudOneVar.fillCoord.Y + 3
                    }, clearCloudSizeB);
                    cloudOneVar.fillCoord.X = cloudOneVar.fillCoord.X + 2;
                    cloudOneVar.fillCoord.Y--;
                    AddObject(hStdOut, cloudOneArr[7], cloudOneVar.area, cloudOneVar.fillCoord);
                    AddObject(hStdOut, pushCloudOneArr[2], stickManVar.area, stickManVar.fillCoord);
                    Sleep(sleepTime * 1.5);
                    ClearArea(hStdOut, clearSpaceArr, clearSpaceSize, cloudOneVar.fillCoord, clearCloudSizeA);
                    ClearArea(hStdOut, clearSpaceArr, clearSpaceSize, (COORD)
                    {
                        cloudOneVar.fillCoord.X, cloudOneVar.fillCoord.Y + 3
                    }, clearCloudSizeB);
                    cloudOneVar.fillCoord.X = cloudOneVar.fillCoord.X + 2;
                    cloudOneVar.fillCoord.Y--;
                    AddObject(hStdOut, cloudOneArr[7], cloudOneVar.area, cloudOneVar.fillCoord);
                    AddObject(hStdOut, pushCloudOneArr[1], stickManVar.area, stickManVar.fillCoord);
                    Sleep(sleepTime * 1.5);
                    ClearArea(hStdOut, clearSpaceArr, clearSpaceSize, cloudOneVar.fillCoord, clearCloudSizeA);
                    ClearArea(hStdOut, clearSpaceArr, clearSpaceSize, (COORD)
                    {
                        cloudOneVar.fillCoord.X, cloudOneVar.fillCoord.Y + 3
                    }, clearCloudSizeB);
                    cloudOneVar.fillCoord.X = cloudOneVar.fillCoord.X + 2;
                    cloudOneVar.fillCoord.Y--;
                    AddObject(hStdOut, cloudOneArr[7], cloudOneVar.area, cloudOneVar.fillCoord);
                    AddObject(hStdOut, pushCloudOneArr[0], stickManVar.area, stickManVar.fillCoord);
                    Sleep(sleepTime * 1.5);
                    ClearArea(hStdOut, clearSpaceArr, clearSpaceSize, cloudOneVar.fillCoord, clearCloudSizeA);
                    ClearArea(hStdOut, clearSpaceArr, clearSpaceSize, (COORD)
                    {
                        cloudOneVar.fillCoord.X, cloudOneVar.fillCoord.Y + 3
                    }, clearCloudSizeB);
                    cloudOneVar.fillCoord.X = cloudOneVar.fillCoord.X + 2;
                    cloudOneVar.fillCoord.Y--;
                    AddObject(hStdOut, cloudOneArr[7], cloudOneVar.area, cloudOneVar.fillCoord);
                    AddObject(hStdOut, standRightArr, stickManVar.area, stickManVar.fillCoord);
                    Sleep(sleepTime * 1.5);

                    cloudTwoVar.fillCoord.X = cloudOneVar.fillCoord.X - 8;
                    cloudTwoVar.fillCoord.Y = cloudOneVar.fillCoord.Y - 3;

                    /**cloud continues moving away from stick man**/
                    AddObject(hStdOut, cloudTwoArr[0], cloudTwoVar.area, cloudTwoVar.fillCoord);
                    Sleep(sleepTime * 1.5);

                    ClearArea(hStdOut, clearSpaceArr, clearSpaceSize, cloudTwoVar.fillCoord, cloudTwoVar.area);
                    cloudTwoVar.fillCoord.X = cloudTwoVar.fillCoord.X + 2;
                    cloudTwoVar.fillCoord.Y--;
                    AddObject(hStdOut, cloudTwoArr[1], cloudTwoVar.area, cloudTwoVar.fillCoord);
                    Sleep(sleepTime * 1.5);
                    ClearArea(hStdOut, clearSpaceArr, clearSpaceSize, cloudTwoVar.fillCoord, cloudTwoVar.area);
                    cloudTwoVar.fillCoord.X = cloudTwoVar.fillCoord.X + 2;
                    cloudTwoVar.fillCoord.Y--;
                    AddObject(hStdOut, cloudTwoArr[2], cloudTwoVar.area, cloudTwoVar.fillCoord);
                    Sleep(sleepTime * 1.5);
                    ClearArea(hStdOut, clearSpaceArr, clearSpaceSize, cloudTwoVar.fillCoord, cloudTwoVar.area);
                    cloudTwoVar.fillCoord.X = cloudTwoVar.fillCoord.X + 2;
                    cloudTwoVar.fillCoord.Y--;
                    AddObject(hStdOut, cloudTwoArr[3], cloudTwoVar.area, cloudTwoVar.fillCoord);
                    Sleep(sleepTime * 1.5);
                    ClearArea(hStdOut, clearSpaceArr, clearSpaceSize, cloudTwoVar.fillCoord, cloudTwoVar.area);
                    cloudTwoVar.fillCoord.X = cloudTwoVar.fillCoord.X + 2;
                    cloudTwoVar.fillCoord.Y--;
                    AddObject(hStdOut, cloudTwoArr[4], cloudTwoVar.area, cloudTwoVar.fillCoord);
                    Sleep(sleepTime * 1.5);
                    ClearArea(hStdOut, clearSpaceArr, clearSpaceSize, cloudTwoVar.fillCoord, cloudTwoVar.area);
                    cloudTwoVar.fillCoord.X = cloudTwoVar.fillCoord.X + 2;
                    cloudTwoVar.fillCoord.Y--;
                    AddObject(hStdOut, cloudTwoArr[5], cloudTwoVar.area, cloudTwoVar.fillCoord);
                    Sleep(sleepTime * 1.5);

                    ClearArea(hStdOut, clearSpaceArr, clearSpaceSize, cloudTwoVar.fillCoord, cloudTwoVar.area);
                    cloudTwoVar.fillCoord.X = cloudTwoVar.fillCoord.X + 2;
                    cloudTwoVar.fillCoord.Y--;
                    AddObject(hStdOut, cloudTwoArr[5], cloudTwoVar.area, cloudTwoVar.fillCoord);
                    Sleep(sleepTime * 1.5);
                    ClearArea(hStdOut, clearSpaceArr, clearSpaceSize, cloudTwoVar.fillCoord, cloudTwoVar.area);
                    cloudTwoVar.fillCoord.X = cloudTwoVar.fillCoord.X + 2;
                    cloudTwoVar.fillCoord.Y--;
                    AddObject(hStdOut, cloudTwoArr[5], cloudTwoVar.area, cloudTwoVar.fillCoord);
                    Sleep(sleepTime * 1.5);
                    ClearArea(hStdOut, clearSpaceArr, clearSpaceSize, cloudTwoVar.fillCoord, cloudTwoVar.area);
                    cloudTwoVar.fillCoord.X = cloudTwoVar.fillCoord.X + 2;
                    cloudTwoVar.fillCoord.Y--;
                    AddObject(hStdOut, cloudTwoArr[5], cloudTwoVar.area, cloudTwoVar.fillCoord);
                    Sleep(sleepTime * 1.5);
                    ClearArea(hStdOut, clearSpaceArr, clearSpaceSize, cloudTwoVar.fillCoord, cloudTwoVar.area);
                    cloudTwoVar.fillCoord.X = cloudTwoVar.fillCoord.X + 2;
                    cloudTwoVar.fillCoord.Y--;
                    AddObject(hStdOut, cloudTwoArr[5], cloudTwoVar.area, cloudTwoVar.fillCoord);
                    Sleep(sleepTime * 1.5);

                    Sleep(waitTime);
                    /**sun emerges**/
                    AddObject(hStdOut, cloudTwoArr[6], cloudTwoVar.area, cloudTwoVar.fillCoord);
                    Sleep(sleepTime * 3);
                    AddObject(hStdOut, cloudTwoArr[7], cloudTwoVar.area, cloudTwoVar.fillCoord);
                    Sleep(sleepTime * 3);
                    AddObject(hStdOut, cloudTwoArr[8], cloudTwoVar.area, cloudTwoVar.fillCoord);
                    Sleep(sleepTime * 3);
                    AddObject(hStdOut, cloudTwoArr[9], cloudTwoVar.area, cloudTwoVar.fillCoord);
                    Sleep(sleepTime * 3);
                    AddObject(hStdOut, cloudTwoArr[10], cloudTwoVar.area, cloudTwoVar.fillCoord);
                    Sleep(sleepTime * 3);
                    AddObject(hStdOut, cloudTwoArr[11], cloudTwoVar.area, cloudTwoVar.fillCoord);
                    Sleep(sleepTime * 3);
                    AddObject(hStdOut, cloudTwoArr[12], cloudTwoVar.area, cloudTwoVar.fillCoord);
                    Sleep(sleepTime * 3);

                    Sleep(2000);

                    ClearArea(hStdOut, clearSpaceArr, clearSpaceSize, cloudTwoVar.fillCoord, cloudTwoVar.area);
                }





                else
                {
                    /**flip switch and change color**/
                    FlipLightSwitchStickMan(hStdOut, stickManVar, lightSwitchOneArr, lightSwitchTwoArr, lightSwitchThreeArr, lightSwitchFourArr, standLeftArr);

                    RandomStickManColor(stickManVar, standLeftArr, leftOneArr, leftTwoArr, leftThreeArr, leftFourArr,
                                        standRightArr, rightOneArr, rightTwoArr, rightThreeArr, rightFourArr,
                                        standLeft, leftOne, leftTwo, leftThree, leftFour,
                                        standRight, rightOne, rightTwo, rightThree, rightFour);
                    FillObjectCharArray(jumpOne, jumpOneArr, stickManVar);
                    FillObjectCharArray(jumpTwo, jumpTwoArr, stickManVar);
                    FillObjectCharArray(scratchHeadOne, scratchHeadOneArr, stickManVar);
                    FillObjectCharArray(scratchHeadTwo, scratchHeadTwoArr, stickManVar);
                    FillObjectCharArray(scratchHeadThree, scratchHeadThreeArr, stickManVar);
                    FillObjectCharArray(scratchHeadFour, scratchHeadFourArr, stickManVar);
                    FillObjectCharArray(scratchHeadFive, scratchHeadFiveArr, stickManVar);
                    FillObjectCharArray(lightSwitchOne, lightSwitchOneArr, stickManVar);
                    FillObjectCharArray(lightSwitchTwo, lightSwitchTwoArr, stickManVar);
                    FillObjectCharArray(lightSwitchThree, lightSwitchThreeArr, stickManVar);
                    FillObjectCharArray(lightSwitchFour, lightSwitchFourArr, stickManVar);
                    FillObjectCharArray(checkWatchOne, checkWatchOneArr, stickManVar);
                    FillObjectCharArray(checkWatchTwo, checkWatchTwoArr, stickManVar);
                    FillObjectCharArray(checkWatchThree, checkWatchThreeArr, stickManVar);
                    FillObjectCharArray(hungerOne, hungerOneArr, stickManVar);
                    FillObjectCharArray(hungerTwo, hungerTwoArr, stickManVar);
                    FillObjectCharArray(plantTreeOne, plantTreeOneArr, stickManVar);
                    FillObjectCharArray(plantTreeTwo, plantTreeTwoArr, stickManVar);
                    FillObjectCharArray(plantTreeThree, plantTreeThreeArr, stickManVar);
                    FillObjectCharArray(plantTreeFour, plantTreeFourArr, stickManVar);
                    FillObjectCharArray(plantTreeFive, plantTreeFiveArr, stickManVar);
                    FillObjectCharArray(grabFruitOne, grabFruitOneArr, stickManVar);
                    FillObjectCharArray(grabFruitTwo, grabFruitTwoArr, stickManVar);
                    FillObjectCharArray(grabFruitThree, grabFruitThreeArr, stickManVar);
                    FillObjectCharArray(grabFruitFour, grabFruitFourArr, stickManVar);
                    FillObjectCharArray(grabFruitFive, grabFruitFiveArr, stickManVar);
                    FillObjectCharArray(eatFruitOne, eatFruitOneArr, stickManVar);
                    FillObjectCharArray(eatFruitTwo, eatFruitTwoArr, stickManVar);
                    FillObjectCharArray(eatFruitThree, eatFruitThreeArr, stickManVar);
                    FillObjectCharArray(eatFruitFour, eatFruitFourArr, stickManVar);
                    FillObjectCharArray(eatFruitFive, eatFruitFiveArr, stickManVar);
                    FillObjectCharArray(eatFruitSix, eatFruitSixArr, stickManVar);
                    FillObjectCharArray(callDog1, callDog1Arr, stickManVar);
                    FillObjectCharArray(callDog2, callDog2Arr, stickManVar);
                    FillObjectCharArray(callDog3, callDog3Arr, stickManVar);
                    FillObjectCharArray(callDog4, callDog4Arr, stickManVar);
                    FillObjectCharArray(callDog5, callDog5Arr, stickManVar);
                    FillObjectCharArray(callDog6, callDog6Arr, stickManVar);
                    FillObjectCharArray(callDog7, callDog7Arr, stickManVar);
                    FillObjectCharArray(callDog8, callDog8Arr, stickManVar);
                    FillObjectCharArray(callDog9, callDog9Arr, stickManVar);
                    FillObjectCharArray(callDog10, callDog10Arr, stickManVar);
                    FillObjectCharArray(callDog11, callDog11Arr, stickManVar);
                    FillObjectCharArray(callDog12, callDog12Arr, stickManVar);
                    FillObjectCharArray(callDog13, callDog13Arr, stickManVar);
                    FillObjectCharArray(callDog14, callDog14Arr, stickManVar);
                    FillWatchFireWorksCharArrays(watchFireWorks, watchFireWorksArr, watchFireWorksNumFrames, stickManVar); //fill all CHAR-INFO structs (frames)
                    FillStickManCharArrays(pushCloudOne, pushCloudOneArr, pushCloudOneNumFrames, stickManVar);

                    AddObject(hStdOut, lightSwitchTwoArr, stickManVar.area, stickManVar.fillCoord);
                    Sleep(150);
                    AddObject(hStdOut, lightSwitchOneArr, stickManVar.area, stickManVar.fillCoord);
                    Sleep(150);
                    AddObject(hStdOut, standLeftArr, stickManVar.area, stickManVar.fillCoord);
                }

                Sleep(1000); //stick man sleep time before next action
                eventCount++;

            }
            while(eventCount < eventLimit);
            userInput = 2;
            break;

        /**test animation: push cloud**/
        case 1:
            ClearArea(hStdOut, clearSpaceArr, clearSpaceSize, userInputFillCoord, userInputSize);


            AddObject(hStdOut, standRightArr, stickManVar.area, stickManVar.fillCoord); //remove when added to main loop
            Sleep(1000);

            /**move stick man if too far to the right**/
            if (stickManVar.fillCoord.X > 50)
            {
                MoveStickManLeft(hStdOut, stickManVar, standRightArr, leftOneArr, leftTwoArr, leftThreeArr, leftFourArr,
                                 1, stickManVar.fillCoord.X - 50, 100, clearSpaceArr, clearSpaceSize);
            }
            cloudOneVar.fillCoord.X = stickManVar.fillCoord.X + 11;
            cloudOneVar.fillCoord.Y = stickManVar.fillCoord.Y + 1;

            Sleep(1000);
            /**cloud appears**/
            AddObject(hStdOut, cloudOneArr[0], cloudOneVar.area, cloudOneVar.fillCoord);
            Sleep(sleepTime * 2);
            AddObject(hStdOut, cloudOneArr[1], cloudOneVar.area, cloudOneVar.fillCoord);
            Sleep(sleepTime * 2);
            AddObject(hStdOut, cloudOneArr[2], cloudOneVar.area, cloudOneVar.fillCoord);
            Sleep(sleepTime * 2);
            AddObject(hStdOut, cloudOneArr[3], cloudOneVar.area, cloudOneVar.fillCoord);
            Sleep(sleepTime * 2);
            AddObject(hStdOut, cloudOneArr[4], cloudOneVar.area, cloudOneVar.fillCoord);
            Sleep(sleepTime * 2);
            AddObject(hStdOut, cloudOneArr[5], cloudOneVar.area, cloudOneVar.fillCoord);
            Sleep(sleepTime * 2);
            AddObject(hStdOut, cloudOneArr[6], cloudOneVar.area, cloudOneVar.fillCoord);
            Sleep(sleepTime * 2);
            AddObject(hStdOut, cloudOneArr[7], cloudOneVar.area, cloudOneVar.fillCoord);
            Sleep(1000);

            /**stick man pushes cloud**/
            AddObject(hStdOut, pushCloudOneArr[0], stickManVar.area, stickManVar.fillCoord);
            Sleep(sleepTime * 1.5);
            AddObject(hStdOut, pushCloudOneArr[1], stickManVar.area, stickManVar.fillCoord);
            Sleep(sleepTime * 1.5);
            AddObject(hStdOut, pushCloudOneArr[2], stickManVar.area, stickManVar.fillCoord);
            Sleep(sleepTime * 1.5);
            AddObject(hStdOut, pushCloudOneArr[3], stickManVar.area, stickManVar.fillCoord);
            Sleep(sleepTime * 3);

            /**cloud moves away from stick man**/
            ClearArea(hStdOut, clearSpaceArr, clearSpaceSize, cloudOneVar.fillCoord, clearCloudSizeA);
            ClearArea(hStdOut, clearSpaceArr, clearSpaceSize, (COORD)
            {
                cloudOneVar.fillCoord.X, cloudOneVar.fillCoord.Y + 3
            }, clearCloudSizeB);
            cloudOneVar.fillCoord.X = cloudOneVar.fillCoord.X + 2;
            cloudOneVar.fillCoord.Y--;
            AddObject(hStdOut, cloudOneArr[7], cloudOneVar.area, cloudOneVar.fillCoord);
            Sleep(sleepTime * 1.5);
            ClearArea(hStdOut, clearSpaceArr, clearSpaceSize, cloudOneVar.fillCoord, clearCloudSizeA);
            ClearArea(hStdOut, clearSpaceArr, clearSpaceSize, (COORD)
            {
                cloudOneVar.fillCoord.X, cloudOneVar.fillCoord.Y + 3
            }, clearCloudSizeB);
            cloudOneVar.fillCoord.X = cloudOneVar.fillCoord.X + 2;
            cloudOneVar.fillCoord.Y--;
            AddObject(hStdOut, cloudOneArr[7], cloudOneVar.area, cloudOneVar.fillCoord);
            Sleep(sleepTime * 1.5);
            ClearArea(hStdOut, clearSpaceArr, clearSpaceSize, cloudOneVar.fillCoord, clearCloudSizeA);
            ClearArea(hStdOut, clearSpaceArr, clearSpaceSize, (COORD)
            {
                cloudOneVar.fillCoord.X, cloudOneVar.fillCoord.Y + 3
            }, clearCloudSizeB);
            cloudOneVar.fillCoord.X = cloudOneVar.fillCoord.X + 2;
            cloudOneVar.fillCoord.Y--;
            AddObject(hStdOut, cloudOneArr[7], cloudOneVar.area, cloudOneVar.fillCoord);
            AddObject(hStdOut, pushCloudOneArr[2], stickManVar.area, stickManVar.fillCoord);
            Sleep(sleepTime * 1.5);
            ClearArea(hStdOut, clearSpaceArr, clearSpaceSize, cloudOneVar.fillCoord, clearCloudSizeA);
            ClearArea(hStdOut, clearSpaceArr, clearSpaceSize, (COORD)
            {
                cloudOneVar.fillCoord.X, cloudOneVar.fillCoord.Y + 3
            }, clearCloudSizeB);
            cloudOneVar.fillCoord.X = cloudOneVar.fillCoord.X + 2;
            cloudOneVar.fillCoord.Y--;
            AddObject(hStdOut, cloudOneArr[7], cloudOneVar.area, cloudOneVar.fillCoord);
            AddObject(hStdOut, pushCloudOneArr[1], stickManVar.area, stickManVar.fillCoord);
            Sleep(sleepTime * 1.5);
            ClearArea(hStdOut, clearSpaceArr, clearSpaceSize, cloudOneVar.fillCoord, clearCloudSizeA);
            ClearArea(hStdOut, clearSpaceArr, clearSpaceSize, (COORD)
            {
                cloudOneVar.fillCoord.X, cloudOneVar.fillCoord.Y + 3
            }, clearCloudSizeB);
            cloudOneVar.fillCoord.X = cloudOneVar.fillCoord.X + 2;
            cloudOneVar.fillCoord.Y--;
            AddObject(hStdOut, cloudOneArr[7], cloudOneVar.area, cloudOneVar.fillCoord);
            AddObject(hStdOut, pushCloudOneArr[0], stickManVar.area, stickManVar.fillCoord);
            Sleep(sleepTime * 1.5);
            ClearArea(hStdOut, clearSpaceArr, clearSpaceSize, cloudOneVar.fillCoord, clearCloudSizeA);
            ClearArea(hStdOut, clearSpaceArr, clearSpaceSize, (COORD)
            {
                cloudOneVar.fillCoord.X, cloudOneVar.fillCoord.Y + 3
            }, clearCloudSizeB);
            cloudOneVar.fillCoord.X = cloudOneVar.fillCoord.X + 2;
            cloudOneVar.fillCoord.Y--;
            AddObject(hStdOut, cloudOneArr[7], cloudOneVar.area, cloudOneVar.fillCoord);
            AddObject(hStdOut, standRightArr, stickManVar.area, stickManVar.fillCoord);
            Sleep(sleepTime * 1.5);

            cloudTwoVar.fillCoord.X = cloudOneVar.fillCoord.X - 8;
            cloudTwoVar.fillCoord.Y = cloudOneVar.fillCoord.Y - 3;

            /**cloud continues moving away from stick man**/
            AddObject(hStdOut, cloudTwoArr[0], cloudTwoVar.area, cloudTwoVar.fillCoord);
            Sleep(sleepTime * 1.5);

            ClearArea(hStdOut, clearSpaceArr, clearSpaceSize, cloudTwoVar.fillCoord, cloudTwoVar.area);
            cloudTwoVar.fillCoord.X = cloudTwoVar.fillCoord.X + 2;
            cloudTwoVar.fillCoord.Y--;
            AddObject(hStdOut, cloudTwoArr[1], cloudTwoVar.area, cloudTwoVar.fillCoord);
            Sleep(sleepTime * 1.5);
            ClearArea(hStdOut, clearSpaceArr, clearSpaceSize, cloudTwoVar.fillCoord, cloudTwoVar.area);
            cloudTwoVar.fillCoord.X = cloudTwoVar.fillCoord.X + 2;
            cloudTwoVar.fillCoord.Y--;
            AddObject(hStdOut, cloudTwoArr[2], cloudTwoVar.area, cloudTwoVar.fillCoord);
            Sleep(sleepTime * 1.5);
            ClearArea(hStdOut, clearSpaceArr, clearSpaceSize, cloudTwoVar.fillCoord, cloudTwoVar.area);
            cloudTwoVar.fillCoord.X = cloudTwoVar.fillCoord.X + 2;
            cloudTwoVar.fillCoord.Y--;
            AddObject(hStdOut, cloudTwoArr[3], cloudTwoVar.area, cloudTwoVar.fillCoord);
            Sleep(sleepTime * 1.5);
            ClearArea(hStdOut, clearSpaceArr, clearSpaceSize, cloudTwoVar.fillCoord, cloudTwoVar.area);
            cloudTwoVar.fillCoord.X = cloudTwoVar.fillCoord.X + 2;
            cloudTwoVar.fillCoord.Y--;
            AddObject(hStdOut, cloudTwoArr[4], cloudTwoVar.area, cloudTwoVar.fillCoord);
            Sleep(sleepTime * 1.5);
            ClearArea(hStdOut, clearSpaceArr, clearSpaceSize, cloudTwoVar.fillCoord, cloudTwoVar.area);
            cloudTwoVar.fillCoord.X = cloudTwoVar.fillCoord.X + 2;
            cloudTwoVar.fillCoord.Y--;
            AddObject(hStdOut, cloudTwoArr[5], cloudTwoVar.area, cloudTwoVar.fillCoord);
            Sleep(sleepTime * 1.5);

            ClearArea(hStdOut, clearSpaceArr, clearSpaceSize, cloudTwoVar.fillCoord, cloudTwoVar.area);
            cloudTwoVar.fillCoord.X = cloudTwoVar.fillCoord.X + 2;
            cloudTwoVar.fillCoord.Y--;
            AddObject(hStdOut, cloudTwoArr[5], cloudTwoVar.area, cloudTwoVar.fillCoord);
            Sleep(sleepTime * 1.5);
            ClearArea(hStdOut, clearSpaceArr, clearSpaceSize, cloudTwoVar.fillCoord, cloudTwoVar.area);
            cloudTwoVar.fillCoord.X = cloudTwoVar.fillCoord.X + 2;
            cloudTwoVar.fillCoord.Y--;
            AddObject(hStdOut, cloudTwoArr[5], cloudTwoVar.area, cloudTwoVar.fillCoord);
            Sleep(sleepTime * 1.5);
            ClearArea(hStdOut, clearSpaceArr, clearSpaceSize, cloudTwoVar.fillCoord, cloudTwoVar.area);
            cloudTwoVar.fillCoord.X = cloudTwoVar.fillCoord.X + 2;
            cloudTwoVar.fillCoord.Y--;
            AddObject(hStdOut, cloudTwoArr[5], cloudTwoVar.area, cloudTwoVar.fillCoord);
            Sleep(sleepTime * 1.5);
            ClearArea(hStdOut, clearSpaceArr, clearSpaceSize, cloudTwoVar.fillCoord, cloudTwoVar.area);
            cloudTwoVar.fillCoord.X = cloudTwoVar.fillCoord.X + 2;
            cloudTwoVar.fillCoord.Y--;
            AddObject(hStdOut, cloudTwoArr[5], cloudTwoVar.area, cloudTwoVar.fillCoord);
            Sleep(sleepTime * 1.5);

            /**sun emerges**/
            AddObject(hStdOut, cloudTwoArr[6], cloudTwoVar.area, cloudTwoVar.fillCoord);
            Sleep(sleepTime * 3);
            AddObject(hStdOut, cloudTwoArr[7], cloudTwoVar.area, cloudTwoVar.fillCoord);
            Sleep(sleepTime * 3);
            AddObject(hStdOut, cloudTwoArr[8], cloudTwoVar.area, cloudTwoVar.fillCoord);
            Sleep(sleepTime * 3);
            AddObject(hStdOut, cloudTwoArr[9], cloudTwoVar.area, cloudTwoVar.fillCoord);
            Sleep(sleepTime * 3);
            AddObject(hStdOut, cloudTwoArr[10], cloudTwoVar.area, cloudTwoVar.fillCoord);
            Sleep(sleepTime * 3);
            AddObject(hStdOut, cloudTwoArr[11], cloudTwoVar.area, cloudTwoVar.fillCoord);
            Sleep(sleepTime * 3);
            AddObject(hStdOut, cloudTwoArr[12], cloudTwoVar.area, cloudTwoVar.fillCoord);
            Sleep(sleepTime * 3);

            Sleep(2000);

            ClearArea(hStdOut, clearSpaceArr, clearSpaceSize, cloudTwoVar.fillCoord, cloudTwoVar.area);


            Sleep(50000000);


        /**test animation: fire works**/
        case 2:
            ClearArea(hStdOut, clearSpaceArr, clearSpaceSize, userInputFillCoord, userInputSize);

            /**stick man walks to a place to sit and watch fire works**/
            if (stickManWatchFireWorksVar.fillCoord.X > 20)
            {
                MoveStickManLeft(hStdOut, stickManVar, standRightArr, leftOneArr, leftTwoArr, leftThreeArr, leftFourArr,
                                 1, stickManVar.fillCoord.X - 20, 100, clearSpaceArr, clearSpaceSize);
            }
            else if (stickManWatchFireWorksVar.fillCoord.X < 20)
            {
                MoveStickManRight(hStdOut, stickManVar, standRightArr, rightOneArr, rightTwoArr, rightThreeArr, rightFourArr,
                                  1, 20 - stickManVar.fillCoord.X, 100, clearSpaceArr, clearSpaceSize);
            }
            Sleep(1000);

            /**stick man sits to watch fire works**/
            stickManWatchFireWorksVar.fillCoord.X = stickManVar.fillCoord.X - 5;

            AddObject(hStdOut, watchFireWorksArr[0], stickManWatchFireWorksVar.area, stickManWatchFireWorksVar.fillCoord);
            Sleep(sleepTime * 2);
            AddObject(hStdOut, watchFireWorksArr[1], stickManWatchFireWorksVar.area, stickManWatchFireWorksVar.fillCoord);
            Sleep(sleepTime * 2);
            AddObject(hStdOut, watchFireWorksArr[2], stickManWatchFireWorksVar.area, stickManWatchFireWorksVar.fillCoord);
            Sleep(sleepTime * 2);
            AddObject(hStdOut, watchFireWorksArr[3], stickManWatchFireWorksVar.area, stickManWatchFireWorksVar.fillCoord);
            Sleep(sleepTime * 2);
            AddObject(hStdOut, watchFireWorksArr[4], stickManWatchFireWorksVar.area, stickManWatchFireWorksVar.fillCoord);
            Sleep(sleepTime * 2);
            AddObject(hStdOut, watchFireWorksArr[5], stickManWatchFireWorksVar.area, stickManWatchFireWorksVar.fillCoord);
            Sleep(sleepTime * 3);
            AddObject(hStdOut, watchFireWorksArr[6], stickManWatchFireWorksVar.area, stickManWatchFireWorksVar.fillCoord);
            Sleep(2000);

            /**fire works show**/
            do
            {
                int randVar = rand() % 10;

                COORD randCoordOne;
                COORD randCoordTwo;
                COORD randCoordThree;

                /**set fireworks coords**/
                randCoordOne.X = (rand() % (static_cast<int>((numX - fireWorksVar.area.X) * .8))) + ((numX - fireWorksVar.area.X) * .1);
                randCoordOne.Y = (rand() % (static_cast<int>(numY * .33))) + 1;

                do
                {
                    randCoordTwo.X = (rand() % (static_cast<int>((numX - fireWorksVar.area.X) * .8))) + ((numX - fireWorksVar.area.X) * .1);
                    randCoordTwo.Y = (rand() % (static_cast<int>(numY * .33))) + 1;
                }
                while(randCoordTwo.X > (randCoordOne.X - fireWorksVar.area.X) &&
                        randCoordTwo.X < (randCoordOne.X + fireWorksVar.area.X));

                do
                {
                    randCoordThree.X = (rand() % (static_cast<int>((numX - fireWorksVar.area.X) * .8))) + ((numX - fireWorksVar.area.X) * .1);
                    randCoordThree.Y = (rand() % (static_cast<int>(numY * .33))) + 1;
                }
                while((randCoordThree.X > (randCoordOne.X - fireWorksVar.area.X) &&
                        randCoordThree.X < (randCoordOne.X + fireWorksVar.area.X)) ||
                        (randCoordThree.X > (randCoordTwo.X - fireWorksVar.area.X) &&
                         randCoordThree.X < (randCoordTwo.X + fireWorksVar.area.X)));

                /**one fire work**/
                if (randVar <= 2)
                {
                    AddObject(hStdOut, fireWorksArr[0], fireWorksVar.area, randCoordOne);
                    Sleep(sleepTime);
                    AddObject(hStdOut, fireWorksArr[1], fireWorksVar.area, randCoordOne);
                    Sleep(sleepTime);
                    AddObject(hStdOut, fireWorksArr[2], fireWorksVar.area, randCoordOne);
                    Sleep(sleepTime);
                    AddObject(hStdOut, fireWorksArr[3], fireWorksVar.area, randCoordOne);
                    Sleep(sleepTime);
                    AddObject(hStdOut, fireWorksArr[4], fireWorksVar.area, randCoordOne);
                    Sleep(sleepTime);
                    AddObject(hStdOut, fireWorksArr[5], fireWorksVar.area, randCoordOne);
                    Sleep(sleepTime);
                    AddObject(hStdOut, fireWorksArr[6], fireWorksVar.area, randCoordOne);
                    Sleep(sleepTime);
                    AddObject(hStdOut, fireWorksArr[7], fireWorksVar.area, randCoordOne);
                    Sleep(sleepTime);
                    AddObject(hStdOut, fireWorksArr[8], fireWorksVar.area, randCoordOne);
                    Sleep(sleepTime);
                    ClearArea(hStdOut, clearSpaceArr, clearSpaceSize, randCoordOne, fireWorksVar.area);
                    Sleep(1000);
                }
                /**two fire works**/
                else if (randVar <= 5)
                {
                    AddObject(hStdOut, fireWorksArr[0], fireWorksVar.area, randCoordOne);
                    Sleep(sleepTime);
                    AddObject(hStdOut, fireWorksArr[1], fireWorksVar.area, randCoordOne);
                    Sleep(sleepTime);
                    AddObject(hStdOut, fireWorksArr[2], fireWorksVar.area, randCoordOne);
                    Sleep(sleepTime);
                    AddObject(hStdOut, fireWorksArr[3], fireWorksVar.area, randCoordOne);
                    Sleep(sleepTime);
                    AddObject(hStdOut, fireWorksArr[4], fireWorksVar.area, randCoordOne);
                    AddObject(hStdOut, fireWorksArr[0], fireWorksVar.area, randCoordTwo);
                    Sleep(sleepTime);
                    AddObject(hStdOut, fireWorksArr[5], fireWorksVar.area, randCoordOne);
                    AddObject(hStdOut, fireWorksArr[1], fireWorksVar.area, randCoordTwo);
                    Sleep(sleepTime);
                    AddObject(hStdOut, fireWorksArr[6], fireWorksVar.area, randCoordOne);
                    AddObject(hStdOut, fireWorksArr[2], fireWorksVar.area, randCoordTwo);
                    Sleep(sleepTime);
                    AddObject(hStdOut, fireWorksArr[7], fireWorksVar.area, randCoordOne);
                    AddObject(hStdOut, fireWorksArr[3], fireWorksVar.area, randCoordTwo);
                    Sleep(sleepTime);
                    AddObject(hStdOut, fireWorksArr[8], fireWorksVar.area, randCoordOne);
                    AddObject(hStdOut, fireWorksArr[4], fireWorksVar.area, randCoordTwo);
                    Sleep(sleepTime);
                    ClearArea(hStdOut, clearSpaceArr, clearSpaceSize, randCoordOne, fireWorksVar.area);
                    AddObject(hStdOut, fireWorksArr[5], fireWorksVar.area, randCoordTwo);
                    Sleep(sleepTime);
                    AddObject(hStdOut, fireWorksArr[6], fireWorksVar.area, randCoordTwo);
                    Sleep(sleepTime);
                    AddObject(hStdOut, fireWorksArr[7], fireWorksVar.area, randCoordTwo);
                    Sleep(sleepTime);
                    AddObject(hStdOut, fireWorksArr[8], fireWorksVar.area, randCoordTwo);
                    Sleep(sleepTime);
                    ClearArea(hStdOut, clearSpaceArr, clearSpaceSize, randCoordTwo, fireWorksVar.area);
                    Sleep(1000);
                }
                else
                {
                    /**three fire works**/
                    AddObject(hStdOut, fireWorksArr[0], fireWorksVar.area, randCoordOne);
                    Sleep(sleepTime);
                    AddObject(hStdOut, fireWorksArr[1], fireWorksVar.area, randCoordOne);
                    Sleep(sleepTime);
                    AddObject(hStdOut, fireWorksArr[2], fireWorksVar.area, randCoordOne);
                    Sleep(sleepTime);
                    AddObject(hStdOut, fireWorksArr[3], fireWorksVar.area, randCoordOne);
                    Sleep(sleepTime);
                    AddObject(hStdOut, fireWorksArr[4], fireWorksVar.area, randCoordOne);
                    AddObject(hStdOut, fireWorksArr[0], fireWorksVar.area, randCoordTwo);
                    Sleep(sleepTime);
                    AddObject(hStdOut, fireWorksArr[5], fireWorksVar.area, randCoordOne);
                    AddObject(hStdOut, fireWorksArr[1], fireWorksVar.area, randCoordTwo);
                    Sleep(sleepTime);
                    AddObject(hStdOut, fireWorksArr[6], fireWorksVar.area, randCoordOne);
                    AddObject(hStdOut, fireWorksArr[2], fireWorksVar.area, randCoordTwo);
                    Sleep(sleepTime);
                    AddObject(hStdOut, fireWorksArr[7], fireWorksVar.area, randCoordOne);
                    AddObject(hStdOut, fireWorksArr[3], fireWorksVar.area, randCoordTwo);
                    Sleep(sleepTime);
                    AddObject(hStdOut, fireWorksArr[8], fireWorksVar.area, randCoordOne);
                    AddObject(hStdOut, fireWorksArr[4], fireWorksVar.area, randCoordTwo);
                    Sleep(sleepTime);
                    ClearArea(hStdOut, clearSpaceArr, clearSpaceSize, randCoordOne, fireWorksVar.area);
                    AddObject(hStdOut, fireWorksArr[5], fireWorksVar.area, randCoordTwo);
                    AddObject(hStdOut, fireWorksArr[0], fireWorksVar.area, randCoordThree);
                    Sleep(sleepTime);
                    AddObject(hStdOut, fireWorksArr[6], fireWorksVar.area, randCoordTwo);
                    AddObject(hStdOut, fireWorksArr[1], fireWorksVar.area, randCoordThree);
                    Sleep(sleepTime);
                    AddObject(hStdOut, fireWorksArr[7], fireWorksVar.area, randCoordTwo);
                    AddObject(hStdOut, fireWorksArr[2], fireWorksVar.area, randCoordThree);
                    Sleep(sleepTime);
                    AddObject(hStdOut, fireWorksArr[8], fireWorksVar.area, randCoordTwo);
                    AddObject(hStdOut, fireWorksArr[3], fireWorksVar.area, randCoordThree);
                    Sleep(sleepTime);
                    ClearArea(hStdOut, clearSpaceArr, clearSpaceSize, randCoordTwo, fireWorksVar.area);
                    AddObject(hStdOut, fireWorksArr[4], fireWorksVar.area, randCoordThree);
                    Sleep(sleepTime);
                    AddObject(hStdOut, fireWorksArr[5], fireWorksVar.area, randCoordThree);
                    Sleep(sleepTime);
                    AddObject(hStdOut, fireWorksArr[6], fireWorksVar.area, randCoordThree);
                    Sleep(sleepTime);
                    AddObject(hStdOut, fireWorksArr[8], fireWorksVar.area, randCoordThree);
                    Sleep(sleepTime);
                    ClearArea(hStdOut, clearSpaceArr, clearSpaceSize, randCoordThree, fireWorksVar.area);
                    Sleep(1000);
                }

            }
            while(true);

        }
    }
    while (true);

    return 0;
}

