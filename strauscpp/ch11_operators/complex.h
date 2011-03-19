#pragma once
#include <vector>
#include <cmath>
// � ������ ����������� ������ ���������� ����������
// ���������� ���������� ����������� ��� ��� ������ � ����������� ������, 
// ��� � ��� �������������� ���������� � ����������� �����������: -> [] ()

/* ����� �����������
+	-	*	/	=
%	^	&|	~		
==	<	>	!=	<=	>=
+=	-=	*=	/=
%=	^=	&=	|=
<<	>>	>>=	<<=
!	&&	||	
++	--
->	->*	[]	() ,
new	new[]	delete	delete[]
operator {type}()
*/

/*������ �����������
::	.	.*	?:
*/

// ������ ������������ ��������� �� ���������, 
// �.�. ����� ������������ ����� ������� �������� �-��� �������

/** @brief 
����� complex_t ��������� ���������� ������������ �����
� ������������� �������� ���������� �������� � C++
*/
class complex_t
{
public:
	// ����������� �� ���������, �� �� ������ �����������
	complex_t(double r = 0., double i = 0.);

	// ����������� ��� �������� �������������� �� int
	complex_t(int r);

	// --- ��������������� ������� --- 
	inline double real();
	inline double imag();

	// --- ������������� ��������� --- 
	// ���������, ������� ����� ����������� �������
	// ������ ���������� ������ �� ����, �.�. �������� ���� ���������
	// ��� ����������� ������ � ������� a += b += c ...
	// � �������������� ���������� ����������� ������������� ��������
	complex_t& operator+=( const complex_t& a );
	complex_t& operator-=( const complex_t& a );
	complex_t& operator*=( const complex_t& a );
	complex_t& operator/=( const complex_t& a );

	// ��� ��������� �����������, �.�. �� �������� ��������� �������
	bool operator==( const complex_t& a ) const;
	bool operator!=( const complex_t& a ) const;

	// ��������� � ���������
	// ���������� - ���������� ������!
	complex_t& operator++();
	complex_t& operator--();
	// ����������� - ���������� �� ���� ��������, ��� ����
	// ��������� ��������� �������� int
	complex_t operator++(int);
	complex_t operator--(int);

	// ���������, ������� ����� �����������, �� � ������ ������ �� �����
	// operator=() - ���������� ���������������� �� ���������
	// ! �� �� ��� ������������ �����������
	// �������� ��������, ��� �������� ������������ ����������� 
	// �� ����� ������������ �� �������� - ��� �������� ��� � ����������� ��������

	// ���������, ������� ����������� ����������� ������� ������ - 
	// ��������� �������������� ���� - (!) �� ����� ������������� ��������,...
	operator int();
	operator double();
	// ... � ����� ��� ��������� ���������:
	// =	� ������ ������ �� ����� - ���������� ������ �� ����, �.�. ������������ ���������
	//		��� ���� ���������� �������� �� ��������������!
	// ->	��� ����� ���������� � ���������� ���������� ������� (���������)
	// []	��� �������� ��������� (!!! ������ ���� ����������� � ������������� - ������ ��. 4 ���. 101)
	// ()	� ���������, ���������� ��������� (substr) � ��� ����������� ������

	// ����� ��������������� � ��������, ���������� ��������� �������
	// �������� � ����������� while( cin >> x ){}
	// cin >> x ���������� istream& � ������������� � int

	// ���������, ������������� �������������� ���������
	// �.�. ��� ��������� ����� ��� complex_t&, �������� ���� int ��� double
	// ����� ���� ������ ������������� - ��� ���� ������� �������� � ��������������� ��������
	// ����� ����� �� ��������� �� ��������, � ������������ ��������� � �������� ����� ������
	
	// ����� ����� ��, ��� ���������� ������������� ������� �.�. ������������
	// �.�. �� ������ ��� ������������� ������, � ���� ����� ��������� � ������������
	friend complex_t operator+( const complex_t& a, const complex_t& b );
	friend complex_t operator-( const complex_t& a, const complex_t& b );
	friend complex_t operator*( const complex_t& a, const complex_t& b );
	friend complex_t operator/( const complex_t& a, const complex_t& b );

	// ������-������ ������������ �����
	friend double r_vector(const complex_t& c){
		return sqrt( (c.re*c.re) + (c.im*c.im) );
	}
	
