
import RunTestCases; // Bound to specific test

import <stdexcept>;
import <iostream>;
import <vector>;
import <string>;

int main(int argc, const char** argv) {

  try {

    const std::vector<std::string> vArgs(argv + 1, argv + argc);
    std::string instrFn = std::string(argv[0]) + ".";


    test::runner r(instrFn);

    r.run_cases();

  } catch (const std::runtime_error& rte) {
    std::cerr << rte.what() << '\n';
    return 1;
  } catch (const std::logic_error& le) {
    std::cerr << le.what() << '\n';
    return 2;
  } catch (...) {
    std::cerr << "Unknown error\n";
    return 3;
  }

  return 0;

}
