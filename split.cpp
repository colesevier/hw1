/*
CSCI 104: Homework 1 Problem 1

Write a recursive function to split a sorted singly-linked
list into two sorted linked lists, where one has the even 
numbers and the other contains the odd numbers. Students 
will receive no credit for non-recursive solutions. 
To test your program write a separate .cpp file and #include
split.h.  **Do NOT add main() to this file**.  When you submit
the function below should be the only one in this file.
*/

#include "split.h"

/* Add a prototype for a helper function here if you need */

// added prototype in split.h but here
void append(Node*& in, Node* node);

// helper function
void append(Node*& in, Node* node){
  // check to see if the list code is in is null
  if (in == nullptr)
  {
    in = node;
    // make the next pointer null
    node->next = nullptr;
  }
  // recursive case
  else
  {
    append(in->next, node);
  }
}

void split(Node*& in, Node*& odds, Node*& evens)
{
  /* Add code here */
// WRITE YOUR CODE HERE

  // make a temp node to walk down and add to odds/evens
  Node* temp = in;
  // check to make sure that in isn't null
  if (temp== nullptr)
  {
    return;
  }
  
  // iterate in so that it doesn't change when we change temp
  in = in->next;

  // detach the node from the rest of in
  temp->next = nullptr;
  // start with the base cases
  // Case 1: in is null

  // Case 2: odd
  if (temp->value%2 == 1)
  {
    // do a ptr switch with temp
    // make sure it's in increasing order
    append(odds, temp);
    split(in, odds, evens);
  }
  // Case 3: even
  else
  {
    // do a ptr switch with temp
    append(evens, temp);
    split(in, odds, evens);
  }
  // go to the next value of in
  // go to recursive case

}

/* If you needed a helper function, write it here */
