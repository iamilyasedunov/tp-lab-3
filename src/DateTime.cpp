#include "DateTime.h"

string days[7] = {"sunday", "monday", "tuesday",
                  "wednesday", "thursday", "friday",
                  "saturday"};
string months[12] = {"january","february","march","april",
                     "may","june","july","august",
                     "september","october","november","december"};


void DateTime::Rewrite(struct tm * Time){
        day = Time->tm_mday;
        month = Time->tm_mon;
        year = Time->tm_year + 1900;
        wday = Time->tm_wday;
}
DateTime::DateTime(){
        time_t rawtime;
        time(&rawtime);
        struct tm * Time = localtime(&rawtime);
        sec = mktime(Time);
        cout<<Time->tm_mday<<endl<<Time->tm_mon<<endl;
        Rewrite(Time);
}
DateTime::DateTime(int new_day, int new_month, int new_year){
        time_t rawtime;
        time(&rawtime);
        struct tm * Time = localtime(&rawtime);
        Time->tm_mday = new_day;
        Time->tm_mon = new_month - 1;
        Time->tm_year = new_year - 1900;
        sec = mktime(Time);
        Rewrite(Time);
}	
DateTime::DateTime(const DateTime& T){
        this->day = T.day;
        this->month = T.month;
        this->year = T.year;
        this->wday = T.wday;
        this->sec = T.sec;
}

string DateTime::buildDate() {
        string ans = "";
        if (day < 10){
            ans = ans + "0";
        }
        ans = ans + to_string(day) + " " + months[month] + " " + to_string(year)+ ", " + days[wday];
        return ans;
}
string DateTime::getToday(){
		return buildDate();
}
string DateTime::getTomorrow() {
        return getFuture(1);
}
string DateTime::getYesterday() {
        return getPast(1);
}
string DateTime::getFuture(unsigned int N){
        time_t in_future = (time_t)N*86400 + sec;
        struct tm * Time = localtime(&in_future);
        sec = mktime(Time);
        Rewrite(Time);
        return buildDate();
}
string DateTime::getPast(unsigned int N){
        time_t in_future = -(time_t)N*86400 + sec;
        struct tm * Time = localtime(&in_future);
        sec = mktime(Time);
        Rewrite(Time);
        return buildDate();
}
int DateTime::getDifference(DateTime& Time2){
        time_t sec1 = sec;
        time_t sec2 = Time2.sec;
        return (int)(abs(sec2 - sec1)/86400);
}