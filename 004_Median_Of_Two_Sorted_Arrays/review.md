# 004_Median_Of_Two_Sorted_Arrays

### Johnmmm 2018.11.06

## 思路一

其实就直接遍历就好，复杂度为`O((m+n)/2)`

## 思路二

在这种有序的数组的问题当中，在寻找一个需要确定的值的时候，通常会有`log`的复杂度。

因此本题的思路有，将两端数组分为一长一短，在短的数组里面进行二分查找。

    nums1[0] nums1[1] ... nums1[tmpi-1] | nums1[tmpi] ... nums1[n] 
    nums2[0] nums2[1] ... nums2[tmpj-1] | nums2[tmpj] ... nums1[m]

我们认为nums2是短的一个。为满足条件，选取`tmpi`和`tmpj`，使得`max(nums1[tmpi-1], nums2[tmpj-1]) <= min(nums1[tmpi], nums2[tmpj])` 即可为满足要求的分割。并有公式：`tmpi = (m + n + 1) / 2 - tmpj`。（由于0.5会被去除，因此加一对偶数无影响）

通过这样的方法会得到合理的`tmpi`和`tmpj`，随后分奇偶性讨论得到结果即可。

问题：在选取到两边的时候，有极端情况需要讨论：

* `tmpj`为0或者size2
* `tmpi`为0或者size1