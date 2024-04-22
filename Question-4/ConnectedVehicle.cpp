#include "ConnectedVehicle.h"

std::ostream &operator<<(std::ostream &os, const ConnectedVehicle &rhs) {
    os << "_vehicleId: " << rhs._vehicleId
       << " _vehicleFullModel: " << rhs._vehicleFullModel
       << " _engine: " << rhs._engine;
    return os;
}

ConnectedVehicle::ConnectedVehicle(std::string vehicleId, std::string vehicleFullModel, VehicleSoftwareType sType, VehicleNormCategory nType, EnginePointer engine, VehicleFeautures fType)
: _vehicleId{vehicleId}, _vehicleFullModel{vehicleFullModel}, _sType{sType}, _nType{nType}, _engine{engine}, _fType{fType}
{}
