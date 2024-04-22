#ifndef PRIVATEVEHICLE_H
#define PRIVATEVEHICLE_H

#include <iostream>
#include "LicenseCategory.h"

class PrivateVehicle
{
private:
    std::string _vehicleRegistrationNumber{""};
    std::string _vehicleBrand{""};
    float _vehiclePrice{0.0f};
    LicenseCategory _lType{LicenseCategory::LEARNING};
    unsigned int _seatCount{0};

public:
    PrivateVehicle()=default;          // Default constructor enabled 
    
    PrivateVehicle(const PrivateVehicle&)=delete;              // Copy constructor disabled
    
    PrivateVehicle(PrivateVehicle&&)=delete;                   // Move Constructor disabled
    
    PrivateVehicle& operator=(const PrivateVehicle&)=delete;      // Copy Assignment Operator diabled
    
    PrivateVehicle& operator=(PrivateVehicle&&)=delete;       // Move Assignment Operator disabled
    
    ~PrivateVehicle()=default;                      // Default destructor enabled

    PrivateVehicle(std::string vehicleRegistrationNumber, std::string vehicleBrand, float vehiclePrice, LicenseCategory lType, unsigned int seatCount);

    std::string vehicleRegistrationNumber() const { return _vehicleRegistrationNumber; }
    void setVehicleRegistrationNumber(const std::string &vehicleRegistrationNumber) { _vehicleRegistrationNumber = vehicleRegistrationNumber; }

    std::string vehicleBrand() const { return _vehicleBrand; }
    void setVehicleBrand(const std::string &vehicleBrand) { _vehicleBrand = vehicleBrand; }

    float vehiclePrice() const { return _vehiclePrice; }
    void setVehiclePrice(float vehiclePrice) { _vehiclePrice = vehiclePrice; }

    LicenseCategory lType() const { return _lType; }
    void setLType(const LicenseCategory &lType) { _lType = lType; }

    unsigned int seatCount() const { return _seatCount; }
    void setSeatCount(unsigned int seatCount) { _seatCount = seatCount; }

    friend std::ostream &operator<<(std::ostream &os, const PrivateVehicle &rhs);
};

#endif // PRIVATEVEHICLE_H
