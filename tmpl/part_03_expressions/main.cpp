#include "simple_array.h"
#include "efficient_array.h"


// ������������� ����� ������������� ������ ��������� ����������
// ��� ������� ������������ � ���������� "� ���", � ���������� ����
// ��������� ��������
void show_unefficient(){

	SArray<double> x(10);
	SArray<double> y(10);
	x[0] = 1.0; x[3] = 2.0; x[6] = 3.0;
	y[0] = 2.0; y[3] = 4.0; y[6] = 2.0;

	print_debug("start expression");
	x = 1.2*x + x*y;
	print_debug("end expression");
	// 3 ��������� ������� � 4 �������� �����������
	// �� �������� ����������� 1000 ��� ����� ��������!
}

// ���������� ��������� ����� ���������� �� ���� ����������
void show_efficient(){

	Array<double> x(10);
	Array<double> y(10);
	x[0] = 1.0; x[3] = 2.0; x[6] = 3.0;
	y[0] = 2.0; y[3] = 4.0; y[6] = 2.0;

	print_debug("start expression");
	x = 1.2*x + x*y;
	print_debug("end expression");
	// ��� �������� �������� � ������������ �������� ������������
	// ��������� ����������� "�� �����"
}

int main(){


	show_unefficient();
	show_efficient();

	return 0;
}