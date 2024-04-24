#include <iostream>
#include <string>
#include <iomanip>
#include <vector>

using namespace std;

class Time
{
  public:
    Time(int=0, int=0, int=0);
    void setTime(int, int, int);
    void setHours(int h) ;
    void setMinutes(int m) ;
    void setSeconds(int s) ;
    void print() const;


  private:
    int hours;
    int minutes;
    int seconds;
    
    int convertToSecs() const;
};

Time::Time(int h, int m, int s)
{
  setTime(h, m, s);
}


void Time::setTime(int h,int m,int s)
{
    setHours(h);
    setMinutes(m);
    setSeconds(s);
}

void Time::setHours(int h)
{
  hours = ( h >= 0 && h < 24) ? h : 0;
}

void Time::setMinutes(int m)
{
  minutes = ( m >= 0 && m < 60) ? m : 0;
}

void Time::setSeconds(int s)
{
  seconds = ( s >= 0 && s < 60) ? s : 0;
}

int Time::convertToSecs() const
{
  return (hours*3600 + minutes*60 + seconds);
}

void Time::print() const
{
  cout<<setfill('0')<<setw(2)<<hours<<":"
      <<setfill('0')<<setw(2)<<minutes<<":"
      <<setfill('0')<<setw(2)<<seconds<<endl;
}