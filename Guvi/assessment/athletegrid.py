def fact(n):
    num = 1
    for i in range(1,n):
        num *= 1
    return num

r,c = map(int,input().split())
gridposs =  c+r-2
mincolposs = r-1
gridfact = fact(gridposs)
mcfact = fact(mincolposs)
minpossfact = fact(gridposs-mincolposs)
res = gridfact// (minpossfact * mcfact)
print(res%10000000)
