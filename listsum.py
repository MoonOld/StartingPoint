try:
    a = input()
    b = input()
    c = []

    b = [int(x) for x in b.split()]
    b.sort()
    for i in b:
        if(i not in c):
            c.append(i)
    print(c[int(a[2])-1])

except EOFError:
    pass