
    #include "Listel.h"
    template <typename type>
    ListElem<type>::ListElem(type data)
    {
        this -> data = data;
        this -> prev = nullptr;
        this -> next = nullptr;
    }
    template <typename type>
    ListElem<type>::ListElem(ListElem<type>* const & obj)
    {
        this -> data = obj -> data;
        this -> next = nullptr;
        this -> prev = nullptr;
    }
    template <typename type>
    ListElem<type>* ListElem<type>::getNext() const
    {
        return this -> next;
    }
    template <typename type>
    const type& ListElem<type>::getData() const
    {
        return this -> data;
    }

    template <typename type>
    myIterator<type>::myIterator() : p(nullptr) {}
    template <typename type>
    myIterator<type>::myIterator(ListElem<type>* el) : p(el) {
    }
    template <typename type>
    typename myIterator<type>::reference myIterator<type>::operator*() const 
    {
        if(p == nullptr)
        throw std::runtime_error("List is empty");
        return p -> data;
    }
    template <typename type>
    myIterator<type>& myIterator<type>::operator++() 
    {
        if(p == nullptr)
        throw std::runtime_error("List is empty");
        p = p -> next;
        return *this;
    }
    template <typename type>
    myIterator<type> myIterator<type>::operator++(int) 
    {
        if(p == nullptr)
        throw std::runtime_error("List is empty");
        myIterator resp = *this;
        p = p->next;
        return resp;
    }
    template <typename type>
    bool myIterator<type>::operator==(const myIterator<type>& it) const {
        return p == it.p;
    }
    template <typename type>
    bool myIterator<type>::operator!=(const myIterator<type>& it) const {
        return !(*this == it);
    }
    template class ListElem<int>;
    template class ListElem<std::string>;
    template class myIterator<int>;
    template class myIterator<std::string>;