import sys
input=sys.stdin.readline

N=int(input())
attack=list(map(int,input().split()))

main_charater=attack.pop(0)
attack.sort()

for i in attack:
    if main_charater > i:
        main_charater += i
    else:
        print("No")
        exit(0)
print("Yes")