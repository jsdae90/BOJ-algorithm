def solution(board, moves):
    answer = 0
    basket = []
    for i in moves:
        for j in range(len(board)):
            if board[j][i - 1] != 0:
                basket.append(board[j][i - 1])
                board[j][i - 1] = 0
                if len(basket) > 1 and basket[-1] == basket[-2]:
                    answer += 2
                    del basket[-2:]
                break
    return answer
