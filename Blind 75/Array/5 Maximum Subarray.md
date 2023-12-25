
## 5. Maximum Subarray



[Problem Link](https://leetcode.com/problems/maximum-subarray/)


### Problem statement: 
---
Given an integer array nums, find the 
subarray
 with the largest sum, and return its sum.

### Example 1
    
    Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
    Output: 6
    Explanation: The subarray [4,-1,2,1] has the largest sum 6.

### Example 2

    Input: nums = [1]
    Output: 1
    Explanation: The subarray [1] has the largest sum 1.

## Constraints:
    
    1 <= nums.length <= 105
    -104 <= nums[i] <= 104
 
   Follow up: If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.

### How to think and hint:
---

#### Method 1

Every time sum with current number of array and take maximum If curr sum negetive then curr = 0


<br/>

    Time Complexity : O(n)  
    Space Complexity: O(1)  

#### Method 2



<br/>



### Write down code
---

### Method 1

```C++
   class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSub = nums[0];
        int currSum = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(currSum < 0)
                currSum = 0;
            
            currSum += nums[i];

            maxSub = max(maxSub, currSum);
        }
        return maxSub;
    }
};
```
