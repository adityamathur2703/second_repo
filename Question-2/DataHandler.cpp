#include "DataHandler.h"
#include <mutex>
#include <numeric>
#include <vector>
#include <algorithm>

std::mutex mt;

Pointer DataHandler::_solo_hero_obj{nullptr};

void DataHandler::TakeInput(std::array<int, 5>& data)
{
    std::lock_guard<std::mutex> lg(mt);
    for(int i=0; i<5; i++){
        int n;
        std::cout<<i+1<<" Integer: ";
        std::cin>>n;
        if(n>=1 && n<=10){
            data[i]=n;
        }
        else{
            std::cout<<"Sorry! out of Range, TYPE AGAIN"<<std::endl;
            i--;
        }
    }
    std::cout<<std::endl;
    setData(data);
}

void DataHandler::AverageValue()
{
    std::lock_guard<std::mutex> lg(mt);
    std::vector<int> temp{2,3,5,7,11};
    int i=-1;
    int sum=std::accumulate(
        temp.begin(),
        temp.end(),
        0,
        [&](int answer_upto_now, int n){
            i++;
            return answer_upto_now+temp[i];
        }
    );
    std::cout<<"The Average of first Prime Number is: "<<(float)sum/temp.size()<<std::endl;
}

void DataHandler::ComputSquare()
{
    std::lock_guard<std::mutex> lg(mt);
    std::array<int, 5> temp;
    int last=1;
    for(int i=0; i<5; i++){
        bool check=true;
        while(check){
            if(last%2!=0 && last%3==0){
                temp[i]=last*last;
                check=false;
            }
            last+=2;
        }
    }
    std::cout<<"Squares are: ";
    for(int i:temp){
        std::cout<<i<<"  ";
    }
    std::cout<<std::endl;
    setSquareResults(temp);
}

int factorial(int n){
    int ans=1;
    for(int i=1; i<=n; i++){
        ans*=i;
    }
    return ans;
}

void DataHandler::ComputeFactorial()
{
    if(data().empty()){
        throw EmptyContainerException("Data Not Found");
    }
    std::lock_guard<std::mutex> lg(mt);
    std::array<int, 5> temp;
    for(int i=0; i<5; i++){
        int f=data()[i];
        temp[i]=factorial(f);
    }
    std::cout<<"Factorials are: ";
    for(int i:temp){
        std::cout<<i<<"  ";
    }
    std::cout<<std::endl;
}
