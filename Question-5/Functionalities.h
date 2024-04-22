#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include "Car.h"
#include <memory>
#include <vector>
#include <stack>
#include <queue>
#include "EmptyContainerException.h"

using Pointer = std::shared_ptr<Car>;

auto comp = [](const Pointer &p1, const Pointer &p2)            // Comparison Operator
{
    return p1->price() < p2->price();
};

// using PriceContainer = std::vector<int>;
// using CarContainer = std::vector<Pointer>;

using Container = std::priority_queue<Pointer>;      // Priority Queue Container

void createsObjects(Container& data);

void display(Container& data, int n);

void highestPriorityPrice(Container& data);

void highestPrioritySeatCount(Container& data);

void calculateRoadTax(Container& data);

#endif // FUNCTIONALITIES_H
