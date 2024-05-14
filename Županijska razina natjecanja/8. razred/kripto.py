n=int(input())
ri=[]
br=[]
for i in range(n):
    a=str(input())
    if a not in ri:
        ri.append(a)
        br.append(1)
    else:
        br[ri.index(a)]+=1
od=[]
brr=list(br)
while len(od)<len(ri):
    tm=max(br)
    naj=[]
    while max(br)==tm:
        d=br.index(max(br))
        naj.append(ri[d])
        br[d]=-1
    if len(naj)==1:
        od.append(naj[0])
        naj=[]
    du=[]
    for i in naj:
        du.append(len(i))
    brrr=0
    while len(naj)!=brrr:
        tmm=max(du)
        najj=[]
        while max(du)==tmm:
            d=du.index(max(du))
            najj.append(naj[d])
            du[d]=-1
        for i in najj:
            od.append(i)
            brrr+=1
for i in od:
    for j in range(brr[ri.index(i)]):
        print(i)
