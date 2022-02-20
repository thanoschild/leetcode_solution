class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
       if(head == NULL) return NULL;
       ListNode* root = new ListNode();
       ListNode* temp = root;
        while(head){
                if(head->val == 0)
                head = head->next;
                if(!head)
                break;
                int sum = 0;
                while(head->val != 0){
                sum += head->val;
                head = head->next;
                }
                root->next = new ListNode(sum);
                root = root->next;
        }
      return temp->next; 
    }
};
