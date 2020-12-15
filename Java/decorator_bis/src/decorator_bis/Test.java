package decorator_bis;

import java.util.ArrayList;
import java.util.List;

public class Test {

	public static void main(String[] args) {
		List<Integer> list = new MaxElementDecorator<Integer>(new ArrayList<Integer>(), 4 );
		list.add(1);
		list.add(2);
		list.add(3);
		list.add(4);
		list.add(5); // not appended as intended
		list.add(6); //not added as planned
		for (Integer elem: list) {
			System.out.println(elem);
		}
	}

}
