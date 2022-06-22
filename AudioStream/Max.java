import java.util.ArrayList;

public class Max extends Analysis implements Processable{
    public Max() {
        this.type = "Max";
    }

    @Override
    public void process (ArrayList<Float> current){
        Float max = current.get(0);

        for (int i=1; i < current.size(); i++){
            if (current.get(i) > max){
                max = current.get(i);
            }
        }

        this.output =  max;
    }
}
