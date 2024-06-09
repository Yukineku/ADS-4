// Copyright 2021 NNTU-CS
#include <alg.h>
#include <iostream>
#include <cstdint>

int countPairs1(int* arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < (len - 1); i++) {
        for (int j = i + 1; j < len; j++) {
            if ((arr[i] + arr[j]) == value) {
                count++;
            }
        }
    }
    if (count > (0)) {
        return count;
    }
    return 0;
}

int countPairs2(int* arr, int len, int value) {
    int count = 0, x = 0, j = 0;
    for (int i = 0; i < (len - 1); i++) {
        if ((arr[i] + arr[i + 1]) >= value) {
            x = i;
            break;
        }
    }
    for (int i = 0; i < (len - 1); i++) {
        if (arr[i] > value) {
            break;
        }
        if (x <= i) {
            j = i + 1;
        } else {
            j = x;
        }
        for (; j < len; j++) {
            if ((arr[i] + arr[j]) == value) {
                count++;
            }
            if (arr[j] > value) {
                break;
            }
        }
    }
    return count;
}
int countPairs3(int *arr, int len, int value) {
  int count = 0;
  int right, first, second, left;
  for (int i = 0; i < len; ++i) {
    right = len - 1;
    left = i + 1;
    second = value - arr[i];
    while (left <= right) {
      first = (left + right) / 2;
      if (arr[first] == second) {
        count++;
        int next = first - 1;
        while ((next > i) && (arr[next] == arr[first])) {
          count++;
          next--;
        }
        int next2 = first + 1;
        while ((i < next2) && (arr[next2] == arr[first])) {
          count++;
          next2++;
        }
        break;
      } else if (arr[first] > second) {
        right = first - 1;
      } else {
        left = first + 1;
      }
    }
  }
  return count;
