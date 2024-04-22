#ifndef TRANSPORTVEHICLE_H
#define TRANSPORTVEHICLE_H

#include "VehicleType.h"
#include "Permit.h"
#include <memory>
#include <ostream>

using Pointer = std::shared_ptr<Permit>;

class TransportVehicle
{
private:
    Pointer _permit{nullptr};
    VehicleType _vType{VehicleType::MINI_VAN};
    unsigned int _seatCount{0};
    unsigned int _stopsCount{0};

public:
    TransportVehicle()=default;          // Default constructor enabled 
    
    TransportVehicle(const TransportVehicle&)=delete;              // Copy constructor disabled
    
    TransportVehicle(TransportVehicle&&)=delete;                   // Move Constructor disabled
    
    TransportVehicle& operator=(const TransportVehicle&)=delete;      // Copy Assignment Operator diabled
    
    TransportVehicle& operator=(TransportVehicle&&)=delete;       // Move Assignment Operator disabled
    
    ~TransportVehicle()=default;                      // Default destructor enabled

    TransportVehicle(Pointer permit, VehicleType vType, unsigned int seatCount, unsigned int stopsCount);

    Pointer permit() const { return _permit; }
    void setPermit(const Pointer &permit) { _permit = permit; }

    VehicleType vType() const { return _vType; }
    void setVType(const VehicleType &vType) { _vType = vType; }

    unsigned int seatCount() const { return _seatCount; }
    void setSeatCount(unsigned int seatCount) { _seatCount = seatCount; }

    unsigned int stopsCount() const { return _stopsCount; }
    void setStopsCount(unsigned int stopsCount) { _stopsCount = stopsCount; }

    friend std::ostream &operator<<(std::ostream &os, const TransportVehicle &rhs);
};

#endif // TRANSPORTVEHICLE_H
