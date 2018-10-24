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

    vector<int> twoSum(vector<int>& nums, int target) 
    {
        vector<int> ret;
        unordered_map<int, int> place_map;

        for (int i = 0; i < nums.size(); i++)
        {
            place_map[nums[i]] = i;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            int tmp = target - nums[i];
            //存在且不是同一个
            if (place_map.count(tmp) > 0 && place_map[tmp] != i)
            {
                ret.push_back(i);
                ret.push_back(place_map[tmp]);//从头开始搜索保证了顺序
                return ret;
            }
        }
        
        return ret;
    }
};

int main()
{
    FILE *fp = fopen("./in.txt", "r");
    fread(buf, 1, bufN, fp);

    int num = getint();
    vector<int> nums;
    vector<int> ans;
    for (int i = 0; i < num; i++)
    {
        nums.push_back(getint());
    }
    int target = getint();

    Solution solution;
    ans = solution.twoSum(nums, target);

    printf("[%d, %d]\n", ans[0], ans[1]);

    return 0;
}