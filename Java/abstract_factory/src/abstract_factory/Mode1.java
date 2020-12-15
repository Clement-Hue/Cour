package abstract_factory;

public class Mode1 implements GameFactory{

	@Override
	public SuperHero createSuperHero() {
		return new Batman();
	}

	@Override
	public Enemy createEnemy() {
		return new Joker();
	}
	
}
