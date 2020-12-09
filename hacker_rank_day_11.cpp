#include <bits/stdc++.h>

using namespace std;

constexpr int MAX{2};
void max_sum_of_hour_glass(vector<vector<int>> arr)
{
    int max_sum = -32768;
    int temp = 0;
    for(int row = 0; row < arr.size()-MAX; row++)
    {
        for(int col = 0; col < arr[row].size()-MAX; col++)
        {
                  //upper row of glass hour
            temp = arr[row][col] + arr[row][col+1] + arr [row][col+2]
                                + arr[row+1][col+1] //middle row of glass hour
                   + arr[row+2][col] +  arr[row+2][col+1] + arr[row+2][col+2]; // lower row of glasshour

            if(temp > max_sum)
                max_sum = temp; 
        }
    }
    std::cout<< max_sum;
}

int main()
{
    vector<vector<int>> arr(6);
    for (int i = 0; i < 6; i++) {
        arr[i].resize(6);

        for (int j = 0; j < 6; j++) {
            cin >> arr[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    max_sum_of_hour_glass(arr);
    return 0;
}
