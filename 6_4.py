
def hanoi(n, fromm, temp, to):
    if n==1:
        l_fromm = len(fromm)
        l_temp = len(temp)
        l_to = len(to)
        to[l_to]=fromm[l_fromm-1]
        fromm[l_fromm-1]=''
        print(fromm,temp,to)
    else:
        hanoi(n-1,fromm,to,temp)
        l_fromm = len(fromm)
        l_temp = len(temp)
        l_to = len(to)
        to[l_to]=fromm[l_fromm-1]
        fromm[l_fromm-1] = 0
        printf(fromm,temp,to)
        hanoi(n-1,temp,fromm,to)

n = int(input("Altezza pila: "))
fromm = []
temp = []
to = []

for i in range(n-1):
    fromm.append(chr(97+i))

hanoi(n,fromm,temp,to)
