#include <iostream>
#include <vector>

int binary_search_template_1(const std::vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1;
}

int main() {
    // Example sorted array
    std::vector<int> sorted_array = {1, 3, 5, 7, 9, 11, 13, 15, 17};

    // Target element to search for
    int target_element = 11;

    // Perform binary search using the template function
    int result_index = binary_search_template_1(sorted_array, target_element);

    if (result_index != -1) {
        std::cout << "Element " << target_element << " found at index " << result_index << std::endl;
    } else {
        std::cout << "Element " << target_element << " not found in the array" << std::endl;
    }

    return 0;
}
