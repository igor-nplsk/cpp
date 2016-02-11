//Написать приложение, которое «угадывает» задуманное пользователем число от 1 до 100.
//Для запроса к пользователю использовать окна сообщений.После того, как число отгадано,
//необходимо вывести количество попыток, потребовавшихся для этого, и предоставить
//пользователю возможность сыграть еще раз, не завершая программу.Окна сообщений следует
//оформить кнопками и иконками в соответствии с конкретной ситуацией.

#include <windows.h>
#include <tchar.h>
#include <cstdlib>
#include <ctime>

INT WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR lpszCmdLine, int nCmdShow)
{
	std::srand(time(NULL));
	int count = 0;
	TCHAR szTitle[] = _T("Угадай число");
	TCHAR buf[64];
	wsprintf(buf, _T("Загадайте число в диапазоне от 1 до 100"));
	MessageBox(NULL, buf, szTitle, MB_OK | MB_ICONINFORMATION);

	while (true)
	{
		int id;
		int number = rand() % 100 + 1;
		wsprintf(buf, _T("Ваше число: %d ?"), number);
		++count;
		id = MessageBox(NULL, buf, szTitle, MB_YESNO | MB_ICONQUESTION);
		if (id == IDYES)
		{
			wsprintf(buf, _T("Число угадано с %d попытки"), count);
			MessageBox(NULL, buf, szTitle, MB_OK | MB_ICONASTERISK);
			id = MessageBox(NULL, _T("Хотите сыграть еще?"),
				szTitle, MB_YESNO | MB_ICONQUESTION);
			if (id == IDNO)
				break;
			else
				count = 0;
		}
	}
	return 0;
}
