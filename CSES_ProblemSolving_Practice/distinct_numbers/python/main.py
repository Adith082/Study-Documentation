


n = int(input())

numbers = list(map(int, input().split()))

numbers.sort()

length = len(numbers)

res = 1

for i in range(1, length, 1):
    if numbers[i] != numbers[i-1]:
        res += 1
print(res)