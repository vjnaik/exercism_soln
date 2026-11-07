def find(search_list, value):
    if len(search_list) == 0 or value < search_list[0] or value > search_list[-1]:
        raise ValueError("value not in array")

    def bsearch_helper(arr, target, low, high):
        if low > high:
            raise ValueError("value not in array")
    
        mid = low + (high - low) // 2
    
        if arr[mid] == target:
            return mid
    
        if arr[mid] > target:
            return bsearch_helper(arr, target, low, mid - 1)

        return bsearch_helper(arr, target, mid + 1, high)

    return bsearch_helper(search_list, value, 0, len(search_list))