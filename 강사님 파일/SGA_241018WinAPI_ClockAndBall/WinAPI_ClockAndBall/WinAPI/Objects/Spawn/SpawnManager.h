#pragma once

// 직사각형을 만드는 기능....을 다시 씬에서 쉽게 호출하게 만들려고 준비한 싱글턴

class SpawnManager : public Singleton<SpawnManager>
{
private:
    const UINT POOL_SIZE = 50;
    const float SPAWN_TIME = 1.0f;

private:
    friend class Singleton;

    SpawnManager();
    ~SpawnManager();

public:
    void Update();
    void Render(HDC hdc);

    void DestoryObject(Vector2 point);
    void DestoryObject(Rect* rect);

public:
    vector<SpawnObject*> spawnObjects; // <- 만들어진 직사각형이 들어가는 벡터

    float playTime = 0.0f;

    UINT score = 0;
};