package DesignPattern.tpVisiteur.etudiant;

public class Stats extends Visitor {
	private int  nbAssignment = 0;
	public final int getNbAssignment() {
		return nbAssignment;
	}

	public final int getNbConditionnal() {
		return nbConditionnal;
	}

	public final int getNbPrint() {
		return nbPrint;
	}

	public final int getNbRead() {
		return nbRead;
	}

	public final int getNbWhile() {
		return nbWhile;
	}

	private int  nbConditionnal = 0;
	private int  nbPrint = 0;
	private int  nbRead = 0;
	private int  nbWhile = 0;

	public int getNbStatement() {
		return nbAssignment + nbConditionnal + nbPrint + nbRead + nbWhile;
	}

	@Override
	public void visit(BinExpression binExpression) {
		// TODO Auto-generated method stub

	}

	@Override
	public void visit(Integer value) {
		// TODO Auto-generated method stub

	}

	@Override
	public void visit(VariableRef variableRef) {
		// TODO Auto-generated method stub

	}

	@Override
	public void visit(Assignment assignment) {
		nbAssignment++;
		assignment.getVar().accept(this);
		assignment.getRhs().accept(this);
	}

	@Override
	public void visit(Conditionnal conditionnal) {
		nbConditionnal++;
		conditionnal.getCond().accept(this);
		conditionnal.getThenPart().accept(this);
		conditionnal.getElsePart().accept(this);
	}

	@Override
	public void visit(Print pr) {
		nbPrint++;
		pr.getPrint().accept(this);
	}

	@Override
	public void visit(Read read) {
		nbRead++;
		read.getVar().accept(this);
	}

	@Override
	public void visit(While wh) {
		nbWhile++;
		wh.getBody().accept(this);
	}

	@Override
	public void visit(Block block) {
		for (Statement elem: block.getS()) {
			elem.accept(this);
		}
	}

}
