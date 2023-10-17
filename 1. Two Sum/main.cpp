#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::vector<int>::iterator it;
        std::vector<int> output;
        for(int i=0; i<nums.size(); i++)
        {
            it = std::find(nums.begin(), nums.begin()+i, nums[i]);
            if(it != nums.begin()+i)
            {
                output.push_back(static_cast<int>(it-nums.begin()));
                output.push_back(i);
                return output;
            }
            else
            {
                nums[i] = target - nums[i];
            }
        }
        return output;
    }
};

int main(int argc, char** argv)
{
    std::vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    Solution sol;
    std::vector<int> output = sol.twoSum(nums, target);
    std::cout << "[" << output[0] << "," << output[1] << "]" << std::endl; 
}