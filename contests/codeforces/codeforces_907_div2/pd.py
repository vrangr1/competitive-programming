import math

MOD = 1e9+7

def compute_ans(val):
    lgx = math.log2(val)
    lglgx = math.log2(math.floor(lgx))
    return math.floor(lgx/lglgx)

def binary_search(low, high):
    if (low == high): return low
    assert low < high, f"{low} should be less than {high}"
    mid = (low+high+1)//2
    assert low != mid, f"{low} can't be equal to {mid}"
    assert mid <= high, f"{mid} should always be <= {high}; low = {low}"
    cmid = compute_ans(mid)
    if (cmid == compute_ans(low)):
        return binary_search(mid,high)
    return binary_search(low,mid-1)

def compute_next(x):
    pr = math.floor(math.log2(x)) + 1
    nxt = (1<<pr)
    assert x < nxt, f"{x} should always be less than {nxt}"
    return binary_search(x, nxt-1)

def compute_sum(cur, r):
    if (cur > r): return 0
    if (cur == r): return compute_ans(cur)
    nxt = min(compute_next(cur),r)
    assert nxt >= cur, f"{nxt} should be greater or equal to than {cur}"
    return ((compute_ans(cur)*(nxt-cur+1))%MOD + compute_sum(nxt+1,r))%MOD

if __name__ == '__main__':
    l = 179
    r = 1000000000000000000
    # l = 729
    # r = 50625
    # l = 7
    # r = 201018960
    # l = 4
    # r = 201018959
    # l = 57
    # r = 179
    print(compute_sum(l,r))
