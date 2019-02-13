#include <vector>
#include <unordered_map>
#include <string>
#include <queue>
using namespace std;

const int bufN = 10000;
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

inline string getstring()
{
    string res;
    while(*p == ' ' || *p == '\n')
        ++p;
    while(*p != ' ' && *p != '\n')
		res += *p++;
    return res;
}

class Solution
{
public:
    Solution(){}

    bool isMatch(string s, string p)
    {
        int s_size = s.size();
        int p_size = p.size();
        bool dp[s_size+1][p_size+1];
        memset(dp, 0, sizeof(bool)*(s_size+1)*(p_size+1));
        dp[s_size][p_size] = true;
        for(int i = s_size; i >= 0; i--)
            for(int j = p_size-1; j >= 0; j--)
        {
            bool firstmatch = (i < s_size && (s[i] == p[j] || p[j] == '.'));
            if (j + 1 < p_size && p[j+1] == '*')
            {
                dp[i][j] = dp[i][j+2] || (firstmatch && dp[i+1][j]);
            }
            else //不是*的情况下
            {
                dp[i][j] = firstmatch && dp[i+1][j+1];
            }
            //printf("now: i:%d, j:%d, bool:%d\n", i, j, dp[i][j]);
        }
        return dp[0][0];
    }

};

int main ()
{
    Solution solution;
    FILE *fp = fopen("./in.txt", "r");
    fread(buf, 1, bufN, fp);

    string s = getstring();
    string p = getstring();
    bool ans = solution.isMatch(s, p);
    printf("%d\n", ans);

    return 0;
}