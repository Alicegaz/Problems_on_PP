#include <iostream>
#include <bits/stdc++.h>
#include <stdexcept>
#include <algorithm>

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

template <int leftBorder, int rightBorder, typename T>
class Array
{
    int length;
    int nextIndex;
    int top;
public:
    T *S;//we declare the pointer to the first element of the array, instead of T S[N], because the N might be given as a negative number
    int N;
    typedef RANGE<leftBorder, rightBorder> Range1; //define the type with fixed left and right borders
    Array(){
        /** checking if the N is not negative*/
        N = abs(leftBorder) + abs(rightBorder) + 1;
        assert(N>0);
        S = new T[N];//allocate the space for N variables after checking the value
        //for (int i = 0; i < N; i++)
            //S[i] = 0;
        length = N;
        nextIndex = 0;
        top = -1;
        cout << "ranges " << N << endl;
        }
    /** read method, reading elements of the stack from the console*/
    void read(){
        T n;
      for(int i=0; i<length; i++)
     {
         cout<<"Enter for array "<<i<<" number: ";
         cin>>n;
         add(n);
     }
     cout << "array read: " << endl;
     for (int i = 0; i<length; i++)
     {
    cout<<S[i]<<' ';
    }
    }
    /**delete top, deleting the last element from the array*/
    T delete_top()
    {
        assert(length!=0);
        T del_el = S[top];
        T* temp = (T*) malloc((top)*sizeof(T));
        memcpy(temp, S, top*sizeof(T)); //move everything before the element to be removed
        top--;
        length--;
        delete [] S;
        S = temp;
        cout << del_el << ' ';
        return del_el;
    }
    /** delete arbitrary element*/
    T delete_arb(int ind)
    {
        Range1 index_range = ind;
        assert(index_range.in_range());
        int index = ind - leftBorder;
        assert(length!=0);
        assert(index =length && index >=0);
        T del_el = S[index];
        T* temp = malloc((length-1)*sizeof(T));
        memcpy(temp, S, (index- 1)*sizeof(T));
        memcpy(temp+(index* sizeof(T)), S+((index +1)*sizeof(T)), (length - index)*sizeof(T) );//copy everything after the element to remove
        length--;
        delete [] S;
        S = temp;
        return del_el;
    }
    /**destroy the array method*/
    void destoy()
    {
        delete[] S;
        std::cout << "Array destroyed\n" << endl;
    }
    /**indexing operator*/
    T& operator[] (int ind){
        //cout << ind << endl;
        T *extended;
        //cout << "nextIndex" << nextIndex << endl;
        Range1 index_range(ind);
        assert(index_range.in_range());

        int index = ind - leftBorder;
        //cout << index << endl;
        if (index >= length){
            int l = length*2;
            extended = new T[l];
            //for (int i = 0; i < nextIndex; i++)
                //extended[i] = S[i];
            memcpy( extended, S, sizeof(T)*length);
            for (int j = nextIndex; j < l; j++)
                extended[j] = 0;
            length = l;
            delete [] S;
            S = extended;
        }
        //cout << "nextIndex" << nextIndex << endl;
        if (index > nextIndex)
            nextIndex = index + 1;
        return *(S + index);
    }
	/**returns the last entered element from the
	array, equals to the length+1 of the array.
	If we double the size of the array there will
	be 0, so we don`t count them here */
    int peak(){
        return top;
    }

    T display(void){
        cout << "\n" << endl;
    for (int i = 0; i<=this->peak(); i++)
    {
        cout<< i+leftBorder << ": " << S[i] << ", ";
    }
    }
    /**Adding an element to array method*/
    void add(T& v){
        //cout << v << endl;
        Range1 index_range(nextIndex+leftBorder);
        //cout << index_range << endl;
        cout << nextIndex + leftBorder << ' ';
        assert(index_range.in_range());

        //int index = ind - leftBorder;
    T *extended;
    if (nextIndex == length){
        extended = new T[length*2];
        //for (int i = 0; i < length; i++)
            //extended[i] = S[i];
        memcpy( extended, S, sizeof(T)*length);
        for (int j = nextIndex; j < length*2; j++)
            extended[j] = 0;
        delete [] S;
        S = extended;
        length = length*2;
    }
    //cout << nextIndex << endl;
    S[nextIndex++] = v;
    top++;
    }
    /**
    size of the array, when resized returns the
	actual number of elements, including those
	not used (zero)
    **/
    int size(){
        return length;
    }
    int act_size()
    {
        return (peak() + 1);
    }
    /**destructor of the array*/
    ~Array()
    {
        cout << endl << "destroying the array"<<endl;
        //for (int i = 0; i< length; i++)
        //{
        //    cout << S[i] << ' ';
        //}
        delete[] S;
        std::cout << "\nArray destroyed\n" << endl;
    }

};


int main()
{
    Array<-5, 5, int> c;
    int v = 4;
    int i = -5;
    c.add(v);
    cout << c[i] << endl;

    v++;
    c.add(v);
    cout << c[-4] << endl;

    for (i=0; i<=8; i++){
            v++;
        c.add(v);
    }
    c.display();

    /**assigning the value to the element of the array*/
    c[3] = 5;
    c.display();

    int l = c.act_size();
    cout << "\nsize  " << l << endl;
   // cout << c[0] << endl;
    //cout << c[5] << endl;
    //cout << c[-6] << endl; //terminated
    return 0;
}
