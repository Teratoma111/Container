
#ifndef LISTEL_H
#define LISTEL_H
using namespace std;
#include <stdexcept>
template <typename type>
class ListElem
{
    public:
    ListElem* next;
    ListElem* prev;
    type data;
    
    ListElem(type data);
   
    ListElem(ListElem* const & obj);

    ListElem* getNext() const;
    const type& getData() const;
};
template<typename type>
class myIterator 
{
    private:
    ListElem<type> *p;
    public:
    friend class ListElem<type>;
    using iterator_category = std::forward_iterator_tag;
    using value_type = type;
    using pointer = type*;
    using reference = type&;
    using difference_type = std::ptrdiff_t;
    reference operator*() const;
    myIterator();
    myIterator(ListElem<type>* el);
    myIterator& operator++();

    myIterator operator++(int);

    bool operator==(const myIterator& it) const;
    bool operator!=(const myIterator& it) const;
};
#endif