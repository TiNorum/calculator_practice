#include "Functions.h"

//-------отвечает за закрытия окна SDL-------
bool quit = false;

//-------Переменные масштабирования и сдвига графика-------
int scroll_x = 0, scroll_y = SCREEN_HEIGHT / 2;
int Ax = -10, Bx = 10; // - промежуток по Ох
int Ay = -10, By = 10; // - промежуток по Оу


/* Коэфициенты функций */
double A, B, C, D;
double* array_A; // - в случае полином степени N нужен нужен массив для аргументов А0...An;
double N; // - количество слагаемых в полиноме степени
double сosine_function(double x);



void Menu_functions()
{
	bool quite_menu = false;
	while (!quite_menu)
	{
		system("cls");
		std::cout << "\t\t\tРабота с функциями:" << std::endl;
		std::cout << "1)Вычисление определенного интеграла на отрезке" << std::endl;
		std::cout << "2)Построение графика" << std::endl;
		std::cout << "3)Поиск корня Y=0 на отрезке" << std::endl;
		std::cout << "4)Поиск экстремумов на отрезке" << std::endl;
		std::cout << "0)Назад" << std::endl;
		std::cout << std::endl << "Выберите номер задания: ";

		unsigned short a;

		std::cin >> a;
		system("cls");

		if (a == 0) break;
		
		bool quite_menu_2 = false;

		unsigned short b;

		double (*func)(double) = NULL;


		while (!quite_menu_2)
		{
			std::cout << "\t\t\tВыберите функцию:" << std::endl;
			std::cout << "1)Полином степени N" << std::endl << "\ta0+a1*x+a2*x^2+...+an*x^n" << std::endl;
			std::cout << "2)Степенная " << std::endl << "\ta*x^b+с" << std::endl;
			std::cout << "3)Показательная" << std::endl << "\ta*b^x+с" << std::endl;
			std::cout << "4)Логарифмическая" << std::endl << "\ta*ln(x*b)+c" << std::endl;
			std::cout << "5)Синусоийда" << std::endl << "\ta*sin(x*b+c)+d" << std::endl;
			std::cout << "6)Косинусойда" << std::endl << "\ta*cos(x*b+c)+d" << std::endl;
			std::cout << "0)Назад" << std::endl;
			std::cout << std::endl << "Выберите номер задания: ";
			std::cin >> b;
			system("cls");
			quite_menu_2 = true;

			switch (b)
			{
			case 1:
				func = polynomial_degree_function;  
				N = 0;

				std::cout << "\ta0+a1*x+a2*x^2+...+an*x^n" << std::endl;

				while (N <= 0)
				{
					std::cout << "Введите N:";
					std::cin >> N;
				}
				
				array_A = new double[N];

				for (int i = 0; i < N; i++)
				{
					std::cout << "Введите A[" << i << "]: ";
					std::cin >> array_A[i];
				}

				break;
			case 2:
				
				func = power_function;
				
				std::cout << "\ta*x^b+с" << std::endl;
				std::cout << "Введите A: ";
				std::cin >> A;
				std::cout << "Введите B: ";
				std::cin >> B;
				std::cout << "Введите C: ";
				std::cin >> C;

				break;
			case 3:
				func = exponential_function;

				std::cout << "\ta*b^x+с" << std::endl;
				std::cout << "Введите A: ";
				std::cin >> A;
				std::cout << "Введите B: ";
				std::cin >> B;
				std::cout << "Введите C: ";
				std::cin >> C;	

				break;
			case 4:
				func = logarithmic_function;
			
				std::cout << "\ta * ln(x * b) + c" << std::endl;
				std::cout << "Введите A: ";
				std::cin >> A;
				std::cout << "Введите B: ";
				std::cin >> B;
				std::cout << "Введите C: ";
				std::cin >> C;
			
				break;
			case 5:
				func = sinusoid_function;

				std::cout<< "\ta*sin(x*b+c)+d" << std::endl;
				std::cout << "Введите A: ";
				std::cin >> A;
				std::cout << "Введите B: ";
				std::cin >> B;
				std::cout << "Введите C: ";
				std::cin >> C;
				std::cout << "Введите D: ";
				std::cin >> D;

				break;
			case 6:
				func = сosine_function;

				std::cout << "\ta*cos(x*b+c)+d" << std::endl;
				std::cout << "Введите A: ";
				std::cin >> A;
				std::cout << "Введите B: ";
				std::cin >> B;
				std::cout << "Введите C: ";
				std::cin >> C;
				std::cout << "Введите D: ";
				std::cin >> D;

				break;
			case 0:
				break;
			default:
				quite_menu_2 = false;
			}
		}

		double x1, x2;

		switch (a)
		{
		case 1:
			integral(func);
			system("pause");
			break;

		case 2:

			draw_graph(func);
			break;

		case 3:
			
			find_y0(func);
			system("pause");
			break;

		case 4:
			 x1, x2;
			
			 do {
				 std::cout << "Введите отрезок [a,b]: " << std::endl;
				 std::cin >> x1 >> x2;
			 } while (x1 >= x2);

			find_extremums(func, x1, x2);
			system("pause");
			break;
		}
	}

	delete[] array_A;
}


double polynomial_degree_function(double x)
{
	double sum = 0;

	for (int i = 0; i < N; i++)
	{
		sum += array_A[i] * pow(x, i);
	}

	return sum;
}


double power_function(double x)
{
	return A * pow(x , B) + C;
}


double exponential_function(double x)
{
	return A * pow(B ,x) + D;
}


