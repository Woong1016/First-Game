#include "Framework.h"

//void Func(Object*& obj)
//{
//    obj = new Object();
//}

SpawnManager::SpawnManager()
{
    //spawnObjects.reserve(POOL_SIZE);//Capacity    
    //
    //for (UINT i = 0; i < POOL_SIZE; i++)
    //{
    //    SpawnObject* obj = new SpawnObject();
    //    spawnObjects.push_back(obj);
    //}
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
    //playTime += DELTA;
    //
    //if (playTime >= SPAWN_TIME)
    //{
    //    for (SpawnObject* spawnObjecct : spawnObjects)
    //    {
    //        if (!spawnObjecct->Active())
    //        {
    //            spawnObjecct->Spawn();
    //            playTime = 0.0f;
    //            break;
    //        }
    //    }
    //}

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
