#include "debug_error.h"
#include "tracer.h"

#include <iostream>
#include <algorithm>
using std::cout;
using std::endl;
using std::sort;
using std::stable_sort;

// ������� ��� ������������ ������������� �������������
// �� ����������� ��������� ����������
void test_trace(){
	tracer input[] = {7,3,9,2,7,2,9,1,7,3,8,2,6,5,0,1,7,3,9,2,7,2,9,1,7,3,8,2,6,5,0,1
	,7,3,9,2,7,2,9,1,7,3,8,2,6,5,0,1,7,3,9,2,7,2,9,1,7,3,8,2,6,5,0,1,7,3,9,2,7,2,9,1,7,3,8,2,6,5,0,1
	,7,3,9,2,7,2,9,1,7,3,8,2,6,5,0,1,7,3,9,2,7,2,9,1,7,3,8,2,6,5,0,1,7,3,9,2,7,2,9,1,7,3,8,2,6,5,0,1
	,7,3,9,2,7,2,9,1,7,3,8,2,6,5,0,1,7,3,9,2,7,2,9,1,7,3,8,2,6,5,0,1,7,3,9,2,7,2,9,1,7,3,8,2,6,5,0,1};
	size_t sz = sizeof(input);
	cout << "--- Start sorting trace ---" << endl;
	sort<>(input, input + (sz/sizeof(tracer)) );
	//stable_sort<>(input, input + (sz/sizeof(tracer)) );
	cout << "--- End sorting trace ---" << endl;
}
// ���� �� ����� ����� ��������� � �������� ��������� - 
// ���������������� �������� �� ������������ ���������� �������

// ������������� ������ ������������� � ������� �����������
void show_trace(){
	test_trace();
	cout << "Total result:" << endl;
	cout << "Tracer creations: " << tracer::creations() << endl;
	cout << "Tracer copies: " << tracer::copies() << endl;
	cout << "Tracer assignments: " << tracer::assigmennts() << endl;
	cout << "Tracer comparasions: " << tracer::comparasions() << endl;
	cout << "Tracer max objects: " << tracer::max_objects() << endl;
}

int main(){
	show_long_error();
	show_trace();
	return 0;
}
