#include "PrivateVehicle.h"
#include "TransportVehicle.h"

#include <memory>
#include <variant>
#include <future>
#include <vector>

using PrivateVehiclePointer = std::shared_ptr<PrivateVehicle>;
using TransportVehiclePointer = std::shared_ptr<TransportVehicle>;

using Combined = std::variant<PrivateVehiclePointer, TransportVehiclePointer>;

using Container= std::vector<Combined>;

void createObjects(Container& data);

std::vector<TransportLicenseCategory> CategoryOfLicense(Container& data);

void averageVehiclePrice(Container& data);

void VehiclePrices(Container& data, std::future<int>& ft);

bool checkType(Container& data);