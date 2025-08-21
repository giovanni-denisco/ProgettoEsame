
#include <gtest/gtest.h>
#include "../Activity.h"

//Creo oggetto di test da usare in tutti i test

class ActivityTest : public ::testing::Test {

protected:
    Activity activity;

};


TEST(SampleTest, TrueIsTrue) {
    EXPECT_TRUE(true);
}

//Test su metodi setter/getter

TEST_F(ActivityTest, SetGetHourTimeStart) {
    activity.setHourTimeStart(10);
    EXPECT_EQ(activity.getHourTimeStart(), 10);
}

TEST_F(ActivityTest, SetGetMinTimeStart) {
    activity.setMinTimeStart(23);
    EXPECT_EQ(activity.getMinTimeStart(), 23);
}

TEST_F(ActivityTest, SetGetHourTimeEnd) {
    activity.setHourTimeEnd(13);
    EXPECT_EQ(activity.getHourTimeEnd(), 13);
}

TEST_F(ActivityTest, SetGetMinTimeEnd) {
    activity.setMinTimeEnd(42);
    EXPECT_EQ(activity.getMinTimeEnd(), 42);
}

TEST_F(ActivityTest, SetGetDescription) {
    activity.setDescription("Spesa");
    EXPECT_EQ(activity.getDescription(), "Spesa");
}

//Test setter/getter valori non validi

TEST_F(ActivityTest, SetHourTimeStartInvalid) {
    activity.setHourTimeStart(25);
    EXPECT_NE(activity.getHourTimeStart(), 25);
}

TEST_F(ActivityTest, SetMinTimeStartInvalid) {
    activity.setMinTimeStart(73);
    EXPECT_NE(activity.getMinTimeStart(), 73);
}



