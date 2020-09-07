### Programmers - Lv2 - 기능개발

#### 문제 설명

---

프로그래머스 팀에서는 기능 개선 작업을 수행 중입니다. 각 기능은 진도가 100%일 때 서비스에 반영할 수 있습니다.

또, 각 기능의 개발속도는 모두 다르기 때문에 뒤에 있는 기능이 앞에 있는 기능보다 먼저 개발될 수 있고, 이때 뒤에 있는 기능은 앞에 있는 기능이 배포될 때 함께 배포됩니다.

먼저 배포되어야 하는 순서대로 작업의 진도가 적힌 정수 배열 progresses와 각 작업의 개발 속도가 적힌 정수 배열 speeds가 주어질 때 각 배포마다 몇 개의 기능이 배포되는지를 return 하도록 solution 함수를 완성하세요.

<br>

#### 제한사항

---

- 작업의 개수(progresses, speeds배열의 길이)는 100개 이하입니다.
- 작업 진도는 100 미만의 자연수입니다.
- 작업 속도는 100 이하의 자연수입니다.
- 배포는 하루에 한 번만 할 수 있으며, 하루의 끝에 이루어진다고 가정합니다. 예를 들어 진도율이 95%인 작업의 개발 속도가 하루에 4%라면 배포는 2일 뒤에 이루어집니다.

<br>

#### 입출력 예

---

| progresses               | speeds             | return    |
| ------------------------ | ------------------ | --------- |
| [93, 30, 55]             | [1, 30, 5]         | [2, 1]    |
| [95, 90, 99, 99, 80, 99] | [1, 1, 1, 1, 1, 1] | [1, 3, 2] |

<br>

#### 입출력 예 설명

---

##### 입출력 예 #1

첫 번째 기능은 93% 완료되어 있고 하루에 1%씩 작업이 가능하므로 7일간 작업 후 배포가 가능합니다.
두 번째 기능은 30%가 완료되어 있고 하루에 30%씩 작업이 가능하므로 3일간 작업 후 배포가 가능합니다. 하지만 이전 첫 번째 기능이 아직 완성된 상태가 아니기 때문에 첫 번째 기능이 배포되는 7일째 배포됩니다.
세 번째 기능은 55%가 완료되어 있고 하루에 5%씩 작업이 가능하므로 9일간 작업 후 배포가 가능합니다.

따라서 7일째에 2개의 기능, 9일째에 1개의 기능이 배포됩니다.

<br>

##### 입출력 예 #2

모든 기능이 하루에 1%씩 작업이 가능하므로, 작업이 끝나기까지 남은 일수는 각각 5일, 10일, 1일, 1일, 20일, 1일입니다. 어떤 기능이 먼저 완성되었더라도 앞에 있는 모든 기능이 완성되지 않으면 배포가 불가능합니다.

따라서 5일째에 1개의 기능, 10일째에 3개의 기능, 20일째에 2개의 기능이 배포됩니다.



#### 제출 코드

---

##### 1차 제출 코드

```python
def solution(progresses, speeds):
    answer = []
    days = len(progresses) * [0]
    
    for idx in range(len(progresses)):
        while progresses[idx] < 100:
            days[idx] += 1
            progresses[idx] += speeds[idx]
            
    for idx in range(1, len(days)):
        if days[idx] < days[idx-1]:
            days[idx] = days[idx-1]
    
    for day in sorted(set(days)):
        answer.append(days.count(day))
        
    return answer
```

progresses 내 각 기능들이 완성(100 이상의 값)이 되려면 몇일이 걸리는지 체크하기 위해

첫번째 for문 내 while문을 사용했다.

이후, progresses 내 기능의 순서대로 제출이 가능하여 기능 개발 완수가 `[5일, 1일, 10일]`이 걸릴 경우

`[5일, 5일, 10일]`로서 `5일 : 2개, 10일 : 1개` 제출이 가능하기에

for문을 통해 이전 작업완수일이 현재 작업완수일보다 값이 클 경우, 이전 작업완수일의 값과 같이 해주었다.

이후, 마지막 for문을 통해 answer에 일자별 정렬된 unique한 값들을 돌며

일자별 건수를 count하여 return해주었다.

<br>

<br>

##### 최종 제출 코드

```python
import math

def solution(progresses, speeds):
    answer = []
    remain_day = []
    
    for i in range(len(progresses)):
        remain_day.append(math.ceil((100-progresses[i])/speeds[i]))
    
    for i in range(1, len(progresses)):
        if remain_day[i] <= remain_day[i-1]:
            remain_day[i] = remain_day[i-1]
    
    cnt = 1
    for i in range(1, len(remain_day)):
        if remain_day[i] == remain_day[i-1]:
            cnt += 1
        else:
            answer.append(cnt)
            cnt = 1
    
    answer.append(cnt)
    
    return answer
```

더 나은 방식이 있는지 인터넷 검색을 하던 중, 기능에 따라 남은 작업량을 속도로 나누어 올림해줌으로써

남은 일자를 계산하는 코드를 발견하고, 이를 적용했다.

방식 자체는 기존 코드와 다르지 않지만, 일자 계산과 count 방식이 차이가 있다.

그리고, 해당 코드 또한 for문을 3번 사용하지만 코드 속도가 더욱 개선되었다.