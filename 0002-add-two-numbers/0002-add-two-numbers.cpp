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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        int carry = 0;

        ListNode* dummy = new ListNode(0);//create an dummy node
        ListNode* temp3 = dummy;

        ListNode* temp1 = l1;
        ListNode* temp2 = l2;

        while (temp1 != NULL || temp2 != NULL || carry != 0) {
            int val1 = 0;
            int val2 = 0;
            if (temp1 != NULL){
                val1 = temp1->val;
            }
            if (temp2 != NULL){
                val2 = temp2->val;
            }
            int sum = val1 + val2 + carry;
            int digit = sum % 10;
            carry = sum / 10;

            temp3->next = new ListNode(digit);
            temp3 = temp3->next;

            if (temp1 != NULL)
                temp1 = temp1->next;

            if (temp2 != NULL)
                temp2 = temp2->next;
        }

        return dummy->next;//dummy node has 0 which is not neded
    }
};