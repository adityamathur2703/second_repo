#include "Functionalities.h"
#include <mutex>

std::mutex mt;

void createObjects(Container &data)
{
    data.push_back(std::make_shared<TransportVehicle>(std::make_shared<Permit>("P1", 10), VehicleType::BUS, 50, 15));
    data.push_back(std::make_shared<TransportVehicle>(std::make_shared<Permit>("P2", 15), VehicleType::CAB, 20, 10));
    data.push_back(std::make_shared<TransportVehicle>(std::make_shared<Permit>("P3", 25), VehicleType::MINI_VAN, 10, 5));
    data.push_back(std::make_shared<TransportVehicle>(std::make_shared<Permit>("P4", 5), VehicleType::BUS, 30, 20));
}

std::function<std::optional<bool>(Container&, int)> PermiNumber=[](Container &data, int n)->std::optional<bool>{
    if(data.empty()){
        throw EmptyContainerException("Data Not Found");
    }
    std::string num{""};
    num=data[n-1]->permit()->permitNumber();
    if(num==""){
        return std::nullopt;
    }
    std::cout<<num<<std::endl;
    return true;
};

void sameVehicleType(Container &data)
{
    if(data.empty()){
        throw EmptyContainerException("Data Not Found");
    }
    std::lock_guard<std::mutex> lg(mt);
    std::cout<<"All Vehicle have same Vehicle Type: ";
    VehicleType temp = data[0]->vType();
    std::cout<<std::boolalpha<<std::all_of(
        data.begin(),
        data.end(),
        [&](TransportPointer& p){
            return p->vType()==temp;
        }
    );
}

void findPermitNumber(Container &data, int n)
{
    if(data.empty()){
        throw EmptyContainerException("Data Not Found");
    }
    std::lock_guard<std::mutex> lg(mt);
    std::cout<<"Permit Number is: ";
    std::cout<<data[n-1]->permit()->permitNumber()<<std::endl;
}

void averageSeatCount(Container &data, VehicleType vt)
{
    std::lock_guard<std::mutex> lg(mt);
    std::cout<<"The Average is: ";
    int n=0;
    unsigned int sum=std::accumulate(
        data.begin(),
        data.end(),
        0,
        [&](unsigned int answer_upto_now, TransportPointer& p){
            if(p->vType()==vt){
                n++;
                return answer_upto_now+p->seatCount();
            }
            return answer_upto_now;
        }
    );
    std::cout<<sum/n<<std::endl;
}
