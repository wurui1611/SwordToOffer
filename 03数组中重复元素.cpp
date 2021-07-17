#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

//剑指offer 03 数组中重复的元素
class Solution{
public:
    int duplicateElement(vector<int> &nums){
        //sort
        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); i++){
            if (nums[i] == nums[i - 1]) return nums[i];
        }
        return -1;

        //hashmap
        unordered_map <int, int> nMap;
        for (auto data:nums) ++nMap[data];
        for (auto data:nums){
            if (nMap[data] > 1) return data;
        }
        return -1;

        //set
        unordered_set <int> nSet;
        for (auto data:nums){
            if (nSet.count(data) == 1) return data;
            else nSet.insert(data);
        }
        return -1;
        
        //element and index
        for(int i = 0; i < nums.size(); i++){
            while(nums[i] != i){// keypoint
                if(nums[i] == nums[nums[i]]) return nums[i];
                swap(nums[i], nums[nums[i]]);
            }
        }
        return -1;

        //..remove specific number
        int val = 1, j = 0;
        for (size_t i = 0; i < nums.size(); ++i) {
            if (nums[i] != val) {
                nums[j] = nums[i];

                ++j;

            }
        }

        return j;
    }
};