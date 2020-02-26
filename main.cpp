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

/// Helper for recursive approach
bool binarySearchRecursiveHelper(const std::vector<int>& nums, int val, int lo, int hi)
{
    if(lo > hi) return false;

    /// Some offseting needed since we split the vector in each successive recursive call.s
    hi = hi - lo;
    lo = 0;
    int mid = lo + (hi - lo)/2;
    mid = mid - lo;

    if(val < nums[mid]) {
        std::vector<int> vec(nums.begin(), nums.begin() + mid);
        return binarySearchRecursiveHelper(vec, val, lo, mid - 1);
    } else if(val > nums[mid]) {
        std::vector<int> vec(nums.begin() + mid + 1, nums.end());
        return binarySearchRecursiveHelper(vec, val, mid + 1, hi);
    } else {
        return true;
    }

    return false;
}

/// Recursive approach
bool binarySearchRecursive(const std::vector<int>& nums, int val)
{
    int lo = 0;
    int hi = nums.size() - 1;

    return binarySearchRecursiveHelper(nums, val, lo, hi);
}



int main()
{
    std::vector<int> nums{1,2,3,5,6};

    for(auto num : nums) {
        std::cout << std::boolalpha << binarySearchRecursive(nums, num) << std::endl;
    }

    std::cout << "Not absents: " << std::endl;
    std::cout << std::boolalpha << binarySearchRecursive(nums, -2) << std::endl;
    std::cout << std::boolalpha << binarySearchRecursive(nums, -1) << std::endl;
    std::cout << std::boolalpha << binarySearchRecursive(nums, 0) << std::endl;
    std::cout << std::boolalpha << binarySearchRecursive(nums, 4) << std::endl;
    std::cout << std::boolalpha << binarySearchRecursive(nums, 7) << std::endl;
    std::cout << std::boolalpha << binarySearchRecursive(nums, 8) << std::endl;
}

