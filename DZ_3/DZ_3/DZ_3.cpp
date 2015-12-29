//Написать класс для эффективной работы со строками, позволяющий форматировать и сравнивать строки, хранить
//в строках числовые значения и извлекать их.Для этого необходимо реализовать :
//• перегруженные операции присваивания и конкатенации;
//• ввод / вывод строки;
//• операции сравнения и приведения типов;
//• преобразование в число любого типа;
//• поиска символов и подстрок.
//• обращение к элементам строки по индексу.
//Весь функционал должен быть реализован в соответствии с хорошими практиками и необходимыми проверками.
//Написать программу, демонстрирующую работу с этим классом.Программа должна содержать меню,
//позволяющее осуществить проверку всех методов класса.

#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

class String
{
private:
	unsigned size = 0;
	char* str = nullptr;
public:
	String() : str(nullptr), size(0)
	{}

	String(const char *s)
	{
		if (s && *s)
		{
			size = strlen(s) + 1;
			str = new char[size];
			strcpy_s(str, size, s);
		}
	}

	String(const String& s)
	{
		if (this != &s)
			delete[] str;
		size = s.size;
		str = new char[size];
		strcpy_s(str, size, s.str);
	}

	~String()
	{
		if (str)
		{
			delete[] str;
			str = nullptr;
		}
	}

	void operator=(const String& s)
	{
		if (this != &s)
		{
			delete[] str;
			str = nullptr;
		}
		size = s.size;
		str = new char[size];
		strcpy_s(str, size, s.str);
	}

	void operator+=(const char* s)
	{
		if (s && *s)
		{
			int new_size = strlen(s) + size;
			char *new_str = new char[new_size];
			strcpy_s(new_str, size, str);
			delete[] str;
			strcat_s(new_str, new_size, s);
			size = new_size;
			str = new_str;
		}
	}

	bool operator==(const String& s) const
	{
		if (size != s.size)
			return false;
		return !strcmp(str, s.str);
	}	

	bool operator>(const String& s) const
	{
		return strcmp(str, s.str) > 0;
	}

	bool operator<(const String& s) const
	{
		return s > *this;
	}

	bool operator!=(const String& s) const
	{
		return !(*this == s);
	}

	char& operator[](unsigned i) const
	{
		if (i < size - 1)
		{
			return str[i];
		}
	}

	const char *get_str() const
	{
		return str;
	}

	explicit operator int() const
	{
		return atoi(str);
	}

	operator char*()
	{
		return str;
	}

	void SearchUnderStr(char *s) const;
	void SearchSymbol(char symbol) const;
	friend ostream& operator<<(ostream& os, const String& s);
	friend istream& operator>>(istream& is, String& s);
};

int main()
{
	int choice;

	do{
		cout << "MENU:" << endl;
		cout << "1. Input and output string" << endl;
		cout << "2. Show assignation" << endl;
		cout << "3. Show concatenation" << endl;
		cout << "4. Show compare" << endl;
		cout << "5. Show type conversion" << endl;
		cout << "6. Show inversion to int" << endl;
		cout << "7. Show search symbol" << endl;
		cout << "8. Show search understring" << endl;
		cout << "9. Show access by index" << endl;
		cout << "10. Exit" << endl;

		cin >> choice;
		switch (choice)
		{
		case 1:
		{
				  String str;
				  cout << "Input string:" << endl;
				  fflush(stdin);
				  cin >> str;
				  cout << "You input: " << endl << str << endl;

				  break;
		}
		case 2:
		{
				  String str1("Happy New Year!");
				  cout << "Show string1: " << str1.get_str() << endl;
				  String str2;
				  str2 = str1;
				  cout << "Show string2: " << str2.get_str() << endl;

				  break;
		}
		case 3:
		{
				  String str3("Happy New Year!");
				  cout << "Show string1: " << str3.get_str() << endl;
				  str3 += "Marry Christmas!";
				  cout << "Show string1 after concatenation: " << str3.get_str() << endl;

				  break;
		}
		case 4:
		{
				  String str41 = "Happy Christmas!";
				  cout << "Show string1: " << str41.get_str() << endl;
				  String str42 = "Marry Christmas!";
				  cout << "Show string2: " << str42.get_str() << endl;
				  cout << "Show compare string1 and string2: " << endl;
				  if (str41 == str42)
					  cout << "Lenghts strings equal" << endl;
				  else
				  {
					  cout << "Lenghts strings unequal" << endl;
					  if (str41 > str42)
						  cout << "String1 bigger from ASCII code" << endl;
					  else
						  cout << "String2 bigger from ASCII code" << endl;
				  }

				  break;
		}
		case 5:
		{
				  String str5 = "123df45";
				  cout << static_cast<char*>(str5) << endl;

				  break;
		}
		case 6:
		{
				  cout << "Show inversion Marry to int:" << int("Marry") << endl;
				  cout << "Show inversion Marry Christmas! to int:" << int("Marry Christmas!") << endl;

				  break;
		}
		case 7:
		{
				  String str7 = "Happy New Year!";
				  char symbol;
				  cout << "Show string: " << str7.get_str() << endl;
				  cout << "Input symbol:" << endl;
				  cin >> symbol;
				  str7.SearchSymbol(symbol);

				  break;
		}
		case 8:
		{
				  String str8 = "Happy New Year!";
				  char understr[150];
				  cout << "Show string: " << str8.get_str() << endl;
				  cout << "Input understring:" << endl;
				  cin >> understr;
				  str8.SearchUnderStr(understr);

				  break;
		}
		case 9:
		{
				  unsigned i;
				  String str9 = "Happy New Year!";
				  cout << "Show string: " << str9.get_str() << endl;
				  cout << "Input index: ";
				  cin >> i;
				  if (i < strlen(str9))
				  {
					  cout << "Show element: " << str9[i] << endl;
				  }
				  else
				  {
					  cout << "Error!No element!" << endl;
				  }
				  break;
		}
		case 10:
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

ostream& operator<<(ostream& os, const String& s)
{
	if (s.str)
		return os << s.str;
	return os;
}

istream& operator>>(istream& is, String& s)
{
	char newstr[150];

	fgets(newstr, 150, stdin);
	if (s.str)
	{
		delete[]s.str;
		s.str = nullptr;
	}
	s.str = new char[strlen(newstr) + 1];
	strcpy_s(s.str, strlen(newstr) + 1, newstr);

	return is;
}

void String::SearchUnderStr(char *s) const
{
	char* understr = nullptr;
	if (s && *s)
	{
		understr = strstr(str, s);
	}
	if (understr)
	{
		cout << "First entrance of understring be found: " << understr << endl;
	}
	else
	{
		cout << "Understring is not be found!" << endl;
	}
}

void String::SearchSymbol(char symbol) const
{
	unsigned count = 0;

	for (unsigned i = 0; i < size - 1; i++)
	{
		if (str[i] == symbol)
		{
			cout << "First entrance of symbol " << symbol << " be found in position " << i + 1 << endl;
			++count;
			break;
		}
	}
	if (count == 0)
		cout << "Symbol is not be found!" << endl;
}
