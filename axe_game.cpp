#include "raylib.h"

const int windowWidth = 350;    //setting the window width 
const int windowHeight = 200;   //setting the window height value

int main()
{
    //initializing the window
    InitWindow(windowWidth, windowHeight, "Axe Game");

//WindowShouldClose returns true if user hits the X button or presses X
//so this while loop will keep running until the user does either one of the two conditions above and end the game
    while (WindowShouldClose() == false)
    {
        BeginDrawing(); //drawing on the canvas within the window
        ClearBackground(RED); //clearing the background to avoid the screen flickering
        EndDrawing();   //ending the drawing process
    }
}