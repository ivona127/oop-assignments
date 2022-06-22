public class Effects {
    protected String type;
    protected AudioStream output = new AudioStream();

    public String toString(){
        return this.type + " - " + output.values;
    }
}
