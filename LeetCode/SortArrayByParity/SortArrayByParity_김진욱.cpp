#include <iostream>

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int> result;

        for(int i : nums){
            cout << i ;
            if(i % 2== 0){
                result.insert(result.begin() , i);
            } else {
                result.push_back(i);
            }
        }
        return result;
    }
};