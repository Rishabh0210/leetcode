//https://leetcode.com/explore/featured/card/july-leetcoding-challenge/545/week-2-july-8th-july-14th/3386/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if(!head) 
            return head;
        
        Node* curr = head;
        
        while(curr) {
            Node* nextNode = curr -> next;
            if(curr -> child) {
                Node* childList = flatten(curr -> child);
                Node* childEnd = childList;
                while(childEnd -> next) 
                    childEnd = childEnd -> next;
                curr -> next = childList;
                childList -> prev = curr;
                
                curr -> child = NULL;
                
                childEnd -> next = nextNode;
                if(nextNode)
                    nextNode -> prev = childEnd;
            }
            curr = nextNode;
        }
        
        return head;
    }
};