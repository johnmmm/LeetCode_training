# 21_Merge_Two_Sorted_List

### Johnmmm 2018.10.24

## 思路

组装一个新的链表

## 问题

这个题的问题不在于写答案，而是在于如何在自己的机子上面测试这个程序。。。

学习到了关于指针的复制规律，之前对于指针的感知理解完全错误。。。对于相等就是完全复制，带*就是复制内容理解正确，但是却错误的认为用带*的语句来`*pointer = *pointer->next`是正确的，实际上这是一种破坏性的阅读，并且每次都要复制一大堆东西，对于很大的结构体来说浪费时间。

## 思考题

如何在自己的机子里面获得程序栈里面搞出来的指针指向的结构体，以及学习评测机是怎么搞出来的。
