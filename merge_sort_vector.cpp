//merge sort: splitting up the problem into sub problems (1/2)
/*e.g: ascending order
8 3 6 2 1 5 7 4
8 3 6 2         1 5 7 4
8 3    6 2      1 5    7 4
8   3    6   2   1   5    7   4

repeatedly merging te single element arrays and sorting at the same time
38  26  15  47
2368    1475
12345678
*/

#include <iostream>
#include <vector>
/*
sort an array inascending order using merge sort
return the sorted array

Step:
1. Find the midpoint of the array and divide into sublists
2. Conquer: recursively sort the sublists created in the previous step
3. Combine: merge the sorted sublists created in the previous step 

Recursive function has basic pattern: 
1. Base case: we start with the base case that incluses a stopping condition: simplist condition that satisfies the result
2. After that we have some logic that breaks down the problem and recursively calls itself
*/

//return a completely sorted vector of integers
/*we should pass in reference parameter:
- Avoids Copying: When you pass list by reference (const std::vector<int>& list), you're passing a reference to the original 
vector rather than making a copy of it. This is more efficient, especially for large vectors, because it avoids the overhead 
of copying the entire vector.

- Const Correctness: Using const ensures that the function merge_sort does not modify the original vector. This is important 
for maintaining clarity and preventing accidental modifications to data that shouldn't change.

- Flexibility: Passing by reference allows the function to operate on the original vector directly, which can be crucial if 
you need to modify or inspect the vector within the function without affecting its original state outside of the function.
*/
std::pair<std::vector<int>, std::vector<int>> split(std::vector <int>& list);
std::vector<int> merge(std::vector<int>& left_half, std::vector<int>& right_half);


std::vector<int> merge_sort(std::vector<int>& list)
{
    //our stopping condition is our end goal
    int size = list.size();
    if (size <= 1)
    {
        return list;
    }

    //divide the array into two subarrays
    auto [left_half, right_half] = split(list);

    //conquer: recursively sort the subarrays
    left_half = merge_sort(left_half);
    right_half = merge_sort(right_half);
    return merge(left_half, right_half);
}

std::pair<std::vector<int>, std::vector<int>> split(std::vector <int>& list)
{
    /*
    Divide the unsorted list at midpoint into sublists
    Return 2 sublists - left and right
    */
    int mid = list.size()/2;
    std::vector<int> left_half = std::vector<int>(list.begin(), list.begin() + mid);
    std::vector<int> right_half = std::vector<int>(list.begin() + mid, list.end());
    return {left_half, right_half};
}

std::vector<int> merge(std::vector<int>& left_half, std::vector<int>& right_half)
{
    /*
    Merge two arrays into one
    Return a new merged array
    e.g: 37 58
    left = 37, right = 58
    they will compare left[0] and right[0] --> 3
    then, left[1] and right[0] --> 5
    then, left[1] and right[1] --> 8
    */
   int left = 0, right = 0; //index for left and right 
   std::vector<int> result; //store the result

    //when left and right have the same size
   while (left < left_half.size() && right < right_half.size())
   {
        if (left_half[left] < right_half[right])
        {
            result.push_back(left_half[left]);
            left++; //move to the next element
        } else {
            result. push_back(right_half[right]);
            right++;
        }
   }
    /*there are situatiin when when 1 array is larger or smaller than the other
    e.g: there are 3 elements

    where the right is shorter than the left and the loop above will terminate earlier, then not all sorted
    we add the remaining elements in the left to the new list
    we not going to compare but assume that within a list, the elements are already sorted */

   //if left_half still has elements
   while (left < left_half.size())
   {
        result.push_back(left_half[left]);
        left++;
   }

    //if right_half still has elements
    while (right < right_half.size())
    {
        result.push_back(right_half[right]);
        right++;
    }
    return result;
}

void print_vector(std::vector<int>& list)
{
    for (int i = 0; i < list.size(); i++)
    {
        std::cout << list[i] << " ";
    }
    std::cout << std::endl;
}

int main (void)
{
    std::vector<int> list = {8, 3, 6, 2, 1, 5, 7, 4};
    std::vector<int> sorted_list = merge_sort(list);
    print_vector(sorted_list);
}