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
    ListNode* swapPairs(ListNode* head) { 
        if(head == NULL){ 
            return head; 
        } 
        ListNode *curr = head->next; 
        ListNode *temp = head; 
        if(curr == NULL){ 
            return head; 
        } 
        
        // Handle the first pair swap
        head = head -> next; 
        temp->next = curr->next; 
        head->next = temp; 
        
        // Track the end of the last swapped pair
        ListNode *prev = temp;
        curr = temp->next; 

        // Loop through the remaining pairs
        while(curr != NULL && curr->next != NULL){ 
            temp = curr;
            curr = curr->next;
            
            // Swap the current pair
            temp->next = curr->next;
            curr->next = temp;
            
            // Link the previous pair to the newly swapped pair
            prev->next = curr;
            
            // Move pointers forward for the next iteration
            prev = temp;
            curr = temp->next;
        } 
        
        return head; // Added missing return statement
    } 
};