// first we struct of trie node
struct trieNode{
trieNode* child[26]; //we considered small alphabets 26;
bool isend;  // it help to find it an end position or not;
trieNode()
{
    isend=false; //initially each node is false and pointing to null value
    for(int i=0;i<26;i++)
    {
        child[i]=NULL; 
    }
}

};


class Trie {
public:
    trieNode* root;
    Trie() {
        root=new trieNode; // here we initiallize node value with root so that we can start;
        
    }
    
    void insert(string word) {
        trieNode*curr = root; //current node =root;
        for(int i=0;i<word.length();i++)
        {
            int index=word[i]-'a'; //word is in char format now we convert it into ASCII value;
            if(curr->child[index]==NULL)//curr pointing child index value is not present than we considered as NULL
            {
                curr->child[index]=new trieNode;// curr point child node as a new trieNode;
            }
            curr=curr->child[index];//shift the current;
        }
        curr->isend=true; // initiallize curr=truel,when we reach to the end;
    }
    
    bool search(string word) {
    trieNode* curr=root; // similar to insert function,changes are true ans false value;
    for(int i=0;i<word.length();i++)
    {
        int index=word[i]-'a';
        if(curr->child[index]==NULL)
        {
            return false;
        }
        curr=curr->child[index];
        
    }        
    return curr->isend;
    }
    
    bool startsWith(string prefix) {
            trieNode*curr=root;//this will used when we have to find out prefix value like in example
            for(int i=0;i<prefix.length();i++)
            {
                int index=prefix[i]-'a';
                if(curr->child[index]==NULL)
                {
                    return false; //if curr not pointing to child index then we return false;
                
                }
                curr=curr->child[index];//c\shift curr position
            }
            return true; //if we reach the end of prefix then we return true;
        }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */