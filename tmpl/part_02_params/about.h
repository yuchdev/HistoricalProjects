/*
����� 8 ����������
������� �����������. 
����� ��������: �������, ��������� ������, ����������� �����
����������� �������. ���������� ��������. ��������� � ��������� �������.
��������� ��������: �������, ���������, ���������
*/

/*
�������:
1.SFINAE, ������ ���.131
*/

/*
������:
I  ��������� ��������
1. ��������� �������� ������� �������� 
   - ���� <int, int>
   - ������ ������ (type_t a; X<a>)
   - �� ���������
   - ����� ���������� (������� ����������� ���������� �������, <>)
2. ���������� ��������� �������� ������� ���������� �������� ����� ������.
3. ��� ���������� ��������� ������� �� ����� ����� ���������� ���������� ���� ����� 
   ������ ����������� ���������� (���������������).
4. ����������� ����� �� ����� ����:
   - ��������� ������ � ������������ (���������� � �������� �������)
   - ������������� ������ � ������������ (���������������� ����� typedef)
5. ������ ���������� �������� ������������ ���� ����� ���� ��� ������� ��������� �� ����� ����������

II ������� � ������.
1. ���������� ������������� ������� ����� ���� ������������ ����������� ������� 
   (�.�. ����� ��� � ������ ����� �� �����)
2. ���������� ������������� ������� �.�. ������������.
3. ���������� ������������� ������� �� ����� ���� ������������.
4. ����� ��������� ������������� ���������� ��������� �������.
5. ������������� ������ ������ ���� ����� � ����� ����������, � ������� �� ������
6. �������� ����������� �������������� ������� � �������� ���������� �������
7. ����� - � ��������� ������ ������ ���������� ������������� �������,
   ����� ��� ������� ��������� ODR

III ��������� ���������
1. ��������� �������� ����� ������������ �����:
   - ������������� ���, � �.�. enum
   - ��������� � ������� ����������� ()
   - ������ � ������� �����������.
2. �� ����� ���� static � mutable, ��������� const � volatile ������������. ������ �������� rvalue.
3. � ��������� ����������-���������� ����� ������������ �������� ����� typename,
   ���� � ��������� ������������ ���

IV SFINAE

V ��������� ��������� �������
1. ��������� �������� ������������ �������� ������ class
2. ��� ���������� ��������� ������� �� ����� ���� ������������ � �������
3. ���� ��� ���������� ��������� ������� ����� �� ������������, ��� ����� ��������
4. ��������� �������� �������, ������� ��������� �� ���������, ������ ��������� �� � ������ ����������
5. �������� ���������� ��������� ������� � ����� ������� ������������ ������  

VI �������-����� � ����� ��������
1. ������� ����� �������� ������� � ��������� ������, ������� � ��������� ������, 
   ����������� ����������� ������, ����������� �����.
2. � ������� �� �������, ��� �������� �� ����������� ���������� ���� � ������� ���������.
3. ������� �� ����� ����� ���������� �� ������ extern "C", �� ����� ����� 
   ������������� ���������� �� ������ extern "X".
4. ������� ����� ������� ����������, ����� ����������� ��� static
*/