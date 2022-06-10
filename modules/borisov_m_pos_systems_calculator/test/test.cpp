// Copyright 2022 Borisov Maxim

#include <gtest/gtest.h>

#include <iostream>
#include <string>

#include "include/borisov_m_pos_systems_calculator.h"

TEST(borisov_lab2, test_check_is_hex) {
  std::string test_string = ("a23e2");
  bool result = converter::is_hex(test_string);
  ASSERT_TRUE(result);
}

TEST(borisov_lab2, test_check_is_bin) {
  std::string test_string = ("1010101");
  bool result = converter::is_bin(test_string);
  ASSERT_TRUE(result);
}

TEST(borisov_lab2, test_check_is_oct) {
  std::string test_string = ("2345");
  bool result = converter::is_oct(test_string);
  ASSERT_TRUE(result);
}

TEST(borisov_lab2, test_create_empty_calc) {
  calculator calc;
  ASSERT_EQ(calc.get_value(), "");
}

TEST(borisov_lab2, test_create_from_string) {
  calculator calc("1010101");
  ASSERT_EQ(calc.get_value(), "1010101");
}

TEST(borisov_lab2, test_operator_eq_calc) {
  calculator calc("1010101");
  calc = calculator("2345");
  ASSERT_EQ(calc.get_value(), "2345");
}

TEST(borisov_lab2, test_operator_eq_string) {
  calculator calc("1010101");
  calc = "2345";
  ASSERT_EQ(calc.get_value(), "2345");
}

TEST(borisov_lab2, test_can_convert_bin) {
  std::string test_string = "1010101";
  int result = converter::convert(test_string);
  EXPECT_EQ(result, 85);
}

TEST(borisov_lab2, test_can_convert_oct) {
  std::string test_string = "2345";
  int result = converter::convert(test_string);
  EXPECT_EQ(result, 1253);
}

TEST(borisov_lab2, test_can_convert_hex) {
  std::string test_string = "0xa23e2";
  int result = converter::convert(test_string);
  EXPECT_EQ(result, 664546);
}

TEST(borisov_lab2, test_returns_zero_if_bad_value) {
  std::string test_string = "hjkl";
  int result = converter::convert(test_string);
  EXPECT_EQ(result, 0);
}

TEST(borisov_lab2, test_bin_plus_bin) {
  std::string lhs = "11111";
  std::string rhs = "11010";
  calculator calc(lhs);
  int result = calc + rhs;
  EXPECT_EQ(result, 57);
}
TEST(borisov_lab2, test_bin_minus_bin) {
  std::string lhs = "11111";
  std::string rhs = "11010";
  calculator calc(lhs);
  int result = calc - rhs;
  EXPECT_EQ(result, 5);
}
TEST(borisov_lab2, test_bin_divide_bin) {
  std::string lhs = "100000";
  std::string rhs = "1000";
  calculator calc(lhs);
  int result = calc / rhs;
  EXPECT_EQ(result, 4);
}
TEST(borisov_lab2, test_bin_multi_bin) {
  std::string lhs = "100";
  std::string rhs = "1000";
  calculator calc(lhs);
  int result = calc * rhs;
  std::cout << converter::convert(lhs) << " " << converter::convert(rhs);
  EXPECT_EQ(result, 32);
}

TEST(borisov_lab2, test_oct_plus_oct) {
  std::string lhs = "2341";
  std::string rhs = "5212";
  calculator calc(lhs);
  int result = calc + rhs;
  EXPECT_EQ(result, 3947);
}
TEST(borisov_lab2, test_oct_minus_oct) {
  std::string lhs = "5212";
  std::string rhs = "2341";
  calculator calc(lhs);
  int result = calc - rhs;
  EXPECT_EQ(result, 1449);
}
TEST(borisov_lab2, test_oct_divide_oct) {
  std::string lhs = "175";
  std::string rhs = "31";
  calculator calc(lhs);
  int result = calc / rhs;
  EXPECT_EQ(result, 5);
}
TEST(borisov_lab2, test_oct_multi_oct) {
  std::string lhs = "20";
  std::string rhs = "4";
  calculator calc(lhs);
  int result = calc * rhs;
  EXPECT_EQ(result, 64);
}

TEST(borisov_lab2, test_hex_plus_hex) {
  std::string lhs = "0x432";
  std::string rhs = "0xfa";
  calculator calc(lhs);
  int result = calc + rhs;
  EXPECT_EQ(result, 1324);
}
TEST(borisov_lab2, test_hex_minus_hex) {
  std::string lhs = "0x432";
  std::string rhs = "0xfa";
  calculator calc(lhs);
  int result = calc - rhs;
  EXPECT_EQ(result, 824);
}
TEST(borisov_lab2, test_hex_divide_hex) {
  std::string lhs = "0xfa";
  std::string rhs = "0xa";
  calculator calc(lhs);
  int result = calc / rhs;
  EXPECT_EQ(result, 25);
}
TEST(borisov_lab2, test_hex_multi_hex) {
  std::string lhs = "0xa";
  std::string rhs = "0xf";
  calculator calc(lhs);
  int result = calc * rhs;
  EXPECT_EQ(result, 150);
}

TEST(borisov_lab2, test_hex_plus_bin) {
  std::string lhs = "0xfa";
  std::string rhs = "11010101";
  calculator calc(lhs);
  int result = calc + rhs;
  EXPECT_EQ(result, 463);
}

TEST(borisov_lab2, test_bin_minus_oct) {
  std::string lhs = "11010101";
  std::string rhs = "323";
  calculator calc(lhs);
  int result = calc - rhs;
  EXPECT_EQ(result, 2);
}

TEST(borisov_lab2, test_hex_divide_oct) {
  std::string lhs = "0xfa";
  std::string rhs = "12";
  calculator calc(lhs);
  int result = calc / rhs;
  EXPECT_EQ(result, 25);
}

TEST(borisov_lab2, test_bin_multi_hex) {
  std::string lhs = "10100";
  std::string rhs = "0x14";
  calculator calc(lhs);
  int result = calc * rhs;
  EXPECT_EQ(result, 400);
}