double logarithmic_function(double x)
{
	return A * log(x * B) + C;
}


double sinusoid_function(double x)
{ 
	return A * sin(x * B + C) + D;
}


double сosine_function(double x)
{
	return A * cos(x * B + C) + D;
}


//-------Функция обработки событий окна-------
void event_handling(SDL_Event* event)
{
	int coord_mous_click_x = -1, coord_mous_click_y = -1;
	bool b = false;
	while (!quit)
	{
		switch (event->type)
		{
		case SDL_QUIT:
			quit = true;
			event->type = NULL;
		case SDL_WINDOWEVENT:
			break;
		case SDL_MOUSEWHEEL:
			if (Ax - event->wheel.y * 10 < Bx + event->wheel.y * 10)
			{
				Ax -= event->wheel.y * 10;
				Bx += event->wheel.y * 10;

			}
			event->type = NULL;
			break;
		case SDL_MOUSEBUTTONDOWN:
			b = true;
			break;
		case SDL_MOUSEBUTTONUP:
			b = false;
			event->type = NULL;
			break;
		case SDL_MOUSEMOTION:
			if (!b)   break;


			if (!(event->motion.xrel > SCREEN_WIDTH || event->motion.yrel > SCREEN_HEIGHT))
			{
				scroll_x -= event->motion.xrel;
				scroll_y += event->motion.yrel;
			}

			if (event->motion.x == 0 || event->motion.x == SCREEN_WIDTH || event->motion.y == 0 || event->motion.y == SCREEN_HEIGHT)
				event->type = SDL_MOUSEBUTTONUP;
			else
				event->type = NULL;
			break;
		}
	}

}
//-------Функция обработки событий окна-------


int draw_graph(double (*func)(double))
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		std::cout << "SDL_Error:" << SDL_GetError(); //- проверка на открытие окна;
	}
	else
	{
		SDL_Window* window = NULL; //окно 

		window = SDL_CreateWindow(u8"Построение графика", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (window == NULL)
		{
			std::cout << " SDL_Error:" << SDL_GetError();
		}
		else
		{
			SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);
			SDL_Event event;

			std::thread th(event_handling, &event);

			quit = false;
			while (!quit)
			{
				SDL_PollEvent(&event);

				SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
				SDL_RenderClear(renderer);

				SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);

				SDL_RenderDrawLine(renderer, 0, scroll_y, SCREEN_WIDTH,
					scroll_y);

				SDL_RenderDrawLine(renderer, SCREEN_WIDTH / 2 - scroll_x, 0, SCREEN_WIDTH / 2 - scroll_x, SCREEN_HEIGHT);

				double dp_x = SCREEN_WIDTH / (double(abs(Ax)) + abs(Bx));
				double dp_y = SCREEN_WIDTH / (double(abs(Ay)) + abs(By));


				for (double i = scroll_x; i < SCREEN_WIDTH + scroll_x; i++)
				{
					double y = func(Ax+i/dp_x);
					if (-round(y * dp_y) + scroll_y > SCREEN_HEIGHT || -round(y * dp_y) + scroll_y < 0) continue;

					double y2 = func(Ax + (i+1) / dp_x);


					SDL_SetRenderDrawColor(renderer, 255, 0, 0, 0);
					SDL_RenderDrawLine(renderer, i - scroll_x, -round(y * dp_y) + scroll_y, i + 1 - scroll_x,
						-round(y2 * dp_y) + scroll_y);
				}

				SDL_RenderPresent(renderer);
			}

			th.join();

			SDL_DestroyRenderer(renderer);
			SDL_DestroyWindow(window);
			SDL_Quit();
		}



	}
	return 0;
}


void integral(double(*func)(double))
{
	double a, b, h;

	do {
		std::cout << "Введите отрезок [a,b]: ";
		std::cin >> a >> b;
	} while (a >= b);

	h = 0.01; // шаг интегрирования
	std::cout << "Интеграл на отрезке [" << a << ", " << b << "] равен: " << method_simpson(func,a,b,h) << std::endl;

}


void find_y0(double(*func)(double))
{
	double x1, x2;
	double eps;

	eps = 0.0001;

	do {
		std::cout << "Введите отрезок [a,b]: " << std::endl;
		std::cin >> x1 >> x2;
	} while (x1 >= x2);


	std::cout << "y = 0, при x = " << dichotomy_method(func, x1, x2, eps) << "\tточность  " << eps << std::endl;
}


double dichotomy_method(double(*func)(double), double a, double b, double eps)
{
	double c = (a + b) / 2;

	if (func(a) * func(c) > 0)
		b = c;
	else
		a = c;

	if (abs(b - a) > eps && func(c) != 0)
		return dichotomy_method(func,a, b,eps);
	else
		return c;
}


void find_extremums(double(*func)(double), double a, double b)
{
	float step = 0.001;
	bool f = func(a) > func(a + step);
	double y1, y2;

	for (float i = a; i < b; i += step)
	{
		y1 = func(i);
		y2 = func(i + step);

		if ( (y2 -y1) / step > 0.0001)
		{
			std::cout << "x = " << i << std::endl;
		}
		
	}

}


double method_simpson(double (*f)(double),double a, double b, double h)
{
	double n = (b - a) / h; // задаём число разбиений n
	double integral = h * (f(a) + f(b)) / 6.0;

	for (int i = 1; i <= n; i++)
		integral = integral + 4.0 / 6.0 * h * f(a + h * (i - 0.5));

	for (int i = 1; i <= n - 1; i++)
		integral = integral + 2.0 / 6.0 * h * f(a + h * i);
	
	return integral;
}