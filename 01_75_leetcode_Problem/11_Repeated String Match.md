
## 10 Repeated String Match


[Problem Link](https://leetcode.com/problems/repeated-string-match/)


### Problem statement: 
---
Given two strings *a* and *b*, return the minimum number of times you should repeat string *a* so that string *b* is a substring of it. If it is impossible for *b*​​​​​​ to be *a* substring of a after repeating it, return *-1*.

Notice: string *"abc"* repeated 0 times is *""*, repeated 1 time is *"abc"* and repeated 2 times is *"abcabc"*.

### Example 1
    
    Input: a = "abcd", b = "cdabcdab"
    Output: 3
    Explanation: We return 3 because by repeating a three times "abcdabcdabcd", b is a substring of it.
### Example 2

    Input: a = "a", b = "aa"
    Output: 2

## Constraints:
    
    1 <= a.length, b.length <= 104
    a and b consist of lowercase English letters.
 
### How to think and hint:
---

#### Method 1

We can think First simple case 
*
    a = abcd
    b = cdabcdab

    // First Common pattan of b

    b =>  n*a                    => (abcd)       ===> n
    b => prefix + n*a  + suffix  => cd (abcd) ab ===> n + 2
    b => prefix + n*a            => cd (abcd)    ===> n + 1
    b => n*a + suffix            => (abcd) cd    ===> n + 1


To find out **n** = len(b)/len(a);

<br/>

    Time Complexity : O(na) * O(b)  
    Space Complexity: O(1)  

#### Method 2

we can use KMP algorithm to find out pattarn matching KMP(str1, str2)  here **str1 main** string str2 which we want to search   


### Write down code
---

### Method 1

```C++
class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        
       int len_b = b.length();
       int len_a = a.length();
       
       int n = len_b / len_a;
    
        string na = "";

        int cnt = n;
        while(cnt--)
        {
            na = na + a;
        }

        // N*a case => n
        if(na.find(b) != std::string::npos )
        {
            return n;
        }

        // Prefix + N*a => n + 1; 
        na = na + a;

        if(na.find(b) != std::string::npos)
        {
            return n+1;
        }

        // Prefix + N*a + suffix => n + 2; 
        na = na + a;

        if(na.find(b) != std::string::npos )
        {
            return n+2;
        }

        return -1;

    }
};

``` 


### Method 2
 
 - In case normal pattarn matching algo i & j forward again come back after j complete, here i is outer loop and j in inner loop **Nested** 

 - In case KMP i goes only forward  capter close Now think where j should go back
          

    1Pass

          01 2 i = 3 forward direction
          || |
    str = ab[a]babab
    pat = [a]ba
           
           rest j = 1

    why?

    pat = aba after 1 pass str = aba full match
    then str suffix = a and pat prefix = a now we checking start with b  

    str => length of suffix 
    pat => length of prefix 

    if match is very very important



```C++
class Solution {
public:

    void computeLPS(string str, vector<int> &lps);
    {
        int i = 1;
        int len = 0;
        lps[0] = 0;

        while(i < str.length())
        {
            if(str[i] == str[len])
            {
                len++;
                lps[i] = len;
                i++;
            }
            else{

                if(len != 0)
                {
                    len = lps[len - 1];
                }
                else{
                   lps[i] = 0;
                   i++; 
                }
            }
           
        }
         return ;
    }
    bool KMP(string str, string pat){

        vector<int> lps(pat.length());

        computeLPS(pat, lps);

        int i = 0;
        int j = 0;

        while(i < str.length())
        {
            if(str[i] == pat[j])
            {
                i++;
                j++;
            }
            else{
                if(j != 0)
                {
                    j = lps[j-1];
                }
                else{
                    i++;
                }
            }
        }
    }


    int repeatedStringMatch(string a, string b) {
        
       int len_b = b.length();
       int len_a = a.length();
       
       int n = len_b / len_a;
    
        string na = "";

        int cnt = n;
        while(cnt--)
        {
            na = na + a;
        }

        // N*a case => n
        if(KMP(na, b))
        {
            return n;
        }

        // Prefix + N*a => n + 1; 
        na = na + a;

        if(KMP(na, b))
        {
            return n+1;
        }

        // Prefix + N*a + suffix => n + 2; 
        na = na + a;

        if(KMP(na, b))
        {
            return n+2;
        }

        return -1;

    }
};

```