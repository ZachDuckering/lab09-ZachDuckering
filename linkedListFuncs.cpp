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
    if (head->next == NULL) 
        return head->data;
  return head->data+recursiveSum(head->next);
}


//head: ptr to a Node* which is the head of a linked list
//return the largest value in the linked list using a recursive approach
//you may assume the list has at least one element
int recursiveLargestValue(Node* head) {
    if (head->next == NULL) 
        return head->data;
    //if (head->data > recursiveLargestValue(head->next)) 
    //    return 
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
    if (head == NULL){
        return NULL
    }
    if (k == 1) {
        return head;
    }
    k--;
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
    if (k==1 || head->next == NULL) {
        return head->next;
    }
    k--;
    head->next = recursiveDeleteKthNode(head->next, k);
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
    if (k==1 || head->next == NULL) {
        return head->next;
    }
    k--;
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
    if (head1 == NULL && head2 == NULL) {
        return NULL;
    }
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
    Node* p = new Node;
    p->data = num1+num2;
    p->next = recursiveElementwiseSum(h1, h2);
    return p;
    //STUB: edit with the correct output, according to the lab instructions, using recursion
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
    if (head1 == NULL)
        return head2;
    if (head2 == NULL)
        return head1;
    
    head1->next = recursiveSplice(head2, head1->next);
    return head1;
    //STUB: edit with the correct output, according to the lab instructions, using recursion
}
