#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

#define TITLE "DECIMAL TO RADIX-i converter"
#define AUTHOR "Patricia Munginga"
#define YEAR 2022

//Add comments and code should stop when user inputs <0
//Make code neater and shorter
// How can one save space, little endian maybe?
//check if radix is between 2 and 16?
void asterix(void)
    {for(int i=0;i<30;i++)
       printf("*");}

int getD(void)
    {    int D;
         printf("\nEnter a decimal number: ");//
         scanf("%d",&D);
         return D;
    }

void Dec2RadixI(int decValue, int radValue)
{
    int n =ceil((log(decValue+1))/(log(radValue)))-1;
    int q;
    int ri;

    printf("\nThe radix-%d value is ",radValue);

    for(int i=n;i>=0;i--)
    {
        ri=pow(radValue,i);
        q = trunc(decValue/ri);
        if (q<=9)
        {
            printf("%d",q);
        }
        else
        {
            printf("%c",q+55);
        }
        decValue = decValue - (q*ri);
    }
}

int main()
{
    asterix();
    printf("\n%s\nWritten by: %s\nDate: %d\n",TITLE, AUTHOR,YEAR);//
    asterix();

    int D;
    int radix;

    while(D=getD(),D>=0)
    {
        printf("The number you have entered is %d\n",D);
        printf("Enter a radix for the converter between 2 and 16: ");
        scanf("%d",&radix);

        printf("The radix you have entered is %d\n",radix);
        printf("The log2 of the number is: %.2f\n",(log(D)/log(2)));
        printf("The integer result of the number divided by 2 is %d\n",D/2);
        printf("The remainder is %d",D%2);

        Dec2RadixI(D,radix);
    }

    printf("EXIT");

    return 0;


}
