#pragma once

// 직사각형을 좀 더 쉽게 만들기 위해 준비했던 클래스
// 랜덤으로 직사각형을 만들어 뿌린다

class SpawnObject : public Rect
{
private:
    const float MIN_SIZE = 50.0f;
    const float MAX_SIZE = 200.0f;
    const float MIN_LIFE_TIME = 3;
    const float MAX_LIFE_TIME = 10;

public:
    SpawnObject();
    ~SpawnObject();

    void Update();
    void Render(HDC hdc);

    void Spawn();
    void Destroy();

private:    
    float lifeTime = 0;
    float playTime = 0;

    HBRUSH hBrush = nullptr;
    // HBursh : 브러시 핸들러. 색깔 표시, 지정, 출력 등을 수행
    //          핸들러란 "이벤트 함수를 이용해서 특정 지시를 받으면 대응하게 만든 기능"
    //          여기서는 기능을 대기시키고 있다가, '색깔, 스타일, 출력방법' 등에 대해
    //          개발자가 나중에 지시 코드를 제시하면 그에 맞추어서 연산을 수행한다
};