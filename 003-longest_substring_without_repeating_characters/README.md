# 3. Longest Substring Without Repeating Characters
Given a string `s`, find the length of the **longest substring** without repeating characters.

**Example 1:**
```
Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
```

### Solution
I'm going to use two pointers, both which start at index 0. `ptr_right` which slides up the string and queries each character, and `ptr_left` which follows it up _only_ if a repeat character is encountered. There will be another variable called `longest_substring` which keeps track of the longest substring encountered in the process, and is defined by `ptr_right - ptr_left`

**Procedure**
1. As `ptr_right` moves up the list, we store the character it has encountered in a set.
2. If `ptr_right` reaches a character which is already present in the set, slide `ptr_left` up the string, removing each character it encounteres in the string from the set, until we've removed that repeat character `ptr_right` has encountered. 
3. Each time `ptr_right` moves, compute the length of the current substring, and update `longest_substring` if necessary.

Running and compiling [longest_substring.cpp](longest_substring.cpp) yields the following result:
```
The longest substring of unique letters in "abcabcbb" is 3 character(s) long
The longest substring of unique letters in "bbbbb" is 1 character(s) long
The longest substring of unique letters in "pwwkew" is 3 character(s) long
The longest substring of unique letters in "grapeape" is 5 character(s) long
```


This solution requires O(n) time as it's done in one pass up the string by two pointers, and at worst requires O(n) space to store a "copy" of the string in the `substring_chars` set.