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

    string numToOneWords[20] = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven",
                        "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", 
                        "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    string numToTenWords[10] = {"???", "???", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", 
                        "Seventy", "Eighty", "Ninety"};
    string hundredWord = "Hundred";
    string thousandWord = "Thousand";

    string numberToBillion(int num)
    {
        string ans = "";
        if (num == 0)
            return ans;
        return numberToOne(num) + " Billion";
    }

    string numberToMillion(int num)
    {
        string ans = "";
        if (num == 0)
            return ans;
        return numberToOne(num) + " Million";
    }

    string numberToThousand(int num)
    {
        string ans = "";
        if (num == 0)
            return ans;
        return numberToOne(num) + " Thousand";
    }

    string numberToOne(int num)
    {
        string ans = "";
        if (num == 0)
            return ans;
        int tmpnum = num;
        int lastTwo = tmpnum % 100;

        if (lastTwo == 0)
            ans = "";
        else if (lastTwo <= 19)
            ans = numToOneWords[lastTwo];
        else
        {
            if (lastTwo % 10 > 0)
                ans = numToTenWords[lastTwo / 10] + " " + numToOneWords[lastTwo % 10];
            else
                ans = numToTenWords[lastTwo / 10];
        }

        tmpnum /= 100;
        int hundredPlace = tmpnum % 10;
        string hundredAns = numToOneWords[hundredPlace];

        if (hundredAns == "")
            return ans;
        else if (ans == "")
            return hundredAns + " Hundred";
        else
            return hundredAns + " Hundred " + ans;
    }

    string numberToWords(int num)
    {
        string ans = "";
        if (num == 0)
            return "Zero";
        int tmpnum = num;
        int thousandNum = 0;

        thousandNum = tmpnum % 1000;
        tmpnum /= 1000;
        ans += numberToOne(thousandNum);

        //空格由每个函数补
        thousandNum = tmpnum % 1000;
        tmpnum /= 1000;
        string thousandPart = numberToThousand(thousandNum);

        thousandNum = tmpnum % 1000;
        tmpnum /= 1000;
        string millionPart = numberToMillion(thousandNum);

        thousandNum = tmpnum % 1000;
        string billionPart = numberToBillion(thousandNum);

        if (thousandPart == "")
            ans = ans;
        else if (ans == "")
            ans = thousandPart;
        else
            ans = thousandPart + " " + ans;

        if (millionPart == "")
            ans = ans;
        else if (ans == "")
            ans = millionPart;
        else
            ans = millionPart + " " + ans;

        if (billionPart == "")
            ans = ans;
        else if (ans == "")
            ans = billionPart;
        else
            ans = billionPart + " " + ans;

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
        string ans = solution.numberToWords(romanint);
        printf("%s\n", ans.c_str());
    } 

    return 0;
}