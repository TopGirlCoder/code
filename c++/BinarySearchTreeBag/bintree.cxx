// FILE: bintree.template
// IMPLEMENTS: The binary_tree node class (see bintree.h for documentation). 
#include <cassert>    // Provides assert
#include <cstdlib>   // Provides NULL, std::size_t
#include <iomanip>    // Provides std::setw
#include <iostream>   // Provides std::cout

namespace hw5
{
    template <class Process, class BTNode>
    void inorder(Process f, BTNode* node_ptr)
    // Library facilities used: cstdlib
    {
        if (node_ptr != NULL)
        {
            inorder(f, node_ptr->left( ));
            f( node_ptr->data( ) );
            inorder(f, node_ptr->right( ));
        }
    }

    template <class Process, class BTNode>
    void postorder(Process f, BTNode* node_ptr)
    // Library facilities used: cstdlib
    {
        if (node_ptr != NULL)
        {
            postorder(f, node_ptr->left( ));
            postorder(f, node_ptr->right( ));
            f(node_ptr->data( ));
        }
    }

    template <class Process, class BTNode>
    void preorder(Process f, BTNode* node_ptr)
    // Library facilities used: cstdlib
    {
        if (node_ptr != NULL)
        {
            f( node_ptr->data( ) );
            preorder(f, node_ptr->left( ));
            preorder(f, node_ptr->right( ));
        }
    }

    template <class ItemType, class SizeType>
    void print(binary_tree_node<ItemType>* node_ptr, SizeType depth)
    // Library facilities used: iomanip, iostream, stdlib
    {
        if (node_ptr != NULL)
        {
            print(node_ptr->right( ), depth+1);
            std::cout << std::setw(4*depth) << ""; // Indent 4*depth spaces.
            std::cout << node_ptr->data( ) << std::endl;
            print(node_ptr->left( ),  depth+1);
        }
    }    
	
    template <class ItemType>
    void tree_clear(binary_tree_node<ItemType>*& root_ptr)
    // Library facilities used: cstdlib
    {
	binary_tree_node<ItemType>* child;
	if (root_ptr != NULL)
	{
	    child = root_ptr->left( );
	    tree_clear( child );
	    child = root_ptr->right( );
	    tree_clear( child );
	    delete root_ptr;
	    root_ptr = NULL;
	}
    }

    template <class ItemType>
    binary_tree_node<ItemType>* tree_copy(const binary_tree_node<ItemType>* root_ptr)
    // Library facilities used: cstdlib
    {
	binary_tree_node<ItemType> *l_ptr;
	binary_tree_node<ItemType> *r_ptr;

	if (root_ptr == NULL)
	    return NULL;
	else
	{
	    l_ptr = tree_copy( root_ptr->left( ) );
	    r_ptr = tree_copy( root_ptr->right( ) );
	    return
		new binary_tree_node<ItemType>( root_ptr->data( ), l_ptr, r_ptr);
	}
    }

    template <class ItemType>
    typename binary_tree_node<ItemType>::size_type tree_size(const binary_tree_node<ItemType>* node_ptr)
    // Library facilities used: cstdlib
    {
        if (node_ptr == NULL)
            return 0;
        else 
            return 
	    1 + tree_size(node_ptr->left( )) + tree_size(node_ptr->right( ));
    }    
}
