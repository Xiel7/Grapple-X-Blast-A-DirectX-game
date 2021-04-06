#pragma once
#include "GameObject.h"
#include "BlastCannon.h"
#include "GrappleGun.h"
#define PLAYER_SPRITE "assets/player/player_spritesheet.png"


class Player : public GameObject
{
private:
	static Player* instance;
	float speed;
	bool isSwitched;
	D3DXVECTOR3 playerBbY;//player head & feet bounding box size
	D3DXVECTOR3 playerBbX;//player hand & body bouding box size
	int ammoAmount;
	int keyAmount;
	bool showKeyMsg;
	int playerKeyStatus;
	Player();
	~Player();

public:
	BlastCannon* blastCannon;
	GrappleGun* grappleGun;
	GameObject* currentWeapon;
	static Player* getInstance();
	void Initialize(LPDIRECT3DDEVICE9 device);
	void Update();
	void Draw();
	void ReleaseInstance();
	float getBlastOffAngle();
	D3DXVECTOR3 getPlayerBbSize();

	void Draw(std::string msg);
	
	//void switchWeapon();
	//void action();
	bool isMoving;
	void setAmmoAmount(int num) { this->ammoAmount = num; };
	void updateAmmoAmount(int num) { this->ammoAmount += num; };
	int getAmmoAmount() { return ammoAmount; };
	void updateKeyAmount(int num) { this->keyAmount += num; };
	int getKeyAmount() { return keyAmount; };
	void setShowKeyMsg(bool i) { this->showKeyMsg = i; };
	bool getShowKeyMsg() { return showKeyMsg; };
	
};

