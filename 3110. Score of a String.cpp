#include <string>
#include <cmath>
class Solution
{
public:
      /* method sums up the ascii difference of adjacent chars */
      int scoreOfString(std::string &s)
      {
            int ans = 0;
            for (size_t i = 1; i < s.length(); i++)
            {
                  /* important, we take absolute difference */
                  ans += abs(s[i] - s[i - 1]);
            }
            return ans;
      }
};