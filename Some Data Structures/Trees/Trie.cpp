//
//  main.cpp
//  Trie
//
//  Created by Daniel García Molero on 09/05/2017.
//  Copyright © 2017 Daniel García Molero. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    Node() {mContent = ' '; mMarker = 0;}
    ~Node() {}
    char content() {return mContent;}
    void setContent(char c) {mContent = c;}
    size_t wordMarker() {return mMarker;}
    void setWordMarker() {mMarker++;}
    Node* findChild(char c);
    void appendChild(Node* child) {mChildren.push_back(child);}
    vector<Node*> children() {return mChildren;}
    
private:
    char mContent;
    size_t mMarker;
    vector<Node*> mChildren;
};

class Trie {
public:
    Trie();
    ~Trie();
    void addWord(string s);
    void addWord2(string s);
    size_t searchWord(string s);
    void deleteWord(string s);
private:
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
    // Free memory
}

void Trie::addWord(string s) {
    addWord2(s);
    if (s.length() > 1) { //Insert backwards!!!
        reverse(s.begin(), s.end());
        addWord2(s);
    }
}

void Trie::addWord2(string s) {
    Node* current = root;
    
    if (s.length() == 0) {
        current->setWordMarker(); // an empty word
        return;
    }
    
    for (int i = 0; i < s.length(); i++) {
        Node* child = current->findChild(s[i]);
        if (child != NULL) {
            current = child;
        } else {
            Node* tmp = new Node();
            tmp->setContent(s[i]);
            current->appendChild(tmp);
            current = tmp;
        }
        if (i == s.length() - 1) current->setWordMarker();
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
    
    return false;
}

int main() {
    Trie trie = Trie();
    trie.addWord("1");
    trie.addWord("1");
    trie.addWord("001");
    cout << "2 " << trie.searchWord("1") << endl;
    cout << "0 " << trie.searchWord("0") << endl;
    cout << "1 " << trie.searchWord("001") << endl;
    cout << "1 " << trie.searchWord("100") << endl;
    return 0;
}
