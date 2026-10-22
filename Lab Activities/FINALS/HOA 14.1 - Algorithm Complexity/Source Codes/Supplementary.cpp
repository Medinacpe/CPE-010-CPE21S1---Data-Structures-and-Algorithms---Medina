// CPE010 - Lab 14.1 Supplementary Activity

#include <iostream>
#include <vector>
#include <chrono>
#include <iomanip>

using namespace std;

// Linear Search from lab
bool linearSearchArr(const vector<int>& data, int item){
    for (int i = 0; i < (int)data.size(); i++){
        if (data[i] == item) {
            return true;
        }
    }
    return false;
}

// Binary Search from lab
bool binarySearchArr(const vector<int>& arr, int low, int high, int item){
    if (low > high) {
        return false;
    }

    int mid = low + (high - low) / 2;

    if (arr[mid] == item){
        return true;
    } else if (item < arr[mid]){
        return binarySearchArr(arr, low, mid - 1, item);
    } else {
        return binarySearchArr(arr, mid + 1, high, item);
    }
}

double measureTime(const vector<int>& arr, int item, bool useBinary, int repetitions) {
    const int trials = 5;
    double total = 0;

    for (int trial = 0; trial < trials; trial++) {
        volatile int foundCount = 0;
        auto start = chrono::steady_clock::now();

        for (int i = 0; i < repetitions; i++) {
            bool found;

            if (useBinary) {
                found = binarySearchArr(arr, 0, (int)arr.size() - 1, item);
            } else {
                found = linearSearchArr(arr, item);
            }

            if (found) {
                foundCount++;
            }
        }

        auto finish = chrono::steady_clock::now();

        double microseconds =
            chrono::duration<double, micro>(finish - start).count();
        total += microseconds / repetitions;
    }

    return total / trials;
}

int main() {
    int sizes[] = {1000, 10000, 100000};

    cout << fixed << setprecision(4);
    cout << "LAB 14.1 - SUPPLEMENTARY ACTIVITY\n";
    cout << "Average execution time of 5 trials (microseconds)\n";

    cout << left << setw(18) << "Input Size (N)" << setw(26) << "Binary Search (us)" << "Linear Search (us)\n";

    for (int n : sizes) {
        vector<int> data;
        for (int i = 1; i <= n; i++) {
            data.push_back(i);
        }

        int target = n + 1;
        int linearRepetitions = 5000000 / n;
        int binaryRepetitions = 100000;

        double binaryTime = measureTime(data, target, true, binaryRepetitions);
        double linearTime = measureTime(data, target, false, linearRepetitions);

        cout << left << setw(18) << n << setw(26) << binaryTime << linearTime << "\n";
    }

    return 0;
}
