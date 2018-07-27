enum class Month {
    January=1, February, March, April, May, June, July, August, September, October, November, December
};

class Date{
public:
    class Invalid {};
    Date(int y, Month m, int d);
    Date();
    void add_day(int n);
    void add_month(int n);
    void add_year(int n);
    int month() const {return int(m);};
    int day() const {return d;};
    int year() const {return y;};
    void longForm();
    bool leapYear();
private:
    int y,d;
    Month m;
    bool is_valid();
};

istream& operator>>(istream& is, Date& dd);
ostream& operator<<(ostream& os, const Date& d);
bool operator==(const Date& d1, const Date& d2);
bool operator!=(const Date& d1, const Date& d2);




