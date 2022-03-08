#include "tests.h"

#include <string>
#include <iostream>

int parse_arg(const std::string& arg) {
  try {
    std::size_t pos;
    int x = std::stoi(arg, &pos);
    if (pos < arg.size()) {
      std::cerr << "Trailing characters after number: " << arg << '\n';
    }

    return x;
  } catch (std::invalid_argument const &ex) {
    std::cerr << "Invalid number: " << arg << '\n';
  } catch (std::out_of_range const &ex) {
    std::cerr << "Number out of range: " << arg << '\n';
  }

  return 0;
}

int main(int argc, char *argv[]) {
  if (argc < 2) {
    // Mirrors i7-6700HQ CPU with 128KiB L1D and 1MiB L2
    test_random(128, 1024, 10000);
  } else {
    std::string test_type{argv[1]};

    if (test_type == "random") {
      int capacity = parse_arg(argv[2]);
      int k = parse_arg(argv[3]);
      int m = parse_arg(argv[4]);

      test_random(capacity, k, m);
    } else if (test_type == "norm") {
      int capacity = parse_arg(argv[2]);
      int k = parse_arg(argv[3]);
      int m = parse_arg(argv[4]);

      test_norm(capacity, k, m);
    } else if (test_type == "loop") {
      int capacity = parse_arg(argv[2]);
      int k = parse_arg(argv[3]);
      int n = parse_arg(argv[4]);
      int m = parse_arg(argv[5]);

      test_loop(capacity, k, n, m);
    } else if (test_type == "loop_cmb") {
      int capacity = parse_arg(argv[2]);
      int k = parse_arg(argv[3]);
      int n = parse_arg(argv[4]);
      int m = parse_arg(argv[5]);

      test_loop_cmb(capacity, k, n, m);
    }
  }


//  test_loop(128, 32, 32, 1500);
//  test_loop(128, 64, 32, 3200);
//  test_loop(128, 128, 32, 6000);
//  test_loop(128, 256, 32, 10000);
//
//  test_loop(128, 512, 16, 8192);
//  test_loop(128, 1024, 8, 8192);

  return 0;
}