

#include<conio.h>
#include "Game.h"
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
// g++ -o myprogram main.cpp -lpthread

int main() {

    Party* p = new Party(3);
    
    //Game g;
    _getch();
    // Create a new thread and pass the function to be executed
    //std::thread t(threadFunction);%
    //char choice = _getch();
    //if (choice == 'p')
    //{
    //    s_finished = true;
    //}

    //// Wait for the thread to finish execution
    //t.join();

    //std::cout << "Hello from main!\n";

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
