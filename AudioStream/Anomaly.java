import java.util.ArrayList;
import java.util.Collections;

public class Anomaly extends Analysis implements Processable{
    private int size;

    public Anomaly(int size) {
        this.type = "Anomaly";
        this.size = size;
    }

    @Override
    public void process (ArrayList<Float> current){
        int anomaly = 0;
        int counter = 0;
        int j = 0;

        while( counter != ( current.size() - size ) + 1 ){
            ArrayList <Float> additional = new ArrayList<>();
            float max = 0;

            for (int i = 0; i < size; i++) {

                if (max < current.get(j)){
                    max = current.get(j);
                }
                additional.add(current.get(j));
                j++;
            }
            j -= size - 1;

            // max number
            additional.remove(max);

            // sort ArrayList
            Collections.sort(additional);

            // median
            float middle;

            if (additional.size() % 2 == 1) {
                middle = additional.get(additional.size() / 2);
            } else {
                middle = ( (additional.get( additional.size() / 2 ) + additional.get( additional.size() / 2 - 1) ) ) / 2 ;
            }

            // Is it an anomaly?
            if(max / middle >= 2.0){
                anomaly += 1;
            }

            counter += 1;
        }

        this.output =  (float) anomaly / current.size() * 100 ;
    }

}
