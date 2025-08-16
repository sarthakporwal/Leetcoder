class Solution {
public:
    ListNode* curr;
    void solve(ListNode* head){
        if(head == NULL) return;

        solve(head->next);

        ListNode* temp = curr->next;
        if(curr->next == NULL){
            return;
        }else if(head == curr){
            head->next = NULL;
            return;
        }
        curr->next = head;
        head->next = (temp == head) ? NULL : temp;
        curr = temp;
    }

    void reorderList(ListNode* head) {
        curr = head;

        solve(head);

    }
};