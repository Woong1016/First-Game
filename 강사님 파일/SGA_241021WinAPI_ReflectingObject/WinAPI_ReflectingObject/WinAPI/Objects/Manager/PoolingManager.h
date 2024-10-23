#pragma once

// ���� ���� ������Ʈ ���� Ŭ����
// '������Ʈ' ���ͷ� ���� ���� �繰 ����
// <�̸�, ������Ʈ> ������ ���� �� �繰 �Ѱ�

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