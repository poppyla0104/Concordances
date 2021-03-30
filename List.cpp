/*Poppy La
Instructor: Dr.Stiber
Course: CSS343
Program 1: List class
   This is a linked list class which each node of the list contain a Word object.
   The class can inserts linkedlist's node, deletes and displays the llinked list.
*/

#include "List.h"
#include <string>

using namespace std;


//default contructor
List::List()
{
   head_ = nullptr;
   end_ = nullptr;
}


//destructor
//function called: List::deleteList()
List::~List()
{
   deleteList();
}


//takes a Word object in parameter to insert in the list
//pre-condition: word object passed in parameter valid
//post-condition: a new node stores word object is inserted at the end of linked listed
//return: true when insertion completed
bool List::insert(Word *obj)
{
   //create a new Word object to add to the list
   Word* keyword = new Word(*obj);

   //insert in an empty list
   if(head_ == nullptr) {
      head_ = new Node;          //create new node
      head_->data_ = keyword;
      head_->next_ = nullptr;
      end_ = head_;

   //insert in a non-empty list
   } else {
      end_->next_ = new Node;    //create new node at the end of list
      end_ = end_->next_;        //move end pointer to the last node(new node)
      end_->data_ = keyword;
   }
          
   return true;
}


//pre-condition: the linked list valid
//post-condition: print out the linked list with all the word's objects data
void List::display() const
{
   Node* temp = head_;           //temporary pointer

   //print all the valid node of the list
   while (temp != nullptr) {
      cout << *(temp->data_) << endl << endl;
      temp = temp->next_;
   }
}


//pre-condition: the linked list valid
//post-condition: delete all the linked list nodes
//return: true when deletion completed
bool List::deleteList()
{
   //delete all the node in the list
   while (head_ != nullptr) {
      Node *temp = head_;         //temporary pointer
      head_ = head_->next_;
      delete temp->data_;        //delete dynamic allocated Word object
      delete temp;
   }
   return true;
}


//pre-condition: linked list object valid
//post-condition: printout all the words stored in all the linkedlist nodes.
//function called: List::display()
//return: out_stream
ostream& operator<<(ostream& out_stream, const List&list)
{
   list.display();
   return out_stream;
}

