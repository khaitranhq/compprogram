#!/usr/bin/python3

import subprocess
import glob

PROBLEM = 'Leetcode/largest-local-values-in-a-matrix'

list_input_files = glob.glob(f"{PROBLEM}/test/*.inp")

for index, input_file in enumerate(list_input_files):
    try:
        with open(f"{PROBLEM}/test/{index}.inp", 'r') as input_file:
            subprocess.run(
                ["g++", f"{PROBLEM}/main.cpp", "-o", f"{PROBLEM}/main.exe"],
                check=True)

            input_data = input_file.read().strip()
            # print(input_data)
            result = subprocess.run([f"./{PROBLEM}/main.exe"],
                                    input=input_data,
                                    text=True,
                                    capture_output=True,
                                    check=True)
            print(result.stdout.strip())

            if result.stdout.strip() == open(f"{PROBLEM}/test/{index}.ans").read().strip():
                print(f"Testcase ${index}: Success\n")
            else:
                print(f"Testcase ${index}: Failed\n")

        print("==================================================")
    except FileNotFoundError:
        print("File not found.")
    except subprocess.CalledProcessError as e:
        print("Error:", e)
        # print("Subprocess output:", e.output)
