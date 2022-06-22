package Soldier;

import java.util.ArrayList;
import java.util.List;
import Modifier.*;

public class Soldier {
    private String name;
    private String typeOfAttack;
    private int currentPoints;
    private int maxPoints;
    private int attackStrength;
    private int protectionAgainstMelee;
    private int protectionAgainstRanged;
    public ArrayList <String> tags = new ArrayList<>();
    private List<Modifier> modifiers = new ArrayList<Modifier>();

    private int attackStrengthSum = 0;
    private int protectionAgainstMeleeSum = 0;
    private int protectionAgainstRangedSum = 0;
    public Soldier(String name, int maxPoints, int attackStrength,
                   int protectionAgainstMelee, int protectionAgainstRanged, String typeOfAttack) {
        this.name = name;
        this.maxPoints = maxPoints;
        this.currentPoints = maxPoints;
        this.attackStrength = attackStrength;
        this.protectionAgainstMelee = protectionAgainstMelee;
        this.protectionAgainstRanged = protectionAgainstRanged;
        this.typeOfAttack = typeOfAttack;
    }

    public int getCurrentPoints() {
        return currentPoints;
    }

    public int getMaxPoints() {
        return maxPoints;
    }

    public int getAttackStrength() {
        return attackStrength;
    }

    public int getProtectionAgainstMelee() {
        return protectionAgainstMelee;
    }

    public int getProtectionAgainstRanged() {
        return protectionAgainstRanged;
    }

    public String getTypeOfAttack() {
        return typeOfAttack;
    }

    public ArrayList<String> getTags() {
        return tags;
    }

    public void setProtectionAgainstRangedSum(int protectionAgainstRangedSum) {
        this.protectionAgainstRangedSum += protectionAgainstRangedSum;
    }

    public void setProtectionAgainstMeleeSum(int protectionAgainstMeleeSum) {
        this.protectionAgainstMeleeSum += protectionAgainstMeleeSum;
    }

    public void setAttackStrengthSum(int attackStrengthSum) {
        this.attackStrengthSum += attackStrengthSum;
    }

    public void setAttackStrength(int attackStrength) {
        this.attackStrength += attackStrength;
    }

    public void setMaxPoints(int maxPoints) {
        this.maxPoints += maxPoints;
    }

    public void setProtectionAgainstMelee(int protectionAgainstMelee) {
        this.protectionAgainstMelee += protectionAgainstMelee;
    }

    public void setProtectionAgainstRanged(int protectionAgainstRanged) {
        this.protectionAgainstRanged += protectionAgainstRanged;
    }

    @Override
    public String toString() {
        String printableModifiers = "";
        for ( Modifier m: modifiers){
            String type = m.getClass().getSimpleName();
            switch(type) {
                case "AttributeModifier": {
                    printableModifiers += "Added extra \"" + m.getCharacteristic() + "\" to " + name + " for +" + m.getValue() + "\n";
                    break;
                }
                case "AttackModifier": {
                    printableModifiers += "Extra attack against \"" + m.getTag() + "\" for +" + m.getValue() + "\n";
                    break;
                }
                case "ProtectionModifier": {
                    printableModifiers += "Extra defence against \"" + m.getTag() + "\" for +" + m.getValue() + "\n";
                    break;
                }
            }
        }

        return name + "\n" +
                "\t" + "HP:  "  + currentPoints + "/" + maxPoints + "\n" +
                "\t" + "ATK: " + attackStrength + "+" + attackStrengthSum + "\n" +
                "\t" + "DEF: " + protectionAgainstMelee + "+" + protectionAgainstMeleeSum +
                "/" + protectionAgainstRanged + "+" + protectionAgainstRangedSum + "\n" +
                "Modifiers:" + "\n" +
                printableModifiers;
    }

    public void addModifier(Modifier modifier){
        this.modifiers.add(modifier);
        modifier.attributeModifier(this);
    }

    public int getDamageAgainst(Soldier enemy){
        if (tags.isEmpty() || enemy.tags.isEmpty()) {
            return attackStrength;
        } else {
            int sum = 0;

            for (Modifier m: modifiers){
                sum += m.attackModifier(this, enemy);
            }

            return this.attackStrength + sum;
        }
    }

    public Soldier chooseTarget(List<Soldier> enemies){
        Soldier easiestDefeatedEnemy = enemies.get(0);
        int minDamage = enemies.get(0).getAttackStrength();

        for (Soldier e : enemies){
            if ( e.getAttackStrength() < minDamage ){
                easiestDefeatedEnemy = e;
            };
        }
        return easiestDefeatedEnemy;
    }
    public int getDamageFrom(Soldier enemy, int value, String type) {
        int damage = value;

        if (type == this.typeOfAttack){
            switch (type){
                case "ranged": damage -= protectionAgainstRanged; break;
                case "melee": damage -= protectionAgainstMelee; break;
            }
        } else {
            switch (type){
                case "melee": damage -= protectionAgainstMeleeSum; break;
                case "ranged": damage -= protectionAgainstRangedSum;break;
            }
        }

        for (Modifier m : modifiers) {
            damage -= m.protectionModifier(this, enemy);
        }

        if (damage < 1) {
            damage = 1;
        }

        return damage;
    }

    public void receiveAttack(Soldier enemy, int value, String type){
        int damage = this.getDamageFrom(enemy, value, type);

        currentPoints -= damage;

        if (currentPoints < 0){
            currentPoints = 0;
        }

    }
}
