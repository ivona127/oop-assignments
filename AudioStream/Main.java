public class Main {
    public static void main(String[] args) {
        AudioStream as1 = new AudioStream();
        as1.values.add(1f);
        as1.values.add(2f);
        as1.values.add(10f);
        as1.values.add(5f);
        as1.values.add(6f);
        as1.values.add(8f);

        String result;

        // as1 - average
        Average avr = new Average();
        avr.process(as1.values);
        result = avr.toString();
        System.out.println(result);

        // as1 - max
        Max max = new Max();
        max.process(as1.values);
        result = max.toString();
        System.out.println(result);

        // as1 - anomaly
        Anomaly anm = new Anomaly(6);
        anm.process(as1.values);
        result = anm.toString();
        System.out.println(result);

        Anomaly anm2 = new Anomaly(3);
        anm2.process(as1.values);
        result = anm2.toString();
        System.out.println(result);

        AudioStream as2 = new AudioStream();
        as2.values.add(-5f);
        as2.values.add(2f);
        as2.values.add(3f);
        as2.values.add(-4f);
        as2.values.add(10f);
        as2.values.add(12f);

        // as2 - mute
        Mute mute = new Mute();
        mute.process(as2.values);
        result = mute.toString();
        System.out.println(result);

        // as2 - normalize
        Normalize normalize = new Normalize();
        normalize.process(as2.values);
        result = normalize.toString();
        System.out.println(result);

        AudioStream as3 = new AudioStream();
        as3.values.add(1f);
        as3.values.add(3f);
        as3.values.add(10f);
        as3.values.add(4f);

        // as3 - denoise
        Denoise denoise = new Denoise(3, 3);
        denoise.process(as3.values);
        result = denoise.toString();
        System.out.println(result);
    }
}