	// �������� ��������� �������� ����� ���������� ��� �������, ��� � ��������.
	// ������� ��� ������ ��������, �.�. ��� ������������ ��������������� ��������
	// � �������� � ������, ����� ���� �������� ������ ��������, �������� �� this ( << >> )
	// �� ����� ����� ������� � namespace 
	// ! ��� ��������� ���������� ��� ������������ � ������ ����� ��-�������



private:
	double re, im;
};


// ���������� ������, ����������� �������� ����������� ���������� �� ��������
// (�������� ���� � ���� ������� �������������)
// ��������, ������ ��� ������������������ ������� � ����
// (��. ���������� � complex.cpp)
complex_t& get_cache();
complex_t& operator%( const complex_t& a, const complex_t& b );



/** @brief 
������ �� ��������. ���������� �������.
�������� ���������, ��������� 3 ���� ������ - �����������, ������������ � ��������������.
�������� �������� ������ �������� ����. ���������� ����� ������� �� ����������.
����������, ����� � ���� ���������� ������� ���� char, unsigned char.
�������� - � ��������� ������ � ������������ ������� ������� �� ������ ������!
*/

/** @brief 
������ �� ��������. POD/non-POD ����.
�� ��������� POD-����, ��� ������, 
- ������� ������ �������������� �����������
- �� ������� ����������� �������
- ���� � ������ ���� ������ ������, �� ��� �������� POD-������
- ���� ����� ��������� �� ������� ������, �� �������� �������� POD-�����
��� ����� ������� ������ ���������� ������

non-POD ������ - ��� ��� ��������� ������. ��� ��� ������� ���������� ������,
� ����� ���������� �����������
��� ������������� �������� ������ ����������� �� ����������.

*/

/** @brief 
����� complex_matrix ��������� ������������ ������� ��������� complex_t
� ������������ ������������� ��� ������������ ������ � ������� 
� ���������� ����������� � ������ ������ ��������
*/
class complex_matrix{

protected:
	/** @brief ��������� ������� ������� ������ ��� ���������� ������� */
	void clear();
public:
	// � �������������, ��� � �������� ������������� ���������
	// ���������� ���������� ���������,
	// ���������� ������������ � ������� explicit ����������� 
	// ������� �������������, �������� ����� �� ���� ���: 
	// complex_matrix c_cet = 5;
	/** @brief ������ ����������� ������� �������-������ */
	explicit complex_matrix(const size_t count_x);

	/** @brief ������ ����������� ���� ��������� ������ ������� */
	complex_matrix(const size_t count_x, const size_t count_y);

	/** @brief ����������� ����������� ��� ������� ������ ������ �����������
	��� ���������� "�������� �����������" - deep copy, � ���������� ���������� ����������� 
	������������ �� ���������  - �.�. "������������� �����������, shallow copy" */
	complex_matrix( const complex_matrix& c );

	/** @brief 
	�������� ������������ ����� ������ ���� "��������".
	����� ����, �� ������ ���������� ������ ������ ����� ������������ */
	complex_matrix& operator=( const complex_matrix& c );

	// ���������� ����� ���������� ������ ������������ - 
	// � ������� �������� swap (��. ��������� ���������� � cpp)

	// ����������� �� ���������� ����������.
	~complex_matrix() throw();

	// ��� ���������� �������������� ���������� ������������� ��� ������ - 
	// ������� � �����������. ����������� ����� ��� ����������� �������� �� ����
	// ������� ���������� ������ �� �������� � �����, ����� ��������� � ��������
	// ����� �������������� ����� �� ����� = (���� l-value)
	// ������������� �������� operator[] � ������ ������ �� ����� ������,
	// �.�. ������ �������������� ���������. �� �������� ��� �������.
	complex_t* operator[](unsigned index);
	complex_t* operator[](unsigned index) const;

	// � ���������� ����������� ������ ��� ���������� ����� ������������ �������� ()
	// ������ [], �.�. �������� [] ��������� �������� ������ ������ �������
	complex_t& operator()(unsigned index_x, unsigned index_y);
	complex_t& operator()(unsigned index_x, unsigned index_y) const;

	// ������ ����� ��������� � �������� ��� �������� ����� ������ - �� ����� ��������.
	// �������� ����� ����� ��������� ��������� ������� ������...
	friend double complex_t::real();
	friend double complex_t::imag();

	// ...��� ���� ����� (���� � ���� ������ ����� ��������� �������� ���������
	// , ���������� ��� ������������)
	friend class complex_t;

private:
	size_t _count_x;
	size_t _count_y;
	complex_t** _matrix;
};
