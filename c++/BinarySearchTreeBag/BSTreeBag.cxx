// FILE: BSTreeBag.cxx 
// IMPLEMENTS: The binary_tree node class (see bintree.h for documentation). 
#include <cassert>    // Provides assert
#include <cstdlib>   // Provides NULL, std::size_t
#include <iomanip>    // Provides std::setw
#include <iostream>   // Provides std::cout

namespace hw5
{
	template <class ItemType>
	BSTreeBag<ItemType>::BSTreeBag()
	{
		root_ptr = NULL;
	}
	
	template <class ItemType>
	BSTreeBag<ItemType>::BSTreeBag(const BSTreeBag& source)
	{
		root_ptr = tree_copy(source.root_ptr);
	}
	
	template <class ItemType>
	BSTreeBag<ItemType>::~BSTreeBag()
	{
		tree_clear(root_ptr);
	}
	
	template <class ItemType>
    void BSTreeBag<ItemType>::operator =(const BSTreeBag& source)
    {
		if (root_ptr == source.root_ptr)
			return;
		tree_clear(root_ptr);
		root_ptr = tree_copy(source.root_ptr);
	}

	template <class ItemType>
    typename BSTreeBag<ItemType>::size_type BSTreeBag<ItemType>::erase(const ItemType& target)
    {
		return bst_remove_all(root_ptr, target);
	}
	
	template <class ItemType>
    bool BSTreeBag<ItemType>::erase_one(const ItemType& target)
    {
		return bst_remove(root_ptr, target); 
	}
	
	template <class ItemType>
    void BSTreeBag<ItemType>::insert(const ItemType& entry)
    {
		binary_tree_node<ItemType>* cursor;
		
		bool done = false;
		
		if (root_ptr == NULL){
			root_ptr = new binary_tree_node<ItemType>(entry);
			done = true;
		}
		else{
			cursor = root_ptr;
			while (!done){
				if(cursor->data() >= entry){
					if(cursor->left() == NULL){
						cursor->left() = new binary_tree_node<ItemType>(entry);
						done = true;
					}
					else cursor = cursor->left();
				}
				else{
					if(cursor->right() == NULL){
						cursor->right() = new binary_tree_node<ItemType>(entry);
						done = true;
					}
					else cursor = cursor->right();
				}
			}
		}	
	}		
	
	template <class ItemType>
    void BSTreeBag<ItemType>::operator +=(const BSTreeBag& addend)
    {
		if (root_ptr == addend.root_ptr)
		{
			BSTreeBag<ItemType> copy = addend;
			insert_all(copy.root_ptr);
		}
		else insert_all(addend.root_ptr);	
	}

    template <class ItemType>
    BSTreeBag<ItemType> operator +(const BSTreeBag<ItemType>& b1, const BSTreeBag<ItemType>& b2)
	{
		BSTreeBag<ItemType> answer = b1;
		answer += b2;
		return answer;
	}	
	
	template <class ItemType>
    void BSTreeBag<ItemType>::insert_all(binary_tree_node<ItemType>* addroot_ptr)
    {
		if (addroot_ptr != NULL)
		{
			insert(addroot_ptr->data());
			insert_all(addroot_ptr->left());	
			insert_all(addroot_ptr->right());
		}
	}

	template <class ItemType>
    typename BSTreeBag<ItemType>::size_type BSTreeBag<ItemType>::size( ) const
    {
		return tree_size(root_ptr); 
	}
	
	template <class ItemType>
    typename BSTreeBag<ItemType>::size_type BSTreeBag<ItemType>::count(const ItemType& target) const
    {
		binary_tree_node<ItemType>* cursor;
		cursor = root_ptr;
		
		size_type count = 0;
		while (cursor != NULL)
		{
			if (cursor->data() >= target)
			{
				if (cursor->data() == target)
					count ++;
				cursor = cursor->left();
			}
			else
			{
				cursor = cursor->right();
			}
		}
		return count;
	}
	
	template <class ItemType>
	void bst_remove_max(binary_tree_node<ItemType>*& root_ptr, ItemType& removed)
	{
		if (root_ptr->right() == NULL)
		{
			removed = root_ptr->data();
			binary_tree_node<ItemType>* old_root_ptr = root_ptr;
			root_ptr = root_ptr->left();
			delete old_root_ptr;
			old_root_ptr = NULL;
		}
		else
			bst_remove_max(root_ptr->right(), removed);
		
	}
	
	template <class ItemType>
	bool bst_remove(binary_tree_node<ItemType>*& root_ptr, const ItemType& target)
	{
		binary_tree_node<ItemType>* old_root_ptr;
		if (root_ptr == NULL)
		{
			return false;
		}
		if (target < root_ptr->data())
		{
			return bst_remove(root_ptr->left(), target);
		}
		if (target > root_ptr->data())
		{
			return bst_remove(root_ptr->right(), target);
		}
			
		if (root_ptr->left() == NULL)
		{
			binary_tree_node<ItemType>* old_root_ptr = root_ptr;
			root_ptr = root_ptr->right();
			delete old_root_ptr;
			old_root_ptr = NULL;
			return true;	
		}
		bst_remove_max(root_ptr->left(), root_ptr->data());
		return true;
	}
	
	template <class ItemType>
	typename BSTreeBag<ItemType>::size_type bst_remove_all(binary_tree_node<ItemType>*& root_ptr, const ItemType& target)
	{		
		if (root_ptr == NULL)  
	        return 0;
	    if (target < root_ptr->data( ))
	        bst_remove_all(root_ptr->left(), target);
	    if (target > root_ptr->data( ))  
	        bst_remove_all(root_ptr->right(), target);
	    if (root_ptr->left( ) == NULL)
	    {  
			binary_tree_node<ItemType>* old_root_ptr = root_ptr;
			root_ptr = root_ptr->right();
			delete old_root_ptr;
			old_root_ptr = NULL;
			return 1;	
	    }
	    bst_remove_max(root_ptr->left(), root_ptr->data());
	    return 1 + bst_remove_all(root_ptr, target);
	}
}


	
	

	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
