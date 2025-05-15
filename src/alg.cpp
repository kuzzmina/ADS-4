// Copyright 2021 NNTU-CS
#include <iostream>
#include <unordered_set>

int countPairs1(int *arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len; ++i) {
        for (int j = i + 1; j < len; ++j) {
            if (arr[i] + arr[j] == value) count++;
        }
    }
    return count;
}

int countPairs2(int *arr, int len, int value) {
    int count = 0;
    int left = 0, right = len - 1;
    while (left < right) {
        int sum = arr[left] + arr[right];
        if (sum == value) {
            count++;
            left++;
            right--;
        } else if (sum < value) left++;
        else right--;
    }
    return count;
}

int countPairs3(int *arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len - 1; ++i) {
        int target = value - arr[i];
        int left = i + 1, right = len - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] == target) {
                count++;
                break;
            } else if (arr[mid] < target) left = mid + 1;
            else right = mid - 1;
        }
    }
    return count;
}

int main() {
    int arr[] = {20, 30, 30, 40, 40};
    int len = sizeof(arr) / sizeof(arr[0]);
    int value = 50;
    std::cout << "Count of pairs (method 1): " 
              << countPairs1(arr, len, value) << std::endl;
    std::cout << "Count of pairs (method 2): " 
              << countPairs2(arr, len, value) << std::endl;
    std::cout << "Count of pairs (method 3): " 
              << countPairs3(arr, len, value) << std::endl;
    return 0;
}

