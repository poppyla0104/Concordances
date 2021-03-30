/*Poppy La
Instructor: Dr.Stiber
Course: CSS343
Program 1: Concordaces class
   This class takes a corpus's and stopword's file name, stores them in corpus and
	stopword vectors, indentify if the words are keywords,then add them in a binary 
	search tree. The class process the file, displays the BST in KWIC format.
*/

#pragma once
#include "BST.h"
#include <string>
#include <vector>

using namespace std;

class Concordances
{
	public:
//--------------------------------------------------------------
//                  CONSTRUCTORS & DESTRUCTOR
//--------------------------------------------------------------
   //default contructor
	Concordances();

	//destructor
	~Concordances();

//--------------------------------------------------------------
//                         FUNCTIONS
//--------------------------------------------------------------
	//takes corpus file in parameter and check stopword.txt file, stores in corpus and 
	//stopword vectors,indentify if the words are keywords then add them to BST
	//pre-condition: file name is valid
	//post-condition: create BST that has all keywords
	//function called: Concordances::cleanWord(string&), Concordances::notStopWord(const string&)
	//return: true if corpus file is found and BST is created with all keywords
	bool process(const string&);

	//display the concordances of corpus file
	//pre-condition: corpus file is valid, BST with keyword is created
	//post-condition: printout all keywords in KWIC format
	//function called: BST::display()
	void display() const;


	protected:
	//take a word reference and clean all the punctuation character at the begin & end of word
	//pre-condition: word string is not empty
	//post-condition: word does not contain punctuations at the beginning and ending
	void cleanWord(string&);

	//check if the word is stopword
	//pre-condition: stopWordValid_ is true
	//post-condition: compare word with all stopwords
	//return: true if the word is not stopword, false otherwise
	bool notStopWord(const string&) const;


	private:
//--------------------------------------------------------------
//                          VARIABLES
//--------------------------------------------------------------
	vector<string> corpus_;			//stores all words in corpus file
	vector<string> stopWords_;		//stores all words in stopword.txt 
											//file if file exist
	bool stopWordValid_;				//check if stopword file is valid flag
	BST concordances_;				//Binary search tree off all non-stopword word
	
};