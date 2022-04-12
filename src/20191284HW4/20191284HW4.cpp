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
	if (Set_Position(position) == true)
		m_position = position;
	m_years = year;
}
bool Employee::Set_Position(string position)
{
	if (position == "사원")		{ m_position = "사원"; m_position_level = 0; }
	else if (position == "대리")	{ m_position = "대리"; m_position_level = 1; }
	else if (position == "과장")	{ m_position = "과장"; m_position_level = 2; }
	else if (position == "차장")	{ m_position = "차장"; m_position_level = 3; }
	else if (position == "부장")	{ m_position = "부장"; m_position_level = 4; }
	else if (position == "이사")	{ m_position = "이사"; m_position_level = 5; }
	else m_position_level = -1;
	if (m_position_level >= 0)
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
	if (5 <= m_years && m_years< 10)			
		m_allowance *= 5;
	else if (10 <= m_years && m_years < 20)
		m_allowance *= 10;
	else if (20 <= m_years && m_years < 30)
		m_allowance *= 20;
	else if (30 <= m_years)			
		m_allowance *= 30;
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
 /*	1. Employee클래스의 1명의 객체를 동적으로 선언한다.
	2. Employee클래스의 포인터 변수를 선언한다. 
	3. 위에서 선언한 포인터 변수에 3명의 배열의 주소를 치환한다.
	4. 포인터 변수와 for문을 이용하여 배열 객체의 총 급여를 계산하고 출력한다.
	5. 포인터 변수를 사용할 때 for문의 반복변수( 예) 반복변수 i )를 사용하면 안 된다. 포인터 변수 자체값이 변하면서 배열에 접근하도록 한다.
	   (Compute_Salary(), Print_Result() 함수 사용)
	6. cin 객체를 사용하여 종업원의 이름, 직급, 총 근무연수를 입력받는다. 입력받은 값을 접근자 
	   함수를 사용하여 동적으로 생성한 객체에 값을 세팅한다. 직급을 세팅할 때는 접근자 함수를 
	   사용하여 반드시 에러 체크를 한다. 
	7. 동적으로 생성한 객체의 총 급여를 계산하고 출력한다. 출력할 때 Print_Result()함수를 사용하지 말고
	   접근자 함수(Get 계열 함수)를 사용해서 출력해야 한다. 출력 형식은 출력 결과 예를 참조한다.*/

	Employee e[3];
	e[0].Employee::Employee("홍길동", "과장", 17);
	e[1].Employee::Employee("장길산", "부장", 23);
	e[2].Employee::Employee("임꺽정", "이사", 34);
	Employee* e1;															
	e1 = e;
	for (int i = 0; i < 3; i++)
	{
		e1->Compute_Salary();
		e1->Print_Result();
		e1++;
	}
	e1 = new Employee;
	string name, pos; int year;
	cout << "종업원의 이름을 입력하세요. : ";
	cin >> name;
	
	e1->Set_Name(name);
	cout << "종업원의 직급을 입력하세요. : ";
	cin >> pos;
	
	while (e1->Set_Position(pos) == false)
	{
		cout << "** 에러 발생. 사원, 대리, 과장, 차장, 부장, 이사 중에서 입력하세요 **" << endl << endl;
		cout << "종업원의 직급을 입력하세요 : ";
		cin >> pos;
	}
	e1->Set_Position(pos);
	
	cout << "종업원의 근무 년수를 입력하세요. : ";
	cin >> year; cout << endl;
	e1->Set_Year(year);

	cout << e1->Get_Name() << " " << e1->Get_Position() << "의 총 근무 년수는 " << e1->Get_Year() << "년 입니다." << endl;
	cout << e1->Get_Name() << " " << e1->Get_Position() << "의 봉급은 " << e1->Compute_Salary() << "원 입니다." << endl;
	cout << endl;

	delete e1;
	system("PAUSE");
	return 0;
}