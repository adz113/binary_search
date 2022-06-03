// binarySearch.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void bubbleSort(int numbers[], int size) {
    int maxElement;
    int index;
    for (maxElement = size - 1; maxElement > 0; maxElement--) {
        for (index = 0; index < maxElement; index++) {
            if (numbers[index] > numbers[index + 1]) {
                swap(numbers[index], numbers[index + 1]);
            }
        }
    }
}

int binarySearch(int numbers[], int size, int value) {
    int first = 0;
    int last = size - 1;
    int middle;
    int position = -1;
    bool found = false;
    while (!found && first <= last) {
        middle = (first + last) / 2; 
        if (numbers[middle] == value) {
            found = true;
            position = middle;
        }
        else if (numbers[middle] > value) {
            last = middle - 1;
        }
        else {
            first = middle + 1;
        }
    }
    return position + 1;
}

int main()
{
    int size;
    cout << "Enter the amount of numbers you want to enter: ";
    cin >> size;
    vector<int>numbers;

    for (int i = 0; i <= size-1; i++) {
        int num;
        cout << "Enter " << i+1 << " Number: ";
        cin >> num;
        numbers.push_back(num);
    }

    bubbleSort(&(numbers[0]), size);
    cout << "\nSorted array: ";
    for (int i = 0; i < size-1; i++) {
        cout << numbers[i] << ", ";
    }
    cout << numbers[size - 1] << endl;

    int value;
    cout << "\nEnter number you want to search: ";
    cin >> value;
    int position = binarySearch(&(numbers[0]), size, value);
    string end;
    if (position == 1) {
        end = "st";
    }
    if (position == 2) {
        end = "nd";
    }
    if (position == 3) {
        end = "rd";
    }
    if (position >= 4) {
        end = "th";
    }
    cout << "Number is presented at " << position << end << " location." << endl;
}


