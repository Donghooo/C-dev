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
	if (position == "���")		{ m_position = "���"; m_position_level = 0; }
	else if (position == "�븮")	{ m_position = "�븮"; m_position_level = 1; }
	else if (position == "����")	{ m_position = "����"; m_position_level = 2; }
	else if (position == "����")	{ m_position = "����"; m_position_level = 3; }
	else if (position == "����")	{ m_position = "����"; m_position_level = 4; }
	else if (position == "�̻�")	{ m_position = "�̻�"; m_position_level = 5; }
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
	cout << m_name << " " << m_position << "�� �� �ٹ� ����� " << m_years << "�� �Դϴ�." << endl;
	cout << m_name << " " << m_position << "�� ������ " << m_gross_salary << "�� �Դϴ�." << endl;
	cout << endl;
}


int main()
{
 /*	1. EmployeeŬ������ 1���� ��ü�� �������� �����Ѵ�.
	2. EmployeeŬ������ ������ ������ �����Ѵ�. 
	3. ������ ������ ������ ������ 3���� �迭�� �ּҸ� ġȯ�Ѵ�.
	4. ������ ������ for���� �̿��Ͽ� �迭 ��ü�� �� �޿��� ����ϰ� ����Ѵ�.
	5. ������ ������ ����� �� for���� �ݺ�����( ��) �ݺ����� i )�� ����ϸ� �� �ȴ�. ������ ���� ��ü���� ���ϸ鼭 �迭�� �����ϵ��� �Ѵ�.
	   (Compute_Salary(), Print_Result() �Լ� ���)
	6. cin ��ü�� ����Ͽ� �������� �̸�, ����, �� �ٹ������� �Է¹޴´�. �Է¹��� ���� ������ 
	   �Լ��� ����Ͽ� �������� ������ ��ü�� ���� �����Ѵ�. ������ ������ ���� ������ �Լ��� 
	   ����Ͽ� �ݵ�� ���� üũ�� �Ѵ�. 
	7. �������� ������ ��ü�� �� �޿��� ����ϰ� ����Ѵ�. ����� �� Print_Result()�Լ��� ������� ����
	   ������ �Լ�(Get �迭 �Լ�)�� ����ؼ� ����ؾ� �Ѵ�. ��� ������ ��� ��� ���� �����Ѵ�.*/

	Employee e[3];
	e[0].Employee::Employee("ȫ�浿", "����", 17);
	e[1].Employee::Employee("����", "����", 23);
	e[2].Employee::Employee("�Ӳ���", "�̻�", 34);
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
	cout << "�������� �̸��� �Է��ϼ���. : ";
	cin >> name;
	
	e1->Set_Name(name);
	cout << "�������� ������ �Է��ϼ���. : ";
	cin >> pos;
	
	while (e1->Set_Position(pos) == false)
	{
		cout << "** ���� �߻�. ���, �븮, ����, ����, ����, �̻� �߿��� �Է��ϼ��� **" << endl << endl;
		cout << "�������� ������ �Է��ϼ��� : ";
		cin >> pos;
	}
	e1->Set_Position(pos);
	
	cout << "�������� �ٹ� ����� �Է��ϼ���. : ";
	cin >> year; cout << endl;
	e1->Set_Year(year);

	cout << e1->Get_Name() << " " << e1->Get_Position() << "�� �� �ٹ� ����� " << e1->Get_Year() << "�� �Դϴ�." << endl;
	cout << e1->Get_Name() << " " << e1->Get_Position() << "�� ������ " << e1->Compute_Salary() << "�� �Դϴ�." << endl;
	cout << endl;

	delete e1;
	system("PAUSE");
	return 0;
}