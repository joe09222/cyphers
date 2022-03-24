#include <iostream>
#include <string>

using namespace std;

// 1 dash between letters 
// 3 dashes between words


string morseCodeCypher( string msg );
void toLower( string& msg );
string morseDeCypher( string msg );
int getIndex( string item  ,string arr[] , int size );


int main(){


    string original = "hello world";

    string cypher = morseCodeCypher(original);
    string deCypher = morseDeCypher(cypher);


    cout << "original msg is: " << original << endl;
    cout << "cyphered msg is: " << cypher << endl;
    cout << "decyphered msg is: " << deCypher << endl;



}


// chnage string to lower case 
void toLower( string& msg ){
    for( int i = 0 ; i < msg.length() ;i++){
        msg[i] = tolower(msg[i]);
    }
}



string morseCodeCypher( string msg ){
    // morse code in alphabtical order  0 -> a, 1 -> b, ...
    string mosreRefrence[26] = {
        ".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--",
        "-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."
    };

    string cypheredMsg = "";    // variable to store cyphererd msg

    toLower( msg );             // make the input msg to lowercase

    //  loop on every char in msg 
    for( int i = 0; i < msg.length() ;i++){
        int charIndex = int(msg[i]) % 97;   // get it's index in the morse refrence 
        if ( charIndex == 32)   // space 
            cypheredMsg += "   ";   // add 3 dashes
        else{
            cypheredMsg += mosreRefrence[charIndex];    // add corrosponding letter morse code to cyphered message
            cypheredMsg += " ";     // then add 1 dash
        }
    }

    return cypheredMsg;         // return cyphered message

}


string morseDeCypher( string msg ){
    // morse code in alphabtical order  0 -> a, 1 -> b, ...
    string mosreRefrence[26] = {
        ".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--",
        "-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."
    };


    string originalMsg = "";        // variable that will store original message

    string currentCode = "";        // current morse code from the string 
    int spaceRepetation = 0;        // how many consecutive spaces we counted
    bool foundCode = false;         // if we found a code after spaces

    // loop over morse code
    for( int i = 0; i < msg.length() ; i++){
        if( msg[i] == ' '){         // if we found dash
            spaceRepetation += 1;   // increment space repeatation 
            foundCode = true;       // we found a code
            continue;               // we loop again
        }else if ( spaceRepetation >= 1 && foundCode == true){      // if we have space repetation then that means we have a code in the current code

            int codeIndex = getIndex(currentCode, mosreRefrence, 26);   // get code index from the morse refrence
            int charIndex = 97 + codeIndex;             // get char from code index
            originalMsg += char(charIndex);             // add char to the original msg

            // if we have 4 or more than that we add space as 3 dashes crosspond to 1 space
            while( spaceRepetation >= 4){   
                originalMsg += " ";
                spaceRepetation -= 3;
            }
            spaceRepetation = 0;    // we reset space seperations

            currentCode = "";       // reset current code

        }

        currentCode += msg[i];     // add letter from code to current code if both cases are not ture

    }
    // we do it again bcz we cant trigger last time as there's no more spaces 
    int codeIndex = getIndex(currentCode, mosreRefrence, 26);
    int charIndex = 97 + codeIndex;
    originalMsg += char(charIndex);


    return originalMsg ;
}

int getIndex( string item  ,string arr[] , int size ){

    for( int i = 0 ; i < size ; i++){
        if(arr[i] == item){
            return i;
        }
    }
    return -1;
}