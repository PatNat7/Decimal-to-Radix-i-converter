#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

/*Create constants for heading block*/
#define TITLE "DECIMAL TO RADIX-i converter"                      //The constant TITLE is assigned the title "DECIMAL TO RADIX-i converter"
#define AUTHOR "Patricia Munginga and Thandiwe Zhanje"           //The constant AUTHOR is assigned the name "Patricia Munginga and Thandiwe Zhanje"
#define YEAR 2022                                               //The constant YEAR is assigned the value 2022

void asterisk(void)
{
        /*Function that generates the asterisk portion of the heading block*/
        for(int i=0;i<50;i++)  //prints 50 asterisks in one line
        {printf("*");}
}

int getD(void)
{
         /*Function that prompts an external user to enter a positive decimal integer and displays it on the screen*/
         int D;                                           //Declare integer variable 'D' that will be assigned to the decimal number

         printf("\nEnter a decimal number: ");            //Prompt user to enter a decimal number
         scanf("%d",&D);                                  // Obtain the decimal number value from the user

         if(D>=0)
         {
             printf("The number you have entered is %d\n",D); //Display the user's decimal number input to the screen if it is >=0
         }

         return D;                                           //The function will return the decimal number for use outside the function
}

int getRadix(void)
{
    /*Function that prompts an external user to enter a radix between 2 and 16 and displays it on the screen*/
    int radix;                                                         //Declare integer variable 'radix' that will be assigned to the radix number
    printf("Enter a radix for the converter between 2 and 16: ");      //Prompt user to enter radix between 2 and 16
    scanf("%d",&radix);                                                //Obtain the radix value from the user

    if((radix<2)||(radix>16))
        {
            printf("The radix you have entered is out of bounds\n");   //Prompt user to enter a new radix if the radix they've entered is not between 2 and 16
            radix = getRadix();                                        //Call the function getRadix() to obtain the new radix value
        }
    else
    {
        printf("The radix you have entered is %d\n",radix);            //Display the value of the radix that the user has input to the screen
    }
    return radix;                                                      //The function will return the radix for use outside the function
}

void Dec2RadixI(int decValue, int radValue)
{
    /*Function that takes in the decimal number and the radix value entered by the user and displays the equivalent radix-i symbol*/
    if(decValue==0)
        {
            printf("\nThe radix-%d value is 0",radValue);             //The radix-i value of the decimal number 0 is 0 despite what value the radix is
        }
    else
        {   printf("\nThe radix-%d value is ",radValue);              //Display the beginning of the statement that outputs the radix-i symbol

            int n =ceil((log(decValue+1))/(log(radValue)))-1;         //Declare the integer 'n' which is the value of the most significant bit position
            int q;                                                    //Declare integer variables 'q' and 'ri' for use in the sum of weights method for finding the radix-i symbol
            int ri;


            for(int i=n;i>=0;i--)                                     //Initiate for loop to assign bit values to the bit poisitions 0 to n
               {
                   ri=trunc(pow(radValue,i));                         //The radix is raised to the power i, (i being the value of the bit position)
                   q = trunc(decValue/ri);                            //The bit value, q, in the corresponding bit position, i ,is found by truncating the value of (Decimal number/ri)

                   if (q<=9)
                     {
                        printf("%d",q);                               //If q<=9, the bit value at position i is q
                     }
                   else
                     {
                        printf("%c",q+55);                            //If q>9, the bit value at i is the corresponding letter representation (ie. 10='A', 11='B', 12='C' etc.). This is obatined by representing it as the char value at q+55 in the ASCII table.eg.  char (10+55) =char 65= 'A' in the ASCII table.
                     }
                   decValue = decValue - (q*ri);                      //Update the value of 'D' which will be used in the next iteration of the for loop.
               }
        }
}

int main()
{
    asterisk();                                                      //Create heading block
    printf("\n%s\nWritten by: %s\nDate: %d\n",TITLE, AUTHOR,YEAR);
    asterisk();

    int D;                                                           //Declare integer variables 'D', 'radix', 'm', 'res' and 'rem' for use in main function
    int radix;
    int m;
    int res;
    int rem;

    while(D=getD(),D>=0)                                             //Initiate while loop to run whilst D is assigned a value and is greater than or equal to 0
    {
        radix=getRadix();                                            //Call the function getRadix() to obtain the user's value of the radix

        if(D==0)
        {
            printf("The log2 of the number is undefined\n");         //If D is 0 the log2 value will be undefined so the output on the screen will tell the user that it is undefined
        }
        else
        {
            printf("The log2 of the number is: %.2f\n",(log(D)/log(2)));      //If D is not 0, the log2 value will be calculated and output to the screen
        }

        res = D/radix;                                                            //Calculate the value of the decimal number divided by the radix
        printf("The integer result of the number divided by %d is %d\n",radix,res);  //Display the integer value of 'res'

        rem=D%radix;                                                              //Calculate the remainder obtained when the decimal number is divided by the radix
        printf("The remainder is %d",rem);                                    //Display the integer value of the remainder

        Dec2RadixI(D,radix);                                                  //Call the function Dec2RadixI(int decValue, int radValue) to obtain the radix-i representation from the user's input of the decimal number and radix value
    }

    printf("EXIT");                                                           //Display "EXIT" to the screen when the input of the decimal number is less than 0

    return 0;                                                                 //The program will execute successfully and do what it is intended to do.
}
