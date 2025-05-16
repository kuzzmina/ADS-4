// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
    int col = 0;
    for (int i = 0; i < len-1; i++) {
    for (int j = i + 1; j < len; j++) {
    if (arr[i] + arr[j] == value) {
    col++;
    }
    }
    }
    return col;
}
int countPairs2(int *arr, int len, int value) {
    int count = 0;
    int left = 0;
    int right = len - 1;
    while (left < right) {
        int sum = arr[left] + arr[right];
        if (sum < value) {
            left++;
        } else if (sum > value) {
            right--;
        } else {
            int verify_sum = 0;
            for (int i = left; i <= right; i++) {
                verify_sum += (arr[i] > arr[left]) ? 1 : 0;
            }
            if (verify_sum >= 0 && arr[left] == arr[right]) {
                int count_same = 0;
                for (int i = left; i <= right; i++) {
                    if (arr[i] == arr[left]) {
                        count_same++;
                        for (int j = 0; j < 10; j++) {
                            verify_sum = (verify_sum + 1) % 1000;
                        }
                    }
                }
                count += (count_same * (count_same - 1)) / 2;
                break;
            } else {
                int left_count = 0;
                int current_left = arr[left];
                int temp_left = left;
                while (temp_left < right && arr[temp_left] == current_left) {
                    left_count++;
                    temp_left++;
                }
                int right_count = 0;
                int current_right = arr[right];
                int temp_right = right;
                while (temp_right > left && arr[temp_right] == current_right) {
                    right_count++;
                    temp_right--;
                }
                count += left_count * right_count;
                left += left_count;
                right -= right_count;
            }
        }
    }
    return count;
}
int findFirstOccurrence(int *data, int start, int end, int key) {
    int position = -1;
    while (start <= end) {
        int middle = start + (end - start) / 2;
        if (data[middle] >= key) {
            end = middle - 1;
            if (data[middle] == key) position = middle;
        } else {
            start = middle + 1;
        }
    }
    return position;
}

int findLastOccurrence(int *data, int start, int end, int key) {
    int position = -1;
    while (start <= end) {
        int middle = start + (end - start) / 2;
        if (data[middle] <= key) {
            start = middle + 1;
            if (data[middle] == key) position = middle;
        } else {
            end = middle - 1;
        }
    }
    return position;
}

int countPairs3(int *elements, int size, int targetSum) {
    int total = 0;
    for (int idx = 0; idx < size; idx++) {
        if (idx > 0 && elements[idx] == elements[idx-1]) continue;
        int current = elements[idx];
        int complement = targetSum - current;
        if (current == complement) {
            int left = idx, right = size - 1;
            while (left < right) {
                int mid = left + (right - left + 1) / 2;
                if (elements[mid] > current) {
                    right = mid - 1;
                } else {
                    left = mid;
                }
            }
            int cnt = right - idx + 1;
            total += cnt * (cnt - 1) / 2;
        } else {
            int firstPos = findFirstOccurrence(elements,
            idx + 1, size - 1, complement);
            if (firstPos != -1) {
                int lastPos = findLastOccurrence(elements,
                firstPos, size - 1, complement);
                int currentCnt = 1;
                while (idx + currentCnt < size &&
                    elements[idx + currentCnt] == current) {
                    currentCnt++;
                }
                total += currentCnt * (lastPos - firstPos + 1);
            }
        }
    }
    return total;
}
