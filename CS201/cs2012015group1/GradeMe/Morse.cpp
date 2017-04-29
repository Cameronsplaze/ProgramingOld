/*

Cameron Showalter
Finished 12-4-2015

Teacher: Brandon M.
CS 201 project
V: 1.Whatever

*/


#include "Crypto.h"
#include <cstring>
#include <iostream>
using namespace std;

// Makes sure value i is not greater that LENGTH otherwise pointer would point off the array.
int maxLength(int i, int LENGTH);

// basically does strlen() without breaking Brandon's stupid string rules
//(Unless you are Brandon, then the rules are awesome)
int getSize2(char * string);

//Takes a char array of letters and returns morse code
char* encryptMorse(char Morse[])
{
    int length = getSize2(Morse);
    int ACS = 0; // ACS = Array current size, just didn't
                 //feel like typing it every time.
    char* temp = new char[length+1];
    char* ptr = temp;
    char* returnMe = new char[200];
    for(int i=0; i<length; i++){
        temp[i] = Morse[i];
        //--PRINT CHARACTERS--
        //-------                       I copied/pasted my own code here ALOT
        if(*(ptr+i)=='A'){               //all of these are notes-to-self:
            for(int j=1; j<=2; j++){        //j< the number of '.' and '-'
                if(j==1){                   // if statement for every 'char' in Morse.
                    returnMe[ACS] = '.';//.-
                    ACS++;
                }
                else if(j == 2){
                    returnMe[ACS] = '-';
                    ACS++;
                }
            }
        }
        //-------                       I copied/pasted my own code here ALOT
        if(*(ptr+i)=='B'){              //all of these are notes-to-self:
            for(int j=1; j<=4; j++){        //j< the number of '.' and '-'
                if(j==1){                   // if statement for every 'char' in Morse.
                    returnMe[ACS] = '-';//-...
                    ACS++;
                }
                else if(j == 2){
                    returnMe[ACS] = '.';
                    ACS++;
                }
                else if(j == 3){
                    returnMe[ACS] = '.';
                    ACS++;
                }
                else if(j == 4){
                    returnMe[ACS] = '.';
                    ACS++;
                }
            }
        }
        //-------                       I copied/pasted my own code here ALOT
        if(*(ptr+i)=='C'){              //all of these are notes-to-self:
            for(int j=1; j<=4; j++){        //j< the number of '.' and '-'
                if(j==1){                   // if statement for every 'char' in Morse.
                    returnMe[ACS] = '-';//-.-.
                    ACS++;
                }
                else if(j == 2){
                    returnMe[ACS] = '.';
                    ACS++;
                }
                else if(j==3){
                    returnMe[ACS] = '-';
                    ACS++;
                }
                else if(j == 4){
                    returnMe[ACS] = '.';
                    ACS++;
                }
            }
        }
        //-------                       I copied/pasted my own code here ALOT
        if(*(ptr+i)=='D'){              //all of these are notes-to-self:
            for(int j=1; j<=3; j++){        //j< the number of '.' and '-'
                if(j==1){                   // if statement for every 'char' in Morse.
                    returnMe[ACS] = '-';//-..
                    ACS++;
                }
                else if(j == 2){
                    returnMe[ACS] = '.';
                    ACS++;
                }
                else if(j == 3){
                    returnMe[ACS] = '.';
                    ACS++;
                }
            }
        }
        //-------                       I copied/pasted my own code here ALOT
        if(*(ptr+i)=='E'){              //all of these are notes-to-self:
            for(int j=1; j<=1; j++){        //j< the number of '.' and '-'
                if(j==1){                   // if statement for every 'char' in Morse.
                    returnMe[ACS] = '.';//.
                    ACS++;
                }
            }
        }
        //-------                       I copied/pasted my own code here ALOT
        if(*(ptr+i)=='F'){              //all of these are notes-to-self:
            for(int j=1; j<=4; j++){        //j< the number of '.' and '-'
                if(j==1){                   // if statement for every 'char' in Morse.
                    returnMe[ACS] = '.';//..-.
                    ACS++;
                }
                else if(j == 2){
                    returnMe[ACS] = '.';
                    ACS++;
                }
                else if(j == 3){
                    returnMe[ACS] = '-';
                    ACS++;
                }
                else if(j == 4){
                    returnMe[ACS] = '.';
                    ACS++;
                }
            }
        }
        //-------                       I copied/pasted my own code here ALOT
        if(*(ptr+i)=='G'){              //all of these are notes-to-self:
            for(int j=1; j<=3; j++){        //j< the number of '.' and '-'
                if(j==1){                   // if statement for every 'char' in Morse.
                    returnMe[ACS] = '-';//--.
                    ACS++;
                }
                else if(j == 2){
                    returnMe[ACS] = '-';
                    ACS++;
                }
                else if(j == 3){
                    returnMe[ACS] = '.';
                    ACS++;
                }
            }
        }
        //-------                       I copied/pasted my own code here ALOT
        if(*(ptr+i)=='H'){              //all of these are notes-to-self:
            for(int j=1; j<=4; j++){        //j< the number of '.' and '-'
                if(j==1){                   // if statement for every 'char' in Morse.
                    returnMe[ACS] = '.';//....
                    ACS++;
                }
                else if(j == 2){
                    returnMe[ACS] = '.';
                    ACS++;
                }
                else if(j == 3){
                    returnMe[ACS] = '.';
                    ACS++;
                }
                else if(j == 4){
                    returnMe[ACS] = '.';
                    ACS++;
                }
            }
        }
        //-------                       I copied/pasted my own code here ALOT
        if(*(ptr+i)=='I'){              //all of these are notes-to-self:
            for(int j=1; j<=2; j++){        //j< the number of '.' and '-'
                if(j==1){                   // if statement for every 'char' in Morse.
                    returnMe[ACS] = '.';//..
                    ACS++;
                }
                else if(j == 2){
                    returnMe[ACS] = '.';
                    ACS++;
                }
            }
        }
        //-------                       I copied/pasted my own code here ALOT
        if(*(ptr+i)=='J'){              //all of these are notes-to-self:
            for(int j=1; j<=4; j++){        //j< the number of '.' and '-'
                if(j==1){                   // if statement for every 'char' in Morse.
                    returnMe[ACS] = '.';//.---
                    ACS++;
                }
                else if(j == 2){
                    returnMe[ACS] = '-';
                    ACS++;
                }
                 else if(j == 3){
                    returnMe[ACS] = '-';
                    ACS++;
                }
                 else if(j == 4){
                    returnMe[ACS] = '-';
                    ACS++;
                }
            }
        }
        //-------                       I copied/pasted my own code here ALOT
        if(*(ptr+i)=='K'){              //all of these are notes-to-self:
            for(int j=1; j<=3; j++){        //j< the number of '.' and '-'
                if(j==1){                   // if statement for every 'char' in Morse.
                    returnMe[ACS] = '-';//-.-
                    ACS++;
                }
                else if(j == 2){
                    returnMe[ACS] = '.';
                    ACS++;
                }
                 else if(j == 3){
                    returnMe[ACS] = '-';
                    ACS++;
                }
            }
        }
        //-------                       I copied/pasted my own code here ALOT
        if(*(ptr+i)=='L'){              //all of these are notes-to-self:
            for(int j=1; j<=4; j++){        //j< the number of '.' and '-'
                if(j==1){                   // if statement for every 'char' in Morse.
                    returnMe[ACS] = '.';//.-..
                    ACS++;
                }
                else if(j == 2){
                    returnMe[ACS] = '-';
                    ACS++;
                }
                else if(j == 3){
                    returnMe[ACS] = '.';
                    ACS++;
                }
                else if(j == 4){
                    returnMe[ACS] = '.';
                    ACS++;
                }
            }
        }
        //-------                       I copied/pasted my own code here ALOT
        if(*(ptr+i)=='M'){              //all of these are notes-to-self:
            for(int j=1; j<=2; j++){        //j< the number of '.' and '-'
                if(j==1){                   // if statement for every 'char' in Morse.
                    returnMe[ACS] = '-';//--
                    ACS++;
                }
                else if(j == 2){
                    returnMe[ACS] = '-';
                    ACS++;
                }
            }
        }
        //-------                       I copied/pasted my own code here ALOT
        if(*(ptr+i)=='N'){              //all of these are notes-to-self:
            for(int j=1; j<=2; j++){        //j< the number of '.' and '-'
                if(j==1){                   // if statement for every 'char' in Morse.
                    returnMe[ACS] = '-';//-.
                    ACS++;
                }
                else if(j == 2){
                    returnMe[ACS] = '.';
                    ACS++;
                }
            }
        }
        //-------                       I copied/pasted my own code here ALOT
        if(*(ptr+i)=='O'){              //all of these are notes-to-self:
            for(int j=1; j<=3; j++){        //j< the number of '.' and '-'
                if(j==1){                   // if statement for every 'char' in Morse.
                    returnMe[ACS] = '-';//---
                    ACS++;
                }
                else if(j == 2){
                    returnMe[ACS] = '-';
                    ACS++;
                }
                else if(j == 3){
                    returnMe[ACS] = '-';
                    ACS++;
                }
            }
        }
        //-------                       I copied/pasted my own code here ALOT
        if(*(ptr+i)=='P'){              //all of these are notes-to-self:
            for(int j=1; j<=4; j++){        //j< the number of '.' and '-'
                if(j==1){                   // if statement for every 'char' in Morse.
                    returnMe[ACS] = '.';//.--.
                    ACS++;
                }
                else if(j == 2){
                    returnMe[ACS] = '-';
                    ACS++;
                }
                else if(j == 3){
                    returnMe[ACS] = '-';
                    ACS++;
                }
                else if(j == 4){
                    returnMe[ACS] = '.';
                    ACS++;
                }
            }
        }
        //-------                       I copied/pasted my own code here ALOT
        if(*(ptr+i)=='Q'){              //all of these are notes-to-self:
            for(int j=1; j<=4; j++){        //j< the number of '.' and '-'
                if(j==1){                   // if statement for every 'char' in Morse.
                    returnMe[ACS] = '-';//--.-
                    ACS++;
                }
                else if(j == 2){
                    returnMe[ACS] = '-';
                    ACS++;
                }
                else if(j == 3){
                    returnMe[ACS] = '.';
                    ACS++;
                }
                else if(j == 4){
                    returnMe[ACS] = '-';
                    ACS++;
                }
            }
        }
        //-------                       I copied/pasted my own code here ALOT
        if(*(ptr+i)=='R'){              //all of these are notes-to-self:
            for(int j=1; j<=3; j++){        //j< the number of '.' and '-'
                if(j==1){                   // if statement for every 'char' in Morse.
                    returnMe[ACS] = '.';//.-.
                    ACS++;
                }
                else if(j == 2){
                    returnMe[ACS] = '-';
                    ACS++;
                }
                else if(j == 3){
                    returnMe[ACS] = '.';
                    ACS++;
                }
            }
        }
        //-------                       I copied/pasted my own code here ALOT
        if(*(ptr+i)=='S'){              //all of these are notes-to-self:
            for(int j=1; j<=3; j++){        //j< the number of '.' and '-'
                if(j==1){                   // if statement for every 'char' in Morse.
                    returnMe[ACS] = '.';//...
                    ACS++;
                }
                else if(j == 2){
                    returnMe[ACS] = '.';
                    ACS++;
                }
                else if(j == 3){
                    returnMe[ACS] = '.';
                    ACS++;
                }
            }
        }
        //-------                       I copied/pasted my own code here ALOT
        if(*(ptr+i)=='T'){              //all of these are notes-to-self:
            for(int j=1; j<=1; j++){        //j< the number of '.' and '-'
                if(j==1){                   // if statement for every 'char' in Morse.
                    returnMe[ACS] = '-';//-
                    ACS++;
                }
            }
        }//-------                       I copied/pasted my own code here ALOT
        if(*(ptr+i)=='U'){              //all of these are notes-to-self:
            for(int j=1; j<=3; j++){        //j< the number of '.' and '-'
                if(j==1){                   // if statement for every 'char' in Morse.
                    returnMe[ACS] = '.';//..-
                    ACS++;
                }
                else if(j == 2){
                    returnMe[ACS] = '.';
                    ACS++;
                }
                else if(j == 3){
                    returnMe[ACS] = '-';
                    ACS++;
                }
            }
        }
        //-------                       I copied/pasted my own code here ALOT
        if(*(ptr+i)=='V'){              //all of these are notes-to-self:
            for(int j=1; j<=4; j++){        //j< the number of '.' and '-'
                if(j==1){                   // if statement for every 'char' in Morse.
                    returnMe[ACS] = '.';//...-
                    ACS++;
                }
                else if(j == 2){
                    returnMe[ACS] = '.';
                    ACS++;
                }
                else if(j == 3){
                    returnMe[ACS] = '.';
                    ACS++;
                }
                else if(j == 4){
                    returnMe[ACS] = '-';
                    ACS++;
                }
            }
        }
        //-------                       I copied/pasted my own code here ALOT
        if(*(ptr+i)=='W'){              //all of these are notes-to-self:
            for(int j=1; j<=3; j++){        //j< the number of '.' and '-'
                if(j==1){                   // if statement for every 'char' in Morse.
                    returnMe[ACS] = '.';//.--
                    ACS++;
                }
                else if(j == 2){
                    returnMe[ACS] = '-';
                    ACS++;
                }
                else if(j == 3){
                    returnMe[ACS] = '-';
                    ACS++;
                }
            }
        }
        //-------                       I copied/pasted my own code here ALOT
        if(*(ptr+i)=='X'){              //all of these are notes-to-self:
            for(int j=1; j<=4; j++){        //j< the number of '.' and '-'
                if(j==1){                   // if statement for every 'char' in Morse.
                    returnMe[ACS] = '-';//-..-
                    ACS++;
                }
                else if(j == 2){
                    returnMe[ACS] = '.';
                    ACS++;
                }
                else if(j == 3){
                    returnMe[ACS] = '.';
                    ACS++;
                }
                else if(j == 4){
                    returnMe[ACS] = '-';
                    ACS++;
                }
            }
        }
        //-------                       I copied/pasted my own code here ALOT
        if(*(ptr+i)=='Y'){              //all of these are notes-to-self:
            for(int j=1; j<=4; j++){        //j< the number of '.' and '-'
                if(j==1){                   // if statement for every 'char' in Morse.
                    returnMe[ACS] = '-';//-.--
                    ACS++;
                }
                else if(j == 2){
                    returnMe[ACS] = '.';
                    ACS++;
                }
                else if(j == 3){
                    returnMe[ACS] = '-';
                    ACS++;
                }
                else if(j == 4){
                    returnMe[ACS] = '-';
                    ACS++;
                }
            }
        }
        //-------                       I copied/pasted my own code here ALOT
        if(*(ptr+i)=='Z'){              //all of these are notes-to-self:
            for(int j=1; j<=4; j++){        //j< the number of '.' and '-'
                if(j==1){                   // if statement for every 'char' in Morse.
                    returnMe[ACS] = '-';//--..
                    ACS++;
                }
                else if(j == 2){
                    returnMe[ACS] = '-';
                    ACS++;
                }
                else if(j == 3){
                    returnMe[ACS] = '.';
                    ACS++;
                }
                else if(j == 4){
                    returnMe[ACS] = '.';
                    ACS++;
                }
            }
        }
        //--PRINT SPACES--
        //-------
        if(*(ptr+i)==' '){
            for(int j=0; j<4; j++){
                returnMe[ACS] = ' ';
                ACS++;
            }
        }
        else if(!(*(ptr+i)== '\0')){
            returnMe[ACS] = ' ';
            ACS++;
        }
    }
    returnMe[ACS] = '\0';
    //delete temp;
    return returnMe;
}


