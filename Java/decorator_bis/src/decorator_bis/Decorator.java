package decorator_bis;

import java.util.List;

public abstract class Decorator<T> implements List<T> {
	List<T> list;
	
	public Decorator(List<T> list) {
		this.list = list;
	}
}
