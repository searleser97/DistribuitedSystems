#include "Trie.h"

 // 12
Trie::Trie() {
    root = new Node();
}
  // O(STR.SIZE)
void Trie::insert(const string &str) {
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
Node* Trie::find(const string &str) {
  Node *curr = root;
  for (auto &c : str) {
    if (!curr->ch.count(c)) return nullptr;
    curr = curr->ch[c];
  }
  return curr;
}
// 5
// O(STR.SIZE) number of words matching str
int Trie::strCount(const string &str) {
  Node *node = find(str);
  return node ? node->w : 0;
}