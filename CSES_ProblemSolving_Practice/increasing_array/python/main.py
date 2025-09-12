
n = int(input())

numbers = list(map(int, input().split()))

length = len(numbers)
res = 0
for i in range(1, length, 1):
    
    diff = numbers[i] - numbers[i-1]
    if diff < 0:
        res += abs(diff)
        numbers[i] = numbers[i] + abs(diff)

print(res)