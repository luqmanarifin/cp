def generate_sequence():
    mask = (1 << 18) - 1
    N = 2*10**5
    prefill = (1 << 17) + 1

    ans = []
    # First element
    ans.append(mask + 1)

    # Next prefill-1 generated elements
    x = 1
    for _ in range(1, prefill):
        ans.append(x)
        x = (x * 5 + 1) & mask

    # Fill the rest with zeros
    ans.extend([0] * (N - prefill))

    return ans

# Now call it:
ans = generate_sequence()
s1 = [1] * 200000
s2 = [x - 1 for x in ans]
for i in range(200000):
    if s2[i] == -1:
        s2[i] = 0
        s1[i] = 0

    

print(1)
print(200000, 1000000000)
print(" ".join(map(str, s1)))
print(" ".join(map(str, s2)))