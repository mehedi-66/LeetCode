
## 1. Two Sum


[Problem Link](https://leetcode.com/problems/two-sum/description/)


### Problem statement: 
---
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to *target*.

You may assume that each input would have *exactly one* solution, and you may not use the same element twice.

You can return the answer in any order.

### Example 1
    
    Input: nums = [2,7,11,15], target = 9
    Output: [0,1]
    Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
### Example 2

    Input: nums = [3,2,4], target = 6
    Output: [1,2]

## Constraints:
    
    2 <= nums.length <= 104
    -109 <= nums[i] <= 109
    -109 <= target <= 109
 
    Only one valid answer exists.
**Follow-up:** Can you come up with an algorithm that is less than O(n2) time complexity?

### How to think and hint:
---

#### Method 1

We can solve using two nested loop by Searching Technique  


<br/>

    Time Complexity : O(n^2)  
    Space Complexity: O(1)  

#### Method 2

We can store previous data into map with index Then Target substract current number If sub value previously we seen That is our ans.

<br/>

    Time Complexity : O(n)  
    Space Complexity: O(n)  for store into map   

### Write down code
---

### Method 1

```C++
    for(int i = 0; i < nums.size(); i++)
    {
        // j = i then same value num[i] + num[i] == target 
        for(int j = i+1; j < nums.size(); j++)
        {
            if(nums[i] + nums[j] == target)
            {
                ans.push_back(i);
                ans.push_back(j);

                break;
            }
        }
    }
```

```C++
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> mp;
        vector<int> ans;
        
        mp[nums[0]] = 1;  // Coner case 0 index 
                          // one index fast forward 

        for(int i = 1; i < nums.size(); i++)
        {
            int x = target - nums[i];
            if(mp[x] > 0)
            {
                ans.push_back(mp[x] - 1);
                ans.push_back(i);
                break;
            }
            else{
                mp[nums[i]] = i+1;
            }
        }

        return ans;
    }
};
```