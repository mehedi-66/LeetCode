#include<bits/stdc++.h>
using namespace std;

/*
Problem statement:

    Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

    You may assume that each input would have exactly one solution, and you may not use the same element twice.

    You can return the answer in any order.

Example:
    Input: nums = [2,7,11,15], target = 9
    Output: [0,1]

Constrains:
    2 <= nums.length <= 10^4
    -10^9 <= nums[i] <= 10^9
    -10^9 <= target <= 10^9

Approach 1:
        B.F
        *) select one position Looping rest of the array

        *) Time: O(n^2) Space: O(1)

Approach 2:
        *) After sort and keep index poition fixed
        *) Tow pointer: start, end => meet on the mid

        *) Time: O(n log n) Space: O(1)

Approach 3:
        *) map or unorderMap
        *) Before seen problem
        *) map[ Target - curr ] present or not

        *) Time: O(n) Space: O(n)

*/
 vector<int> twoSum1(vector<int>& nums, int target) {

   // map<int, int> mp; // 8 ms
    unordered_map<int, int> mp;  // 3 ms  74% beat

    vector<int> ans;
    for(int i = 0; i < nums.size(); i++)
    {

        int x = target - nums[i];
        //cout << mp[x] << " " <<  (target - nums[i]) << " " << i << endl;
        if(mp[x] == 0)
        {
            mp[nums[i]] = (i+1);
        }
        else{

            ans.push_back(i);
            ans.push_back(mp[x]-1);
            return ans;
        }
    }
    return ans;

}

vector<int> twoSum2(vector<int>& nums, int target) {

   // Tow pointer approach
   // Sort array with pair means keep index wise sorted
   vector<pair<int, int>> sortWithIndex;
   for(int i = 0; i < nums.size(); i++)
   {
       sortWithIndex.push_back({nums[i], i});
   }

   sort(sortWithIndex.begin(), sortWithIndex.end());

   auto start = sortWithIndex.begin();
   auto end = sortWithIndex.end() - 1;

   vector<int> ans;
   while(start < end)
   {

      int sum = start->first + end->first;

        if (sum == target) {
            ans.push_back(start->second);
            ans.push_back(end->second);
            return ans; // Return the first valid pair
        }
        if (sum < target) {
            start++; // Move to a larger value
        } else {
            end--; // Move to a smaller value
        }
   }

   return ans;

}
int main()
{
    vector<int> v;
    int n, target;
    cin >> n >> target;

    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);

    }

    vector<int> ans = twoSum2(v, target);
    cout << "ans = " <<  ans[0] << " " << ans[1] << endl;

    return 0;
}
