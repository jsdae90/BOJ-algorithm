import sys

while True:
    line = sys.stdin.readline().rstrip("\n")
    upper, lower, blank, digit = 0, 0, 0, 0

    if not line:
        break

    for i in line:
        if i.isupper():
            upper += 1
        elif i.islower():
            lower += 1
        elif i.isdigit():
            digit += 1
        elif i.isspace():
            blank += 1
    sys.stdout.write("{} {} {} {}\n".format(lower, upper, digit, blank))
