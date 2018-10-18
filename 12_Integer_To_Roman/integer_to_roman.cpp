#include <vector>
#include <string>
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

    string intToRoman(int num)
    {
        string ans = "";
        int tmpnum = num;

        while (tmpnum >= 1000)
        {
            tmpnum -= 1000;
            ans += "M";
        }
        if (tmpnum >= 900)
        {
            tmpnum -= 900;
            ans += "CM";
        }

        while (tmpnum >= 500)
        {
            tmpnum -= 500;
            ans += "D";
        }
        if (tmpnum >= 400)
        {
            tmpnum -= 400;
            ans += "CD";
        }

        while (tmpnum >= 100)
        {
            tmpnum -= 100;
            ans += "C";
        }
        if (tmpnum >= 90)
        {
            tmpnum -= 90;
            ans += "XC";
        }

        while (tmpnum >= 50)
        {
            tmpnum -= 50;
            ans += "L";
        }
        if (tmpnum >= 40)
        {
            tmpnum -= 40;
            ans += "XL";
        }

        while (tmpnum >= 10)
        {
            tmpnum -= 10;
            ans += "X";
        }
        if (tmpnum >= 9)
        {
            tmpnum -= 9;
            ans += "IX";
        }

        while (tmpnum >= 5)
        {
            tmpnum -= 5;
            ans += "V";
        }
        if (tmpnum >= 4)
        {
            tmpnum -= 4;
            ans += "IV";
        }

        while (tmpnum >= 1)
        {
            tmpnum -= 1;
            ans += "I";
        }

        return ans;
    }
};

int main ()
{
    FILE *fp = fopen("./in.txt", "r");
    fread(buf, 1, bufN, fp);

    int num = getint();
    for (int i = 0; i < num; i++)
    {
        int romanint = getint();
        Solution solution;
        string ans = solution.intToRoman(romanint);
        printf("%s\n", ans.c_str());
    } 

    return 0;
}