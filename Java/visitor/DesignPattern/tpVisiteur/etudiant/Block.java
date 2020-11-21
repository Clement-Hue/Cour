package DesignPattern.tpVisiteur.etudiant;

import java.util.*;

public class Block extends Statement {
	private ArrayList<Statement> s;

	public Block(ArrayList<Statement> s) {
		super();
		this.s = s;
	}
	
	public ArrayList<Statement> getS() {
		return s;
	}
	
	@Override
	public void accept(Visitor v) {
		v.visit(this);
	}
}
