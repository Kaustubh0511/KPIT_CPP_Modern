#include<iostream>
#include<memory>
using namespace std;
#define line(msg) cout<<"________________"#msg"______________________\n"
 
class CA
{
public:
    CA()
    {
        cout << "Default \n";
    }
    CA(const CA& par)
    {
        cout << "Copy\n";
    }
    CA(CA&& par) noexcept
    {
        cout << "Move\n";
    }
    ~CA() noexcept
    {
        cout << "D-tor\n";
    }
};
class CB
{
public:
    CB()
    {
        cout << "CB Ctor\n";
    }
    CB(int)
    {
        cout << "CB(int)\n";
    }
    CB(int, int)
    {
        cout << "CB(int,int)\n";
    }
    void fun()
    {
 
    }
    CB(CA par)
    {
        cout << "CB(CA)\n";
    }
    ~CB()
    {
        cout << "CB D-tor\n";
    }
};
 
 
template<typename T>
class Smart
{
    T* pt;
public:
    explicit Smart(T* pt = NULL):pt(pt)
    {
    }
 
    Smart(Smart&& par) noexcept :pt(par.pt)
    {
        par.pt = NULL;
    }
 
    Smart(const Smart&) = delete;
    Smart& operator=(const Smart&) = delete;
 
    T& operator*() const
    {
        return *pt;
    }
    T* operator->() const
    {
        return pt;
    }
 
    T* release()
    {
        T* tmp = pt;
        pt = NULL;
        return tmp;
    }
    void reset(T* par = NULL)
    {
        delete this->pt;
        this->pt = par;
    }
    operator bool() const
    {
        return pt != NULL;
    }
 
    ~Smart() noexcept
    {
        delete pt;
    }
};
 
template<typename T,typename... PCK>
Smart<T> make_smart(PCK&&... pck)
{
    return Smart<T>(new T(std::forward<PCK>(pck)...));
}
 
//template<typename T, typename... PCK>
//Smart<T> make_smart1(PCK&&... pck)
//{
//  T* tmp = new T(std::forward<PCK>(pck)...);
//  return Smart<T>(tmp);
//  //return Smart<T>(new T(std::forward<PCK>(pck)...));
//}
 
 
int main1()
{
    CA obj;
    line();
    Smart<CB> smt1=make_smart<CB>();
    line(10);
    Smart<CB> smt2=make_smart<CB>(10);
    line(1020);
    Smart<CB> smt3=make_smart<CB>(10,20);
    line(obj);
    Smart<CB> smt4=make_smart<CB>(obj);
    line(move_obj);
    Smart<CB> smt5=make_smart<CB>(std::move(obj));
    line(booloperator);
    if (smt1)
    {
        smt1->fun();
    }
    line(dtor);
 
    return 0;
}
 
 
void My_Smart()
{
    line(1_My_Smart);
    Smart<CB> smt1 = make_smart<CB>();
    line(2);
    Smart<CB> smt2;
    smt2.reset(new CB(10));
    line(3);
    smt2.reset(new CB(10, 20));
    line(4);
    CB* pt = smt2.release();
    line(5);
    delete pt;
    line(6);
    Smart<CB> smt3 = make_smart<CB>();
    line(7_smt3.reset(smt2.release()));
    smt3.reset(smt1.release());
    line(8);
    if (smt3)
    {
        smt3->fun();
        (*smt3).fun();
    }
    line(9);
}
 
 
void My_Smart_1()
{
    line(1_My_Smart_1);
    
    unique_ptr<CB> smt1 = make_unique<CB>();
    line(2);
    unique_ptr<CB> smt2;
    smt2.reset(new CB(10));
    line(3);
    smt2.reset(new CB(10, 20));
    line(4);
    CB* pt = smt2.release();
    line(5);
    delete pt;
    line(6);
    unique_ptr<CB> smt3 = make_unique<CB>();
    line(7_smt3.reset(smt2.release()));
    smt3.reset(smt1.release());
    line(8);
    if (smt3)
    {
        smt3->fun();
        (*smt3).fun();
    }
    line(9);
}
 
int main()
{
    My_Smart();
    cout << "*******************************************\n";
    My_Smart_1();
    return 0;
}