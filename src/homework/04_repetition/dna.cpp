//add include statements
#include <iostream>

//add function(s) code here

int factorial(int num)
{
    int sum = num;

    for(int i = 1; i < num; i++)
    {
        sum *= i;
    }

    return sum;
}

int gcd(int num1, int num2)
{
    if(num1 <= 0 || num2 <= 0) return 0; // added to make code more robust incase of later use without input validation
    
    while(num1 != num2)
    {
        if(num2 > num1) 
        {
            num1 = num1 + num2; // swap the values of the variables without temp variable
            num2 = num1 - num2;
            num1 = num1 - num2;
        } 
        else 
        {
            num1 -= num2;
        }
    }
    return num1;
}

int get_int(std::string prompt)
{
    std::cout<<prompt;
    int num;
    std::cin>>num;
    if(num >= 0)
    {
        return num;
    }
    else
    {
        return get_int("Please enter a valid number (>= 0): ");
    }
}

void print_menu()
{
    std::cout<<"\n\n1-Factorial\n2-Greatest Common Divisor\n3-Exit\n\n";
}

bool run_menu_choice()
{
    int choice = get_int("Please enter a menu option: ");

    switch (choice)
    {
    case 1:
        choice = factorial(get_int("Please enter the number you would like the factorial of: "));

        std::cout<<"\nResult: "<<choice<<std::endl;
        break;
    
    case 2:
        choice = gcd(get_int("Please enter a number: "), get_int("Please enter a number: "));

        std::cout<<"\nResult: "<<choice<<std::endl;
        break;
    
    case 3:
        std::cout<<"Are you sure you would like to exit y/n: ";

        char exit;

        std::cin>>exit;

        if(exit == 'y')
        {
            return false;
        }
    default:
        break;
    }
    return true;
}