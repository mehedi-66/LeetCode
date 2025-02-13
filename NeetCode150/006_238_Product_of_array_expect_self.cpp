#include<bits/stdc++.h>
using namespace std;
/*

Problem Statement:
    Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

    The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

    You must write an algorithm that runs in O(n) time and without using the division operation.

Example 1:

    Input: nums = [1,2,3,4]
    Output: [24,12,8,6]

Example 2:

    Input: nums = [-1,1,0,-3,3]
    Output: [0,0,9,0,0]

Constraints:

    2 <= nums.length <= 10^5
    -30 <= nums[i] <= 30

Approach 1:
    1) [1] [arr] [1] cumulative product can solve this <- arr[i] ->
    2) previously cumulative product generate
    3) Back to cumulative product gives ans of CumProduct[....... 1]

    3) TC: O(n)  SC: O(n)

Approach 2:
    1)
    2)

    3)

*/
 vector<int> productExceptSelf(vector<int>& nums) {
    vector<int> ans;
    vector<int> prodSufix;
    prodSufix.push_back(1);
    int currPrefix = 1;
    int currsufix = 1;
    for(int i = nums.size()-1; i > 0; i--)
    {
        currsufix = currsufix * nums[i];
        prodSufix.push_back(currsufix);
    }

    int sufixInd = prodSufix.size()-1;

    for(int i = 0; i < nums.size(); i++)
    {
       int ans1 =  currPrefix * prodSufix[sufixInd--];
         currPrefix = currPrefix * nums[i];
        ans.push_back(ans1);
    }

    return ans;
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
    vector<int> ans;
    ans = productExceptSelf(nums);
    for(int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}
