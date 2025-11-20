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

      /* follow up part with case when string comes with unicode symbols */
      bool isAnagramUnicode(std::u32string s, std::u32string t)
      {
            if (s.length() != t.length())
            {
                  return false;
            }
            /* we assume the input is represented as std::u32string, which is a sequence of char32_t. Each char32_t is a single, unambiguous Unicode code point */
            std::unordered_map<char32_t, int> counter;

            for (size_t i = 0; i < s.length(); i++)
            {
                  counter[s[i]]++;
                  counter[t[i]]--;
            }

            bool allZero = true;
            for (const auto &pair : counter)
            {
                  if (pair.second != 0)
                  {
                        allZero = false;
                        break;
                  }
            }
            return allZero;
      }
};
