
// prob link: https://leetcode.com/problems/remove-nth-node-from-end-of-list/

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


// Without Dummy node
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = 0;
        ListNode* temp = head;
        while(temp){
            temp = temp->next;
            len++;
        }
        len = len-n+1;
        
        temp = head;
        ListNode* prev;
        bool isVis = false;
        for(int i=1; i<len; ++i){
            prev = temp;
            temp = temp->next;
            isVis = true;
        }
        if(isVis) prev->next = temp->next;
        else head = head->next;
        temp->next = NULL;
        
        return head;
    }
};

// Using dummy node
class Solution {
public:
    // if we don't use a dummy node then we need to takle head case separately
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = 0;
        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode* temp = head;
        
        while(temp){
            temp = temp->next;
            len++;
        }
        len -= n;
        
        temp = dummy;
        while(len--){
            temp = temp->next;
        }
        temp->next = temp->next->next;
        
        return dummy->next; // we can't return head directly as it may be removed
    }
};

// two iterations
// Time complx: O(N)
// Space complx: O(1)


// Using fast and slow pointer
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode *slow = dummy, *fast = head;
        while(n--){
            fast = fast->next;
        }
        while(fast){
            slow = slow->next;
            fast = fast->next;
        }
        slow->next = slow->next->next;
        
        return dummy->next;
    }
};

// one iteration
// Time complx: O(N)
// Space complx: O(1)