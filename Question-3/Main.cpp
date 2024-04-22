#include "Functionalities.h"
#include "EmptyContainerException.h"
#include "NoInstanceFound.h"
#include <future>

int main(){
    Container data;
    createObjects(data);

    try{
        std::cout<<"----------------------------------------------------------------------------"<<std::endl;
        std::future<std::vector<TransportLicenseCategory>> ans1 = std::async(&CategoryOfLicense, std::ref(data));
        std::cout<<"License Category are: ";
        for(TransportLicenseCategory t:ans1.get()){
            if(t==TransportLicenseCategory::HMV){
                std::cout<<"HMV  ";
            }
            else{
                std::cout<<"HMV_STATE  ";
            }
        }

        std::future<void> ans2 = std::async(&averageVehiclePrice, std::ref(data));
        std::cout<<std::endl;

        std::promise<int> pr;
        std::future<int> ft=pr.get_future();
        std::future<void> ans3 = std::async(&VehiclePrices, std::ref(data), std::ref(ft));
        int value=0;
        std::cout<<"Enter n to display Instances: ";
        std::cin>>value;
        pr.set_value(value);

        std::future<bool> ans4 = std::async(&checkType, std::ref(data));
        std::cout<<"All Private Vehicle are of same Type: "<<std::boolalpha<<ans4.get()<<std::endl;
        std::cout<<"----------------------------------------------------------------------------"<<std::endl;
    }
    catch(EmptyContainerException& ex){
        std::cout<<ex.what()<<std::endl;
    }
    catch(NoInstanceFound& ex){
        std::cout<<ex.what()<<std::endl;
    }
}