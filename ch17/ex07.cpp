#include <iostream>
#include <stack>
#include <deque>
#include <vector>

namespace Exercises
{
    template<class T, class C = deque<T> >
    class Stack
    {
    protected:
        bool needsFree;
        C& c;
    public:
        typedef typename C::value_type value_type;
        typedef typename C::size_type size_type;
        typedef typename C::iterator iterator;
        typedef typename C::const_iterator const_iterator;
        typedef C container_type;

        Stack() : needsFree(true), c(*(new C())) {}
        explicit Stack(C& a) : needsFree(false), c(a) {}
        ~Stack() { if(needsFree) delete &c; }

        bool empty() const { return c.empty(); }
        size_type size() const { return c.size(); }

        value_type& top() { return c.back(); }
        const value_type& top() const { return c.back(); }

        void push(const value_type& x) { c.push_back(x); }
        void pop() { c.pop_back(); }

        iterator begin() { return c.begin(); }
        const_iterator begin() const { return c.begin(); }
        iterator end() { return c.end(); }
        const_iterator end() const { return c.end(); }
    };
}

int main()
{
    using namespace std;
    using namespace Exercises;

    Stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);

    // should print 123
    for(Stack<int>::const_iterator i = s.begin(); i != s.end(); i++)
    {
        cout << *i;
    }
    cout << endl;

    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    Stack<int,vector<int> > s2(v);
    s2.push(4);
    s2.push(5);

    // should print 12345
    for(Stack<int,vector<int> >::const_iterator i = s2.begin(); i != s2.end(); i++)
    {
        cout << *i;
    }
    cout << endl;

    // should print 12345
    for(vector<int>::const_iterator i = v.begin(); i != v.end(); i++)
    {
        cout << *i;
    }
    cout << endl;

    return 0;
}
