// 95% faster than all C++ submissions!

#include <iostream>

 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

 struct LinkedList{
    ListNode *head = nullptr;
 };



class Solution{
    public:
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2){
            int carry = 0;
            LinkedList ll;
            ListNode *head = ll.head;
            while (true){
                int digitTotal = 0;
                digitTotal += carry;
                if (l1 != nullptr){
                    digitTotal += l1->val;
                    l1 = l1->next;
                }
                if (l2 != nullptr){
                    digitTotal += l2->val;
                    l2 = l2->next;
                }
                carry = 0;
                if (digitTotal > 9){
                    carry = 1;
                    digitTotal -= 10;
                }

                if (ll.head == nullptr){
                    ll.head = new ListNode(digitTotal);
                    head = ll.head;
                }
                else{
                    head->next = new ListNode(digitTotal);
                    head = head->next;
                }
                if (l1 == nullptr && l2 == nullptr){
                    if (carry > 0){
                        head->next = new ListNode(carry);
                    }
                    return ll.head;
                }
            }
        }
};


int main(){
    Solution x;
    ListNode *l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);
    ListNode *l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);
    ListNode *sol = x.addTwoNumbers(l1,l2);
    return 0;
}