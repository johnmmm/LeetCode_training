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

    int removeDuplicates(vector<int>& nums) 
    {
        int size = nums.size();
        if (size == 0)
            return 0;
        int ans = 0;
        for (int i = 1; i < size; i++)
        {
            if (nums[i] == nums[ans])
            {
                if (i == 1)
                    ans++;
                else
                {
                    if (nums[i] != nums[ans-1])
                    {
                        ans++;
                        nums[ans] = nums[i];
                    }
                }
            }
            if (nums[i] != nums[ans])
            {
                ans++;
                nums[ans] = nums[i];
            }
                
        }
        ans++;

        return ans;
    }
};

int main()
{
    FILE *fp = fopen("./in.txt", "r");
    fread(buf, 1, bufN, fp);

    int num = getint();
    vector<int> arrays;
    for (int i = 0; i < num; i++)
    {
        arrays.push_back(getint());
    }

    Solution solution;
    int ans = solution.removeDuplicates(arrays);

    printf("%d\n", ans);

    return 0;
}