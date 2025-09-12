/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/

#include "split.h"
#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
  int a = 20;
  Node* in = nullptr;


  for (int i = a; i >= 1; --i) {
    Node* newNode = new Node{i, in};
    in = newNode;
  }
  cout << "in: " << endl;

  Node* temp = in;

  for (int i = 1; i <= a; ++i) {
    cout << temp->value << " ";
    temp = temp->next;
  }
  cout << endl;

  Node* odds = nullptr;
  Node* evens = nullptr;
  split(in, odds, evens);

  cout << "odds: ";
  for (temp = odds; temp != nullptr; temp = temp->next) {
    cout << temp->value << " ";
  }
  cout << endl;

  cout << "evens: ";
  for (temp = evens; temp != nullptr; temp = temp->next) {
    cout << temp->value << " ";
  }
  cout << endl;

  if (in == nullptr) {
    cout << "in is nullptr" << endl;
  }
  else {
    cout << "in isnt a nullptr" << endl;
  }

  while (odds != nullptr) {
    Node* deleteNode = odds;
    odds = odds->next;
    delete deleteNode;
  }

  while (evens != nullptr) {
    Node* deleteNode = evens;
    evens = evens->next;
    delete deleteNode;
  }

}
