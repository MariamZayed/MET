def partition(array, left, right):
    # choose the rightmost element as pivot
    pivot = array[right]
    # pointer for greater element
    i = left - 1
    
    # compare each element with pivot
    for j in range(left, right):
        if array[j] <= pivot:
            # If element smaller than pivot is found
            # swap it with the greater element pointed by i
            i = i + 1
            # Swapping element at i with element at j
            (array[i], array[j]) = (array[j], array[i])
            
    # Swap the pivot element with the greater element specified by i
    (array[i + 1], array[right]) = (array[right], array[i + 1])
    # Return the position from where partition is done
    return i + 1


# function to perform quicksort
def quickSort(array, left, right):
    if left < right:
        # Find pivot element 
        # element smaller than pivot are on the left of pivot
        # element greater than pivot are on the right of the pivot
        pivot = partition(array, left, right)
        # Recursive call on the left of pivot
        quickSort(array, left, pivot - 1)
        # Recursive call on the right of pivot
        quickSort(array, pivot + 1, right)


data = [20 , 10 , 30 , 60, 80, 5]
print("Unsorted Array")
print(data)
size = len(data)
quickSort(data, 0, size - 1)
print('Sorted Array in Ascending Order:')
print(data)