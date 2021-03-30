/*Poppy La
Instructor: Dr.Stiber
Course: CSS343
Program 1: List class
   This is a linked list class which each node of the list contain a Word object.
   The class can inserts linkedlist's node, deletes and displays the llinked list.
*/

#pragma once
#include <iostream>
#include "Word.h"
#include <string>


using namespace std;

class List
{
   public:
//--------------------------------------------------------------
//                  CONSTRUCTORS & DESTRUCTOR
//--------------------------------------------------------------
   //default contructor
   List();

   //destructor
   //function called: List::deleteList()
   ~List();


//--------------------------------------------------------------
//                         FUNCTIONS
//--------------------------------------------------------------
   //takes a Word object in parameter to insert in the list
   //pre-condition: word object passed in parameter valid
   //post-condition: a new node stores word object is inserted at the end of linked listed
   //return: true when insertion completed
   bool insert(Word*);

   //pre-condition: the linked list valid
   //post-condition: print out the linked list with all the word's objects data
   void display() const;

   //pre-condition: the linked list valid
   //post-condition: delete all the linked list nodes
   //return: true when deletion completed
   bool deleteList();


//--------------------------------------------------------------
//                       OPERATORS OVERLOAD
//--------------------------------------------------------------
   //pre-condition: linked list object valid
   //post-condition: printout all the words stored in all the linkedlist nodes.
   //function called: List::display()
   //return: out_stream
   friend ostream& operator<<(ostream& out_stream, const List&list);


   protected:
//--------------------------------------------------------------
//                          VARIABLES
//--------------------------------------------------------------
   //Linked list node that contain a Word object pointer and next pointer 
   struct Node
   {
      Word *data_ = nullptr;
      Node *next_ = nullptr;
   };


   private:
   Node *head_;      //pointer that points the first node of linkedlist
   Node *end_;       //pointer that points the last node of linkedlist
};
