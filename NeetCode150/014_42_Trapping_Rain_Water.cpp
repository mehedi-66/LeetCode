#include<bits/stdc++.h>
using namespace std;

/*
42. Trapping Rain Water
    Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

Example 1:

    Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
    Output: 6
    Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.

Example 2:

    Input: height = [4,2,0,3,2,5]
    Output: 9


Approach 1:
    1) 1 0 2  => min(Rh, Lh) - currentH > 0 then possible to have some water
    2) any given position to find left max and right max height then calculate the amount of water for current position
    3) take two array left max array and right max array from one read of array
    4) then left and right max goes and calculate the array
    3) TC: O(n^2) and SC: O(2n)


*/
int trap(vector<int>& height) {

    vector<int> lMax(height.size());
    vector<int> rMax(height.size());
    int lMaxV = 0;
    int rMaxV = 0;
    for(int i = 0, j = height.size()-1; i < height.size(); i++, j--)
    {
        lMaxV = max(height[i], lMaxV);
        rMaxV = max(height[j], rMaxV);
        lMax[i] = lMaxV;
        rMax[j] = rMaxV;
    }

    int ans = 0;
    for(int i = 0; i < height.size(); i++)
    {
        if((min(lMax[i], rMax[i])-height[i])>0)
        {
            ans += (min(lMax[i], rMax[i])-height[i]);
        }
    }
    return ans;
}

int main()
{

    int n;
    cin >> n;
    vector<int> height;
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        height.push_back(x);
    }
    cout << trap(height) << endl;
    return  0;
}
