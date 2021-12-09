//https://leetcode.com/problems/remove-nth-node-from-end-of-list/submissions/
class Solution {
private:
    int length(ListNode* head){
        int l = 0;
        while(head != NULL){
            l++;
            head = head -> next;
        }
        return l;
    }
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = length(head);
        if (len - n == 0){
            ListNode* temp = head;
            head = head -> next;
            delete temp;
            return head;
        }
        ListNode* temp = head;
        int count = 0;
        while (count < len - n - 1){
            temp = temp -> next;
            count++;
        }
        ListNode* node = temp -> next;
        temp -> next = temp -> next -> next;
        delete node;
        return head;
    }
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *fast = head, *slow = head;
        for (int i = 0; i < n; i++) fast = fast->next;
        if (!fast) return head->next;
        while (fast->next) fast = fast->next, slow = slow->next;
        ListNode* temp = slow -> next;
        slow->next = slow->next->next;
        delete temp;
        return head;
    }
};