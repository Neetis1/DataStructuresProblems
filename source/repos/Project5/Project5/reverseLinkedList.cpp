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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        /*recursively we can do this by thinking that apart from the 3 pointer approach another way of reversing the list would be
	to reach the end of the linked list and then reverse the list from there. but we dont have a backward pointer, so how can we
	do this. we will do this usig recursion. we reach the end of the list by calling itself on next until the next is NULL. 
	then while returning we change the head->next-.next to head how does that happen in the following example say we reach 5 th node,
	we will see its next is null we return from there and store its address in result(this becomes the head) now wen we return the
	current head at that particular place is 4 and if we do head-next-next(5->next) = head(4) it becomes 5->4 and in the next line
	we make head->next = NULL, which is 4->next = NULL (this will be reversed in the next call).
       1->2->3->4->5->NULL
       */
        
        ListNode newHead(0);
        ListNode *prev = &newHead;
        ListNode *curr = NULL;
        ListNode *nextt = NULL;
        newHead.next = head;
        for(int i=1;i<m;i++)
            prev = prev->next;
        curr = prev->next;
        
        for(int i=0;i<n-m;i++){
            nextt = curr->next;
            curr->next = nextt->next;
            nextt->next = prev->next;
            prev->next = nextt;
        }
        return newHead.next; 
    }
};
