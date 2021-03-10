#pragma once
#include<iostream>
#include<SDL.h>
#include<thread>

//-------Ðàçìåð îêíà-----
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;


/* Âîçðàùàåò çíà÷åíèå ôóíêöèè ïðè çàäàííîì X è êîýôèöåíòîâ */
double polynomial_degree_function(double x);
double power_function(double x);
double exponential_function(double x);
double logarithmic_function(double x);
double sinusoid_function(double x);
double ñosine_function(double x);

/* Íàõîäèì òî÷êè ýêñòðåìóìà */
void find_extremums(double(*func)(double), double a, double b);

/* Íàõîäèì òî÷êè ýêñòðåìóìà */
double simpson(double a, double b, int n);
/* Ðèñóåò ãðàôèê ñ ïîìîùüþ áèáëèîòåêè SDL */
int draw_graph(double (*func)(double));

/* Íàõîæäåíèå y=0 íà îòðåçêå */
void find_y0(double(*func)(double));
/* Íàõîæäåíèå y=0 ñ ïîìîùüþ ìåòîäà äèõîòîìèè */
double dichotomy_method(double (*func)(double), double a, double b, double eps);

/* Âû÷èñëåíèå èíòåãðàëà */
void integral(double(*func)(double));
/* Íàõîæäåíèå èíòåãðàëà ñ ïîìîùüþ ìåòîäà Ñèìïñîíà */
double method_simpson(double (*f)(double), double a, double b, double h);

void Menu_functions();

