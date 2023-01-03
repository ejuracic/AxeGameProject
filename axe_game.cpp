#include "raylib.h"

//Window Dimensions
const int windowWidth = 800;    //setting the window width 
const int windowHeight = 450;   //setting the window height value

int main()
{
    //Circle Dimensions
    int circleXCoordinate = 200;  //Setting the X coordinates where the Circle will be related to the X-Axis of the window
    int circleYCoordinate = 200;  //Setting the Y coordinates where the Circle will be related to the Y-Axis of the window
    int circleRadius = 25;        //Radius of the circle

    //Circle Coordinates
    int leftCircleX = circleXCoordinate - circleRadius;
    int rightCircleX = circleXCoordinate + circleRadius;
    int upperCircleY = circleYCoordinate - circleRadius;
    int bottomCircleY = circleYCoordinate + circleRadius;

    //axe dimensions
    int axeXCoordinate = 400;
    int axeYCoordinate = 0;
    int axeLength = 50;

    //axe edges
    int leftAxeX = axeXCoordinate;
    int rightAxeX = axeXCoordinate + axeLength;
    int upperAxeY = axeYCoordinate;
    int bottomAxeY = axeYCoordinate + axeLength;

    int axeDirection = 10;

    //collision detection bool
    bool collisionWithAxe = false;

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
        if (collisionWithAxe == true)
        {
            DrawText("Game Over!", 400, 200, 20, RED);
        }

        else
        {
            DrawCircle(circleXCoordinate, circleYCoordinate, circleRadius, BLUE); //first two parameters represent coordinates within the X & Y axis of the screen, third parameter is radius of the circle. Last parameter is color
            
            DrawRectangle(axeXCoordinate, axeYCoordinate, axeLength, axeLength, RED);

            //move the axe
            axeYCoordinate += axeDirection;

            //if the axe either hits the top or bottom of the screen, reverse the direction
            if (axeYCoordinate > windowHeight || axeYCoordinate < 0)
            {
                axeDirection = -axeDirection;
            }

            //the and statements below represent the boundaries that the circle can work within the window. If it tries to overstep, it is blocked from moving in that direction

            //go right
            if(IsKeyDown(KEY_D) && circleXCoordinate < windowWidth)
            {
                circleXCoordinate += 5;
            }

            //go left
            if(IsKeyDown(KEY_A) && circleXCoordinate > 0)
            {
                circleXCoordinate -= 5;
            }

            //go up
            if(IsKeyDown(KEY_W) && circleYCoordinate > 0)
            {
                circleYCoordinate -= 5;
            }

            //go down
            if(IsKeyDown(KEY_S) && circleYCoordinate < windowHeight)
            {
                circleYCoordinate += 5;
            }

        }

        //game logic ends

        EndDrawing();   //ending the drawing process
        
    }
}