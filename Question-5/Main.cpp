#include "Functionalities.h"

int main(){
    Container data;
    createsObjects(data);

    display(data, 2);                          // Display N instances
    highestPriorityPrice(data);                // Price of highest Priority
    highestPrioritySeatCount(data);            // Count of highest Priority
    calculateRoadTax(data);                    // Road Tax of highest Priority
}