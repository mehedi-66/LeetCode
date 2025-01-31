#include<bits/stdc++.h>
using namespace std;

/*
Problem Statement:

    Given an array of strings strs, group the anagrams together.
    You can return the answer in any order.

Exmaple:

    Input: strs = ["eat","tea","tan","ate","nat","bat"]

    Output: [["bat"],["nat","tan"],["ate","eat","tea"]]

Constrains:
    1 <= strs.length <= 10^4
    0 <= strs[i].length <= 100
    strs[i] consists of lowercase English letters.

Approach 1:
    *) B.F search
    *) select one and try similar exit of not each eatration

    *) TC: O(n^2) SC: O(n) to store that

Approach 2:
    *) map and unorderMap sorted base string as key like [aet] => holdes [ate, eat, tea]

    *) TC: O(n log n * k) SC: O(n)

Approach 3:
     *) 26 Characters
     *) create a 26 alphabet key inside hasmap
     *) eficient approach
     *) letter frequency count and match of any instead of sorting
     *) love babbar

     ABC
     S: 111000000000000 as key
     Hasmap [s] => list of similar org-string can generate same key they are anagram of each other

*/
vector<vector<string>> groupAnagrams(vector<string>& strs) {

    unordered_map<string, vector<string>> mp;
    vector<vector<string>> ans;

    for(int i = 0; i < strs.size(); i++)
    {
        string s = strs[i];
        sort(s.begin(), s.end());
        mp[s].push_back(strs[i]);
    }

    for(auto it = mp.begin(); it != mp.end(); it++)
    {
        ans.push_back(it->second);
    }
    return ans;
}
// writing code nice way
vector<vector<string>> groupAnagrams1(vector<string>& strs) {

   unordered_map<string, vector<string>> mp;
    vector<vector<string>> ans;

    for(const string& str : strs) {
        string s = str;
        sort(s.begin(), s.end()); // Sorting the string to use as a key
        mp[s].push_back(str);
    }

    for(const auto& pair : mp) {
        ans.push_back(pair.second);
    }

    return ans;
}
int main()
{

    vector<string> strs;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        strs.push_back(s);
    }
    vector<vector<string>> ans;
   ans = groupAnagrams(strs);

   for(int i = 0; i < ans.size(); i++)
   {

       for(int j = 0; j < ans[i].size(); j++)
       {
           cout << ans[i][j] << " ";
       }
       cout << endl;
   }
   /*
    for (const auto& group : ans) {
        for (const auto& word : group) {
            cout << word << " ";
        }
        cout << endl;
    }
 */
    return 0;
}
