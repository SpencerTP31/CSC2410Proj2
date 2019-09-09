/*   Program Name: cli_sumEff.c
 *   Author: Spencer Peters
 *   Class: CSC-2410
 *   Date: 9/3/19
 *   Location ~/speters/csc2410/binaryConv.c
 *   Program that reads in a binary number and output it in hex, octal, or decimal
 */

#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

/* Description: This function uses Horner method to convert a binary number to decimal
 * Pre Condition: The function receives input which is the array of the binary numbers and length which is
 * the length of the binary array
 * Post Condition: Once the function has ran it will return an unsigned int type which will hold the
 * decimal value converted within the function, making it easier for us to convert to hex or octal.
*/
unsigned int horners(int *input, int length)
{
    unsigned int sum;
    sum = input[0];
    int i;
    for (i = 1; i < length; i++)
    {
        sum = sum * 2 + input[i];
    }
    return sum;
}

/* Description: This function is used to check to see if the binary number inputted is a valid number
 * Pre Condition: The function receives input which is the stored binary number and the length of the binary array
 * Post Condition: After completion of the function a bool will be returned, if true is returned then the array is valid,
 * if false is return that means there is an invalid binary number.
*/
bool validation(int *input, int length)
{
    int i;
    bool ans;
    for (i = 0; i < length; i++)
    {
        if(input[i] == 0 || input[i] == 1)
        {
            ans = true;
        }
        else
        {
            ans = false;
        }
    }
    return ans;
}

int main(int argc, char *argv[])
{
    int j = 0;
    bool answer;
    unsigned int postHorners;
    int binary[strlen(argv[1])];

    // This for loop runs through argv[1] where the binary number is held and puts it in an
    // int array to hold the binary number using the 0x0F to convert the ASCII value to an
    // int
    for (j = 0; j < strlen(argv[1]); j++)
    {
        binary[j] = (argv[1][j] & 0x0F);
    }

    // Sends the binary array to validation to make sure that the array has only 1's and 0's
    answer = validation(binary, j);

    // If answer is true then the binary array will be sent to horner's method to convert to decimal
    // if false the program will shot out an error and exit with exit code 2
    if(answer == 1)
    {
        postHorners = horners(binary, j);
    }
    else if(answer == 0)
    {
        fprintf(stderr, "Invalid Binary!\n");
        exit (2);
    }

    // This switch checks to see what's in argv[2] to see what form the number will get converted to
    switch(argv[2][0])
    {
        case 'h':
            fprintf(stdout, "%s ==> 0x%x\n", argv[1], postHorners);
            break;
        case 'o':
            fprintf(stdout, "%s ==> o%o\n", argv[1], postHorners);
            break;
        case 'd':
            fprintf(stdout, "%s ==> %d\n", argv[1], postHorners);
            break;
        default:
            fprintf(stderr, "Error: Unknown Type: %s\n", argv[2]);
            exit(2);
    }
    return 0;
}
