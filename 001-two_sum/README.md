# 1. Two Sum
Given an array of integers `nums` and an integer `target`, return the _indices of the two numbers such that thye add up to `target`_.  
You may assume that each input would have **exactly one solution**, and you may not use the _same_ element twice.  
You can return the answer in any order.

### Solution
I'm going to use a map as a lookup to find a value's complement while I loop through the list of integers, where the complement will be the key and that value's index will be the value.
- Calculate the values complement - check if the complement exists as a key within the map
- If the complement _does not exist_ as a key in the map, then we know we haven't found our solution yet, update the map using the complement as the key and the index as the value.
- If the complement _does exist_ as a key in the map, we've found our solution. Extract the index using the complement as the key, and return that along with the current index as a vector.

The code in [two_sum.cpp](two_sum.cpp) contains the solution - when submitted to leetcode it runs faster than ~90% of solutions, but is near the top in terms of memory usage. 
