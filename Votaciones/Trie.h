#include<bits/stdc++.h>
using namespace std;
// 3
// wpt = number of words passing through
// w = number of words ending in the node
// c = character
// 8
struct Trie {

  struct Node {
    // for lexicographical order use 'map'
    // map<char, Node *> ch;
    unordered_map<char, Node *> ch;
    int w = 0, wpt = 0;
  };
  // 12
  Node *root = new Node();

  // O(STR.SIZE)
  void insert(const string &str) {
    Node *curr = root;
    for (auto &c : str) {
      if (!curr->ch.count(c))
        curr->ch[c] = new Node();
      curr->wpt++, curr = curr->ch[c];
    }
    curr->wpt++, curr->w++;
  }
  // 9
  // O(STR.SIZE)
  Node *find(const string &str) {
    Node *curr = root;
    for (auto &c : str) {
      if (!curr->ch.count(c)) return nullptr;
      curr = curr->ch[c];
    }
    return curr;
  }
  // 5
  // O(STR.SIZE) number of words matching str
  int strCount(const string &str) {
    Node *node = find(str);
    return node ? node->w : 0;
  }
};