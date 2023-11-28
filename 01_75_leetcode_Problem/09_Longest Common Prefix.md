
## 09 Longest Common Prefix

[Problem Link](https://leetcode.com/problems/longest-common-prefix/description/)


### Problem statement: 
---
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

### Example 1
    Input: strs = ["flower","flow","flight"]
    Output: "fl"
### Example 2
    Input: strs = ["dog","racecar","car"]
    Output: ""
    Explanation: There is no common prefix among the input strings.

### How to think and hint:
---

#### Method 1
Select first or smallest string from given array by sorting *O(nlong)*  then base on selected string Iterate rest of the string common prefix then added to answer worst case Time complexity *O(n^2)* more spacific: *O(length of array * smallest string length)* 
### let's => ["abc", "abcd", "ab", "abc"]
    select: abc

    a => looping => rest like column has common (a) as prefix 
    
    abcd
    ab
    abc

- all the 1,2,3 prefix  --> charater match then added to answer one by one  ---> 
- If any string length overflow then break the loop 


#### Method 2

using Tries structure we can find out longest common prefix <br/>
- All the string insert into Tries
- Root to visit child count 1 the added to answer

-- Time complixity *O(m*n)* and sapce *O(m*n)* coz all string traverse and store into tries 
![alt text](https://media.geeksforgeeks.org/wp-content/uploads/Longest-Common-Prefix-using-Trie.png)

### Write down code
---
### Method 1

```C++
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";

        // take first string 
        for(int i = 0; i < strs[0].size(); i++)
        {
            char ch = strs[0][i];
            bool flag = false;
            for(int j = 0; j < strs.size(); j++)
            {   
            
                // not match and size of current string 
                if(i > strs[j].size() || ch != strs[j][i])
                {
                    flag  = true;
                    break;
                }
            }

            if(flag == false)
            {
                ans.push_back(ch);
            }
            else{
                break;
            }
        }

        return ans;
    }
};

``` 
### Method 2

```C++
#include<bits/stdc++.h>
using namespace std;

class TrieNode{
    public:
        char data;
        TrieNode* children[26];
        int childCount;
        bool isTerminal;

        // constructor  for new node create 
        TrieNode(char ch)
        {
            data = ch;
            for(int i = 0; i < 26; i++)
            {
                children[i] = NULL;
            }
            childCount = 0;
            isTerminal = false;
        }

        
};

class Trie{
    public:
        TrieNode* root;

        Trie(char ch)
        {
            root = new TrieNode(ch);
        }

        void insertUtil(TrieNode* root, string word)
        {
            // base case
            if(word.length() == 0)
            {
                root -> isTerminal = true;
                return ;
            }
      

            // assumption world will be in small
            int index = word[0] - 'a';
            TrieNode* child;

            // present
            if(root-> children[index] != NULL)
            {
                // index based forward to Tree
                child = root->children[index];
            }
            else{
                // absent 
                child = new TrieNode(word[0]);
                root->childCount++;
                root->children[index] = child;
            }

            // recursion 
            insertUtil(child, word.substr(1));
      }

      void insertWord(string word)
      {
          insertUtil(root, word);
      }

      void lcp(string str, string &ans)
      {
          for(int i = 0; i < str.length(); i++)
          {
              char ch = str[i];
              
              // child count 1 or not 
              if(root->childCount == 1)
              {
                  ans.push_back(ch);

                  // go forwoard 
                  int index = ch - 'a';
                  root = root->children[index];
              }
              else{
                  break;
              }

              if(root-> isTerminal)
              {
                  break;
              }
          }
      }
};

string longestCommonPrefix(vector<string> &arr, int n)
{
    Trie *t = new Trie('\0');

    // insert all the string into trie
    for(int i = 0; i < n; i++)
    {
        //connser case:  string size is empty then return ""
        if(arr[i].size() == 0) return "";

        t->insertWord(arr[i]);
    }

    string first = arr[0];
    string ans = "";

    t-> lcp(first, ans);

    return ans;

}

int main()
{
    vector<string> arr = {"abc", "abcd", "abb", "abcc", "abbb"};

    cout << longestCommonPrefix(arr, 5);
}

```


