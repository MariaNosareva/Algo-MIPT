#include <gtest/gtest.h>
#include "../SolverLib/PuzzleSolver.h"
#include <fstream>

TEST(InitTest, Size) {
  std::vector<int> input = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 14, 0};
  PuzzleSolver solver = PuzzleSolver(4, input);
  ASSERT_EQ(4, solver.getSize());
}

TEST(InitTest, Solution) {
  std::vector<int> input = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 14, 0};
  PuzzleSolver solver = PuzzleSolver(4, input);
  ASSERT_EQ("", solver.getSolution());
}

TEST(SolvingTest, FirstUnsolvable) {
  std::vector<int> input = {1, 2, 3, 4, 5, 6, 8, 7, 0};
  PuzzleSolver solver(3, input);
  solver.SolveIt();
  ASSERT_EQ(solver.getSolution(), "-1");
}

TEST(SolvingTest, SecondUnsolvable) {
  std::vector<int> input = {1, 2, 3, 8, 0, 4, 7, 6, 5};
  PuzzleSolver solver(3, input);
  solver.SolveIt();
  ASSERT_EQ(solver.getSolution(), "-1");
}

TEST(SolvingTest, Example) {
  std::vector<int> input = {0, 1, 6, 4, 3, 2, 7, 5, 8};
  PuzzleSolver solver(3, input);
  solver.SolveIt();
  ASSERT_EQ(solver.getMoves(), 8);
  ASSERT_EQ(solver.getSolution(), "RDRULDDR");
}

TEST(SolvingTest, SimpleInput) {
  std::vector<int> input = {0, 1, 2, 3, 4, 5, 6, 7, 8};
  PuzzleSolver solver(3, input);
  solver.SolveIt();
  ASSERT_EQ(solver.getMoves(), 22);
  ASSERT_EQ(solver.getSolution(), "RDLDRRULLDRUURDDLLURRD");
}



int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}