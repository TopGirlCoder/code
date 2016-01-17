// Tanya Lindermeier
//FILE: BSTreeBag6.h (part of the namespace main_savitch_10)
// TEMPLATE CLASS PROVIDED: BSTreeBag<ItemType>
//     (a container template class for a collection of items)
//
// TYPEDEFS for the BSTreeBag<ItemType> class:
//   BSTreeBag<ItemType>::value_type
//     BSTreeBag<ItemType>::value_type is the data type of the items in the BSTreeBag. It may
//     be any of the C++ built-in types (int, char, etc.), or a class with a
//     default constructor, a copy constructor, an assignment operator, and a
//     less-than operator forming a strict weak ordering.
//
//   BSTreeBag<ItemType>::size_type
//     BSTreeBag<ItemType>::size_type is the data type of any variable that keeps track
//     of how many items are in a BSTreeBag.
//
// CONSTRUCTOR for the BSTreeBag<ItemType> class:
//   BSTreeBag( )
//     Postcondition: The BSTreeBag is empty.
//
// MODIFICATION MEMBER FUNCTIONS for the BSTreeBag<ItemType> class:
//   size_type erase(const ItemType& target)
//     Postcondition: All copies of target have been removed from the BSTreeBag. The
//     return value is the number of copies removed (which could be zero).
//
//   bool erase_one(const ItemType& target)
//     Postcondition: If target was in the BSTreeBag, then one copy of target has been
//     removed from the BSTreeBag; otherwise the BSTreeBag is unchanged. A true return value
//     indicates that one copy was removed; false indicates that nothing was
//     removed.
//
//   void insert(const ItemType& entry)
//     Postcondition: A new copy of entry has been inserted into the BSTreeBag.
//
//   void operator +=(const BSTreeBag& addend)
//     Postcondition: Each item in addend has been added to this BSTreeBag.
//
// CONSTANT MEMBER FUNCTIONS for the BSTreeBag<ItemType> class:
//   size_type size( ) const
//     Postcondition: Return value is the total number of items in the BSTreeBag.
//
//   size_type count(const ItemType& target) const
//     Postcondition: Return value is number of times target is in the BSTreeBag.
//
// NONMEMBER FUNCTIONS for the BSTreeBag class:
//   BSTreeBag operator +(const BSTreeBag& b1, const BSTreeBag& b2)
//     Postcondition: The BSTreeBag returned is the union of b1 and b2.
//
// VALUE SEMANTICS for the BSTreeBag class:
//   Assignments and the copy constructor may be used with BSTreeBag objects.
//
// DYNAMIC MEMORY USAGE by the BSTreeBag: 
//   If there is insufficient dynamic memory, then the following functions
//   throw bad_alloc: The constructors, insert, operator +=, operator +, and
//   the assignment operator.

#ifndef BAG6_H 
#define BAG6_H
#include <cstdlib>     // Provides NULL and size_t
#include "bintree.h"   // Provides binary_tree_node and related functions

namespace hw5
{
    template <class ItemType>
    class BSTreeBag
    {
    public:
        // TYPEDEFS
		typedef unsigned int size_type;
        typedef ItemType value_type;
        // CONSTRUCTORS and DESTRUCTOR
        BSTreeBag( );
        BSTreeBag(const BSTreeBag& source);
        ~BSTreeBag( );	
        // MODIFICATION functions
        size_type erase(const ItemType& target);
        bool erase_one(const ItemType& target);
        void insert(const ItemType& entry);
        void operator +=(const BSTreeBag& addend);
        void operator =(const BSTreeBag& source);	
        // CONSTANT functions
        size_type size( ) const;
        size_type count(const ItemType& target) const;

    private:
        binary_tree_node<ItemType> *root_ptr; // Root pointer of binary search tree
        void insert_all(binary_tree_node<ItemType>* addroot_ptr);
        //HELPER functions
        //bool bst_remove(binary_tree_node<ItemType>*& root_ptr, const ItemType& target);
        //size_type bst_remove_all(binary_tree_node<ItemType>*& root_ptr, const ItemType& target);
        //void bst_remove_max(binary_tree_node<ItemType>*& root_ptr, ItemType& removed);
    };

    // NONMEMBER functions for the BSTreeBag<ItemType> template class
    template <class ItemType>
    BSTreeBag<ItemType> operator +(const BSTreeBag<ItemType>& b1, const BSTreeBag<ItemType>& b2);
}

#include "BSTreeBag.cxx" // Include the implementation.
#endif
