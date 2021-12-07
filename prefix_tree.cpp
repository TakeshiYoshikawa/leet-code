class Node{
    public:
    char data;
    unordered_map<char, Node*> node;
    bool isWord;
    
    Node(char data){
        this->data = data;
        isWord = false;
    }
};

class Trie {
public:
    Node* root;
    
    Trie() {
        root = new Node(' ');
    }
    
    void insert(string word) {
        Node* current = root;
        
        for(char &c : word){
            if(current->node[c] == nullptr){
                Node* next = new Node(c);
                current->node[c] = next;
            }
            current = current->node[c];
        }
        
        current->isWord = true;
    }
    
    bool search(string word) {
        Node* current = root;
        
        for(char &c : word){
            if(current->node[c] == nullptr)
                return false;
            current = current->node[c];
        }
        
        return current->isWord;
    }
    
    bool startsWith(string prefix) {
        Node* current = root;
        
        for(char &c: prefix){
            if(current->node[c] == nullptr){
                return false;
            }
            current = current->node[c];
        }
        
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
