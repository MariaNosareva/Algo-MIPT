//
// Created by maria on 09.12.16.
//

#include <gtest/gtest.h>
#include "../AkhoStateMachine/AkhoStateMachine.h"

TEST(Bor, Size) {
  std::stringstream in;
  in << "ab??aba?c \n"
      "ababacabaacca";
  AkhoStateMachine fsm = AkhoStateMachine::FromStream(in);
  fsm.BuildBor();
  ASSERT_EQ(fsm.getFSMStates(), 5);
}

TEST(TestingSolution, Example) {
  std::stringstream in;
  in << "ab??aba \n"
        "ababacaba";
  AkhoStateMachine fsm = AkhoStateMachine::FromStream(in);
  std::vector<int> fsmAnswer = fsm.process();
  std::vector<int> answer = {2};
  ASSERT_EQ(fsmAnswer, answer);
}

TEST(TestingSolution, Overlay) {
  std::stringstream in;
  in << "a?a \n"
      "abracadabra";
  AkhoStateMachine fsm = AkhoStateMachine::FromStream(in);
  std::vector<int> fsmAnswer = fsm.process();
  std::vector<int> answer = {3, 5};
  ASSERT_EQ(fsmAnswer, answer);
}

TEST(TestingSolution, EndOfPattern) {
  std::stringstream in;
  in << "?c? \n"
      "ccccc";
  AkhoStateMachine fsm = AkhoStateMachine::FromStream(in);
  std::vector<int> fsmAnswer = fsm.process();
  std::vector<int> answer = {0, 1, 2};
  ASSERT_EQ(fsmAnswer, answer);
}

int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}