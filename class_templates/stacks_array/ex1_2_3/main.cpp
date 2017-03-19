#include <iostream>
#include <bits/stdc++.h>
#include <stdexcept>
#include <algorithm>

using namespace std;

template <typename T, int N>
class Stack
{
    int top;
    T *S;//we declare the pointer to the first element of the array, instead of T S[N], because the N might be given as a negative number
    //T *S;
    //int N;
public:
    Stack(){
        assert(N > 0);//the execution of the program is aborted if the size of the stack is given as a negative number
        S = new T[N];//allocate the space for N variables after checking the value
        top = -1;
        }
    //user-defined copy constructor
    Stack(const Stack &obj, int new_size)
    {
        cout << "Copy constructor allocating S of size N";
        assert(obj.N > 0);
        S = new T[N];
        top = obj.top;
        int copy_size = std::min(N, new_size);
        std::copy( obj.S, S+copy_size, S);

    }

    void push (T& v) {
        if (top == N)
            throw string("Stack is already full"); //without this check an overflow of the storage of the stack would occur
        S[++top] = v;
        }

    T pop (T& v) //pop operation accepts a reference to the value to be popped
    {
        if (top == -1)
            throw string("Stack is still empty");//without this check the deletion of non-existent parts of the stack would have happened. Index out of bounds of the stack.
        //top--;
         //v = (&(--top));//decrement top and return array position *v
         v = S[top--]; //here we are not copying, reassigning
         cout << v << endl;
         return v;
        //return S[top--];//we delete an item after returning it's value
    }
    bool empty()
    {
        if (top == -1)
        {
            return 1;
        }
        else return 0;
    }

    ~Stack()
    {
        delete[] S;
    }

};
int main()
{
    //Stack<int, -10> sneg10int; // the execution of the program is aborted
    Stack<int, 10> s10int;
    int v = 10;
    cout << "Pushing elements to the stack" << endl;
    while(v<=100)
    {
    s10int.push(v);
    cout << v << ' ';
    v+=10;
    }
    cout << "\nPopping elements from the stack" << endl;
    while(v>=10){
    s10int.pop(v);
    v-=10;
    }
    return 0;
}
