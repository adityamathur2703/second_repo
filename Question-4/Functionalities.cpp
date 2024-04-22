#include "Functionalities.h"
#include <mutex>

std::mutex mt;

void createMapObjects(Container& data){
    data.emplace("A1", std::make_shared<ConnectedVehicle>("A1", "XYZ", VehicleSoftwareType::ADAPTIVE_AUTOSAR, VehicleNormCategory::EU, std::make_shared<Engine>(EngineType::EV, 100, 150.0f), VehicleFeautures::Good));
    data.emplace("B2", std::make_shared<ConnectedVehicle>("B2", "MNQ", VehicleSoftwareType::CLASSIC_AUTOSAR, VehicleNormCategory::GB, std::make_shared<Engine>(EngineType::IC, 150, 100.0f), VehicleFeautures::Good));
    data.emplace("C3", std::make_shared<ConnectedVehicle>("C3", "ABC", VehicleSoftwareType::CLASSIC_AUTOSAR, VehicleNormCategory::US, std::make_shared<Engine>(EngineType::EV, 90, 80.0f), VehicleFeautures::Good));
    data.emplace("D4", std::make_shared<ConnectedVehicle>("D4", "ILR", VehicleSoftwareType::ADAPTIVE_AUTOSAR, VehicleNormCategory::BS6_IN, std::make_shared<Engine>(EngineType::IC, 50, 200.0f), VehicleFeautures::Good));
}

void countEngineIC(Container &data)
{
    if(data.empty()){
        throw EmptyContainerException("Data Not Found!");
    }
    std::lock_guard<std::mutex> lg(mt);
    int count=0;
    for(auto& [key, value] : data){
        if(value->engine()->eType()==EngineType::IC){
            count++;
        }
    }
    if(count==0){
        throw IdNotFoundException("No Instances Found!");
    }
    std::cout<<"Instances having IC Engine Type are: "<<count<<std::endl;
}

void sameVehicleId(Container &data, std::string id)
{
    if(data.empty()){
        throw EmptyContainerException("Data Not Found!");
    }
    std::lock_guard<std::mutex> lg(mt);
    float ans{0.0f};
    for(auto& [key, value] : data){
        if(value->vehicleId()==id){
            ans=value->engine()->engineTorque();
            break;
        }
    }
    if(ans==0.0f){
        throw IdNotFoundException("No Instances Found!");
    }
    else{
        std::cout<<"Vehicle Founded, Torque is: "<<ans<<std::endl;
    }
}

std::vector<ConnectedPointer> sameSoftwareType(Container &data)
{
    if(data.empty()){
        throw EmptyContainerException("Data Not Found!");
    }
    std::lock_guard<std::mutex> lg(mt);
    std::vector<ConnectedPointer> ans;
    std::cout<<"Vehicle ID of Adaptive Autosar Type are: ";
    for(auto& [key, value] : data){
        if(value->sType()==VehicleSoftwareType::ADAPTIVE_AUTOSAR){
            std::cout<<value->vehicleFullModel()<<"  ";
            ans.push_back(value);
        }
    }
    std::cout<<std::endl;
    return ans;
}

void hasEvEngineType(Container &data)
{
    if(data.empty()){
        throw EmptyContainerException("Data Not Found!");
    }
    std::lock_guard<std::mutex> lg(mt);
    bool check=false;
    for(auto& [key, value] : data){
        if(value->engine()->eType()==EngineType::EV){
            check=true;
            break;
        }
    }
    std::cout<<"Instances have at least one EV Engine Type: "<<std::boolalpha<<check<<std::endl;
}

void averageEngineTorque(Container &data)
{
    if(data.empty()){
        throw EmptyContainerException("Data Not Found!");
    }
    std::lock_guard<std::mutex> lg(mt);
    float sum{0.0f};
    for(auto& [key, value] : data){
        sum+=value->engine()->engineTorque();
    }
    if(sum==0.0f){
        throw IdNotFoundException("No Instances Found!");
    }
    std::cout<<"The Average Engine Torque is: "<<sum/data.size()<<std::endl;
}
