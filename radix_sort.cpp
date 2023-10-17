#include <iostream>
#include <vector>

// A utility function to find the maximum element in an array
int findMax(std::vector<int>& arr) {
    int max = arr[0];
    for (int num : arr) {
        if (num > max) {
            max = num;
        }
    }
    return max;
}

// A utility function to perform counting sort based on a specific digit's position (exp)
void countingSort(std::vector<int>& arr, int exp) {
    const int n = arr.size();
    std::vector<int> output(n, 0);
    std::vector<int> count(10, 0);

    // Count the occurrences of each digit at the current position
    for (int i = 0; i < n; i++) {
        count[(arr[i] / exp) % 10]++;
    }

    // Adjust the count array to store the position of digits in output
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    // Build the output array
    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // Copy the sorted elements back to the original array
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

// Radix Sort function
void radixSort(std::vector<int>& arr) {
    int max = findMax(arr);

    // Perform counting sort for every digit position
    for (int exp = 1; max / exp > 0; exp *= 10) {
        countingSort(arr, exp);
    }
}

int main() {
    std::vector<int> arr = {170, 45, 75, 90, 802, 24, 2, 66};
    
    std::cout << "Original array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    radixSort(arr);

    std::cout << "Sorted array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
