
#include "list.h"
    template <typename type>
    myIterator<type> List<type>::begin()
    {
        return myIterator<type>(this -> head);
    }
    template <typename type>
    myIterator<type> List<type>::end()
    {
        return myIterator<type>(nullptr);
    }
    template <typename type>
    List<type>::List() 
    {
        this -> head = nullptr;
    }
    template <typename type>
    List<type>::List(List<type> const & obj)
    {
        this -> tail = new ListElem<type>(obj.head);
        ListElem<type>*&  temp1 = this -> tail;
        ListElem<type>* temp2 = obj.head;
        while(temp2 -> next != nullptr)
        {
            temp2 = temp2 -> next;
            temp1 -> next = new ListElem<type>(temp2);
            temp1 -> next -> prev = temp1;
            temp1 = temp1 -> next;
        }
         ListElem<type>* temp3 = this -> tail;
         while(temp3 -> prev != nullptr)
         temp3 = temp3 -> prev;
         this -> head = temp3;
         this -> head -> next = temp3 -> next;
    }
    template <typename type>
    void List<type>::operator=(List<type> const & obj)
    {
        if(this -> head != nullptr)
        {
            if(this -> head == obj.head && this -> tail == obj.tail)
            return;
        this ->~List();
        }
         this -> tail = new ListElem<type>(obj.head);
        ListElem<type>*&  temp1 = this -> tail;
        ListElem<type>* temp2 = obj.head;
        while(temp2 -> next != nullptr)
        {
            temp2 = temp2 -> next;
            temp1 -> next = new ListElem<type>(temp2);
            temp1 -> next -> prev = temp1;
            temp1 = temp1 -> next;
        }
         ListElem<type>* temp3 = this -> tail;
         while(temp3 -> prev != nullptr)
         temp3 = temp3 -> prev;
         this -> head = temp3;
         this -> head -> next = temp3 -> next;
       
    }
    template <typename type>
    List<type>::~List()
    {
        if(this -> head != nullptr)
        {
        ListElem<type>* temp1 = this -> head;
        ListElem<type>* temp2;
        while(temp1 != this -> tail)
        {
            temp2 = temp1; 
            temp1 = temp1 -> next;
            delete temp2;
        }
        delete temp1;
        }
    }
    template <typename type>
    void List<type>::insert(const type& data)
    {
        if(this -> head == nullptr)
        {
            this -> head = new ListElem<type>(data);
            this -> tail = this -> head;
        }
        else
        {
            ListElem<type>* temp = this -> tail;
            this -> tail = new ListElem<type>(data);
            this -> tail -> next = nullptr;
            this -> tail -> prev = temp;
            temp -> next = this -> tail;
            int a =2*2;
        }
    }

    template <typename type>
    void List<type>::remove(const type& data)
    {
        ListElem<type>* temp = this -> head;
        if(this -> head == nullptr)
        return;
        while(temp -> data != data)
        {
            temp = temp -> next;
            if(temp == nullptr)
            return;
        }
        if(temp == this -> head)
        {
            temp = this -> head -> next;
            temp -> prev == nullptr;
            delete this -> head;
            this -> head = temp;
            return;
        }
        if(temp -> next == nullptr)
        {
            this -> tail = temp -> prev;
            temp -> prev -> next = this -> tail;
            delete temp;
        }
        else
        {
        ListElem<type>* swap = temp -> next;
        temp -> prev -> next = swap;
        swap -> prev = temp -> prev;
        delete temp;
        }
    }
    template <typename type>
    bool List<type>::exists(const type& data) const
    {
        ListElem<type>* temp = this -> head;
        if(temp == nullptr)
        {
            return false;
        }
        while(temp -> getData() != data)
        {
            if(temp -> getNext() == nullptr)
            return false;
            temp = temp -> getNext();
        }
        return true;
    }
    template class List<int>;
    template class List<std::string>;
