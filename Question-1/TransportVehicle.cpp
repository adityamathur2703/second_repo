#include "TransportVehicle.h"

std::ostream &operator<<(std::ostream &os, const TransportVehicle &rhs) {
    std::string type;
    if(rhs._vType==VehicleType::BUS){
        type="BUS";
    }
    else if(rhs._vType==VehicleType::CAB){
        type="CAB";
    }
    else{
        type="MINI VAN";
    }
    os << "_permit: " << rhs._permit
       << " vType: " << type
       << " _seatCount: " << rhs._seatCount
       << " _stopsCount: " << rhs._stopsCount;
    return os;
}

TransportVehicle::TransportVehicle(Pointer permit, VehicleType vType, unsigned int seatCount, unsigned int stopsCount)
:_permit{permit}, _vType{vType}, _seatCount{seatCount}, _stopsCount{stopsCount}
{}

