






#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;


struct dicNode {
    char letter;
    vector<dicNode*> child;
    
    dicNode* parent = NULL;
    dicNode(char c){
        letter = c;
    }
    dicNode(){}
};


class dictionary {
private:
    
    dicNode* root;
    string output;
    
public:
    dictionary(){
        root = new dicNode;
    }
    
    bool isExist(string word){
        dicNode *tmp = root;
        for (int i=0; i<word.size(); i++) {
            char wordLetter = tolower(word[i]);
            bool isBreak = false;
            for (int j=0; j<tmp->child.size(); j++) {
                if (tmp->child[j]->letter == wordLetter) {
                    tmp = tmp->child[j];
                    isBreak = true;
                    break;
                }
            }
            if (isBreak==false) {
                return false;
            }
        }
        return true;
    }
    void addWord (string word){
        dicNode *tmp = root;
        for (int i=0; i<word.size(); i++) {
            char wordLetter = tolower(word[i]);
            bool isBreak = false;
            for (int j=0; j < tmp->child.size(); j++) {
                if (tmp->child[j]->letter == wordLetter) {
                    isBreak = true;
                    tmp = tmp->child[j];
                    break;
                }
            }
            if (isBreak == false) {
                dicNode *newNode = new dicNode;
                newNode -> letter = wordLetter;
                tmp->child.push_back(newNode);
                tmp->child[tmp->child.size()-1]->parent = tmp;
                tmp = tmp->child[tmp->child.size()-1];
            }
        }
    }
    void visit(dicNode* s){
        if (s->child.size()==0) {
            printf("%s\n", output.c_str());
            return;
        }
        
        for (int i=0; i<s->child.size(); i++) {
            output.push_back(s->child[i]->letter);
            visit(s->child[i]);
            output.pop_back();
        }
    }
    void traverse(){
        visit(root);
    }
};





int main() {
    
    dictionary D;
    return 0;
}
