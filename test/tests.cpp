// Copyright 2021 GHA Test Team
#include <gtest/gtest.h>
#include "textgen.h"

TEST(TestCaseName1, Test1) {
  std::string text = "one fish two fish red fish blue fish";
  int npref = 2;
  Markov gen = Markov(text, npref);
  prefix pref = gen.statetab.begin()->first;
  int n = pref.size();
  EXPECT_EQ(n, npref);
}

TEST(TestCaseName2, Test2) {
  std::string text = "one fish two fish red fish blue fish";
  int npref = 2;
  Markov gen = Markov(text, npref);
  prefix pref = prefix();
  pref.push_back("one");
	pref.push_back("fish");
  std::string s = gen.statetab[pref][0];
  EXPECT_EQ(s, "two");
}

TEST(TestCaseName3, Test3) {
  std::string text = "one fish two fish red fish blue fish";
  int npref = 1;
  Markov gen = Markov(text, npref);
  prefix pref = prefix();
  pref.push_back("two");
  std::string s = gen.statetab[pref][0];
  EXPECT_EQ(s, "fish");
}
