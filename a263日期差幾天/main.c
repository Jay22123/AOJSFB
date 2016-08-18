#ifdef _DEBUG
#	define debug(function) function
#else
#	define debug(function)
#endif

#include <stdio.h>
#include <stdbool.h>
#include <math.h>

typedef struct _Date
{
	int Year, Month, Day;
}Date;

bool isLeapYear(int year)
{
	/*
	��k�Ǯa�K���s�W�w�|�~���W�h���G�褸�~��
	�{4�����ƶ|�A �Ҧp�G�褸1992�B1996�~���A��4�����ơA�G���|�~�C
	�{100�����Ƥ��|�A �Ҧp�G�褸1700�B1800�B1900�~�A��100�����ơA��~���|�~�C
	�{400�����ƶ|�A �Ҧp�G�褸1600�B2000�B2400�~�A��400�����ơA���|�~
	�{4000�����Ƥ��|�A �Ҧp�G�褸4000�B8000�~�A���|�~�C
	�ѦҸ�� : http://tamweb.tam.gov.tw/faq/calendar-0409277-2.htm
	*/
	return ((year % 4 == 0) && (year % 100 != 0)) ||
		((year % 400 == 0) && (year % 4000 != 0));
}

int getDaysOfMonth(int year, int month)
{
	switch (month)
	{
	case 2:
		return (!isLeapYear(year)) ? 28 : 29;
	case 4:
	case 6:
	case 9:
	case 11:
		return 30;
	default:
		return 31;
	}
}

int getDaysOfYear(int year)
{
	return !isLeapYear(year) ? 365 : 366;
}

int getDayInYear(Date date)
{
	int month, days = 0;
	for (month = 1; month < date.Month; month++)
	{
		days += getDaysOfMonth(date.Year, month);
	}
	days += date.Day;

	return days;
}

int getDaysOfDate(Date date)
{
	int year, days = 0;
	for (year = 1; year < date.Year; year++)
	{
		days += getDaysOfYear(year);
	}
	days += getDayInYear(date);
	return days;
}

void swap(Date *a, Date *b)
{
	Date *tmp = a;
	b = a;
	a = tmp;
}

void MaxMin(Date *Max, Date *Min)
{
	if (Max->Year < Min->Year)
		swap(Max, Min);
	else if (Max->Month < Min->Month)
		swap(Max, Min);
	else if (Max->Day < Min->Day)
		swap(Max, Min);
}

int daySub(Date a, Date b)
{
	MaxMin(&a, &b);
	Date diff;
	diff.Year = a.Year - b.Year;
	diff.Month = a.Month - b.Month;
	diff.Day = a.Day - b.Day;

	int days = 0, year;
	days += getDaysOfYear(b.Year) - getDayInYear(b);
	int yearDays = 0;
	for (year = b.Year + 1; year < a.Year; year++)
	{
		days += getDaysOfYear(year);
		yearDays += getDaysOfYear(year);
	}
	days += getDayInYear(a);

	return abs(getDaysOfDate(a)- getDaysOfDate(b));
}


int main(int argc, char *argv[])
{
	Date date[2];

	while (scanf("%d", &(date[0].Year)) != EOF)
	{
		scanf("%d %d", &(date[0].Month), &(date[0].Day));
		debug(printf("[DEBUG] %04d %02d %02d\n",
			date[0].Year, date[0].Month, date[0].Day));

		scanf("%d %d %d", &(date[1].Year), &(date[1].Month), &(date[1].Day));
		debug(printf("[DEBUG] %04d %02d %02d\n",
			date[1].Year, date[1].Month, date[1].Day));

		printf("%d\n", daySub(date[0], date[1]));
	}

	return 0;
}
