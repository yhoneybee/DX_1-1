#include "DXUT.h"
#include "LoadScene.h"

void LoadScene::Init()
{
	AddAnim("next", "next_", "");
	AddAnim("restart", "restart_", "");
	AddAnim("home", "home_", "");
	AddAnim("clear_title", "Clear_", "");
	AddAnim("fail_title", "FAIL_", "");
	AddAnim("boss_BOOM");
	AddAnim("player_idle");
	AddAnim("Start", "START_", "");
	AddAnim("Logo_anim", "LogoFrame_", "");
	AddAnim("Back", "Backframe_", "");
	AddAnim("ping", "ping_Frame", "");
	AddAnim("transition_effect", "tran_", "");
	AddAnim("Skill_anim", "Frame_", "");
	AddAnim("Boss_explosion", "Boss_Ex", "");

	AddImg("/bullet/bullet_1");
	AddImg("/bullet/bullet_2");
	AddImg("/bullet/bullet_3");
	AddImg("/bullet/bullet_4");
	AddImg("/bullet/Player_bullet");
	AddImg("/number/0");
	AddImg("/number/1");
	AddImg("/number/2");
	AddImg("/number/3");
	AddImg("/number/4");
	AddImg("/number/5");
	AddImg("/number/6");
	AddImg("/number/7");
	AddImg("/number/8");
	AddImg("/number/9");
	AddImg("/number/dot");
	AddImg("arrowkeys");
	AddImg("bar");
	AddImg("Bg");
	AddImg("BG_mountains_night_1024");
	AddImg("BigBlue");
	AddImg("black");
	AddImg("Bolt");
	AddImg("button_cross");
	AddImg("cross");
	AddImg("enemy1");
	AddImg("enemy2");
	AddImg("enemy3");
	AddImg("enemy4");
	AddImg("enemy5");
	AddImg("enemy6");
	AddImg("enemy7");
	AddImg("enemy8");
	AddImg("Exit");
	AddImg("gage");
	AddImg("gray");
	AddImg("HowToPlay");
	AddImg("intro1");
	AddImg("intro2");
	AddImg("intro3");
	AddImg("intro4");
	AddImg("intro5");
	AddImg("minimap");
	AddImg("minimapbg");
	AddImg("Option");
	AddImg("persent");
	AddImg("player");
	AddImg("result_BG");
	AddImg("result_bolt");
	AddImg("result_bolt_slot");
	AddImg("result_home");
	AddImg("result_next");
	AddImg("result_retry");
	AddImg("Round_Text");
	AddImg("round1_after");
	AddImg("round1_before");
	AddImg("round2_after");
	AddImg("round2_before");
	AddImg("round3_after");
	AddImg("round3_before");
	AddImg("Start");
	AddImg("Start_BG");
	AddImg("Start_title");
	AddImg("tik");
	AddImg("Time_Text");
	AddImg("Title");
	AddImg("yes-tic");
	AddImg("play");
	AddImg("Credit");
	AddImg("CreditBG");
	AddImg("score_ui");
	AddImg("ST_1");
	AddImg("ST_2");
	AddImg("ST_3");

	AddImg("lina_me");
	AddImg("me_lina");
	AddImg("me_trickster");
	AddImg("trickster_me");
	AddImg("Skip");
	AddImg("Story_BG");

	IMG->Add("gage_infill");

	load_count = loads.size();
}

void LoadScene::Update()
{
	if (loads.empty())
	{
		SCENE->Set("title");
	}
	else
	{
		LoadInfo temp = loads.front();
		loads.pop_front();

		char str[256];
		sprintf(str, "loads left count : %d\n", int(loads.size()));
		OutputDebugStringA(str);

		if (temp.before == "default" && temp.after == "default")
			IMG->Add(temp.name);
		else
			ANIM->Add(temp.name, temp.before, temp.after);
	}
}

void LoadScene::Render()
{
	char str[256];
	sprintf(str, "%.2f %%", float((load_count - loads.size()) * 100) / load_count);
	IMG->Write("·ÎµùÁß...", V2(CENTER.x + 70, CENTER.y), 100);
	IMG->Write(str, V2(CENTER.x, CENTER.y + 350), 100);

	IMG->Add("gage_infill")->Render({ CENTER.x,CENTER.y + 350 }, { -LONG(415 / 2),-LONG(47 / 2),LONG(415 / 2) - 410 + LONG((float((load_count - loads.size()) * 100) / load_count) / 100 * 408),LONG(47 / 2) }, V2(3, 2));
}

void LoadScene::AddImg(const string& name)
{
	loads.emplace_back(LoadInfo(name));
}

void LoadScene::Release()
{
}

void LoadScene::AddAnim(const string& name, const string& before, const string& after)
{
	loads.emplace_back(LoadInfo(name, before, after));
}
