#pragma once
#include "GameObject.h"
#include "BlastCannon.h"
#define PLAYER_SPRITE "assets/player/player_spritesheet.png"


class Player : public GameObject
{
private:
	static Player* instance;
	float speed;

	
	Player();
	~Player();

public:
	BlastCannon blastCannon;
	static Player* getInstance();
	void Initialize(LPDIRECT3DDEVICE9 device);
	void Begin();
	void Update();
	//void SetTransform();
	void Draw();
	void ReleaseInstance();
};

