//O(n^2) time complexity
// sorting
#include <iostream>

void selection_sort (int* array, int size)
{
    for (int i = 0; i <size; i++) // n lan
    {
        for (int j = i + 1; j < size; j++) //n -i lan
        {
            if (array[i] > array[j])
            {
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }

    for (int k = 0; k < size; k++)
    {
        std::cout << array[k] << " ";
    }
}

int main (void)
{
    int array[] = {4, 3, 6, 2, 1, 5};
    int size = sizeof(array) / sizeof(array[0]);

    selection_sort(array, size);
}