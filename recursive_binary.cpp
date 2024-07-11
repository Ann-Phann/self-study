//O(log n) time complexity
#include <iostream>

int recursive_binary (int* array, int size, int target)
{
    if (size  == 0)
    {
        std::cout << "No elements in the array" << std::endl;
        return -1;
    }

    int midpoint = size/2;

    if (array[midpoint] == target)
    {
        return midpoint;
    }
    else if ( array[midpoint] < target)
    {
        //search in the right half side of the array
        return recursive_binary(array + midpoint + 1, size - midpoint - 1, target);
    } else {
        //search in the left half side of the array
        return recursive_binary(array, midpoint, target);
    }
}


void verify(int index)
{
    if (index != -1)
    {
        std::cout << "Element found: " << index << std::endl;
    }
    else
    {
        std::cout << "Element not found" << std::endl;
    }
}

int main(void)
{
    int array[] = {1, 2, 3, 4, 5};
    int key = 3;
    int size = sizeof(array) / sizeof(array[0]);

    verify(recursive_binary(array, size, key));
}