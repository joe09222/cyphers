// FCAI – Programming 1 – 2022 - Assignment 2
// Program Name: Rail-fence-Cipher-20210549.cpp
// Program Description: how to find square root of any float number with Bakhshali Approximation
// Last Modification Date: 3/15/2022
// Author1 and ID and Group: Youssef Mohsen Mohamed and 20210549 and All
// Teaching Assistant: NONE
// Purpose: how to find square root of any float number with Bakhshali Approximation

#include <iostream>
#include <string>
#include <limits>



std::string cypher( std::string msg, int depth);
std::string deCypher( std::string cypherd_msg, int depth );




int main(){
    
}





//  Rail fence cypher with dynamic depth and no input string changes
std::string cypher( std::string msg, int depth ){
    // Dont allow any depth less than 2 
    if( depth < 2 ){
        std::cout << "DEPTH SHOULD BE 2 OR MORE" << std::endl;
        return "ERROR";
    }

    std::string cypherdMsg = "";               // variable that stores the cypher
    int msgLength = msg.length();              // length of incoming string { no of columns }

    // depth is the no of rows
    std::string cypherArr[depth][msgLength];  // make a 2D array with those sizes
    
    // Fill the whole array with (!) to determine the empty spaces {FLAGS}
    for(int i = 0; i < depth ;i++){
        for( int j= 0; j < msgLength ;j++){
            cypherArr[i][j] = "!";
        }
    }

    bool isUpToDown = true;         // direction of diagonal movement
    int currentRow = 0;             // current Row
    int currentColumn = 0;          // current Column
    // loop thorugh the given string and add them to the 2d array in diagnol order
    for( int i =0 ; i < msgLength ;i++){
        cypherArr[currentRow][currentColumn] = msg[i];

        currentColumn ++;               // column always incrementing
        
        // Decide wether we are moving {up to down or down to up}
        // if we are at the max row which is (depth - 1) we need to (move down to up)
        if( currentRow == depth - 1){
            isUpToDown = false;
        }
        if( isUpToDown == true )        // if we are moving up to down we need to inc the row number
            currentRow++;
        else {
            currentRow --;             // if not we are moving down to up so we need to dec row number 
            if( currentRow == 0){     // check if we at the min row if so we reverse our direction
                isUpToDown = true;
            }
        }
    }
    
    // Loop through our final cypher array and add all the letters  that are not ! to the cypherd msg
    for(int i = 0; i < depth ; i++){
        for( int j= 0; j < msgLength ;j++){
            if( cypherArr[i][j] != "!"){
                cypherdMsg += cypherArr[i][j];
            }
        }
    }

    std::cout << "cypherd msg: " << cypherdMsg << std::endl;
    return cypherdMsg;
}



//  Rail fence decypher with dynamic depth { plz dont forget the original depth :( }
std::string deCypher( std::string cypherd_msg, int depth ){
    // Dont allow any depth less than 2 
    if( depth < 2 ){
        std::cout << "DEPTH SHOULD BE 2 OR MORE" << std::endl;
        return "ERROR";
    }

    int msgLength = cypherd_msg.length();                  // no of columns
    
    std::string originalMsg = "";                          // decypherd msg
    std::string cypherArr[depth][msgLength];               // make 2d array with depth as rows and msg_given as columns
    
    // Fill the array with (!) to determine the empty spaces {FLAGS}
    for(int i = 0; i < depth ;i++){
        for( int j= 0; j < msgLength ;j++){
            cypherArr[i][j] = "!";
        }
    }

    int currentColumn = 0;
    int currentRow = 0;
    bool isUpToDown = true;

    //  loop thorugh the msg and mark it's places in diagonal manner with $ sign
    for( int i = 0; i < msgLength ;i++){
        cypherArr[currentRow][currentColumn] = "$";


        currentColumn ++;  
        // Decide wether we are moving {up to down or down to up}
        // if we are at the max row which is (depth - 1) we need to (move down to up)
        if( currentRow == depth - 1){
            isUpToDown = false;
        }
        if( isUpToDown == true )        // if we are moving up to down we need to inc the row number
            currentRow++;
        else {
            currentRow --;             // if not we are moving down to up so we need to dec row number 
            if( currentRow == 0){     // check if we at the min row if so we reverse our direction
                isUpToDown = true;
            }
        }
    }

    int index = 0;                      // index that traces every letter in the cypherd message
    // loop thorugh our matrix and Replace every $ sign with letter in the cypherd msg
    for(int i = 0; i < depth ; i++){
        for( int j= 0; j < msgLength ;j++){
            if(cypherArr[i][j] == "$"){
                cypherArr[i][j] = cypherd_msg[index];
                index++;
            }
        }
    }
    // loop thorugh the matrix again and add the letters in diagonal manner to our original message
    currentColumn = 0;
    currentRow = 0;
    isUpToDown = true;
    for(int i = 0; i < msgLength ; i++){
        originalMsg +=  cypherArr[currentRow][currentColumn];


        currentColumn ++;  
        // Decide wether we are moving {up to down or down to up}
        // if we are at the max row which is (depth - 1) we need to (move down to up)
        if( currentRow == depth - 1){
            isUpToDown = false;
        }
        if( isUpToDown == true )        // if we are moving up to down we need to inc the row number
            currentRow++;
        else {
            currentRow --;             // if not we are moving down to up so we need to dec row number 
            if( currentRow == 0){     // check if we at the min row if so we reverse our direction
                isUpToDown = true;
            }
        }      
    }


    std::cout << "decypherd msg: " << originalMsg << std::endl;
    return originalMsg;
}