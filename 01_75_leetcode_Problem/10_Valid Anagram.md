
## 10 Valid Anagram


[Problem Link](https://leetcode.com/problems/valid-anagram/description/)


### Problem statement: 
---
Given two strings s and t, return true if t is an anagram of s, and false otherwise.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters **exactly once**.

### Example 1
    Input: s = "anagram", t = "nagaram"
    Output: true
### Example 2
    Input: s = "rat", t = "car"
    Output: false

## Constraints:
    1 <= s.length, t.length <= 5 * 104
    s and t consist of lowercase English letters.
 
### How to think and hint:
---

#### Method 1
Using map store occurance of charater then if we can make second str from mp then okay
*1 (s) or 2 (t) Map depend on your Implementation* 

    S map                  T map
    __________           ___________
    a   3                 a    3
    n   1                 n    1
    g   1                 g    1
    r   1                 r    1
    m   1                 m    1

<br/>

    Time Complexity : O(N)
    Space Complexity: O(26)  

#### Method 2
We can sort both of the string and compaire each other if( s == t) true or false

    s = aaagmnr
    t = aaagmnr

<br/>

    Time Complexity : O(N log N)
    Space Complexity: O(1)   sometimes sort algo take O(n) spance


### Write down code
---

### Method 1   using  map

```C++
class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char, int> mp;

        // if length of both string not same 
        if(s.size() != t.size()) return false;
        
        // count occurance
        for(int i = 0; i < s.size(); i++)
        {
            mp[s[i]]++;
        }

        // second str can we from by similar charater or not
        for(int i = 0; i < t.size(); i++)
        {
            int x = mp[t[i]];
            if(x > 0 )
            {
                mp[t[i]]--;
            }
            else{
                return false;
            }
        }

        return true;
    }
};

``` 


### Method 2 using sort 

```C++
class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        if(s == t)
        {
            return true;
        }
        else{
            return false;
        }
    }
};

```