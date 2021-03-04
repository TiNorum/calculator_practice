#pragma once
#include<iostream>
#include<SDL.h>
#include<thread>

//-------Размер окна-----
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;


/* Возращает значение функции при заданном X и коэфицентов */
double polynomial_degree_function(double x);
double power_function(double x);
double exponential_function(double x);
double logarithmic_function(double x);
double sinusoid_function(double x);
double сosine_function(double x);

/* Находим точки экстремума */
void find_extremums(double(*func)(double), double a, double b);

/* Находим точки экстремума */
double simpson(double a, double b, int n);
/* Рисует график с помощью библиотеки SDL */
int draw_graph(double (*func)(double));

/* Нахождение y=0 на отрезке */
void find_y0(double(*func)(double));
/* Нахождение y=0 с помощью метода дихотомии */
double dichotomy_method(double (*func)(double), double a, double b, double eps);

/* Вычисление интеграла */
void integral(double(*func)(double));
/* Нахождение интеграла с помощью метода Симпсона */
double method_simpson(double (*f)(double), double a, double b, double h);

void Menu_functions();

