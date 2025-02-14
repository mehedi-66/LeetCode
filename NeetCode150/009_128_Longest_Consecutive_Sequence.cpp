#include<bits/stdc++.h>
using namespace std;
/*
128. Longest Consecutive Sequence

    Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

    You must write an algorithm that runs in O(n) time.

Example 1:

    Input: nums = [100,4,200,1,3,2]
    Output: 4
    Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.

Example 2:

    Input: nums = [0,3,7,2,5,8,4,6,0,1]
    Output: 9

Constraints:

    0 <= nums.length <= 10^5
    -10^9 <= nums[i] <= 10^9
    --------------------------------------------------------------------------

Approach 1:
    1) Sort the array and
    2) read and max count of Consecutive sequence

    3) TC: O(n log n) and SC: O(n)

Approach 2: HashSet
    1) insert all array element to hashsert
    2) subsequence start value find out
    3) first start any number and back and back by -1 to get start number
       of any random subsequence
    4)  when we found start then  increment and increment get length of sequence

    5) TC: O(n) and SC: (n)
*/
int longestConsecutive1(vector<int>& nums) {

   if (nums.empty()) return 0;  // Handle edge case

    sort(nums.begin(), nums.end());

    int cnt = 1, maxLen = 1;
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] == nums[i - 1]) continue; // Skip duplicates

        if (nums[i] == nums[i - 1] + 1) {
            cnt++;  // Increase count for consecutive numbers
        } else {
            maxLen = max(maxLen, cnt);  // Update max length
            cnt = 1;  // Reset count
        }
    }
    return max(maxLen, cnt); // Ensure the last sequence is counted
}
int longestConsecutive2(vector<int>& nums) {
    if (nums.empty()) return 0;

    unordered_set<int> numSet(nums.begin(), nums.end());
    int longestSub = 0;

    for (int num : numSet) {
        // Start a sequence only if num-1 is not in the set
        if (numSet.find(num - 1) == numSet.end()) {
            int currentNum = num;
            int cnt = 1;

            while (numSet.find(currentNum + 1) != numSet.end()) {
                cnt++;
                currentNum++;
            }

            longestSub = max(longestSub, cnt);
        }
    }
    return longestSub;
}
int main()
{
    int n;
    cin >> n;
    vector<int> nums;
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        nums.push_back(x);
    }
   int ans = longestConsecutive2(nums);
   cout << ans << endl;
    return 0;
}
