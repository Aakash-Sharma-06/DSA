class WordDictionary {
public:

    char data;
    WordDictionary* children[26];
    bool isTerminal;

    WordDictionary() {
        data='\0';

        for(int i=0;i<26;i++){
            children[i]=NULL;
        }
        isTerminal=false;
    }
    WordDictionary(char ch) {
        data=ch;

        for(int i=0;i<26;i++){
            children[i]=NULL;
        }
        isTerminal=false;
    }
    
    void addWordUtil(WordDictionary* root,string word){
        if(word.length()==0){
            root->isTerminal=true;
            return;
        }
        int index=word[0]-'a';
        WordDictionary* child;

        if(root->children[index]!=NULL){
            child=root->children[index];
        }
        else{
            child=new WordDictionary(word[0]);
            root->children[index]=child;
        }
        addWordUtil(child,word.substr(1));
    }

    void addWord(string word) {
        addWordUtil(this,word);
    }
    
    bool searchUtil(WordDictionary* root,string word){
        if(word.length()==0){
            return root->isTerminal;
        }

        if(word[0]=='.'){

            for(int i=0;i<26;i++){
                if(root->children[i]!=NULL){
                    
                    if(searchUtil(root->children[i],word.substr(1))){
                        return true;
                    }
                }
            }
            return false;
        }

        int index=word[0]-'a';
        WordDictionary* child;

        if(root->children[index]!=NULL){
            child = root->children[index];
        }
        else{
            return false;
        }
        return searchUtil(child, word.substr(1));
    }

    bool search(string word) {
        return searchUtil(this,word);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */