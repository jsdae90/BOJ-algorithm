from itertools import product


def solution(monster, S1, S2, S3):
    board_num = S1 + S2 + S3 + 1
    monster_in = set([(m - 1) for m in monster if m <= board_num])
    s1_list = list(range(1, S1 + 1))
    s2_list = list(range(1, S2 + 1))
    s3_list = list(range(1, S3 + 1))
    temp = [s1_list, s2_list, s3_list]
    total_case_list = product(*temp)

    case_num = 0
    for case in total_case_list:
        if sum(case) in monster_in:
            case_num += 1

    print(case_num)

    return int((1 - case_num / S1 / S2 / S3) * 1000)
