#include "map.h"
#include <windows.h>

void Map::PrintInitmap()
{
	for (auto& p : initmap)
	{
		p.Print();
		Sleep(10);//Ӫ�춯��Ч��
	}
}
