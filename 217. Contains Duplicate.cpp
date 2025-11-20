#include <vector>
#include <unordered_set>
class Solution
{
public:
      bool containsDuplicate(std::vector<int> &nums)
      {
            /* set stores only unique elements */
            std::unordered_set<int> seen;
            /* i find multiple returns as bad statement */
            bool foundDuplicate = false;
            for (int i = 0; i < nums.size(); i++)
            {
                  if (seen.count(nums[i]))
                  {
                        foundDuplicate = true;
                        break;
                  }
                  seen.insert(nums[i]);
            }
            return foundDuplicate;
      }
};