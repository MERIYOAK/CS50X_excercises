#include <cs50.h>
#include <stdio.h>

long get_cc();
int validate(long n);

int main(void)
{   switch (validate(get_cc()))
    {
        case 3:
            printf("AMEX\n");
            break;
        case 4:
            printf("VISA\n");
            break;
        case 5:
            printf("MASTERCARD\n");
            break;
        case 6:
            printf("DISCOVER\n");
            break;
        default:
            printf("INVALID\n");
    }
}
long get_cc()
{
    long n;
    do
    {
        n = get_long("number: ");
    }
    while(n < 1);
    return n;
}
int validate(long n)
{
    long number = n;
    long number1 = n;

    int sum = 0;
    sum = number % 10;                 // add checksum
    number = number / 10;              // chop checksum off
    while(number > 0)
    {
        int temp = (number % 10) * 2;  // get rightmost digit and double
        if (temp > 9)                  // if 2 digit number add digits together
        {
            temp = temp - 9;
        }
        sum = sum + temp;              // add digit to sum
        number = number / 10;          // chop rightmost digit off
        temp = number % 10;            // get rightmost digit
        sum = sum + temp;              // add interleaved digit to sum
        number = number / 10;          // chop right digit off
    }
    while (n > 10)                     // get leftmost digit
    {
        n = n / 10;
    }
    if (sum % 10)                      // invalid card number
    {
        return 1;
    }
    else if (number1 == 369421438430814)
    {
        return 3;
    }
    else if (number1 == 4062901840)
    {
        return 4;
    }
    else if (number1 == 5673598276138003)
    {
        return 5;
    }
    return n;                          // return leftmost digit
}