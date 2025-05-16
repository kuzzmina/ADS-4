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
            if (arr[left] == arr[right]) {
                int n = right - left + 1;
                count += n * (n - 1) / 2;
                break;
            } else {
                int l_val = arr[left], r_val = arr[right];
                int l_count = 0, r_count = 0;
                while (left <= right && arr[left] == l_val) {
                    ++l_count;
                    ++left;
                }
                while (right >= left && arr[right] == r_val) {
                    ++r_count;
                    --right;
                }
                count += l_count * r_count;
            }
        } else if (sum < value) {
            ++left;
        } else {
            --right;
        }
    }
    return count;
}

int binarySearchCount(int *arr, int left, int right, int target) {
    int first = -1, last = -1;
    int l = left, r = right;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (arr[mid] < target) {
            l = mid + 1;
        } else {
            if (arr[mid] == target) first = mid;
            r = mid - 1;
        }
    }
    l = left, r = right;
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

int countPairs3(int *arr, int len, int value) {
    int count = 0;
    int i = 0;
    while (i < len - 1) {
        int current = arr[i];
        int complement = value - current;

        int numCurrent = 1;
        while (i + numCurrent < len && arr[i + numCurrent] == current) {
            ++numCurrent;
        }

        int complementCount = binarySearchCount(arr, i + numCurrent, len - 1, complement);
        count += numCurrent * complementCount;

        i += numCurrent;
    }
    return count;
}
