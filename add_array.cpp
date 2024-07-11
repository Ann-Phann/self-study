#include <iostream>
#include <vector>

int main()
{
    // Initial array
    std::vector<int> array = {4, 5, 6};
    
    // Elements to be added
    std::vector<int> elements_to_add = {1, 2, 3};
    
    // Append elements to the existing array
    array.insert(array.end(), elements_to_add.begin(), elements_to_add.end());

    // Print the resulting array
    std::cout << "Extended array: ";
    for (int i = 0; i < array.size(); ++i)
    {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
