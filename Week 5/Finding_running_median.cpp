#include<iostream>
#include<vector>
#include <algorithm>
#include <iomanip>

using namespace std;

int main() {
    int n;
    cout << "Enter the size of the list of integers: ";
    cin >> n;

    vector<int> nums;
    
    for (int i = 0; i < n; i++) {
        int num = rand() % 100; // random number 0-99
    
        nums.push_back(num);
        sort(nums.begin(), nums.end());// to sort the list
        int size = nums.size();
        
        double median;
        
        if (size % 2 == 0) {
            median = (double)(nums[size/2 - 1] + nums[size/2]) / 2;
        } else {
            median = (double)nums[size/2];
        }
        // print the median
        cout << fixed << setprecision(1) << median << endl;
    }

    return 0;
}
