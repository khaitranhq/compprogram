#!/usr/bin/python3

import subprocess
import glob

PROBLEM = 'C'

list_input_files = glob.glob(f"{PROBLEM}/test/*.inp")

for index, input_file in enumerate(list_input_files):

    command = f"g++ -DLOCAL {PROBLEM}/data.cpp -o {PROBLEM}/data.exe && {PROBLEM}/data.exe {input_file}"

    result = subprocess.getoutput(command)

    print(f"Output of Testcase ${index}:\n")
    print(result)
