#include <string>
class Solution
{
public:
      bool isSubsequence(std::string s, std::string t)
      {
            if (s.length() > t.length())
            {
                  return false;
            }

            int s_pointer = 0;
            for (int i = 0; i < t.length(); i++)
            {
                  if (t[i] == s[s_pointer])
                  {
                        s_pointer++;
                  }
            }
            /* our pointer should come to the end if it is subsequence of t */
            return s_pointer == s.size();
      }
};