def solution(board, nums):
    col_line = []
    diag_line_1 = []
    diag_line_2 = []
    bingo = 0

    nums = set(nums)

    for line in board:
        for idx in range(len(line)):
            if line[idx] in nums:
                line[idx] = 0

    def col_list(array, i):
        return [row[i] for row in array]

    for row in range(len(board)):
        col_line.append(col_list(board, row))

    for idx in range(len(board)):
        if board[idx][idx] != 0:
            diag_line_1 = False
            break
        diag_line_1.append(board[idx][idx])

    x = 0
    y = len(board) - 1

    for _ in range(len(board)):
        if board[x][y] != 0:
            diag_line_2 = False
            break
        diag_line_2.append(board[x][y])
        x += 1
        y -= 1

    for line in board:
        if sum(line) == 0:
            bingo += 1

    for line in col_line:
        if sum(line) == 0:
            bingo += 1

    for diag in diag_line_1, diag_line_2:
        if diag == False:
            continue

        elif sum(diag) == 0:
            bingo += 1

    return bingo
