package decorator_bis;

import java.util.Collection;
import java.util.Iterator;
import java.util.List;
import java.util.ListIterator;

public class MaxElementDecorator<T> extends Decorator<T> {
	private int limit = 5; 


	public MaxElementDecorator(List<T> list, final int  limit) {
		super(list);
		this.limit = limit - 1; // une liste commence à zero
	}

	@Override
	public int size() {
		return this.list.size();
	}

	@Override
	public boolean isEmpty() {
		return this.list.isEmpty();
	}

	@Override
	public boolean contains(Object o) {
		return this.list.contains(o);
	}

	@Override
	public Iterator<T> iterator() {
		return this.list.iterator();
	}

	@Override
	public Object[] toArray() {
		return this.list.toArray();
	}

	@Override
	public <E> E[] toArray(E[] a) {
		return this.list.toArray(a);
	}

	@Override
	public boolean add(T e) {
		if (this.list.size() > this.limit) 
			return false;
		return this.list.add(e);
	}

	@Override
	public boolean remove(Object o) {
		// TODO Auto-generated method stub
		return false;
	}

	@Override
	public boolean containsAll(Collection<?> c) {
		return this.list.containsAll(c);
	}

	@Override
	public boolean addAll(Collection<? extends T> c) {
		if (this.list.size() + c.size() > this.limit)
			return false;
		return this.list.addAll(c);
	}

	@Override
	public boolean addAll(int index, Collection<? extends T> c) {
		if (this.list.size() + c.size() > this.limit)
			return false;
		return this.list.addAll(c);
	}

	@Override
	public boolean removeAll(Collection<?> c) {
		return this.list.removeAll(c);
	}

	@Override
	public boolean retainAll(Collection<?> c) {
		return this.list.retainAll(c);
	}

	@Override
	public void clear() {
		this.list.clear();
	}

	@Override
	public T get(int index) {
		return this.list.get(index);
	}

	@Override
	public T set(int index, T element) {
		return this.list.set(index, element);
	}

	@Override
	public void add(int index, T element) {
		if (this.list.size() + 1 > this.limit)
			return;
		this.list.set(index, element);
	}

	@Override
	public T remove(int index) {
		return this.list.remove(index);
	}

	@Override
	public int indexOf(Object o) {
		return this.list.indexOf(o);
	}

	@Override
	public int lastIndexOf(Object o) {
		return this.list.lastIndexOf(o);
		
	}

	@Override
	public ListIterator<T> listIterator() {
		return this.list.listIterator();
	}

	@Override
	public ListIterator<T> listIterator(int index) {
		return this.list.listIterator(index);
	}

	@Override
	public List<T> subList(int fromIndex, int toIndex) {
		return this.list.subList(fromIndex, toIndex);
	}

}
