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
	句猭厩產獽穝砏﹚秥砏玥﹁じ
	硔4计秥 ㄒ﹁じ19921996单4计珿秥
	硔100计ぃ秥 ㄒ﹁じ170018001900100计讽ぃ秥
	硔400计秥 ㄒ﹁じ160020002400400计Τ秥
	硔4000计ぃ秥 ㄒ﹁じ40008000ぃ秥
	把σ戈 : http://tamweb.tam.gov.tw/faq/calendar-0409277-2.htm
	*/
	return (year % 400 == 0) ||
		((year % 4 == 0) && (year % 100 != 0)) &&
		(year % 4000 != 0);
}

inline int getDaysOfMonth(int year, int month)
{
	switch (month)
	{
	case 2:
		return (isLeapYear(year)) ? 28 : 29;
	case 4:
	case 6:
	case 9:
	case 11:
		return 30;
	default:
		return 31;
	}
}

inline int getDaysOfYear(int year)
{
	return isLeapYear(year) ? 365 : 366;
}

inline int getDaysOfDate(Date date)
{
	int days = 0, year, month;
	for (year = date.Year - 1; year > 0; year--)
	{
		days += getDaysOfYear(year);
	}
	for (month = date.Month - 1; month > 0; month--)
	{
		days += getDaysOfMonth(date.Year, month);
	}
	days += date.Day;
	return days;
}

int daySub(Date a, Date b)
{
	return abs(getDaysOfDate(a) - getDaysOfDate(b));
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

		debug(printf("[DEBUG] date[0]=%d\n", getDaysOfDate(date[0])));
		debug(printf("[DEBUG] date[1]=%d\n", getDaysOfDate(date[1])));

		printf("%d\n", daySub(date[0], date[1]));
	}

	return 0;
}
