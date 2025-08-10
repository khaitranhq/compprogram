#include <algorithm>
#include <chrono>
#include <cstdlib>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;
namespace fs = std::filesystem;

/**
 * SPOJ DIGOKEYS Testing Framework
 *
 * This program compiles and tests a C++ solution against multiple test cases
 * for the SPOJ DIGOKEYS problem.
 *
 * Usage: ./thesis <cpp_file_path>
 *
 * The framework:
 * 1. Compiles the provided C++ file
 * 2. Runs it against all test cases in ./tests/ folder
 * 3. Compares output with expected results
 * 4. Reports detailed results for each test case
 */

class TestFramework {
private:
  string executablePath;
  string testsDir;
  int totalTests;
  int passedTests;

  /**
   * Trim whitespace from string
   */
  string trim(const string &str) {
    size_t start = str.find_first_not_of(" \t\n\r");
    if (start == string::npos)
      return "";
    size_t end = str.find_last_not_of(" \t\n\r");
    return str.substr(start, end - start + 1);
  }

  /**
   * Read file content into string
   */
  string readFile(const string &filepath) {
    ifstream file(filepath);
    if (!file.is_open()) {
      throw runtime_error("Cannot open file: " + filepath);
    }

    stringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
  }

  /**
   * Execute command and return output
   */
  string executeCommand(const string &command) {
    string result = "";
    FILE *pipe = popen(command.c_str(), "r");
    if (!pipe) {
      throw runtime_error("Failed to execute command: " + command);
    }

    char buffer[128];
    while (fgets(buffer, sizeof(buffer), pipe) != nullptr) {
      result += buffer;
    }

    int exitCode = pclose(pipe);
    if (exitCode != 0) {
      throw runtime_error("Command failed with exit code: " +
                          to_string(exitCode));
    }

    return result;
  }

  /**
   * Compare two strings line by line (ignoring trailing whitespace)
   */
  bool compareOutputs(const string &expected, const string &actual) {
    stringstream expectedStream(expected);
    stringstream actualStream(actual);

    string expectedLine, actualLine;

    while (true) {
      bool expectedExists = (bool)getline(expectedStream, expectedLine);
      bool actualExists = (bool)getline(actualStream, actualLine);

      // If both streams are done, return true
      if (!expectedExists && !actualExists) {
        return true;
      }

      // If only one stream is done, return false
      if (expectedExists != actualExists) {
        return false;
      }

      // Trim whitespace from both lines
      expectedLine = trim(expectedLine);
      actualLine = trim(actualLine);

      // Compare trimmed lines
      if (expectedLine != actualLine) {
        return false;
      }
    }

    return true;
  }

  /**
   * Get all test input files from tests directory
   */
  vector<string> getTestFiles() {
    vector<string> testFiles;

    if (!fs::exists(testsDir)) {
      throw runtime_error("Tests directory not found: " + testsDir);
    }

    for (const auto &entry : fs::directory_iterator(testsDir)) {
      if (entry.is_regular_file() && entry.path().extension() == ".in") {
        testFiles.push_back(entry.path().stem().string());
      }
    }

    // Sort test files numerically
    sort(testFiles.begin(), testFiles.end(),
         [](const string &a, const string &b) {
           // Extract number from test filename (e.g., "test1" -> 1)
           int numA = 0, numB = 0;
           sscanf(a.c_str(), "test%d", &numA);
           sscanf(b.c_str(), "test%d", &numB);
           return numA < numB;
         });

    return testFiles;
  }

public:
  TestFramework(const string &testsDirectory = "./tests")
      : testsDir(testsDirectory), totalTests(0), passedTests(0) {}

  /**
   * Compile the C++ source file
   */
  bool compile(const string &sourceFile) {
    // Extract filename without extension for executable name
    fs::path sourcePath(sourceFile);
    string execName = sourcePath.stem().string() + "_test.exe";
    executablePath = "./" + execName;

    // Compile command with optimization and standard flags
    string compileCmd =
        "g++ -std=c++17 -O2 -Wall -Wextra -o " + execName + " " + sourceFile;

    cout << "Compiling: " << compileCmd << endl;

    try {
      executeCommand(compileCmd);
      cout << "✓ Compilation successful!" << endl;
      return true;
    } catch (const runtime_error &e) {
      cout << "✗ Compilation failed: " << e.what() << endl;
      return false;
    }
  }

