/*Poppy La
Instructor: Dr.Stiber
Course: CSS343
Program 1: Concordances with Binary Search Tree
   The program create a list of concordances from a text corpus of an input file using 
   Binary search tree and linked lists. Each BST will stores a keyword and its linked list
   of context. The program will take and read an input file from the command line argument 
   and a stopword file (if the file is valid). Output prints out the keywords in alphabetical 
   order with KWIC form, the same keyword with different contexts will be printed in its 
   occurrence order in the corpus text.
   Error messages appears if no file/ wrong file name is passed by the command line argument.
   The program runs with or without stopword.txt file.
*/

#include <string>
#include <iostream>
#include "Concordances.h"

using namespace std;


int main(int argc, char* argv[])
{
   //notice if the corpus file is missing
   if(argv[1] == nullptr){
      cout << "Please input a file name!" << endl;

   } else {
      //ignore all the other input after corpus file in command line argument, then process
      if(argc > 2) {
         cout << "Input after the file name will be ignored. Processing.. " << endl << endl;
      }

      //create concordances object and process
      Concordances corpus;
      corpus.process(argv[1]);
      corpus.display();
   }

}