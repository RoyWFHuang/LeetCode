/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


void __mergeTwoLists(
    struct ListNode* ret_list, struct ListNode* l1, struct ListNode* l2)
{
    if (NULL ==  l1) {
        ret_list->next = l2;
        return;
    } else if (NULL ==  l2) {
        ret_list->next = l1;
        return;
    }

    if (l1->val < l2->val) {
        ret_list->next = l1;
        l1 = l1->next;
    } else {
        ret_list->next = l2;
        l2 = l2->next;
    }
    ret_list = ret_list->next;
    return __mergeTwoLists(ret_list, l1, l2);

}

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2)
{
    if (NULL ==  l1)
        return l2;
    else if (NULL ==  l2)
        return l1;
    else if (NULL ==  l2 &&  NULL ==  l1)return NULL;

    struct ListNode* ret_list = NULL, *tmp_list;

    if (l1->val < l2->val) {
        ret_list = l1;
        l1 = l1->next;
    } else {
        ret_list = l2;
        l2 = l2->next;
    }
    tmp_list = ret_list;
    __mergeTwoLists(tmp_list, l1, l2);
    printf("\n");
    return ret_list;

}


struct ListNode* mergeKLists(struct ListNode** lists, int listsSize){

    if (0 == listsSize)
        return NULL;
    else if (1 == listsSize)
        return lists[0];
    else if (2 == listsSize)
        return mergeTwoLists(lists[0], lists[1]);
    else
        return mergeTwoLists(
            mergeKLists(lists, listsSize/2),
            mergeKLists(&lists[listsSize/2], listsSize - listsSize/2));

    // return ret_list;
}
