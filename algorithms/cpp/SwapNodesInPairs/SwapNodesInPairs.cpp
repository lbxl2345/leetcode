/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* pre = NULL;
        ListNode* cur = head;
        ListNode* next = NULL;
        if(!cur) return head;
        if(cur->next) head = cur->next;
        while(cur && cur->next){
          next= cur->next;
          if(pre) pre->next = next;
          cur->next = next->next;
          next->next = cur;
          pre = cur;
          cur = pre->next;
        }
        return head;
    }
};
