#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include "TransportVehicle.h"
#include "EmptyContainerException.h"
#include <vector>
#include <numeric>
#include <functional>
#include <optional>
#include <algorithm>

using TransportPointer = std::shared_ptr<TransportVehicle>;
using Container = std::vector<TransportPointer>;

void createObjects(Container& data);

void averageSeatCount(Container &data, VehicleType vt);

void sameVehicleType(Container& data);

void findPermitNumber(Container& data, int n);

#endif // FUNCTIONALITIES_H
