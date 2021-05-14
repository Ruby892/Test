#include "stdafx.h"
#include "MainScene.h"
#include "Circle.h"
#include "Circle1.h"
#include "Circle2.h"
#include "Circle3.h"
#include "GameScene.h"

MainScene::MainScene()
{
	Offset = GameMgr::GetInst()->m_offset;
		
	m_Delay = 1.35f + (Offset / 100);
	Note = 1;
	Bote = 1;

	mciSendString(L"play C:\\Sound\\Stage1.wav", NULL, 0, NULL);
}

MainScene::~MainScene()
{
}

void MainScene::Init()
{
	m_BG = Sprite::Create(L"Painting/BG/BG1.png");
	m_BG->SetPosition(1920 / 2, 1080 / 2);

	m_Text = new TextMgr();
	m_Text->Init(32, true, false, "Arial");
	m_Text->SetColor(255, 255, 255, 255);

	m_Ga = Sprite::Create(L"Painting/Game.png");
	m_Ga->SetPosition(1920 / 2, 1080 / 2);

	m_Pan = Sprite::Create(L"Painting/Pan.png");
	m_Pan->SetPosition(1920 / 2, 1080 / 2 - 150);

	m_Pan1 = Sprite::Create(L"Painting/Pan.png");
	m_Pan1->SetPosition(1920 / 2, 1080 / 2 + 150);

	m_Pan2 = Sprite::Create(L"Painting/Pan1.png");
	m_Pan2->SetPosition(1920 / 2 - 150, 1080 / 2);

	m_Pan3 = Sprite::Create(L"Painting/Pan1.png");
	m_Pan3->SetPosition(1920 / 2 + 150, 1080 / 2);

}

void MainScene::Release()
{
}

void MainScene::Update(float deltaTime, float time)
{
	m_NowTick += deltaTime;

	if (INPUT->GetButtonDown())
	{
		SceneDirector::GetInst()->ChangeScene(new GameScene());
		INPUT->ButtonDown(false);
		mciSendString(L"stop C:\\Sound\\Stage1.wav", NULL, 0, NULL);
		GameMgr::GetInst()->y = 1;
		GameMgr::GetInst()->m_300 = 0;
		GameMgr::GetInst()->m_100 = 0;
		GameMgr::GetInst()->m_50 = 0;
		GameMgr::GetInst()->m_acc = 0;
		GameMgr::GetInst()->m_Combo = 0;
		GameMgr::GetInst()->m_miss = 0;
		GameMgr::GetInst()->count = 0;
		GameMgr::GetInst()->m_Score = 0;
		Sleep(100);
	}
}

