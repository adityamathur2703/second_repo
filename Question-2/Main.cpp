#include "DataHandler.h"
#include <thread>

int main(){
    std::array<int, 5> arr;
    Pointer obj=DataHandler::getfirstInstances({0,0,0,0,0});

    std::thread t1(&DataHandler::TakeInput, obj, std::ref(arr));
    t1.join();

    std::thread t2(&DataHandler::ComputSquare, obj);
    t2.join();

    std::thread t3(&DataHandler::ComputeFactorial, obj);
    t3.join();

    std::thread t4(&DataHandler::AverageValue, obj);
    t4.join();
}