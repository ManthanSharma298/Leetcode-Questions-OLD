// prob link: https://leetcode.com/problems/intersection-of-two-linked-lists/

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode*> s;
        ListNode* tmp = headA;
        while(tmp){
            s.insert(tmp);
            tmp = tmp->next;
        }
        tmp = headB;
        while(tmp){
            if(s.count(tmp)) return tmp;
            tmp = tmp->next;
        }
        return NULL;
    }
};
// Time complx: O(a+b)
// Space complx: O(a)


class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int l1 = 0, l2 = 0;
        ListNode *t1 = headA, *t2 = headB;
        while(t1){
            l1++;
            t1 = t1->next;
        }
        while(t2){
            l2++;
            t2 = t2->next;
        }
        t1 = headA;
        t2 = headB;
        if(l1 < l2){
            t1 = headA;
            t2 = headB;
        }
        else{
            t1 = headB;
            t2 = headA;
        }
        int diff = abs(l2-l1);
        while(diff--){
            t2 = t2->next;
        }
        while(t1 && t2){
            if(t1 == t2) return t1;
            t1 = t1->next;
            t2 = t2->next;
        }
        return NULL;
    }
};
// Time complx: O(n+m) + O(max(m,n)) = O(2*max(m,n))
// Space complx: O(1)

// messy code
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *p = headA, *q = headB;
        while(true){
            if(p == NULL) p = headB;
            if(q == NULL) q = headA;
            if(p == q) return p;
            p = p->next;
            q = q->next;
            if(p == q) return p;
        }
        return NULL;
    }
};
// Time complx: O(2*max(m,n))
// Space complx: O(1)

// clean code
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *p = headA, *q = headB;
        while(p != q){
            p = (p ? p->next : headB);
            q = (q ? q->next : headA);
        }
        return p;
    }
};
// Time complx: O(2*max(m,n))
// Space complx: O(1)