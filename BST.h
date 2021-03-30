/*Poppy La
Instructor: Dr.Stiber
Course: CSS343
Program 1: BST class
   This is a Binary search tree class which each node of the BST contains 
   a keyword and linked list that stores its context. The class can inserts tree's
   node, deletes and displays the BST.
*/

#pragma once
#include "List.h"
#include <string>

class BST
{
   public:
//--------------------------------------------------------------
//                  CONSTRUCTORS & DESTRUCTOR
//--------------------------------------------------------------
   //default contructor
   BST();

   //destructor
   //function called: BST::display(), BST::empty()
   ~BST();

//--------------------------------------------------------------
//                         FUNCTIONS
//--------------------------------------------------------------
   //takes a Word object in parameter to insert in the list
   //pre-condition: word object passed in parameter valid
   //post-condition: create a new node if the Word's keyword does not exist,
   //       add the new Word object to the linkedlist if the keyword exist
   //return: true when insertion completed
   bool insert(Word*);

   //pre-condition: the BST valid(has nodes)
   //post-condition: delete all the BST nodes
   void empty();

   //pre-condition: the BST valid(has nodes)
   //post-condition: printout all the BST nodes
   void display() const;

//--------------------------------------------------------------
//                       OPERATORS OVERLOAD
//--------------------------------------------------------------
   //pre-condition: BST valid
   //post-condition: printout all the words and its context stored 
   //       in all the BST nodes.
   //function called: BST::display()
   //return: out_stream
   friend ostream& operator<<(ostream& out_stream, const BST &bst);


   protected:
   //Linked list node that contain a string of keyword, a linkedlist pointer 
   //and BST node's left, right pointers 
   struct Node
   {
      string keyword_ = "\0";       //lower case keyword
      List context_;                //linked list stores keyword's context
      Node* left_ = nullptr;        //left pointer
      Node* right_ = nullptr;       //right pointer
   };

   //a helper of insert() function, takes a target node and word object to insert
   //pre-condition: word object passed in parameter valid
   //post-condition: create a new node at approriate location in BST if the Word's keyword
   //does not exist, add the new Word object to the linkedlist if the keyword exist
   //return: true when insertion completed
   bool insertHelper(Node*&, Word*);

   //a helper of empty() function, takes a target node to delete
   //pre-condition: the BST valid(has nodes)
   void emptyHelper(Node *&);

   //a helper of display() function, takes a target node to printout
   //pre-condition: the BST valid(has nodes)
   //post-condition: print out the BST node with all the keywords and their context
   void displayHelper(Node*) const;


//--------------------------------------------------------------
//                          VARIABLES
//--------------------------------------------------------------
   private:
   Node *root_;         //root pointer
};