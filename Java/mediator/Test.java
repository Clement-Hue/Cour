class Test {
    public static void main(String[] args) {
        Mediator chatroom = new ChatRoom(); 
        Colleague user1 = new User("user1");
        Colleague user2 = new User("user2");
        Colleague user3 = new User("user3");
        user1.register(chatroom);
        user2.register(chatroom);
        user3.register(chatroom);
        user1.send("salut les copains");
        user2.send("salut comment vas-tu");
    }
}