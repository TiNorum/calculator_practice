#pragma once
#include<iostream>

#define MAX_ROW 20
#define MAX_COL 20


void Menu_matrix_calculator();

void addition_matrix();
void subtraction_matrix();
void multiplication_matrix();
void multiplication_by_number();
void matrix_transpose();
void inverse_matrix();
void determinant();
double matrixDet(double matrix[MAX_ROW][MAX_COL], int size);
