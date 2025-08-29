#include <gtest/gtest.h>
#include <ncurses.h>
#include "../Register.h"
#include "../Activity.h"

//Creazione Classe per Test
class RegisterTest : public ::testing::Test {
protected:
    Register reg;
    Activity act1;
    Activity act2;

    void SetUp() override {
        act1.setTitle("Titolo1");
        act1.setDescription("Descrizione1");
        act1.setHourTimeStart(9);
        act1.setMinTimeStart(30);
        act1.setHourTimeEnd(10);
        act1.setMinTimeEnd(15);

        act2.setTitle("Titolo2");
        act2.setDescription("Descrizione2");
        act2.setHourTimeStart(14);
        act2.setMinTimeStart(0);
        act2.setHourTimeEnd(15);
        act2.setMinTimeEnd(30);
    }
};

TEST_F(RegisterTest, AddActivityIncreasesCount) {
    EXPECT_TRUE(reg.isEmpty());
    reg.addActivity(act1);
    EXPECT_EQ(reg.numberActivities(), 1);
    reg.addActivity(act2);
    EXPECT_EQ(reg.numberActivities(), 2);
}

TEST_F(RegisterTest, RemoveActivityDecreasesCount) {
    reg.addActivity(act1);
    reg.addActivity(act2);

    EXPECT_EQ(reg.numberActivities(), 2);

    reg.removeActivity(0);
    EXPECT_EQ(reg.numberActivities(), 1);

    EXPECT_EQ(reg.numberActivities(), 1);
}

TEST_F(RegisterTest, RemoveActivityWithInvalidIndexDoesNothing) {
    reg.addActivity(act1);

    EXPECT_EQ(reg.numberActivities(), 1);

    reg.removeActivity(-1);
    EXPECT_EQ(reg.numberActivities(), 1);

    reg.removeActivity(5);
    EXPECT_EQ(reg.numberActivities(), 1);
}

TEST_F(RegisterTest, IsEmptyReturnsTrueWhenNoActivities) {
    EXPECT_TRUE(reg.isEmpty());
}

TEST_F(RegisterTest, IsEmptyReturnsFalseWhenActivitiesExist) {
    reg.addActivity(act1);
    EXPECT_FALSE(reg.isEmpty());
}