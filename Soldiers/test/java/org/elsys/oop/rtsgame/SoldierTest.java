package org.elsys.oop.rtsgame;
import Modifier.*;
import Soldier.*;

import org.junit.jupiter.api.AfterEach;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import java.util.ArrayList;
import java.util.List;

import static org.junit.jupiter.api.Assertions.assertEquals;

class SoldierTest {
    Soldier s1;
    Soldier testSoldier;
    Soldier enemy1;
    Soldier enemy2;
    Soldier enemy3;
    Modifier m1;
    Modifier m2;
    Modifier m3;
    Modifier m4;
    Modifier m5;

    @BeforeEach
    void setUp() {
        s1 = new Soldier("Warrior", 100, 10, 10, 5, "melee");
        testSoldier = new Soldier("Warrior", 100, 5, 5, 10, "melee");
        enemy1 = new Soldier("Warrior", 150, 60, 80, 9, "melee");
        enemy2 = new Soldier("Archer", 100, 30, 2, 5, "ranged");
        enemy3 = new Soldier("Warrior", 100, 50, 10, 5, "melee");
        m1 = new AttributeModifier("attackStrength", 5);
        m2 = new AttackModifier("archer", 5);
        m3 = new AttributeModifier("protectionAgainstMelee", 5);
        m4 = new ProtectionModifier("archer", 5);
        m5 = new AttributeModifier("protectionAgainstRanged", 5);
    }

    @AfterEach
    void tearDown() {
        s1 = null;
        testSoldier = null;
        enemy1 = null;
        enemy2 = null;
        enemy3 = null;
        m1 = null;
        m2 = null;
        m3 = null;
        m4 = null;
        m5 = null;
    }

    @Test
    void unmodifiedStats() {
        assertEquals(100, testSoldier.getMaxPoints());
        assertEquals(100, testSoldier.getCurrentPoints());
        assertEquals(5, testSoldier.getAttackStrength());
        assertEquals(5, testSoldier.getProtectionAgainstMelee());
        assertEquals(10, testSoldier.getProtectionAgainstRanged());
    }

    @Test
    void modifiedStats() {
        testSoldier.addModifier(new AttributeModifier("maxPoints", 5));
        assertEquals(105, testSoldier.getMaxPoints());

        testSoldier.addModifier(new AttributeModifier("attackStrength", 10));
        assertEquals(15, testSoldier.getAttackStrength());

        testSoldier.addModifier(new AttributeModifier("protectionAgainstMelee", 15));
        assertEquals(20, testSoldier.getProtectionAgainstMelee());

        testSoldier.addModifier(new AttributeModifier("protectionAgainstRanged", 20));
        assertEquals(30, testSoldier.getProtectionAgainstRanged());
    }

    @Test
    void chooseTarget() {
        List<Soldier> enemies = new ArrayList<>();
        enemies.add(enemy1);
        enemies.add(enemy2);
        assertEquals(enemy2, testSoldier.chooseTarget(enemies));
        enemy2.addModifier(new AttributeModifier("attackStrength", 8500));
        assertEquals(enemy1, testSoldier.chooseTarget(enemies));
    }

    @Test
    void getDamageAgainst() {
        s1.addModifier(m1);
        s1.addModifier(m2);
        enemy1.addModifier(m2);
        assertEquals(20, s1.getDamageAgainst(enemy1));
    }

    @Test
    void getDamageFrom() {
        s1.addModifier(m3);
        s1.addModifier(m4);
        s1.addModifier(m5);
        enemy3.addModifier(m4);
        enemy3.addModifier(m5);
        assertEquals(4, s1.getDamageFrom(enemy3, 24, "melee"));
        assertEquals(1, s1.getDamageFrom(enemy3, 15, "melee"));
        assertEquals(19, s1.getDamageFrom(enemy3, 24, "ranged"));
    }


    @Test
    void receiveAttack() {
        enemy3.addModifier(m4);
        enemy3.addModifier(m5);
        s1.addModifier(m3);
        s1.addModifier(m4);
        s1.addModifier(m5);

        s1.receiveAttack(enemy3,24, "melee");
        assertEquals(96, s1.getCurrentPoints());
        s1.receiveAttack(enemy3, 15, "melee");
        assertEquals(95, s1.getCurrentPoints());
    }

    @Test
    void testToString() {
        s1.addModifier(m1);
        s1.addModifier(m2);
        s1.addModifier(m3);
        s1.addModifier(m4);
        s1.addModifier(m5);
        assertEquals("Warrior\n" +
                "\tHP:  100/100\n" +
                "\tATK: 15+5\n" +
                "\tDEF: 15+5/10+0\n" +
                "Modifiers:\n" +
                "Added extra \"attackStrength\" to Warrior for +5\n" +
                "Extra attack against \"archer\" for +5\n" +
                "Added extra \"protectionAgainstMelee\" to Warrior for +5\n" +
                "Extra defence against \"archer\" for +5\n" +
                "Added extra \"protectionAgainstRanged\" to Warrior for +5\n", s1.toString());
    }
}