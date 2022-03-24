#include <iostream>
#include <string>

using namespace std;

void stringToUpper( string& msg );
string vignereCypher( string msg, string keyword);
bool isAlphabet( char letter );



int main(){

    string up = vignereCypher("due november 4", "hwone");

    cout << up;
}

void stringToUpper( string& msg ){
    for( int i = 0; i < msg.length(); i++){
        msg[i] = toupper(msg[i]);
    }
}

string vignereCypher( string msg, string keyword) {

    stringToUpper(msg);
    stringToUpper(keyword);

    string cypheredMsg = "";

    // generate string with keyword that matches or exceeds the original msg
    string completeKeyword = "";
    int keywordNumber = msg.length() / keyword.length() + 1 ;
    for( int i = 0; i < keywordNumber ;i++){
        completeKeyword += keyword;
    }

    // loop through the original message and do our algorthim 
    for( int i = 0; i < msg.length(); i++) {
        
        if(isAlphabet(msg[i])){
            int originalLetterIndex = int(msg[i]);
            int keywordLetterIndex = int(completeKeyword[i]);
            int newIndex = (( originalLetterIndex + keywordLetterIndex ) % 26) + 65 ;

            cypheredMsg += char(newIndex);
        }else{
            cypheredMsg += msg[i];
        }
    }

    return cypheredMsg;
}


bool isAlphabet( char letter ){
    if((letter >= 'a' && letter <= 'z') || (letter >= 'A' && letter <= 'Z'))
        return true;
    return false;
}