/*Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.

Example:

Input: 1->2->4, 1->3->4
Output: 1->1->2->3->4->4*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode * third = NULL;
		ListNode* last = NULL;
		if (l1 == NULL && l2 == NULL)
			return NULL;
		if (l1 == NULL)
			return l2;
		if (l2 == NULL)
			return l1;

		if (l1->val < l2->val) {
			third = l1;
			l1 = l1->next;
			third->next = NULL;
			last = third;

		}
		else {
			third = l2;
			l2 = l2->next;
			third->next = NULL;
			last = third;
		}

		while (l1 != NULL && l2 != NULL) {
			if (l1->val < l2->val) {
				last->next = l1;
				l1 = l1->next;
				last = last->next;
				last->next = NULL;

			}
			else {
				last->next = l2;
				l2 = l2->next;
				last = last->next;
				last->next = NULL;
			}
		}
		if (l1 != NULL)
			last->next = l1;
		if (l2 != NULL)
			last->next = l2;
		return third;
	}
};