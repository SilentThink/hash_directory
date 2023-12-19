#ifndef HUSH_H
#define HUSH_H

#include <bits/stdc++.h>
using namespace std;
#include <QDebug>

template<typename T>
struct Linknode {
    T pair;
    Linknode *next;
    Linknode() { this->next = nullptr; }
    Linknode(T temp) : pair(temp), next(nullptr) {}
};

class Hush
{
    const static int p = 233, mod = 1001;

    private:
        Linknode<pair<string, string> > *head[mod];

        int hashCode(string key);

        bool findKey(string key);

    public:
        Hush();

        ~Hush();

        void insert(string key, string value);

        void deleteKey(string key);

        string find(string key);
};

#endif // HUSH_H
