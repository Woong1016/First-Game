#pragma once

// 범용 게임 오브젝트 관리 클래스
// '오브젝트' 벡터로 게임 등장 사물 관리
// <이름, 오브젝트> 맵으로 게임 내 사물 총괄

class PoolingManager
{    
public:
    PoolingManager();
    ~PoolingManager();

    virtual void Update();
    void Render(HDC hdc);

    GameObject* Pop(string key);

    virtual void CreateObjects(string key, UINT poolSize) = 0;

    void ClearObjects(string key);

protected:
    typedef vector<GameObject*> Objects;
    map<string, Objects> totalObjects;
};