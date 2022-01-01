
// prob link: https://leetcode.com/problems/reorder-list/

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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* nxt;
        while(curr){
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        return prev;
    }
    
    ListNode* findMiddle(ListNode* root){
        if(root == NULL || root->next == NULL) return root;
        ListNode* slow = root;
        ListNode* fast = root->next->next;
        
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        if(fast) slow = slow->next;
        return slow;
    }
    void reorderList(ListNode* head) {
        ListNode* mid = findMiddle(head);
        ListNode* temp = mid->next;
        mid->next = NULL;
        ListNode* midHead = reverseList(temp);
        
        ListNode* start = head;
        ListNode* end = midHead;
        
        while(start && end){
            ListNode* temp = end->next;
            ListNode* res = start->next;
            start->next = end;
            end->next = res;
            
            start = res;
            end = temp;
        }
    }
};


// thoda sa clean code likhna h