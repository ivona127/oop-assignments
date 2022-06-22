import java.util.ArrayList;

public class Average extends Analysis implements Processable{
    public Average() {
        this.type = "Average";
    }

    @Override
    public void process (ArrayList<Float> current){
        Float values = 0f;

        for (int i=0; i < current.size(); i++){
            values += current.get(i);
        }

        this.output =  values / current.size();
    }
}
