
n = int(input())

summ = 0

for i in range(1, n+1):
    summ = summ ^ i

input_numbers = list(map(int, input().split())) # input string converted to list of 
                                                # substring based on spaces which is then mapped to int, then the map object
                                                # is converted into List

for val in input_numbers:
    summ = summ ^ val

print(summ)