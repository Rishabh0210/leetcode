//https://leetcode.com/explore/challenge/card/june-leetcoding-challenge/539/week-1-june-1st-june-7th/3348/

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
    void deleteNode(ListNode* node) {
        ListNode* prev = node;
        while(node -> next != NULL) {
            node -> val = node -> next -> val;
            prev = node;
            node = node -> next;
        }
        prev -> next = NULL;
        // free(node);
    }
};