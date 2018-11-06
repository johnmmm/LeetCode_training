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

    int removeElement(vector<int>& nums, int val) 
    {
        int size = nums.size();
        if (size == 0)
            return 0;
        int j = 0;
        for (int i = 0; i < size; i++)
        {
            if (nums[i] != val)
            {
                nums[j++] = nums[i];
            }
        }
        return j;
    }
};

int main()
{
    FILE *fp = fopen("./in.txt", "r");
    fread(buf, 1, bufN, fp);

    int n = getint();
    vector<int> arrays1;
    for (int i = 0; i < n; i++)
    {
        arrays1.push_back(getint());
    }
    int m = getint();

    Solution solution;
    double ans = solution.removeElement(arrays1, m);

    printf("%lf\n", ans);

    return 0;
}