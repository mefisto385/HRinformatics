def bs(y):
    x=int(y[0])*60*60+int(y[1])*60+int(y[2])
    return x
n,m=map(int,input().split())
bv=[]
nv=[]
lv=[]
for i in range(n):
    a=list(map(int,input().split()))
    bv.append(a)
for i in range(m):
    b,c=map(str,input().split())
    nv.append(b)
    lv.append(c.split(':'))
lzs=[0]*86400
for j in range(m):
    ps=bs(lv[j])
    #print(ps)
    for k in range(ps,ps+int(nv[j])):
        if k>=86400:
            k=k-86400
        lzs[k]=1
#print(lzs)
print(sum(lzs))
