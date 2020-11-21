package DesignPattern.tpVisiteur.etudiant;

public class BinExpression extends Expression {
	private Expression rhs, lhs;
	private String operator; 
	
	public BinExpression(Expression l, String o, Expression r){
		this.lhs =l;
		this.operator =o;
		this.rhs =r;
	}
	
	public Expression getLhs() {
		return lhs;
	}

	@Override
	public void accept(Visitor v) {
		v.visit(this);
	}


	public void setLhs(Expression lhs) {
		this.lhs = lhs;
	}



	public String getOperator() {
		return operator;
	}



	public void setOperator(String operator) {
		this.operator = operator;
	}



	public Expression getRhs() {
		return rhs;
	}



	public void setRhs(Expression rhs) {
		this.rhs = rhs;
	}

}
