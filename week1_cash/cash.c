#include <cs50.h>
#include <stdio.h>

int get_cents(void);
int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickels(int cents);
int calculate_pennies(int cents);
int userInput;
int change;

int main(void)
{
    // Ask how many cents the customer is owed
    int cents = get_cents();
    //next line added by me
    cents = userInput;

    // Calculate the number of quarters to give the customer
    int quarters = calculate_quarters(cents);

    //calculate remaining change after quarters subtracted from total
//    cents = cents % (quarters * 25);


    //subtract total cents from cents value of quarters
    cents = cents - quarters * 25;


    // Calculate the number of dimes to give the customer
    int dimes = calculate_dimes(cents);
    cents = cents - dimes * 10;

    printf("change left after subtracting quarters is: %i\n", cents);

    // Calculate the number of nickels to give the customer
    int nickels = calculate_nickels(cents);
    cents = cents - nickels * 5;

    // Calculate the number of pennies to give the customer
    int pennies = calculate_pennies(cents);
    cents = cents - pennies * 1;

    // Sum coins
    int coins = quarters + dimes + nickels + pennies;

    // Print total number of coins to give the customer
    printf("%i\n", coins);
}

int get_cents(void)
{
    // TODO
    do
    {
        userInput = get_int("Please enter a positive number: ");
    }
    while (userInput <= 0);
    return userInput;
}

int calculate_quarters(int cents)
{
    // TODO
    int quarters = cents / 25;
    printf("number of quarters is: %i\n", quarters);
//    change = cents % 25;
//    printf("%i\n", change);
    return quarters;
}

int calculate_dimes(int cents)
{
    // TODO
    int dimes = cents / 10;
    printf("number of dimes is: %i\n", dimes);
    return dimes;
}

int calculate_nickels(int cents)
{
    // TODO
    int nickels = cents / 5;
    printf("number of nickels is: %i\n", nickels);
    return nickels;
}

int calculate_pennies(int cents)
{
    // TODO
    int pennies = cents / 1;
    printf("number of pennies is: %i\n", pennies);
    return pennies;
}