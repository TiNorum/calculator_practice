#pragma once
#include<iostream>
#include<SDL.h>
#include<thread>

//-------������ ����-----
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;


/* ��������� �������� ������� ��� �������� X � ����������� */
double polynomial_degree_function(double x);
double power_function(double x);
double exponential_function(double x);
double logarithmic_function(double x);
double sinusoid_function(double x);
double �osine_function(double x);

/* ������� ����� ���������� */
void find_extremums(double(*func)(double), double a, double b);

/* ������� ����� ���������� */
double simpson(double a, double b, int n);
/* ������ ������ � ������� ���������� SDL */
int draw_graph(double (*func)(double));

/* ���������� y=0 �� ������� */
void find_y0(double(*func)(double));
/* ���������� y=0 � ������� ������ ��������� */
double dichotomy_method(double (*func)(double), double a, double b, double eps);

/* ���������� ��������� */
void integral(double(*func)(double));
/* ���������� ��������� � ������� ������ �������� */
double method_simpson(double (*f)(double), double a, double b, double h);

void Menu_functions();