  /**
   * Run a single test case
   */
  bool runTest(const string &testName) {
    string inputFile = testsDir + "/" + testName + ".in";
    string expectedFile = testsDir + "/" + testName + ".out";

    if (!fs::exists(inputFile) || !fs::exists(expectedFile)) {
      cout << "✗ Test " << testName << ": Missing input or output file" << endl;
      return false;
    }

    try {
      // Run the executable with input file
      string runCmd = executablePath + " < " + inputFile;

      auto start = chrono::high_resolution_clock::now();
      string actualOutput = executeCommand(runCmd);
      auto end = chrono::high_resolution_clock::now();

      auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);

      // Read expected output
      string expectedOutput = readFile(expectedFile);

      // Compare outputs
      if (compareOutputs(expectedOutput, actualOutput)) {
        cout << "✓ Test " << testName << ": PASSED (" << duration.count()
             << "ms)" << endl;
        return true;
      } else {
        cout << "✗ Test " << testName << ": FAILED (" << duration.count()
             << "ms)" << endl;
        cout << "Expected output:" << endl;
        cout << "" << expectedOutput << endl;
        cout << "Actual output:" << endl;
        cout << "" << actualOutput << endl;
        cout << "---" << endl;
        return false;
      }

    } catch (const runtime_error &e) {
      cout << "✗ Test " << testName << ": ERROR - " << e.what() << endl;
      return false;
    }
  }

  /**
   * Run all test cases
   */
  void runAllTests() {
    vector<string> testFiles = getTestFiles();
    totalTests = testFiles.size();
    passedTests = 0;

    cout << "\n" << string(50, '=') << endl;
    cout << "Running " << totalTests << " test cases..." << endl;
    cout << string(50, '=') << endl;

    for (const string &testName : testFiles) {
      if (runTest(testName)) {
        passedTests++;
      }
    }

    // Print summary
    cout << "\n" << string(50, '=') << endl;
    cout << "TEST SUMMARY" << endl;
    cout << string(50, '=') << endl;
    cout << "Total tests: " << totalTests << endl;
    cout << "Passed: " << passedTests << endl;
    cout << "Failed: " << (totalTests - passedTests) << endl;

    if (passedTests == totalTests) {
      cout << "🎉 ALL TESTS PASSED! 🎉" << endl;
    } else {
      cout << "❌ " << (totalTests - passedTests) << " test(s) failed." << endl;
    }
    cout << string(50, '=') << endl;
  }

  /**
   * Cleanup: remove executable
   */
  ~TestFramework() {
    if (!executablePath.empty() && fs::exists(executablePath)) {
      fs::remove(executablePath);
    }
  }
};

int main(int argc, char *argv[]) {
  if (argc != 2) {
    cout << "Usage: " << argv[0] << " <cpp_file_path>" << endl;
    cout << "\nThis program tests a C++ solution for SPOJ DIGOKEYS problem."
         << endl;
    cout << "It compiles the provided C++ file and runs it against all test "
            "cases"
         << endl;
    cout << "in the ./tests/ directory." << endl;
    cout << "\nExample: " << argv[0] << " main.cpp" << endl;
    return 1;
  }

  string sourceFile = argv[1];

  // Check if source file exists
  if (!fs::exists(sourceFile)) {
    cout << "Error: Source file '" << sourceFile << "' not found!" << endl;
    return 1;
  }

  cout << "SPOJ DIGOKEYS Testing Framework" << endl;
  cout << "Testing solution: " << sourceFile << endl;

  try {
    TestFramework framework;

    // Compile the source file
    if (!framework.compile(sourceFile)) {
      return 1;
    }

    // Run all test cases
    framework.runAllTests();

  } catch (const exception &e) {
    cout << "Fatal error: " << e.what() << endl;
    return 1;
  }

  return 0;
}
