#include <iostream>
#include <bits/stdc++.h>
#include <stdexcept>
#include <algorithm>

using namespace std;

template <typename T, int N>
class Dynarray
{
    T *S;//we declare the pointer to the first element of the array, instead of T S[N], because the N might be given as a negative number
    int length;
    int nextIndex;
    T top;
public:
    /** Array constructor*/
    Dynarray(){
        //N = 10;
        assert(N>0);
        S = new T[N];//allocate the space for N variables after checking the value
        //for (int i = 0; i < N; i++)
            //S[i] = 0;
        length = N;
        nextIndex = 0;
        top = -1;
        }
    /** read method*/
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
    /**delete top*/
    T delete_top()
    {
        assert(length!=0);
        T del_el = S[top];
        T* temp = malloc((legth-1)*sizeof(T));
        memcpy(temp, S, top - 1); //move everything before the element to be removed
        top--;
        length--;
        delete [] S;
        S = temp;
        return del_el;
    }
    /** delete arbitrary element*/
    T delete_arb(int ind)
    {
        assert(length!=0);
        assert(ind<=length && ind >=0);
        T del_el = S[ind];
        T* temp = malloc((length-1)*sizeof(T));
        memcpy(temp, S, ind - 1);
        memcpy(temp+(ind * sizeof(T)), S+((ind+1)*sizeof(T)),length - ind ); //copy everything after the element to remove
        length--;
        delete [] S;
        S = temp
        return del_el;
    }
    /**destroy the array method*/
    void destoy()
    {
        delete[] S;
        std::cout << "Array destroyed\n" << endl;
    }
    /**indexing operator*/
    T& operator[] (int index){
        T *extended;
        //cout << "nextIndex" << nextIndex << endl;
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
    /**Adding an element to array method*/
    void add(T& v){
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
    S[nextIndex++] = v;
    top++;
    }
    /**
    size of the array, when resized returns the actual number of elements, including those not used (zero)
    **/
    int size(){
        return length;
    }
    /**destructor of the array*/
    ~Dynarray()
    {
        cout << "destroying the array"<<endl;
        for (int i = 0; i< length; i++)
        {
            cout << S[i] << ' ';
        }
        delete[] S;
        std::cout << "\nArray destroyed\n" << endl;
    }

};
int main()
{
    Dynarray<int, 10> da; //create an array
    int p = 10;
    int i = 0;
    int j = 0;
    for(i = 0; i<10; i++)
    {
        da.add(p);
        p+=10;
    }
    cout << "array with fixed number of elements: " << endl;
    for (i = 0; i<da.size(); i++)
        cout << da[i] << ' ';//call the element of the array by it's index
    cout << "\n" << endl;

    cout << "\nthe length of the array: " << da.size() << "\n" << endl;//getting the current length of the array

    da[12] = 25; //resize by assigning to the element of the array of the index > length a value
    cout << "resized array: " << endl;
    for (j = 0; j<da.size(); j++)
        cout << da[j] << ' ';
    cout << "\n" << endl;

    cout << "\nthe length of the array: " << da.size() << "\n" << endl;
    //getting the current length of the array

    /**reading the array from
    console calling the read
    operator from the template
    **/
    Dynarray<int, 10> da1;
    da1.read();
    cout << "\n" << endl;

    da1[18] = 5;
    cout << "array read from the console and resized:";
    for (int i = 0; i<da1.size(); i++)
    {
        cout << da1[i] << ' ';
    }
    cout << "\n" << endl;
    return 0;
}
