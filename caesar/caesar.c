#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

int main(int argc, string argv[])
{

//    for (int a = 0; a < strlen(argv[1]); a++)
        for (int a = 0, len = strlen(argv[1]); a < len; a++)
    {    if (isdigit(argv[1][a]) == false) {
            printf("failure: argv[1] is not all digits\n");
            return 1;
        } else {
    printf("success: argv[1] is all digits\n");}
    }


    // exit program if at two arguments are not passed through command line
    if(argc != 2){
        printf("ERROR: You need at least one argument.\n");
        return 1;
    }

    string plaintext = get_string("What shall we encrypt?\n");
    printf("plaintext:  %s\n", plaintext);

    printf("argv[1] is %s\n", argv[1]);

    //convert string argument to integer type
    int ciphernumber = atol(argv[1]);
    //get length of text to be encrypted
    int len = strlen(plaintext);
    printf("intlen: %d\n", len);
//    char strOutput[len];

    // define length of array as length of plaintext in argument
    char strOutput[len];
    // 'subtract by' variable used to minus 97 or 65 from ascii code of character
    int subtractby;
    char newnumber;
    printf("ciphernumner is %d\n", ciphernumber);

    //loop through plaintext characters
    for (int i = 0; i < strlen(plaintext); i++)
    {
        if(islower(plaintext[i])){
            subtractby = 97;
        } else {
            subtractby = 65;
        }

        if(isalpha(plaintext[i]) != 0){
            //this section executed if char is a-zA-Z. Symbols handled in else statement.
            newnumber = plaintext[i] + ciphernumber - subtractby;
            newnumber = newnumber % 26;
            // add the ascii value which was subtracted previosly to get the case correct of cyphertext
            newnumber += subtractby;
            // concatonate cyphertext characters into strOutput
            strncat(strOutput, &newnumber, 1);
//            printf("hi %s\n", strOutput);
        } else{
            strncat(strOutput, &plaintext[i], 1);
        }
        printf("ciphertext: %s\n", strOutput);
        newnumber = 0;
    }
    printf("ciphertext: %s\n", strOutput);
}