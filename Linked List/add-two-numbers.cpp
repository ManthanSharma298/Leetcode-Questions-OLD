// prob link: https://leetcode.com/problems/add-two-numbers/


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

// By calculating size of numbers
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int c = 0;
        ListNode* res = new ListNode();
        ListNode* t = res;
        int sz = 0, st = 0;
        ListNode* i = l1;
        while(i){
            i = i->next;
            sz++;
        }
        i = l2;
        while(i){
            i = i->next;
            st++;
        }
        sz = max(sz, st);
        // cout<<sz<<"\n";
        while(sz--){
            ListNode* n = new ListNode();
            
            int sm = c;
            if(l1){
                sm += l1->val;
            }
            if(l2){
                sm += l2->val;
            }
            if(sm >= 10){
                n->val = sm%10;
                c = 1;
                if(sz == 0){
                    ListNode* nn = new ListNode();
                    nn->val = 1;
                    n->next = nn;
                }
            }
            else{
                n->val = sm;
                c = 0;
            }
            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
            t->next = n;
            t = t->next;
        }
        return res->next;
    }
};
// Time complx: O(max(l1.size,l2.size));
// Space complx: O(1)

// do it in one loop 
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int c = 0;
        ListNode* res = new ListNode();
        ListNode* t = res;
        while(l1 || l2 || c){
            ListNode* n = new ListNode();
            int sm = c;
            if(l1){
                sm += l1->val;
            }
            if(l2){
                sm += l2->val;
            }
            n->val = sm%10;
            c = sm/10;
            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
            t->next = n;
            t = t->next;
        }
        return res->next;
    }
};
// Time complx: O(max(l1.size,l2.size));
// Space complx: O(1)
