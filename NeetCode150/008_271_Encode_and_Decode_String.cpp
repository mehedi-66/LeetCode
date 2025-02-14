#include<bits/stdc++.h>
using namespace std;
/*
Problem Statement:
    Design an algorithm to encode a list of strings to s string the encoded string is then
    sent over the network and is decoded back to the original list of strings

Example:
    S: [ab, b, abc, d]
    E.S: [xxxxxxxxxxxx]
    D.S: [ab, b, abc, d]

Approach 1: use extra character
    S: [ab, b, abc, d]
    E.S: [ab # b # abc# d]
    D.S: [ab, b, abc, d]

    TC: O(n)  and SC: O(1)

Approach 2: adding 4 bits (Intersting)
    S: [ab, b, abc, d]

       ***)  2-> ab -> 0010 (4 bit of 2 binary represetation)
       ***) next 2 element of need to read as substring

    E.S: [0|0|1|0|a|b|0|0|0|1|a|0|0|1|1|a|b|c|0|0|0|1|d]

    D.S: [ab, b, abc, d]


*/

 string encode(vector<string> strs)
{
    if(strs.size() == 0)
    {
        return "";
    }
    string separate = "#";
    string ans = "";
    for(string temp : strs)
    {
        ans += temp + separate;

    }
    return ans;
}
 vector<string> decode(string s)
{
    vector<string> ans;
    string temp = "";
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] == '#')
        {
            ans.push_back(temp);
            temp = "";
            continue;
        }
        else{
            temp.push_back(s[i]);
        }
    }

    return ans;

}
int main()
{
    int n;
    cin >> n;
    vector<string> strs;
    for(int i = 0; i < n; i++)
    {
        string t;
        cin >> t;
        strs.push_back(t);
    }
    vector<string> ans;
    ans = decode(encode(strs));
    for(string t: ans)
    {
        cout << t ;
    }

}
