//#include<conio.h>
//#include "Game.h"
#include "raylib.h"
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

    
    InitWindow(screenWidth, screenHeight, "Dessiner des formes");
    SetTargetFPS(60);
    Color colors[] = { BLUE, YELLOW, RED, GREEN };
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        for (int i = 0; i <= 3; i++)
        {
            DrawCircle(20 + i * 60, 20, 20, colors[i]);
            DrawRectangleRec(Rectangle{ float(20 + i * 60),60, 40,40 }, colors[i]);
            DrawRectanglePro(Rectangle{ float(40 + i * 60),120, 40,40 }, { 0,0 }, 45.0f, colors[i]);
            DrawTriangle({ float(20 + i * 60), 220 }, { float(60 + i * 60), 220 }, { float(40 + i * 60), 185 }, colors[i]);

        }
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
