//File name: ArrayBag.java
//Name: girlrobot
//Assignment: HW 2, Bag Array
//Due date: September 23, 2013

import java.util.*; // to use the class Arrays, * avail to all files

public class ArrayBag<ItemType> implements BagInterface<ItemType>
{
	private ItemType[] itemArray;   // itemArray must not be final 
									//if going to resize
	private static final int DEFAULT_CAPACITY = 4;
	private int myCapacity; //added a variable to track changing capacity
	private int numberOfItems;
	
	// Constructor; creates a bag with an empty Item array
	public ArrayBag()
	{
		this(DEFAULT_CAPACITY);
	}
	
	// Extra constructor; creates and initializes an empty Bag
	public ArrayBag(int capacity)
	{
		myCapacity = capacity;
		numberOfItems = 0; 
		@SuppressWarnings("unchecked") // says don't pick on me for casting types
		ItemType [] tempBag = (ItemType []) new Object[capacity]; 
		// ( ) says doesn't look like an item type but it is
		itemArray = tempBag;		
		
	}
	
	// Extra constructor; creates a bag by copy
	public ArrayBag(ArrayBag anotherBag)
	{	 
		@SuppressWarnings("unchecked")
		ItemType [] tempBag = (ItemType []) new Object[anotherBag.getCapacity()]; 
		myCapacity = anotherBag.getCapacity();
		itemArray = tempBag;
		
		numberOfItems = anotherBag.numberOfItems;	
		for (int index = 0; index < anotherBag.numberOfItems; ++index)
		{
			@SuppressWarnings("unchecked")
			ItemType movingItem = (ItemType) anotherBag.itemArray[index];	
			itemArray[index] = movingItem;
		}
			
	}
	
	// Return the number of Items being stored in the Bag
	public int getCurrentSize()
	{
		return numberOfItems;		
	}

	// Return the capacity of the bag (the maximum Items it can store) 
	public int getCapacity()
	{
		return myCapacity;
		
	}

	//Resizes the bag's capacity to newCapacity
	//if the new size is larger, copy all bag contents
	//else, do nothing
	public void resize(int newCapacity)
	{
		if (myCapacity > newCapacity)
		{	
			return;
		}		
		else
		{	
			itemArray = Arrays.copyOf(itemArray, newCapacity);
			myCapacity = newCapacity;
		}	
	}

	// Report whether the Bag is empty
	// Return true if the Bag is empty (storing no Items);
	// Return false if Items exist in the Bag
	public boolean isEmpty()
	{		
		return numberOfItems == 0;
	}
	
	// Report whether the Bag is full
	// Return true if the Bag is filled to capacity
	// Return false if there is still room
	public boolean isFull()
	{
		if (myCapacity == numberOfItems)
		{
			return true;
		}	
		return false;		
	}
	
	// Give the Bag a new Item to store
	// If Bag is full, double size and add
	// Else, Bag must add this Item to its Item array and update its numberOfItems
	// If Bag is full after this, return true; else return false
	public boolean add(ItemType newItem)
	{
		if (isFull())
		{
			resize(2 * myCapacity);
			itemArray[numberOfItems] = newItem;
			numberOfItems++;
			return true;
		}	
		else
		{
			itemArray[numberOfItems] = newItem;
			numberOfItems++;
			if (isFull())
			{
				return true;
			}
			else
			{
				return false;
			}	
		}
	}
	
	// Make the Bag act like an empty Bag again
	public void clear() 
	{
		for (int index = 0; index < numberOfItems; index++)
			itemArray[index] = null;
		numberOfItems = 0;	
	}
	
	// Check how many times an Item is in the Bag
	// return 0 if it's not there; otherwise,
	// return the number of times it occurs
	public boolean remove(ItemType anItem)
	{
		int k = 0;
		while (k < numberOfItems)
		{
			if (itemArray[k].equals(anItem))
			{
				if (k < numberOfItems)
				{	
					itemArray[k] = itemArray[numberOfItems-1];
					itemArray[numberOfItems-1] = null;
					numberOfItems--;
					return true;
				}	
			}
			k++;
		}
		return false;
	}
	
	// Check if an Item is in the Bag
	// Return true if it is in the Bag, and false if not
	public boolean contains(ItemType anItem)
	{
		if (isEmpty()) return false;
		else
		{
			int k = 0;
			while (k < numberOfItems)
			{
				if (itemArray[k] == anItem)
					return true;
				k++;
			}
		}
		return false; 	
	}
	
	// Check how many times an Item is in the Bag
	// return 0 if it's not there; otherwise,
	// return the number of times it occurs
	public int getFrequencyOf(ItemType anItem)
	{
		int counter = 0;
		for (int index = 0; index < numberOfItems; index++)
		{
			if (itemArray[index].equals(anItem))
			{
				counter++;
			}
		}
		return counter;		
	}
	
	// Make an output vector of Items from the bag (for checking)
	public ItemType[] toArray()
	{
		@SuppressWarnings("unchecked")
		ItemType[] result = (ItemType[]) new Object[numberOfItems];
		for (int index = 0; index < numberOfItems; index++)
			result[index] = itemArray[index];
		return result;
	}
	
}