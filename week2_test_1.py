def solution(seat):
    visited = set()

    for x, y in seat:
        if (x, y) not in visited:
            visited.add((x, y))
        else:
            continue

    return len(visited)
