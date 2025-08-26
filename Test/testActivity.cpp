
#include <gtest/gtest.h>
#include <ncurses.h>
#include "../Activity.h"

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
    EXPECT_THROW(activity.setHourTimeStart(25), std::invalid_argument);
}

TEST_F(ActivityTest, SetMinTimeStartInvalid) {
    EXPECT_THROW(activity.setMinTimeStart(73), std::invalid_argument);
}

TEST_F(ActivityTest, SetHourTimeEndInvalid) {
    EXPECT_THROW(activity.setHourTimeEnd(30), std::invalid_argument);
}

TEST_F(ActivityTest, SetMinTimeEndInvalid) {
    EXPECT_THROW(activity.setMinTimeEnd(90), std::invalid_argument);
}


