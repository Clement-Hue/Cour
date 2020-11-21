package DesignPattern.tpVisiteur.etudiant;

public class Conditionnal extends Statement {
	private Expression cond;
	private Block thenPart;
	private Block elsePart;

	public final Expression getCond() {
		return cond;
	}

	public final Block getThenPart() {
		return thenPart;
	}

	public final Block getElsePart() {
		return elsePart;
	}

	@Override
	public void accept(Visitor v) {
		v.visit(this);
	}
}
