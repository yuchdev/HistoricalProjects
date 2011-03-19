/** @brief 
����� 14, ���������� � �����������
����� 7 �������
��������� ����������
����������� ����������. ���������� ���������. ������������ � �����������.
����������� ����������
*/

/*
�������:
1. ���������� �� ��������� �����
2. ���������� ���������� �
3. ������ - ������ ���. 429-434 �� ��������������
4. ��� ��������� SEH
5. ���������� ������� �� 0
*/

/*
�������:
1. � ��������� ������� ���� ������������ ������������?
2. set_new_handler() - �����������!
*/

//exception 
// <- bad_alloc					new
// <- bad_cast					dynamic_cast
// <- bad_exception				������������ ����������
// <- bad_typeid				typeid
// <- bad_ios_base::failure		ios_base::clear()
// <- logic_error				���������� ������
//		<- domain_error 
//		<- invalid_argument		bitset()
//		<- length_error		
//		<- out_of_range			at(), bitset<>::operator[]
// <- runtime_error				������ ������� ����������
//		<- range_error 
//		<- overflow_error		bitset::to_ulong()
//		<- underflow_error



/*
������:
1. ����������� ������������ � main(), � �.�. catch(...)
2. �� ����������� ������������, ����� ���������� ��������� ����������� �����������.
3. ����������� ��������� "��������� �������� ���� �������������"
4. ����������� ���������� ��� �������� �� ������ � ������������
5. �� ����������� ���������� � ������������
6. � ������� ������� ���������� �� ������ ������ ����������.
7. ������������ ������������ ������� ������� � ������������ � ������ ����������.
8. ����������� ������������� ����������.
7. ���������� �� ������ ���� ���������� ���������� ��������� ��� �������� ���������� ����������.
8. �������������� ��������� ��������� ������ �� ������ ������� ��������������.
9. ����������� ������ �����������.
10.������������ �� ����� ���������� ������ ��������� explicit.
11.auto_ptr ��������� ��������� �������� (��� �������������� �����������)
12.�������� SEH ����������� � ��������� Win � �� �������� ����������� ��� ��������� �����.
13.unexpected() ���������� ��� ��������� ������������ ����������. ����� ��������� �� set_unexpected()
14.������ �������� unexpected() �������� ����������� catch(...) � main() ����� ������ bad_exception �� unexpected()
15.terminate() ���������� ��� ������ ���������������� ����������. 
16.���������� �������� abort() 
   ����� ��������� ����� �����, ��������, ������� exit(0) - �� ���� �� ������� �����������.
17.�������������� ����������� - ������������� ��� ���������� ���� � ������ ������������� ( � �������� �� ����� )
18.�������������� ����� ������������� ��� ���������� � ����.
19.���� ���� ��������� ����� ������ - ��������� ������ �� terminate()
20.����������� ������������ ������������. ���������� ��, ������� ������ STL � ������� ������ ������ ������������.
21.����� ������ �������������� ���������� ��� ���������� bad_alloc.
22.������ ������������ � �������� ��������� ���������� ����������� ��������� auto_ptr,
   ������ ��� �������� ����������� auto_ptr �������� �������� ���������
23.catch(...) ������������ ��� SE ����������
24.C������ ������������� SE � �++ ���������� ��������� _set_se_translator()
25.���� ������, �� ������� �������������� ���������� ������������, ������������ ����� ��������������
   ���������� ����� ���������� �����. �� ��� ����� �� ������.
*/
