#include "Framework.h"

SpawnManager::SpawnManager()
{
    spawnObjects.resize(POOL_SIZE);
    for (SpawnObject*& spawnObject : spawnObjects)
    {
        spawnObject = new SpawnObject();
    }
}

SpawnManager::~SpawnManager()
{
    for (SpawnObject* spawnObject : spawnObjects)
        delete spawnObject;
}

void SpawnManager::Update()
{
    // 이 싱글턴이 씬에서 호출되고, 업데이트가 진행되면.....

    // 아래 조건문에 따라 (좌클릭 시 실행)

    // 직사각형이 만들어져서 벡터 안에 들어가게 된다

    // (지우는 건 이 싱글턴만으론 불가능하니까 외부에서 필요할 때 호출하도록 함)

    if(KEY_DOWN(VK_LBUTTON))
    {
        for (SpawnObject* spawnObjecct : spawnObjects)
        {
            if (!spawnObjecct->Active())
            {
                spawnObjecct->Spawn();
                playTime = 0.0f;
                break;
            }
        }
    }

    for (SpawnObject* spawnObjecct : spawnObjects)
    {
        spawnObjecct->Update();
    }
}

void SpawnManager::Render(HDC hdc)
{
    for (SpawnObject* spawnObjecct : spawnObjects)
    {
        spawnObjecct->Render(hdc);
    }

    wstring scoreText = L"Score : " + to_wstring(score);
    TextOut(hdc, (int)CENTER_X, 0, scoreText.c_str(),
        (int)scoreText.size());
}

void SpawnManager::DestoryObject(Vector2 point)
{
    for (SpawnObject* spawnObject : spawnObjects)
    {
        if (spawnObject->IsCollision(point))
        {
            spawnObject->Destroy();
            score++;
            return;
        }
    }
}

void SpawnManager::DestoryObject(Rect* rect)
{
    for (SpawnObject* spawnObject : spawnObjects)
    {
        if (spawnObject->IsCollision(rect))
        {
            spawnObject->Destroy();
            score++;
            return;
        }
    }
}
