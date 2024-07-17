
def merge_sort(list):
    if len(list) <= 1:
    
        return list
    
    left_half, right_half = split(list)
    #conquer
    left = merge_sort(left_half)
    right = merge_sort(right_half)
    return merge(left, right)

def split(list):
    mid = len(list)//2
    return list[:mid], list[mid:]

def merge(left, right):
    """
    Merge two lists (arrays), sorting them in the process
    Return a new merged list
    """

    l= []
    i = 0 #index for left
    j = 0 #index for right

    while i < len(left) and j <len(right):
        if left[i] < right[j]:
            l.append(left[i])
            i += 1
        else:
            l.append(right[j])
            j += 1
#there are situatiin when when 1 array is larger or smaller than the other
#e.g: there are 3 elements

#where the right is shorter than the left and the loop above will terminate earlier, then not all sorted
#we add the remaining elements in the left to the new list
#we not going to compare but assume that within a list, the elements are already sorted 
    while i < len(left):
        l.append(left[i])
        i += 1
    while j < len(right):
        l.append(right[j])
        j += 1
    return l

def verify_sorted(list):
    n = len(list)

    if n == 0 or n == 1:
        return True
    return list[0] < list[1] and verify_sorted(list[1:])