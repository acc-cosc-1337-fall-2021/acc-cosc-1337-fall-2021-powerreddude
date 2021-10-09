//write include statement for decisions header
#include "decisions.h"
#include <iostream>

using std::cout;
//Write code for function(s) code here

std::string get_letter_grade_using_if(int grade)
{
    if (grade <= 100 && grade >= 90)
    {
        return "A";
    } else if (grade >= 80) {
        return "B";
    } else if (grade >= 70) {
        return "C";
    } else if (grade >= 60) {
        return "D";
    } else if (grade >= 0) {
        return "F";
    } else {
        return "error: invalid int";
    }
}

std::string get_letter_grade_using_switch(int grade)
{
    switch (grade)
    {
    case 90 ... 100:
        return "A";
        break;
    
    case 80 ... 89:
        return "B";
        break;
    
    case 70 ... 79:
        return "C";
        break;
    
    case 60 ... 69:
        return "D";
        break;
    
    case 0 ... 59:
        return "F";
        break;
    
    default:
        return "error: invalid int";
        break;
    }
}

void print_main_menu()
{
    cout<<"\tMAIN MENU\n\n1-Letter grade using if\n2-Letter grade using switch\n3-Exit\n\n";
}

int get_int(std::string prompt)
{
    cout<<prompt;
    int num;
    std::cin>>num;
    if(num > 100 || num < 0)
    {
        return get_int("Please enter a valid number: ");
    } else {
        return num;
    }
}

void run_grade_to_letter_grade_conversion()
{
    int num;

	switch (get_int("Please enter your selection: "))
	{
	case 1:
		num = get_int("Please enter your grade: ");

		if (num >= 0 && num <= 100)
		{
			std::cout<<"You're letter grade is "<<get_letter_grade_using_if(num)<<"\n";
		} else {
			std::cout<<"Please rerun and enter a valid number\n";
		}

		break;
	
	case 2:
		num = get_int("Please enter your grade: ");

		if (num >= 0 && num <= 100)
		{
			std::cout<<"You're letter grade is "<<get_letter_grade_using_switch(num)<<"\n";
		} else {
			std::cout<<"Please rerun and enter a valid number\n";
		}
		
		break;
		
	default:
		break;
	}
}