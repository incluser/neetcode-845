# NeetCode 845 Solutions

This repository contains explanations and efficient solutions for 845 problems, documented one by one. I focus primarily on clear, optimal approaches.

---

## 1. Score of a String

We are given a string `s` and asked to compute the sum of the absolute differences between the ASCII values of every pair of adjacent characters.

### Example

**Input**

```text
s = "hello"
```

**Output**

```text
13
```

**Explanation**

The ASCII values are:

- `'h'` → 104
- `'e'` → 101
- `'l'` → 108
- `'l'` → 108
- `'o'` → 111

We then sum the absolute differences of adjacent characters:

|104 - 101| + |101 - 108| + |108 - 108| + |108 - 111| = 3 + 7 + 0 + 3 = 13

### Approach

- Start from index `1` and iterate to the end of the string.
- At each step, add the absolute difference between the current character and the previous character.
- Return the total sum.

### C++ Implementation

```cpp
#include <string>
#include <cmath>

class Solution {
public:
    int scoreOfString(std::string &s) {
        int ans = 0;
        for (size_t i = 1; i < s.length(); i++) {
            ans += std::abs(s[i] - s[i - 1]);
        }
        return ans;
    }
};
```

### Complexity

- **Time complexity:** `O(n)` — we traverse the string once, doing constant work for each pair of adjacent characters.
- **Space complexity:** `O(1)` — we use a fixed number of variables regardless of the input size.

---

## 2. Concatenation of Array

We are given array of integers `nums` and asked to concatenate the array with itself.
Usually i do not prefer to mutate the incoming array so we will create another one.

### Example

**Input**

```text
[1,2,3]
```

**Output**

```text
[1,2,3,1,2,3]
```

### Approach

- Create a result array with size `2 * nums.length()`
- Iterate in loop where `0 <= i < 2 * nums.length()`
- To stay in array range we use `%` operator

### C++ Implementation

```cpp
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
```

### Complexity

- **Time complexity:** `O(2n) -> O(n)` — we iterate double length of array but in terms of BigO its still linear time.
- **Space complexity:** `O(n)` — we allocate additional ans array to not mutate the incoming array.

---

## 3. Contains Duplicate

We are given an array of integers and we have to determine if this array contains duplicate.

### Example

**Input**

```text
[1,2,3,1]
```

**Output**

```text
true
```

### Approach

- We use the data structure set which stores only unique elements. If you try to add duplicate in set, it just will ignore it
- We keep track if current element presents in set
- If so then we have duplicate
- Otherwise all elements in array are unique therefore we return false

### C++ Implementation

```cpp
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
```

### Complexity

- **Time complexity:** `O(n)` — worst case for us when all elements are unique and we check all of them for duplicate
- **Space complexity:** `O(n)` — again we fill our set with all incoming array elements in case where all elements are unique

## 4. Valid anagram

We are given two strings `s` and `t` and our problem is to check if they are anagrams to each other.
Strings `s` and `t` called an `anagram` if `t` is string with same chars as in `s` but might be rearranged

### Example

**Input**

```text
s = "anagram", t = "nagaram"
```

**Output**

```text
true
```

**Input**

```text
s = "hello", t = "eholl"
```

**Output**

```text
true
```

**Input**

```text
s = "school", t = "school"
```

**Output**

```text
true
```

### Approach

- We can sort the string but it will take `O(n logn)` time which is not efficient
- First case they have to have equal length, otherwise we immediately return false
- All characters are lowercase english letters so they are 26 letters total
- We use array of 26 elements initially filled with zeros
- We map each char to his index in array, `a -> 0`, `b -> 1`, ... ,`z -> 25`
- We increment the frequency of char from `s`
- We decremeent the frequency of char from `t`
- In the end if they are really anagrams we should have only zeros in our array and we check it

### C++ Implementation

```cpp
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
```

### Complexity

- **Time complexity:** `O(n)`
- **Space complexity:** `O(26) -> O(1)` — we use array which limited with 26 elements so after all its `O(1)`
