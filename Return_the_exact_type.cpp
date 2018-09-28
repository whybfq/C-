/*********************************************************************************
  *@copyright (C) 2018 san All Rights Reserved
  *@file    Return_the_exact_type.cpp
  *@date    Sep 2018
  *@author  san
  *@CMAKE_CXX_STANDARD 17
  *@IDE:    Clion 2018.3
  *@OS:     macOS High Sierra 10.13.6
  *
  *@brief:  从例子中可以看出返回确切类型要更通用些，而且在自动地进行向上类型转换时不丢失特定地信息。然而，返回基类型通常会解决我们地问题。
  *@function_lists:
  *  1.

  *@warning:
  *@history:
     1.Date:
       Author:
       Modification:
**********************************************************************************/
#include <iostream>
#include <string>
using namespace std;

class PetFood{
public:
    virtual string foodType() const = 0;
};

class Pet{
public:
    virtual string type() const = 0;
    virtual PetFood * eats() = 0; //return a point to PetFood
};

class Bird : public Pet{
public:
    string type() const { return "Bird"; }
    class BirdFood : public PetFood {
    public:
        string foodType() const { return "Birds food"; }
    };

    // upcast to base type:
    PetFood* eats() { return  &bf; }  //向上转换为基类PetFood

private:
    BirdFood bf;
};

class Cat : public Pet{
public:
    string type() const { return "Cat";  }
    class CatFood : public PetFood {
    public:
        string foodType() const { return "Cats food"; }
    };
    // return exact type instead:
    CatFood* eats() { return  &cf; }  // 返回确切类型，从基类的返回类型中继承而来。
    // eats()还是返回一个PetFood指针

private:
    CatFood cf;
};

int main(int argc, char const *argv[]) {
    Bird b;
    Cat c;
    Pet* p[] = {&b,&c };
    for (int i = 0; i < sizeof p/ sizeof （* p）; ++i) {
        cout << p[i]->type() << " eats " << p[i]->eats()->foodType() << endl;
    }
    // Can return the exact type:
    Cat::CatFood * cf = c.eats();
    Bird::BirdFood* bf;
    // Can't return the exact type:
    // ! bf = b.eats();
    // Must downcast:    必须向下类型转换为确切地类型
    bf = dynamic_cast<Bird::BirdFood*>(b.eats());
}
