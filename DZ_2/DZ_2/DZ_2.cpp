//Описать классы, реализующие RAII - обёртки(передача прав, уникальный ресурс, совместное владение)
//над ресурсом(ресурс может быть любой).Написать программу, демонстрирующую работу с этим классом.
//Программа должна содержать меню, позволяющее осуществить проверку всех методов классов.

#include <iostream>
#include <cstring>
using namespace std;

class String1
{
private:
	unsigned size = 0;
	char *str = nullptr;
public:
	String1()
	{}

	String1(const char *s) : str(nullptr), size(0)
	{
		if (s && *s)
		{
			size = strlen(s) + 1;
			str = new char[size];
			strcpy_s(str, size, s);
		}
	}

	String1(String1& s)
	{
		str = s.str;
		s.str = nullptr;
	}

	void operator=(String1& s)
	{
		if (this != &s)
			delete[] str;
		str = s.str;
		s.str = nullptr;
	}

	const char *get_str() const
	{
		return str;
	}

	~String1()
	{
		if (str)
		{
			delete[] str;
			str = nullptr;
		}
	}
};

class String2
{
private:
	unsigned size = 0;
	char *str = nullptr;
public:
	String2()
	{}

	String2(const char *s)
	{
		if (s && *s)
		{
			size = strlen(s) + 1;
			str = new char[size];
			strcpy_s(str, size, s);
		}
	}

	String2(const String2& str) = delete;

	void operator=(const String2& s) = delete;

	const char *get_str() const
	{
		return str;
	}

	~String2()
	{
		if (str)
		{
			delete[] str;
			str = nullptr;
		}
	}
};

class String3
{
private:
	unsigned size = 0;
	char *str = nullptr;
	int *count = nullptr;
public:
	String3()
	{}

	String3(const char *s)
	{
		if (s && *s)
		{
			size = strlen(s) + 1;
			str = new char[size];
			strcpy_s(str, size, s);
			count = new int;
			*count = 1;
		}
	}

	String3(const String3& s)
	{
		str = s.str;
		count = s.count;
		++(*count);
	}

	void operator=(String3& s)
	{
		if (this != &s)
			delete[] str;
		str = s.str;
		count = s.count;
		++(*count);
	}

	const char *get_str() const
	{
		return str;
	}

	~String3()
	{
		if (str && --(*count) == 1)
		{
			delete[] str;
			str = nullptr;
		}
		else
			--(*count);
	}
};

int main()
{
	int choice;

	do{
		cout << "MENU:" << endl;
		cout << "1. Show pass of rights" << endl;
		cout << "2. Show unique resource" << endl;
		cout << "3. Show joint ownership" << endl;
		cout << "4. Exit" << endl;

		cin >> choice;

		switch (choice)
		{
		case 1:
		{
				  String1 str = "Test1";
				  cout << "String str: " << str.get_str() << " AddressPointer= " << &str
					  << " AddressString= " << (int*)str.get_str() << endl << endl;

				  String1 str1 = str;
				  cout << "Output after String1 str1=str:" << endl;
				  cout << "String str1= " << str1.get_str() << " AddressPointer1= " << &str1
					  << " AddressString1= " << (int*)str1.get_str() << endl << endl;

				  String1 str2;
				  str2 = str1;
				  cout << "Output after str2=str1:" << endl;
				  cout << "String str2= " << str2.get_str() << " AddressPointer2= " << &str2
					  << " AddressString2= " << (int*)str2.get_str() << endl << endl;

				  break;
		}
		case 2:
		{
				  String2 str = "Test2";

				  cout << "String str: " << str.get_str() << " AddressPointer= " << &str
					  << " AddressString= " << (int*)str.get_str() << endl << endl;

				  //String2 str1 = str;                           // эта операция запрещена (функция удалена)
				  //String2 str2;
				  //str2 = str1;                                  // эта операция запрещена (функция удалена)

				  cout << "Error!String2 str1 = str; - it is a deleted function." << endl;
				  cout << "Error!String2 str2; str1 = str; - it is a deleted function." << endl << endl;

				  break;
		}
		case 3:
		{
				  String3 str = "Test3";
				  cout << "String str: " << str.get_str() << " AddressPointer= " << &str
					  << " AddressString= " << (int*)str.get_str() << endl << endl;

				  String3 str1 = str;
				  cout << "Output after String3 str1=str:" << endl;
				  cout << "String str= " << str.get_str() << " AddressPointer= " << &str
					  << " AddressString= " << (int*)str.get_str() << endl;
				  cout << "String str1= " << str1.get_str() << " AddressPointer1= " << &str1
					  << " AddressString1= " << (int*)str1.get_str() << endl << endl;

				  String3 str2;
				  str2 = str1;
				  cout << "Output after str2=str1:" << endl;
				  cout << "String str= " << str.get_str() << " AddressPointer= " << &str
					  << " AddressString= " << (int*)str.get_str() << endl;
				  cout << "String str1= " << str1.get_str() << " AddressPointer1= " << &str1
					  << " AddressString1= " << (int*)str1.get_str() << endl;
				  cout << "String str2= " << str2.get_str() << " AddressPointer2= " << &str2
					  << " AddressString2= " << (int*)str2.get_str() << endl << endl;

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