//----DECRYPTMORSE STARTS HERE----
//----DECRYPTMORSE STARTS HERE----

//Takes a char array of morse code and returns normal letters
char* decryptMorse(char notMorse[])
{
    int LENGTH = getSize2(notMorse);
    int ACS = 0; // ACS = arrayCurrentSize, just didn't feel like typing it every time.
    char* temp = new char[LENGTH+1];
    char* returnMe = new char[200];

    for(int i=0; i<LENGTH; i++){
        temp[i] = notMorse[i];
    }
    for(int i=0; i<LENGTH; i++){
        //--That REALLY tedious tree--
        if(*(temp+i) == '.'){
                //same thing for all of these but basically maxLength makes sure that the pointer never points off the array
                //and '\0' makes sure it figures out what the last character is. (Find/Replace was SO useful coding this...)
            if(*(temp+((maxLength(i+1, LENGTH)))) == ' ' || *(temp+((maxLength(i+1, LENGTH)))) == '\0' || LENGTH == (i-1) ){
                returnMe[ACS] = 'E';
                ACS++;
                i+=0;
            }
            else{
                if(*(temp+((maxLength(i+1, LENGTH)))) == '.'){
                    if(*(temp+((maxLength(i+2, LENGTH)))) == ' ' || *(temp+((maxLength(i+2, LENGTH)))) == '\0' || LENGTH == (i-1) ){
                        returnMe[ACS] = 'I';
                        ACS++;
                        i+=1;
                    }
                    else{
                        if(*(temp+((maxLength(i+2, LENGTH)))) == '.'){
                            if(*(temp+((maxLength(i+3, LENGTH)))) == ' ' || *(temp+((maxLength(i+3, LENGTH)))) == '\0' || LENGTH == (i-1) ){
                                returnMe[ACS] = 'S';
                                ACS++;
                                i+=2;
                            }
                            else{
                                if(*(temp+((maxLength(i+3, LENGTH)))) == '.'){
                                    if(*(temp+((maxLength(i+4, LENGTH)))) == ' ' || *(temp+((maxLength(i+4, LENGTH)))) == '\0' || LENGTH == (i-1) ){
                                        returnMe[ACS] = 'H';
                                        ACS++;
                                        i+=3;
                                    }
                                }
                                else if(*(temp+((maxLength(i+3, LENGTH)))) == '-'){
                                    if(*(temp+((maxLength(i+4, LENGTH)))) == ' ' || *(temp+((maxLength(i+4, LENGTH)))) == '\0' || LENGTH == (i-1) ){
                                        returnMe[ACS] = 'V';
                                        ACS++;
                                        i+=3;
                                    }
                                }
                            }
                        }
                        else if(*(temp+((maxLength(i+2, LENGTH)))) == '-'){
                            if(*(temp+((maxLength(i+3, LENGTH)))) == ' ' || *(temp+((maxLength(i+3, LENGTH)))) == '\0' || LENGTH == (i-1) ){
                                returnMe[ACS] = 'U';
                                ACS++;
                                i+=2;
                            }
                            else{
                                if(*(temp+((maxLength(i+3, LENGTH)))) == '.'){
                                    if(*(temp+((maxLength(i+4, LENGTH)))) == ' ' || *(temp+((maxLength(i+4, LENGTH)))) == '\0' || LENGTH == (i-1) ){
                                        returnMe[ACS] = 'F';
                                        ACS++;
                                        i+=3;
                                    }
                                }
                            }
                        }
                    }
                }
                else if(*(temp+((maxLength(i+1, LENGTH)))) == '-'){
                    if(*(temp+((maxLength(i+2, LENGTH)))) == ' ' || *(temp+((maxLength(i+2, LENGTH)))) == '\0' || LENGTH == (i-1) ){
                        returnMe[ACS] = 'A';
                        ACS++;
                        i+=1;
                    }
                    else{
                        if(*(temp+((maxLength(i+2, LENGTH)))) == '.'){
                            if(*(temp+((maxLength(i+3, LENGTH)))) == ' ' || *(temp+((maxLength(i+3, LENGTH)))) == '\0' || LENGTH == (i-1) ){
                                returnMe[ACS] = 'R';
                                ACS++;
                                i+=2;
                            }
                            else{
                                if(*(temp+((maxLength(i+3, LENGTH)))) == '.'){
                                    if(*(temp+((maxLength(i+4, LENGTH)))) == ' ' || *(temp+((maxLength(i+4, LENGTH)))) == '\0' || LENGTH == (i-1) ){
                                        returnMe[ACS] = 'L';
                                        ACS++;
                                        i+=3;
                                    }
                                }
                            }
                        }
                        else if(*(temp+((maxLength(i+2, LENGTH)))) == '-'){
                            if(*(temp+((maxLength(i+3, LENGTH)))) == ' ' || *(temp+((maxLength(i+3, LENGTH)))) == '\0' || LENGTH == (i-1) ){
                                returnMe[ACS] = 'W';
                                ACS++;
                                i+=2;
                            }
                            else{
                                if(*(temp+((maxLength(i+3, LENGTH)))) == '.'){
                                    if(*(temp+((maxLength(i+4, LENGTH)))) == ' ' || *(temp+((maxLength(i+4, LENGTH)))) == '\0' || LENGTH == (i-1) ){
                                        returnMe[ACS] = 'P';
                                        ACS++;
                                        i+=3;
                                    }
                                }
                                else if(*(temp+((maxLength(i+3, LENGTH)))) == '-'){
                                    if(*(temp+((maxLength(i+4, LENGTH)))) == ' ' || *(temp+((maxLength(i+4, LENGTH)))) == '\0' || LENGTH == (i-1) ){
                                        returnMe[ACS] = 'J';
                                        ACS++;
                                        i+=3;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        else if(*(temp+i) == '-'){
            if(*(temp+((maxLength(i+1, LENGTH)))) == ' ' || *(temp+((maxLength(i+1, LENGTH)))) == '\0' || LENGTH == (i-1) ){
                returnMe[ACS] = 'T';
                ACS++;
                i+=0;
            }
            else{
                if(*(temp+((maxLength(i+1, LENGTH)))) == '.'){
                    if(*(temp+((maxLength(i+2, LENGTH)))) == ' ' || *(temp+((maxLength(i+2, LENGTH)))) == '\0' || LENGTH == (i-1) ){
                        returnMe[ACS] = 'N';
                        ACS++;
                        i+=1;
                    }
                    else{
                        if(*(temp+((maxLength(i+2, LENGTH)))) == '.'){
                            if(*(temp+((maxLength(i+3, LENGTH)))) == ' ' || *(temp+((maxLength(i+3, LENGTH)))) == '\0' || LENGTH == (i-1) ){
                                returnMe[ACS] = 'D';
                                ACS++;
                                i+=2;
                            }
                            else{
                                if(*(temp+((maxLength(i+3, LENGTH)))) == '.'){
                                    if(*(temp+((maxLength(i+4, LENGTH)))) == ' ' || *(temp+((maxLength(i+4, LENGTH)))) == '\0' || LENGTH == (i-1) ){
                                        returnMe[ACS] = 'B';
                                        ACS++;
                                        i+=3;
                                    }
                                }
                                else if(*(temp+((maxLength(i+3, LENGTH)))) == '-'){
                                    if(*(temp+((maxLength(i+4, LENGTH)))) == ' ' || *(temp+((maxLength(i+4, LENGTH)))) == '\0' || LENGTH == (i-1) ){
                                        returnMe[ACS] = 'X';
                                        ACS++;
                                        i+=3;
                                    }
                                }
                            }
                        }
                        else if(*(temp+((maxLength(i+2, LENGTH)))) == '-'){
                            if(*(temp+((maxLength(i+3, LENGTH)))) == ' ' || *(temp+((maxLength(i+3, LENGTH)))) == '\0' || LENGTH == (i-1) ){
                                returnMe[ACS] = 'K';
                                ACS++;
                                i+=2;
                            }
                            else{
                                if(*(temp+((maxLength(i+3, LENGTH)))) == '.'){
                                    if(*(temp+((maxLength(i+4, LENGTH)))) == ' ' || *(temp+((maxLength(i+4, LENGTH)))) == '\0' || LENGTH == (i-1) ){
                                        returnMe[ACS] = 'C';
                                        ACS++;
                                        i+=3;
                                    }
                                }
                                else if(*(temp+((maxLength(i+3, LENGTH)))) == '-'){
                                    if(*(temp+((maxLength(i+4, LENGTH)))) == ' ' || *(temp+((maxLength(i+4, LENGTH)))) == '\0' || LENGTH == (i-1) ){
                                        returnMe[ACS] = 'Y';
                                        ACS++;
                                        i+=3;
                                    }
                                }
                            }
                        }
                    }
                }
                else if(*(temp+((maxLength(i+1, LENGTH)))) == '-'){
                    if(*(temp+((maxLength(i+2, LENGTH)))) == ' ' || *(temp+((maxLength(i+2, LENGTH)))) == '\0' || LENGTH == (i-1) ){
                        returnMe[ACS] = 'M';
                        ACS++;
                        i+=1;
                    }
                    else{
                        if(*(temp+((maxLength(i+2, LENGTH)))) == '.'){
                            if(*(temp+((maxLength(i+3, LENGTH)))) == ' ' || *(temp+((maxLength(i+3, LENGTH)))) == '\0' || LENGTH == (i-1) ){
                                returnMe[ACS] = 'G';
                                ACS++;
                                i+=2;
                            }
                            else{
                                if(*(temp+((maxLength(i+3, LENGTH)))) == '.'){
                                    if(*(temp+((maxLength(i+4, LENGTH)))) == ' ' || *(temp+((maxLength(i+4, LENGTH)))) == '\0' || LENGTH == (i-1) ){
                                        returnMe[ACS] = 'Z';
                                        ACS++;
                                        i+=3;
                                    }
                                }
                                else if(*(temp+((maxLength(i+3, LENGTH)))) == '-'){
                                    if(*(temp+((maxLength(i+4, LENGTH)))) == ' ' || *(temp+((maxLength(i+4, LENGTH)))) == '\0' || LENGTH == (i-1) ){
                                        returnMe[ACS] = 'Q';
                                        ACS++;
                                        i+=3;
                                    }
                                }
                            }
                        }
                        else if(*(temp+((maxLength(i+2, LENGTH)))) == '-'){
                            if(*(temp+((maxLength(i+3, LENGTH)))) == ' ' || *(temp+((maxLength(i+3, LENGTH)))) == '\0' || LENGTH == (i-1)+1 ){
                                returnMe[ACS] = 'O';
                                ACS++;
                                i+=2;
                            }
                        }
                    }
                }
            }
        }
        //--For Spaces
        else if(*(temp + (i)) == ' '){
            if(*(temp+((maxLength(i+1, LENGTH)))) == ' ' || *(temp+((maxLength(i+1, LENGTH)))) == '\0' || LENGTH == (i-1) ){
                returnMe[ACS] = ' ';
                ACS++;
                i+=4;
            }
        }
    }
    returnMe[ACS+1]='\0';
    delete[] temp;

    //cout << endl << returnMe << endl;
    return returnMe;
}
//makes sure the pointers don't point off the array
int maxLength(int i, int LENGTH){
    if(i>LENGTH){
        return LENGTH;
    }
return i;

}
//gives the size of the array
int getSize2(char * string)
{
    int i = 0;
    while (string[i] != '\0')
    {
        i++;
    }
    return i;
}
