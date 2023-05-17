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
    int pairSums(ListNode* head) 
    {
        ListNode* temp = head;
        std::vector<int> vec;
        int size;

        while (temp != nullptr)
        {
            size++;
            vec.push_back(temp->val);
            temp = temp->next;
        }
    }
};

int main()
{
    ListNode* head = new ListNode(5);
    head->next = new ListNode(4);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(3);
    Solution sol;
    sol.pairSums(head);
}