void MainScene::Render()
{
	m_BG->Render();
	m_Ga->Render();
	m_Pan->Render();
	m_Pan1->Render();
	m_Pan2->Render();
	m_Pan3->Render();

	/*
	ObjMgr->AddObject(new Circle(1920 / 2, 1080 / 2 - 400), "Ciecle");
	ObjMgr->AddObject(new Circle1(1920 / 2 - 400, 1080 / 2), "Ciecle1");
	ObjMgr->AddObject(new Circle2(1920 / 2, 1080 / 2 + 400), "Ciecle");
	ObjMgr->AddObject(new Circle3(1920 / 2 + 400, 1080 / 2), "Ciecle1");
	*/

	//노트생성

	if (Bote == 6)
		Note = 3;
	if (Bote == 7)
		Note = 1;
	if (Bote == 8)
		Note = 2;
	if (Bote == 9)
		Note = 3;
	if (Bote == 10)
		Note = 4;
	if (Bote == 11)
		Note = 2;
	if (Bote == 12)
		Note = 1;
	if (Bote == 13)
		Note = 4;
	if (Bote == 14)
		Note = 1;
	if (Bote == 18)
		Note = 3;
	if (Bote == 21)
		Note = 2;
	if (Bote == 22)
		Note = 4;
	if (Bote == 23)
		Note = 2;
	if (Bote == 24)
		Note = 3;
	if (Bote == 25)
		Note = 1;
	if (Bote == 26)
		Note = 2;
	if (Bote == 27)
		Note = 3;
	if (Bote == 28)
		Note = 1;
	if (Bote == 29)
		Note = 2;
	if (Bote == 30)
		Note = 4;
	if (Bote == 31)
		Note = 3;
	if (Bote == 32)
		Note = 1;
	if (Bote == 33)
		Note = 4;
	if (Bote == 34)
		Note = 2;
	if (Bote == 35)
		Note = 4;
	if (Bote == 36)
		Note = 3;
	if (Bote == 37)
		Note = 1;
	if (Bote == 38)
		Note = 4;
	if (Bote == 39)
		Note = 3;
	if (Bote == 40)
		Note = 2;
	if (Bote == 41)
		Note = 1;
	if (Bote == 42)
		Note = 2;
	if (Bote == 43)
		Note = 4;
	if (Bote == 44)
		Note = 3;
	if (Bote == 45)
		Note = 4;
	if (Bote == 46)
		Note = 3;
	if (Bote == 47)
		Note = 2;
	if (Bote == 48)
		Note = 1;
	if (Bote == 49)
		Note = 4;
	if (Bote == 50)
		Note = 2;
	if (Bote == 51)
		Note = 3;
	if (Bote == 52)
		Note = 1;
	if (Bote == 53)
		Note = 4;
	if (Bote == 54)
		Note = 3;
	if (Bote == 55)
		Note = 1;
	if (Bote == 56)
		Note = 2;
	if (Bote == 57)
		Note = 3;
	if (Bote == 58)
		Note = 1;
	if (Bote == 59)
		Note = 2;
	if (Bote == 60)
		Note = 4;
	if (Bote == 61)
		Note = 3;
	if (Bote == 62)
		Note = 1;
	if (Bote == 63)
		Note = 3;
	if (Bote == 64)
		Note = 2;
	if (Bote == 65)
		Note = 4;
	if (Bote == 66)
		Note = 3;
	if (Bote == 67)
		Note = 1;
	if (Bote == 68)
		Note = 4;
	if (Bote == 69)
		Note = 3;
	if (Bote == 70)
		Note = 2;
	if (Bote == 71)
		Note = 1;
	if (Bote == 72)
		Note = 2;
	if (Bote == 73)
		Note = 4;
	if (Bote == 74)
		Note = 3;
	if (Bote == 75)
		Note = 4;
	if (Bote == 76)
		Note = 3;
	if (Bote == 77)
		Note = 2;
	if (Bote == 78)
		Note = 1;
	if (Bote == 79)
		Note = 4;
	if (Bote == 80)
		Note = 2;
	if (Bote == 81)
		Note = 3;
	if (Bote == 82)
		Note = 1;
	if (Bote == 83)
		Note = 4;
	if (Bote == 84)
		Note = 1;
	if (Bote == 85)
		Note = 3;
	if (Bote == 86)
		Note = 1;
	if (Bote == 87)
		Note = 3;
	if (Bote == 88) {
		Note = 4;
		Bote2 = 1;
	}
	if (Bote == 89)
		Note = 1;
	if (Bote == 90)
		Note = 2;
	if (Bote == 91)
		Note = 4;
	if (Bote == 92) {
		Note = 1;
		Bote3 = 1;
	}
	if (Bote == 93)
		Note = 2;
	if (Bote == 94)
		Note = 4;
	if (Bote == 95)
		Note = 1;
	if (Bote == 96) {
		Note = 2;
		Bote4 = 1;
	}
	if (Bote == 97)
		Note = 1;
	if (Bote == 98)
		Note = 3;
	if (Bote == 99)
		Note = 4;
	if (Bote == 100) {
		Note = 3;
		Bote1 = 1;
	}
	if (Bote == 101)
		Note = 2;
	if (Bote == 102)
		Note = 1;
	if (Bote == 103)
		Note = 3;
	if (Bote == 104) {
		Note = 4;
		Bote2 = 1;
	}
	if (Bote == 105)
		Note = 1;
	if (Bote == 106)
		Note = 3;
	if (Bote == 107)
		Note = 2;
	if (Bote == 108) {
		Note = 1;
		Bote3 = 1;
	}
	if (Bote == 109)
		Note = 4;
	if (Bote == 110)
		Note = 3;
	if (Bote == 111)
		Note = 1;
	if (Bote == 112) {
		Note = 2;
		Bote4 = 1;
	}
	if (Bote == 113)
		Note = 3;
	if (Bote == 114)
		Note = 1;
	if (Bote == 115)
		Note = 4;
	if (Bote == 116) {
		Note = 3;
		Bote1 = 1;
	}
	if (Bote == 117)
		Note = 2;
	if (Bote == 118)
		Note = 3;
	if (Bote == 119)
		Note = 1;
	if (Bote == 120) {
		Note = 4;
		Bote2 = 1;
	}
	if (Bote == 121)
		Note = 1;
	if (Bote == 122)
		Note = 4;
	if (Bote == 123)
		Note = 2;
	if (Bote == 124) {
		Note = 1;
		Bote3 = 1;
	}
	if (Bote == 125)
		Note = 2;
	if (Bote == 126)
		Note = 1;
	if (Bote == 127)
		Note = 3;
	if (Bote == 128) {
		Note = 2;
		Bote4 = 1;
	}
	if (Bote == 129)
		Note = 1;
	if (Bote == 130)
		Note = 3;
	if (Bote == 131)
		Note = 4;
	if (Bote == 132) {
		Note = 3;
		Bote1 = 1;
	}
	if (Bote == 133)
		Note = 2;
	if (Bote == 134)
		Note = 4;
	if (Bote == 135)
		Note = 2;
	if (Bote == 136)
		Note = 3;
	if (Bote == 137)
		Note = 1;
	if (Bote == 138)
		Note = 4;
	if (Bote == 139)
		Note = 3;
	if (Bote == 140)
		Note = 2;
	if (Bote == 141)
		Note = 4;
	if (Bote == 142)
		Note = 1;
	if (Bote == 143)
		Note = 3;
	if (Bote == 144)
		Note = 2;
	if (Bote == 145)
		Note = 4;
	if (Bote == 146)
		Note = 1;
	if (Bote == 147)
		Note = 2;
	if (Bote == 148)
		Note = 1;
	if (Bote == 149)
		Note = 3;
	if (Bote == 150)
		Note = 1;
	if (Bote == 151)
		Note = 3;
	if (Bote == 152) {
		Note = 4;
		Bote2 = 1;
	}
	if (Bote == 153)
		Note = 1;
	if (Bote == 154)
		Note = 2;
	if (Bote == 155)
		Note = 4;
	if (Bote == 156) {
		Note = 1;
		Bote3 = 1;
	}
	if (Bote == 157)
		Note = 2;
	if (Bote == 158)
		Note = 4;
	if (Bote == 159)
		Note = 1;
	if (Bote == 160) {
		Note = 2;
		Bote4 = 1;
	}
	if (Bote == 161)
		Note = 1;
	if (Bote == 162)
		Note = 3;
	if (Bote == 163)
		Note = 4;
	if (Bote == 164) {
		Note = 3;
		Bote1 = 1;
	}
	if (Bote == 165)
		Note = 2;
	if (Bote == 166)
		Note = 1;
	if (Bote == 167)
		Note = 3;
	if (Bote == 168) {
		Note = 4;
		Bote2 = 1;
	}
	if (Bote == 169)
		Note = 1;
	if (Bote == 170)
		Note = 3;
	if (Bote == 171)
		Note = 2;
	if (Bote == 172) {
		Note = 1;
		Bote3 = 1;
	}
	if (Bote == 173)
		Note = 4;
	if (Bote == 174)
		Note = 3;
	if (Bote == 175)
		Note = 1;
	if (Bote == 176) {
		Note = 2;
		Bote4 = 1;
	}
	if (Bote == 177)
		Note = 3;
	if (Bote == 178)
		Note = 1;
	if (Bote == 179)
		Note = 4;
	if (Bote == 180) {
		Note = 3;
		Bote1 = 1;
	}
	if (Bote == 181)
		Note = 2;
	if (Bote == 182)
		Note = 3;
	if (Bote == 183)
		Note = 1;
	if (Bote == 184) {
		Note = 4;
		Bote2 = 1;
	}
	if (Bote == 185)
		Note = 1;
	if (Bote == 186)
		Note = 4;
	if (Bote == 187)
		Note = 2;
	if (Bote == 188) {
		Note = 1;
		Bote3 = 1;
	}
	if (Bote == 189)
		Note = 2;
	if (Bote == 190)
		Note = 1;
	if (Bote == 191)
		Note = 3;
	if (Bote == 192) {
		Note = 2;
		Bote4 = 1;
	}
	if (Bote == 193)
		Note = 1;
	if (Bote == 194)
		Note = 3;
	if (Bote == 195)
		Note = 4;
	if (Bote == 196) {
		Note = 3;
		Bote1 = 1;
	}
	if (Bote == 197)
		Note = 4;
	if (Bote == 198)
		Note = 2;
	if (Bote == 199)
		Note = 1;
	if (Bote == 200)
		Note = 3;
	if (Bote == 201)
		Note = 1;
	if (Bote == 202)
		Note = 4;
	if (Bote == 203)
		Note = 3;
	if (Bote == 204)
		Note = 2;
	if (Bote == 205)
		Note = 3;
	if (Bote == 206)
		Note = 1;
	if (Bote == 207)
		Note = 4;
	if (Bote == 208)
		Note = 2;
	if (Bote == 209)
		Note = 3;
	if (Bote == 210)
		Note = 1;
	if (Bote == 211)
		Note = 2;
	if (Bote == 212)
		Note = 4;
	if (Bote == 213)
		Note = 3;
	if (Bote == 214) {
		Note = 4;
		m_Delay = 4.75f;
	}
	if (Bote == 215)
		Note = 3;
	if (Bote == 216)
		Note = 4;
	if (Bote == 217)
		Note = 1;
	if (Bote == 218)
		Note = 4;
	if (Bote == 219)
		Note = 2;
	if (Bote == 220)
		Note = 2;
	if (Bote == 221)
		Note = 4;
	if (Bote == 222)
		Note = 1;
	if (Bote == 223)
		Note = 3;
	if (Bote == 224)
		Note = 2;
	if (Bote == 225)
		Note = 4;
	if (Bote == 226)
		Note = 1;
	if (Bote == 227)
		Note = 3;
	if (Bote == 228)
		Note = 2;
	if (Bote == 229)
		Note = 4;
	if (Bote == 230)
		Note = 1;
	if (Bote == 231)
		Note = 1;
	if (Bote == 232)
		Note = 4;
	if (Bote == 233)
		Note = 3;
	if (Bote == 234)
		Note = 2;
	if (Bote == 235)
		Note = 4;
	if (Bote == 236)
		Note = 1;
	if (Bote == 237)
		Note = 2;
	if (Bote == 238)
		Note = 1;
	if (Bote == 239)
		Note = 3;
	if (Bote == 240)
		Note = 4;
	if (Bote == 241)
		Note = 2;
	if (Bote == 242)
		Note = 4;
	if (Bote == 243)
		Note = 3;
	if (Bote == 244)
		Note = 1;
	if (Bote == 245)
		Note = 2;
	if (Bote == 246)
		Note = 1;
	if (Bote == 247)
		Note = 3;
	if (Bote == 248)
		Note = 4;
	if (Bote == 249)
		Note = 4;
	if (Bote == 250)
		Note = 1;
	if (Bote == 251)
		Note = 2;
	if (Bote == 252)
		Note = 4;
	if (Bote == 253)
		Note = 3;
	if (Bote == 254)
		Note = 2;
	if (Bote == 255)
		Note = 4;
	if (Bote == 256)
		Note = 1;
	if (Bote == 257)
		Note = 3;
	if (Bote == 258)
		Note = 1;
	if (Bote == 259)
		Note = 2;
	if (Bote == 260)
		Note = 4;
	if (Bote == 261)
		Note = 4;
	if (Bote == 262)
		Note = 3;
	if (Bote == 263)
		Note = 1;
	if (Bote == 264)
		Note = 2;
	if (Bote == 265)
		Note = 4;
	if (Bote == 266)
		Note = 3;
	if (Bote == 267)
		Note = 2;
	if (Bote == 268)
		Note = 1;
	if (Bote == 269)
		Note = 3;
	if (Bote == 270)
		Note = 2;
	if (Bote == 271)
		Note = 4;
	if (Bote == 272)
		Note = 1;
	if (Bote == 273)
		Note = 4;
	if (Bote == 274)
		Note = 2;
	if (Bote == 275)
		Note = 3;
	if (Bote == 276)
		Note = 2;
	if (Bote == 277)
		Note = 1;
	if (Bote == 278)
		Note = 4;
	if (Bote == 279)
		Note = 3;
	if (Bote == 280)
		Note = 2;
	if (Bote == 281)
		Note = 1;
	if (Bote == 282) {
		Note = 4;
		m_Delay = 0.295f;
	}
	if (Bote == 283)
		Note = 2;
	if (Bote == 284)
		Note = 4;
	if (Bote == 285)
		Note = 1;
	if (Bote == 286) {
		Note = 3;
		Bote1 = 1;
	}	
	if (Bote == 287)
		Note = 2;
	if (Bote == 288)
		Note = 1;
	if (Bote == 289)
		Note = 4;
	if (Bote == 290) {
		Note = 2;
		Bote4 = 1;
	}
	if (Bote == 291)
		Note = 3;
	if (Bote == 292)
		Note = 2;
	if (Bote == 293)
		Note = 4;
	if (Bote == 294) {
		Note = 3;
		Bote1 = 1;
	}
	if (Bote == 295)
		Note = 4;
	if (Bote == 296)
		Note = 2;
	if (Bote == 297)
		Note = 3;
	if (Bote == 298) {
		Note = 2;
		Bote4 = 1;
	}
	if (Bote == 299)
		Note = 4;
	if (Bote == 300)
		Note = 3;
	if (Bote == 301 )
		Note = 2;
	if (Bote == 302) {
		Note = 1;
		Bote3 = 1;
	}
	if (Bote == 303)
		Note = 2;
	if (Bote == 304)
		Note = 1;
	if (Bote == 305)
		Note = 4;
	if (Bote == 306) {
		Note = 2;
		Bote4 = 1;
	}
	if (Bote == 307)
		Note = 3;
	if (Bote == 308)
		Note = 1;
	if (Bote == 309)
		Note = 4;
	if (Bote == 310) {
		Note = 1;
		Bote3 = 1;
	}
	if (Bote == 311)
		Note = 2;
	if (Bote == 312)
		Note = 4;
	if (Bote == 313)
		Note = 1;
	if (Bote == 314) {
		Note = 2;
		Bote4 = 1;
	}
	if (Bote == 315)
		Note = 3;
	if (Bote == 316)
		Note = 4;
	if (Bote == 317)
		Note = 2;
	if (Bote == 318) {
		Note = 1;
		Bote3 = 1;
	}
	if (Bote == 319)
		Note = 1;
	if (Bote == 320)
		Note = 3;
	if (Bote == 321)
		Note = 4;
	if (Bote == 322) {
		Note = 2;
		Bote4 = 1;
	}
	if (Bote == 323)
		Note = 2;
	if (Bote == 324)
		Note = 4;
	if (Bote == 325)
		Note = 1;
	if (Bote == 326) {
		Note = 1;
		Bote3 = 1;
	}
	if (Bote == 327)
		Note = 4;
	if (Bote == 328)
		Note = 2;
	if (Bote == 329)
		Note = 3;
	if (Bote == 330) {
		Note = 2;
		Bote4 = 1;
	}
	if (Bote == 331)
		Note = 3;
	if (Bote == 332)
		Note = 1;
	if (Bote == 333)
		Note = 4;
	if (Bote == 334) 
		Note = 2;
	if (Bote == 335)
		Note = 3;
	if (Bote == 336)
		Note = 1;
	if (Bote == 337)
		Note = 4;
	if (Bote == 338)
		Note = 2;
	if (Bote == 339)
		Note = 1;
	if (Bote == 340)
		Note = 3;
	if (Bote == 341)
		Note = 4;
	if (Bote == 342)
		Note = 2;
	if (Bote == 343)
		Note = 1;
	if (Bote == 344)
		Note = 4;
	if (Bote == 345)
		Note = 2;
	if (Bote == 346)
		Note = 3;
	if (Bote == 347)
		Note = 2;
	if (Bote == 348)
		Note = 1;
	if (Bote == 349)
		Note = 3;
	if (Bote == 350) {
		Note = 2;
		Bote4 = 1;
	}
	if (Bote == 351)
		Note = 3;
	if (Bote == 352)
		Note = 4;
	if (Bote == 353)
		Note = 2;
	if (Bote == 354) {
		Note = 1;
		Bote3 = 1;
	}
	if (Bote == 355)
		Note = 2;
	if (Bote == 356)
		Note = 4;
	if (Bote == 357)
		Note = 3;
	if (Bote == 358) {
		Note = 2;
		Bote4 = 1;
	}
	if (Bote == 359)
		Note = 2;
	if (Bote == 360)
		Note = 4;
	if (Bote == 361)
		Note = 1;
	if (Bote == 362) {
		Note = 1;
		Bote3 = 1;
	}
	if (Bote == 363)
		Note = 4;
	if (Bote == 364)
		Note = 3;
	if (Bote == 365)
		Note = 1;
	if (Bote == 366) {
		Note = 2;
		Bote4 = 1;
	}
	if (Bote == 367)
		Note = 3;
	if (Bote == 368)
		Note = 4;
	if (Bote == 369)
		Note = 2;
	if (Bote == 370) {
		Note = 1;
		Bote3 = 1;
	}
	if (Bote == 371)
		Note = 3;
	if (Bote == 372)
		Note = 2;
	if (Bote == 373)
		Note = 4;
	if (Bote == 374) {
		Note = 2;
		Bote4 = 1;
	}
	if (Bote == 375)
		Note = 3;
	if (Bote == 376)
		Note = 2;
	if (Bote == 377)
		Note = 4;
	if (Bote == 378) {
		Note = 1;
	}
	if (Bote == 379)
		Note = 2;
	if (Bote == 380)
		Note = 4;
	if (Bote == 381)
		Note = 3;
	if (Bote == 382) {
		Note = 2;
	}
	if (Bote == 383)
		Note = 3;
	if (Bote == 384)
		Note = 1;
	if (Bote == 385)
		Note = 2;
	if (Bote == 386) {
		Note = 1;
	}
	if (Bote == 387)
		Note = 3;
	if (Bote == 388)
		Note = 4;
	if (Bote == 389)
		Note = 1;
	if (Bote == 390) {
		Note = 2;
	}
	if (Bote == 391)
		Note = 3;
	if (Bote == 392)
		Note = 4;
	if (Bote == 393)
		Note = 2;
	if (Bote == 394) {
		Note = 1;
		m_Delay = 0.1975f;
	}
	if (Bote == 395)
		Note = 4;
	if (Bote == 396)
		Note = 2;
	if (Bote == 397)
		Note = 1;
	if (Bote == 398)
		Note = 3;
	if (Bote == 399)
		Note = 2;
	if (Bote == 400)
		Note = 4;
	if (Bote == 401)
		Note = 1;
	if (Bote == 402)
		Note = 3;
	if (Bote == 403)
		Note = 4;
	if (Bote == 404)
		Note = 2;
	if (Bote == 405)
		Note = 1;
	if (Bote == 406)
		Note = 3;
	if (Bote == 407)
		Note = 2;
	if (Bote == 408)
		Note = 1;
	if (Bote == 409)
		Note = 4;
	if (Bote == 410)
		Note = 3;
	if (Bote == 411)
		Note = 2;
	if (Bote == 412)
		Note = 4;
	if (Bote == 413)
		Note = 1;
	if (Bote == 414)
		Note = 3;
	if (Bote == 415)
		Note = 2;
	if (Bote == 416)
		Note = 4;
	if (Bote == 417)
		Note = 1;
	if (Bote == 418)
		Note = 3;
	if (Bote == 419)
		Note = 4;
	if (Bote == 420) {
		Note = 1;
		m_Delay = 0.295f;
	}
	if (Bote == 421)
		Note = 3;
	if (Bote == 422)
		Note = 1;
	if (Bote == 423)
		Note = 3;
	if (Bote == 424)
		Note = 2;
	if (Bote == 425)
		Note = 4;
	if (Bote == 426)
		Note = 2;
	if (Bote == 427)
		Note = 1;
	if (Bote == 428)
		Note = 4;
		


	if (m_NowTick - m_LastTick > m_Delay&& Bote == 214)
	{
		m_Delay = 0.590f;
	}

	if (m_NowTick - m_LastTick > m_Delay && Bote <= 4)
	{
		if (i == 0)
		{
			m_Delay = 0.295f;
			i = 1;
		}

		m_LastTick = m_NowTick;

		if (Note == 1)
		{
			ObjMgr->AddObject(new Circle(1920 / 2, 1080 / 2 - 400), "Ciecle");
			Note += 1;
			
		}
		else if (Note == 2)
		{
			ObjMgr->AddObject(new Circle1(1920 / 2 - 400, 1080 / 2), "Ciecle1");
			Note += 1;
		}
		else if (Note == 3)
		{
			ObjMgr->AddObject(new Circle2(1920 / 2, 1080 / 2 + 400), "Ciecle");
			Note += 1;
		}
		else if (Note == 4)
		{
			ObjMgr->AddObject(new Circle3(1920 / 2 + 400, 1080 / 2), "Ciecle1");
			Note = 1;
			Bote += 1;
			j++;
		}

	}

	if (m_NowTick - m_LastTick > m_Delay&& Bote <= 1000)
	{
		m_LastTick = m_NowTick;

		Bote++;

		j++;

		if (Note == 1)
		{
			ObjMgr->AddObject(new Circle(1920 / 2, 1080 / 2 - 400), "Ciecle");
		}
		else if (Note == 2)
		{
			ObjMgr->AddObject(new Circle1(1920 / 2 - 400, 1080 / 2), "Ciecle1");
		}
		else if (Note == 3)
		{
			ObjMgr->AddObject(new Circle2(1920 / 2, 1080 / 2 + 400), "Ciecle");
		}
		else if (Note == 4)
		{
			ObjMgr->AddObject(new Circle3(1920 / 2 + 400, 1080 / 2), "Ciecle1");
		}

		if (Bote1 == 1)
		{
			ObjMgr->AddObject(new Circle(1920 / 2, 1080 / 2 - 400), "Ciecle");
			Bote1 = 0;
		}
		if (Bote2 == 1)
		{
			ObjMgr->AddObject(new Circle1(1920 / 2 - 400, 1080 / 2), "Ciecle1");
			Bote2 = 0;
		}
		if (Bote3 == 1)
		{
			ObjMgr->AddObject(new Circle2(1920 / 2, 1080 / 2 + 400), "Ciecle");
			Bote3 = 0;
		}
		if (Bote4 == 1)
		{
			ObjMgr->AddObject(new Circle3(1920 / 2 + 400, 1080 / 2), "Ciecle1");
			Bote4 = 0;
		}
	}
	
	//노트생성 조건

	m_1 = (50 * GameMgr::GetInst()->m_50 + 100 * GameMgr::GetInst()->m_100 + 300 * GameMgr::GetInst()->m_300);
	
	m_2 = 300 * (GameMgr::GetInst()->m_miss + GameMgr::GetInst()->m_50 + GameMgr::GetInst()->m_100 + GameMgr::GetInst()->m_300);

	m_3 = m_1 / m_2 * 200;

	//인터페이스

	m_4 = 0;

	Renderer::GetInst()->GetSprite()->Begin(D3DXSPRITE_ALPHABLEND);

	m_Text->print("\n\n\n\n                      Score : " + std::to_string(GameMgr::GetInst()->m_Score), 0, 0);
	m_Text->print("\n\n\n\n\n\n\n                      Combo : " + std::to_string(GameMgr::GetInst()->m_Combo), 0, 0);
	
	if (GameMgr::GetInst()->count == 0)
	{
		m_Text->print("\n\n\n\n\n\n\n\n\n\n                      Accuracy : " + std::to_string(m_4) + "%", 0, 0);
	}

	if (GameMgr::GetInst()->count >= 1)
	{
		m_Text->print("\n\n\n\n\n\n\n\n\n\n                      Accuracy : " + std::to_string(m_3) + "%", 0, 0);
	}

	m_Text->print("\n\n                                                                                                                Offset : " + std::to_string(GameMgr::GetInst()->m_offset), 0, 0);

	Renderer::GetInst()->GetSprite()->End();

}

