// Copyright 2021 NNTU-CS
#include <iostream>

int countPairs1(int *arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len; ++i) {
        for (int j = i + 1; j < len; ++j) {
            if (arr[i] + arr[j] == value) ++count;
            else if (arr[i] + arr[j] > value) break;
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
            int l_val = arr[left], r_val = arr[right];
            int l_count = 1, r_count = 1;
            ++left;
            --right;
            while (left < right && arr[left] == l_val) {
                ++l_count;
                ++left;
            }
            while (left <= right && arr[right] == r_val) {
                ++r_count;
                --right;
            }
            count += l_count * r_count;
        } else if (sum < value) {
            ++left;
        } else {
            --right;
        }
    }
    return count;
}

int binarySearch(int *arr, int left, int right, int target) {
    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] == target) {
            int count = 1;
            int idx = mid;
            while (--idx >= left && arr[idx] == target) ++count;
            idx = mid;
            while (++idx <= right && arr[idx] == target) ++count;
            return count;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return 0;
}

int countPairs3(int *arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len; ++i) {
        int complement = value - arr[i];
        count += binarySearch(arr, i + 1, len - 1, complement);
    }
    return count;
}
