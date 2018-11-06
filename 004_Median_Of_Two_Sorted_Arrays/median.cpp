#include <vector>
#include <unordered_map>
using namespace std;

const int bufN = 1000;
char buf[bufN], *p = buf;

inline int getint()
{
	while (*p < 48 || *p > 57)
		++p;

	int res = 0;
	while (*p > 47 && *p < 58)
		res = res * 10 + *p++ - 48;
	return res;
}

class Solution 
{ 
public:
    Solution(){}

    int maxone(int a, int b)
    {
        if (a > b)
            return a;
        return b;
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
    {
        int size1 = nums1.size();
        int size2 = nums2.size();
        double ans = 0.0;
        if (size1 == 0 && size2 == 0)
            return 0.0;

        else if (size1 == 0 && size2 != 0)
        {
            if (size2 % 2 == 0)
            {
                int tmp = size2 / 2;
                ans = (nums2[tmp-1] + nums2[tmp]) / 2.0;
            }
            else
            {
                int tmp = (size2 - 1) / 2;
                ans = (double)nums2[tmp];
            }
        }       
        else if (size1 != 0 && size2 == 0)
        {
            if (size1 % 2 == 0)
            {
                int tmp = size1 / 2;
                ans = (nums1[tmp-1] + nums1[tmp]) / 2.0;
            }
            else
            {
                int tmp = (size1 - 1) / 2;
                ans = (double)nums1[tmp];
            }
        } 

        else
        {
            if (size1 < size2)
                nums1.swap(nums2);
            size1 = nums1.size();
            size2 = nums2.size();
            printf("size1: %d, size2: %d\n", size1, size2);
            int l = 0, r = size2;
            int tmpj = 0, tmpi = 0, tmphalf = (size2 + size1 + 1) / 2, tmpiseven = (size1 + size2) % 2;
            printf("tmpeven: %d\n", tmpiseven);

            //直接判断是不是需要上下接
            if (nums1[size1-1] <= nums2[0])
            {
                if (size1 == size2)
                    ans = (nums1[size1-1] + nums2[0]) / 2.0;
                else
                {
                    tmpj = 0;
                    tmpi = tmphalf - tmpj;
                    printf("tmpi: %d, tmpj: %d, ans:%d\n", tmpi, tmpj, nums1[tmpj-1]);
                    if (tmpiseven == 0)
                        ans = (nums1[tmpi-1] + nums1[tmpi]) / 2.0;
                    else
                        ans = nums1[tmpi-1];
                }
            }
            else if (nums1[0] >= nums2[size2-1])
            {
                if (size1 == size2)
                    ans = (nums1[0] + nums2[size2-1]) / 2.0;
                else
                {
                    tmpj = size2;
                    tmpi = tmphalf - tmpj;
                    if (tmpiseven == 0)
                        ans = (nums1[tmpi-1] + nums1[tmpi]) / 2.0;
                    else
                        ans = nums1[tmpi-1];   
                }
            }
            else
            {
                while (l <= r)
                {
                    tmpj = (l + r + 1) / 2;
                    printf("l:%d, r:%d, tmpj:%d\n", l, r, tmpj);
                    tmpi = tmphalf - tmpj;
                    if (tmpj == size2)
                    {
                        if (max(nums1[tmpi-1], nums2[tmpj-1]) <= nums1[tmpi])
                        {
                            if (tmpiseven == 0)
                                ans = (max(nums1[tmpi-1], nums2[tmpj-1]) + nums1[tmpi]) / 2.0;
                            else
                                ans = max(nums1[tmpi-1], nums2[tmpj-1]);
                            break;
                        }
                        else
                        {
                            r = tmpj - 1;
                            continue;
                        }
                    }
                    else if (tmpj == 0)
                    {
                        if (tmpiseven == 0)
                            ans = (nums1[tmpi-1] + min(nums1[tmpi], nums2[tmpj])) / 2.0;
                        else
                            ans = nums1[tmpi-1];
                        break;
                    }
                    //开始对比大小
                    if (max(nums1[tmpi-1], nums2[tmpj-1]) <= min(nums1[tmpi], nums2[tmpj]))
                    {
                        if (tmpiseven == 0)
                            ans = (max(nums1[tmpi-1], nums2[tmpj-1]) + min(nums1[tmpi], nums2[tmpj])) / 2.0;
                        else
                            ans = max(nums1[tmpi-1], nums2[tmpj-1]);
                        break;
                    }
                    else
                    {
                        if (nums2[tmpj-1] > nums1[tmpi])
                        {
                            if (r - l == 1)
                                r = tmpj - 1;
                            else
                                r = tmpj;
                        }   
                        else
                            l = tmpj;
                    }
                }
            }
        }

        return ans;
    }
};

int main()
{
    FILE *fp = fopen("./in.txt", "r");
    fread(buf, 1, bufN, fp);

    int n = getint(), m = getint();
    vector<int> arrays1;
    vector<int> arrays2;
    for (int i = 0; i < n; i++)
    {
        arrays1.push_back(getint());
    }
    for (int i = 0; i < m; i++)
    {
        arrays2.push_back(getint());
    }

    Solution solution;
    double ans = solution.findMedianSortedArrays(arrays1, arrays2);

    printf("%lf\n", ans);

    return 0;
}