#include<bits/stdc++.h>
using namespace std;
/*
125. Valid Palindrome
    A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

    Given a string s, return true if it is a palindrome, or false otherwise.
Example 1:

    Input: s = "A man, a plan, a canal: Panama"
    Output: true
    Explanation: "amanaplanacanalpanama" is a palindrome.
Example 3:

    Input: s = " "
    Output: true
    Explanation: s is an empty string "" after removing non-alphanumeric characters.
    Since an empty string reads the same forward and backward, it is a palindrome.

Constraints:

    1 <= s.length <= 2 * 105
    s consists only of printable ASCII characters.

Approach 1: reverse str

    1) remove all the non-alphanumaric character
    2) get origianl string
    3) reverse the string

    4) TC: O(n) and SP: O(n)

Approach 2: two pointer
    1) get origianl string
    2) both side match meet in the middle

    3) TC: O(n) or O(n/2)  and SC: O(n)

*/
bool isAlphabet(char ch)
{

    if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9'))
    {
        return true;
    }
    else{
        return false;
    }
}

 bool isPalindrome(string s) {

    string ans;
    for(int i = 0; i < s.size(); i++)
    {
        if(isAlphabet(s[i]))
        {
            if(s[i] >= 'A' && s[i] <= 'Z'){
                ans.push_back((char)(s[i]+32));
            }
            else{
                ans.push_back(s[i]);
            }
        }
    }
    int start = 0;
    int end = ans.size()-1;
    while(start < end)
    {
        if(ans[start] != ans[end])
        {
            return false;
        }
        start++, end--;
    }
    return true;
 }
int main()
{
    string s;
    cin >> s;

    cout << isPalindrome(s);


    return 0;
}
