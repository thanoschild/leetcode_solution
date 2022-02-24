class Solution {
public:
    ListNode* findmid(ListNode* head){
        ListNode* fast = head, *slow = head;
        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode* merge(ListNode* left, ListNode* right){
        if(!left) return right;
        if(!right) return left; 
        if(left->val < right->val){
            left->next = merge(left->next, right);
            return left;
        }
        else{
            right->next = merge(left, right->next);
            return right;
        }
    }
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* mid = findmid(head);
        ListNode* left = head;
        ListNode* right = mid->next;
        mid->next = NULL;
        left = sortList(left);
        right = sortList(right);
        ListNode* result = merge(left, right);
        return result;

    }
};
