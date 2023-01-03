#include "raylib.h"

//Window Dimensions
const int windowWidth = 350;    //setting the window width 
const int windowHeight = 200;   //setting the window height value

int main()
{
    //Circle Dimensions
    int circleXCoordinate = 175;  //Setting the X coordinates where the Circle will be related to the X-Axis of the window
    int circleYCoordinate = 100;  //Setting the Y coordinates where the Circle will be related to the Y-Axis of the window
    int circleRadius = 25;        //Radius of the circle


    //initializing the window
    InitWindow(windowWidth, windowHeight, "Axe Game");

    SetTargetFPS(60);

//WindowShouldClose returns true if user hits the X button or presses X
//so this while loop will keep running until the user does either one of the two conditions above and end the game
    while (WindowShouldClose() == false)
    {
        BeginDrawing(); //drawing on the canvas within the window
        ClearBackground(WHITE); //clearing the background to avoid the screen flickering

        //game logic begins


        DrawCircle(circleXCoordinate, circleYCoordinate, circleRadius, BLUE); //first two parameters represent coordinates within the X & Y axis of the screen, third parameter is radius of the circle. Last parameter is color
        
        //the and statements below represent the boundaries that the circle can work within the window. If it tries to overstep, it is blocked from moving in that direction
        
        //go right
        if(IsKeyDown(KEY_D) && circleXCoordinate < windowWidth)
        {
            circleXCoordinate = circleXCoordinate + 5;
        }

        //go left
        if(IsKeyDown(KEY_A) && circleXCoordinate > 0)
        {
            circleXCoordinate = circleXCoordinate - 5;
        }

        //go up
        if(IsKeyDown(KEY_W) && circleYCoordinate > 0)
        {
            circleYCoordinate = circleYCoordinate - 5;
        }

        //go down
        if(IsKeyDown(KEY_S) && circleYCoordinate < windowHeight)
        {
            circleYCoordinate = circleYCoordinate + 5;
        }


        //game logic ends

        EndDrawing();   //ending the drawing process
    }
}