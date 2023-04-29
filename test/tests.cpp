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

TEST(TestCaseName4, Test4) {
  std::string text = "one fish two fish red fish blue fish";
  int npref = 1;
  Markov gen = Markov(text, npref);
  prefix pref = prefix();
  pref.push_back("fish");
  suffix suf = suffix();
  suf.push_back("two");
  suf.push_back("red");
  suf.push_back("blue");
  EXPECT_EQ(gen.statetab[pref][0], suf[0]);
  EXPECT_EQ(gen.statetab[pref][1], suf[1]);
  EXPECT_EQ(gen.statetab[pref][2], suf[2]);
}

TEST(TestCaseName5, Test5) {
  auto table = std::map<prefix, suffix>();
  prefix pref = prefix();
  suffix suf = suffix();
  pref.push_back("fish");
  suf.push_back("red");
  table[pref] = suf;
  pref.clear();
  suf.clear();
  pref.push_back("red");
  suf.push_back("fish");
  table[pref] = suf;
  Markov gen = Markov(table);
  std::string res = "fish red fish red fish red fish red fish red fish";
  EXPECT_EQ(res, gen.Generator(50));
}
