import sys

lower_case = [
    "a",
    "b",
    "c",
    "d",
    "e",
    "f",
    "g",
    "h",
    "i",
    "j",
    "k",
    "l",
    "m",
    "n",
    "o",
    "p",
    "q",
    "r",
    "s",
    "t",
    "u",
    "v",
    "w",
    "x",
    "y",
    "z",
]

upper_case = [
    "A",
    "B",
    "C",
    "D",
    "E",
    "F",
    "G",
    "H",
    "I",
    "J",
    "K",
    "L",
    "M",
    "N",
    "O",
    "P",
    "Q",
    "R",
    "S",
    "T",
    "U",
    "V",
    "W",
    "X",
    "Y",
    "Z",
]

line = list(sys.stdin.readline().rstrip())

for i in range(len(line)):
    if line[i] in upper_case:
        idx = upper_case.index(line[i])
        idx += 13
        if idx > 25:
            idx %= 25 + 1
        line[i] = upper_case[idx]

    elif line[i] in lower_case:
        idx = lower_case.index(line[i])
        idx += 13
        if idx > 25:
            idx %= 25 + 1
        line[i] = lower_case[idx]

print("".join(line))
