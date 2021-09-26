#define _CRT_SECURE_NO_WARNINGS
#include <bangtal>
using namespace bangtal;
#include <cstdlib>
#include <ctime>
#include <time.h>

ScenePtr scene;
ObjectPtr puz[9], puz_original[9];
ObjectPtr start, restart, tt;

TimerPtr timer, limit;
float mixTime = 0.03f, limitT = 120.f, takenT;
int mixCount = 50;
char t[5];

clock_t tstart;

int blank;

//퍼즐의 인덱스를 반환하는 함수
int game_index(ObjectPtr p) {
    for (int i = 0; i < 9; i++)
        if (puz[i] == p) return i;
    return -1;
}

//해당 인덱스의 x좌표를 반환하는 함수
int index2x(int index) {
    return 70 + 171 * (index % 3);
}

//해당 인덱스의 y좌표를 반환하는 함수
int index2y(int index) {
    return 400 - 171 * (index / 3);
}

//퍼즐을 빈칸으로 이동
void move(int index) {
    auto piece = puz[index];

    puz[index] = puz[blank];
    puz[index]->locate(scene, index2x(index), index2y(index));
   
    puz[blank] = piece;
    puz[blank]->locate(scene, index2x(blank), index2y(blank));
 
    blank = index;
}

//빈칸으로 이동할 수 있는 퍼즐인지 확인하는 함수
bool check_move(int index) {
    if (blank % 3 > 0 && index == blank - 1) return true; //빈칸의 왼쪽 퍼즐
    if (blank % 3 < 2 && index == blank + 1) return true; //빈칸의 오른쪽 퍼즐
    if (blank / 3 > 0 && index == blank - 3) return true; //빈칸의 위쪽 퍼즐
    if (blank / 3 < 2 && index == blank + 3) return true; //빈칸의 아래쪽 퍼즐

    return false; //그 외 퍼즐은 이동할 수 없음
}

//빈칸으로 이동시킬 랜덤한 퍼즐의 인덱스를 반환하는 함수
int random_move() {
    int index = rand() % 9;

    //이동할 수 없는 퍼즐이면 다시 돌림
    while (!check_move(index)) {
        index = rand() % 9;
    }

    return index;
}

//게임을 시작하는 함수
void start_game() {
    //퍼즐섞기 타이머 작동
    mixCount = 50;
    timer->set(mixTime);
    timer->start();

    //시간제한 작동
    limit->set(limitT);
    limit->start();

    //걸린 시간 재기 시작
    tstart = clock();

    start->hide(); //시작버튼 숨기기
    restart->show(); //재시작버튼 보이기
}

//퍼즐을 풀었는지 확인하는 함수
bool check_end() {
    for (int i = 0; i < 9; i++) {
        if (puz[i] != puz_original[i]) return false;
    }

    return true;
}

//게임을 끝내는 함수
void end_game() {
    puz[8]->show();
    start->show();
    restart->hide();
    limit->stop();

    //걸린 시간을 계산
    clock_t tend = clock();
    takenT = (tend - tstart)/CLOCKS_PER_SEC;

    sprintf(t, "와우~혹시 당신은 퍼즐천재?\n걸린시간 : %.0f초", takenT);

    showMessage(t);
}

//게임 초기화
void init_game() {
    //불필요한 기본옵션 제거
    setGameOption(GameOption::GAME_OPTION_INVENTORY_BUTTON, false);
    setGameOption(GameOption::GAME_OPTION_MESSAGE_BOX_BUTTON, false);

    //배경 생성
    scene = Scene::create("퍼즐 맞추기", "배경.jpg");

    //퍼즐 생성
    char path[10];

    for (int i = 0; i < 9; i++) {
        sprintf(path, "%d.jpg", i + 1);
        puz[i] = Object::create(path, scene, index2x(i), index2y(i));

        puz[i]->setOnMouseCallback([&](auto p, auto x, auto y, auto action)->bool {
            int index = game_index(p);
            
            if (check_move(index)) {
                move(index);

                if (check_end()) {
                    end_game();
                }
            }

            return true;
            });
        puz_original[i] = puz[i];
    }

    //시작, 재시작 버튼 생성
    start = Object::create("start.png", scene, 250, 100);
    restart = Object::create("restart.png", scene, 700, 530);
    restart->hide();

    tt = Object::create("time.png", scene, 260, 590);

    //시작 버튼 누르면 게임 시작
    start->setOnMouseCallback([&](auto, auto, auto, auto)->bool {
        blank = 8;
        puz[8]->hide(); //빈칸 생성

        start_game();

        return true;
        });

    //타이머를 이용해 퍼즐 섞기
    timer = Timer::create(mixTime);
    timer->setOnTimerCallback([&](auto)->bool {
        move(random_move());

        mixCount--;
        if (mixCount > 0) {
            timer->set(mixTime);
            timer->start();
        }
    
        return true;
        });

    //시간제한이 끝나면 실패
    limit = Timer::create(limitT);
    showTimer(limit);
    limit->setOnTimerCallback([&](TimerPtr)->bool {
        showMessage("시간초과!!ㅠㅠ");

        return true;
        });

    //재시작버튼을 누르면 다시 섞고 시작
    restart->setOnMouseCallback([&](auto, auto, auto, auto)->bool {
        start_game();

            return true;
        });
    
    //게임 시작
    startGame(scene);
}

int main()
{
    srand((unsigned int)time(NULL)); //타이머를 작동시키려면 메인 함수에 있어야 함
    
    init_game();

    return 0;
}