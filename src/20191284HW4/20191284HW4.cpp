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
	int salary = 2000000;
	for (int i = 0; i < 6; i++)
	{
		m_basic_salary[i] = salary;
		salary += 500000;
	}
	m_allowance = 100000;
}
Employee::Employee(string name, string position, int year)
{
	int salary = 2000000;
	for (int i = 0; i < 6; i++)
	{
		m_basic_salary[i] = salary;
		salary += 500000;
	}
	m_allowance = 100000;

	m_name = name;
	Set_Position(position);
	m_years = year;
}
bool Employee::Set_Position(string position)
{
	if (position == "사원")		{ m_position_level = 0; }
	else if (position == "대리")	{ m_position_level = 1; }
	else if (position == "과장")	{ m_position_level = 2; }
	else if (position == "차장")	{ m_position_level = 3; }
	else if (position == "부장")	{ m_position_level = 4; }
	else if (position == "이사")	{ m_position_level = 5; }
	else m_position_level = -1;
	if (m_position_level >= 0)
	{
		m_position = position;
		return true;
	}
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
	if (5 <= m_years && m_years< 10)		m_allowance *= 5;
	else if (10 <= m_years && m_years < 20)	m_allowance *= 10;
	else if (20 <= m_years && m_years < 30)	m_allowance *= 20;
	else if (30 <= m_years)					m_allowance *= 30;
	m_gross_salary = m_basic_salary[m_position_level] + 50000 * m_years + m_allowance;
	return m_gross_salary;
}
void Employee::Print_Result()
{
	cout << m_name << " " << m_position << "의 총 근무 년수는 " << m_years << "년 입니다." << endl;
	cout << m_name << " " << m_position << "의 봉급은 " << m_gross_salary << "원 입니다." << endl;
	cout << endl;
}


int main()
{
	Employee e[3];
	e[0] = Employee("홍길동", "과장", 17);
	e[1] = Employee("장길산", "부장", 23);
	e[2] = Employee("임꺽정", "이사", 34);
	Employee *employee = new Employee;
	Employee* e1;
	e1 = e;
	for (int i = 0; i < 3; i++)
	{
		e1->Compute_Salary();
		e1->Print_Result();
		e1++;
	}
	
	string name, pos; int year;
	cout << "종업원의 이름을 입력하세요. : ";
	cin >> name;
	employee->Set_Name(name);

	cout << "종업원의 직급을 입력하세요. : ";
	cin >> pos;
	while (employee->Set_Position(pos) == false)
	{
		cout << "** 에러 발생. 사원, 대리, 과장, 차장, 부장, 이사 중에서 입력하세요 **" << endl << endl;
		cout << "종업원의 직급을 입력하세요 : ";
		cin >> pos;
	}
	
	cout << "종업원의 근무 년수를 입력하세요. : ";
	cin >> year; cout << endl;
	employee->Set_Year(year);

	cout << employee->Get_Name() << " " << employee->Get_Position() << "의 총 근무 년수는 " << employee->Get_Year() << "년 입니다." << endl;
	cout << employee->Get_Name() << " " << employee->Get_Position() << "의 봉급은 " << employee->Compute_Salary() << "원 입니다." << endl;
	cout << endl;

	delete employee;
	system("PAUSE");
	return 0;
}