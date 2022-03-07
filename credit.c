#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    long sumEven(long n);
    int sumRemaining(long n, int i);
    int digitSum(int n);

    //Asking for a card number
    long cardNumber = get_long("Number: ");

    //Adding multiplied numbers
    int sumeven = sumEven(cardNumber);

    //Adding the remaining numbers
    int sumremaining = sumRemaining(cardNumber, sumeven);

    //Checking the modulo of the number
    if (sumremaining % 10 == 0)
    {
        //Checks for Visa
        if (cardNumber / 1000000000000 == 4 || cardNumber / 1000000000000000 == 4)
        {
            printf("VISA\n");
        }
        //Checks for Master Card
        else if (cardNumber / 100000000000000 == 51 || cardNumber / 100000000000000 == 52 ||
                 cardNumber / 100000000000000 == 53 || cardNumber / 100000000000000 == 54 ||
                 cardNumber / 100000000000000 == 55)
        {
            printf("MASTERCARD\n");
        }
        //Checks for American Express
        else if (cardNumber / 10000000000000 == 34 || cardNumber / 10000000000000 == 37)
        {
            printf("AMEX\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}

long sumEven(long n)
{
    int digitSum(int n);
    //This adds the value of the one's digit, since it only takes one step to get to it.
    int sum = digitSum(n / 10 % 10);
    //This one goes to the 10s place to get the even digit.
    n = n / 10;
    //Check if there digits left to add
    for (int i = 7; i != 0; i--)
    {
        //Move onto the next digit
        n = n / 100;
        //Add the digit to the final sum
        sum += digitSum(n % 10);
    }
    return sum;
}

int sumRemaining(long n, int i)
{
    int sum = 0;
    for (int j = 8; j != 0; j--)
    {
        //Add the digit to the total sum
        sum += n % 10;
        //Move to the next digit
        n = n / 100;
    }
    return i + sum;
}

//This function turns a product of 2, into the sum of its digits
int digitSum(int n)
{
    //Multiplies numbers between 0 to 4 by 2
    if (n <= 4)
    {
        return n * 2;
    }
    //Produces the digit sum of numbers between (including) 5 and 8
    else if (n > 4)
    {
        if (n == 5)
        {
            return 1;
        }
        else if (n == 6)
        {
            return 3;
        }
        else if (n == 7)
        {
            return 5;
        }
        else if (n == 8)
        {
            return 7;
        }
        else if (n == 9)
        {
            return 9;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        return 0;
    }
}
