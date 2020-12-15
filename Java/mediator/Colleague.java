public  abstract class Colleague {
    Mediator chatRoom; 
    protected String name;
    public String getName() {
        return name;
    }
    public Colleague(String name) {
        this.name = name;
    }
    public void register(Mediator chatRoom) {
        this.chatRoom = chatRoom;
        this.chatRoom.register(this);
    }
    public void unregister() {
        this.chatRoom = null;
        this.chatRoom.unregister(this);
    }
    public void send(String message) {
        System.out.println(name+ " -> " + message);
        this.chatRoom.send(this,message);
    }
    public void receive(String message) {
        System.out.println(name + " <- " + message);
    }
}
