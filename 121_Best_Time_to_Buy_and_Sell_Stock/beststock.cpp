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

    int maxProfit(vector<int>& prices) 
    {
        int size = prices.size();
        if (size == 0 || size == 1)
            return 0;
        
        int ans = 0;
        int tmpmin = prices[0], tmpmax = prices[0];
        for (int i = 1; i < size; i++)
        {
            //printf("ans:%d, max:%d, min:%d\n", ans, tmpmax, tmpmin);
            if (prices[i] < tmpmin)
            {
                if (tmpmax - tmpmin > ans)
                    ans = tmpmax - tmpmin;
                tmpmin = prices[i];
                tmpmax = prices[i];
            }
            else if (prices[i] > tmpmax)
            {
                tmpmax = prices[i];
            }
        }
        if (tmpmax - tmpmin > ans)
            ans = tmpmax - tmpmin;
        return ans;
    }
};

int main()
{
    FILE *fp = fopen("./in.txt", "r");
    fread(buf, 1, bufN, fp);

    int num = getint();
    vector<int> arrays;
    for (int i = 0; i < num; i++)
    {
        arrays.push_back(getint());
    }

    Solution solution;
    int ans = solution.maxProfit(arrays);

    printf("%d\n", ans);

    return 0;
}