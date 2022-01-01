
// prob link: https://leetcode.com/problems/merge-two-sorted-lists/

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

// Iterative
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* newHead = new ListNode();
        ListNode* temp = newHead;
        while(l1 && l2){
            if(l1->val < l2->val){
                temp->next = l1;
                l1 = l1->next;
            }
            else{
                temp->next = l2;
                l2 = l2->next;     
            }
            temp = temp->next;
        }
        if(l1) temp->next = l1;
        if(l2) temp->next = l2;
        return newHead->next;
    }
};

// Time complx: O(m + n)
// Space complx: O(m + n)

// Recursive
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        if(l1->val < l2->val){
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }
        else{
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
};

// Time complx: O(m + n)
// Space complx: O(m + n)

// In-Place (Iterative)
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        if(l1->val > l2->val){
            ListNode* tmp = l1;
            l1 = l2;
            l2 = tmp;
        }
        ListNode* head = l1;
        ListNode* prev = new ListNode();
        prev->next = l1;
        while(l1 && l2){
            while(l1 && l2 && l1->val <= l2->val){
                l1 = l1->next;
                prev = prev->next;
            }
            ListNode* tmp = l2->next;
            prev->next = l2;
            if(l1){
                l2->next = l1;
                l2 = tmp;
                prev = prev->next;
            }
        }
        return head;
    }
};

// Time complx: O(m + n)
// Space complx: O(1)