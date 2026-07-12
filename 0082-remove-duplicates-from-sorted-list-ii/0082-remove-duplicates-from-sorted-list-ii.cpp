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
    ListNode* deleteDuplicates(ListNode* head) {
        unordered_set<int> dup;

        // Pass 1: Remove extra copies and store duplicate values
        ListNode* curr = head;
        while (curr != NULL && curr->next != NULL) {
            if (curr->val == curr->next->val) {
                dup.insert(curr->val);

                ListNode* temp = curr->next;
                curr->next = curr->next->next;
                delete temp;
            } else {
                curr = curr->next;
            }
        }

        // Remove duplicate values from the beginning
        while (head != NULL && dup.count(head->val)) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
        }

        // Pass 2: Remove duplicate values from the remaining list
        curr = head;
        while (curr != NULL && curr->next != NULL) {
            if (dup.count(curr->next->val)) {
                ListNode* temp = curr->next;
                curr->next = curr->next->next;
                delete temp;
            } else {
                curr = curr->next;
            }
        }

        return head;
    }
};