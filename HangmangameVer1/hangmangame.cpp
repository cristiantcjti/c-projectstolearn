#include <iostream>
#include <string>
#include <cstdlib>
#include <bits/stdc++.h> 

using namespace std;

// GLOBAL VARIALBLES
int  g_level;
int  g_word;
char g_yesOrNo;

//string g_wordslevel1[] = { "door", "car", "house" };
//string g_wordslevel2[] = { "study", "practice", "thoughtful" };
//string g_wordslevel3[] = { "entertainment", "householder", "thoroughfare" };


// FUNCTIONS
bool SelectLevel();
bool CheckInput(int _nOpc);
bool TryAgain();
string SelectWord();

// MAIN PROGRAM
int main(){
    string _cWord;
    cout << "Welcome to the Hangmangame!"<<endl;
    cout << "Here you can test your English spelling knowledge."<<endl;
    cout << "Are you ready?...So let's go!"<<endl;
    if(SelectLevel()){
        _cWord = SelectWord();
        cout<<_cWord; // here
    }
    return 0;
}

bool SelectLevel(){
    selectLevel:
    bool _lRet = 0;
    g_level = 0;
    cout << "\nSelect a round level:[1]=Easy [2]=Medium [3]=Advanced: ";
    cin >>g_level;
    if (!CheckInput(2)){ //CHECK THE ENTRY WORD, IF NOT TRUE
        if (TryAgain()){ // CHECK THE ENTRY ANSWER, IF TRUE
            goto selectLevel;
        }else{
            cout<<"\nEnd of game!";
        }
    }else{
        return _lRet=1;
    }
}

string SelectWord(){
    g_word = 0;
    string g_wordslevel1[] = { "door", "car", "house" };
    string g_wordslevel2[] = { "study", "practice", "thoughtful" };
    string g_wordslevel3[] = { "entertainment", "householder", "thoroughfare" };
    cout <<"\nSelect a word: [1]=Word 1 [2]=Word 2 [3]=Word 3: ";
    cin >>g_word;

    if(!CheckInput(3)){
        if (TryAgain()){ // CHECK THE ENTRY ANSWER, IF TRUE
            SelectWord();
        }else{
            cout<<"\nEnd of game!";
        }            
    }

    if(g_level == 1){
        return g_wordslevel1[g_word-1];   
    }else if(g_level == 2){
        return g_wordslevel2[g_word-1];
    }else{
        return g_wordslevel3[g_word-1]; 
    }   
}

bool CheckInput(int _nOpc){
    bool _lRet;
    switch(_nOpc){
        //YES OR NO
        case 1:
            if(g_yesOrNo == 'y' || g_yesOrNo == 'Y'){
                return _lRet=1;
            }else{
                return _lRet=0;    
            }
            break;
        //SELECTED LEVEL
        case 2:
            if(g_level == 1 || g_level == 2 || g_level == 3){
                return _lRet=1;
            }else{
                return _lRet=0;    
            }
            break;
        case 3:
            if(g_word == 1 || g_word == 2 || g_word == 3){
                return _lRet=1;
            }else{
                return _lRet=0;    
            }
            break;
        default:
            cout<<"\nWrong insert.";
    }
}

bool TryAgain(){
    bool yOrNo;
    g_yesOrNo;
    cout <<"\nSorry it seems you did not insert a valid entry."<<endl;
    cout <<"\nWould you like to try again?[Y]=Yes [N]=No: ";
    cin >>g_yesOrNo;
    if (CheckInput(1)){
        return yOrNo=1;
    }else{
        return yOrNo=0;
    }
}

