// Copyright 2021 NNTU-CS
#include <iostream>

int countPairs1(int* arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len; ++i) {
        for (int j = i + 1; j < len; ++j) {
            int sum = arr[i] + arr[j];
            if (sum == value) ++count;
            else if (sum > value) break;
        }
    }
    return count;
}

int countPairs2(int* arr, int len, int value) {
    int count = 0;
    int left = 0;
    int right = len - 1;
    while (left < right) {
        int sum = arr[left] + arr[right];
        if (sum == value) {
            if (arr[left] == arr[right]) {
                int n = right - left + 1;
                count += n * (n - 1) / 2;
                break;
            }
            int lval = arr[left];
            int rval = arr[right];
            int lcount = 0;
            int rcount = 0;
            while (left <= right && arr[left] == lval) {
                ++lcount;
                ++left;
            }
            while (right >= left && arr[right] == rval) {
                ++rcount;
                --right;
            }
            count += lcount * rcount;
        } else if (sum < value) {
            ++left;
        } else {
            --right;
        }
    }
    return count;
}

int binarySearch(int* arr, int left, int right, int target) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

int countPairs3(int* arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len - 1; ++i) {
        int complement = value - arr[i];
        int pos = binarySearch(arr, i + 1, len - 1, complement);
        if (pos == -1) continue;
        int left = pos;
        int right = pos;
        while (left > i && arr[left - 1] == complement) --left;
        while (right + 1 < len && arr[right + 1] == complement) ++right;
        count += (right - left + 1);
    }
    return count;
}

