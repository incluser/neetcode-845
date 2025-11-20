#include <string>
#include <vector>
#include <unordered_map>
class Solution
{
public:
      bool isAnagram(std::string s, std::string t)
      {
            /* two string with different lengths cant form anagrams */
            if (s.length() != t.length())
            {
                  return false;
            }

            /* since all letters are lowercase we use 26 size array to count them */
            std::vector<int> counter(26, 0);

            /* build frequency histogram which at the end should be zero */
            for (int i = 0; i < s.length(); i++)
            {
                  counter[s[i] - 97]++;
                  counter[t[i] - 97]--;
            }

            bool allZero = true;
            for (int i = 0; i < 26; i++)
            {
                  if (counter[i] != 0)
                  {
                        allZero = false;
                        break;
                  }
            }
            return allZero;
      }
};
