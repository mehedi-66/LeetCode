
## 2. Best Time to Buy and Sell Stock


[Problem Link](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/)


### Problem statement: 
---
You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

### Example 1
    
    Input: prices = [7,1,5,3,6,4]
    Output: 5
    Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
    Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.
### Example 2

    Input: prices = [7,6,4,3,1]
    Output: 0
    Explanation: In this case, no transactions are done and the max profit = 0.

## Constraints:
    
    1 <= prices.length <= 105
    0 <= prices[i] <= 104
 

### How to think and hint:
---

#### Method 1

We Think like a graph The price up and down <br/>
We need to apply two pointer approach *Left* and *Right* <br/>
when left price is greater then Right then move left pointer by right <br/>
else calculate maxProfit <br/>
move right pointer by one 

<br/>

    Time Complexity : O(n)  
    Space Complexity: O(1)  



### Write down code
---

### Method 1

```C++
   class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        int left = 0;
        int right = 0;
        while(left <= right && right < prices.size())
        {
            if(prices[left] > prices[right])
            {
                left = right;
            }
            else{
                maxProfit = max(maxProfit, prices[right] - prices[left]);
            }

            right++;
            
        }

        return maxProfit;
    }
};
```

