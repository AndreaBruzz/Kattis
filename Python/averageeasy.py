# https://open.kattis.com/problems/averageseasy

T = int(input())

for t in range (T):
    line = input()
    line = input()

    (cs, e) = line.split()

    cs = int(cs)
    e = int(e)

    line = input()
    cs_qi = line.split()
    cs_avg = 0

    for i in range (cs):
        cs_qi[i] = int(cs_qi[i])
        cs_avg += cs_qi[i]
    cs_avg /= cs

    line = input()
    e_qi = line.split()
    e_avg = 0

    for i in range (e):
        e_qi[i] = int(e_qi[i])
        e_avg += e_qi[i]
    e_avg /= e

    e_qi.sort()
    cs_qi.sort()

    cont = 0

    for i in cs_qi:
        if i < cs_avg and i > e_avg: cont += 1

    print(cont)

