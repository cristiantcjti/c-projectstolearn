#include<iostream>
#include<string>
#include<cstdlib>
#include<windows.h>

//#include <bits/stdc++.h> 

using namespace std;

// GLOBAL VARIALBLES
int  g_level;
int  g_word;
char g_letter;
char g_yesOrNo;

// FUNCTIONS
bool SelectLevel();
bool CheckInput(int _nOpc);
bool TryAgain();
string SelectWord();
void PrintWord(string *aRet,int size, int attempts);
bool TakeWord(bool check,char *_cWordCheck, int sizeWord,string *aRet);
bool CheckWords(string *_aPrevRet, string *_aRet,int size,int *_nCount);
bool PlayAgain();

// MAIN PROGRAM
int main(){
    cout << "\nWelcome to the Hangmangame!"<<endl;
    Sleep(1000);
    cout << "\nHere you can test your English spelling knowledge."<<endl;
    Sleep(1000);
    cout << "\nLet's do it?..."<<endl;
    Sleep(1000);
    cout<<"\nSo let's go!"<<endl;
    Sleep(1000);
    playagain:
    string _cWord;
    string _aRet;
    int sizeWord;
    int attempts=5;
    if(SelectLevel()){
        _cWord = SelectWord();
        sizeWord = _cWord.size();
        string _aRet[sizeWord];
        string _aPrevRet[sizeWord];
        char _cWordCheck[sizeWord];
        int _nCount=0;
        strcpy(_cWordCheck, _cWord.c_str());
        TakeWord(false,_cWordCheck,sizeWord,_aRet);
        do{
            PrintWord(_aRet,sizeWord,attempts);
            copy(_aRet, _aRet+sizeWord, _aPrevRet);
            cout<<"\nType a letter: ";
            cin>>g_letter;
            if (!TakeWord(true,_cWordCheck,sizeWord,_aRet)){
                attempts--;
            }
            CheckWords(_aPrevRet,_aRet,sizeWord,&_nCount);
            if(_nCount == sizeWord){
                PrintWord(_aRet,sizeWord,attempts);
                cout<<"\n\nYou got it. Congratulations!!!";
                break;
                }
        }while(attempts>0);  
    }
    if(!attempts>0){
        system("cls");
        cout<<"\nSorry but you failed.\n";
    }
    if(PlayAgain()){
        system("cls");
        goto playagain;
    }else{
        cout<<"End of the game.";
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
    string g_wordslevel1[3] = { "door", "car", "house" };
    string g_wordslevel2[3] = { "study", "practice", "thoughtful" };
    string g_wordslevel3[3] = { "entertainment", "householder", "thoroughfare" };
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
    //g_yesOrNo;
    cout <<"\nSorry it seems you did not insert a valid entry."<<endl;
    cout <<"\nWould you like to try again?[Y]=Yes [N]=No: ";
    cin >>g_yesOrNo;
    if (CheckInput(1)){
        return yOrNo=1;
    }else{
        return yOrNo=0;
    }
}

bool TakeWord(bool check,char *_cWordCheck, int sizeWord, string *aRet){
    bool lRet=0;
    if(!check){
        for(int x=0; x<sizeWord; x++){
            aRet[x] = "_ ";
        }    
    }else{
        for(int x=0; x<sizeWord; x++){
            if(_cWordCheck[x] == g_letter){
                aRet[x] = g_letter;
                lRet=1; 
            }else{
                aRet[x] = "_ "; 
            } 
        }
    }
    return lRet;
}

void PrintWord(string *aRet,int size, int attempts){
    system("cls");
    cout<<"Attempts remaining: "<<'['<<attempts<<']';
    cout<<"\n\n";
    for(int x=0; x < size; x++ ){
        cout<<aRet[x];
    }
}

bool CheckWords(string *_aPrevRet, string *_aRet,int size,int *_nCount){
    *_nCount=0;
    for(int x = 0; x < size; x++){
        if((_aPrevRet[x] != "_ ") && (_aRet[x] == "_ ")){
            _aRet[x]=_aPrevRet[x];
        }
        if(_aRet[x] != "_ "){
            *_nCount+=1;
        }
    }
}
bool PlayAgain(){
    bool yOrNo;
    //g_yesOrNo;
    cout <<"\nWould you like to play again?[Y]=Yes [N]=No: ";
    cin >>g_yesOrNo;
    if (CheckInput(1)){
        return yOrNo=1;
    }else{
        return yOrNo=0;
    }
}