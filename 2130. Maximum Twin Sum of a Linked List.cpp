/*
* Beats 47.95% in speed
* Beats 36.66% in memory
*/

#include <vector>
// Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    int pairSum(ListNode* head) 
    {
        ListNode* temp = head;
        std::vector<int> vec;

        while (temp != nullptr)
        {
            vec.push_back(temp->val);
            temp = temp->next;
        }
        int max = 0;
        int n = vec.size();
        for (int i=0; i<n/2; i++)
        {
            int vecSum = vec[i]+vec[n-i-1];
            if (vecSum > max)
                max = vecSum;
        }
        return max;
    }
};

int main()
{
    ListNode* head = new ListNode(5);
    head->next = new ListNode(4);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(3);
    Solution sol;
    sol.pairSum(head);
}