
n, m, k = map(int, input().split())

applicants = list(map(int, input().split()))

apartments = list(map(int, input().split()))

applicants.sort()

apartments.sort()

i = 0
j = 0
res = 0
while i<n and j<m:
    
    max_consideration = applicants[i] + k
    min_consideration = applicants[i] - k
    
    if apartments[j] > max_consideration:
        i += 1
    elif apartments[j] < min_consideration:
        j += 1
    else:
        res += 1
        i += 1
        j += 1
print(res)