#include <iostream>
#include <vector>

std::vector<int> sortParityArray(std::vector<int>& nums){
    int odds=0, temp;
    for(int i=0; i<nums.size(); i++){
        if(nums[i] % 2 == 0){
            temp = nums[odds];
            nums[odds] = nums[i];
            nums[i] = temp;
            odds++;
        }
    }
    for(int i=0; i<nums.size(); i++){
        std::cout<<nums[i]<<std::endl;
    }
    return nums;
}

int main(){
    std::vector<int> nums = {3,1,2,4};
    sortParityArray(nums);
}