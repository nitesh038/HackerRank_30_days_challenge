#include <bits/stdc++.h>

#include<iostream>
#include<vector>

void get_consecutive_max_ones(std::vector<long double>remainder)
{
    int max_count{0};
    int count{0};
    for(const auto& it : remainder)
    {
        if(it)
        {
            count++;
            if(max_count < count)
                max_count++;
        }
        else
        {
            count = 0;
        }
                   
    }
    std::cout << max_count; 
}

void get_decimal_to_binary(long number)
{
    int base{2};
    std::vector<long double> remainder;
    long divisor{number};
    while(divisor!=0)
    {
        long temp_divisor = divisor/base;
        long temp_remainder = divisor%base;
        remainder.push_back(temp_remainder);
        divisor = temp_divisor;
    }
    std::cout << "remainder.size(): "<< remainder.size() << std::endl ;
    for(const auto& it : remainder)
    {   //Note the huge difference between next two lines
        std::cout<< "remainder[it]: " <<remainder[it] << std::endl;
        std::cout<< "it: " <<it<< std::endl;
    }
    /* for(int counter=0; counter< remainder.size() ; counter++)
    {
        std::cout<< remainder[counter];
    }  */
    get_consecutive_max_ones(remainder);
}
int main()
{
    long number{};
    std::cin>>number;
    std::cin.ignore();
    get_decimal_to_binary(number);
}