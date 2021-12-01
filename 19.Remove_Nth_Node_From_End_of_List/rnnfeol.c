/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    struct ListNode *curr = NULL, *rec = NULL;
    int cnt = 0;
    curr = rec = head;
    while(curr->next) {
        curr = curr->next;
        if (cnt < n) cnt++;
        else {
            rec = rec->next;
        }
    }
    struct ListNode *tmp = rec;
    if (rec->next) {
        tmp = rec->next;
        if (cnt != n) {
            tmp = head;
            head = head->next;
            // free(rec);
        } else {
            if (tmp->next) rec->next = tmp->next;
            else rec->next = NULL;
        }
        free(tmp);
        tmp = NULL;
    } else {
        head = NULL;
        free(tmp);
    }


    return head;
}