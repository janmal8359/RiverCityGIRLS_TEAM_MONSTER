#include "pch.h"
#include "sfxStorage.h"

sfxStorage::sfxStorage()
{
}

sfxStorage::~sfxStorage()
{
}

HRESULT sfxStorage::init()
{
	/////////////////���� �ҽ�///////////////
#pragma region SFXSOURCE

//�÷��̾� ����
#pragma region PLAYERSFX

	//�÷��̾� �⺻ ����///////////////////////////////////////////////////////////////////////////////////////////////
	
	//�ȴ¼Ҹ�1
	SOUNDMANAGER->addSound("PLAYER_footStep1", "Resource/SFX/Player/player_footsteps_run_01.wav", false, false);
	//�ȴ¼Ҹ�2
	SOUNDMANAGER->addSound("PLAYER_footStep2", "Resource/SFX/Player/player_footsteps_run_02.wav", false, false);
	//�ȴ¼Ҹ�3
	SOUNDMANAGER->addSound("PLAYER_footStep3", "Resource/SFX/Player/player_footsteps_run_03.wav", false, false);

	//����
	SOUNDMANAGER->addSound("PLAYER_jump", "Resource/SFX/Player/player_jump.wav", false, false);
	//����
	SOUNDMANAGER->addSound("PLAYER_land", "Resource/SFX/Player/player_land.wav", false, false);

	//�����
	SOUNDMANAGER->addSound("PLAYER_grabWall", "Resource/SFX/Player/player_grab_wall.wav", false, false);


	//��������
	SOUNDMANAGER->addSound("PLAYER_knee", "Resource/SFX/Player/DD2_knee.wav", false, false);


	//����
	SOUNDMANAGER->addSound("PLAYER_block", "Resource/SFX/Player/player_block.wav", false, false);
	//�¾����� ����
	SOUNDMANAGER->addSound("PLAYER_getHitBlock", "Resource/SFX/Player/player_gethit_blocked.wav", false, false);
	//�°������¼Ҹ�
	SOUNDMANAGER->addSound("PLAYER_knockDown_01", "Resource/SFX/Player/gethit_knockdown_01.wav", false, false);


	//�׾ �������¼Ҹ�1
	SOUNDMANAGER->addSound("PLAYER_death", "Resource/SFX/Player/player_death_pitfall.wav", false, false);
	
	
	//����//////////////////////////////////////////////////////////////////////////////////////////////////////////////
	
	//��ġ1
	SOUNDMANAGER->addSound("PLAYER_punch1", "Resource/SFX/Player/player_punch_01.wav", false, false);
	//��ġ2
	SOUNDMANAGER->addSound("PLAYER_punch2", "Resource/SFX/Player/player_punch_02.wav", false, false);
	//��ġ3
	SOUNDMANAGER->addSound("PLAYER_punch3", "Resource/SFX/Player/player_punch_03.wav", false, false);

	//������
	SOUNDMANAGER->addSound("PLAYER_throw", "Resource/SFX/Player/player_throw.wav", false, false);

	//����ű
	SOUNDMANAGER->addSound("PLAYER_jumpKick", "Resource/SFX/Player/player_jump_kick.wav", false, false);
	//������ġ
	SOUNDMANAGER->addSound("PLAYER_jumpPunch", "Resource/SFX/Player/player_jump_punch.wav", false, false);
	//ȸ��ű
	SOUNDMANAGER->addSound("PLAYER_rollKick", "Resource/SFX/Player/player_kyoko_roundhouse.wav", false, false);

	//�۷ι����
	SOUNDMANAGER->addSound("PLAYER_global_Catch", "Resource/SFX/Player/player_global_catch.wav", false, false);
	//���
	SOUNDMANAGER->addSound("PLAYER_grab", "Resource/SFX/Player/player_grab.wav", false, false);


	//�Ӹ� �������////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//��ų����
//	SOUNDMANAGER->addSound("PLAYER_powerBomb_StartUp", "Resource/SFX/Player/player_misako_powerbomb_startup.wav.wav", false, false);
	//��ų��������
	SOUNDMANAGER->addSound("PLAYER_powerBomb_falling", "Resource/SFX/Player/player_misako_powerbomb_falling.wav", false, false);
	//��ų����
	SOUNDMANAGER->addSound("PLAYER_powerBomb_landing", "Resource/SFX/Player/player_misako_powerbomb_landing.wav.wav", false, false);

	//��ٸ�////////////////////////////////////////////////////////////////////////////////////////////////////////////
	
	//�����¼Ҹ�1
	SOUNDMANAGER->addSound("PLAYER_climb1", "Resource/SFX/Player/player_climb_01.wav", false, false);
	//�����¼Ҹ�2
	SOUNDMANAGER->addSound("PLAYER_climb2", "Resource/SFX/Player/player_climb_02.wav", false, false);

	//��ٸ������ͼ� �����������
	SOUNDMANAGER->addSound("PLAYER_climb_Down_Ledge", "Resource/SFX/Player/player_climb_down_ledge.wav", false, false);
	//��ٸ������ͼ� �ö󰬾�����
	SOUNDMANAGER->addSound("PLAYER_climb_Up_Ledge", "Resource/SFX/Player/player_climb_up_ledge.wav", false, false);

	//����/////////////////////////////////////////////////////////////////////////////////////////////////////////////

	//���ſ��������
	SOUNDMANAGER->addSound("PLAYER_pickUpHeavy", "Resource/SFX/Player/player_global_pickup_weapon_heavy.wav", false, false);
	//�������������
	SOUNDMANAGER->addSound("PLAYER_pickUpLight", "Resource/SFX/Player/player_global_pickup_weapon_light.wav", false, false);
	//���ſ�����������
	SOUNDMANAGER->addSound("PLAYER_throwHeavy", "Resource/SFX/Player/player_global_throw_weapon_heavy.wav", false, false);
	//��������������
	SOUNDMANAGER->addSound("PLAYER_throwLight", "Resource/SFX/Player/player_global_throw_weapon_light.wav", false, false);

	//���� �̻�////////////////////////////////////////////////////////////////////////////////////////////////////////
	//����
	SOUNDMANAGER->addSound("PLAYER_dizzy", "Resource/SFX/Player/player_global_dizzy.wav", false, false);
	//����
	SOUNDMANAGER->addSound("PLAYER_parry", "Resource/SFX/Player/player_global_parry.wav", false, false);
	//��Ҹ�///////////////////////////////////////////////////////////////////////////////////////////////////////////
	SOUNDMANAGER->addSound("PLAYER_combo1", "Resource/SFX/Player/Kyoko/vo_kyoko_effort_16.wav", false, false);
	SOUNDMANAGER->addSound("PLAYER_combo2", "Resource/SFX/Player/Kyoko/vo_kyoko_effort_18.wav", false, false);
	SOUNDMANAGER->addSound("PLAYER_combo3", "Resource/SFX/Player/Kyoko/vo_kyoko_effort_22.wav", false, false);
#pragma endregion PLAYERSFX

	


#pragma region MENUSFX
//	SOUNDMANAGER->addSound("MENU_busUse", "Resource/SFX/menu/interface_bus_use.wav", true, false);
//	SOUNDMANAGER->addSound("MENU_gameover", "Resource/SFX/menu/interface_game_over.wav", true, false);
//	SOUNDMANAGER->addSound("MENU_mapMarker", "Resource/SFX/menu/interface_map_marker.wav", true, false);
//	SOUNDMANAGER->addSound("MENU_wediditJingle", "Resource/SFX/menu/interface_wedidit_jingle.wav", true, false);
//	SOUNDMANAGER->addSound("MENU_jingleMap1", "Resource/SFX/menu/jingle_map_01.wav", true, false);
//	SOUNDMANAGER->addSound("MENU_jingleTutorial3", "Resource/SFX/menu/jingle_tutorial_03.wav", true, false);
//	SOUNDMANAGER->addSound("MENU_levelUp", "Resource/SFX/menu/level_up_sequence.wav", true, false);
//	SOUNDMANAGER->addSound("MENU_accessoryEquip", "Resource/SFX/menu/menu_accesory_equip.wav", true, false);
//	SOUNDMANAGER->addSound("MENU_accessoryUnequip", "Resource/SFX/menu/menu_accesory_unequip.wav", true, false);
//	SOUNDMANAGER->addSound("MENU_back", "Resource/SFX/menu/menu_back.wav", true, false);
//	SOUNDMANAGER->addSound("MENU_cannot", "Resource/SFX/menu/menu_cannot.wav", true, false);
//	SOUNDMANAGER->addSound("MENU_confirm", "Resource/SFX/menu/menu_confirm.wav", true, false);
//	SOUNDMANAGER->addSound("MENU_cursor", "Resource/SFX/menu/menu_cursor.wav", true, false);
//	SOUNDMANAGER->addSound("MENU_emptyAccessory", "Resource/SFX/menu/menu_empty_accessory.wav", true, false);
//	SOUNDMANAGER->addSound("MENU_interact", "Resource/SFX/menu/menu_interact.wav", true, false);
//	SOUNDMANAGER->addSound("MENU_phoneBack", "Resource/SFX/menu/menu_phone_back2.wav", true, false);
//	SOUNDMANAGER->addSound("MENU_phoneCursor1", "Resource/SFX/menu/menu_phone_cursor_01.wav", true, false);
//	SOUNDMANAGER->addSound("MENU_phoneCursor2", "Resource/SFX/menu/menu_phone_cursor_02.wav", true, false);
//	SOUNDMANAGER->addSound("MENU_phoneCursor3", "Resource/SFX/menu/menu_phone_cursor_03.wav", true, false);
//	SOUNDMANAGER->addSound("MENU_phonePause", "Resource/SFX/menu/menu_phone_pause.wav", true, false);
//	SOUNDMANAGER->addSound("MENU_phoneRotate", "Resource/SFX/menu/menu_phone_rotate.wav", true, false);
//	SOUNDMANAGER->addSound("MENU_phoneSelect", "Resource/SFX/menu/menu_phone_select3.wav", true, false);
//	SOUNDMANAGER->addSound("MENU_phoneSliderTick", "Resource/SFX/menu/menu_phone_slider_tick.wav", true, false);
//	SOUNDMANAGER->addSound("MENU_phoneUnpause", "Resource/SFX/menu/menu_phone_unpause.wav", true, false);
//	SOUNDMANAGER->addSound("MENU_playerSelectFirst", "Resource/SFX/menu/menu_player_select_first.wav", true, false);
//	SOUNDMANAGER->addSound("MENU_playerSelectLast", "Resource/SFX/menu/menu_player_select_last.wav", true, false);
//	SOUNDMANAGER->addSound("MENU_notification", "Resource/SFX/menu/notification.wav", true, false);
//	SOUNDMANAGER->addSound("MENU_uiChainsAppear", "Resource/SFX/menu/UI_chains_appear.wav", true, false);
//	SOUNDMANAGER->addSound("MENU_uiChainsBreak", "Resource/SFX/menu/UI_chains_break.wav", true, false);
#pragma endregion MENUSFX

#pragma region GLOBAL & PICKUP

	//���� Ŭ����
	SOUNDMANAGER->addSound("GLOBAL_bossFinal", "Resource/SFX/global/boss_finalhit.wav", true, true);
	//���� ����
	SOUNDMANAGER->addSound("GLOBAL_bossIntro", "Resource/SFX/global/boss_intro_placard", true, true);


	//���� �Ұ�
	SOUNDMANAGER->addSound("PICKUP_cannot", "Resource/SFX/pickup/cannot_pickup.wav", true, true);
	//���� ���� ������ �߰�
	SOUNDMANAGER->addSound("PICKUP_confirm", "Resource/SFX/pickup/interface_item_pickup_confirm.wav", true, true);
	//���� ���� ������ ȹ��
	SOUNDMANAGER->addSound("PICKUP_intro", "Resource/SFX/pickup/interface_item_pickup_intro.wav", true, true);
	//������ ��Ʈ�� ��
	SOUNDMANAGER->addSound("PICKUP_outro", "Resource/SFX/pickup/interface_item_pickup_outro.wav", true, true);
	//û���� ����
	SOUNDMANAGER->addSound("PICKUP_bill", "Resource/SFX/pickup/pickup_bill.wav", true, true);
	//�ٸ���ġ ��1
	SOUNDMANAGER->addSound("PICKUP_cat1", "Resource/SFX/pickup/pickup_cat_01.wav", true, true);
	//�ٸ���ġ ��2
	SOUNDMANAGER->addSound("PICKUP_cat2", "Resource/SFX/pickup/pickup_cat_02.wav", true, true);
	//�ٸ���ġ ��3
	SOUNDMANAGER->addSound("PICKUP_cat3", "Resource/SFX/pickup/pickup_cat_03.wav", true, true);
	//�Ӵ� ����
	SOUNDMANAGER->addSound("PICKUP_coin", "Resource/SFX/pickup/pickup_coin.wav", true, true);
	//���� ����
	SOUNDMANAGER->addSound("PICKUP_food", "Resource/SFX/pickup/pickup_food.wav", true, true);
	//�� ����
	SOUNDMANAGER->addSound("PICKUP_med", "Resource/SFX/pickup/pickup_med_01.wav", true, true);

#pragma endregion GLOBAL & PICKUP

#pragma region ENVIRONMENT

	//��ġ �μ�
	SOUNDMANAGER->addSound("ENVIRONMENT_benchBreak", "Resource/SFX/environment/environment_bench_break.wav", true, false);

	//ȭ�н� å�� �μ�
	SOUNDMANAGER->addSound("ENVIRONMENT_chemistryTableBreak", "Resource/SFX/environment/environment_chemistry_table_break.wav", true, false);

	//���� �μ�
	SOUNDMANAGER->addSound("ENVIRONMENT_woodSmash", "Resource/SFX/environment/environment_wood_smash.wav", true, false);
	SOUNDMANAGER->addSound("ENVIRONMENT_woodCrunch", "Resource/SFX/environment/environment_wood_crunch.wav", true, false);

	//�� �μ�
	SOUNDMANAGER->addSound("ENVIRONMENT_rockSmash", "Resource/SFX/environment/environment_rock_smash.wav", true, false);
	SOUNDMANAGER->addSound("ENVIRONMENT_rockCrunch", "Resource/SFX/environment/environment_rock_crunch.wav", true, false);

	//���Ǳ� �μ�
	SOUNDMANAGER->addSound("ENVIRONMENT_vendingmachinePunched", "Resource/SFX/environment/environment_vending_machine_punched.wav", true, false);
	SOUNDMANAGER->addSound("ENVIRONMENT_vendingmachineBreak", "Resource/SFX/environment/environment_vending_machine_break.wav", true, false);

	//�������� ����
	SOUNDMANAGER->addSound("ENVIRONMENT_dumpsterClose", "Resource/SFX/environment/environment_dumpster_close.wav", true, false);

	//�������� ����
	SOUNDMANAGER->addSound("ENVIRONMENT_dumpsterOpen", "Resource/SFX/environment/environment_dumpster_open.wav", true, false);

	//���� �ٴ�
	SOUNDMANAGER->addSound("ENVIRONMENT_electricfloorOn", "Resource/SFX/environment/environment_electricfloor_on.wav", true, false);

	//���߹� ī��Ʈ �ٿ�
	SOUNDMANAGER->addSound("ENVIRONMENT_explosivesCountdownBeep", "Resource/SFX/environment/environment_explosives_countdown_beep.wav", true, false);

	//���߹� ī��Ʈ �ٿ� ����..? - �Ⱦ��Ű���
	SOUNDMANAGER->addSound("ENVIRONMENT_explosivesCountdownBeepLoop", "Resource/SFX/environment/environment_explosives_idle_beep_loop.wav", true, true);

	//���߹� ����
	SOUNDMANAGER->addSound("ENVIRONMENT_explosivesExplode", "Resource/SFX/environment/environment_explosives_explode.wav", true, false);
	SOUNDMANAGER->addSound("ENVIRONMENT_explosivesExplodePlant", "Resource/SFX/environment/environment_explosives_plant.wav", true, false);

	//���߹� ���� �� �̸�
	SOUNDMANAGER->addSound("ENVIRONMENT_explosivesRinging", "Resource/SFX/environment/environment_explosives_ringing.wav", true, false);

	//�峭�� ����
	SOUNDMANAGER->addSound("ENVIRONMENT_toysSqueek", "Resource/SFX/environment/environment_pattinson_toys_squeek.wav", true, false);

	//ī�޶� �������� ����
	SOUNDMANAGER->addSound("ENVIRONMENT_projectorLoop", "Resource/SFX/environment/environment_projector_loop.wav", true, false);

#pragma endregion ENVIRONMENT




















	//���� Ÿ����

	SOUNDMANAGER->addSound("WEAPONS_bassball1_bat", "Resource/SFX/weapons/weapon_baseball_bat_hit.wav", true, false);			//�߱������  ��
	SOUNDMANAGER->addSound("WEAPONS_bassball2_bat", "Resource/SFX/weapons/weapon_baseball_impact.wav", true, false);			//�߱������2 Ź 

	SOUNDMANAGER->addSound("WEAPONS_bench1", "Resource/SFX/weapons/weapon_bench_break.wav", true, false);				//��ġ �μ����¼Ҹ�
	SOUNDMANAGER->addSound("WEAPONS_bench2", "Resource/SFX/weapons/weapon_bench_impact.wav", true, false);				//��ġ ����Ʈ

	SOUNDMANAGER->addSound("WEAPONS_bicycle", "Resource/SFX/weapons/weapon_bicycle_impact.wav", true, false);				//������
	SOUNDMANAGER->addSound("WEAPONS_boomerang", "Resource/SFX/weapons/weapon_boomerang_throw.wav", true, false);			//�θ޶�
	SOUNDMANAGER->addSound("WEAPONS_chain", "Resource/SFX/weapons/weapon_chain_swing.wav", true, false);				//ü��
	SOUNDMANAGER->addSound("WEAPONS_dodgeball", "Resource/SFX/weapons/weapon_dodgeball_impact.wav", true, false);			//�Ǳ���
	SOUNDMANAGER->addSound("WEAPONS_fish1", "Resource/SFX/weapons/weapon_fish_explode.wav", true, false);				//�����1
	SOUNDMANAGER->addSound("WEAPONS_fish2", "Resource/SFX/weapons/weapon_fish_impact.wav", true, false);				//�����2
	SOUNDMANAGER->addSound("WEAPONS_frying_pan", "Resource/SFX/weapons/weapon_frying_pan_impact2.wav", true, false);			//��������

	SOUNDMANAGER->addSound("WEAPONS_guitar1", "Resource/SFX/weapons/weapon_guitar_impact_01.wav", true, false);			//��Ÿ1
	SOUNDMANAGER->addSound("WEAPONS_guitar2", "Resource/SFX/weapons/weapon_guitar_impact_02.wav", true, false);			//��Ÿ2
	SOUNDMANAGER->addSound("WEAPONS_guitar3", "Resource/SFX/weapons/weapon_guitar_impact_03.wav", true, false);			//��Ÿ3
	SOUNDMANAGER->addSound("WEAPONS_guitar4", "Resource/SFX/weapons/weapon_guitar_impact_04.wav", true, false);			//��Ÿ4

	SOUNDMANAGER->addSound("WEAPONS_lightSaber1", "Resource/SFX/weapons/weapon_light_saber_impact_01.wav", true, false);		//����Ʈ���̹�1
	SOUNDMANAGER->addSound("WEAPONS_lightSaber2", "Resource/SFX/weapons/weapon_light_saber_impact_02.wav", true, false);		//����Ʈ���̹�2
	SOUNDMANAGER->addSound("WEAPONS_lightSaber3", "Resource/SFX/weapons/weapon_light_saber_impact_03.wav", true, false);		//����Ʈ���̹�3

	SOUNDMANAGER->addSound("WEAPONS_lightSaverSwing1", "Resource/SFX/weapons/weapon_light_saber_swing_01.wav", true, false);		//����Ʈ���̹�����1
	SOUNDMANAGER->addSound("WEAPONS_lightSaverSwing2", "Resource/SFX/weapons/weapon_light_saber_swing_02.wav", true, false);		//����Ʈ���̹�����2
	SOUNDMANAGER->addSound("WEAPONS_lightSaverSwing3", "Resource/SFX/weapons/weapon_light_saber_swing_03.wav", true, false);		//����Ʈ���̹�����3
	SOUNDMANAGER->addSound("WEAPONS_lightSaverSwing4", "Resource/SFX/weapons/weapon_light_saber_swing_04.wav", true, false);		//����Ʈ���̹�����4

	SOUNDMANAGER->addSound("WEAPONS_chair", "Resource/SFX/weapons/weapon_metal_chair_impact.wav", true, false);			//�ݼ�����
	SOUNDMANAGER->addSound("WEAPONS_shovel", "Resource/SFX/weapons/weapon_shovel_impact.wav", true, false);				//��
	SOUNDMANAGER->addSound("WEAPONS_starBaton", "Resource/SFX/weapons/weapon_star_baton_impact.wav", true, false);			//��������
	SOUNDMANAGER->addSound("WEAPONS_woodPlank", "Resource/SFX/weapons/weapon_wood_plank_impact.wav", true, false);			//��������
	SOUNDMANAGER->addSound("WEAPONS_wrench", "Resource/SFX/weapons/weapon_wrench_impact.wav", true, false);				//��ġ
#pragma endregion SFXSOURCE









	return S_OK;
}

void sfxStorage::release()
{
}

void sfxStorage::update()
{
}

void sfxStorage::render()
{
}
