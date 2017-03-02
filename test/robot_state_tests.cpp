#include <gtest/gtest.h>

#include <sstream>

#include "franka/robot_state.h"
#include "helpers.h"

using namespace franka;

bool stringContains(const std::string& actual, const std::string& expected) {
  return actual.find(expected) != std::string::npos;
}

TEST(RobotState, IsInitializedToZero) {
  RobotState robot_state;

  testRobotStateIsZero(robot_state);
}

TEST(RobotState, CanBeStreamed) {
  RobotState robot_state;

  std::stringstream ss;
  ss << robot_state;
  std::string output(ss.str());

  EXPECT_PRED2(stringContains, output, "q_start");
  EXPECT_PRED2(stringContains, output, "O_T_EE_start");
  EXPECT_PRED2(stringContains, output, "elbow_start");
  EXPECT_PRED2(stringContains, output, "tau_J");
  EXPECT_PRED2(stringContains, output, "dtau_J");
  EXPECT_PRED2(stringContains, output, "q");
  EXPECT_PRED2(stringContains, output, "dq");
  EXPECT_PRED2(stringContains, output, "q_d");
  EXPECT_PRED2(stringContains, output, "joint_contact");
  EXPECT_PRED2(stringContains, output, "cartesian_contact");
  EXPECT_PRED2(stringContains, output, "joint_collision");
  EXPECT_PRED2(stringContains, output, "cartesian_collision");
  EXPECT_PRED2(stringContains, output, "tau_ext_hat_filtered");
  EXPECT_PRED2(stringContains, output, "O_F_ext_hat_K");
  EXPECT_PRED2(stringContains, output, "K_F_ext_hat_K");
  EXPECT_PRED2(stringContains, output, "message_id");
}

TEST(RobotState, CanCopyConstruct) {
  RobotState robot_state;
  randomRobotState(robot_state);

  RobotState robot_state2(robot_state);

  testRobotStatesAreEqual(robot_state, robot_state2);
}

TEST(RobotState, CanAssign) {
  RobotState robot_state;
  randomRobotState(robot_state);

  RobotState robot_state2;
  robot_state2 = robot_state;

  testRobotStatesAreEqual(robot_state, robot_state2);
}