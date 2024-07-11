//O(log n) time complexity
#include <iostream>

int binary_search(int* array, int size, int target)
{
    int first = 0;
    int last = size - 1;

    while (first <= last)
    {
        int midpoint = (first + last)/2;
        if (array[midpoint] == target)
        {
            return midpoint;
        }
        else if (array[midpoint] < target)
        {
            first = midpoint + 1;
        } else {
            last = midpoint - 1;
        }

    }
    return -1;
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

    verify(binary_search(array, size, key));
}