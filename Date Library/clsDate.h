#pragma once
#pragma warning(disable: 4996)

#include"clsString.h"
#include<iostream>
#include<string>
#include<ctime>

class clsDate
{

private:

	short _Day;
	short _Month;
	short _Year;

public:


	clsDate()
	{

		time_t now = time(0);
		tm* ltm = localtime(&now);

		_Day = ltm->tm_mday;
		_Month = 1 + ltm->tm_mon;
		_Year = 1900 + ltm->tm_year;
	}

	clsDate(const string& Date)
	{

		vector <string> vDate;
		vDate = clsString::Split(Date, "/");

		_Day = stoi(vDate.at(0));
		_Month = stoi(vDate.at(1));
		_Year = stoi(vDate.at(2));
	}

	clsDate(const short& Day, const short& Month, const short& Year)
	{
		_Day = Day;
		_Month = Month;
		_Year = Year;
	}

	clsDate(const short& DaysInYear, const short& Year)
	{
		_Year = Year;

		int RemainingDays = DaysInYear;
		int CurrentMonth = 1;

		_Month = DaysInMonth(Year, CurrentMonth);

		while (true)
		{
			if (RemainingDays > _Month)
			{
				RemainingDays -= _Month;
				CurrentMonth++;
				_Month = DaysInMonth(Year, CurrentMonth);
			}
			else
			{
				_Month = CurrentMonth;
				_Day = RemainingDays;
				break;
			}
		}
	}

	static short DaysInYear(const short& year)
	{
		return (isLeapYear(year)) ? 366 : 365;
	}

	short DaysInYear()
	{
		return DaysInYear(_Year);
	}

	static short HoursInYear(const short& year)
	{
		return DaysInYear(year) * 24;
	}

	short HoursInYear()
	{
		return HoursInYear(_Year);
	}

	static short MinutesInYear(const short& year)
	{
		return HoursInYear(year) * 60;
	}

	short MinutesInYear()
	{
		return MinutesInYear(_Year);
	}

	static short SecondsInYear(const short& year)
	{
		return MinutesInYear(year) * 60;
	}

	short SecondsInYear()
	{
		return SecondsInYear(_Year);
	}

	static short HoursInMonth(const short& year, const short& month)
	{
		return DaysInMonth(year, month) * 24;
	}

	short HoursInMonth()
	{
		return HoursInMonth(_Year, _Month);
	}

	static short MinutesInMonth(const short& year, const short& month)
	{
		return HoursInMonth(year, month) * 60;
	}

	short MinutesInMonth()
	{
		return MinutesInMonth(_Year, _Month);
	}

	static short SecondsInMonth(const short& year, const short& month)
	{
		return MinutesInMonth(year, month) * 60;
	}

	short SecondsInMonth()
	{
		return SecondsInMonth(_Year, _Month);
	}

	static short DayOrderInWeek(const short& Year, const short& Month, const short& Day)
	{
		int a = (14 - Month) / 12;
		int y = Year - a;
		int m = Month + 12 * a - 2;

		return (Day + y + (y / 4) - (y / 100) + (y / 400) + (31 * m) / 12) % 7;
	}

	short DayOrderInWeek()
	{
		return DayOrderInWeek(_Year, _Month, _Day);
	}

	static string DayName(const short& DayOrder)
	{

		string arrDayNames[] = { "Sunday" ,"Monday" ,"Tuesday" ,"Wednesday" ,"Thursday" ,"Friday" ,"Saturday" };
		return arrDayNames[DayOrder];
	}

	string DayName()
	{
		return DayName(DayOrderInWeek());
	}

	static short DaysInMonth(const short& year, const int& month)
	{
		if (month < 1 || month>12) return 0;

		if (month == 2)
		{
			return isLeapYear(year) ? 29 : 28;
		}

		short arr31Days[7] = { 1,3,5,7,8,10,12 };

		for (short i = 0; i < 7; i++)
		{
			if (arr31Days[i] == month)
			{
				return 31;
			}
		}
		return 30;
	}

	static string DayShortName(const short& DayOfWeekOrder)
	{

		string arrDayNames[] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };
		return arrDayNames[DayOfWeekOrder];
	}

	string DayShortName()
	{
		return DayShortName(DayOrderInWeek());
	}

	static string MonthShortName(const short& MonthNumber)
	{

		string Months[12] = {
			"Jan", "Feb", "Mar",
			"Apr", "May", "Jun",
			"Jul", "Aug", "Sep",
			"Oct", "Nov", "Dec"
		};
		return (Months[MonthNumber - 1]);
	}

	string MonthShortName()
	{
		return MonthShortName(_Month);
	}

	static void PrintMonthCalendar(const short& Year, const short& Month)
	{

		int NumberOfDays;
		int current = DayOrderInWeek(Year, Month, 1);

		NumberOfDays = DaysInMonth(Year, Month);

		printf("\n  ---------------%s---------------\n\n", MonthShortName(Month).c_str());
		printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

		int i;

		for (i = 0; i < current; i++)
			printf("     ");

		for (int j = 1; j <= NumberOfDays; j++)
		{
			printf("  %2d ", j);
			if (++i == 7)
			{
				i = 0;
				printf("\n");
			}
		}

		printf("\n  ---------------------------------\n");
	}

	void PrintMonthCalendar()
	{
		PrintMonthCalendar(_Year, _Month);
	}

	static void PrintYearCalendar(const short& Year)
	{

		cout << "  ===============================\n\n";
		cout << "          Calendar _ " << Year << "\n\n";
		cout << "  ===============================\n\n";

		for (short Month = 1; Month <= 12; Month++)
		{
			PrintMonthCalendar(Year, Month);
		}
	}

	void PrintYearCalendar()
	{
		PrintYearCalendar(_Year);
	}

	static short DaysFromBeginningOfYear(const short& Year, const short& Month, const short& Day)
	{

		int TotalDays = 0;

		for (int i = 1; i <= Month - 1; i++)
		{
			TotalDays += DaysInMonth(Year, i);
		}
		TotalDays += Day;

		return TotalDays;
	}

	short DaysFromBeginningOfYear()
	{
		return DaysFromBeginningOfYear(_Year, _Month, _Day);
	}

	static clsDate ExtractDateFromDaysInYear(const short& Year, const short& DaysInYear)
	{

		clsDate Date;

		Date.SetYear(Year);

		short RemainingDays = DaysInYear;
		short CurrentMonth = 1;

		Date.SetMonth(DaysInMonth(Year, CurrentMonth));

		while (true)
		{
			if (RemainingDays > Date.Month())
			{
				RemainingDays -= Date.Month();
				CurrentMonth++;
				Date.SetMonth(DaysInMonth(Year, CurrentMonth));
			}

			else
			{
				Date.SetMonth(CurrentMonth);
				Date.SetDay(RemainingDays);

				break;
			}
		}
		return Date;
	}

	short DaysInMonth()
	{
		return DaysInMonth(_Year, _Month);
	}

	static bool isLeapYear(int year)
	{
		return (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0));
	}

	bool isLeapYear()
	{
		return isLeapYear(_Year);
	}

	short Day()
	{
		return _Day;
	}

	short Month()
	{
		return _Month;
	}

	short Year()
	{
		return _Year;
	}

	void SetDay(const short& Day)
	{
		_Day = Day;
	}

	void SetMonth(const short& Month)
	{
		_Month = Month;
	}

	void SetYear(const short& Year)
	{
		_Year = Year;
	}

	void Print()
	{
		cout << _Day << "/" << _Month << "/" << _Year << endl;
	}

};