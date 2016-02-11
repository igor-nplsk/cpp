//Написать приложение, позволяющее вывести на экран краткое резюме с помощью последовательности окон сообщений
//(количество окон сообщений – не менее трёх).На заголовке последнего окна сообщения должно отобразиться
//среднее число символов на странице(общее число символов в резюме поделить на количество окон сообщений).

#include<windows.h>
#include<tchar.h>

INT WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR lpszCmdLine, int nCmdShow)
{
	TCHAR szTitleFirst[] = _T("Резюме");
	TCHAR szRezume1[] = _T("Я закончил среднюю школу");
	TCHAR szRezume2[] = _T("Я закончил Минский радиотехнический институт");
	TCHAR szRezume3[] = _T("Сейчас я учусь в компьютерной академии");
	MessageBox(NULL, szRezume1, szTitleFirst, MB_OK | MB_ICONINFORMATION);
	MessageBox(NULL, szRezume2, szTitleFirst, MB_OK | MB_ICONINFORMATION);
	TCHAR szTitleSecond[80];

	// этот код компилируется универсально, но среднее число будет целым

	/*int count = ((_tcslen(szRezume1) + _tcslen(szRezume2) + _tcslen(szRezume3)) / 3);
	wsprintf(szTitleSecond, _T("Среднее число символов: %i"), count);*/

	// этот код компилируется для Юникода, но среднее число будет вещественным

	float count = ((_tcslen(szRezume1) + _tcslen(szRezume2) + _tcslen(szRezume3)) / 3.0);
	swprintf(szTitleSecond, 80, _T("Среднее число символов: %.2f"), count);

	MessageBox(NULL, szRezume3, szTitleSecond, MB_OK | MB_ICONINFORMATION);

	return 0;
}