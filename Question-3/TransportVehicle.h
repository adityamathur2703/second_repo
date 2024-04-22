#ifndef TRANSPORTVEHICLE_H
#define TRANSPORTVEHICLE_H

#include <iostream>
#include "TransportLicenseCategory.h"

class TransportVehicle
{
private:
    std::string _vehicleRegistrationNumber{""};
    std::string _vehicleBrand{""};
    float _vehiclePrice{0.0f};
    TransportLicenseCategory _lType{TransportLicenseCategory::HMV};
    float _loadCarryingCapacity{0.0f};
    
public:
    TransportVehicle()=default;          // Default constructor enabled 
    
    TransportVehicle(const TransportVehicle&)=delete;              // Copy constructor disabled
    
    TransportVehicle(TransportVehicle&&)=delete;                   // Move Constructor disabled
    
    TransportVehicle& operator=(const TransportVehicle&)=delete;      // Copy Assignment Operator diabled
    
    TransportVehicle& operator=(TransportVehicle&&)=delete;       // Move Assignment Operator disabled
    
    ~TransportVehicle()=default;                      // Default destructor enabled

    TransportVehicle(std::string vehicleRegistrationNumber, std::string vehicleBrand, float vehiclePrice, TransportLicenseCategory lType, float loadCarryingCapacity);

    std::string vehicleRegistrationNumber() const { return _vehicleRegistrationNumber; }
    void setVehicleRegistrationNumber(const std::string &vehicleRegistrationNumber) { _vehicleRegistrationNumber = vehicleRegistrationNumber; }

    std::string vehicleBrand() const { return _vehicleBrand; }
    void setVehicleBrand(const std::string &vehicleBrand) { _vehicleBrand = vehicleBrand; }

    float vehiclePrice() const { return _vehiclePrice; }
    void setVehiclePrice(float vehiclePrice) { _vehiclePrice = vehiclePrice; }

    TransportLicenseCategory lType() const { return _lType; }
    void setLType(const TransportLicenseCategory &lType) { _lType = lType; }

    float loadCarryingCapacity() const { return _loadCarryingCapacity; }
    void setLoadCarryingCapacity(float loadCarryingCapacity) { _loadCarryingCapacity = loadCarryingCapacity; }

    friend std::ostream &operator<<(std::ostream &os, const TransportVehicle &rhs);
};

#endif // TRANSPORTVEHICLE_H
