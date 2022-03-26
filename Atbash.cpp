#include <iostream>
#include <string>

using namespace std;

void stringToUpper( string& msg );
string atbashCypher( string msg );

int main(){
    cout << atbashCypher("NLSZNNZW VOIZNOB");
}


void stringToUpper( string& msg ){
    for( int i = 0 ; i < msg.length() ; i++)
        msg[i] = toupper(msg[i]);
}

// it works as cypher and decypher 
string atbashCypher( string msg ){
    string cypheredMsg = "";

    stringToUpper(msg);

    // 0 -> 25 
    for( int i = 0; i < msg.length(); i++) {
        if(msg[i] == ' '){
            cypheredMsg += " ";
            continue;
        }

        int letterIndex = msg[i] % 65;
        int newLetterIndex =  (25 - letterIndex) + 65;
        cypheredMsg += char(newLetterIndex);
    }

    return cypheredMsg;
}

