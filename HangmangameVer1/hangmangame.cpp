#include<iostream>

using namespace std;

//A brief introduction
//Msg : Select the level (Three levels), select the level's words, Sort the words selected and store the words in an array.
//Msg : Select a word. 
int level;
char wordsLevel1[3]={'door','car','house'};
char wordsLevel2[3]={'study','practice','thoughtful'};
char wordsLevel3[3]={'entertainment','householder','thoroughfare'};

int main(){
    cout << "Select a round level:[E]=Easy [M]=Medium [A]=Advanced";
    cin >>level;
    return 0;
}