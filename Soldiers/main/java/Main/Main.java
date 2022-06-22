package Main;

import Modifier.*;
import Soldier.*;

import java.util.ArrayList;
import java.util.List;

public class Main {
    public static void main(String[] args) {
        Soldier s1 = new Soldier("Warrior", 100, 10, 10, 5, "melee");

        // getDamageAgainst
        Soldier e1 = new Soldier("Warrior", 150, 60, 80, 9, "melee");
        Modifier m1 = new AttributeModifier("attackStrength", 5);
        Modifier m2 = new AttackModifier("archer", 5);
        s1.addModifier(m1);
        s1.addModifier(m2);
        e1.addModifier(m2);
        System.out.println("getDamageAgainst - " + s1.getDamageAgainst(e1) + "\n");

        // chooseTarget
        Soldier e2 = new Soldier("Magician", 140, 50, 90, 5, "melee");
        Soldier e3 = new Soldier("Archer", 130, 10, 80, 3, "ranged");
        List<Soldier> enemies = new ArrayList<>();
        enemies.add(e2);
        enemies.add(e3);
        System.out.println("chooseTarget - " +  s1.chooseTarget(enemies));

        // getDamageFrom
        Soldier e4 = new Soldier("Warrior", 100, 50, 10, 5, "melee");
        Modifier m3 = new AttributeModifier("protectionAgainstMelee", 5);
        Modifier m4 = new ProtectionModifier("archer", 5);
        Modifier m5 = new AttributeModifier("protectionAgainstRanged", 5);
        s1.addModifier(m3);
        s1.addModifier(m4);
        s1.addModifier(m5);
        e4.addModifier(m4);
        e4.addModifier(m5);
        System.out.println("getDamageFrom - " + s1.getDamageFrom(e4, 24, "melee"));
        System.out.println("getDamageFrom - " + s1.getDamageFrom(e4, 15, "melee"));
        System.out.println("getDamageFrom - " + s1.getDamageFrom(e4, 24, "ranged"));

        // receiveAttack
        s1.receiveAttack(e4,24, "melee");
        System.out.println("receiveAttack - " + s1.getCurrentPoints());

        s1.receiveAttack(e4, 15, "melee");
        System.out.println("receiveAttack - " + s1.getCurrentPoints() + "\n");

        // toString
        System.out.println(s1);
    }
}
