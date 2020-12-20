#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

//A brief introduction
//Msg : Select the level (Three levels), select the level's words, Sort the words selected and store the words in an array.
//Msg : Select a word.

// GLOBAL VARIALBLES
char g_level;
char g_yesOrNo;

string g_wordslevel1[3] = { "door", "car", "house" };
string g_wordslevel2[3] = { "study", "practice", "thoughtful" };
string g_wordslevel3[3] = { "entertainment", "householder", "thoroughfare" };


// FUNCTIONS
void SelectLevel();
bool CheckChar(int _nOpc);
bool YesOrNo();

// MAIN PROGRAM
int main(){
    cout << "Welcome to the Hangmangame!"<<endl;
    cout << "Here you can test your English spelling knowledge."<<endl;
    cout << "Are you ready?...So let's go!"<<endl;
    SelectLevel();
    return 0;
}

void SelectLevel(){
    selectLevel:
    cout << "\nSelect a round level:[E]=Easy [M]=Medium [A]=Advanced:"<<endl;
    cin >>g_level;
    if (!CheckChar(2)){ //CHECK THE ENTRY WORD, IF NOT TRUE
        if (YesOrNo()){ // CHECK THE ENTRY ANSWER, IF TRUE
            goto selectLevel;
        }else{
            cout<<"\nEnd of game!";
        }
    }else{
        //HERE
    }
}

bool CheckChar(int _nOpc){
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
            if((g_level == 'e' || g_level == 'E') || (g_level == 'm' || g_level == 'M') || (g_level == 'a' || g_level == 'A') ){
                return _lRet=1;
            }else{
                return _lRet=0;    
            }
            break;
        default:
            cout<<"\nWrong insert.";
    }
}

bool YesOrNo(){
    bool yOrNo;
    cout <<"\nSorry it seems you did not insert a valid letter."<<endl;
    cout <<"\nWould you like to try again?[Y]=Yes [N]=No:"<<endl;
    cin >>g_yesOrNo;
    if (CheckChar(1)){
        yOrNo=1;
    }else{
        yOrNo=0;
    }
}