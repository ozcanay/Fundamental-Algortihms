#include <iostream>
#include <vector>
#include <limits>

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
    /// CHANGE THIS. UGLY. NO NEED FOR VECTORS BELOW AS WELL. USE INDICES INSTEAD OF ITERATORS.
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

void bubbleSort(std::vector<int>& nums)
{
    for(int i = 0; i < nums.size(); ++i) {
        for(int j = i; j < nums.size(); ++j) {
            if(nums[i] > nums[j]) {
                std::swap(nums[i], nums[j]);
            }
        }
    }
}

void selectionSort(std::vector<int>& nums)
{
  for(int i = 0; i < nums.size(); ++i) {
        int smallest_index = i;
        for(int j = i; j < nums.size(); ++j) {
            if(nums[j] < nums[smallest_index]) {
                smallest_index = j;
            }
        }

        std::swap(nums[i], nums[smallest_index]);
    }
}

void insertionSort(std::vector<int>& nums)
{
    for(int i = 0; i < nums.size(); ++i) {
        for(int j = i; j > 0; --j) {
            /// This comparison is critical. You do not need i index here. You can simply use j to look backwards. Using index i here
            /// makes the code much more complicated.
            if(nums[j] < nums[j - 1]) {
                std::swap(nums[j], nums[j - 1]);
            } else break;
        }
    }
}

int main()
{
    std::vector<int> nums{1,2,3,5,6};

    std::cout << std::boolalpha;
    for(auto num : nums) {
        std::cout << binarySearchRecursive(nums, num) << std::endl;
    }

    std::cout << "Absents: " << std::endl;
    std::cout << binarySearchRecursive(nums, -2) << std::endl;
    std::cout << binarySearchRecursive(nums, -1) << std::endl;
    std::cout << binarySearchRecursive(nums, 0) << std::endl;
    std::cout << binarySearchRecursive(nums, 4) << std::endl;
    std::cout << binarySearchRecursive(nums, 7) << std::endl;
    std::cout << binarySearchRecursive(nums, 8) << std::endl;

    std::vector<int> m{2,0,5,1,8,3,-2,1};
    insertionSort(m);
    for(auto num : m) {
        std::cout << num << std::endl;
    }
}

