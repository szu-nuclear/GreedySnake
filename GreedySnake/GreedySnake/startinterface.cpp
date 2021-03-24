#include "startinterface.h"
#include<windows.h>



void StartInterface::PrintFirst()//�ߴ���߳��ֵ���ȫ���ֵĹ���
{
	for (auto& p : startsnake)
	{
		p.Print();
		Sleep(m_speed);//����һ��ʱ��
	}
}

void StartInterface::PrintSecond()//�ߴ��������ƶ��Ĺ���
{
    
    for (int i = 10; i != 40; ++i) //��ͷ��Ҫ��10�ƶ���40
    {
        /*������ͷ����һ��λ�ã�������ѹ��startsnake�У����Ƴ���������βȥ��*/
        int j = (((i - 2) % 8) < 4) ? (15 + (i - 2) % 8) : (21 - (i - 2) % 8);       
        startsnake.emplace_back(Point(i, j));
        startsnake.back().Print();
        startsnake.front().Clear();
        startsnake.pop_front();
        Sleep(m_speed);
    }
   }

void StartInterface::PrintThird()
{
    while (!startsnake.empty() || textsnake.back().GetX() < 33)//���߻�û��ʧ������û�ƶ���ָ��λ��
    {
        if (!startsnake.empty()) //����߻�û��ʧ�������ƶ�
        {
            startsnake.front().Clear();
            startsnake.pop_front();
        }
        

        ClearText();//�����������
        PrintText();//���Ƹ���λ�ú������
        Sleep(m_speed);
    }
    
}

void StartInterface::PrintText()
{
    for ( auto& t : textsnake)
    {
        if (t.GetX() > 0)
        {
            
            t.Print();
        }
        
    }
}

void StartInterface::ClearText()
{
    for (auto& point : textsnake) 
    {
        if (point.GetX() >= 0)//���
        {
            point.Clear();
        }
        //���������������ƶ�һ��         
        point.ChangePosition(point.GetX()+1 , point.GetY());
    }
}


void StartInterface::Action ()
{
    PrintFirst();
    PrintSecond();
    PrintThird();
}
