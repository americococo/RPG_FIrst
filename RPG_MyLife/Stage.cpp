#include "Stage.h"
#include "Room.h"

#include<fstream>

Stage::Stage(LPCWSTR StageDataFile)
{
	_StageDataFile = StageDataFile;
}


Stage::~Stage()
{

}


void Stage::Init()
{
	{
		int line = 0;
		int row=1;
		char record[1024 * 4];
		std::ifstream infile(_StageDataFile);
		while (!infile.eof())
		{
			infile.getline(record, 1024 * 4);

			char *token = strtok(record, ",");
			switch (line)
			{
			case 0:
				if (NULL != token)
				{
					token = strtok(NULL, ",");
					_StageMaxX = atoi(token);
					token = strtok(NULL, ",");
					_StageMaxY= atoi(token);
				}
				break;
			case 1://����
				break;
			default:
				//�ʵ�����
				if (NULL != token)
				{
					for (int x = 1; x <= _StageMaxX; x++)
					{
						char * roomCode= token;

						if (token[0] != '-')
						{
							Room * room = new Room();
							room->Init(roomCode, x, row);

							_roomList[std::make_pair(x,row)] = room;
						}

						token = strtok(NULL, ",");
					}
					row++;

				}
				break;
			}
			line++;
		}

	}
}
void Stage::Update(float deltaTime)
{



	std::map<std::pair<int,int>, Room*>::iterator itr;
	for (itr = _roomList.begin(); itr != _roomList.end(); itr++)
	{

		if (true == itr->second->CheckPlayer())
			itr->second->Update(deltaTime);
	}
}
void Stage::render()
{
	std::map<std::pair<int, int>, Room *>::iterator itr;

	for (itr = _roomList.begin(); itr != _roomList.end(); itr++)
	{
		if (true == itr->second->CheckPlayer())
			itr->second->render();
	}
}
Room * Stage::GetRoom(int mapX,int mapY)
{
	std::pair<int, int> p = std::make_pair(mapX,mapY);

	return _roomList[p];
}
bool Stage::checkingClearStage()
{
	return false;// �������� Ŭ����
}