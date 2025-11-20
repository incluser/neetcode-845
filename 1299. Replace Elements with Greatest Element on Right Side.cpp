#include <vector>
#include <cmath>
class Solution
{
public:
      std::vector<int> replaceElements(std::vector<int> &nums)
      {
            /* i hope i can mutate the incoming array */
            int right_max = -1;
            for (int i = nums.size() - 1; i >= 0; i--)
            {
                  int temp = nums[i];
                  nums[i] = right_max;
                  right_max = std::max(right_max, temp);
            }
            return nums;
      }
};