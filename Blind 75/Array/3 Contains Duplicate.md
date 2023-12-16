
## 1. Two Sum


[Problem Link](https://leetcode.com/problems/two-sum/description/)


### Problem statement: 
---
Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.

### Example 1
    
    Input: nums = [1,2,3,1]
    Output: true

### Example 2

    Input: nums = [1,2,3,4]
    Output: false

## Constraints:
    
    1 <= nums.length <= 105
    -109 <= nums[i] <= 109

### How to think and hint:
---

#### Method 1

We can store the previous occourace of number using map

<br/>

    Time Complexity : O(n)  
    Space Complexity: O(n)  exta space   

#### Method 2

We can **sort** the array then Check the imidate pair element 

<br/>

    Time Complexity : O(n log n)  
    Space Complexity: O(1)   

### Write down code
---

### Method 1

```C++
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
       
        map<int, int> mp;
       
        for(int i = 0; i < nums.size(); i++)
        {
            if(mp[nums[i]])
            {
                return true;
                // break 
            }
            else{
                mp[nums[i]]++;
            }
        }

        return false;
    }
};
```
### Method 2
```C++
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        
        map<int, int> mp;
        for(int i = 0; i < nums.size(); i++)
        {
            if(mp[nums[i]])
            {
                return true;
            }
            else
            {
                mp[nums[i]] = 1; 
            }
        }
        
        return false;
    }
};
```