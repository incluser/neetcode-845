#include <string>

class Solution
{
public:
      /* as same problem as is subsequence */
      int appendCharacters(std::string s, std::string t)
      {
            int t_pointer = 0;
            for (int i = 0; i < s.length(); i++)
            {
                  if (s[i] == t[t_pointer])
                  {
                        t_pointer++;
                  }
            }
            return t.length() - t_pointer;
      }
};