import java.util.ArrayList;

public class Mute extends Effects implements Processable{
    public Mute() {
        this.type = "Mute";
    }

    @Override
    public void process (ArrayList<Float> current) {
        ArrayList <Float> additional = new ArrayList<>();

        for(int i=0; i < current.size(); i++){
            additional.add(0f);
        }

        this.output.values = additional;
    }
}
