#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

const int bufN = 10000;
char buf[bufN], *p = buf;

const int maxw = 500001;
const int maxh = 500;
short dp[maxh+1][maxw] = {-1};

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

    int minDp(int a, int b)
    {
        int ans = 0;
        if (a == -1 && b == -1)
            return -1;
        else if (a == -1 && b != -1)
            ans = b;
        else if (a != -1 && b == -1)
            ans = a;
        else
        {
            if (a > b)
                ans = b;
            else
                ans = a;
        }
        if (ans + 1 > 100)
            return -1;
        else
            return ans+1;
    }

    void displaydp(int a, int b)
    {
        for (int i = 0; i <= a; i++)
        {
            for (int j = 0; j <= b; j++)
            {
                printf("%d ", dp[i][j]);
            }
            printf("\n");
        }
    }

    int minDis(string a, string b)
    {   
        int sizea = a.size(), sizeb = b.size();
        // printf("%s\n", a.c_str());
        // printf("%s\n", b.c_str());
        // printf("len: %d %d\n", sizea, sizeb);
        if ((sizea - sizeb > 100) || (sizeb - sizea > 100))
            return -1;

        memset(dp, -1, maxh * maxw * 2);
        for (int i = 0; i < maxh; i++)
            dp[i][0] = i;
        for (int i = 0; i < maxw; i++)
            dp[0][i] = i;
        int h_place = 1;
        int tmpdp = 0;
        int tmpdp_11 = 0, tmpdp_1 = 0;
        for (int i = 1; i <= a.size(); i++)
        {
            if (h_place == maxh+1)
            {
                dp[0][0] = dp[maxh][0];
                for (int j = 1; j < maxh; j++)
                    dp[j][0] = dp[j-1][0] + 1;
                for (int j = 1; j < maxw; j++)
                    dp[0][j] = dp[maxh][j];
                h_place = 1;
            }
            for (int j = 1; j <= b.size(); j++)
            {
                if (a.c_str()[i-1] == b.c_str()[j-1])
                    tmpdp = dp[h_place-1][j-1];
                else
                    tmpdp = minDp(dp[h_place][j-1], dp[h_place-1][j]);
                dp[h_place][j] = tmpdp;

                if (tmpdp == -1 && tmpdp_11 == -1 && tmpdp_1 == -1)
                    break;
            }
            h_place++;
        }
        //displaydp(10, 10);
        return dp[h_place-1][b.size()];
    }

private:
    int num;

};

int main ()
{
    FILE *fp = fopen("./in.txt", "r");
    fread(buf, 1, bufN, fp);

    int num = getint();
    int ans;
    for (int i = 0; i < num; i++)
    {
        Solution solution;
        string a = getstring();
        string b = getstring();
        
        ans = solution.minDis(a, b);
        printf("%d\n", ans);
    }

    return 0;
}