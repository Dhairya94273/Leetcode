class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }

        vector<int> ans;
        ListNode *curr = head;
        while (curr != NULL) {
            ans.push_back(curr->val); 
            curr = curr->next;
        }

        sort(ans.begin(), ans.end());
        curr = head;
        int i = 0;
        while (curr != NULL) {
            curr->val = ans[i];  
            i++;
            curr = curr->next;
        }
        
        return head; 
    }
};
