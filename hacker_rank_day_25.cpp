#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int no_of_testcases{};
    cin>>no_of_testcases;
    
    for(auto counter = 0; counter<no_of_testcases; counter++)
    {   
        bool flag{true};
        long int input_number{};
        cin>>input_number;
        if(input_number==1)
        {
            cout<<"Not prime\n";
            continue;
        }
        for(long int counter1 = 2; counter1 <= sqrt(input_number); counter1++)
        {
            if(input_number%counter1 == 0)
            {
                flag = false;
                break;
            }
        }
        if(flag == true)
            cout<<"Prime\n";
        else
            cout<<"Not prime\n";
    }
    return 0;
}
