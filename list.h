#ifndef LIST_H
#define LIST_H
#include "Listel.h"
template<typename T>
class Container
{
public:
    virtual ~Container() {};
    virtual void insert(const T& value) = 0;
    virtual void remove(const T& value) = 0;
    virtual bool exists(const T& value) const = 0;
};

template <typename type>
class List : public Container<type>
{
private:
    friend class ListElem<type>;
    ListElem<type>* head = nullptr;
    ListElem<type>* tail = nullptr;
    using iterator = myIterator<type>;
public:
    void insert(const type& data);
    void remove(const type& data);
    bool exists(const type& data) const;
    List(List const & a);
    void operator=(List const & a);
    List();
    ~List();
    myIterator<type> begin();
    myIterator<type> end();
};
#endif