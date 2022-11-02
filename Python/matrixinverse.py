cont = 1

while True:
    try:
        line = input()

        if line == "": continue

        (a_str, b_str) = line.split()

        a = int(a_str)
        b = int(b_str)

        line = input()
        (c_str, d_str) = line.split()

        c = int(c_str)
        d = int(d_str)

        det = a*d - b*c
        print("Case " + str(cont) + ":")
        print(str(int(d/det)) + " " + str(int(-b/det)))
        print(str(int(-c/det)) + " " + str(int(a/det)))

        cont += 1

    except EOFError:
        break



