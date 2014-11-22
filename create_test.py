import random
from sys import stderr

num_cases = 100

print(num_cases)

for i in range(num_cases):
    num_ints = random.randint(1, 10000)
    ints = [random.randint(-1000, 1000) for _ in range(num_ints)]

    print(num_ints)
    print(*ints)
    print("Case #{}: {}".format(i+1, sum(ints)), file=stderr)
