#pragma once

// ��������������� �������� SEH
// �� ����������� � ��������� Win
// � �� �������� ����������� ��� ��������� �����

// ����������������� ��������� ���������� �� ����� ���� ������������ ����� ����� ��������
// ������������ ������� Windows ������� �������� ����������, ���������� �� ����� ������

class sehhandler
{
public:
	int filter( unsigned code, struct _EXCEPTION_POINTERS* ep );
	void test_seh();
};


//MS ���������� ��������� ��������� � ����� � ��� �� �������.
//��������, excpt.h ����� ��������� ���������� � ����������� :
//unsigned long __cdecl _exception_code(void);
//#define GetExceptionCode _exception_code 
//#define exception_code _exception_code 
// ��������, ��� ������� ��� ��������� ������ ���������� �����������


/*
SEH������ AV ��������, ��������, ������������� ����������� ���������, ��� ����� ����. 
��� ������ ����������, ������� ����� ����� ������ � ����������/�������� ����. 
������ ��� �����-�� ���������� ����� ���� ����� ���������� ���������� ������, ����� ������ ��������������.

EXCEPTION_STACK_OVERFLOW ����� ������ ������ ������, ��� ������� �������� �������������� ��������� (_resetstkoflw)

�� ��������, ������� ������������� SE � �++ ���������� ��������� _set_se_translator()
��� catch(...) ������������ ��� SE ����������.
*/