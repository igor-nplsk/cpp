//�������� ����������, ����������� ������� �� ����� ������� ������ � ������� ������������������ ���� ���������
//(���������� ���� ��������� � �� ����� ���).�� ��������� ���������� ���� ��������� ������ ������������
//������� ����� �������� �� ��������(����� ����� �������� � ������ �������� �� ���������� ���� ���������).

#include<windows.h>
#include<tchar.h>

INT WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR lpszCmdLine, int nCmdShow)
{
	TCHAR szTitleFirst[] = _T("������");
	TCHAR szRezume1[] = _T("� �������� ������� �����");
	TCHAR szRezume2[] = _T("� �������� ������� ���������������� ��������");
	TCHAR szRezume3[] = _T("������ � ����� � ������������ ��������");
	MessageBox(NULL, szRezume1, szTitleFirst, MB_OK | MB_ICONINFORMATION);
	MessageBox(NULL, szRezume2, szTitleFirst, MB_OK | MB_ICONINFORMATION);
	TCHAR szTitleSecond[80];

	// ���� ��� ������������� ������������, �� ������� ����� ����� �����

	/*int count = ((_tcslen(szRezume1) + _tcslen(szRezume2) + _tcslen(szRezume3)) / 3);
	wsprintf(szTitleSecond, _T("������� ����� ��������: %i"), count);*/

	// ���� ��� ������������� ��� �������, �� ������� ����� ����� ������������

	float count = ((_tcslen(szRezume1) + _tcslen(szRezume2) + _tcslen(szRezume3)) / 3.0);
	swprintf(szTitleSecond, 80, _T("������� ����� ��������: %.2f"), count);

	MessageBox(NULL, szRezume3, szTitleSecond, MB_OK | MB_ICONINFORMATION);

	return 0;
}