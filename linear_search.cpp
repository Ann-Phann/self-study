//O(n) time complexity
#include <iostream>

int linear_search(int* array, int size, int target)
{

    for (int i = 0; i < size; i++)
    {
        if (array[i] == target)
        {
            return array[i];
            break;
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

    verify(linear_search(array, size, key));
}