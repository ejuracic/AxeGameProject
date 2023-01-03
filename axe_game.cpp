#include "raylib.h"

//Window Dimensions
const int windowWidth = 350;    //setting the window width 
const int windowHeight = 200;   //setting the window height value

int main()
{
    //Circle Dimensions
    float circleXCoordinate = 175;  //Setting the X coordinates where the Circle will be related to the X-Axis of the window
    float circleYCoordinate = 100;  //Setting the Y coordinates where the Circle will be related to the Y-Axis of the window
    float circleRadius = 25;        //Radius of the circle


    //initializing the window
    InitWindow(windowWidth, windowHeight, "Axe Game");

//WindowShouldClose returns true if user hits the X button or presses X
//so this while loop will keep running until the user does either one of the two conditions above and end the game
    while (WindowShouldClose() == false)
    {
        BeginDrawing(); //drawing on the canvas within the window
        ClearBackground(WHITE); //clearing the background to avoid the screen flickering

        //game logic begins


        DrawCircle(circleXCoordinate, circleYCoordinate, circleRadius, BLUE); //first two parameters represent coordinates within the X & Y axis of the screen, third parameter is radius of the circle. Last parameter is color
        
        //go right
        if(IsKeyDown(KEY_D))
        {
            circleXCoordinate = circleXCoordinate + 0.1;
        }

        //go left
        if(IsKeyDown(KEY_A))
        {
            circleXCoordinate = circleXCoordinate - 0.1;
        }

        //go up
        if(IsKeyDown(KEY_W))
        {
            circleYCoordinate = circleYCoordinate - 0.1;
        }

        //go down
        if(IsKeyDown(KEY_S))
        {
            circleYCoordinate = circleYCoordinate + 0.1;
        }


        //game logic ends

        EndDrawing();   //ending the drawing process
    }
}