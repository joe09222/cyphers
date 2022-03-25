#include <iostream>
#include <string>

using namespace std;


void Print( char arr[], int arr_size );
string cypher( string msg, string keyword );
string deCypher( string msg , string keyword);
int getCharIndex( char letter, char arr[]);


int main() {

    string yo = cypher("a b c d e f g h i j k l m n o p q r s t u v w x y z","cairo");
    string mo = deCypher("c a i r o b d e f g h j k l m n p q s t u v w x y z","cairo");

    cout << yo << endl;
    cout << mo;

}




// [a,b,c, ....]


// [0,1,2,3,4] 
string cypher( string msg, string keyword ){
    string cypherdMsg = "";
    
    char cypherArr[26];

    // ADD 5 letters in keyword to the array
    for( int i = 0; i < 5 ;i++){
        cypherArr[i] = keyword[i];
    }


    // ADD all alphabets except the first 5 we added
    int arrCurrentIndex = 5;
    for( int i = 97; i < 123 ;i++){
        char letter = char(i);
        // Check if the letter is in the first 5 
        for( int j = 0; j < 5 ;j++){
            //  if we found letter we break from the loop
            if( cypherArr[j] == letter )
            {
                break;
            }
            // if we dont find the letter in the last iteration we add it to the array 
            else if( cypherArr[j] != letter && j == 4)
            {
                cypherArr[arrCurrentIndex] = letter;
                arrCurrentIndex++;
            }
        }
    }

    // now loop on the msg the user enterd and apply the cypher 
    for( int i = 0; i < msg.length() ;i++){
        // check spaces 
        if(msg[i] == ' '){
            cypherdMsg += " ";
            continue;
        }
        
        int charIndex = (msg[i] % 97);         // a -> 97 -> 0, b -> 98 -> 1
        cypherdMsg += cypherArr[charIndex];
    } 

    return cypherdMsg;

}

string deCypher( string msg , string keyword) {
    string originalMsg = "";
    
    char cypherArr[26];

    // ADD 5 letters in keyword to the array
    for( int i = 0; i < 5 ;i++){
        cypherArr[i] = keyword[i];
    }


    // ADD all alphabets except the first 5 we added
    int arrCurrentIndex = 5;
    for( int i = 97; i < 123 ;i++){
        char letter = char(i);
        // Check if the letter is in the first 5 
        for( int j = 0; j < 5 ;j++){
            //  if we found letter we break from the loop
            if( cypherArr[j] == letter )
            {
                break;
            }
            // if we dont find the letter in the last iteration we add it to the array 
            else if( cypherArr[j] != letter && j == 4)
            {
                cypherArr[arrCurrentIndex] = letter;
                arrCurrentIndex++;
            }
        }
    }

    // now loop on the msg the user enterd and return it back 
    for( int i = 0; i < msg.length() ;i++){
        // check spaces 
        if(msg[i] == ' '){
            originalMsg += " ";
            continue;
        }
        
        int charIndex = getCharIndex(msg[i], cypherArr) + 97;
        originalMsg += char(charIndex);
    } 

    return originalMsg;
}

int getCharIndex( char letter, char arr[]){
    for( int i = 0; i < 26;i++){
        if( letter == arr[i])
            return i;
    }
    return -1;
}