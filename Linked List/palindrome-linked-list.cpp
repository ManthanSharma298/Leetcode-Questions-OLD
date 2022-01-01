// prob link: https://leetcode.com/problems/palindrome-linked-list/


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
    ListNode* reverse(ListNode* node){
        ListNode* prev = NULL, *curr = node;
        while(curr){
            ListNode* nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        ListNode *f = head, *s = head;
        while(f && f->next){
            s = s->next;
            f = f->next->next;
        }
        if(f){
            s = s->next;
        }
        s = reverse(s);
        f = head;
        while(s != NULL){
            if(f->val != s->val) return false;
            f = f->next;
            s = s->next;
        }
        return true;
    }
};

// Time complx: O(n/2) + O(n/2) + O(n/2) = O(n)
// Space complx: O(1)