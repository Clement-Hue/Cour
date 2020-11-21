package DesignPattern.tpVisiteur.etudiant;

public abstract class Visitor {
	public abstract void visit(BinExpression binExpression);
	public abstract void visit(Integer value);
	public abstract void visit(VariableRef variableRef);
	public abstract void visit(Assignment assignment);
	public abstract void visit(Conditionnal conditionnal);
	public abstract void visit(Print pr);
	public abstract void visit(Read read);
	public abstract void visit(While wh);
	public abstract void visit(Block block);
}
