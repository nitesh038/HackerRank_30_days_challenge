#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Difference {
    private:
    vector<int> elements;
  
  	public:
  	int maximumDifference;
    Difference(vector<int> elements)
    {
        this->elements = elements;
    }
	// Add your code here
    void computeDifference()
    {
       int min = 100;
       int max = 1;

       for(int counter=0;counter<elements.size();counter++)
       {
           if(elements[counter] < min)
           {
               min = elements[counter];
           }
           if(elements[counter] > max)
           {
               max = elements[counter];
           }
       }
       maximumDifference = max-min;
    }

}; // End of Difference class