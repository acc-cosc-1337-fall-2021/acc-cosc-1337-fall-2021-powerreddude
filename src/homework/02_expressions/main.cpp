//write include statements
#include <iostream>
#include "hwexpressions.h"

//write namespace using statement for cout
using std::cout;
using std::cin;

/*
Call multiply_numbers with 10 and 10 parameter values and display function result
*/
int main()
{
	double meal_amount;

	double tip_rate;

	double tip_amount;

	double tax_amount;

	double total;

	cin>>meal_amount;

	tax_amount = get_sales_tax_amount(meal_amount);

	cin>>tip_rate;

	tip_amount = get_tip_amount(meal_amount, tip_rate);

	total = meal_amount + tip_amount + tax_amount;

	cout<<"\nMeal Amount:\t"<<meal_amount<<"\nSales Tax:\t"<<tax_amount<<"\nTip Amount:\t"<<tip_amount<<"\nTotal:\t"<<total;

	return 0;
}
