import java.util.ArrayList;

public class Normalize extends Effects implements Processable{
    public Normalize() {
        this.type = "Normalize";
    }

    @Override
    public void process (ArrayList<Float> current) {
        ArrayList <Float> additional = new ArrayList<>();
        Float min = 0f;
        Float max = 0f;

        for(int i=0; i < current.size(); i++){
            if(current.get(i) < min){
                min = current.get(i);
            }

            if(current.get(i) > max){
                max = current.get(i);
            }
        }

        for(int i=0; i < current.size(); i++){
            float normalized = ( 2 * ( current.get(i) - min) / (max - min) ) - 1;
            additional.add(normalized);
        }

        this.output.values = additional;
    }

}
