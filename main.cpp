#include <iostream>
#include <vector>

/// Iterative approach
bool binarySearch(const std::vector<int>& nums, int val)
{
    int lo = 0;
    int hi = nums.size() - 1;

    while(lo <= hi) {
        int mid = lo + (hi - lo)/2;

        if(val < nums[mid]) {
            hi = mid - 1;
        } else if(val > nums[mid]) {
            lo = mid + 1;
        } else {
            return true;
        }
    }

    return false;
}

int main()
{
    std::vector<int>m{1,2,3,4,5,6};
    std::cout << std::boolalpha << binarySearch(m, 4) << std::endl;
}
