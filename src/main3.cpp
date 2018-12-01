#include "DateTime.h"

int main()
{
    DateTime T1, T2(1, 11, 2018);
    cout<<"today: T1 = "<<T1.getToday()<<endl;
    cout<<"yesterday: T1 = "<<T1.getYesterday()<<endl;
    cout<<"tomorrow: T1 = "<<T1.getTomorrow()<<endl;
    cout<<"T2 = "<<T2.getToday()<<" | T1 = "<<T1.getToday()<<" difference = "<<T1.getDifference(T2)<<endl;
    DateTime T3(31, 12, 1999), T4(T3);
    cout<<"T3 = "<<T3.getToday()<<" | T4 = "<<T4.getToday()<<" difference = "<<T4.getDifference(T3)<<endl;
    cout<<"T3 + 5 = "<<T3.getFuture(5)<<endl;
    cout<<"T4 - 31 = "<<T4.getPast(31)<<endl;
    return 0;
}