//
//  main.cpp
//  Tema10-01
//
//  Created by Daniel García Molero on 10/05/2017.
//  Copyright (c) 2017 Daniel García Molero. All rights reserved.
//

#include <string>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

struct singleNums {
	size_t zeroes;
	size_t ones;
};

class Node {
public:
	Node() { mContent = ' '; mMarker = 0; mWord = false; }
	~Node() {}
	char content() { return mContent; }
	void setContent(char c) { mContent = c; }
	size_t wordMarker() { return mMarker; }
	void increaseWordMarker() { mMarker++; }
	void setWordMarker() { mWord = true; }
	Node* findChild(char c);
	void appendChild(Node* child) { mChildren.push_back(child); }
	vector<Node*> children() { return mChildren; }

private:
	char mContent;
	size_t mMarker;
	bool mWord;
	vector<Node*> mChildren;
};

class Trie {
public:
	Trie();
	~Trie();
	void addWord(string s); //Adds a single word
	void updateWith(string s); //Updates the numbers on the trie using private function
	size_t searchWord(string s);
private:
	void updateTrie(string s);
	Node* root;
};

Node* Node::findChild(char c) {
	for (int i = 0; i < mChildren.size(); i++) {
		Node* tmp = mChildren.at(i);
		if (tmp->content() == c) {
			return tmp;
		}
	}

	return NULL;
}

Trie::Trie() {
	root = new Node();
}

Trie::~Trie() {
	//Free memory
}

void Trie::addWord(string s) {
	Node* current = root;

	if (s.length() == 0) {
		current->setWordMarker(); //Empty word!!!
		return;
	}

	for (int i = 0; i < s.length(); i++) {
		Node* child = current->findChild(s[i]);
		if (child != NULL) {
			current = child;
		}
		else {
			Node* tmp = new Node();
			tmp->setContent(s[i]);
			current->appendChild(tmp);
			current = tmp;
		}
		if (i == s.length() - 1) current->setWordMarker();
	}
}

void Trie::updateWith(string s) {
	for (size_t i = 0; i < s.length(); i++) {
		updateTrie(s.substr(i, s.length() - i));
	}
	
	reverse(s.begin(), s.end());

	for (size_t i = 0; i < s.length(); i++) {
		updateTrie(s.substr(i, s.length() - i));
	}
}

void Trie::updateTrie(string s) {
	//cout << "ADDED TO TRIE: " << s << endl;
	Node* current = root;

	if (s.length() == 0) {
		current->increaseWordMarker(); //Empty word!!!
		return;
	}

	for (int i = 0; i < s.length(); i++) {
		Node* child = current->findChild(s[i]);
		if (child != NULL) {
			current = child;
		}
		else { break; }
		/*else {
			Node* tmp = new Node();
			tmp->setContent(s[i]);
			current->appendChild(tmp);
			current = tmp;
		}*/

		/*Node* n000 = root->findChild('0')->findChild('0')->findChild('0');
		if (current == n000) cout << "000 ADDED!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
		*/
		current->increaseWordMarker();
	}
}

size_t Trie::searchWord(string s) {
	Node* current = root;
	while (current != NULL) {
		for (int i = 0; i < s.length(); i++) {
			Node* tmp = current->findChild(s[i]);
			if (tmp == NULL) return false;
			current = tmp;
		}
		return current->wordMarker();
	}
}

//TRIE CLASS END.

void analyzeSingleLetters(const vector<string> &puzzle, singleNums &sn) {
	for (size_t line = 0; line < puzzle.size(); ++line) {
		sn.zeroes += count(puzzle[line].begin(), puzzle[line].end(), '0');
		sn.ones += count(puzzle[line].begin(), puzzle[line].end(), '1');
	}
}

void analyzeRows(const vector<string> &puzzle, Trie &trie, const size_t &width) {
	if (width == 1) return; //Does NOT take single character strings into account!
	for (size_t row = 0; row < puzzle.size(); ++row) {
		trie.updateWith(puzzle[row]);
	}
}

void analyzeCols(const vector<string> &puzzle, Trie &trie, const size_t &width) {
	if (puzzle.size() == 1) return; //Does NOT take single character strings into account!
	string word = "";
	for (size_t column = 0; column < width; ++column) {
		for (size_t rowIndex = 0; rowIndex < puzzle.size(); ++rowIndex) {
			word.push_back(puzzle[rowIndex][column]);
		}
		trie.updateWith(word);
		word = "";
	}
}

