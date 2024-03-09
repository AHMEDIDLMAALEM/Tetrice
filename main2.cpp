#include <iostream>
#include <chrono>
#include <thread>
static bool s_Finished = false;
void doWork(){
    while (!s_Finished)
    {
        /* code */
    }
    
}
int main(){
    std::thread worker(doWork);
    std::cin.get();
    s_Finished = true;
    worker.join();
    srd::cin.get();
}