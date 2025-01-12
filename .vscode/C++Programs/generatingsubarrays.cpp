#include <iostream>
#include <vector>

std::vector<std::vector<int>> generateSubarrays(const std::vector<int>& arr) {
    int n = arr.size();
    std::vector<std::vector<int>> subarrays;
    for (int i = 0; i < n; ++i) {
        std::vector<int> subarray;
        for (int j = i; j < n; ++j) {
            subarray.push_back(arr[j]);
            subarrays.push_back(subarray);
        }
    }
    return subarrays;
}

int main() {
    std::vector<int> arr = {0, 1, 3, 4, 5, 2, 2, 4};
    std::vector<std::vector<int>> subarrays = generateSubarrays(arr);

    for (const auto& subarray : subarrays) {
        for (int num : subarray) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
