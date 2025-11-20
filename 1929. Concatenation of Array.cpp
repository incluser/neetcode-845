#include <vector>
class Solution
{
public:
      std::vector<int> getConcatenation(std::vector<int> &nums)
      {
            /* we need to save original size */
            int size = nums.size();
            int doubleSize = size * 2;
            std::vector<int> ans;
            for (int i = 0; i < doubleSize; i++)
            {
                  /* thanks to % operator our i remains in range 0:size */
                  ans.push_back(nums[i % size]);
            }
            return ans;
      }
};