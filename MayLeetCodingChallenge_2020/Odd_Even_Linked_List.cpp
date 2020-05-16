//https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/536/week-3-may-15th-may-21st/3331/

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
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL)
            return head;
        if(head -> next == NULL)
            return head;
        
        ListNode* odd = head;
        ListNode* even = head -> next;
        
        ListNode* curr = even -> next;
        ListNode* temp = NULL;
        
        int i = 1;
        while(curr != NULL) {
            if(i % 2 == 1) {
                temp = curr -> next;
                curr -> next = odd -> next;
                odd -> next = curr;
                odd = odd -> next;
                even -> next = temp;
                curr = temp;
            } else {
                even = even -> next;
                curr = curr -> next;
            }
            i++;
        }
        return head;
    }
};