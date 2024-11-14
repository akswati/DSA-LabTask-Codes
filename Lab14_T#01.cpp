#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;

        // Move elements of arr[0..i-1] that are greater than key
        // to one position ahead of their current position
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int array[] = {44391, 44647, 47777, 53759, 55181, 55223, 55225, 55330,
                   55349, 55356, 55405, 55434, 55465, 55469, 55566, 55579,
                   55584, 55590, 55632, 55633, 55652, 55691, 55700, 55766,
                   55780, 55843, 55853, 56067, 56154, 56177, 56274, 56673,
                   56765, 56983};

    int n = sizeof(array) / sizeof(array[0]);

    // Display original array
    cout << "\nOriginal Array (Unsorted): ";
    display(array, n);

    // Perform Bubble Sort in ascending order
    int bubbleArray[n];
    copy(array, array + n, bubbleArray); // Copy the original array for bubble sort
    bubbleSort(bubbleArray, n);
    cout << "\nBubble Sorted Array (Ascending): ";
    display(bubbleArray, n);

    // Perform Insertion Sort in ascending order
    int insertionArray[n];
    copy(array, array + n, insertionArray); // Copy the original array for insertion sort
    insertionSort(insertionArray, n);
    cout << "\nInsertion Sorted Array (Ascending): ";
    display(insertionArray, n);

    return 0;
}
