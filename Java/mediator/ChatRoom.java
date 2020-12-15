public class ChatRoom extends Mediator{
    @Override
    public void send(Colleague sender, String message) {
        for (Colleague user: this.lColleagues) {
            if (user != sender) {
                user.receive(message);
            }
        }
    }
}
