//Создать класс Triangle для представления треугольника.Поля данных являются сторонами треугольника.
//Определить подходящие исключения.Должны быть реализованы операции получения и изменения полей данных,
//вычисления площади, вычисления периметра, вычисления высот, вычисления углов,
//определения вида треугольника(равносторонний, равнобедренный, прямоугольный).
//В случае возникновения ошибок методы должны генерировать исключения.

#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

#define PI 3.14159265

class Triangle {
private:
	double side1;
	double side2;
	double side3;
	double angle1, angle2, angle3;
public:
	Triangle() = default;
	Triangle(const double& s1, const double& s2, const double& s3) : side1(s1), side2(s2), side3(s3)
	{}
	Triangle(const Triangle& obj) = delete;
	const Triangle& operator=(const Triangle& obj) = delete;
	~Triangle()
	{}

	class Negative
	{};

	void set_sides()
	{
		cout << "Input sides of Triangle(side1 side2 side3): " << endl;
		cin >> side1 >> side2 >> side3;

		if (side1 < 0 || side2 < 0 || side3 < 0)
			throw Negative();
	}

	void square()
	{
		double area, P;
		P = (side1 + side2 + side3) / 2;
		area = sqrt(P*(P - side1)*(P - side2)*(P - side3));
		cout << "Area of Triangle: " << area << endl;
	}

	void perimeter()
	{
		double perimeter;
		perimeter = side1 + side2 + side3;
		cout << "Perimeter of Triangle: " << perimeter << endl;
	}

	void hight()
	{
		double h1, h2, h3, p;
		p = (side1 + side2 + side3) / 2;
		h1 = sqrt(4 * p*((p - side1)*(p - side2)*(p - side3)) / (side1*side1));
		h2 = sqrt(4 * p*((p - side1)*(p - side2)*(p - side3)) / (side2*side2));
		h3 = sqrt(4 * p*((p - side1)*(p - side2)*(p - side3)) / (side3*side3));
		cout << "hight1: " << h1 << " " << "hight2: " << h2 << " " << "hight3: " << h3 << endl;
	}

	void angle()
	{
		angle1 = acos((side2*side2 + side3*side3 - side1*side1) / (2 * side2*side3))*180.0 / PI;
		angle2 = acos((side1*side1 + side3*side3 - side2*side2) / (2 * side1*side3))*180.0 / PI;
		angle3 = acos((side2*side2 + side1*side1 - side3*side3) / (2 * side2*side1))*180.0 / PI;
		cout << "angle1: " << angle1 << "\nangle2: " << angle2 << "\nangle3: " << angle3 << endl;
	}

	void kind_of_triangle()
	{
		if (static_cast<int>(side1) == static_cast<int>(side2) == static_cast<int>(side3))
			cout << "Equilateral triangle" << endl;
		if ((static_cast<int>(side1) == static_cast<int>(side2)) ||
			(static_cast<int>(side2) == static_cast<int>(side3)) ||
			(static_cast<int>(side3) == static_cast<int>(side1)))
			cout << "Isosceles triangle" << endl;
		if ((static_cast<int>(angle1) == 90) || (static_cast<int>(angle2) == 90) || (static_cast<int>(angle3) == 90))
			cout << "Rectangular triangle" << endl;
	}

	double get_side1()
	{
		return side1;
	}
	double get_side2()
	{
		return side2;
	}
	double get_side3()
	{
		return side3;
	}
};

int main()
{
	try
	{
		Triangle T;
		T.set_sides();
		if (T.get_side1() + T.get_side2() <= T.get_side3() ||
			T.get_side2() + T.get_side3() <= T.get_side1() ||
			T.get_side3() + T.get_side1() <= T.get_side2())
			throw 11;

		T.square();
		T.perimeter();
		T.hight();
		T.angle();
		T.kind_of_triangle();
	}
	catch (int)
	{
		cout << "Triangle is not exist!" << endl;
	}
	catch (Triangle::Negative)
	{
		cout << "Input negative number!" << endl;
	}

	return 0;
}