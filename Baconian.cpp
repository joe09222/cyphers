#include <iostream>
#include <string>

using namespace std;

void binaryToCode( string& binary );
void codeToBinary( string& code );
string baconianCypher( string msg );
void stringToUpper( string& msg );
int getIndex( string item, string arr[] );
string baconianDecypher( string msg );


int main() {
    cout << baconianCypher( "youssef mohsen" ) << endl;
    cout << baconianDecypher( "bbaaaabbbababaabaababaabaaabaaaabab abbaaabbbaaabbbbaabaaabaaabbab" );
}


void stringToUpper( string& msg ){
    for( int i = 0 ; i < msg.length() ;i++)
        msg[i] = toupper(msg[i]);
    
}

void binaryToCode( string& binary ) {
    for( int i = 0; i < binary.length() ; i++){
        if (binary[i] == '1')
            binary[i] = 'b';
        else 
            binary[i] = 'a';
    }
}


void codeToBinary( string& code ) {
    for( int i = 0; i < code.length() ; i++){
        if (code[i] == 'b')
            code[i] = '1';
        else 
            code[i] = '0';
    }
}


int getIndex( string item, string arr[] ){
    for( int i = 0; i < 26 ;i++){
        if(item == arr[i]){
            return i;
        }
    }
    return -1;
}

string baconianCypher( string msg ) {

    string cypheredMsg = "";

    stringToUpper( msg );

    string refrenceArray[26] = {
        "00000","00001","00010","00011","00100","00101",
        "00110","00111","01000","01001","01010","01011",
        "01100","01101","01110","01111","10000","10001",
        "10010","10011","10100","10101","10110","10111",
        "11000","11001"
    };

    // loop over evey letter in msg and convert it 
    for( int i = 0; i < msg.length() ; i++){
        if( msg[i] == ' '){
            cypheredMsg += " ";
            continue;
        }

        int letterIndex = msg[i] % 65;                      // get letter index
        string letterBinary = refrenceArray[letterIndex];   // get letter binary from ref array
        binaryToCode(letterBinary);                         // convert binary to its code
        cypheredMsg += letterBinary;
    }

    return cypheredMsg;
}



string baconianDecypher( string msg ) {

    string originalMsg = "";


    string refrenceArray[26] = {
        "00000","00001","00010","00011","00100","00101",
        "00110","00111","01000","01001","01010","01011",
        "01100","01101","01110","01111","10000","10001",
        "10010","10011","10100","10101","10110","10111",
        "11000","11001"
    };

    // loop over evey letter in msg and convert it 
    int lettersFound = 0;           // trace letters found
    string currentCode = "";        // add letters to this code when tracing 
    for( int i = 0; i < msg.length() ; i++){
        // add space if we find space 
        if( msg[i] == ' '){
            originalMsg += " ";
            continue;
        }
        // if not then we found a letter 
        lettersFound ++;                // increment letter by 1
        currentCode += msg[i];          // add letter to code
        if( lettersFound  == 5 ){       // if we have 5 letter then we have a single code
            lettersFound = 0;           // reset letters found to 0
            codeToBinary( currentCode );// get binary of the code 
            int letterIndex = getIndex( currentCode, refrenceArray );   // get letter index from the binary code
            originalMsg += char( letterIndex ) + 65;                    // add the new char
            currentCode = "";                                           // reset code
        }   

    }

    return originalMsg;
}



