#include "TransportVehicle.h"

TransportVehicle::TransportVehicle(std::string vehicleRegistrationNumber, std::string vehicleBrand, float vehiclePrice, TransportLicenseCategory lType, float loadCarryingCapacity)
:_vehicleRegistrationNumber{vehicleRegistrationNumber}, _vehicleBrand{vehicleBrand}, _vehiclePrice{vehiclePrice}, _lType{lType}, _loadCarryingCapacity{loadCarryingCapacity}
{}


std::ostream &operator<<(std::ostream &os, const TransportVehicle &rhs) {
    std::string type{""};
    if(rhs._lType==TransportLicenseCategory::HMV){
        type= "HMV";
    }
    else{
        type="HMV_STATE";
    }
    os << "_vehicleRegistrationNumber: " << rhs._vehicleRegistrationNumber
       << " _vehicleBrand: " << rhs._vehicleBrand
       << " _vehiclePrice: " << rhs._vehiclePrice
       << " _lType: " << type
       << " _loadCarryingCapacity: " << rhs._loadCarryingCapacity;
    return os;
}
