#include<iostream>
#include<vector>
void swap(long& a, long& b)
{
    long temp = a;
    a = b;
    b = temp;
}
int main()
{
    int n{};
    std::cin>>n;
    std::vector<long>a{};
    int data{};
    for(int counter=0; counter<n; counter++)
    {
        std::cin >> data;
        a.push_back(data);
    }

    // Track number of elements swapped during a single array traversal
    int numberOfSwaps = 0;
    
    for (int i = 0; i < n; i++) 
    {
    
        for (int j = 0; j < n - 1; j++) {
            // Swap adjacent elements if they are in decreasing order
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
                numberOfSwaps++;
            }
        }
    
        // If no elements were swapped during a traversal, array is sorted
        if (numberOfSwaps == 0) {
            break;
        }
    }
    std::cout<<"Array is sorted in "<<numberOfSwaps <<"swaps.\n";
    std::cout<<"First Element: "<<a[0] <<std::endl;
    std::cout<<"Last Element: "<<a[n-1] <<std::endl;
    return 0;
}

