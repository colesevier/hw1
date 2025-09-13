/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/

#include "split.h"

// helper function for printing
// void display(Node*& in)
// {
//   if (in->next == nullptr)
//   {
//     cout << 
//   }
// }

// delete function
void deletelist(Node*& node)
{
  if (node == nullptr)
  {
    return;
  }
  deletelist(node->next);
  delete node;
}

int main(int argc, char* argv[])
{
  Node* in = nullptr;
  Node* evens = nullptr;
  Node* odds = nullptr;
  // make nodes 1-3
  Node* node1 = new Node(3, nullptr);
  in = node1;
  Node* node2 = new Node(24, nullptr);
  node1->next = node2;
  Node* node3 = new Node(107, nullptr);
  node2->next = node3;
  split(in, odds, evens);

  deletelist(odds);
  deletelist(evens);
  deletelist(in);
  // Go through odds and print all of the items (recursively)

}
