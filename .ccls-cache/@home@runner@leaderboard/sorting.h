#ifndef SORTING_H
#define SORTING_H

#include <string>

using namespace std;

void insertionSort(string &unsortedString) {
  char key;
  int j;
  for (int i = 1; i < unsortedString.length(); i++) {
    key = unsortedString[i];
    if (key == '\0') {
      break;
    }
    j = i - 1;
    while (j >= 0 && unsortedString[j] > key) {
      unsortedString[j + 1] = unsortedString[j];
      j = j - 1;
    }
    unsortedString[j + 1] = key;
  }
}

void bubbleSort(string &unsortedString) {
  bool swapped;
  for (int i = 0; i < unsortedString.length(); i++) {
    swapped = false;
    for (int j = 0; j < unsortedString.length() - 1; j++) {
      if (unsortedString[j + 1] == '\0') {
        break;
      }
      if (unsortedString[j] > unsortedString[j + 1]) {
        swap(unsortedString[j], unsortedString[j + 1]);
        swapped = true;
      }
    }
    if (!swapped) {
      break;
    }
  }
}

int partition(string &unsortedString, int low, int high) {
  char pivot = unsortedString[high];
  int i = low - 1;
  for (int j = low; j <= high; j++) {
    if (unsortedString[j] < pivot) {
      i++;
      swap(unsortedString[i], unsortedString[j]);
    }
  }
  swap(unsortedString[i + 1], unsortedString[high]);
  return i + 1;
}

void quickSort(&unsortedString, int low, int high) {
  if (low < high) {
    int pivot = partition(unsortedString, low, high);
    quickSort(unsortedString, low, pivot - 1);
    quickSort(unsortedString, pivot + 1, high);
  }
}

#endif