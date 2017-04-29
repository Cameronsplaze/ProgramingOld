#include "Crypto.h"

char * encryptCaesar(char encryptCaesar[], int key)
{
    int count = 0;
    while(encryptCaesar[count])
    {
        count++;
    }
    char *ptr = new char[count];
    //This is for changing the pointer
    for(int j = 0; j < count; j++)
    {
        ptr[j] = encryptCaesar[j];
        //If character has a blankspace in it, leave it be.
        if(ptr[j] == ' ')
        {
            continue;
        }

        //If character pointer is greater than 'Z', subtract 26
        if(ptr[j] + key > 'Z')
        {
            ptr[j] -= 26;
        }

        if(ptr[j] < 'A')
        {
            ptr[j] += key;
        }

        //This is if each of the two tests fail
        else
        {
            ptr[j] += (char)key;
        }
    }
    return ptr;
}

//This is for decrypting
char * decryptCaesar(char decryptCaesar[], int key)
{
    int count = 0;
    while(decryptCaesar[count])
    {
        count++;
    }
    char *ptrA = new char[count];
    //This is for decrypting the pointer
    for(int j = 0; j < count; j++)
    {
        ptrA[j] = decryptCaesar[j];
        //If character has a blankspace in it, leave it be.
        if(ptrA[j] == ' ')
        {
            continue;
        }

        //If character pointer is less than 'A', add 26
        if(ptrA[j] - key < 'A')
        {
            ptrA[j] += 26;
        }

        //If character pointer is greater than Z, then subtract it with key
        if(ptrA[j] > 'Z')
        {
            ptrA[j] -= key;
        }

        //This is if each of the two tests fail
        else
        {
            ptrA[j] -= (char)key;
        }
    }
    return ptrA;
}
