ni = input()
n = len(ni)

sol = 0
fnd = []

for p in range(n):
    for m in range(n):
        for f in range(n):

            if (f == p and f != 0) or (p == m and m != 0) or (f == m and f != 0):
                continue

            if f == 0 and p == 0 and m == 0: continue

            #print(p, m, f)

            s = []

            si = ""
            fal = False
            for i in range(len(ni)):
                if i == p and p != 0:
                    s.append(si)

                    if (si[0] == '0' and int(si) != 0): fal = True
                    
                    s.append("+")
                    si = ""

                if i == m and m != 0:
                    s.append(si)

                    if (si[0] == '0' and int(si) != 0): fal = True
                    
                    s.append("-")
                    si = ""

                if i == f and f != 0:
                    s.append(si)

                    if (si[0] == '0' and int(si) != 0): fal = True
                    
                    s.append("*")
                    si = ""

                si += ni[i]

                if i == n-1:
                    if si[0] == '0' and int(si) != 0: fal = True
                    s.append(si)

            if not fal:
                x = ""

                for sx in s:
                    x+=sx
                    if sx[0] == '0' and sx != "0": x+="abc"

                #print(s)
                try:
                    xi = eval(x)

                    if xi >= 0 and xi not in fnd:
                        fnd.append(xi)
                        sol+=1
                except:
                    pass

print(sol)
