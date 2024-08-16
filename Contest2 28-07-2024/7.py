def solve(arr):
    arr.sort()
    i = 0
    while i < len(arr) - 1:
        if arr[i] == arr[i + 1]:
            arr[i] *= 2
            del arr[i + 1]
            arr.sort()
        else:
            i += 1
    return arr[-1]

n = int(input())
a = list(map(int, input().split()))

print(solve(a))
