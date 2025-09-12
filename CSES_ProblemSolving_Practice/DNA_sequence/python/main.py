'''

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

'''
dna = input()
length = len(dna)
cnt = 1
maxx = 1
for i in range(1, length):
    if dna[i] == dna[i-1]:
        cnt += 1 
    else:
        maxx = max(maxx, cnt)
        cnt = 1
maxx = max(maxx, cnt)
print(maxx)
    