
## 08 Longest Palindromic Substring

[Problem Link](https://leetcode.com/problems/longest-palindromic-substring/)


### Problem statement: 
---
Given a string s, return the longest palindromic substring in s.

### Example 1
    Input: s = "babad"
    Output: "bab"
    Explanation: "aba" is also a valid answer.
### Example 2
    Input: s = "cbbd"
    Output: "bb"

### How to think and hince:
---

#### Method 1
Find all the substring *O(n^2)* and also check each substring isPalindrom or not *O(n)*  then Overal time complexity n . n^2 => *O(n^3)*
### let's => babab
    b
    ba
    bab
    baba
    babab
    ---
    a
    ab
    aba
    --
    --

**bab** check palindrom using two pointer from both side up to middile point OR middle to spread -> bab <- or <-a->

#### Method 2
Center to spread *aba*  <- b -> scan hole array take *O(n)* and Check *O(n)* overall *O(n^2)*  <br>
One conner case we are missing EVEN palindrom bb 

### Write down code
---

```C++
class Solution {
public:

    int expand(string &s, int left, int right)
    {
        while(left >= 0 && right < s.size() && s[left] == s[right])
        {
            left--;
            right++;
        }

        return right-left-1;
    }
    string longestPalindrome(string s) {
      int start = 0, end = 0;

      for(int i = 0; i < s.size(); i++)
      {
          int odd = expand(s, i, i);
          int even = expand(s, i, i+1);

          int len = max(odd, even);

          if(len > end - start)
          {
              start = i - (len-1)/2;
              end = i + len/2;
          }

      }

     string ans = "";

     for(int i = start; i <= end; i++)
     {
         ans.push_back(s[i]);
     }

     return ans;

    }
};

``` 


