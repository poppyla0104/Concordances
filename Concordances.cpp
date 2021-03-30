/*Poppy La
Instructor: Dr.Stiber
Course: CSS343
Program 1: Concordaces class
   This class takes a corpus's and stopword's file name, stores them in corpus and
	stopword vectors, indentify if the words are keywords,then add them in a binary 
	search tree. The class process the file, displays the BST in KWIC format.
*/

#include "Concordances.h"
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <cctype>
#include <algorithm>

using namespace std;

//default contructor
Concordances::Concordances()
{
   stopWordValid_ = false;
}


//destructor
Concordances::~Concordances()
{}



//takes corpus file in parameter and check stopword.txt file, stores in corpus and 
//stopword vectors,indentify if the words are keywords then add them to BST
//pre-condition: file name is valid
//post-condition: create BST that has all keywords
//function called: Concordances::cleanWord(string&), Concordances::notStopWord(const string&)
//return: true if corpus file is found and BST is created with all keywords
bool Concordances::process(const string& file_name)
{
   ifstream corpusFile, stopWordFile;
   corpusFile.open(file_name);
   stopWordFile.open("stopword.txt");

   //notice that corpus file is not exist and stop processing
   if (!corpusFile.is_open()){
      cout << "File can not be opened or file does not exist." << endl; 
      return false;
   }

   //go through each word in corpus file, "clean" and add to corpus vector
   while(!corpusFile.eof()){
      string corpusWord;
      corpusFile >> corpusWord;
      //remove word's begin and end punctuations if exist
      cleanWord(corpusWord);

      //add to corpus vectorif corpusWord string is not empty
      if(corpusWord.size() != 0) {
      corpus_.push_back(corpusWord);
      }
   }

   //notify that stopword file is exist and add them to stopword vector
   if (stopWordFile.is_open()){
      cout << "stopword.txt valid." << endl << endl;
      stopWordValid_ = true;

      //go through each word in stopword file and add to stopword vector
      while (!stopWordFile.eof()){
         string stopword;
         stopWordFile >> stopword;
         //remove stopword's begin and end punctuations if exist
         cleanWord(stopword);

         //add to stopword vector if stopword string is not empty
         if(stopword.size() != 0) {
         stopWords_.push_back(stopword);
         }
      }
   }

   //determine if each word in corpus vector is keyword(non-stopword) and add to BST
   for (int i = 0; i < corpus_.size(); i++){   
      int index = i;
      int wordCount = 0;
      
      //word is non-stopword
      if (notStopWord(corpus_.at(i))){
         string beforeWord = "\0";     //will store 5 words before keyword
         string afterWord = "\0";      //will store 5 words after keyword
         
         //get 5 words before keyword
         while (index > 0 && wordCount < 5){
            beforeWord = corpus_.at(--index) + " " + beforeWord;
            wordCount++;
         }
         
         index = i;
         wordCount = 0;
         //get 5 words after keyword
         while (index < corpus_.size()-1 && wordCount < 5){
            afterWord += " " + corpus_.at(++index);
            wordCount++;
         }
         
         //create Word object that has keyword, 5 words before keyword and
         //5 words after keyword
         Word keyword(corpus_.at(i), beforeWord, afterWord);
         concordances_.insert(&keyword);        //insert Word to BST
      }
   } 
   return true;
}


//take a word reference and clean all the punctuation character at the begin & end of word
//pre-condition: word string is not empty
//post-condition: word does not contain punctuations at the beginning and ending
void Concordances::cleanWord(string& word)
{
   while (word.size() != 0){
      //erase if the beginning of the word has punctuation
      if(ispunct(word[0])){
         word.erase(0,1);

      } else {
         break;   //break when all punctuations at the beginning are erased
      }
   }

   while (word.size() != 0){
      //erase if the ending of the word has punctuation
      if(ispunct(word[word.size()-1])){
         word.erase(word.size()-1,1);

      } else {
         break;   //break when all punctuations at the end are erased
      }
   }
}


//check if the word is stopword
//pre-condition: stopWordValid_ is true
//post-condition: compare word with all stopwords
//return: true if the word is not stopword, false otherwise
bool Concordances::notStopWord(const string& word) const
{
   if(stopWordValid_) {
      string lowCaseWord = word;       //stores lowercase of word
      transform(lowCaseWord.begin(), lowCaseWord.end(), lowCaseWord.begin(), ::tolower);
      
      for(int i = 0; i < stopWords_.size(); i++) {
         string lowCaseStopWord = stopWords_.at(i);   //lowercase of stop word
         transform(lowCaseStopWord.begin(), lowCaseStopWord.end(), lowCaseStopWord.begin(), ::tolower);
         
         //compare 2 lower case version of word and stop word
         if (lowCaseWord == lowCaseStopWord){
            return false;
         }
      }
   }
   return true;
}


//display the concordances of corpus file
//pre-condition: corpus file is valid, BST with keyword is created
//post-condition: printout all keywords in KWIC format
//function called: BST::display()
void Concordances::display() const
{
   concordances_.display();
}