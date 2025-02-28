#include<bits/stdc++.h>
using namespace std;

/*

121. Best Time to Buy and Sell Stock

    You are given an array prices where prices[i] is the price of a given stock on the ith day.

    You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

    Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

Example 1:

    Input: prices = [7,1,5,3,6,4]
    Output: 5
    Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
    Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.

Example 2:

    Input: prices = [7,6,4,3,1]
    Output: 0
    Explanation: In this case, no transactions are done and the max profit = 0.

Approach 1:
    1) nested loop fix one and rest of them find out maxProfit

    2) TC: O(n^2) and SP: O(1)

Approach 2:
    1) Two pointer first and Forward
    2) if forwared to first dfference negetive then fist move
    3) maxProfit calculate

    4) TC: O(n) and SP: O(1)



*/
int maxProfit(vector<int>& prices) {
     if (prices.size() < 2) return 0; // Edge case

    int left = 0;
    int right = 1;
    int maxProfit = 0;

    while (right < prices.size()) {

            // this condition always true
            // if down  7\1 then difference negative
            // a min 1 value to future all value get a + profit

        if (prices[right] < prices[left]) {
            left = right;  // Move left to the new lowest price
        } else {
            maxProfit = max(maxProfit, prices[right] - prices[left]);
        }
        right++;
    }

    return maxProfit;
}

int main()
{
    int n;
    cin >> n;
    vector<int> v;

    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }

    cout << maxProfit(v);

    return 0;
}
