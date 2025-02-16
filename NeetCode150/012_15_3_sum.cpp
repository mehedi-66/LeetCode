#include<bits/stdc++.h>
using namespace std;

/*
15. 3Sum
    Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

    Notice that the solution set must not contain duplicate triplets.

Example 1:

    Input: nums = [-1,0,1,2,-1,-4]
    Output: [[-1,-1,2],[-1,0,1]]
    Explanation:
    nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
    nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
    nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
    The distinct triplets are [-1,0,1] and [-1,-1,2].
    Notice that the order of the output and the order of the triplets does not matter.


Example 2:

    Input: nums = [0,1,1]
    Output: []
    Explanation: The only possible triplet does not sum up to 0.


Constraints:

    3 <= nums.length <= 3000
    -105 <= nums[i] <= 10^5


NOTE: after sort the array Positive value search give +sum not given zero

Approach 1:
        1) nested loop

        2) TC: O(n^3)  and SC: O(1)

Approach 2:
    1) Sort 1 time
    2) Dubplicate value skip

    3) TC: O(n^2) and SC: O(1)

Approach 3: Two Sum problem (HashSet)

    1) fix first element let's say -5
    2) From rest of them nums[j] + nums[k] +5
    3) actually make two sum Before seen problem

    4) TC: O(n^2) and SC: O(n)


Approach 4: two sum ii problem (Two pointer)
    1) fix one
    2) sort rest of the array
    3) both side two pointer read that


*/


 vector<vector<int>> threeSum(vector<int>& nums) {

     vector<vector<int>> ans;
     map<vector<int>, int> mp;
     for(int i = 0; i < nums.size(); i++)
     {
         for(int j = i+1; j < nums.size(); j++)
         {
             for(int k = j+1; k < nums.size(); k++)
             {
                 if((nums[i]+nums[j]+nums[k]) == 0)
                 {
                    vector<int> t;
                    t.push_back(nums[i]);
                    t.push_back(nums[j]);
                    t.push_back(nums[k]);
                    sort(t.begin(), t.end());
                    if(mp[t] != 0)
                    {
                        mp[t] = 1;
                        ans.push_back(t);
                    }
                 }
             }
         }
     }
     return ans;
}

vector<vector<int>> threeSum2(vector<int>& nums) {
         sort(nums.begin(), nums.end()); // Sort the array
    vector<vector<int>> ans;

    for (int i = 0; i < nums.size(); i++) {
        if (i > 0 && nums[i] == nums[i - 1]) continue; // Skip duplicates for i

        int left = i + 1, right = nums.size() - 1;
        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];

            if (sum == 0) {
                ans.push_back({nums[i], nums[left], nums[right]});

                // Skip duplicate values for left and right pointers
                while (left < right && nums[left] == nums[left + 1]) left++;
                while (left < right && nums[right] == nums[right - 1]) right--;

                left++;
                right--;
            }
            else if (sum < 0) left++;  // Increase left pointer if sum is too small
            else right--;  // Decrease right pointer if sum is too large
        }
    }

    return ans;
    }

vector<vector<int>> threeSum(vector<int> nums)
{
    sort(nums.begin(), nums.end()); // Sort the array
    vector<vector<int>> ans;

    for(int i = 0; i < nums.size(); i++)
    {
        if(i > 0 && nums[i] == nums[i-1]) continue; // Skip duplicate elements for 'i'

        int left = i+1;
        int right = nums.size() - 1;

        while(left < right)
        {
            int sum = nums[i] + nums[left] + nums[right];

            if(sum < 0)
            {
                left++;
            }
            else if(sum > 0)
            {
                right--;
            }
            else {
                ans.push_back({nums[i], nums[left], nums[right]});

                // Skip duplicate values for left and right pointers
                while(left < right && nums[left] == nums[left + 1]) left++;
                while(left < right && nums[right] == nums[right - 1]) right--;

                left++;
                right--;
            }
        }
    }

    return ans;
}
int main()
{
    int n;
    vector<int> nums;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        nums.push_back(x);
    }
    vector<vector<int>> ans;
    ans = threeSum(nums);
    return 0;
}
