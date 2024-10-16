#pragma once

// ���� �Ŵ��� (�̱���, �� �ϳ����� ���� ���� Ŭ����!)

class GameManager : public Singleton<GameManager>
{
private:
    friend class Singleton;

    GameManager();
    ~GameManager();

public:
    void Init(HWND hWnd);   // �������� ���� ������
                            // (������ �̱������� �ϳ��� �ְ�)
                            // (ȣ��� ���ÿ� ��ü�� ��������Ƿ�)
                            
    // WndProc���� �ô� �� �Լ�
    void Update();          // ������Ʈ : ���� �� ���� ���ΰ�ħ ���
    void Render();          // ���� : ȭ�� ǥ�� ���

    HWND GetHWND() { return hWnd; } // ȣ���ϸ� ������ ���� ����

private:
    static GameManager* instance;

    Scene* scene;                   // "��" = ���
                                    // ���� �Ŵ����� ������ �����Ѵٸ�
                                    // ���� �� "��"�� �ٷ�
                                    // ���� �� ���� ����, �ٽ� ����
                                    // "���� ���� ���� ������ �� ��ü"��
                                    // �����Ѵ�!
                                    // �ٸ� ����, �� "��"�� ��
                                    // "�� ���� ���̴� ����"�̴�.

                    // �׷���, �� "��"��....
                    // �츮�� ���������� �ڵ��ϴ� ����.

    HWND hWnd = nullptr;
    HDC hdc = nullptr;

    HDC hBackDC = nullptr;
    HBITMAP hBackBitmap = nullptr;
};