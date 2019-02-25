#include "DateTime.h"

string days[7] = {"sunday", "monday", "tuesday",
                  "wednesday", "thursday", "friday",
                  "saturday"};
string months[12] = {"january","february","march","april",
                     "may","june","july","august",
                     "september","october","november","december"};



DateTime::DateTime(){
        time_t rawtime;
        time(&rawtime);
        struct tm * Time = localtime(&rawtime);
        sec = mktime(Time);
}
DateTime::DateTime(int new_day, int new_month, int new_year){
        time_t rawtime;
        time(&rawtime);
        struct tm * Time = localtime(&rawtime);
        Time->tm_mday = new_day;
        Time->tm_mon = new_month - 1;
        Time->tm_year = new_year - 1900;
        sec = mktime(Time);
}	
DateTime::DateTime(const DateTime& T){
        sec = T.sec;
}

string DateTime::buildDate(struct tm * Time) {
        string ans = "";
        if (Time->tm_mday < 10){
            ans = ans + "0";
        }
        ans = ans + to_string(Time->tm_mday) + " " + months[Time->tm_mon] + " " + to_string(Time->tm_year + 1900)+ ", " + days[Time->tm_wday];
        return ans;
}
string DateTime::getToday(){
        time_t today = sec;
        struct tm * Time = localtime(&today);
        mktime(Time);
        return buildDate(Time);
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
        mktime(Time);
        return buildDate(Time);
}
string DateTime::getPast(unsigned int N){
        time_t in_past = -(time_t)N*86400 + sec;
        struct tm * Time = localtime(&in_past);
        mktime(Time);
        return buildDate(Time);
}
int DateTime::getDifference(DateTime& Time2){
        time_t sec1 = sec;
        time_t sec2 = Time2.sec;
        return (int)(abs(sec2 - sec1)/86400);
}
