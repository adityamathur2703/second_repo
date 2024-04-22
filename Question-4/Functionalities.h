#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include "ConnectedVehicle.h"
#include "EmptyContainerException.h"
#include "IdNotFoundException.h"
#include <unordered_map>
#include <vector>
#include <numeric>
#include <algorithm>

using ConnectedPointer = std::shared_ptr<ConnectedVehicle>;
using Container = std::unordered_map<std::string, ConnectedPointer>;

void createMapObjects(Container& data);

void countEngineIC(Container& data);

void sameVehicleId(Container& data, std::string id);

std::vector<ConnectedPointer> sameSoftwareType(Container& data);

void hasEvEngineType(Container& data);

void averageEngineTorque(Container& data);

#endif // FUNCTIONALITIES_H
