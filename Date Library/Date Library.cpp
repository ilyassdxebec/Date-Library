#include <iostream>
#include"clsDate.h"

using namespace std;

int main()
{
    clsDate Date1;
    
    cout << (clsDate::enDateComparison) Date1.CompareToDate2(clsDate(23, 3, 2026)) << endl;
}
