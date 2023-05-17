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
    ListNode* swapPairs(ListNode* head) 
    {
        if (head == nullptr || head->next == nullptr)
            return head;

        ListNode* first = head;
        ListNode* second = first->next;
        ListNode* prev = nullptr;

        if (second != nullptr)
            head = second;

        while (second != nullptr)
        {
            ListNode* temp = second->next;
            first->next = temp;
            second->next = first;

            if (prev != nullptr)
                prev->next = second;

            prev = first;

            if (first->next != nullptr)
                second = first->next->next;
            else
                break;

            first = first->next;
        }
        return head;
    }
};

int main()
{
    // ListNode* head = new ListNode(1);
    ListNode* head = nullptr;
    // head->next = new ListNode(2);
    // head->next->next = new ListNode(3);
    // head->next->next->next = new ListNode(4);
    Solution sol;
    sol.swapPairs(head);
}