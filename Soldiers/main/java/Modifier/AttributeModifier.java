package Modifier;
import Soldier.*;

public class AttributeModifier implements Modifier {

    private String characteristic;
    private int value;

    public AttributeModifier(String characteristic, int value) {
        this.characteristic = characteristic;
        this.value = value;
    }

    @Override
    public void attributeModifier(Soldier soldier) {

        switch (characteristic) {
            case "maxPoints": soldier.setMaxPoints(value); break;
            case "attackStrength": soldier.setAttackStrength(value); break;
            case "protectionAgainstMelee": soldier.setProtectionAgainstMelee(value);  break;
            case "protectionAgainstRanged": soldier.setProtectionAgainstRanged(value); break;
            }
    }

    @Override
    public int attackModifier(Soldier soldier, Soldier enemy) {
        return 0;
    }

    @Override
    public int protectionModifier(Soldier soldier, Soldier enemy) {
        return 0;
    }

    @Override
    public int getValue() {
        return value;
    }

    @Override
    public String getTag() {
        return null;
    }

    @Override
    public String getCharacteristic() {
        return characteristic;
    }

}
