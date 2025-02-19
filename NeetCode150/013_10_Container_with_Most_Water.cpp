#include<bits/stdc++.h>
using namespace std;

/*
11. Container With Most Water
    You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

    Find two lines that together with the x-axis form a container, such that the container contains the most water.

    Return the maximum amount of water a container can store.

    Notice that you may not slant the container.
Example 1:


    Input: height = [1,8,6,2,5,4,8,3,7]
    Output: 49
    Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.


NOTE: H x W  gives area

Approach 1: Brute Force

        1) First 1st positon fix and make how much Area of container
        2) Nested looping

        3) TC: O(n^2) and SC: O(1)

Approach 2: Two pointer

    1) left and right fix and calculate Area
    2) which ever height is smaller that will be updated

    3) TC: O(n) and SC: O(1)

*/
  int maxArea(vector<int>& height) {
    int left = 0;
    int right = height.size()-1;
    int maxArea = 0;
    while(left < right)
    {
        int area = (min(height[left], height[right])) * (right - left);
        maxArea = max(maxArea, area);
        if(height[left] < height[right])
        {
            left++;
        }
        else{f
            right--;
        }
    }

    return maxArea;

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

    cout << maxArea(height) << endl;
    return 0;
}
