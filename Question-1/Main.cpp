#include "Functionalities.h"
#include <thread>


int main(){
    Container data;
    createObjects(data);

    std::thread t1(&findPermitNumber, std::ref(data), 2);
    std::thread t2(&averageSeatCount, std::ref(data), VehicleType::BUS);
    std::thread t3(&sameVehicleType, std::ref(data));

    t1.join();
    std::cout<<" "<<std::endl;
    t2.join();
    std::cout<<" "<<std::endl;
    t3.join();
    std::cout<<" "<<std::endl;
}