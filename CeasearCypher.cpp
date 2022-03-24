#include <iostream>
#include <string>

using namespace std;

void toLower( string& msg );
string cesarCypher( string msg, int shiftSize );
string cesarDeCypher( string msg, int shiftSize );
bool isAlphabet( char letter );


int main() {

}

// chnage string to lower case 
void toLower( string& msg ){
    for( int i = 0 ; i < msg.length() ;i++){
        msg[i] = tolower(msg[i]);
    }
}

// 97 -> 122
// shift right 


string cesarCypher( string msg, int shiftSize ){
    shiftSize = abs(shiftSize);
    while(shiftSize >= 26){
        shiftSize %= 26;
    }
    toLower(msg);
    string cypherdMsg = "";

    for( int i = 0; i < msg.length() ;i++){
        int letterIndex = int(msg[i]);
        if(isAlphabet(msg[i])){
            if( letterIndex - shiftSize < 97){
                int newLetterIndex = (letterIndex - shiftSize + 26);
                cypherdMsg += char( newLetterIndex );
            }else{
                int newLetterIndex = letterIndex - shiftSize;
                cypherdMsg += char( newLetterIndex );
            }
        }else{
                cypherdMsg += msg[i];
        }


    }


    return cypherdMsg;

}

string cesarDeCypher( string msg, int shiftSize ){
    shiftSize = abs(shiftSize);
    while(shiftSize >= 26){
        shiftSize %= 26;
    }
    toLower(msg);
    string originalMsg = "";

    for( int i = 0; i < msg.length() ; i++){
        int letterIndex = int(msg[i]);
        if( letterIndex + shiftSize > 122){
            int newLetterIndex = (letterIndex + shiftSize - 26);
            originalMsg += char( newLetterIndex );
        }else{
            int newLetterIndex = (letterIndex + shiftSize);
            originalMsg += char( newLetterIndex );
        }
    }




    return originalMsg;

}



bool isAlphabet( char letter ){
    if((letter >= 'a' && letter <= 'z') || (letter >= 'A' && letter <= 'Z'))
        return true;
    return false;
}

