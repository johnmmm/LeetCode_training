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

    int lengthOfLongestSubstring(string s) 
    {
        int num = strlen(s.c_str());
        if (num == 0)
            return 0;
        else if (num == 1)
            return 1;
        else
        {
            int ans = 0;
            int char_table[128] = {-1};
            for (int i = 0; i < 128; i++)
                char_table[i] = -1;
            char_table[s.c_str()[0]] = 0;

            int begin = 1, end = 0;
            while (begin < s.length())
            {
                //printf("%d\n", ans);
                if (char_table[s.c_str()[begin]] >= end)
                {
                    if (begin - end > ans)
                        ans = begin - end;
                    end = char_table[s.c_str()[begin]] + 1;
                }
                char_table[s.c_str()[begin]] = begin;

                begin++;
            }
            if (begin - end > ans)
                ans = begin - end;

            return ans;
        }
    }
};

int main ()
{
    Solution solution;
    FILE *fp = fopen("./in.txt", "r");
    fread(buf, 1, bufN, fp);

    string tmp = getstring();
    printf("%s\n", tmp.c_str());
    int result = solution.lengthOfLongestSubstring(tmp);
    printf("%d\n", result);

    return 0;
}