//Returns the diagonal starting on the given coordinates
string getUpDownDiagonal(const vector<string> &puzzle, const size_t &row, const size_t &col, const size_t &width) {
	string word = "";
	int currentRow = row, currentCol = col;
	while (currentRow < puzzle.size() && currentCol < width) {
		word.push_back(puzzle[currentRow][currentCol]);
		++currentRow;
		++currentCol;
	}
	return word;
}

/*Analyzes diagonals that go in a SouthEast (or NorthWest) direction.
It will follow this pattern:
234X
1---
X---
(It does NOT take isolated corner numbers into account, marked as X)
*/
void analyzeDiagonalsUpDown(const vector<string> &puzzle, Trie &trie, const size_t &width) {
	int row = puzzle.size() - 2, col = 0;
	while (row >= 0) {
		trie.updateWith(getUpDownDiagonal(puzzle, row, col, width));
		--row;
	}
	row = 0;
	++col;
	while (col < width - 1) {
		trie.updateWith(getUpDownDiagonal(puzzle, row, col, width));
		++col;
	}
}

//Returns the diagonal starting on the given coordinates
string getDownUpDiagonal(const vector<string> &puzzle, const size_t &row, const size_t &col, const size_t &width) {
	string word = "";
	int currentRow = row, currentCol = col;
	while (currentRow >= 0 && currentCol < width) {
		word.push_back(puzzle[currentRow][currentCol]);
		--currentRow;
		++currentCol;
	}
	return word;
}

/*Analyzes diagonals that go in a NorthEast (or SouthWest) direction.
It will follow this pattern:
X---
1---
234X
(It does NOT take isolated corner numbers into account, marked as X)
*/
void analyzeDiagonalsDownUp(const vector<string> &puzzle, Trie &trie, const size_t &width) {
	int row = 1, col = 0;
	while (row < puzzle.size()) {
		trie.updateWith(getDownUpDiagonal(puzzle, row, col, width));
		++row;
	}
	row = puzzle.size() - 1;
	++col;
	while (col < width - 1) {
		trie.updateWith(getDownUpDiagonal(puzzle, row, col, width));
		++col;
	}
}

void analyze(const vector<string> &puzzle, const size_t &width, Trie &trie, singleNums &sn) {
	analyzeSingleLetters(puzzle, sn);
	//cout << "ADDED SINGLE LETTERS" << endl;
	analyzeRows(puzzle, trie, width);
	//cout << "ADDED ROWS" << endl;
	analyzeCols(puzzle, trie, width);
	//cout << "ADDED COLS" << endl;
	analyzeDiagonalsUpDown(puzzle, trie, width);
	//cout << "ADDED DIAG UP DOWN" << endl;
	analyzeDiagonalsDownUp(puzzle, trie, width);
	//cout << "ADDED DIAG DOWN UP" << endl;
}

bool solve() {
	size_t width, height;
	cin >> width >> height;
	if (!cin) return false;
	vector<string> puzzle(height);
	vector<string> words;
	for (size_t i = 0; i < height; ++i) {
		cin >> puzzle[i];
	}

	size_t wordsToSearch;
	cin >> wordsToSearch;

	Trie trie = Trie();
	string aux;
	for (size_t j = 0; j < wordsToSearch; ++j) {
		cin >> aux;
		words.push_back(aux);
		trie.addWord(aux);
	}

	singleNums sn;
	sn.ones = 0;
	sn.zeroes = 0;

	sort(words.begin(), words.end());
	analyze(puzzle, width, trie, sn);

	size_t count;
	for (size_t i = 0; i < words.size(); i++) {
		if (words[i].length() > 1) {
			count = trie.searchWord(words[i]);
			if (count > 0) {
				cout << words[i] << " " << count << endl;
			}
		}
		else {
			if (words[i] == "0" && sn.zeroes > 0) {
				cout << words[i] << " " << sn.zeroes << endl;
			}
			else if (words[i] == "1" && sn.ones > 0) {
				cout << words[i] << " " << sn.ones << endl;
			}
		}
	}
	cout << "---" << endl;
	return true;
}

int main() {
	while (solve());
	return 0;
}