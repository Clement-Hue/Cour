package DesignPattern.tpVisiteur.etudiant;

import java.util.*;

public class Test {
	public static void main(String[] argv){
		Visitor stat = new Stats();
		Statement firstAssign = new Assignment(
				new VariableRef("y"),
				new BinExpression( new VariableRef("x"), "*", new Integer(4)));
		Statement secondAssign = new Assignment(
				new VariableRef("p"),
				new BinExpression( new VariableRef("n"), "*", new Integer(8)));
		ArrayList<Statement> list = new ArrayList<Statement>();
		list.add(firstAssign);
		list.add(secondAssign);
		ProgramNode s = new Block(list);
		Statement w = new While(new Integer(5), (Block) s);
		w.accept(stat);
		System.out.println(((Stats)stat).getNbStatement());
	}
}
