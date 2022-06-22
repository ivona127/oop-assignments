package Modifier;
import Soldier.*;

public class ProtectionModifier implements Modifier {
    private String tag;
    private int value;

    public ProtectionModifier(String tag, int value) {
        this.tag = tag;
        this.value = value;
    }

    public String getTag(){
        return this.tag;
    }

    @Override
    public String getCharacteristic() {
        return null;
    }

    @Override
    public void attributeModifier(Soldier soldier) {
        soldier.tags.add(tag);
        switch (soldier.getTypeOfAttack()){
            case "melee": soldier.setProtectionAgainstMeleeSum(value); break;
            case "ranged": soldier.setProtectionAgainstRangedSum(value); break;
        }
    }

    @Override
    public int attackModifier(Soldier soldier, Soldier enemy) {
        return 0;
    }

    @Override
    public int protectionModifier(Soldier soldier, Soldier enemy) {
        for (String enemyTag : enemy.tags) {
            if(tag.equals(enemyTag)) {
                return value;
            }
        }

        return 0;
    }

    @Override
    public int getValue() {
        return value;
    }
}
