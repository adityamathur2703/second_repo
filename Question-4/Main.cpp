#include "Functionalities.h"

#include <thread>

int main(){
    Container data;
    createMapObjects(data);

    try{
        std::cout<<"-----------------------------------------------------------"<<std::endl;
        std::thread t1(&countEngineIC , std::ref(data));
        std::thread t2(&sameVehicleId , std::ref(data), "B2");
        std::thread t3(&sameSoftwareType , std::ref(data));
        std::thread t4(&hasEvEngineType , std::ref(data));
        std::thread t5(&averageEngineTorque , std::ref(data));

        t1.join();
        t2.join();
        t3.join();
        t4.join();
        t5.join();
        std::cout<<"-----------------------------------------------------------"<<std::endl;
    }
    catch(EmptyContainerException& ex){
        std::cout<<ex.what()<<std::endl;
    }
    catch(IdNotFoundException& ex){
        std::cout<<ex.what()<<std::endl;
    }
}