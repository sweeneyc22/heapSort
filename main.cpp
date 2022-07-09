// C++ program for implementation of Heap Sort
#include <iostream>
#include <chrono>
#include <vector>

using namespace std;

// To heapify a subtree rooted with node i
// which is an index in arr[].
// n is size of heap
void heapify(int arr[], int n, int i)
{

    // Initialize largest as root
    int largest = i;

    // left = 2*i + 1
    int l = 2 * i + 1;

    // right = 2*i + 2
    int r = 2 * i + 2;

    // If left child is larger than root
    if (l < n && arr[l] > arr[largest])
        largest = l;

    // If right child is larger than largest
    // so far
    if (r < n && arr[r] > arr[largest])
        largest = r;

    // If largest is not root
    if (largest != i) {
        swap(arr[i], arr[largest]);

        // Recursively heapify the affected
        // sub-tree
        heapify(arr, n, largest);
    }
}

// Main function to do heap sort
void heapSort(int arr[], int n)
{

    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // One by one extract an element
    // from heap
    for (int i = n - 1; i > 0; i--) {

        // Move current root to end
        swap(arr[0], arr[i]);

        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

// A utility function to print array of size n
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}

// Driver code
int main()
{
    const long long TIMES_TO_RUN{100};
    std::vector<double> runtimes;

    cout << "Enter array size\n";
    int arraySize;
    cin >> arraySize;

    for (int i = 0; i < TIMES_TO_RUN; ++i)
    {
        int arr[arraySize];
        int n = arraySize;

        for (int i = 0; i < arraySize; ++i)
        {
            arr[i] = rand() % 10000;
        }
        std::chrono::steady_clock::time_point _start(std::chrono::steady_clock::now());
        heapSort(arr, n);
        std::chrono::steady_clock::time_point _end(std::chrono::steady_clock::now());

        double runtime = std::chrono::duration_cast<std::chrono::duration<double>>(
                _end - _start).count();

        runtimes.push_back(runtime);
    }
    double totRuntime{0};
    double avgRuntime{0};
    //Sum the runtimes
    for (double& n : runtimes)
        totRuntime += n;

    avgRuntime = totRuntime / runtimes.size();

    cout << "\n\n\n Total run time: " << totRuntime;
    cout << "\n\n\n Average run time: " << avgRuntime;

}