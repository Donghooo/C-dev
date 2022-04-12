#include <iostream>
using namespace std;
class Employee
{
	string m_name, m_position;
	int m_position_level;
	int m_years;
	int m_allowance;
	int m_basic_salary[6], m_gross_salary;
public:
	Employee();
	Employee(string name, string position, int year);
	void Set_Name(string name);
	bool Set_Position(string position);
	void Set_Year(int Year);
	string Get_Name();
	string Get_Position();
	int Get_Year();
	int Get_Salary();
	int Compute_Salary();
	void Print_Result();
};
Employee::Employee()
{
	m_allowance = 100000;
	int salary = 2000000;
	for (int i = 0; i < 6; i++)
	{
		m_basic_salary[i] = salary;
		salary += 500000;
	}
}
Employee::Employee(string name, string position, int year)
{
	m_name = name;
	m_position = position;
	m_years = year;
}
bool Employee::Set_Position(string position)
{
	if (position == "사원") m_position_level = 0;
	else if (position == "대리") m_position_level = 1;
	else if (position == "과장") m_position_level = 2;
	else if (position == "차장") m_position_level = 3;
	else if (position == "부장") m_position_level = 4;
	else if (position == "이사") m_position_level = 5;
	else m_position_level = -1;
	if (m_position_level > 0)
		return true;
	else return false;
}
void Employee::Set_Name(string name)
{
	m_name = name;
}
void Employee::Set_Year(int year)
{
	m_years = year;
}
string Employee::Get_Name()
{
	return m_name;
}
string Employee::Get_Position()
{
	return m_position;
}
int Employee::Get_Year()
{
	return m_years;
}
int Employee::Get_Salary()
{
	return m_gross_salary;
}
int Employee::Compute_Salary()
{
	if (5 <= m_years < 10)			m_allowance *= 5;
	else if (10 <= m_years < 20)	m_allowance *= 10;
	else if (20 <= m_years < 30)	m_allowance *= 20;
	else if (30 <= m_years)			m_allowance *= 10;
	else m_allowance;
	m_gross_salary = m_basic_salary[m_position_level] + 50000 * m_years + m_allowance;
	return m_gross_salary;
}
void Employee::Print_Result()
{
	cout << m_name << " " << Get_Position() << "의 총 근무 년수는" << m_years << "년 입니다." << endl;
	cout << m_name << " " << m_position << "의 봉급은 " << Compute_Salary() << "원 입니다." << endl;
}


int main()
{
	Employee s1, s2, s3;
	s1.Set_Name("홍길동");
	s1.Set_Position("과장");
	s1.Set_Year(17);
	s1.Print_Result();

	return 0;
}