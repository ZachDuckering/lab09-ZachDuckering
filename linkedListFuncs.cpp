#include "linkedListFuncs.h"
#include <stddef.h>

#include <iostream>

using namespace std;

/*All functions MUST be implemented recursively
* No credit will be given for non-recursive solutions
*/


//head: ptr to a Node * which is the head of a linked list
//return sum of all values in linked list using a recursive approach
//if head is null return 0
int recursiveSum(Node* head) {
    //if head is the last node return its value
    if (head->next == NULL) 
        return head->data;
    //returns the sum of heads value and all of the nodes after it
  return head->data+recursiveSum(head->next);
}


//head: ptr to a Node* which is the head of a linked list
//return the largest value in the linked list using a recursive approach
//you may assume the list has at least one element
int recursiveLargestValue(Node* head) {
    //if head is the last node return its value
    if (head->next == NULL) 
        return head->data;
    //goes down until it reaches the end and then sets p to the largest of the two
    int p = recursiveLargestValue(head->next);
    if (head->data > p)
        return head->data;
  return p;
}


/*Given the head of a linked list, find and return the kth node of the linked list
 *Assume head is the first node
 *If k is larger than the size of the linked list, return NULL
 *
 * Example: n1 -> n2 -> n3 -> n4 -> n5, k = 3
 * Return &n3
 */
Node* recursiveFindKthNode(Node *head, int k){
    //if k is greater than the list length return NULL
    if (head == NULL){
        return NULL;
    }
    //if head is Kth node return it
    if (k == 1) {
        return head;
    }
    //count down to correct node
    k--;
    //just continues to return the Kth node once it is found or NULL if k is too big
    return recursiveFindKthNode(head->next, k);
    //STUB: edit with the correct output, according to the lab instructions, using recursion
}


/*Given the head of a linked list, delete the kth node from the linked list
 *k will always be less than the length of the linked list
* 
* Return the head of the new linked list
*
* Example: n1 -> n2 -> n3 -> n4, k = 2
* Delete n2 and return &n1
* New list should look like this: n1 -> n3 -> n4
*/
Node* recursiveDeleteKthNode(Node *head, int k) {
    //if it reaches the end of the list or the desired node return the node after it (or NULL if at the end)
    if (k==1 || head->next == NULL) {
        return head->next;
    }
    //count down to correct node
    k--;
    //sets the next as the same if its not the Kth but if the next was originally the function will return the node after the Kth and shut the Kth node out of the list
    head->next = recursiveDeleteKthNode(head->next, k);
    //returns the head to be set as the previous node's next head which is the same as it was before
    return head;
    //STUB: edit with the correct output, according to the lab instructions, using recursion
}


/*Given the head of a linked list, delete the first k nodes from the linked list
 *k will always be less than the length of the linked list
* 
* Return the head of the new linked list
*
* Example: n1 -> n2 -> n3 -> n4, k = 2
* Delete n1, n2 and return &n3
*/
Node* recursiveRemoveKFromFront(Node *head, int k) {
    //if it reaches the end of the list or it gets to the desired length return the new head
    if (k==1 || head->next == NULL) {
        return head->next;
    }
    //to count down to correct node
    k--;
    //just continues to return the new head
    return recursiveRemoveKFromFront(head->next, k);
    //STUB: edit with the correct output, according to the lab instructions, using recursion
}


/*Given two linked lists, return a NEW linked-list where each element is the sum of the corresponding elements of the input
 * If a linked list has a longer length than the other, treat the corresponding NULL element as a node with value 0
 * 
 * Example: List 1: 1 -> 2 -> 3 -> 12
 * 	    List 2: 4 -> 5 -> 6
 * Return &head of the linked list 5 -> 7 -> 9 -> 12
 */
Node* recursiveElementwiseSum(Node *head1, Node *head2) {
    //if there is nothing left in either list return NULL to end new list
    if (head1 == NULL && head2 == NULL) {
        return NULL;
    }

    //if head1 or head2 is null then set their values to 0 and point to NULL so you dont take NULL->next
    int num1,num2;
    Node* h1;
    Node* h2;
    if (head1 == NULL) {
        num1 = 0;
        h1 = NULL;
    } else {
        num1 = head1->data;
        h1 = head1->next;
    }
    if (head2 == NULL) {
        num2 = 0;
        h2 = NULL;
    } else {
        num2 = head2->data;
        h2 = head2->next;
    }

    //create a new node and set the value to the sums
    Node* p = new Node;
    p->data = num1+num2;

    //set the next to the sum of the next two heads if there are ones
    p->next = recursiveElementwiseSum(h1, h2);

    //return p to set the earlier nodes next to this new one
    return p;
}


/*BONUS: Given the heads of two linked lists, splice the second linked list into the first, alternating elements from each list
 * 
 * The first element of the newly arranged linked list will always be head1, unless head1 is NULL (in which case just return head2)
 *
 * You MUST modify the linked lists themselves and DO NOT create another list or any new nodes
 *
 * Example: List 1: 1->2->3, List 2: 4 -> 5 -> 6
 * Return &head of 1 -> 4 -> 2 -> 5 -> 3 -> 6
 */
Node* recursiveSplice(Node *head1, Node *head2) {
    //if theres no more of either lists return them and the remaining nodes will be added to the end of the spliced one
    if (head1 == NULL)
        return head2;
    if (head2 == NULL)
        return head1;
    
    //switch them to alternate them and set the next of head1 to head2
    head1->next = recursiveSplice(head2, head1->next);
    return head1;
    //STUB: edit with the correct output, according to the lab instructions, using recursion
}
