#include<bits/stdc++.h>
using namespace std;
 /*
    nums = [1, 3, 2, 4, 3, 5];

    Constraints:

    1 <= nums.length <= 10^5
    -10^9 <= nums[i] <= 10^9

    1) This arr contains any duplicate or not
    2) one or multipule times elements appairs

    Approach 1:
         # fix first element looping rest of them
         # two nested loop

         # Time: O(n^2) and Space: O(1)

    Approach 2:
        # Sort the arr
        # then nearest check arr[i] == arr[i-1]

        # Time: O(n log n) and Space: O(1)

    Approach 3:
       # Set use

       # Time: O(n) and Space: O(n)

    Approach 4:
       # Map<int, int>  use
       # Element already seen before and access them quickly

       # Time: O(n) and Space: O(n)



  NOTE:

    map<int, int> mp;

        *) increasing order
        *) Self balancing BST
        *) search time log(n)

   unordered_map<int, int> mp;

        *) no ordering
        *) Hash Table
        *) search time  O(1) -> Average or O(n) -> Worst Case





 */
 bool containsDuplicate(vector<int>& nums) {
    int n = nums.size();
    map<int, int> mp;
    bool isDuplicate = false;
    for(int i = 0; i < n; i++)
    {
        if(mp[nums[i]] == 0)
        {
            mp[nums[i]]++;
        }
        else{
            isDuplicate = true;
            break;
        }
    }
    return isDuplicate;
}
int main()
{
    vector<int> v;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int x ;
        cin >> x;
        v.push_back(x);
    }

    cout << containsDuplicate(v) << endl;

}
