import sys

# Read all input at once
data = sys.stdin.read().split()
n = int(data[0])
arr = map(int, data[1:])

distinct_values = set(arr)

print(len(distinct_values))