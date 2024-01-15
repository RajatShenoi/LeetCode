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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		// dummyHead is the pointer that we will be returning
		ListNode* dummyHead = new ListNode(0);
		// curr is the pointed pointing to the current element which is
		// currently set to the first element of the LinkedList.
		// our list is currently 0->.... 
		ListNode* curr = dummyHead;

		// this is the variable in which we will be storing the carry
		// over values during addition
		int carry = 0;
		// as long as there are more elements in either of the linked list
		// or there is a carry which is not equal to zero
		while (l1 != NULL || l2 != NULL || carry != 0) {
			// if there is not more element, replace with zero
			int x = l1 ? l1->val : 0;
			int y = l2 ? l2->val : 0;

			// calculate the sum of those elements with the carry
			int sum = carry + x + y;

			// calculate the carry over value
			carry = sum / 10;

			// set the current value to be sum % 10
			curr->next = new ListNode(sum % 10);

			// change the current value to the next value for the 
			// next iteration
			curr = curr->next;
			// move one step forward in the l1 and l2 linked lists
			// if it's the end, set to nullptr
			l1 = l1 ? l1->next : nullptr;
			l2 = l2 ? l2->next : nullptr;
		}
		// returning the head of the linked list without the zero.
		// note that `dummyHead.val = 0`
		// return dummyHead->next which is where the answer starts from.
		return dummyHead->next;	
    }
};

