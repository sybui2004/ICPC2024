import sys
import re

def process_input():
    input_data = sys.stdin.read()
    number_pattern = re.compile(r'\d+')
    numbers = number_pattern.findall(input_data)
    INT32_MAX = 2_147_483_647
    INT64_MAX = 9_223_372_036_854_775_807
    
    total_sum = 0
    
    for number in numbers:
        num = int(number)
        if num > INT32_MAX and num <= INT64_MAX:
            total_sum += num
    
    print(total_sum)

if __name__ == "__main__":
    process_input()
