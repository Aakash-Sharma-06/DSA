class Trie {
public:

    char data;
    Trie* children[26];
    bool isTerminal;

    Trie() {
        data = '\0';

        for(int i=0;i<26;i++){
            children[i]=NULL;
        }
        isTerminal=false;
    }

    Trie(char ch) {
    data = ch;

    for(int i = 0; i < 26; i++){
        children[i] = NULL;
    }

    isTerminal = false;
}

    void insertUtil(Trie* root,string word){
        if(word.length() == 0){
        root->isTerminal = true;
        return;
        }

        int index = word[0] - 'a';
        Trie* child;

        if(root->children[index] != NULL){
            child = root->children[index];
        }
        else{
            child = new Trie(word[0]);
            root->children[index] = child;
        }

        insertUtil(child, word.substr(1));
    }
    
    void insert(string word) {
        insertUtil(this,word);
    }
    
    bool searchUtil(Trie* root,string word){
        if(word.length()==0){
            return root->isTerminal;
        }

        int index=word[0]-'a';
        Trie* child;

        if(root->children[index]!=NULL){
            child=root->children[index];
        }
        else{
            return false;
        }

        return searchUtil(child,word.substr(1));
    }

    bool search(string word) {
        return searchUtil(this,word);
    }

    bool startUtil(Trie* root,string word){
        if(word.length()==0){
            return true;
        }

        int index=word[0]-'a';
        Trie* child;

        if(root->children[index]!=NULL){
            child=root->children[index];
        }
        else{
            return false;
        }

        return startUtil(child,word.substr(1));
    }
    
    bool startsWith(string prefix) {
        return startUtil(this,prefix);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */