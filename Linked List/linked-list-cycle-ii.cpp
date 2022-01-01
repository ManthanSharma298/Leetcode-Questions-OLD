// prob link: https://leetcode.com/problems/linked-list-cycle-ii/

// 1. Hashing of ListNode

// 2. slow and fast pointer
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
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL) return NULL;
        ListNode* d = new ListNode(0);
        d->next = head;
        ListNode *s = d, *f = d;
        while(f && f->next){
            s = s->next;
            f = f->next->next;
            if(s == f){
                f = d;
                while(s != f){
                    s = s->next;
                    f = f->next;
                }
                return s;
            }
        }
        return NULL;
    }
};
// Time complx: O(N)
// Space complx: O(1)
