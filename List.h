//
// Created by tanzilya on 26.05.2021.
//

#ifndef WAREHOUSESTRUCTUREONLISTS_LIST_H
#define WAREHOUSESTRUCTUREONLISTS_LIST_H
#include <iostream>
#include <memory>

template<typename value_type> struct node {
    struct node *next;
    value_type *content;
};

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

    ~list(){
        erase(begin(), end());
        _ptr_alloc.deallocate(_head, 1);
    };


        iterator 		begin() { return iterator(this->_head->next); };
        iterator 		end() { return iterator(nullptr); };

        bool empty() const {return _size == 0;};

        size_type size() const { return _size;};

        void push_front(const value_type &val){
            t_node *newNode = addNode();
            newNode->next = _head;
            fillContent(newNode, val, nullptr);
            _head = newNode;
            _size++;
        };

        void push_back (const value_type& val){
            t_node *newNode = addNode();
            _tail->next = newNode;
            fillContent(newNode, val, nullptr);
            _tail = newNode;
            this->_size++;
        };

        iterator insert(iterator position, const value_type &val){
            iterator t = this->begin();
            if (position != end()) {
                while (t != position && t != this->end()) t++;
                if (t == this->end() && _size != 0){
                    *position = val;
                    return position;
                }
            }
            t_node *newNode = addNode();
            t_node *nextNode = t.getNext();
            fillContent(newNode, val, nextNode);
            t.getNode()->next = newNode;
            _size++;
            return iterator(newNode);
        };

        iterator erase(iterator position){
            iterator tmp = this->begin();
            while (tmp != position && tmp != this->end())
                tmp++;
            if (tmp == this->end())
                return position;
            iterator t = tmp; ++tmp;
            deleteNode(t.getNode());
            _size--;
            return tmp;
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

            value_type &operator*(){return *this->_node->content;}
            value_type *operator->(){return this->_node->content;}
            node<value_type> *getNode() const {return this->_node;}
            node<value_type> *getNext() const {return this->_node->next;}
        };

private:
        typedef node<value_type> t_node;
        t_node *_head;
        t_node *_tail;
        size_type _size;

        typedef typename allocator_type::template rebind<node<value_type> >::other PtrAllocator;

        allocator_type _alloc;
        PtrAllocator _ptr_alloc;

        t_node *addNode() {
            t_node *node = _ptr_alloc.allocate(1);
            node->content = _alloc.allocate(1);
            return node;
        }

        void fillContent(t_node *node, value_type const & value, t_node *next) {
            node->next = next;
            _alloc.construct(node->content, value);
        }

        void deleteNode(t_node *node) {
            _alloc.destroy(node->content);
            _alloc.deallocate(node->content, 1);
            _ptr_alloc.deallocate(node, 1);
        }

        void createAbstractNode() {
            _head = _ptr_alloc.allocate(1);
            _head->content = nullptr;
            _head->next = nullptr;
            _tail = _head;
        }
};

#endif //WAREHOUSESTRUCTUREONLISTS_LIST_H
