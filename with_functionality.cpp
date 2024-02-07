// Positive only
#include <iostream>
using namespace std;

// Function to perform counting sort on an array
void countingSort (int orginalSize, int maxValue, int orginalArray[])
{
    int counterArray[maxValue+1] = {0};// Initialized the occurrences tracker array with zero
    int sortedArray[orginalSize];// Storing sorted array here

    // Counting occurrences of each element
    for (int i = 0; i < orginalSize; i++)
    {
        counterArray[orginalArray[i]]++; // Incrementing the value of the counter array, where the original array's element is the index
    }
    
    // Calculating 'running sum' of counter array
    for (int i = 0; i < maxValue; i++)
    {
        counterArray[i+1] += counterArray[i]; // Adding the next element of the counter array with the previous element
    }
    
    // Sorted array placement
    for (int i = 0; i < orginalSize; i++)
    {
        // Assigning the value of orginalArray
        sortedArray[--counterArray[orginalArray[i]]] = orginalArray[i];
        // The original array's element is the index of the counter array, and the counter array's element is the index of the sorted array
    }

    // Assigning the sorted array back to the original array 
    for (int i = 0; i < orginalSize; i++)
    {
        orginalArray[i]=sortedArray[i];
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
    
    // Input elements
    cout<<"     Input elements: ";
    for (int i = 0; i < size; i++)
    {
        cin>>array[i];
        // Finding the largest element of the given array
        maxValue = max(array[i], maxValue);
    }
    
    // Output module
    cout<<endl<<"Output module: "<<endl<<endl
        <<"     Given Array : ";
    // Printing the unsorted given array
    for (int i = 0; i < size; i++) cout<<array[i]<<" ";// printing the unsorted given array
    cout<<endl;

    countingSort(size, maxValue, array);

    // Printing the sorted given array
    cout<<"     Sorted Array: ";
    for (int i = 0; i < size; i++)  cout<<array[i]<<" ";// printing the sorted given array
    cout<<endl;
    
    return 0;
}