#include "PrivateVehicle.h"


std::ostream &operator<<(std::ostream &os, const PrivateVehicle &rhs) {
    std::string type{""};
    if(rhs._lType==LicenseCategory::LEARNING){
        type= "LEARNING";
    }
    else{
        type="PERMANENT";
    }
    os << "_vehicleRegistrationNumber: " << rhs._vehicleRegistrationNumber
       << " _vehicleBrand: " << rhs._vehicleBrand
       << " _vehiclePrice: " << rhs._vehiclePrice
       << " _lType: " << type
       << " _seatCount: " << rhs._seatCount;
    return os;
}

PrivateVehicle::PrivateVehicle(std::string vehicleRegistrationNumber, std::string vehicleBrand, float vehiclePrice, LicenseCategory lType, unsigned int seatCount)
:_vehicleRegistrationNumber{vehicleRegistrationNumber}, _vehicleBrand{vehicleBrand}, _vehiclePrice{vehiclePrice}, _lType{lType}, _seatCount{seatCount}
{}
