#include<iostream>
class Fish
{
    void nump1();
};
class Nemo : Fish
{
public:
void nump1(int* b)
{
    *b += 1;
}
};
int main()
{
    Nemo* nemo = new Nemo();
    int a1 = 0;
    int* a = &a1;
    nemo->nump1(a);
    std::cout<<a1;
    nemo = NULL;
    a = NULL;
    delete nemo;
    delete a;
}