#include "std_lib_facilities.h"
#include "date.h"

Date::Date(int yy, Month mm, int dd)
:y{yy}, m{mm}, d{dd}
{
    if(!is_valid())
        throw Invalid{};
}

Date::Date()
:y{1998}, m{Month::October}, d{15}
{}

bool Date::is_valid(){
    if (y > 2018 || y < 0)
        return false;
    if(int(m) > 12 || int(m) < 1)
        return false;
    if(d >= 1){
        switch(m){
            case Month::January: case Month::March: case Month::May: case Month::July: case Month::August:
            case Month::October: case Month::December:{
                if (d > 31)
                 return false;
            }
            break;
            case Month::April: case Month::June: case Month::September: case Month::November:{
            if (d > 30)
                return false;
            }
            break;
            case Month::February:{
              if(leapYear()){
                if (d > 29)
                 return false;

             }
              else{
                 if (d > 28)
                  return false;
              }
            }
            break;
        }
    }
    else
        return false;
    return true;
}


void Date::add_day(int n)
{
    switch(m){
            case Month::January: case Month::March: case Month::May: case Month::July: case Month::August:
            case Month::October: case Month::December:{
                if (d+n <= 31)
                    d += n;
                else{
                    if(int(m) == 12){
                      m = Month::January;
                      y++;
                    }
                    else{
                        m = Month(int(m)+1);
                    }
                    add_day(n-31);
                }

            }
            break;
            case Month::April: case Month::June: case Month::September: case Month::November:{
                if (d+n <= 30)
                    d += n;
                else{
                     m = Month(int(m)+1);
                    add_day(n-30);
                }
            }
            break;
            case Month::February:{
                if(leapYear()){
                    if (d+n <= 29)
                        d += n;
                    else{
                         m = Month(int(m)+1);
                        add_day(n-29);
                    }
                }
                else{
                    if (d+n <= 28)
                        d += n;
                    else{
                         m = Month(int(m)+1);
                         add_day(n-28);
                    }
                }
            }
            break;
        }
}

void Date::add_month(int n){
    int update = int(m) + n;
    if (update <= 12)
        m = Month(update);
    else{
        m = Month(update-12);
        y++;
        while(int(m) > 12){
            m = Month(int(m)-12);
            y++;
        }
    }
}

void Date::add_year(int n){
    y += n;
}

istream& operator>>(istream& is, Date& dd)
  {
      int y, m, d;
      char ch1, ch2, ch3, ch4;
      is >> ch1 >> y >> ch2 >> m >> ch3 >> d >> ch4;
      if (!is) return is;
      if (ch1!='(' || ch2!=',' || ch3!=',' || ch4!=')')
      {
          is.clear(ios_base::failbit);
          return is;
      }
      dd = Date{y,Month(m),d};
      return is;
  }

ostream& operator<<(ostream& os, const Date& d){
    return os << '(' << d.year() << ',' << d.month() << ',' << d.day() << ')';
}

bool operator==(const Date& d1, const Date& d2){
    if (d1.year() != d2.year())
        return false;
    if (d1.month() != d2.month())
        return false;
    if (d1.day() != d2.day())
        return false;
    return true;
}

bool operator!=(const Date& d1, const Date& d2){
 if ((d1.year() == d2.year()) && (d1.month() == d2.month()) && (d1.day() == d2.day()))
    return false;
 return true;
}

bool Date::leapYear(){
    if((y % 4 == 0) && (y % 100 != 0 || y % 400 == 0))
        return true;
    return false;
}
void Date::longForm(){
    string month;
    switch(m){
    case Month::January:
        month = "January";
        break;
    case Month::February:
        month = "February";
        break;
    case Month::March:
        month = "March";
        break;
    case Month::April:
        month = "April";
        break;
    case Month::May:
        month = "May";
        break;
    case Month::June:
        month = "June";
        break;
    case Month::July:
        month = "July";
        break;
    case Month::August:
        month = "August";
        break;
    case Month::September:
        month = "September";
        break;
    case Month::October:
        month = "October";
        break;
    case Month::November:
        month = "November";
        break;
    case Month::December:
        month = "December";
        break;
    }
    cout << month << " " << d << ", " << y;
}
