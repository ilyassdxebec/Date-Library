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

	enum enDateComparison { Before = -1, Equal = 0, After = 1 };

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

	static double DaysInYear(const short& year)
	{
		return (isLeapYear(year)) ? 366 : 365;
	}

	static string DateToString(const clsDate &Date)
	{
		return to_string(Date._Day) + "/ " + to_string(Date._Month) + " / " + to_string(Date._Year) + "\n";
	}

	string DateToString()
	{
		return DateToString(*this);
	}

	static void SwapDates(clsDate &Date1 ,clsDate &Date2)
	{

		clsDate TempDate;

		TempDate = Date1;
		Date1 = Date2;
		Date2 = TempDate;
	}

	void SwapDates(clsDate &Date2)
	{
		SwapDates(*this ,Date2);
	}

	double DaysInYear()
	{
		return DaysInYear(_Year);
	}

	static double HoursInYear(const short& year)
	{
		return DaysInYear(year) * 24;
	}

	double HoursInYear()
	{
		return HoursInYear(_Year);
	}

	static double MinutesInYear(const short& year)
	{
		return HoursInYear(year) * 60;
	}

	double MinutesInYear()
	{
		return MinutesInYear(_Year);
	}

	static double SecondsInYear(const short& year)
	{
		return MinutesInYear(year) * 60;
	}

	double SecondsInYear()
	{
		return SecondsInYear(_Year);
	}

	static double HoursInMonth(const short& year, const short& month)
	{
		return DaysInMonth(year, month) * 24;
	}

	double HoursInMonth()
	{
		return HoursInMonth(_Year, _Month);
	}

	static double MinutesInMonth(const short& year, const short& month)
	{
		return HoursInMonth(year, month) * 60;
	}

	double MinutesInMonth()
	{
		return MinutesInMonth(_Year, _Month);
	}

	static double SecondsInMonth(const short& year, const short& month)
	{
		return MinutesInMonth(year, month) * 60;
	}

	double SecondsInMonth()
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

	static void AddDaysToDate(clsDate &Date, const int &DaysToAdd)
	{

		int RemainingDays = DaysToAdd + DaysFromBeginningOfYear(Date._Year, Date._Month, Date._Day);
		int MonthDays;

		Date._Month = 1;

		while (true)
		{
			MonthDays = DaysInMonth(Date._Year, Date._Month);

			if (RemainingDays > MonthDays)
			{
				RemainingDays -= MonthDays;
				Date._Month++;

				if (Date._Month > 12)
				{
					Date._Year++;
					Date._Month = 1;
				}
			}
			else
			{
				Date._Day = RemainingDays;
				break;
			}
		}
	}

	void AddDaysToDate(const int &DaysToAdd)
	{
		AddDaysToDate(*this, DaysToAdd);
	}

	static bool IsDate1BeforeDate2(const clsDate& Date1, const clsDate &Date2)
	{
		return (Date1._Year < Date2._Year) ? true : ((Date1._Year == Date2._Year) ? (Date1._Month < Date2._Month ? true : (Date1._Month == Date2._Month ? Date1._Day < Date2._Day : false)) : false);
	}

	bool IsBeforeDate2(const clsDate &Date2)
	{
		return IsDate1BeforeDate2(*this, Date2);
	}

	static bool IsDate1EqualDate2(const clsDate& Date1, const clsDate& Date2)
	{
		return (Date1._Year == Date2._Year) ? ((Date1._Month == Date2._Month) ? ((Date1._Day == Date2._Day) ? true : false) : false) : false;
	}

	bool IsEqualToDate2(const clsDate &Date2)
	{
		return IsDate1EqualDate2(*this, Date2);
	}

	static bool isLastDayInMonth(const clsDate &Date)
	{
		return DaysInMonth(Date._Year, Date._Month) == Date._Day;
	}

	bool isLastDayInMonth()
	{
		return isLastDayInMonth(*this);
	}

	static bool isLastMonthInYear(const clsDate &Date)
	{
		return Date._Month == 12;
	}

	bool isLastMonthInYear()
	{
		return isLastMonthInYear(*this);
	}

	static void IncreaseDateByOneDay(clsDate &Date)
	{

		if (isLastDayInMonth(Date))
		{
			Date._Day = 1;

			if (isLastMonthInYear(Date))
			{
				Date._Month = 1;
				Date._Year++;
			}
			else
			{
				Date._Month++;
			}
		}
		else
		{
			Date._Day++;
		}
	}

	void IncreaseDateByOneDay()
	{
		IncreaseDateByOneDay(*this);
	}

	static int DaysBetweenTwoDates(clsDate Date1, clsDate Date2)
	{

		if (!IsDate1BeforeDate2(Date1, Date2))
		{

			cout << "\nYou cannot do that since Date1 is not Before Date2!\n";
			return 0;

		}

		if (Date1._Year == Date2._Year)
		{
			return (DaysFromBeginningOfYear(Date2._Year, Date2._Month, Date2._Day) - DaysFromBeginningOfYear(Date1._Year, Date1._Month, Date1._Day));
		}

		int DaysBetween = 0;
		
		while (true)
		{

			DaysBetween += DaysInYear(Date2._Year);
			Date2._Year--;

			if (Date1._Year == Date2._Year)
			{
				return (DaysFromBeginningOfYear(Date2._Year, Date2._Month, Date2._Day) - DaysFromBeginningOfYear(Date1._Year, Date1._Month, Date1._Day)) + DaysBetween;
			}
		}
	}

	int DaysBetweenTwoDates(clsDate Date2)
	{
		return DaysBetweenTwoDates(*this, Date2);
	}

	static bool IsWeekEnd(const clsDate &Date)
	{

		short DayOrder = DayOrderInWeek(Date._Year, Date._Month, Date._Day);
		return (DayOrder == 6 || DayOrder == 5);
	}

	bool IsWeekEnd()
	{
		return IsWeekEnd(*this);
	}

	static bool IsEndOfWeek(const clsDate &Date)
	{
		return DayOrderInWeek(Date._Year, Date._Month, Date._Day) == 6;
	}

	bool IsEndOfWeek()
	{
		return IsEndOfWeek(*this);
	}

	static bool IsBusinessDay(const clsDate& Date)
	{
		return (!IsWeekEnd(Date));
	}

	bool IsBusinessDay()
	{
		return IsBusinessDay(*this);
	}

	static int DaysUntilEndOfWeek(const clsDate& Date)
	{
		return 6 - DayOrderInWeek(Date._Year, Date._Month, Date._Day);
	}

	int DaysUntilEndOfWeek()
	{
		return DaysUntilEndOfWeek(*this);
	}

	static int DaysUntilEndOfMonth(const clsDate& Date)
	{
		return DaysInMonth(Date._Year, Date._Month) - Date._Day;
	}

	int DaysUntilEndOfMonth()
	{
		return DaysUntilEndOfMonth(*this);
	}

	static int DaysUntilEndOfYear(const clsDate& Date)
	{
		return (DaysInYear(Date._Year) - DaysFromBeginningOfYear(Date._Year, Date._Month, Date._Day));
	}

	int DaysUntilEndOfYear()
	{
		return DaysUntilEndOfYear(*this);
	}

	static string ShortNameOfDay(const clsDate& Date)
	{

		string NameOfDay[] = { "Sun","Mon","Tue","Wed","Thu","Fri","Sat" };

		short OrderOfDay = DayOrderInWeek(Date._Year, Date._Month, Date._Day);

		return NameOfDay[OrderOfDay];
	}

	string ShortNameOfDay()
	{
		return ShortNameOfDay(*this);
	}

	static int CalculateVacationDays(clsDate VacationStarts, clsDate VacationEnds)
	{

		int VacationDays = 0;

		while (IsDate1BeforeDate2(VacationStarts, VacationEnds))
		{
			if (IsBusinessDay(VacationStarts))
				VacationDays++;

			IncreaseDateByOneDay(VacationStarts);
		}

		return VacationDays;
	}

	int CalculateVacationDays(clsDate VacationEnds)
	{
		return CalculateVacationDays(*this, VacationEnds);
	}


	static clsDate CalculateVacationReturnDate(clsDate Date, const int &VacationDays)
	{
		int WeekEnd = 0;

		while (IsWeekEnd(Date))
		{
			IncreaseDateByOneDay(Date);
		}

		for (int i = 0; i < VacationDays + WeekEnd; i++)
		{
			if (IsWeekEnd(Date))
				WeekEnd++;

			IncreaseDateByOneDay(Date);
		}

		while (IsWeekEnd(Date))
		{
			IncreaseDateByOneDay(Date);
		}

		return Date;
	}

	clsDate CalculateVacationReturnDate(const int &VacationDays)
	{
		return CalculateVacationReturnDate(*this, VacationDays);
	}

	static bool IsDate1AfterDate2(const clsDate& Date1, const clsDate& Date2)
	{
		return (!IsDate1BeforeDate2(Date1, Date2)) && (!IsDate1EqualDate2(Date1, Date2));
	}

	bool IsAfterDate2(const clsDate &Date2)
	{
		return IsDate1AfterDate2(*this, Date2);
	}

	static enDateComparison CompareTwoDates(const clsDate &Date1, const clsDate &Date2)
	{
		if (IsDate1BeforeDate2(Date1, Date2)) return Before;
		if (IsDate1EqualDate2(Date1, Date2)) return Equal;
		return After;
	}

	enDateComparison CompareToDate2(const clsDate &Date2)
	{
		return CompareTwoDates(*this, Date2);
	}

	static bool IsValid(const clsDate& Date)
	{
		if (Date._Year < 1)
			return false;

		if (Date._Month < 1 || Date._Month>12)
			return false;

		if (Date._Day<1 || Date._Day>DaysInMonth(Date._Year, Date._Month))
			return false;

		return true;
	}

	bool IsValid()
	{
		return IsValid(*this);
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

	static clsDate GetSystemDate()
	{
		clsDate Date;

		time_t now = time(0);
		tm* ltm = localtime(&now);

		Date._Day = ltm->tm_mday;
		Date._Month = 1 + ltm->tm_mon;
		Date._Year = 1900 + ltm->tm_year;

		return Date;
	}

	static bool IsLastDayInMonth(clsDate Date)
	{
		return (Date._Day == DaysInMonth(Date._Year, Date._Month));
	}

	bool IsLastDayInMonth()
	{
		return IsLastDayInMonth(*this);
	}
	
	static bool IsLastMonthInYear(const short &Month)
	{
		return (Month == 12);
	}

	bool IsLastMonthInYear()
	{
		return IsLastMonthInYear(_Month);
	}

	static void IncreaseDateByOneWeek(clsDate &Date)
	{
		for (int i = 1; i <= 7; i++)
		{
			IncreaseDateByOneDay(Date);
		}
	}

	void IncreaseDateByOneWeek()
	{
		IncreaseDateByOneWeek(*this);
	}

	void Print()
	{
		cout << DateToString();
	}

};