//Commwnting

// Just a small edit to force GitHub to update
#include <iostream>

#include <iostream>

int removeMax(int myArray[], int & size)
{
    if (size <= 0) {
        return -1;
    }
    
    int maxIndex = 0;
    for (int i = 1; i < size; i++) {
        if (myArray[i] > myArray[maxIndex]) {
            maxIndex = i;
        }
    }
    
    for (int i = maxIndex; i < size - 1; i++) {
        myArray[i] = myArray[i + 1];
    }
    
    size--;
    
    return maxIndex;
}

int main()
{
    int arr[] = {5, 9, 3, 7, 2};
    int size = 5;
    
    int maxIndex = removeMax(arr, size);
    
    std::cout << "Max index: " << maxIndex << std::endl;
    
    std::cout << "Array after: ";
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    
    return 0;
}