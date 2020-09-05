def solution(brown, red):
    width, height = 0, 0
    total = brown + red

    for height in range(1, total):
        width = total // height
        print(width, height)
        if (width - 2) * (height - 2) == red:
            return [width, height]
