#include <vector>

int removeDuplicates(std::vector<int>& nums) 
{
    int* front = &nums[0];
    int currentUnique = nums[0];
    int uniques = 1;
    for (int i=0; i<nums.size(); i++)
    {
        if (nums[i] != currentUnique)
        {
            front++;
            *front = nums[i];
            uniques++;
            currentUnique = nums[i];
        }
    }
    return uniques;
}

int main()
{
    std::vector<int> vec = {1,1,2};
    int k = removeDuplicates(vec);
    int j = 0;
}