from itertools import permutations
br=[]
for i in range(6):
    a=int(input())
    br.append(a)
sb=list(permutations(br))
nm=0
nmx=0
nmy=0
tm=0
for i in sb:
    tm=0
    xx=str(str(i[0])+str(i[1])+str(i[2]))
    yy=str(str(i[3])+str(i[4])+str(i[5]))
    x=int(xx)
    y=int(yy)
    if x>99 and y>99:
        tm=x+y
        if tm>nm and tm<1000:
            nm=tm
            nmx=x
            nmy=y
        if tm==nm:
            if x>y:
                if x>nmx:
                    nm=tm
                    nmx=x
                    nmy=y
            if x<y:
                if y>nmx:
                    nm=tm
                    nmx=x
                    nmy=y
if nm==0:
    print('Bilbo')
else:
    print(nm)
    print(nmx)
    print(nmy)
