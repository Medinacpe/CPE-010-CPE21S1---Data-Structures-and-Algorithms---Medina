#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <iomanip>

void bubbleSort(std::vector<int>& arr) {
    int n = arr.size();
    bool swapped;

    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        if (!swapped)
            break;
    }
}

void shellSort(std::vector<int>& arr) {
    int n = arr.size();

    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j = i;

            while (j >= gap && arr[j - gap] > temp) {
                arr[j] = arr[j - gap];
                j -= gap;
            }

            arr[j] = temp;
        }
    }
}

double measureTime(const std::vector<int>& original, bool useBubbleSort) {
    const int trials = 5;
    double totalTime = 0;

    for (int t = 0; t < trials; t++) {
        std::vector<int> arr = original;

        auto start = std::chrono::steady_clock::now();

        if (useBubbleSort) {
            bubbleSort(arr);
        } else {
            shellSort(arr);
        }

        auto finish = std::chrono::steady_clock::now();

        double microseconds =
            std::chrono::duration<double, std::micro>(finish - start).count();
        totalTime += microseconds;
    }

    return totalTime / trials;
}

int main() {
    int sizes[] = {100, 1000, 10000};

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "LAB 14.1 - EXPERIMENTAL SORTING ANALYSIS PROCEDURE\n";
    std::cout << "Average execution time in 5 trials (microseconds)\n";

    for (int n : sizes) {
        std::vector<int> bestCase;

        // Best case
        for (int i = 1; i <= n; i++) {
            bestCase.push_back(i);
        }

        // worst case
        std::vector<int> worstCase = bestCase;
        std::reverse(worstCase.begin(), worstCase.end());

        double bubbleBest = measureTime(bestCase, true);
        double bubbleWorst = measureTime(worstCase, true);
        double shellBest = measureTime(bestCase, false);
        double shellWorst = measureTime(worstCase, false);

        std::cout << "\nInput Size (N): " << n << "\n";
        std::cout << std::left << std::setw(16) << "Case"
                  << std::setw(23) << "Bubble Sort (us)"
                  << "Shell Sort (us)\n";
        std::cout << std::left << std::setw(16) << "Best Case"
                  << std::setw(23) << bubbleBest << shellBest << "\n";
        std::cout << std::left << std::setw(16) << "Reverse Sorted"
                  << std::setw(23) << bubbleWorst << shellWorst << "\n";
    }
    return 0;
}