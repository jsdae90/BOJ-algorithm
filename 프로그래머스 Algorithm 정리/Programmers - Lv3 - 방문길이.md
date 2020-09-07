### Programmers - Lv3 - 방문길이

#### 문제 설명

---

게임 캐릭터를 4가지 명령어를 통해 움직이려 합니다. 명령어는 다음과 같습니다.

- U: 위쪽으로 한 칸 가기
- D: 아래쪽으로 한 칸 가기
- R: 오른쪽으로 한 칸 가기
- L: 왼쪽으로 한 칸 가기

캐릭터는 좌표평면의 (0, 0) 위치에서 시작합니다. 좌표평면의 경계는 왼쪽 위(-5, 5), 왼쪽 아래(-5, -5), 오른쪽 위(5, 5), 오른쪽 아래(5, -5)로 이루어져 있습니다.

<img src="https://res.cloudinary.com/jistring93/image/upload/v1495542181/%EB%B0%A9%EB%AC%B8%EA%B8%B8%EC%9D%B41_qpp9l3.png">

예를 들어, "ULURRDLLU"로 명령했다면

| 1    | 2    | 3    | 4    | 5    | 6    | 7    | 8    | 9    |
| ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- |
| U    | L    | U    | R    | R    | D    | L    | L    | U    |

- 1번 명령어부터 7번 명령어까지 다음과 같이 움직입니다.

<img src="https://res.cloudinary.com/jistring93/image/upload/v1495542704/%EB%B0%A9%EB%AC%B8%EA%B8%B8%EC%9D%B43_sootjd.png">

- 8번 명령어부터 9번 명령어까지 다음과 같이 움직입니다.

<img src="https://res.cloudinary.com/jistring93/image/upload/v1495542767/%EB%B0%A9%EB%AC%B8%EA%B8%B8%EC%9D%B44_hlpiej.png">



이때, 우리는 게임 캐릭터가 지나간 길 중 **캐릭터가 처음 걸어본 길의 길이**를 구하려고 합니다. 예를 들어 위의 예시에서 게임 캐릭터가 움직인 길이는 9이지만, 캐릭터가 처음 걸어본 길의 길이는 7이 됩니다. (8, 9번 명령어에서 움직인 길은 2, 3번 명령어에서 이미 거쳐 간 길입니다)

단, 좌표평면의 경계를 넘어가는 명령어는 무시합니다.

예를 들어, "LULLLLLLU"로 명령했다면

| 1    | 2    | 3    | 4    | 5    | 6    | 7    | 8    | 9    |
| ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- |
| L    | U    | L    | L    | L    | L    | L    | L    | U    |

- 1번 명령어부터 6번 명령어대로 움직인 후, 7, 8번 명령어는 무시합니다. 다시 9번 명령어대로 움직입니다.

<img src="https://res.cloudinary.com/jistring93/image/upload/v1495544946/%EB%B0%A9%EB%AC%B8%EA%B8%B8%EC%9D%B46_nzhumd.png">

이 때, 캐릭터가 처음 걸어본 길의 길이는 7이 됩니다.

명령어가 매개변수 dirs로 주어질 때, 게임 캐릭터가 처음 걸어본 길의 길이를 구하여 return 하는 solution 함수를 완성해 주세요.



<br>


#### 제한사항

---

- dirs는 string형으로 주어지며, 'U', 'D', 'R', 'L' 이외에 문자는 주어지지 않습니다.
- dirs의 길이는 500 이하의 자연수입니다.



<br>

#### 입출력 예

---

| dirs        | answer |
| ----------- | ------ |
| "ULURRDLLU" | 7      |
| "LULLLLLLU" | 7      |

<br>

#### 제출 코드

---

```python
def solution(dirs):
    visited = set()
    cmd = {'L' : (0, -1), 'R': (0, 1), 'U': (1, 0),  'D': (-1, 0)}
    x, y = 0, 0
    
    for dir in dirs:
        dir_x, dir_y = cmd[dir]
        if abs(x + dir_x) <= 5 and abs(y + dir_y) <= 5:
            next_x, next_y = x + dir_x, y + dir_y
            if (x, y, next_x, next_y) not in visited:
                visited.add((x, y, next_x, next_y))
                visited.add((next_x, next_y, x, y))
            x, y = next_x, next_y
            
    return len(visited)/2
```

가장 먼저, visited를 이용하여 기존에 이용했던 길이 중복되지 않게 체크하기 위함과 더불어

visited에 있는지 없는지를 계속 체크해야하기때문에 visited를 set으로 사용했다.

리스트로 하게 된다면, 중복에 대한 별도 체크도 필요하고 최대 O(len)을 dirs만큼 탐색해야 하기 때문이다.

또한, 딕셔너리를 이용해 명령어를 key, 명령어에 따른 좌표이동값을 value로 두었다.


<br>


#### 문제 풀이

---

길을 이용했는지 여부를 확인하기 위해 visited를 선언하고, 명령어에 따른 좌표이동값을 저장하고, 

초기 x, y좌표 값인 0을 넣어준다.

이후, dirs내의 명령어에 따른 x, y 좌표 이동값을 cmd에서 가져온다.

좌표가 -5 ~ 5의 값을 가져 -5에서 -1, 5에서 +1을 이동할 수 없기에

if문을 통해 기존위치에서 이동한 값의 절대값이 5 이하일 경우에 하위 코드를 진행하도록 했다.

또한, (1,0) -> (1, 1)로 이동하는것과 (1,1) -> (1,0)으로 이동한 길이 같기에

`(x, y, next_x, next_y)`가 visited에 없을 경우

`(x, y, next_x, next_y)`와 `(next_x, next_y, x, y)`와 같이 A->B, B->A 이동에 대해 visited에 넣는다.

그리고 x,y를 변경하며 모든 명령에 대해 이동을 수행한다.

마지막으로, visited에는 한 길에 대해 A->B, B->A와 같이 2개가 등록되기 때문에

최종적으로 `len(visited)`를 2로 나누어 return해준다.
