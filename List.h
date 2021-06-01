//
// Created by tanzilya on 26.05.2021.
//

#ifndef WAREHOUSESTRUCTUREONLISTS_LIST_H
#define WAREHOUSESTRUCTUREONLISTS_LIST_H
#include <iostream>
#include <memory>

template<typename value_type> struct node {
    struct node *prev;
    struct node *next;
    value_type *content;
};

template<bool Cond, class T = void> struct enable_if {};

template<class T> struct enable_if<true, T> { typedef T type; };

template<class T, class Alloc = std::allocator<T> >

class list {
public:

    typedef T 											value_type;
    typedef Alloc 										allocator_type;
    typedef size_t 										size_type;
    class 												iterator;

    explicit list(const allocator_type &alloc = allocator_type()) : _alloc(alloc), _size(0){
        createAbstractNode();
    };

    list(const list &x) : _size(0){
        createAbstractNode();
        *this = x;
    };

    ~list(){
        clearList();
        _ptr_alloc.deallocate(_abstractNode, 1);
    };

    list &operator=(const list &x){
        if (this != &x){
            clearList();
            _size = 0;
            iterator i = x.begin();
            while (_size != x.size()) {
                push_back(*i);
                i++;
            }
        }
        return *this;
    }

        iterator 		begin() { return iterator(this->_abstractNode->next); };
        iterator 		end() { return iterator(this->_abstractNode); };

        bool empty() const {return _size == 0;};

        size_type size() const { return _size;};

        void push_front(const value_type &val){
            t_node *tmp = _abstractNode->next;
            t_node *newNode = addNode();
            _abstractNode->next = newNode;
            tmp->prev = newNode;
            fillContent(newNode, val, tmp, _abstractNode);
            _size++;
        };

        void pop_front(){
            t_node *oldBegin = this->begin().getNode();
            t_node *newBegin = oldBegin->next;
            _abstractNode->next = newBegin;
            newBegin->prev = _abstractNode;
            deleteNode(oldBegin);
            _size--;
        };

        void push_back (const value_type& val){
            t_node *tmp = _abstractNode->prev;
            t_node *newNode = addNode();
            _abstractNode->prev = newNode;
            tmp->next = newNode;
            fillContent(newNode, val, _abstractNode, tmp);
            this->_size++;
        };

        iterator insert(iterator position, const value_type &val){
            iterator tmp = position;
            if (position != end()) {
                iterator tmp = this->begin();
                while (tmp != position && tmp != this->end()) tmp++;
                if (tmp == this->end() && _size != 0){
                    *position = val;
                    return position;
                }
            }
            t_node *newNode = addNode();
            t_node *nextNode = tmp.getNode();
            t_node *prevNode = nextNode->prev;
            nextNode->prev = newNode;
            prevNode->next = newNode;
            fillContent(newNode, val, nextNode, prevNode);
            _size++;
            return iterator(newNode);
        };

        template<class iterator>
        void insert(iterator position, iterator first, iterator last,
                    typename enable_if<std::__is_input_iterator<iterator>::value>::type* = 0){
            iterator tmp = position;
            while (first != last) {
                tmp = insert(tmp, *first++);
                tmp++;
            }
        };

        iterator erase(iterator position){
            iterator tmp = this->begin();
            while (tmp != position && tmp != this->end())
                tmp++;
            if (tmp == this->end())
                return position;
            t_node *prevNode = tmp.getNode()->prev;
            t_node *nextNode = prevNode->next->next;
            prevNode->next = nextNode;
            nextNode->prev = prevNode;
            deleteNode(tmp.getNode());
            _size--;
            return iterator(nextNode);
        };

        iterator erase(iterator first, iterator last){
            iterator tmp = first;
            iterator i;
            if (tmp == last) return (iterator(tmp));
            while (tmp != last){
                i = erase(tmp);
                tmp++;
            }
            return i;
        };

        void swap(list &x){
            t_node *tmp = x._abstractNode;
            x._abstractNode = this->_abstractNode;
            this->_abstractNode = tmp;

            size_type size = x._size;
            x._size = _size;
            _size = size;
        };

        void clear(){
            clearList();
        };

        void remove(const value_type &val){
            for (iterator i = this->begin(); i != this->end();){
                if (*i == val) i = erase(i);
                else ++i;
            }
        };

        void sort(){
            sort(_ascedingOrder());
        };

        template<class Compare>
        void sort(Compare comp){
            mergeSort(&(_abstractNode->next));
            connectionsRecovery();
        };

        iterator find(value_type toFind) {
            for (iterator i = begin(); i != end(); ++i)
                if (*i == toFind) return i;
            return end();
        }

        class iterator {
        private:
            node<value_type> *_node;
        public:
            iterator(){ _node = nullptr; }

            iterator &operator=(iterator const &iterator1){
                if (this != &iterator1)
                    _node = iterator1._node;
                return *this;
            }

            iterator(iterator &iterator1){*this = iterator1;}
            iterator(const iterator &iterator1){*this = iterator1;}
            iterator(node<value_type> *el){ _node = el;};

            ~iterator() {};

            bool operator==(iterator const &iterator) const {return iterator.getNode() == this->_node;}
            bool operator!=(iterator const &iterator) const {return iterator.getNode() != this->_node;}

