#include <iostream>
#include <map>
#include <vector>

using std::vector;
using std::map;

class Solution {
    public:
    vector<int> twoSum(vector<int>& nums, int target) {

        map<int, int> complement_container;
        int vect_length = nums.size();
        int complement, x, y;
        
        for (int i = 0; i < vect_length; i++) {
            complement = target - nums[i];
            if (complement_container.find(complement) == complement_container.end()) {
                complement_container.insert({nums[i], i});
            }
            else {
                x = i;
                y = complement_container.at(complement);
                break;
            }
        } 
        return {x, y};
    }
};

int main () {
    return 0;
}