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

    int expandString(int place, string s)
    {
        int len = 0;
        int size = s.size();
        int l, r;

        if (place % 2 == 0)
        {
            len = 1;
            l = place / 2 - 1; 
            r = place / 2 + 1;
        }
        else
        {
            l = place / 2; 
            r = place / 2 + 1;
        }

        while (l >= 0 && r < size)
        {
            if (s[l] == s[r])
            {
                len += 2;
                l--;
                r++;
            }
            else
                break;
        }
        return len;
    }

    string longestPalindrome(string s) 
    {
        int size = s.size();
        if (size == 0)
            return "";
        else if (size == 1)
            return s;
        else
        {
            int maxone = 0;
            string ans = "";
            int ansnum = 0;
            for (int i = 0; i < 2 * size - 1; i++)
            {
                int len = expandString(i, s);
                if (len > maxone)
                {
                    maxone = len;
                    ansnum = i;
                }
            }

            //这个根据奇偶性写一下
            if (ansnum % 2 == 0)
                ans = s.substr(((ansnum / 2) - (maxone - 1) / 2), maxone);
            else
                ans = s.substr((ansnum / 2 - maxone / 2 + 1), maxone);
            return ans;
        }
    }
};

int main ()
{
    Solution solution;
    FILE *fp = fopen("./in.txt", "r");
    fread(buf, 1, bufN, fp);

    int n = getint();
    string str = getstring();
    string ans = solution.longestPalindrome(str);
    printf("%s\n", ans.c_str());

    return 0;
}