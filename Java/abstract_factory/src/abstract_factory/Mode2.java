package abstract_factory;

public class Mode2 implements GameFactory{

	@Override
	public SuperHero createSuperHero() {
		return new Superman();
	}

	@Override
	public Enemy createEnemy() {
		return new Cryptoman();
	}
	
}
