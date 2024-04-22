#include "Functionalities.h"
#include <optional>
#include <future>

void createsObjects(Container &data)
{
    data.push(std::make_shared<Car>("A1", CarType::SEDAN, 100000.0f, 3.0f, 6));
    data.push(std::make_shared<Car>("B2", CarType::HATCHBACK, 15000.0f, 4.0f, 4));
    data.push(std::make_shared<Car>("C3", CarType::SUV, 50000.0f, 5.0f, 5));
}

void display(Container &data, int n)
{
    if(data.empty()){
        throw EmptyContainerException("Data Not Found!");
    }
    std::stack<Pointer> ans;
    while(!data.empty()){
        if(n==0){
            return;
        }
        ans.push(data.top());
        std::cout<<*(data.top())<<std::endl;
        data.pop();
        n--;
    }
    createsObjects(data);
}

void highestPriorityPrice(Container &data)
{
    if(data.empty()){
        throw EmptyContainerException("Data Not Found!");
    }
    int max=data.top()->price();
    std::cout<<"Maximum Price is: "<<max<<std::endl;
}

void highestPrioritySeatCount(Container &data)
{
    if(data.empty()){
        throw EmptyContainerException("Data Not Found!");
    }
    int max=data.top()->carSeatCount();
    std::cout<<"Maximum Price is: "<<max<<std::endl;
}

void calculateRoadTax(Container &data)
{
    if(data.empty()){
        throw EmptyContainerException("Data Not Found!");
    }
    int tax=0;
    if(data.top()->cType()==CarType::SEDAN){
        tax=((data.top()->price())*14)/100;
    }
    else{
        tax=((data.top()->price())*10)/100;
    }
    std::cout<<"Road Tax is: "<<tax<<std::endl;
}
