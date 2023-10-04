#include <iostream>
#include <vector>

int findMissing(const std::vector<int>& nums) {
    int n = nums.size();
    int total = (n + 1) * (n + 2) / 2;  

    for (int num : nums) {
        total -= num;
    }

    return total;
}

int main() {
    std::vector<int> nums = {1, 2, 4, 6, 3, 7, 8};
    std::cout << "The missing number is: " << findMissing(nums) << std::endl;

    return 0;
}
