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
    time_t sec;
public:
    DateTime();
    DateTime(int new_day, int new_month, int new_year);
    DateTime(const DateTime& T);

    string buildDate(struct tm * Time);
	
    string getToday();
    string getTomorrow();
    string getYesterday();
	
    string getFuture(unsigned int N);
    string getPast(unsigned int N);
    int getDifference(DateTime& Time2);
};