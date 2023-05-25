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
    ListNode *frontPointer;
    
    bool recursiveCheck(ListNode* node){
        if(node != nullptr){
            if(!recursiveCheck(node->next))
                return false;
            if(node->val != frontPointer->val) 
                return false;
            frontPointer = frontPointer->next;
        }
        return true;
    }
    bool isPalindrome(ListNode* head) {
        frontPointer = head;
        if(recursiveCheck(head)) 
            return true;
        return false;
    }
};