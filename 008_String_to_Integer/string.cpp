#include <vector>
#include <unordered_map>
#include <string>
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

    int getInt(string str, int minus)
    {
        int p = 0;
        int size = str.size();
        int MAXN = 2147483647;
        int MINN = -2147483648;
        if (str.c_str()[p] < 48 || str.c_str()[p] > 57)
            return 0;
        int res = 0;
        while (str.c_str()[p] > 47 && str.c_str()[p] < 58 && p < size)
        {
            if (minus == 0)
            {
                int tmpres = res * 10 + str.c_str()[p] - 48;
                int changeres = (tmpres - str.c_str()[p] + 48) / 10;
                //printf("res: %d, changeres: %d\n", res, changeres);
                if (res != changeres || tmpres < 0)
                {
                    res = MAXN;
                    break;
                }
                res = tmpres;
                p++;
            }
            else if (minus == 1)
            {
                int tmpres = res * 10 - (str.c_str()[p] - 48);
                int changeres = (tmpres + str.c_str()[p] - 48) / 10;
                if (res != changeres || tmpres > 0)
                {
                    res = MINN;
                    break;
                }
                res = tmpres;
                p++;
            }
        }
        return res;
    }

    int myAtoi(string str) 
    {
        int size = str.size();
        if (size == 0)
            return 0;
        while (str.c_str()[0] == ' ')
            str = str.substr(1);
        size = str.size();
        if (size == 0)
            return 0;

        int minus = 0;
        while (str.c_str()[0] == '-' || str.c_str()[0] == '+')
        {
            if (str.c_str()[0] == '-')
            {
                minus = !minus;
                str = str.substr(1);
            }
            else if (str.c_str()[0] == '+')
            {
                minus = minus;
                str = str.substr(1);
            }
        }
        if (size == 0)
            return 0;  

        int ans = getInt(str, minus);
        return ans;
    }
};

int main ()
{
    Solution solution;
    FILE *fp = fopen("./in.txt", "r");
    fread(buf, 1, bufN, fp);

    //int n = getint();
    string str = getstring();
    int ans = solution.myAtoi(str);
    printf("%d\n", ans);

    return 0;
}