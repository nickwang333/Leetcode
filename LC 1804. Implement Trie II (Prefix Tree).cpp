struct Node{
    Node* next[26];
    int contain_counter = 0;
    int equal_counter = 0;
};

class Trie {
    Node* root;
public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* tmp = root;
        for(int i=0; i<word.size(); i++){
            if(tmp->next[word[i]-'a'] == NULL){
                tmp->next[word[i]-'a'] = new Node();
            }
            tmp->next[word[i]-'a']->contain_counter++;
            if(i == word.size()-1){
                tmp->next[word[i]-'a']->equal_counter++;
            }
            tmp = tmp->next[word[i]-'a'];
        }
    }
    
    int countWordsEqualTo(string word) {
        Node* tmp = root;
        for(int i=0; i<word.size(); i++){
            if(tmp->next[word[i]-'a'] == NULL){
                tmp->next[word[i]-'a'] = new Node();
            }
            tmp = tmp->next[word[i]-'a'];
        }
        return tmp->equal_counter;
    }
    
    int countWordsStartingWith(string prefix) {
        Node* tmp = root;
        for(int i=0; i<prefix.size(); i++){
            if(tmp->next[prefix[i]-'a'] == NULL){
                tmp->next[prefix[i]-'a'] = new Node();
            }
            tmp = tmp->next[prefix[i]-'a'];
        }
        return tmp->contain_counter;
    }
    
    void erase(string word) {
        Node* tmp = root;
        for(int i=0; i<word.size(); i++){
            if(countWordsEqualTo(word) > 0){
                tmp->next[word[i]-'a']->contain_counter--;
                tmp = tmp->next[word[i]-'a'];
            }
        }
        tmp->equal_counter--;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * int param_2 = obj->countWordsEqualTo(word);
 * int param_3 = obj->countWordsStartingWith(prefix);
 * obj->erase(word);
 */
