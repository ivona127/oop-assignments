package Modifier;
import Soldier.*;

public interface Modifier {
    void attributeModifier(Soldier soldier);
    int attackModifier(Soldier soldier, Soldier enemy);
    int protectionModifier(Soldier soldier, Soldier enemy);
    int getValue();
    String getTag();
    String getCharacteristic();
}
