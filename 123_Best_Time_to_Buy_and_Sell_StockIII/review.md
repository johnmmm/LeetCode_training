# 123_Best_Time_to_Buy_and_Sell_StockIII

### Johnmmm 2018.11.02

## 思路

本题需要动归了，一个简单的思路就是：

`dp[i][j] = max(dp[i][j-1], dp[i-1][k-1]+prices[j]-prices[k](0<k<=j))`

解释为在用i个transaction的情况下，前j天最好的结果为`dp_ij`。

因此每一个就相当于，今天不买（跟上一天一样），或者是上一个最好结果在买一个到今天卖掉。二者取大。

##### 用到的优化：

由于这样每次有一个0-j的遍历，因此复杂度不是很理想，将新搞出来的带`k`的部分去除，变成`tmpmax_k`，则有：

`tmpmax[i] = max(tmpmax[i], dp[i-1][j-1]-prices[j])`
`dp[i][j] = max(dp[i][j-1], prices[j]+tmpmax[i])`

##### 需要注意的问题：

`tmpmax`需要初始化，否则其在第一个式子中会取0，然后在第二个式子中的意思变为一上来用0买进了。初始化为`-prices[0]`。