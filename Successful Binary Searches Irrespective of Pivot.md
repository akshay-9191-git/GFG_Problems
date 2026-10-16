## 01. Successful Binary Searches Irrespective of Pivot

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/count-always-found/1)

### Problem Description

**Task:** Given an array arr[] of n distinct integers (not necessarily sorted), consider the following search for a target: Maintain a range [lo, hi], initially [0, n-1]. At each step, pick any index p in [lo, hi] (not necessarily the middle) as pivot. If arr[p] = = target, stop - found. If target < arr[p], set hi = p - 1; if target > arr[p], set lo = p + 1. If lo > hi, stop - not found.Count the number of indices i such that searching for target = arr[i] succeeds no matter which pivot is chosen at every step (i.e., for every possible sequence of pivot choices).Examples:Input: arr[] = [3, 7, 9, 8, 15]

#### Examples

##### Example 1

- **Output:**
```text
3
```
- **Explanation:** 3, 7, and 15 (indices 0, 1, 4) are always found: every possible pivot comparison happens to steer the search toward them, no matter the order. 9 and 8 are not: e.g. if the first pivot picked is 8, searching for 9 gets pushed right and index 2 is lost forever; if the first pivot is 9, searching for 8 gets pushed left and index 3 is lost forever.

##### Example 2

- **Input:**
```text
arr[] = [9, 4, 1, 10, 22, 23, 20]
```
- **Output:**
```text
1
```
- **Explanation:** Only 10 (index 3) is always found — every pivot, left or right, happens to steer toward it. Everything else can fail on some pivot order: e.g. picking 4 first pushes a search for 9 away permanently, and picking 20 first makes a search for 22 run off the end of the array entirely.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n)
- **Expected Auxiliary Space Complexity:** O(n)

### Accepted Solutions (1)

#### Solution 1 (C++)

- **Submitted:** 2026-10-16 10:46:28
- **Status:** Correct
- **Marks:** 4

```cpp
class Solution {
  public:
    int countAlwaysFound(vector<int>& arr) {
        // code here
        int n = arr.size();
        vector<int> leftmax(n);
        vector<int> rightmin(n);
        
        leftmax[0] = INT_MIN;
        for(int i=1;i<n;i++){
            leftmax[i] = max(leftmax[i-1] , arr[i-1]);
        }
        
        rightmin[n-1] = INT_MAX;
        for(int i=n-2; i>=0;i--){
            rightmin[i] = min(rightmin[i+1] , arr[i+1]);
        }
        int count = 0;
        for(int i=0;i<n;i++){
            if(arr[i] > leftmax[i] && arr[i] < rightmin[i]){
                count++;
            }
        }
        return count;
        
    }
};
```

*Generated on: 10/16/2026, 9:31:02 PM*