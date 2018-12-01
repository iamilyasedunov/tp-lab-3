#include <string>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <iterator>
#include <queue>
#include <set>
#include <cmath>
#include <string>
#include <ctime>

using namespace std;

class DateTime {
private:
    int day;
    int month;
    int year;
    int wday;
    time_t sec;
public:
    void Rewrite(struct tm * Time);
    DateTime();
    DateTime(int new_day, int new_month, int new_year);
    DateTime(const DateTime& T);

    string buildDate();
	
    string getToday();
    string getTomorrow();
    string getYesterday();
	
    string getFuture(unsigned int N);
    string getPast(unsigned int N);
    int getDifference(DateTime& Time2);
};