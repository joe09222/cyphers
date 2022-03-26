#include <iostream>
#include <string>

using namespace std;

string afiineCypher( string msg );
string afiineDecypher( string msg );
int mod(int a, int b);


int main()
{

    cout <<afiineCypher("affine cipher") << endl;
    cout <<afiineDecypher("ihhwvc SWFRCP");
}

// enc (5x + 8) % 26
// dec 21(y - 8) % 26
// 65 -> 90

void stringToUpper( string& msg ){
    for(int i = 0; i < msg.length() ;i++)
        msg[i] = toupper(msg[i]);
}

// (a * c) mod 26  = 1   < == req 

string afiineCypher( string msg, int a, int b){
    string cypheredMsg = "";                // variable to store cyphered message
    stringToUpper( msg );                   // convert msg to uppercase 

    // loop over every letter in input msg   
    for( int i = 0; i < msg.length(); i++){
        // if letter is space we add space 
        if( msg[i] == ' '){
            cypheredMsg += " ";
            continue;
        }

        int letterIndex = int(msg[i]) % 65;             // get letter indexes, A -> 65 -> 0 | B -> 66 -> 1 | ...
        int newIndex = ( a*letterIndex + b ) % 26;      // affine algorthim
        cypheredMsg += char(newIndex + 65);             // the letter we want in the newPos + 65
    }

    return cypheredMsg;
}


string afiineDecypher( string msg, int b, int c ){
    string originalMsg = "";                // variable to store cyphered message
    stringToUpper( msg );                   // convert msg to uppercase 

    // loop over every letter in input msg   
    for( int i = 0; i < msg.length(); i++){
        // if letter is space we add space 
        if( msg[i] == ' '){
            originalMsg += " ";
            continue;
        }

        int letterIndex = int(msg[i]) % 65;                 // get letter indexes, A -> 65 -> 0 | B -> 66 -> 1 | ...
        // affine algorthim
        int op1 = c * (letterIndex - b);
        int newIndex = mod(op1, 26);       

        originalMsg += char(newIndex + 65);                 // the letter we want in the newPos + 65
    }

    return originalMsg;
}

// function that handles negative mod
int mod(int a, int b)
{
    int r = a % b;
    return r < 0 ? r + b : r;
}