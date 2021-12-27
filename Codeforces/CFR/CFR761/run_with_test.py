#!/usr/bin/python3

import subprocess
import glob

PROBLEM = 'C'

list_input_files = glob.glob(f"{PROBLEM}/test/*.inp")

for index, input_file in enumerate(list_input_files):

    command = f"g++ {PROBLEM}/data.cpp -o {PROBLEM}/data.exe && {PROBLEM}/data.exe < {index}.inp"

    result = subprocess.getoutput(command)

    if result == open(f"{PROBLEM}/test/{index}.ans").read():
        print(f"Testcase ${index}: Success\n")
    else:
        print(f"Testcase ${index}: Failed\n")
