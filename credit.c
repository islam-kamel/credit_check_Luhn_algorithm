#include <cs50.h>
#include <stdio.h>
#include <math.h>


int SUM = 0;

int get_numbers(long number, int digit);
int sum(int length, int multiply);
int confirm(int start[], int digit);

int main(void)
{

    long creditid = get_long("Number: ");
    int ndigit = log10(creditid) + 1;


    get_numbers(creditid, ndigit);

}



int get_numbers(long number, int digit)
{
    int start[2];

    int m = 1;
    int s = 0;

    if (digit <= 13)
    {
        m = 0;
        s = 1;
    }


    for (int i = m; i <= digit; i += 2)
    {

        // get starts number if digit = 13
        if (digit == 13)
        {
            if (i == 10)
            {
                start[0] = number / (long) pow(10, i + 2) % 10;
                start[1] = 0;
                continue;
            }
        }

        // get starts number if digit = 16
        else if (digit == 16 && i == digit - 1)
        {
            start[0] = number / (long) pow(10, i) % 10;
            start[1] = number / (long) pow(10, i - 1) % 10;
        }

        // get starts number i digit = 15
        else if (digit == 15 && i == digit)
        {
            
            start[0] = number / (long) pow(10, i - 1) % 10;
            // printf("---- %i \n",start[0]);
            start[1] = number / (long) pow(10, i - 2) % 10;
        }


        // sum numbers multiply onle
        sum(digit, (number / (long) pow(10, i) % 10) * 2);
    }

    // get other numbers
    for (int i = s; i <= digit; i += 2)
    {
        sum(digit, number / (long) pow(10, i) % 10);
    }

    // get result
    confirm(start, digit);
    return 0;
}


int sum(int length, int multiply)
{
    // Verifying the sent number is the result of the multiplication process
    if (multiply > 9)
    {
        for (int i = 0; i <= 1; i++)
        {
            if (i == 0)
            {
                // Converting a number to a number and then adding the values
                SUM +=  multiply % 10;
            }
            else
            {
                SUM +=  multiply / 10 % 10;
            }
        }
    }

    // If the number is the result of another process
    else
    {
        SUM +=  multiply;
    }

    return 0;

}


int confirm(int start[], int digit)
{
    /*
    Confirmation stage
    of the validity of the
    card number.
    */
    
    // Assign the sent values o the variable
    int start_with = start[0] * 10 + start[1];


    // heck the result of the addition from multiples of 10
    if (SUM  % 10 == 0)
    {
        if (start[0] == 4)
        {
            printf("VISA\n");
    
        }
        else if (start_with >= 51 && start_with < 56)
        {
            printf("MASTERCARD\n");
    
        }
        else if (start_with == 34 || start_with == 37)
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

    return 0;
}