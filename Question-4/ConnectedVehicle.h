#ifndef CONNECTEDVEHICLE_H
#define CONNECTEDVEHICLE_H

#include <iostream>
#include "VehicleNormCategory.h"
#include "VehicleSoftwareType.h"
#include "VehicleFeatures.h"
#include "Engine.h"
#include <memory>

using EnginePointer = std::shared_ptr<Engine>;

class ConnectedVehicle
{
private:
    std::string _vehicleId{""};
    std::string _vehicleFullModel{""};
    VehicleSoftwareType _sType{VehicleSoftwareType::CLASSIC_AUTOSAR};
    VehicleNormCategory _nType{VehicleNormCategory::EU};
    EnginePointer _engine{nullptr};
    VehicleFeautures _fType{VehicleFeautures::Good};

public:
    ConnectedVehicle()=default;          // Default constructor enabled 
    
    ConnectedVehicle(const ConnectedVehicle&)=delete;              // Copy constructor disabled
    
    ConnectedVehicle(ConnectedVehicle&&)=delete;                   // Move Constructor disabled
    
    ConnectedVehicle& operator=(const ConnectedVehicle&)=delete;      // Copy Assignment Operator diabled
    
    ConnectedVehicle& operator=(ConnectedVehicle&&)=delete;       // Move Assignment Operator disabled
    
    ~ConnectedVehicle()=default;                      // Default destructor enabled

    ConnectedVehicle(std::string vehicleId, std::string vehicleFullModel, VehicleSoftwareType sType, VehicleNormCategory nType, EnginePointer engine, VehicleFeautures fType);

    std::string vehicleId() const { return _vehicleId; }
    void setVehicleId(const std::string &vehicleId) { _vehicleId = vehicleId; }

    std::string vehicleFullModel() const { return _vehicleFullModel; }
    void setVehicleFullModel(const std::string &vehicleFullModel) { _vehicleFullModel = vehicleFullModel; }

    VehicleSoftwareType sType() const { return _sType; }
    void setSType(const VehicleSoftwareType &sType) { _sType = sType; }

    VehicleNormCategory nType() const { return _nType; }
    void setNType(const VehicleNormCategory &nType) { _nType = nType; }

    EnginePointer engine() const { return _engine; }
    void setEngine(const EnginePointer &engine) { _engine = engine; }

    VehicleFeautures fType() const { return _fType; }
    void setFType(const VehicleFeautures &fType) { _fType = fType; }

    friend std::ostream &operator<<(std::ostream &os, const ConnectedVehicle &rhs);
};

#endif // CONNECTEDVEHICLE_H
