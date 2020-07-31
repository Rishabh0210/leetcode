//https://leetcode.com/explore/challenge/card/july-leetcoding-challenge/546/week-3-july-15th-july-21st/3396/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* curr;
        ListNode* prev;
        prev = NULL ;
        curr = head;
        
        while(curr != NULL) {
            ListNode* temp = NULL;
            if(curr -> val == val) {
                if(prev == NULL) {
                    head = curr -> next;
                    temp = curr;
                } else {
                    prev -> next = curr -> next;
                    temp = curr;
                }
            } else {
                prev = curr;
            }
            curr = curr -> next;
            // if(temp)
            //     free(temp);
        }
        return head;
    }
};