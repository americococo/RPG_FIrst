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
			case 1://무시
				break;
			default:
				//맵데이터
				if (NULL != token)
				{
					for (int x = 1; x <= _StageMaxX; x++)
					{
						char * roomCode= token;

						if (token[0] != '-')
						{
							Room * room = new Room();
							room->Init(roomCode, x, row);
							_roomList.push_back(room);
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
	std::vector<Room *>::iterator itr;

	for (itr = _roomList.begin(); itr != _roomList.end(); itr++)
	{
		(*itr)->Update(deltaTime);
	}
}
void Stage::render()
{
	std::vector<Room *>::iterator itr;

	for (itr = _roomList.begin(); itr != _roomList.end(); itr++)
	{
		(*itr)->render();
	}
}

bool Stage::checkingClearStage()
{
	return false;// 스테이지 클리어
}