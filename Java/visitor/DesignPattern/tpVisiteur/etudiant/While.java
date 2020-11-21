package DesignPattern.tpVisiteur.etudiant;

public class While extends Statement{
	private Expression cond;
	private Block body;

	public While(Expression cond, Block body) {
		this.body = body;
		this.cond = cond;
	}
	
	@Override
	public void accept(Visitor v) {
		v.visit(this);
	}

	public final Expression getCond() {
		return cond;
	}

	public final Block getBody() {
		return body;
	}
}
