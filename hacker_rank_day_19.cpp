#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
class AdvancedArithmetic{
    public:
        virtual int divisorSum(int n)=0;
};
class Calculator : public AdvancedArithmetic {
public:
    int divisorSum(int n) {
        if(n==1)
            return 1;
        vector<int> divisors{1,n};
        
        int max_sum{};
        for(int counter=2; counter<=n/2;counter++)
        {
            if(n%counter==0)
                divisors.push_back(counter);
        }

        for(const auto& itr:divisors)
            max_sum = max_sum + itr;
        
        return max_sum;
    }
};

int main(){
    int n;
    cin >> n;
    AdvancedArithmetic *myCalculator = new Calculator(); 
    int sum = myCalculator->divisorSum(n);
    cout << "I implemented: AdvancedArithmetic\n" << sum;
    return 0;
}