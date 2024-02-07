// Postive and negative both
#include <iostream>
using namespace std;

// Function to perform counting sort on an array
void countingSort (int orginalSize, int minValue, int maxValue, int orginalArray[])
{
    int range = maxValue - minValue; // Calculating the range of the given array
    int counterArray[range+1] = {0}; // Initialized the occurrences tracker array with zero
    int sortedArray[orginalSize]; // Storing sorted array here

    // Subtracting the smallest value from orginal array elements, and counting occurrences of each element
    for (int i = 0; i < orginalSize; i++)
    {
        orginalArray[i] -= minValue; // Creating positive sortable array by subtruction
        counterArray[orginalArray[i]]++; // Incrementing the value of the counter array, where the original array's element is the index
    }

    // Calculating 'running sum' of counter array
    for (int i = 0; i < range; i++)
    {
        counterArray[i+1] += counterArray[i]; // Adding the next element of the counter array with the previous element
    }

    // Sorted array placement
    for (int i = 0; i < orginalSize; i++)
    {
        // Assigning the real value by addition
        sortedArray[--counterArray[orginalArray[i]]] = orginalArray[i] += minValue;
        // The original array's element is the index of the counter array, and the counter array's element is the index of the sorted array
    }

    // Assigning the sorted array back to the original array  
    for (int i = 0; i < orginalSize; i++)
    {
        orginalArray[i] = sortedArray[i];
    }
}

int main ()
{
    // Input module
    int size;
    cout<<endl<<"Input module: "<< endl
        <<endl<<"     Enter the size of array: ";
    cin>>size;

    int array[size];
    int maxValue = 0;
    int minValue = 0;
    
    // Input elements
    cout<<"     Input elements: ";
    for (int i = 0; i < size; i++)
    {
        cin>>array[i];
        // Finding the largest and smallest elements of the given array
        maxValue = max(array[i], maxValue);
        minValue = min(array[i], minValue);
    }
    
    // Output module
    cout<<endl<<"Output module: "<<endl<<endl
        <<"     Given Array : ";
    // Printing the unsorted given array
    for (int i = 0; i < size; i++) cout<<array[i]<<" "; // printing the unsorted given array
    cout<<endl;

    countingSort(size, minValue, maxValue, array);

    // Printing the sorted given array
    cout<<"     Sorted Array: ";
    for (int i = 0; i < size; i++)  cout<<array[i]<<" "; // printing the sorted given array
    cout<<endl;
    
    return 0;
}