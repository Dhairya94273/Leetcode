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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head) return nullptr;
        
        vector<int> arr;
        ListNode* curr = head;
        while (curr != nullptr) { 
            arr.push_back(curr->val);
            curr = curr->next;
        }
        
        arr.erase(arr.end() - n);
        
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;
        for (int val : arr) {
            temp->next = new ListNode(val);
            temp = temp->next;
        }
        ListNode* newHead = dummy->next;
        delete dummy; // Free the temporary dummy memory
        return newHead;
    }
};
