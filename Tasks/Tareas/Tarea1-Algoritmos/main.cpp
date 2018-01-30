#include <iostream>
#include <cstring>

using namespace std;

int checkWord(string word1,string word2){
    char w1[word1.size()+1];
    char w2[word2.size()+1];
    strcpy(w1, word1.c_str());
    strcpy(w2, word2.c_str());

    int i=0;
    for(int c=0; c<=word2.size();c++){
        if(w2[c]==w1[i]){
            i++;
        }
        if(){

        }
    }
    return 1;
}
int main() {
    std::cout << "Hello, World!" << std::endl;
    checkWord("hola","holahola");
    return 0;
}