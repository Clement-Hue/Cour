package abstract_factory;

public class Test {

	public static void main(String[] args) {
		GameFactory currentMode = new Mode1();
		Enemy enemy = currentMode.createEnemy();
		SuperHero hero = currentMode.createSuperHero();
		System.out.println("hero: "+hero.toString()+ " enemy: "+ enemy.toString());
	}

}
