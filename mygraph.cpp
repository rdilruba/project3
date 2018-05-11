#include <iostream>
#include <algorithm>

using namespace std;


class edge
{
public:
    int pre;
    int next;
    int length;
    int thiefnumber;
    vector<int> thiefs;
    edge()
    {
        length=0;
        next=0;
        pre=0;
        thiefnumber=0;
        thiefs.push_back(0);

    }
    edge(int p,int n,int l,int t)
    {
        pre=p;
        next=n;
        length=l;
        thiefnumber=t;

    }
    edge(int p,int n,int l,int t,vector<int> th)
    {
        pre=p;
        next=n;
        length=l;
        thiefnumber=t;
        for(int i=0; i<thiefnumber; i++)
        {
            thiefs.push_back(th[i]);
        }

    }
    edge(const edge &edge1)
    {
        pre=edge1.pre;
        next=edge1.next;
        length=edge1.length;
        thiefnumber=edge1.thiefnumber;

        if(!thiefs.empty())
            thiefs.clear();
        for(int i=0; i<thiefnumber; i++)
        {
            thiefs.push_back(edge1.thiefs[i]);
        }

    }
    edge& operator=(const edge& edge1)
    {
        pre=edge1.pre;
        next=edge1.next;
        length=edge1.length;
        thiefnumber=edge1.thiefnumber;
        if(!thiefs.empty())
            thiefs.clear();
        for(int i=0; i<thiefnumber; i++)
        {
            thiefs.push_back(edge1.thiefs[i]);
        }
        return *this;
    }
    ~edge()
    {
        //cout<<"edge destroyed"<<endl;
    }
};
class vertex
{
public:
    int city;
    int jeweler;
    vector<int> jewelers;
    vector<edge> edges;
    vertex()
    {
        city=0;
        jeweler=0;
        jewelers.push_back(0);
    }
    vertex(int c,int j)
    {
        city=c;
        jeweler=j;
    }
    vertex(int c,int j,vector<int> je)
    {
        city=c;
        jeweler=j;
        for(int i=0; i<jeweler; i++)
        {
            jewelers.push_back(je[i]);
        }

    }
    vertex(const vertex &vertex1)
    {
        city=vertex1.city;
        jeweler=vertex1.jeweler;
        if(!jewelers.empty())
            jewelers.clear();
        for(int i=0; i<jeweler; i++)
        {
            jewelers.push_back(vertex1.jewelers[i]);
        }
    }

    vertex& operator=(const vertex& vertex1)
    {
        city=vertex1.city;
        jeweler=vertex1.jeweler;
        if(!jewelers.empty())
            jewelers.clear();
        for(int i=0; i<jeweler; i++)
        {
            jewelers.push_back(vertex1.jewelers[i]);
        }
        return *this;
    }
    ~vertex()
    {
        //cout<<"vertex destroyed"<<endl;
    }
};
