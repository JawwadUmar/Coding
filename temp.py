def solve():
    n = int(input())
    v = []

    for _ in range(n):
        dur, dead = map(int, input().split())
        v.append((dur, dead))

    v.sort()

    res = 0
    pref = 0
    for i in range(n):
        pref += v[i][0]
        res += v[i][1] - pref

    print(res)

# Driver code
if __name__ == "__main__":
    solve()
