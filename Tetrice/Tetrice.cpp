//#include<conio.h>
//#include "Game.h"
#include "raylib.h"
#include "piece.h"
static bool s_finished = false;
// Function to be executed in a separate thread
//void threadFunction() {
//    int i = 0;
//    while (!s_finished) {
//        if (!(i % 10))
//            system("cls");
//        std::cout << "*";
//        std::this_thread::sleep_for(std::chrono::milliseconds(800));
//        
//        //std::this_thread::sleep_for()
//        i++;
//
//    }
//    std::cout << "hi from thread ";
//}
const int screenWidth = 1200;
const int screenHeight = 600;
int main() {

    //Game g;
    //_getch();

    const int screenWidth = 1200;
    const int screenHeight = 600;
    InitWindow(screenWidth, screenHeight, "Dessiner des formes");
    SetTargetFPS(60);

    Color colors[] = { BLUE, YELLOW, RED, GREEN };
    static float rotation = 0.0f;
    float x = 600.0f, y = 80.0f;
    bool canDPressKey = true;
    bool canGPressKey = true;

    /*-----------------------------------------*/

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        piece cercleGreen(Cercle, Green, float(x), float(y));
        cercleGreen.draw();
        /* if (x < 0) x = 0;
         if (y < 0) y = 0;
         if (x > screenWidth - 40) x = screenWidth - 40;
         if (y > screenHeight - 40) y = screenHeight - 40;*/
        if (IsKeyPressed(KEY_RIGHT) && canDPressKey) {
            x += GetFrameTime() + 250.0f;
            y += GetFrameTime() + 250.0f;
            canDPressKey = false;
            canGPressKey = false;


        }if (IsKeyPressed(KEY_LEFT) && canGPressKey) {
            x -= GetFrameTime() + 250.0f;
            y += GetFrameTime() + 250.0f;
            canGPressKey = false;
            canDPressKey = false;



        }if (IsKeyPressed(KEY_UP)) {
            x = 600;
            y = 80;
            canGPressKey = true;
            canDPressKey = true;

        }
        /*static float rotation = 45.0f;
        DrawRectanglePro(Rectangle{x ,y, 40,40 }, { 20,20 }, rotation, colors[0]);*/

        /*for (int i = 0; i <= 3; i++)
         {
             static float rotation = 45.0f;
             rotation += 0.5f;
             DrawCircle(20+i*60, 320, 20, colors[i]);
             DrawRectangleRec(Rectangle{float( 20 + i * 60),360, 40,40 }, colors[i]);
             DrawRectanglePro(Rectangle{float( 40 + i * 60),440, 40,40 },{20,20}, rotation, colors[i]);
             DrawTriangle({ float(20 + i * 60), 530 }, { float(60 + i * 60), 530 }, { float(40 + i * 60), 495 }, colors[i]);


         }*/
        EndDrawing();
    }

    CloseWindow();
    return 0;
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
