#include<bits/stdc++.h>
using namespace std;
/*
167. Two Sum II - Input Array Is Sorted
    Given a 1-indexed array of integers numbers that is already sorted in non-decreasing order, find two numbers such that they add up to a specific target number. Let these two numbers be numbers[index1] and numbers[index2] where 1 <= index1 < index2 <= numbers.length.

    Return the indices of the two numbers, index1 and index2, added by one as an integer array [index1, index2] of length 2.

    The tests are generated such that there is exactly one solution. You may not use the same element twice.

    Your solution must use only constant extra space.

Example 1:

    Input: numbers = [2,7,11,15], target = 9
    Output: [1,2]
    Explanation: The sum of 2 and 7 is 9. Therefore, index1 = 1, index2 = 2. We return [1, 2].

Constraints:

    2 <= numbers.length <= 3 * 104
    -1000 <= numbers[i] <= 1000
    numbers is sorted in non-decreasing order.
    -1000 <= target <= 1000
    The tests are generated such that there is exactly one solution.

Approach 1: Brute Force

    1) take single element and search next one

    2) TC: O(n^2) and SC: O(1)


Approach 2: Binary Search

    1) take any element
    2) [target - x] present of given sorted array

    3) TC: O(n log n)  and SC: (1)


Approach 3: Map or Urordered_map

    1) iterate and seen prevous [target-num[i]] present before seen

    2) TC: O(n) and SC: O(n)



Approach 3: Sorted array
    1) given sorted array
    2) Two pointer equal, greater, less then of target

    3) TC: O(n) and SC: O(1)

*/
 vector<int> twoSum(vector<int>& numbers, int target) {
    vector<int> ans;
    int start = 0;
    int end = numbers.size()-1;
    while(start < end)
    {
        if((numbers[start] + numbers[end]) == target)
        {
            ans.push_back(start+1);
            ans.push_back(end+1);
            break;
        }
        else if((numbers[start] + numbers[end]) < target){
            start++;
        }
        else{
            end--;
        }
    }
    return ans;
}
int main()
{
    int n, target;
    cin >> n >> target;
    vector<int> nums;
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        nums.push_back(x);
    }
    vector<int> ans;
   ans = twoSum(nums, target);
   cout << ans[0] << " " << ans[1];
}
