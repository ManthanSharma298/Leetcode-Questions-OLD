// prob link: https://leetcode.com/problems/rotate-list/


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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL) return NULL;
        int len = 1;
        ListNode* tmp = head;
        while(tmp->next){
            len++;
            tmp = tmp->next;
        }
        tmp->next = head;
        k %= len;
        int d = len-k;
        tmp = head;
        ListNode* prev;
        while(d-- > 0){
            prev = tmp;
            tmp = tmp->next;
        }
        head = tmp;
        prev->next = NULL;
        return head;
    }
};

// Time complx: O(n) + O(d) = O(n)
// Space complx: O(1)