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

    string convert(string s, int numRows) 
    {
        if (numRows == 1)
            return s;
        int cyclenum = numRows * 2 - 2;
        int size = s.size();
        string ans = "";
        
        for (int i = 0; i < numRows; i++)
        {
            int j = i;
            while (j < size)
            {
                if (i == 0 || i == numRows - 1)
                {
                    ans += s[j];
                    j += cyclenum;
                    continue;
                }
                else
                {
                    ans += s[j];
                    //j = j - (j % cyclenum) + (cyclenum - j % cyclenum);
                    int tmpj = j + cyclenum - 2 * (j % cyclenum);
                    if (tmpj >= size)
                        break;
                    ans += s[tmpj];
                    j += cyclenum;
                }
            }
        }
        return ans;
    }
};

int main ()
{
    Solution solution;
    FILE *fp = fopen("./in.txt", "r");
    fread(buf, 1, bufN, fp);

    int n = getint();
    string str = getstring();
    string ans = solution.convert(str, n);
    printf("%s\n", ans.c_str());

    return 0;
}