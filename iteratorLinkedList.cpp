class Node {
    public:
        int value;
        Node* next;
};

// Linked List class
class LinkedList {
    public:
        Node* root; // root node

        // Iterator class
        class iterator : public std::iterator<std::forward_iterator_tag, int> {
            public:
                friend class LinkedList; // declare Linked List class as a friend class
                Node* curr;              // the Node this iterator is pointing to

                // the following typedefs are needed for the iterator to play nicely with C++ STL
                typedef int value_type;
                typedef int& reference;
                typedef int* pointer;
                typedef int difference_type;
                typedef std::forward_iterator_tag iterator_category;

                // iterator constructor
                iterator(Node* x=0):curr(x){}
                
                // overload the == operator of the iterator class
                bool operator==(const iterator& x) const {
                    return curr == x.curr; // compare curr pointers for equality
                }

                // overload the != operator of the iterator class
                bool operator!=(const iterator& x) const {
                    return curr != x.curr; // compare curr pointers for inequality
                }

                // overload the * operator of the iterator class
                reference operator*() const {
                    return curr->value;    // return curr's value
                }

                // overload the ++ (pre-increment) operator of the iterator class
                iterator& operator++() {
                    curr = curr->next;     // move to next element
                    return *this;          // return after the move
                }

                // overload the ++ (post-increment) operator of the iterator class
                iterator operator++(int) {
                    iterator tmp(curr);    // create a temporary iterator to current element
                    curr = curr->next;     // move to next element
                    return tmp;            // return iterator to previous element
                }
        };

        // return iterator to first element
        iterator begin() {
            return iterator(root);
        }

        // return iterator to JUST AFTER the last element
        iterator end() {
            return iterator(NULL);
        }
};