            virtual iterator &operator++(){ //pref
                _node = _node->next;
                return *this;
            }

            virtual iterator operator++(int){ //post
                iterator tmp(*this);
                _node = _node->next;
                return tmp;
            }

            virtual iterator &operator--(){ //pref
                _node = _node->prev;
                return *this;
            }

            virtual iterator operator--(int){ //post
                iterator tmp(*this);
                _node = _node->prev;
                return tmp;
            }

            value_type &operator*(){return *this->_node->content;}
            value_type *operator->(){return this->_node->content;}
            node<value_type> *getNode() const {return this->_node;}
        };

private:
        typedef node<value_type> t_node;
        t_node *_abstractNode;
        size_type _size;

        typedef typename allocator_type::template rebind<node<value_type> >::other PtrAllocator;

        allocator_type _alloc;
        PtrAllocator _ptr_alloc;

        t_node *addNode() {
            t_node *node = _ptr_alloc.allocate(1);
            node->content = _alloc.allocate(1);
            return node;
        }

        void fillContent(t_node *node, value_type const & value, t_node *next, t_node *prev) {
            node->next = next;
            node->prev = prev;
            _alloc.construct(node->content, value);
        }

        void deleteNode(t_node *node) {
            _alloc.destroy(node->content);
            _alloc.deallocate(node->content, 1);
            _ptr_alloc.deallocate(node, 1);
        }

        void clearList() {
            erase(begin(), end());
            _abstractNode->next = _abstractNode;
            _abstractNode->prev = _abstractNode;
        }

        void createAbstractNode() {
            _abstractNode = _ptr_alloc.allocate(1);
            _abstractNode->content = nullptr;
            _abstractNode->next = _abstractNode;
            _abstractNode->prev = _abstractNode;
        }

        struct _ascedingOrder {
            bool operator()(value_type const &first, value_type const &second) { return first < second; }
        };

        void mergeSort(t_node **begin) {
            t_node *head = *begin;
            t_node *a;
            t_node *b;

            if (head == _abstractNode || head->next == _abstractNode)
                return;
            nodeSplit(head, &a, &b);
            mergeSort(&a);
            mergeSort(&b);
            *begin = sortedMerge(a, b);
        }

        t_node *sortedMerge(t_node *a, t_node *b){
            t_node *res = _abstractNode;

            if (a == _abstractNode) return b;
            else if (b == _abstractNode) return a;

            if (*(a->content) <= *(b->content)){
                res = a;
                res->next = sortedMerge(a->next, b);
            }
            else {
                res = b;
                res->next = sortedMerge(a, b->next);
            }
            return res;
        }

        void nodeSplit(t_node *src, t_node **front, t_node **back){
            t_node *fast;
            t_node *slow;
            slow = src;
            fast = src->next;

            while (fast != _abstractNode) {
                fast = fast->next;
                if (fast != _abstractNode) {
                    slow = slow->next;
                    fast = fast->next;
                }
            }
            *front = src;
            *back = slow->next;
            slow->next = _abstractNode;
        }

        void connectionsRecovery(){
            t_node *tmp = _abstractNode->next;
            t_node *prevNode = _abstractNode;

            while (tmp != _abstractNode){
                tmp->prev = prevNode;
                prevNode = tmp;
                tmp = tmp->next;
            }
            _abstractNode->prev = prevNode;
        };
    };

    template <class T, class Alloc>
    bool operator==(const list<T,Alloc>& lhs, const list<T,Alloc>& rhs) {
        typename list<T, Alloc>::iterator it = rhs.begin();
        typename list<T, Alloc>::iterator i = lhs.begin();
        if (lhs.size() == rhs.size() && lhs.size() == 0)
            return true;
        if (lhs.size() == rhs.size()) {
            for (; i != lhs.end() && it != rhs.end(); ++i)
                if (*i != *it++)
                    return false;
            return true;
        }
        return false;
    }

    template <class T, class Alloc>
    bool operator!=(const list<T,Alloc>& lhs, const list<T,Alloc>& rhs) { return !(lhs == rhs); }

    template <class T, class Alloc>
    bool operator<  (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs) {
        typename list<T, Alloc>::iterator it = rhs.begin();
        typename list<T, Alloc>::iterator i = lhs.begin();
        typename list<T, Alloc>::iterator ite = rhs.end();
        typename list<T, Alloc>::iterator ie = lhs.end();

        if (lhs.size() == rhs.size() && lhs.size() == 0) return false;
        while (it != ite && i != ie)
            if (*i++ < *it++) return true;
        if (rhs.size() != lhs.size()) return lhs.size() < rhs.size();
        return false;
    }

    template <class T, class Alloc>
    bool operator<=(const list<T,Alloc>& lhs, const list<T,Alloc>& rhs) { return (!(rhs < lhs)); }
    template <class T, class Alloc>
    bool operator>(const list<T,Alloc>& lhs, const list<T,Alloc>& rhs) { return (rhs < lhs); }
    template <class T, class Alloc>
    bool operator>=(const list<T,Alloc>& lhs, const list<T,Alloc>& rhs) { return (!(lhs < rhs)); }

    template <class T, class Alloc> void swap(list<T,Alloc>& x, list<T,Alloc>& y) { x.swap(y);};

#endif //WAREHOUSESTRUCTUREONLISTS_LIST_H
