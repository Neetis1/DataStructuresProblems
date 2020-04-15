/*Reverse a singly linked list.

Example:

Input: 1->2->3->4->5->NULL
Output: 5->4->3->2->1->NULL
Follow up:

A linked list can be reversed either iteratively or recursively. Could you implement both?*/

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
	ListNode* reverseList(ListNode* head)
	{
		//1->2->3->4->5->NULL
		ListNode* previous = NULL;
		ListNode* current = head;
		ListNode* nextpoint = NULL;

		while (current != NULL)
		{
			nextpoint = current->next;
			current->next = previous;
			previous = current;
			current = nextpoint;
		}
		return previous;
	}
};