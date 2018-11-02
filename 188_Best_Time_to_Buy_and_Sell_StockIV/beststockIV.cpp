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

    int minone (int a, int b)
    {
        if (a < b)
            return a;
        return b;
    }

    int maxProfit(int k, vector<int>& prices) 
    {
        int size = prices.size();
        if (size == 0 || size == 1)
            return 0;
        
        int ans = 0;

        //dp;

        int kk = min(k, size);
        int dp[size+1];
        int tmpmax[kk+1];

        //init
        for (int i = 0; i <= kk; i++)
        {
            tmpmax[i] = -prices[0];
        }
        for (int i = 0; i <= size; i++)
            dp[i] = 0;

        int lastdp = 0;
        for (int i = 1; i <= kk; i++)
        {
            for (int j = 1; j <= size; j++)
            {
                tmpmax[i] = maxone(tmpmax[i], lastdp - prices[j-1]);
                lastdp = dp[j];
                dp[j] = maxone(dp[j-1], prices[j-1] + tmpmax[i]);
                //printf("i: %d, j: %d, dp: %d \n", i, j, dp[i][j]);
            }
        }
        ans = dp[size];

        return ans;
    }
};

int main()
{
    FILE *fp = fopen("./in.txt", "r");
    fread(buf, 1, bufN, fp);

    int num = getint();
    int k = getint();
    vector<int> arrays;
    for (int i = 0; i < num; i++)
    {
        arrays.push_back(getint());
    }

    Solution solution;
    int ans = solution.maxProfit(k, arrays);

    printf("%d\n", ans);

    return 0;
}