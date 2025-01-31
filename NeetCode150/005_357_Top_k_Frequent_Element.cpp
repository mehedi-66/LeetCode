#include<bits/stdc++.h>
using namespace std;
/*
Problem Statement:
    Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

Example:
    Input: nums = [1,1,1,2,2,3], k = 2
    Output: [1,2]

Constrains:
    1 <= nums.length <= 105
    -104 <= nums[i] <= 104
    k is in the range [1, the number of unique elements in the array].
    It is guaranteed that the answer is unique.


Approach 1:  (Hasmap + sort)
    *) looping and map or unorder_map  increase the frequency of ocurance
    *) the top k ocurance print by looping of map-frequency of array
    *) Sort the frequency array by max ocurance

    *) TC: O(n log n)  and SP: O(n)

Approach 2: (Hasmap + Heap Priority Queue)
    *) hashmap for frequency count
    *) k heap Priority queue of by max ocurance maintain

    *) TC: O(n log k)  and SP: O(n)


*/
vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> mp;
    vector<int> ans;
    for(int i = 0; i < nums.size(); i++)
    {
        mp[nums[i]]++;
    }
    vector<pair<int, int>> freqVec(mp.begin(), mp.end());

   sort(freqVec.begin(), freqVec.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.second > b.second;
    });


    for (int i = 0; i < k; i++) {
        ans.push_back(freqVec[i].first);
    }

    return ans;

}
vector<int> topKFrequent2(vector<int>& nums, int k) {
        // O(1) time
        if (k == nums.size()) {
            return nums;
        }

        // 1. Build hash map: element and how often it appears
        // O(N) time
        unordered_map<int, int> count_map;
        for (int n : nums) {
            count_map[n] += 1;
        }
   //Initialise a heap with the most frequent elements at the top
        auto comp = [&count_map](int n1, int n2) { return count_map[n1] > count_map[n2]; };
        priority_queue<int, vector<int>, decltype(comp)> heap(comp);

        // 2. Keep k top frequent elements in the heap
        // O(N log k) < O(N log N) time
        for (pair<int, int> p : count_map) {
            heap.push(p.first);
            if (heap.size() > k) heap.pop();
        }

        // 3. Build an output array
        // O(k log k) time
        vector<int> top(k);
        for (int i = k - 1; i >= 0; i--) {
            top[i] = heap.top();
            heap.pop();
        }
        return top;

    return ans;

}
int main()
{
    int n, k;
    cin >> n;
    vector<int> nums;
    vector<int> ans;
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        nums.push_back(x);
    }

    cout << "Enter K: ";
    cin >> k;
    ans = topKFrequent(nums, k);
    for(int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}
