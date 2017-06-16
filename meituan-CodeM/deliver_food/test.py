def get(num):
    pos = 1
    while num // (10*pos):
        pos *= 10;
    d = num // pos
    return d
    
def fun(i, j):
    a = [0]*9;
    for i in range(i,j+1):
        d = get(i)
        a[d-1] += 1;
    print(a)

if __name__ == "__main__":
    get(10)