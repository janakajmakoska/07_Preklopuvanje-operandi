#include <iostream>

class Dropki
{
private:
    int broitel;
    int imenitel;
public:
    Dropki(int b=1, int i=1)
    {
        if(i==0)
        {
            std::cerr<<"Greshka: delenje so 0!";
            broitel=1;
            imenitel=1;
        }
        else if(i<0)
        {
            broitel=-b;
            imenitel=-i;
        }
        else
        {
            broitel=b;
            imenitel=i;
        }
        reduce();
    }

    int gcd(int a, int b)
    {
        if(b==0)
            return a;
        return gcd(b,a%b);
    }

    void reduce()
    {
        int gcd1=gcd(broitel,imenitel);
        broitel/=gcd1;
        imenitel/=gcd1;
    }

    Dropki operator+(const Dropki& d)
    {
        return Dropki(broitel*d.imenitel + d.broitel*imenitel, imenitel*d.imenitel);
    }

    Dropki operator-(const Dropki& d)
    {
        return Dropki(broitel*d.imenitel - d.broitel*imenitel, imenitel*d.imenitel);
    }

    Dropki operator*(const Dropki& d)
    {
        return Dropki(broitel*d.broitel, imenitel*d.imenitel);
    }

    Dropki operator/(const Dropki& d)
    {
        return Dropki(broitel*d.imenitel, imenitel*d.broitel);
    }

    void print()
    {
        std::cout<<broitel<<"/"<<imenitel<<std::endl;
    }

    void print_float()
    {
        std::cout<<(float)broitel/imenitel<<std::endl;
    }
};

int main()
{
    Dropki d1(2,4),d2(1,3),d3;
    d3=d1+d2;
    d3.print();
    d3=d1-d2;
    d3.print();
    d3=d1*d2;
    d3.print();
    d3=d1/d2;
    d3.print();
    d1.print();
    d1.print_float();
    return 0;
}
