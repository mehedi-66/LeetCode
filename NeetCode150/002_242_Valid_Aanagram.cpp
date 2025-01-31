#include<bits/stdc++.h>
using namespace std;

/*
    Given two strings s and t, return true if t is an
    anagram of s, and false otherwise.

    Example:

      Input: s = "anagram", t = "nagaram"

      Output: true

    Constrains:
        1 <= s.length, t.length <= 5 * 10^4
        s and t consist of lowercase English letters.

Conner case : length are same

    Approach 1:
      *) Sort and looping check each position

      *) Time: O(n Log n) Space: O(1)

    Approach 2:
       *) map or HashSet or 26 arr  and count each letter frequency.

       *) Time O(n) and Space O(26)

*/

bool isAnagram1(string s, string t)
{
    if(s.size() != t.size())
    {
        return false;
    }
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());

    for(int i = 0; i < s.size(); i++)
    {

        if(s[i] != t[i])
        {
            return false;
        }
    }

    return true;
}

bool isAnagram(string s, string t)
{
    if(s.size() != t.size())
    {
        return false;
    }
    int ch[25];
    for(int i = 0; i < 26; i++)
    {
        ch[i] = 0;
    }

    for(int i = 0; i < s.size(); i++)
    {
        int ind = (int)(s[i] - 'a');
        ch[ind]++;
    }
    for(int i= 0; i < t.size(); i++)
    {
        int ind = (int)(t[i] - 'a');
        if(ch[ind] > 0)
        {
            ch[ind]--;
        }
        else{
            return false;
        }
    }
    return true;
}

int main()
{
    string s, t;
    cin >> s >> t;

    cout << isAnagram(s, t) << endl;

    return 0;
}
