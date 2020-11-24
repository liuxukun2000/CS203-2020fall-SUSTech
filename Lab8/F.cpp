#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <set>
using namespace std;
int n, op, x;
long long ans, x1, x2;
multiset<int> pet, adopter;
multiset<int>::iterator it1,it2;
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d%d", &op, &x);
        if (op)
        {
            if (!pet.empty())
            {
                it2 = pet.lower_bound(x);
                it1=it2;
                if (it2 == pet.end())
                {
                    it1--;
                    it2--;
                    x2 = (*it2);
                    x1 = (*it1);
                }
                else
                {
                    x2 = (*it2);
                    if (it2 == pet.begin())
                    {
                        x1 = x2;
                    }
                    else
                    {
                        it1--;
                        x1 = (*it1);
                    }
                }
                if(abs(x1-x)<=abs(x2-x))
                {
                    ans+=abs(x1-x);
                    pet.erase(it1);
                }
                else
                {
                    ans+=abs(x2-x);
                    pet.erase(it2);
                }
                 
            }
            else
            {
                adopter.insert(x);
            }
        }
        else
        {
            if (!adopter.empty())
            {
                it2 = adopter.lower_bound(x);
                it1=it2;
                if (it2 == adopter.end())
                {
                    it1--;
                    it2--;
                    x2 = (*it2);
                    x1 = (*it1);
                }
                else
                {
                    x2 = (*it2);
                    if (it2 == adopter.begin())
                    {
                        x1 = x2;
                    }
                    else
                    {
                        it1--;
                        x1 = (*it1);
                    }
                }
                if(abs(x1-x)<=abs(x2-x))
                {
                    ans+=abs(x1-x);
                    adopter.erase(it1);
                }
                else
                {
                    ans+=abs(x2-x);
                    adopter.erase(it2);
                }
            }
            else
            {
                pet.insert(x);
            }
        }
    }
    printf("%lld\n",ans);
}
/**************************************************************
    Problem: 1200
    User: 11912823
    Language: C++
    Result: 正确
    Time:64 ms
    Memory:2032 kb
****************************************************************/
