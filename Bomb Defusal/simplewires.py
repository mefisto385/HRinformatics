wrs = input("What are the wires(red - r, blue - b, green - g, black - l, yellow - y, white - w)?")
sr = input("Last digit of a serial number:")

if len(wrs) == 3:
    if "r" not in wrs: print(2)
    elif wrs[2] == "w": print(3)
    elif wrs.count("b") > 1:
        if wrs[2] == "b": print(3)
        else: print(2)
    else:
        print(3)
elif len(wrs) == 4:
    if wrs.count("r") > 1 and int(sr[-1])%2 == 1:
        for i in range(3,0,-1):
            if wrs[i]=='r':
                x=i
                break
        print(x+1)
    elif wrs.count("r") == 0 and wrs[3] == "y": print(1)
    elif wrs.count("b") == 1: print(1)
    elif wrs.count("y") > 1: print(4)
    else: print(2)
elif len(wrs) == 5:
    if wrs[-1]=='l' and int(sr[-1])%2==1: print(4)
    elif wrs.count('r')==1 and wrs.count('y') >1: print(1)
    elif wrs.count('l') ==0: print(2)
    else: print(1)

else:
    if wrs.count('y')==0 and int(sr[-1])%2==1: print(3)
    elif wrs.count('y')==1 and wrs.count('w')>1: print(4)
    elif wrs.count('r')==0: print(6)
    else: print(4)
    
