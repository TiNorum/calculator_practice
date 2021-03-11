#pragma once
#include <iostream>
#include <iomanip>

void Menu_calculator_ob_drob();

void Addition_of_fractions();
void Subtraction_of_fractions();
void Multiplication_of_fractions();
void Dividing_fractions();
void Comparing_fractions();
void Reduction_of_fractions();
void to_Decimal();

struct fraction
{
	int c = 0;
	int z = 0;

};

int amount_chars(fraction& f);
int NOK(int denominator1, int denominator2);
int NOD(fraction f1);

void print_fraction(fraction f1, double result);
void print_fraction(fraction f1, fraction f2, char sign);
void print_fraction(fraction f1, fraction f2, fraction result, char sign);

void enter_fraction(fraction& f1);
void enter_fraction(fraction& f1, fraction& f2);