#include<bits/stdc++.h>
using namespace std;
// 3
// wpt = number of words passing through
// w = number of words ending in the node
// c = character
// 8

struct Node {
    // for lexicographical order use 'map'
    // map<char, Node *> ch;
    unordered_map<char, Node *> ch;
    int w = 0, wpt = 0;
};

class Trie {
  public:
    Node *root;
  // 12
  public:
    Trie();
    // O(STR.SIZE)
    void insert(const string &str); 
    // 9
    // O(STR.SIZE)
    Node *find(const string &str);
    // 5
    // O(STR.SIZE) number of words matching str
    int strCount(const string &str);
};