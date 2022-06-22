package Modifier;
import Soldier.*;


public class AttackModifier implements Modifier {
    private String tag;
    private int value;

    public AttackModifier(String tag, int value) {
        this.tag = tag;
        this.value = value;
    }

    @Override
    public void attributeModifier(Soldier soldier) {
        soldier.tags.add(tag);
        soldier.setAttackStrengthSum(value);
    }

    @Override
    public int attackModifier(Soldier soldier, Soldier enemy) {
        for (String enemyTag : enemy.tags) {
            if(tag.equals(enemyTag)) {
                return value;
            }
        }
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
        return tag;
    }

    public String getCharacteristic() {
        return null;
    }
}
