#include <iostream>
#include <stdexcept>

using namespace std;

template <int leftBorder, int rightBorder>
class RANGE{
int value;
RANGE(){}
public:

    RANGE(int v)
    {
        value = v;
        check();
    }
    RANGE(RANGE& r)
    {
        value = r.value;
    }

    int get_value(void){
    return value;
    }

    RANGE& operator=(RANGE& r)
    {
        value = r.value;
        check();
        cout << "this" << this << endl;
        cout << "*this" << *this << endl;
        return *this;
    }

    RANGE& operator=(int &v)
    {
        value = v;
        check();
        cout << "this" << this << endl;
        cout << "*this" << *this << endl;
        return *this;
    }
    RANGE& operator+(const RANGE& rang1)
    {
        value += rang1.value;
        check();
        return *this;
    }
     RANGE& operator+(int &v)
    {
        value += v;
        check();
        return *this;
    }

    RANGE& operator*(int &v)
    {
        value *= v;
        check();
        return *this;
    }
    RANGE& operator*(const RANGE& rang1)
    {
        value *= rang1.value;
        check();
        return *this;
    }
    RANGE& operator-(int &v)
    {
        value -= v;
        check();
        return *this;
    }
    RANGE& operator-(const RANGE& rang1)
    {
        value -= rang1.value;
        check();
        return *this;
    }
    RANGE& operator/(const RANGE& rang1)
    {
        if (rang1->value == 0)
        {
            throw std::invalid_argument("Cannot divide by zero");
        }
        value /= rang1.value;
        check();
        return *this;
    }
    RANGE& operator/(int &v)
    {
        if (v == 0)
        {
            throw std::invalid_argument("Cannot divide by zero");
        }
        value /= v;
        check();
        return *this;
    }
    RANGE& operator++(void)
    {
        value++;
        check();
        return *this;
    }
    RANGE& operator--(void)
    {
        value--;
        check();
        return *this;
    }

    bool operator>(const RANGE& rang1)
    {
        if(value > rang1.value)
        {
        check();
        return 1;
        }
        else return 0;
    }

    bool operator>(int &v)
    {
        if(value > v)
        {
        check();
        return 1;
        }
        else return 0;
    }
    bool operator<(const RANGE& rang1)
    {
        if (value < rang1.value)
        {
        check();
        return 1;
        }
        else
            return 0;
    }
     bool operator<(int &v)
    {
        if (value < v)
        {
        check();
        return 1;
        }
        else
            return 0;
    }
    bool operator>=(const RANGE& rang1)
    {
        if(value >= rang1.value)
        {
        check();
        return 1;
        }
        else return 0;
    }
    bool operator>=(int &v)
    {
        if(value >= v)
        {
        check();
        return 1;
        }
        else return 0;
    }

    bool in_range(void){
    if (value >= leftBorder || value <= rightBorder)
        return 1;
    else
        return 0;
    }

    bool operator<=(const RANGE& rang1)
    {
        if(value <= rang1.value)
        {
        check();
        return 1;
        }
        else return 0;

    }
    bool operator<=(int &v)
    {
        if(value <= v)
        {
        check();
        return 1;
        }
        else return 0;

    }
    /**преобразование объектов нашего типа к объектам целого типа*/
    operator int()
    {
        return value;
    }
    operator long()
    {
        return long(value);
    }
    void check(void)
    {
        if (value < leftBorder || value > rightBorder)
            throw 1;
    }

    ~RANGE()
    {
     delete &value;
    }

};
int main()
{
    RANGE<20, 40> c(28);
    RANGE<20, 40> c2(29);
    RANGE<10, 12> n(11);
    int p = 10;
    /*it can use relational operations for integer and a range type variable*/
    if (c <= p)
    {
        cout << c.get_value() << " <= " << p << endl;
    }
    /** error ambiguous overload, objects of different types cannot be compared
    if (n <= c)
    {

        cout << n << " <= " << c << endl;
    }
    */
    /* two objects of same RANGE type can be compared*/
    if (c < c2)
    {
        cout<< "c of type range with bounds 20, 40 is less than c2 of the same type: 1\n" << endl;
    }
    else
    {
        cout << "c of type range with bounds 20, 40 is more than c2 of the same type: 0\n" << endl;
    }
    int a = 2;
    int b = c2 + a;
    cout << "c2 + a = " << b << endl;
    long i = c;
    cout << "\nto long converted: " << i << endl;
    return 0;
}
