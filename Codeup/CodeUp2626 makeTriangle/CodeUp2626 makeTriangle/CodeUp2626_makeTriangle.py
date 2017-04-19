def make(SIZE):
    if SIZE<3:
        return 0
    count=0
    MAX = int(SIZE/2)+1
    for a in range( 1 , MAX):
        for b in range(a, int((SIZE-a)/2)+1):
            c = SIZE-a-b
            if(a+b>c ):
                count+=1
    return count
size = int(input())
print(make(size))



