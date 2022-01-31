#!/usr/bin/python3

import subprocess
import glob

PROBLEM = 'C'

NUMBER_TEST = 1

for i in range(1, NUMBER_TEST + 1):
    command = f"g++ -DLOCAL -DTEST_MODE {PROBLEM}/data.cpp -o {PROBLEM}/data.exe && {PROBLEM}/data.exe {i}"

    result = subprocess.getoutput(command)

    print(f"Output of Testcase ${i}:\n")
    print(result)
