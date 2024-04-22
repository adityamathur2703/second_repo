#include "Functionalities.h"
#include "EmptyContainerException.h"
#include "NoInstanceFound.h"
#include <mutex>

std::mutex mt;

void createObjects(Container& data){
    PrivateVehiclePointer p1=std::make_shared<PrivateVehicle>("Ab12", "Hero", 100000.0f, LicenseCategory::LEARNING, 2);
    PrivateVehiclePointer p2=std::make_shared<PrivateVehicle>("Cd34", "Honda", 900000.0f, LicenseCategory::PERMANENT, 5);

    TransportVehiclePointer p3=std::make_shared<TransportVehicle>("Mn56", "Kia", 150000.0f, TransportLicenseCategory::HMV, 6);
    TransportVehiclePointer p4=std::make_shared<TransportVehicle>("Xy78", "Ertiga", 350000.0f, TransportLicenseCategory::HMV_STATE, 7);
    
    data.push_back(p1);
    data.push_back(p2);
    data.push_back(p3);
    data.push_back(p4);
}

std::vector<TransportLicenseCategory> CategoryOfLicense(Container &data)
{
    if(data.empty()){
        throw EmptyContainerException("Data Not Found!", std::future_errc::no_state);
    }
    std::lock_guard<std::mutex> lg(mt);
    std::vector<TransportLicenseCategory> ans;
    int n=0;
    for(Combined v:data){
        if(std::holds_alternative<TransportVehiclePointer>(v)){         // For specific
            TransportVehiclePointer p = std::get<1>(v);
            ans.push_back(p->lType());
            n++;
        }
    }
    if(n==0){
        throw NoInstanceFound("No Instance Found!", std::future_errc::no_state);
    }
    return ans;
}

void averageVehiclePrice(Container &data)
{
    if(data.empty()){
        throw EmptyContainerException("Data Not Found!", std::future_errc::no_state);
    }
    std::lock_guard<std::mutex> lg(mt);
    int ans=0;
    int n=0;
    for(Combined v:data){
        if(std::holds_alternative<PrivateVehiclePointer>(v)){         // For specific
            PrivateVehiclePointer p = std::get<0>(v);
            ans+=p->vehiclePrice();
            n++;
        }
    }
    if(n==0){
        throw NoInstanceFound("No Instance Found!", std::future_errc::no_state);
    }
    std::cout<<"Average Vehicle Price of Private Vehicle is: "<<ans/n<<std::endl;
}

void VehiclePrices(Container &data, std::future<int>& ft)
{
    if(data.empty()){
        throw EmptyContainerException("Data Not Found!", std::future_errc::no_state);
    }
    std::lock_guard<std::mutex> lg(mt);
    int n = ft.get();
    int check=0;
    for(Combined v:data){
        std::visit(              // For all
            [&](auto&& val){
                if(n==0){
                    return;
                }     
                std::cout<<val->vehiclePrice()<<"\n";
                n--;
                check++;
            },
            v
        );
    }
    if(check==0){
        throw NoInstanceFound("No Instance Found!", std::future_errc::no_state);
    }
}

bool checkType(Container &data)
{
    if(data.empty()){
        throw EmptyContainerException("Data Not Found!", std::future_errc::no_state);
    }
    std::lock_guard<std::mutex> lg(mt);
    PrivateVehiclePointer p = std::get<0>(data[0]);
    LicenseCategory lt = p->lType();
    int n=0;
    for(Combined v:data){
        if(std::holds_alternative<PrivateVehiclePointer>(v)){         // For specific
            PrivateVehiclePointer p = std::get<0>(v);
            if(p->lType()!=lt){
                return false;
            }
            n++;
        }
    }
    if(n==0){
        throw NoInstanceFound("No Instance Found!", std::future_errc::no_state);
    }
    return true;
}
