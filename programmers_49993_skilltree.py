def solution(skill, skill_trees):
    cnt = 0
    for tree in skill_trees:
        a = [tree.index(i) for i in skill if i in tree]
        a_ = sorted(a)
        if a == a_ and all(i in tree for i in skill[: len(a)]):
            cnt += 1
    return cnt
