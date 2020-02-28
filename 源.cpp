/*输入今天的日期（年月日），计算明天的日期。要求进行输入日期合法性验证。*/
#include<iostream>
using namespace std;
class Time
{
public:
	void set_time();
	void show_time();
private:
	bool is_time(int, int, int);
	void add_year();
	void add_month();
	void add_day();
	int year;
	int month;
	int day;
};
int main()
{
	Time t1;
	t1.set_time();
	t1.show_time();
	return 0;
}
void Time::set_time()
{
	char c1, c2;
	cout << "请输入时间（格式 year.month.day)：";
	while (1)
	{
		cin >> year>> c1 >> month >> c2 >> day;
		if (c1 != '.' || c2 != '.')
			cout << "格式不正确，请重新输入" << endl;
		else if (!is_time(year, month, day))
			cout << "时间非法，请重新输入：" << endl;
		else
			break;
	}
}
void Time::show_time()
{
	add_day();
	cout << year << "." << month<< "." << day<<endl;
}
bool Time::is_time(int y, int m, int d)
{
	if (y<0||m<0||m>12||d<0)
	{
		return false;
	}
	else if(m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
	{
		if (d > 31)
			return false;
	}
	else if(m==2)
	{
		if (y % 4 == 0 && y % 100 != 0||y % 400 == 0)
		{
			if (d > 29)
			{
				return false;
			}
		}
		else if (d > 28)
			return false;
	}
	else if (m == 4 || m == 6 || m == 7 || m == 9 || m == 10 || m == 11)
	{
		if (d > 30)
		{
			return false;
		}
	}
	return true;
}
void Time::add_year()
{
	++year;
}
void Time::add_month()
{
	++month;
	if (month > 12)
	{
		month = 1;
		add_year();
	}
}
void Time::add_day()
{
	++day;
	int m;
	int y;
	y = year;
	m = month;
	if (m== 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
	{
		if (day > 31)
			day = 1;
			add_month();
	}
	if (m == 4 || m == 6 || m == 7 || m == 9 || m == 10 || m == 11)
	{
		if (day > 30)
			day = 1;
			add_month();
	}
	else if (m ==2)
	{
		if (y % 4 == 0 && y % 100 != 0 && y % 400 == 0)
		{
			if (day > 29)
			{
				day = 1;
				add_month();
			}
		}
		else if (day > 28)
		{
			day = 1;
			add_month();
		}
	}
}