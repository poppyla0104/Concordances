/*Poppy La
Instructor: Dr.Stiber
Course: CSS343
Program 1: BST class
   This is a Binary search tree class which each node of the BST contains 
   a keyword and linked list that stores its context. The class can inserts tree's
   node, deletes and displays the BST.
*/

#include "BST.h"
#include <string>


//default contructor
BST::BST()
{
   root_ = nullptr;
}


//destructor
//function called: BST::display(), BST::empty()
BST::~BST()
{
   empty();
} 


//pre-condition: word object passed in parameter valid
//post-condition: create a new node if the Word's keyword does not exist,
//       add the new Word object to the linkedlist if the keyword exist
//return: true when insertion completed
bool BST::insert(Word* theWord)
{
   return insertHelper(root_, theWord);
}


//a helper of insert() function, takes a target node and word object to insert
//pre-condition: word object passed in parameter valid
//post-condition: create a new node at approriate location in BST if the Word's keyword
//does not exist, add the new Word object to the linkedlist if the keyword exist
//return: true when insertion completed
bool BST::insertHelper(Node *& node, Word *word)
{
   //add a new node if word not exist in BST
   if (node == nullptr){
      node = new Node;
      node->keyword_ = word->getWordLower();
      node->context_.insert(word);
      node->left_ = nullptr;
      node->right_ = nullptr;
      return true;

   //go left if word < the node's keyword
   } else if (word->getWordLower() < node->keyword_) {
      return insertHelper(node->left_, word);

   //go right if word > the node's keyword
   } else if (word->getWordLower() > node->keyword_) {
      return insertHelper(node->right_, word);

   //insert word object to linkedlist if word exist in BST
   } else if (word->getWordLower() == node->keyword_) {
      node->context_.insert(word);
      return true;

   } else {
      return false;
   }
}


//pre-condition: the BST valid(has nodes)
//post-condition: printout all the BST nodes
void BST::display() const
{
   displayHelper(root_);
}


//a helper of display() function, takes a target node to printout
//pre-condition: the BST valid(has nodes)
//post-condition: print out the BST node with all the keywords and their context
//in order traversal (left, root, right)
void BST::displayHelper(Node* node) const
{
   //print if node exist
   if (node != nullptr){
      displayHelper(node->left_); 
      cout << node->context_;
      displayHelper(node->right_);
   }
}

//pre-condition: the BST valid(has nodes)
//post-condition: delete all the BST nodes
void BST::empty()
{
   emptyHelper(root_);
}


//a helper of empty() function, takes a target node to delete
//pre-condition: the BST valid(has nodes)
//post-condition: delete all the BST nodes
void BST::emptyHelper(Node *& node)
{
   if (node != nullptr) {
      //travers left and right to check all exist node then delete
      emptyHelper(node->left_);
      emptyHelper(node->right_);
      delete node;
   }
}


//pre-condition: BST valid
//post-condition: printout all the words and its context stored 
//       in all the BST nodes.
//function called: BST::display()
//return: out_stream
ostream& operator<<(ostream& out_stream, const BST &bst)
{
   bst.display();
   return out_stream;
}