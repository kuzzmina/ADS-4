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
            int l = arr[left];
            int r = arr[right];
            int lcount = 0;
            int rcount = 0;
            while (left <= right && arr[left] == l) {
                ++lcount;
                ++left;
            }
            while (right >= left && arr[right] == r) {
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

int binarySearchCount(int* arr, int left, int right, int target) {
    int first = -1;
    int last = -1;
    int l = left;
    int r = right;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (arr[mid] < target) {
            l = mid + 1;
        } else {
            if (arr[mid] == target) first = mid;
            r = mid - 1;
        }
    }
    l = left;
    r = right;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (arr[mid] > target) {
            r = mid - 1;
        } else {
            if (arr[mid] == target) last = mid;
            l = mid + 1;
        }
    }
    if (first == -1 || last == -1) return 0;
    return last - first + 1;
}

int countPairs3(int* arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len - 1; ++i) {
        int complement = value - arr[i];
        int cnt = binarySearchCount(arr,
                                   i + 1,
                                   len - 1,
                                   complement);
        count += cnt;
    }
    return count;
}
