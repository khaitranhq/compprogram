#!/usr/bin/python3

import subprocess
import glob

PROBLEM = 'B'

list_input_files = glob.glob(f"{PROBLEM}/test/*.inp")

for index, input_file in enumerate(list_input_files):

    command = f"g++ {PROBLEM}/data.cpp -o {PROBLEM}/data.exe && {PROBLEM}/data.exe < {PROBLEM}/test/{index}.inp"

    result = subprocess.getoutput(command)
    formatted_result = result.replace('\n', ' ')
    formatted_result = formatted_result.split(' ')

    ans = open(f"{PROBLEM}/test/{index}.ans").read()
    formatted_ans = ans.replace('\n', ' ')
    formatted_ans = formatted_ans.split(' ')
    formatted_ans.pop()

    if formatted_result == formatted_ans:
        print(f"Testcase ${index}: Success\n")
    else:
        print(f"Testcase ${index}: Failed")
        print(formatted_result)
        print(formatted_ans)
        break
