#include <iostream>
#include <assert.h>
using namespace std;

template<typename T>
class Node{

        public:
            T value;
            Node* nxt;
            Node* prv;
            Node(T v): value(v), nxt(0), prv(0) {}
            Node(T d, Node* n = NULL, Node* nn = NULL): value(d), nxt(n), prv(nn){}
            void add(Node* n)
            {
                n->nxt = this->next;
                n->prv = this->prv;
                this->nxt= n;
            }

            class iNode{
                Node* current;
                public:
                     iNode(Node* x):current(x) {}
                     iNode(const iNode& p1) : current(p1.current) {}
                     iNode& operator++() {
                         //cout << "current " << *(*current) << endl;
                         current = current->nxt;
                         //cout << "current " << *(*current) << endl;
                         return *this;
                         }
                     iNode operator++(int)
                     {
                         iNode tmp(*this);
                         operator++();
                         return tmp;
                     }
                     iNode& operator--(){
                         assert(current->prv!=NULL);
                         //cout << "what" << endl;
                         //if (current->prv!=null && current == NULL)
                         //{

                         //}
                         //cout << current->prv << endl;
                         current = current->prv;
                         return *this;
                     }
                     iNode operator--(int){
                     iNode tmp(*this);
                     operator--();
                     return tmp;
                     }
                     /*iNode& operator=(const iNode& el)
                     {
                         current->el = el->current;
                         return *this;
                     }
                     iNode& operator=(const T el)
                     {
                         current->value = el;
                         return *this;
                     }
                     */
                     bool operator==(iNode& el)
                     {
                         if (el == NULL)
                         {
                             if (current == NULL)
                                return true;
                             else return false;
                         }
                         else
                         {
                         return current->value==el.current->value;
                         }
                     }
                     bool operator!=( iNode& el)
                     {
                         //cout << el.current->get_value() << endl;
                         //if (el.current == NULL)
                           // return 0;
                         //else
                           // return 1;

                         if (el.current == NULL)
                         {
                           //  cout << "fdgdf" << endl;
                             if (current == NULL)
                               return false;
                             else
                               return true;
                         }
                         else
                         {

                         return current->value!=el.current->value;
                         }
                     }
                     T& operator*()
                     {
                         return current->value;
                     }
                     Node& operator+(T v){
                        iNode tmp = (*this);
                         for (int i = 0; i<v; i++)
                         {
                             tmp++;
                             assert(tmp!=NULL);
                             //return tmp;
                         }
                         return tmp;
                     }

            };
            /*bool operator!=(Node* node1)
            {
                if (this->value == node1->value)
                    return 1;
                else return 0;
            }

            T operator*()
            {
                return this->value;
            }
             */
            Node* operator++()
            {
                return this->next;
            }
            Node* operator++(int)
            {
                Node* tmp(*this);
                operator++();
                return tmp;
            }
            /*T* operator--()
            {
                return this->prv;
            }
            T* operator--(int)
            {
                Node* tmp(*this);
                operator--();
                return tmp;
            }
            */
            Node& operator=(const T el)
                     {
                         this->value = el;
                         return *this;
                     }
            T& get_value()
            {
                return value;
            }

        };

template <typename T>
class DoublyLinkedList{

private:


public:

    Node<T>* tail;
    Node<T>* head;
    Node<T>* current;
    int num;
    DoublyLinkedList()
    {
        tail = NULL;
        head = NULL;
        current = NULL;
        num = 0;
    }
    Node<T>* get_head()
    {
        assert(head!=NULL);
        return head;
    }
    Node<T>* get_tail()
    {
        assert(tail!=NULL);
        return tail;
    }
    Node<T>* get_beyond()
    {
        assert(tail!=NULL);
        return tail->nxt;
    }
    T& get_first()
    {
      assert(head!=NULL);
      return head->value;
    }
    T& get_last()
    {
        assert(tail!=NULL);
        return tail->value;
    }

    int size()
    {
        return num;
    }

    void add(T& val)
    {
        Node<int>* beyond = NULL;
        Node<int>* temp = new Node<int>(val, beyond);
        if (head==NULL)
        {
            head = temp;
            current = head;
        }
        else
        {
            temp->prv = current;
            tail->nxt = temp;
            //tail->prv = current;
        }
        //current = tail;
        tail = temp;
        current = tail;
        //T b  = *tail->prv;
        //cout << "tail->prv" << b << endl;
        num++;
    }
    T& remove_last()
    {
        assert(this->size()!=0);
        Node<int>* to_remove = tail;
        T to_remove_v = to_remove->value;
        if (this->size()==1){
        head = NULL;
          tail = NULL;
        }
        else
        {
        tail = tail->prv;
        }
        delete to_remove;
        num--;
        return to_remove_v;
    }
    T& remove_first()
    {
        assert((this->size())!=0);
        assert(head!=NULL);
        Node<int>* to_remove = head;
        T to_remove_v = head->value;
        if(this->size() == 1)
        {
        head = NULL;
        tail = NULL;
        }
        else
        {
         head = head->nxt;
        }
        delete to_remove;
        num--;
        return to_remove_v;

    }
    T& remove_at(int in)
    {
        int i = 0;
        Node<int>* rem = head;
        while(i!=in)
        {
            rem = rem->nxt;
            i++;
        }
        T rem_val = rem->value;
        rem->prv->prv->nxt =rem->nxt;
        delete rem;
        num--;
        return rem_val;
    }
    T& get_at(int in)
    {
        assert(in>=0 && in<num);
        assert(this->size()!=0);
        Node<int>* find_val = head;
        int i = 0;
     while(i!=in)
     {
         find_val = find_val->nxt;
         i++;
     }
     T find_val_v = find_val->prv->value;
     return find_val_v;
    }
    T& operator[] (int index){
    return get_at(index);
    }

    ~DoublyLinkedList(void)
    {
     while(this->size()!=0){
    this->remove_first();
     }
    }


};

template <typename T, typename P>
P find5 (P first, P beyond, const T& x)
{
    P p = first;
    while (p!=beyond && *p!= x)
    {
        p++;
    }
    return p;
}

int main()
{
    int v = 5;
    int v2 = 7;
    DoublyLinkedList<int> list1;
    list1.add(v);
    list1.add(v2);

    //Node<int>::iNode from(list1.get_head()); /*5*/
    //Node<int>::iNode temp(from);
    //Node<int>::iNode until(++temp);
    Node<int>::iNode first(list1.get_head());
    Node<int>::iNode beyond(list1.get_beyond());
    typedef Node<int>::iNode n;
    Node<int>::iNode a(find5<int, n>(first, beyond, v2));
    //reverse2<int, n>(first, beyond);
    cout <<"found" << *a << endl;
    for (Node<int>::iNode it=first; it!=beyond; it++)
    {
        //cout << *(*it++) << endl;
        cout << "elem" << *it << ' ';
        cout << '\n';
    }
    return 0;
}
