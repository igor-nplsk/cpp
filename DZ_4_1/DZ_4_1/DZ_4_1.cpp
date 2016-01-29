//Создать абстрактный базовый класс Figure с виртуальными методами вычисления площади и периметра.
//Создать производные классы : Rectangle(прямоугольник), Circle(круг), Trapezium(трапеция)
//со своими функциями площади и периметра.

#include <iostream>
#include <cmath>
using namespace std;


class Figure
{
public:
	Figure() = default;
	Figure(const Figure& fig) = delete;
	const Figure& operator=(const Figure& fig) = delete;
	virtual ~Figure()
	{}
	virtual double Area() = 0;
	virtual double Perimeter() = 0;
};

class Circle : public Figure
{
	double r;
public:
	Circle() = default;
	Circle(double Radius) : r(Radius)
	{}
	Circle(const Circle& cir) = delete;
	const Circle& operator=(const Circle& cir) = delete;
	~Circle()
	{}
	void SetData()
	{
		cout << "Input radius: ";
		cin >> r;
	}
	double Area() override
	{
		return 3.14*r*r;
	}
	double Perimeter() override
	{
		return 2 * 3.14*r;
	}
};

class Rectangle : public Figure
{
	double a;
	double b;
public:
	Rectangle() = default;
	Rectangle(double Side1, double Side2) : a(Side1), b(Side2)
	{}
	Rectangle(const Rectangle& rec) = delete;
	const Rectangle& operator=(const Rectangle& rec) = delete;
	~Rectangle()
	{}
	void SetData()
	{
		cout << "Input side1: ";
		cin >> a;
		cout << "Input side2: ";
		cin >> b;
	}
	double Area() override
	{
		return a*b;
	}
	double Perimeter() override
	{
		return (a + b) * 2;
	}
};

class Trapezium : public Figure
{
	double a;
	double b;
	double c;
	double d;
public:
	Trapezium() = default;
	Trapezium(double Side1, double Side2, double Side3, double Side4) : a(Side1), b(Side2), c(Side3), d(Side4)
	{}
	Trapezium(const Trapezium& tra) = delete;
	const Trapezium& operator=(const Trapezium& tra) = delete;
	void SetData()
	{
		cout << "Input bigger parallel side1: ";
		cin >> a;
		cout << "Input lesser parallel side2: ";
		cin >> b;
		cout << "Input side3: ";
		cin >> c;
		cout << "Input side4: ";
		cin >> d;
	}
	double Area() override
	{
		double h;
		h = sqrt(pow(c, 2) - pow(((pow((a - b), 2) + pow(c, 2) - pow(d, 2)) / (2 * (a - b))), 2));
		return (a + b)*h / 2;
	}
	double Perimeter() override
	{
		return a + b + c + d;
	}
};

int main()
{
	int choice;

	do{
		cout << "Choose figure:" << endl;
		cout << "1. Rectangle " << endl;
		cout << "2. Circle " << endl;
		cout << "3. Trapezium " << endl;
		cout << "4. Exit" << endl;

		cin >> choice;
		switch (choice)
		{
		case 1:
		{
				  Rectangle R;
				  R.SetData();
				  cout << "Area of Rectangle = " << R.Area() << endl;
				  cout << "Perimeter of Rectangle = " << R.Perimeter() << endl << endl;
				  break;
		}
		case 2:
		{
				  Circle C;
				  C.SetData();
				  cout << "Area of Circle = " << C.Area() << endl;
				  cout << "Perimeter of Circle = " << C.Perimeter() << endl << endl;
				  break;
		}
		case 3:
		{
				  Trapezium T;
				  T.SetData();
				  cout << "Area of Trapezium = " << T.Area() << endl;
				  cout << "Perimeter of Trapezium = " << T.Perimeter() << endl;
				  break;
		}
		case 4:
		{
				  exit(1);
		}
		default:
		{
				   cout << "Incorrect choice!" << endl;
				   break;
		}
		}
	} while (true);

	return 0;
}