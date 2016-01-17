public interface BagInterface<ItemType>
{
	public int getCurrentSize();
	public int getCapacity();
	public void resize(int newCapacity);
	public boolean isFull();
	public boolean isEmpty();
	public boolean add (ItemType newItem);
	public boolean remove(ItemType anItem);
	public void clear();
	public int getFrequencyOf(ItemType anItem);
	public boolean contains(ItemType anItem);
	public ItemType[] toArray();
}