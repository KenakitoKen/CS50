#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    if(argc != 2){
        printf("ERROR: You need at least one argument.\n");
        return 1;
    }

    int ciphernumber = atol(argv[1]);
    printf("%d\n", ciphernumber);

    int len;
    string plaintext = get_string("What shall we encrypt?\n");
    printf("plaintext:  %s\n", plaintext);
    len = strlen(plaintext);
    char newnumber;
    string newword = NULL;
    char strOutput[len];
    int subtractby;

    ciphernumber = ciphernumber / ciphernumber;
    printf("subtract by is %d\n", ciphernumber);

    if (ciphernumber / ciphernumber == ciphernumber){
        for (int i = 0; i < strlen(plaintext); i++)
        {
            if(islower(plaintext[i])){
                subtractby = 97;
            } else {
                subtractby = 65;
            }
            printf("subtract by is %d\n", subtractby);

            if(isalpha(plaintext[i]) != 0){
                newnumber = plaintext[i] + ciphernumber - subtractby;
                newnumber = newnumber % 26;
    //            printf("plaintext: %d; ciphernumber: %d; subtractby: %d\n", plaintext[i], ciphernumber, subtractby);
                newnumber += subtractby;
                strncat(strOutput, &newnumber, 1);
    //            printf("hi %s\n", strOutput);
            } else{
                strncat(strOutput, &plaintext[i], 1);
            }
            newnumber = 0;
        }
        printf("ciphertext: %s\n", strOutput);
    } else {
        return 1;
}
}