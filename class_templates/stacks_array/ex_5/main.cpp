#include <bits/stdc++.h>
#include <stdexcept>
#include <algorithm>

using namespace std;

template <typename T, int N>
class Dynarray
{
    int length;
    int nextIndex;
    int top;
public:
    /** Array constructor*/
    T *S;//we declare the pointer to the first element of the array, instead of T S[N], because the N might be given as a negative number

    Dynarray(){
        /** checking if the N is not negative*/
        assert(N>0);
        S = new T[N];//allocate the space for N variables after checking the value
        //for (int i = 0; i < N; i++)
            //S[i] = 0;
        length = N;
        nextIndex = 0;
        top = -1;
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
        assert(length!=0);
        assert(ind<=length && ind >=0);
        T del_el = S[ind];
        T* temp = malloc((length-1)*sizeof(T));
        memcpy(temp, S, (ind - 1)*sizeof(T));
        memcpy(temp+(ind * sizeof(T)), S+((ind+1)*sizeof(T)), (length - ind)*sizeof(T) ); //copy everything after the element to remove
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
	/**returns the last entered element from the 
	array, equals to the length+1 of the array.
	If we double the size of the array there will
	be 0, so we don`t count them here */
    int peak(){
        return top;
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
    size of the array, when resized returns the 
	actual number of elements, including those 
	not used (zero)
    **/
    int size(){
        return length;
    }
    /**destructor of the array*/
    ~Dynarray()
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

template <typename T, int N>
class Stack
{
    int top;
    int length;
    Dynarray<T, N> *S;
public:
    Stack()
    {
        assert(N>0);
        S = new Dynarray<T, N>;
        top = S->peak();
        length = S->size();
    }
     void push (T& v) {
        S->add(v);
        /** we don't need top++; top is
		incremented in the Dynarray template */
        top = S->peak();
        }

    void pop (T& v) //pop operation accepts a reference to the value to be popped
    {
        if (top == -1)
            throw string("Stack is still empty");//without this check the deletion of non-existent parts of the stack would have happened. Index out of bounds of the stack.
        //decrement top in the Dynarray method
        S->delete_top();
        top = S->peak();
    }
	/**to check if the stack is empty*/
    bool empty()
    {
       return (S->size()==0);
    }
	
    int size(){
       return S->size();
    }
    /** only those elements used, 0 at the end are ignored**/
    int act_size(){
        return top;
    }
	/** displaying the array*/
    T display(int i){
       assert(i<=top);
       assert(i>=0);
       return (S->S[i]);
    }
    ~Stack()
    {
        delete S;
    }
};

int main()
{
    Stack<int, 10> s10int;
    int v = 0;

    /**Pushing elements to the stack*/
    while(v<100)
    {
        v+= 10;
    s10int.push(v);
    //cout << v << ' ';
    }
	//pushing an element which will doublethe size of the array
    int v2 = 12;
    s10int.push(v2);
    cout << "Pushed elements" << endl;
     for(int i = 0; i<s10int.act_size(); i++)
    {
        cout<< s10int.display(i) << ' ';
    }

    cout << "\nPopping last element from the stack" << endl;
    s10int.pop(v2);
    cout << "\nStack after popping last element from the stack" << endl;
     for(int i = 0; i<s10int.act_size(); i++)
    {
        cout<< s10int.display(i) << ' ';
    }

    cout << "\nPopping elements from the stack" << endl;
    while(v>=10){
    s10int.pop(v);
    v-=10;
    }

    return 0;
}
