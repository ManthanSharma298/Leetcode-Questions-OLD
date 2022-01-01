
// prob link: https://leetcode.com/problems/middle-of-the-linked-list/


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

// Recursive
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* temp = head;
        int len = 0;
        while (head != nullptr) {
            len++;
            head = head -> next;
        }
        for (int i = 0; i < len/2; ++i) {
            temp = temp -> next;
        }
        return temp;
    }
};

// Time complx: O(n) + O(n) = O(n)
// Space complx: O(1)

// Iterative
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode*s = head, *f = head;
        while(f && f->next){
            s = s->next;
            f = f->next->next;
        }
        return s;
    }
};

// Time complx: O(n)
// Space complx: O(1)