N = int(input())
vowels = {'a','e','i','o','u','y'}

def isVowel(c):
    for x in vowels:
        if(x == c):
            return True

    return False

def counter(st):
    cont = 0
    for i in range(1, len(st)):     
        if isVowel(st[i]) and st[i] == st[i-1]:
            cont+=1 
    return cont

while N != 0:

    out = "none"
    max = -1

    for i in range(N):
        st = input()
        cont = counter(st)
        if(cont > max):
            max = cont
            out = st
    
    print(out)
    N = int(input())