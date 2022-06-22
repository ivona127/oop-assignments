import java.util.ArrayList;
import java.util.Collections;

public class Denoise extends Effects implements Processable{
    private int size;
    private float M;

    public Denoise(int size, float M) {
        this.type = "Denoise";
        this.size = size;
        this.M = M;
    }

    @Override
    public void process (ArrayList<Float> current){
        int counter = 0;
        int anomaly = 0;
        int j = 0;

        AudioStream temp = new AudioStream();

        for (int i=0; i < current.size(); i++){
            temp.values.add(current.get(i));
        }

        while( counter != ( temp.values.size() - size ) + 1 ){
            ArrayList<Float> additional = new ArrayList<>();

            float max = 0;
            float second_max = 0;
            int max_index = 0;

            for (int i = 0; i < size; i++) {

                if (max < temp.values.get(j)){
                    max = temp.values.get(j);
                    max_index = j;
                }

                additional.add(temp.values.get(j));
                j++;
            }
            j -= size - 1;

            // max number
            additional.remove(max);

            // sort ArrayList
            Collections.sort(additional);

            // median
            float middle = 0;

            if (additional.size() % 2 == 1) {
                middle = additional.get(additional.size() / 2);
            } else {
                middle = ( (additional.get( additional.size() / 2 ) + additional.get( additional.size() / 2 - 1) ) ) / 2 ;
            }

            for (int i=0; i < additional.size(); i++){
                if (additional.get(i) > second_max){
                    second_max = additional.get(i);
                }
            }

            // Is it an anomaly?
            if(max / middle >= M){
                anomaly += 1;
                temp.values.remove(max_index);
                temp.values.add(max_index, second_max);
            }

            counter += 1;
        }

        this.output = temp;
    }
}
