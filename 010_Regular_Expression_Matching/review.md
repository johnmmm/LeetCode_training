# 010_Regular_Expression_Matching

### Johnmmm 2019.02.13

## 思路

首先这个题不能使用一顺的思路去做，原因就是，他存在一个`*`这个特殊的东西。`*`这种东西它既可以代表0个字母，也可以代表多个字母。而且，存在一个`.`可以代表任何的字母，因此一个字符串，就可以写很多很多不同的匹配式出来，甚至连字母都不一样。因此在进行是否匹配的判定的时候，就不能直接去试，需要使用动归的方法去试最好的匹配方法。

首先使用dp数组进行存储动态规划。由于是进行匹配，需要逐个字母确定它是否匹配，因此从最后一个字母一个一个退去是最好的思路。就算要自顶向下，但是思考起来，还是要向后推求出后面的时候匹配先。因此这个思路总的来说就是从后往前想。

方法为分类讨论：

* 讨论处理`*`的情况
* 讨论处理正常的情况，

在讨论正常的情况的时候，一般就是字符串和匹配式的字母是否匹配，因此有了`firstmatch`，`firstmatch=(i<s_len)&&(s[i]==p[j]||p[j]=='.')`，在不是最后一个字符的情况下，能够匹配上，如果上一个字母和匹配也能匹配上就可以了，因此为`firstmatch&&dp[i+1][j+1]`。

在讨论`*`的情况的时候，需要考虑`*`为0或者为多个的两种情况，因此是个或的关系。为0的情况下由`dp[i][j+2]`得到，就当没有这个`*`；多个的情况下为`firstmatch&&dp[i+1][j]`，如果当前匹配且上一个可以它就可以。

与此同时，在进行`*`处理的时候需要注意判定：`j+1<p_len&&p[j+1]=='*'`，需要p数组够且后面一个是`*`。

最后注意一下开始初始化为0，其余的就没有问题了。