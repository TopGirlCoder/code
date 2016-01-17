public class ArrayBagTester2
{
	public static void main(String[] args)
	{
		// here we call the ArrayBag constructor; this particular bag stores strings 
		BagInterface<String> aBag = new ArrayBag<String>();
		
		// here we call the isEmpty function on a new ArrayBag 
		if (aBag.isEmpty())
			System.out.println("New bag is created empty; that is good");
		else
			System.out.println("New bag is created with stuff; not so good");
			
		// here we call the getCapacity function on a new ArrayBag 
		if (aBag.getCapacity() > 0)
			System.out.println("New bag is created with non-zero capacity; that is good");
		else
			System.out.println("New bag is created with zero capacity; not so good");
			
		// here we add a couple of things 
		aBag.add("tostada");
		aBag.add("tamale");
		aBag.add("taco");

		// here we check if the ArrayBag is empty
		if (aBag.isEmpty())
			System.out.println("Bag after adding thinks it is empty; that is not so good");
		else
			System.out.println("Bag after adding thinks it is not empty; that is good");
			
		// here we check if it knows its own size
		if (aBag.getCurrentSize() != 3)
			System.out.println("Bag after adding has wrong size; that is not so good");
		else
			System.out.println("Bag after adding has right size; that is good");
		
		// check if the ArrayBag can find added items
		if (aBag.contains("tamale") == false)
			System.out.println("Bag can't find added items; that is not so good");
		else
			System.out.println("Bag can find added items; that is good");
		
		// check if the ArrayBag thinks it contains items we didn't add
		if (aBag.contains("torta") == true)
			System.out.println("Bag can find items we never added; that is not so good");
		else
			System.out.println("Bag doesn't find items we never added; that is good");
			
		// here we check what happens if we ask to remove something not in the ArrayBag
		aBag.remove("torta");
		
		// here we check if the ArrayBag knows its own size after a non-event removal
		if (aBag.getCurrentSize() != 3)
			System.out.println("Bag should be the same size as before but isn't; that is not so good");
		else
			System.out.println("Bag is the same size as before; that is good");
		
		// here we remove something in the ArrayBag
		aBag.remove("tamale");
		
		// here we check if the size has changed
		if (aBag.getCurrentSize() != 2)
			System.out.println("Bag should be smaller than before but isn't; that is not so good");
		else
			System.out.println("Bag is the right size after removing one item; that is good");
		
		// empty the bag
		aBag.clear();
		
		// check the size of the empty bag
		if (aBag.getCurrentSize() != 0)
			System.out.println("Bag after clearing has wrong size; that is not so good");
		else
			System.out.println("Bag after clearing has right size; that is good");
		
		//displayBag(aBag);		
		
		int tamales = 0;
		for (int i = 0; i < aBag.getCapacity(); ++i)
		{
			aBag.add("tamale");
			++tamales;
		}
		
		if (aBag.getCurrentSize() != aBag.getCapacity())
			System.out.println("Bag after adding has wrong size; that is not so good");
		else
			System.out.println("Bag after adding has right size; that is good");
		
		//displayBag(aBag);
		
		// try adding to a full ArrayBag
		aBag.add("tamale"); ++tamales;
		
		//displayBag(aBag);
		
		// check if we can count up how often an item appears in the ArrayBag
		if (aBag.getFrequencyOf("tamale") != tamales)
			System.out.println("Bag can't count items correctly when they are present; that is not so good");
		else
			System.out.println("Bag can count items correctly when they are present; that is good");
		
		// check if we get the right answer for an item that isn't in the ArrayBag
		if (aBag.getFrequencyOf("torta") != 0)
			System.out.println("Bag can't count items correctly when they are absent; that is not so good");
		else
			System.out.println("Bag can count items correctly when they are absent; that is good");
			
		// here we call the displayBag function to display the contents of the bag
		//displayBag(aBag);
		
		// use remove to empty the Bag
		for (int i = 0; i < aBag.getCapacity(); ++i)
			aBag.remove("tamale");
			
		// here we call the displayBag function to display the contents of the bag
		//displayBag(aBag);
		
		// check that remove has left the size correct
		if (aBag.getCurrentSize() != 0)
			System.out.println("Size of bag is incorrect after removing all the items; that is not so good");
		else
			System.out.println("Size of bag after removing all the items is correct; that is good");
		//displayBag(aBag);	
	}
	private static void displayBag(BagInterface<String> aBag)
	{
		System.out.print("The bag contains the following item(s): ");
		Object[] bagArray = aBag.toArray();
		
		for (int index = 0; index < bagArray.length; index++)
		{
			System.out.print(bagArray[index] + " ");
		}
		System.out.println();
	}

}
