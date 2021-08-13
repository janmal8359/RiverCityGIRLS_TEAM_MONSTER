#include "pch.h"
#include "imageStorage.h"

imageStorage::imageStorage()
{
}

imageStorage::~imageStorage()
{
}


HRESULT imageStorage::init()
{


	//�̹��� ����
#pragma region IMAGESOURCES

	IMAGEMANAGER->addImage("SHADOW", "Resource/IMG/character/shadow.bmp", 128, 38, true, RGB(255, 0, 255));


	//////////////////////////////////////////////////////////////////////======�÷��̾�======/////////////////////////////////////////////////////////////////////////////////
#pragma region PLAYERIMAGE

	//�÷��̾��� �⺻���� ����/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 

	//IDLE
	IMAGEMANAGER->addFrameImage("PLAYER_idle", "Resource/IMG/character/player/idle.bmp", 1440, 450, 12, 2, true, RGB(255, 0, 255));
	//�ȴ»���

	IMAGEMANAGER->addFrameImage("PLAYER_walk", "Resource/IMG/character/player/walk.bmp", 1476, 402, 12, 2, true, RGB(255, 0, 255));

	//RUN
	IMAGEMANAGER->addFrameImage("PLAYER_run", "Resource/IMG/character/player/run.bmp", 2736, 384, 16, 2, true, RGB(255, 0, 255));

	//JUMP
	IMAGEMANAGER->addFrameImage("PLAYER_jump", "Resource/IMG/character/player/jump.bmp", 480, 640, 3, 2, true, RGB(255, 0, 255));

	//ROLL
	IMAGEMANAGER->addFrameImage("PLAYER_roll", "Resource/IMG/character/player/roll.bmp", 900, 402, 9, 2, true, RGB(255, 0, 255));

	//������
	IMAGEMANAGER->addFrameImage("PLAYER_wait", "Resource/IMG/character/player/wait.bmp", 2520, 440, 18, 2, true, RGB(255, 0, 255));

	//����...?
	IMAGEMANAGER->addFrameImage("PLAYER_wallet", "Resource/IMG/character/player/wallet.bmp", 2964, 420, 26, 2, true, RGB(255, 0, 255));

	//���鿡 �پ��ִ�
	IMAGEMANAGER->addFrameImage("PLAYER_stick", "Resource/IMG/character/player/stick.bmp", 294, 330, 2, 2, true, RGB(255, 0, 255));


	// ��ٸ� �̹���/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 

	//��ٸ� ������
	IMAGEMANAGER->addFrameImage("PLAYER_climb", "Resource/IMG/character/player/climb.bmp", 720, 237, 6, 1, true, RGB(255, 0, 255));

	//��ٸ� Ÿ�� �� �ö����� �̹���
	IMAGEMANAGER->addFrameImage("PLAYER_climbTop", "Resource/IMG/character/player/climbTop.bmp", 288, 192, 3, 1, true, RGB(255, 0, 255));

	//��ٸ� Ÿ�� �����÷��� �Ҷ� �̹���
	IMAGEMANAGER->addFrameImage("PLAYER_climbTopDown", "Resource/IMG/character/player/climbDown.bmp", 288, 234, 3, 1, true, RGB(255, 0, 255));


	//����/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
	
	//�޺����� 1�϶� // �ָ�
	IMAGEMANAGER->addFrameImage("PLAYER_comboAttack1", "Resource/IMG/character/player/comboAttack1.bmp", 1548, 390, 6, 2, true, RGB(255, 0, 255));

	//�޺����� 2�϶� // ������
	IMAGEMANAGER->addFrameImage("PLAYER_comboAttack2", "Resource/IMG/character/player/comboAttack2.bmp", 1869, 402, 7, 2, true, RGB(255, 0, 255));

	//�޺����� 3�϶� /�ٸ� �������
	IMAGEMANAGER->addFrameImage("PLAYER_comboAttack3", "Resource/IMG/character/player/comboAttack3.bmp", 2970, 462, 9, 2, true, RGB(255, 0, 255));

	//�ٴ��� �� ����
	IMAGEMANAGER->addFrameImage("PLAYER_stomp", "Resource/IMG/character/player/stomp.bmp", 1290, 420, 10, 2, true, RGB(255, 0, 255));

	//������� ����
	IMAGEMANAGER->addFrameImage("PLAYER_sAttack", "Resource/IMG/character/player/sAttack.bmp", 3030, 560, 10, 2, true, RGB(255, 0, 255));

	//ȸ��ȸ���� ����
	IMAGEMANAGER->addFrameImage("PLAYER_sAttackDown", "Resource/IMG/character/player/sAttackDown.bmp", 7992, 438, 24, 2, true, RGB(255, 0, 255));

	//���
	IMAGEMANAGER->addFrameImage("PLAYER_grab", "Resource/IMG/character/player/grab.bmp", 270, 384, 2, 2, true, RGB(255, 0, 255));

	//������
	IMAGEMANAGER->addFrameImage("PLAYER_grabFail", "Resource/IMG/character/player/grabFail.bmp", 812, 422, 4, 2, true, RGB(255, 0, 255));

	//�޸��� ����/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
	
	//�뽬 ����  //�ָ�
	IMAGEMANAGER->addFrameImage("PLAYER_dashAttack", "Resource/IMG/character/player/dashAttack.bmp", 2565, 414, 8, 2, true, RGB(255, 0, 255));

	//�뽬 ���Ƽ� ����
	IMAGEMANAGER->addFrameImage("PLAYER_dashSAttack", "Resource/IMG/character/player/dashSAttack.bmp", 5460, 456, 21, 2, true, RGB(255, 0, 255));

	//�����϶� ����/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
	
	//JUMPAttack
	IMAGEMANAGER->addFrameImage("PLAYER_jumpAttack", "Resource/IMG/character/player/jump_Attack.bmp", 1560, 432, 10, 2, true, RGB(255, 0, 255));


	//�÷��̾� �ǰ�/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 

	//����
	IMAGEMANAGER->addFrameImage("PLAYER_guard", "Resource/IMG/character/player/guard.bmp", 351, 378, 3, 2, true, RGB(255, 0, 255));

	//Ÿ��
	IMAGEMANAGER->addFrameImage("PLAYER_hit", "Resource/IMG/character/player/hit.bmp", 246, 420, 2, 2, true, RGB(255, 0, 255));

	//����Ÿ�� ��� ���ϰ� �ٿ�
	IMAGEMANAGER->addFrameImage("PLAYER_down", "Resource/IMG/character/player/down.bmp", 4968, 390, 23, 2, true, RGB(255, 0, 255));

	//���ϻ���
	IMAGEMANAGER->addFrameImage("PLAYER_stun", "Resource/IMG/character/player/stun.bmp", 384, 384, 4, 2, true, RGB(255, 0, 255));

	//�ٿ���¿��� �ٽ� idle��
	IMAGEMANAGER->addFrameImage("PLAYER_stand", "Resource/IMG/character/player/stand.bmp", 1863, 450, 9, 2, true, RGB(255, 0, 255));

	//���/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 

	//�տ��� �¾����� ������� �Ѿ����鼭 ���
	IMAGEMANAGER->addFrameImage("PLAYER_dead", "Resource/IMG/character/player/dead.bmp", 7280, 478, 26, 2, true, RGB(255, 0, 255));

	//�ڿ��� �¾����� ������� �Ѿ����鼭 ��� ���ӳ�����
	IMAGEMANAGER->addFrameImage("PLAYER_gameOver", "Resource/IMG/character/player/gameOver.bmp", 6240, 282, 26, 2, true, RGB(255, 0, 255));
	

	//Ư������ /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
	
	//PICK
	IMAGEMANAGER->addFrameImage("PLAYER_pick", "Resource/IMG/character/player/pick.bmp", 222, 450, 2, 2, true, RGB(255, 0, 255));

	//�߱������ IDLE
	IMAGEMANAGER->addFrameImage("PLAYER_batIdle", "Resource/IMG/character/player/wBatIdle.bmp", 1440, 560, 12, 2, true, RGB(255, 0, 255));

	//�߱������ WALK
	IMAGEMANAGER->addFrameImage("PLAYER_batWalk", "Resource/IMG/character/player/wBatWalk.bmp", 1476, 500, 8, 2, true, RGB(255, 0, 255));

	//�߱������ RUN
	IMAGEMANAGER->addFrameImage("PLAYER_batRun", "Resource/IMG/character/player/wBatRun.bmp", 6784, 560, 16, 2, true, RGB(255, 0, 255));

	//�߱������ JUMP
	IMAGEMANAGER->addFrameImage("PLAYER_batJump", "Resource/IMG/character/player/wBatJump.bmp", 480, 640, 3, 2, true, RGB(255, 0, 255));

	//�߱������ THROW
	IMAGEMANAGER->addFrameImage("PLAYER_batThrow", "Resource/IMG/character/player/wBatThrow.bmp", 1616, 600, 8, 2, true, RGB(255, 0, 255));
	
	//�߱�����̷� ����
	IMAGEMANAGER->addFrameImage("PLAYER_batAttack", "Resource/IMG/character/player/wBatAttack.bmp", 1700, 700, 5, 2, true, RGB(255, 0, 255));

#pragma endregion PLAYERIMAGE

	//////////////////////////////////////////////////////////////////////////======NPC======/////////////////////////////////////////////////////////////////////////////////
#pragma region NPCIMAGE
	//����1
	IMAGEMANAGER->addFrameImage("BOY1", "Resource/IMG/character/npc/boy1.bmp", 396, 480, 4, 2, true, RGB(255, 0, 255));
	//����1 ����
	IMAGEMANAGER->addFrameImage("BOY1", "Resource/IMG/character/npc/boy1_react.bmp", 306, 480, 3, 2, true, RGB(255, 0, 255));

	//����1
	IMAGEMANAGER->addFrameImage("GIRL1", "Resource/IMG/character/npc/girl.bmp", 312, 396, 4, 2, true, RGB(255, 0, 255));
	//����1 ����
	IMAGEMANAGER->addFrameImage("GIRL1", "Resource/IMG/character/npc/girl1_react.bmp", 297, 384, 3, 2, true, RGB(255, 0, 255));

	//����2
	IMAGEMANAGER->addFrameImage("GIRL2", "Resource/IMG/character/npc/girl2.bmp", 324, 522, 4, 2, true, RGB(255, 0, 255));
	//����2 ����
	IMAGEMANAGER->addFrameImage("GIRL2", "Resource/IMG/character/npc/girl2_react.bmp", 360, 504, 3, 2, true, RGB(255, 0, 255));

#pragma endregion NPCIMAGE

	//////////////////////////////////////////////////////////////////////////======ENEMY======///////////////////////////////////////////////////////////////////////////////
#pragma region ENEMYIMAGE
	
	// ���� =============================================================================================================================
#pragma region BOSS
	// ���� ����=============================================================================================================================
	IMAGEMANAGER->addFrameImage("BOSS_attacked0", "Resource/IMG/character/enemy/boss/attacked.bmp", 2214, 594, 9, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("BOSS_attacked1", "Resource/IMG/character/enemy/boss/attacked 01.bmp", 737, 594, 3, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("BOSS_attacked2", "Resource/IMG/character/enemy/boss/attacked 02.bmp", 737, 594, 3, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("BOSS_attacked3", "Resource/IMG/character/enemy/boss/attacked 03.bmp", 737, 594, 3, 2, true, RGB(255, 0, 255));

	// ���� �뽬(���� ��ġ��?)
	IMAGEMANAGER->addFrameImage("BOSS_dash", "Resource/IMG/character/enemy/boss/dash.bmp", 2619, 582, 10, 2, true, RGB(255, 0, 255));

	// ���� ����
	IMAGEMANAGER->addFrameImage("BOSS_block", "Resource/IMG/character/enemy/boss/block.bmp", 1688, 576, 8, 2, true, RGB(255, 0, 255));


	// ���� ����
	IMAGEMANAGER->addFrameImage("BOSS_death", "Resource/IMG/character/enemy/boss/death.bmp", 4576, 576, 13, 2, true, RGB(255, 0, 255));
	// ���� �й�
	IMAGEMANAGER->addFrameImage("BOSS_defeat", "Resource/IMG/character/enemy/boss/defeat.bmp", 4576, 576, 13, 2, true, RGB(255, 0, 255));
	// ���� ��������
	IMAGEMANAGER->addFrameImage("BOSS_dizzy", "Resource/IMG/character/enemy/boss/dizzy.bmp", 1024, 434, 4, 2, true, RGB(255, 0, 255));
	// ���� �ٿ�
	IMAGEMANAGER->addFrameImage("BOSS_down", "Resource/IMG/character/enemy/boss/down.bmp", 5830, 510, 22, 2, true, RGB(255, 0, 255));
	// ���� ������
	IMAGEMANAGER->addFrameImage("BOSS_elbow1", "Resource/IMG/character/enemy/boss/elbow.bmp", 2915, 652, 11, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("BOSS_elbow2", "Resource/IMG/character/enemy/boss/elbow2.bmp", 2885, 652, 11, 2, true, RGB(255, 0, 255));
	// ���� �Ϲ� ��Ʈ
	IMAGEMANAGER->addFrameImage("BOSS_getHit", "Resource/IMG/character/enemy/boss/gethit.bmp", 2214, 594, 9, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("BOSS_getHit_A", "Resource/IMG/character/enemy/boss/gethit_A.bmp", 5830, 510, 22, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("BOSS_getHit_K", "Resource/IMG/character/enemy/boss/gethit_K.bmp", 2880, 594, 10, 2, true, RGB(255, 0, 255));
	// ���� �Ͼ(���)
	IMAGEMANAGER->addFrameImage("BOSS_getUp_C", "Resource/IMG/character/enemy/boss/getup_C.bmp", 2187, 576, 9, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("BOSS_getUp_S", "Resource/IMG/character/enemy/boss/getup_S.bmp", 2560, 466, 10, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("BOSS_getUp_SS", "Resource/IMG/character/enemy/boss/getup_SS.bmp", 3735, 580, 15, 2, true, RGB(255, 0, 255));
	// ���� �׷α�
	IMAGEMANAGER->addFrameImage("BOSS_groggy", "Resource/IMG/character/enemy/boss/groggy.bmp", 1024, 434, 4, 2, true, RGB(255, 0, 255));
	// ���� �Ѿ��� ���� �� ��Ʈ
	IMAGEMANAGER->addFrameImage("BOSS_groundHit", "Resource/IMG/character/enemy/boss/groundhit.bmp", 1036, 460, 4, 2, true, RGB(255, 0, 255));
	// ���� �Ҹ�������
	IMAGEMANAGER->addFrameImage("BOSS_howling", "Resource/IMG/character/enemy/boss/howling.bmp", 2916, 576, 12, 2, true, RGB(255, 0, 255));
	// ���� ������
	IMAGEMANAGER->addFrameImage("BOSS_idle", "Resource/IMG/character/enemy/boss/idle.bmp", 3180, 634, 12, 2, true, RGB(255, 0, 255));
	// ���� ������� ���
	IMAGEMANAGER->addFrameImage("BOSS_meteor", "Resource/IMG/character/enemy/boss/meteor.bmp", 480, 460, 2, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("BOSS_meteor_A", "Resource/IMG/character/enemy/boss/meteor_A.bmp", 410, 660, 2, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("BOSS_meteor_C", "Resource/IMG/character/enemy/boss/meteor_C.bmp", 2988, 576, 12, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("BOSS_meteor_G", "Resource/IMG/character/enemy/boss/meteor_G.bmp", 1224, 422, 6, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("BOSS_meteor_J", "Resource/IMG/character/enemy/boss/meteor_J.bmp", 1888, 672, 8, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("BOSS_meteor_M", "Resource/IMG/character/enemy/boss/meteor_M.bmp", 4674, 576, 19, 2, true, RGB(255, 0, 255));
	// ���� �̵�
	IMAGEMANAGER->addFrameImage("BOSS_move", "Resource/IMG/character/enemy/boss/move.bmp", 2110, 588, 10, 2, true, RGB(255, 0, 255));
	// ���� ������ ����?
	IMAGEMANAGER->addFrameImage("BOSS_phase", "Resource/IMG/character/enemy/boss/phase.bmp", 5658, 748, 23, 2, true, RGB(255, 0, 255));
	// ���� ��ȿ
	IMAGEMANAGER->addFrameImage("BOSS_roar", "Resource/IMG/character/enemy/boss/roar.bmp", 2916, 576, 12, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("BOSS_roar_U", "Resource/IMG/character/enemy/boss/roar_U.bmp", 1000, 474, 4, 2, true, RGB(255, 0, 255));
	// ���� ���ĸ���
	IMAGEMANAGER->addFrameImage("BOSS_slab", "Resource/IMG/character/enemy/boss/slab.bmp", 5278, 582, 14, 2, true, RGB(255, 0, 255));
	// ���� ���ĸ���
	IMAGEMANAGER->addFrameImage("BOSS_slap", "Resource/IMG/character/enemy/boss/slap.bmp", 5278, 582, 14, 2, true, RGB(255, 0, 255));
	// ���� �ָ���
	IMAGEMANAGER->addFrameImage("BOSS_smash", "Resource/IMG/character/enemy/boss/smash.bmp", 11880, 594, 27, 2, true, RGB(255, 0, 255));
	// ���� �ɾƼ� ������
	IMAGEMANAGER->addFrameImage("BOSS_standAttack", "Resource/IMG/character/enemy/boss/standattack.bmp", 2187, 576, 9, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("BOSS_standAttack1", "Resource/IMG/character/enemy/boss/standattack1.bmp", 2560, 466, 10, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("BOSS_standAttack2", "Resource/IMG/character/enemy/boss/standattack2.bmp", 3735, 580, 15, 2, true, RGB(255, 0, 255));
	// ���� �����Ŭ(�����ġ��)
	IMAGEMANAGER->addFrameImage("BOSS_tackle", "Resource/IMG/character/enemy/boss/tackle.bmp", 1120, 576, 5, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("BOSS_tackle_L", "Resource/IMG/character/enemy/boss/tackle_L.bmp", 2882, 576, 11, 2, true, RGB(255, 0, 255));
	// ���� ����?
	IMAGEMANAGER->addFrameImage("BOSS_taunt", "Resource/IMG/character/enemy/boss/taunt.bmp", 5658, 748, 23, 2, true, RGB(255, 0, 255));
	// ���� �ȱ�
	IMAGEMANAGER->addFrameImage("BOSS_walk", "Resource/IMG/character/enemy/boss/walk.bmp", 2110, 588, 10, 2, true, RGB(255, 0, 255));
	// ���� ��ġ
	IMAGEMANAGER->addFrameImage("BOSS_wupunch", "Resource/IMG/character/enemy/boss/wupunch.bmp", 11880, 594, 27, 2, true, RGB(255, 0, 255));
#pragma endregion BOSS
	// ġ��� =========================================================================================================================
#pragma region CHEERLEADER
	// ġ��� �ٿ�
	IMAGEMANAGER->addFrameImage("CHEERLEADER_backDown", "Resource/IMG/character/enemy/cheerLeader/backdown.bmp", 9338, 436, 29, 2, true, RGB(255, 0, 255));
	// ġ��� ���ø�(�����)
	IMAGEMANAGER->addFrameImage("CHEERLEADER_backFlip", "Resource/IMG/character/enemy/cheerLeader/backflip.bmp", 6732, 612, 22, 2, true, RGB(255, 0, 255));
	// ġ��� ����(�� �շ�)
	IMAGEMANAGER->addFrameImage("CHEERLEADER_begging", "Resource/IMG/character/enemy/cheerLeader/begging.bmp", 513, 372, 3, 2, true, RGB(255, 0, 255));
	// ġ��� ����
	IMAGEMANAGER->addFrameImage("CHEERLEADER_block", "Resource/IMG/character/enemy/cheerLeader/block.bmp", 519, 428, 3, 2, true, RGB(255, 0, 255));
	// ġ��� �޺�����
	IMAGEMANAGER->addFrameImage("CHEERLEADER_comboAttack1", "Resource/IMG/character/enemy/cheerLeader/ComboAttack1.bmp", 1332, 468, 6, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("CHEERLEADER_comboAttack2", "Resource/IMG/character/enemy/cheerLeader/ComboAttack2.bmp", 1827, 426, 7, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("CHEERLEADER_comboAttack3", "Resource/IMG/character/enemy/cheerLeader/ComboAttack3.bmp", 4050, 498, 15, 2, true, RGB(255, 0, 255));
	// ġ��� ��Ʈ
	IMAGEMANAGER->addFrameImage("CHEERLEADER_getHit", "Resource/IMG/character/enemy/cheerLeader/gethit.bmp", 1539, 426, 9, 2, true, RGB(255, 0, 255));
	// ġ��� �����Ʈ
	IMAGEMANAGER->addFrameImage("CHEERLEADER_heldHit", "Resource/IMG/character/enemy/cheerLeader/HeldHit.bmp", 840, 384, 5, 2, true, RGB(255, 0, 255));
	// ġ��� ��� �ع�
	IMAGEMANAGER->addFrameImage("CHEERLEADER_heldRelease", "Resource/IMG/character/enemy/cheerLeader/HeldRelease.bmp", 840, 456, 4, 2, true, RGB(255, 0, 255));
	// ġ��� ������
	IMAGEMANAGER->addFrameImage("CHEERLEADER_idle", "Resource/IMG/character/enemy/cheerLeader/idle.bmp", 2304, 432, 12, 2, true, RGB(255, 0, 255));
	// ġ��� ����
	IMAGEMANAGER->addFrameImage("CHEERLEADER_jump", "Resource/IMG/character/enemy/cheerLeader/jump.bmp", 540, 474, 3, 2, true, RGB(255, 0, 255));
	// ġ��� ���� ����
	IMAGEMANAGER->addFrameImage("CHEERLEADER_jumpAttack", "Resource/IMG/character/enemy/cheerLeader/JumpAttack.bmp", 1491, 654, 7, 2, true, RGB(255, 0, 255));
	// ġ��� ������(��ٸ� ��)
	IMAGEMANAGER->addFrameImage("CHEERLEADER_ladder", "Resource/IMG/character/enemy/cheerLeader/ladder.bmp", 900, 255, 6, 1, true, RGB(255, 0, 255));
	// ġ��� �޸���
	IMAGEMANAGER->addFrameImage("CHEERLEADER_run", "Resource/IMG/character/enemy/cheerLeader/run.bmp", 1368, 318, 8, 2, true, RGB(255, 0, 255));
	// ġ��� ����
	IMAGEMANAGER->addFrameImage("CHEERLEADER_stun", "Resource/IMG/character/enemy/cheerLeader/stun.bmp", 540, 390, 4, 2, true, RGB(255, 0, 255));
	// ġ��� ����?(�Ƹ��� ��ٸ����� ������ ��������)
	IMAGEMANAGER->addFrameImage("CHEERLEADER_transition", "Resource/IMG/character/enemy/cheerLeader/transition.bmp", 396, 186, 3, 1, true, RGB(255, 0, 255));
	// ġ��� �ȱ�
	IMAGEMANAGER->addFrameImage("CHEERLEADER_walk", "Resource/IMG/character/enemy/cheerLeader/walk.bmp", 2736, 438, 12, 2, true, RGB(255, 0, 255));
	// ġ��� ������Ʈ
	IMAGEMANAGER->addFrameImage("CHEERLEADER_weaponHit", "Resource/IMG/character/enemy/cheerLeader/weaponHit.bmp", 7084, 436, 22, 2, true, RGB(255, 0, 255));


#pragma endregion CHEERLEADER

	// ������ =========================================================================================================================
#pragma region SCHOOLBOYIMAGE 

	//SCHOOLBOYIMAGE

	IMAGEMANAGER->addFrameImage("SCHOOLBOY_backdown", "Resource/IMG/character/enemy/scoolBoy/backdown.bmp", 7695, 438, 27, 2, true, RGB(255, 0, 255));			//�Ѿ�������
	IMAGEMANAGER->addFrameImage("SCHOOLBOY_begging", "Resource/IMG/character/enemy/scoolBoy/begging.bmp", 216, 354, 2, 2, true, RGB(255, 0, 255));				//�׺�
	IMAGEMANAGER->addFrameImage("SCHOOLBOY_block", "Resource/IMG/character/enemy/scoolBoy/block.bmp", 459, 438, 3, 2, true, RGB(255, 0, 255));					//����
	IMAGEMANAGER->addFrameImage("SCHOOLBOY_comboAttack1", "Resource/IMG/character/enemy/scoolBoy/ComboAttack1.bmp", 2352, 426, 7, 2, true, RGB(255, 0, 255));	//����1
	IMAGEMANAGER->addFrameImage("SCHOOLBOY_comboAttack2", "Resource/IMG/character/enemy/scoolBoy/ComboAttack2.bmp", 1757, 444, 7, 2, true, RGB(255, 0, 255));	//����2
	IMAGEMANAGER->addFrameImage("SCHOOLBOY_comboAttack3", "Resource/IMG/character/enemy/scoolBoy/ComboAttack3.bmp", 1890, 558, 9, 2, true, RGB(255, 0, 255));	//����3

	IMAGEMANAGER->addFrameImage("SCHOOLBOY_gethit", "Resource/IMG/character/enemy/scoolBoy/gethit.bmp", 1728, 450, 9, 2, true, RGB(255, 0, 255));				//�´� ����
	IMAGEMANAGER->addFrameImage("SCHOOLBOY_heldHit", "Resource/IMG/character/enemy/scoolBoy/HeldHit.bmp", 576, 372, 3, 2, true, RGB(255, 0, 255));				//������ �´� ����
	IMAGEMANAGER->addFrameImage("SCHOOLBOY_heldRelease", "Resource/IMG/character/enemy/scoolBoy/HeldRelease.bmp", 660, 480, 4, 2, true, RGB(255, 0, 255));		//������ Ǭ ����
	IMAGEMANAGER->addFrameImage("SCHOOLBOY_idle", "Resource/IMG/character/enemy/scoolBoy/idle.bmp", 1224, 432, 8, 2, true, RGB(255, 0, 255));					//�⺻
	IMAGEMANAGER->addFrameImage("SCHOOLBOY_jump", "Resource/IMG/character/enemy/scoolBoy/jump.bmp", 423, 486, 3, 2, true, RGB(255, 0, 255));					//����
	IMAGEMANAGER->addFrameImage("SCHOOLBOY_jumpAttack", "Resource/IMG/character/enemy/scoolBoy/jumpAttack.bmp", 1224, 468, 6, 2, true, RGB(255, 0, 255));		//���� ����
	IMAGEMANAGER->addFrameImage("SCHOOLBOY_ladder", "Resource/IMG/character/enemy/scoolBoy/ladder.bmp", 738, 264, 6, 1, true, RGB(255, 0, 255));				//���ö󰡴µ���
	IMAGEMANAGER->addFrameImage("SCHOOLBOY_run", "Resource/IMG/character/enemy/scoolBoy/run.bmp", 1920, 390, 10, 2, true, RGB(255, 0, 255));					//�޸���
	IMAGEMANAGER->addFrameImage("SCHOOLBOY_stun", "Resource/IMG/character/enemy/scoolBoy/Stun.bmp", 633, 408, 4, 2, true, RGB(255, 0, 255));					//����
	IMAGEMANAGER->addFrameImage("SCHOOLBOY_transition", "Resource/IMG/character/enemy/scoolBoy/transition.bmp", 405, 183, 3, 1, true, RGB(255, 0, 255));		//���ö�� ��
	IMAGEMANAGER->addFrameImage("SCHOOLBOY_upercut", "Resource/IMG/character/enemy/scoolBoy/upercut.bmp", 1386, 502, 7, 2, true, RGB(255, 0, 255));				//������
	IMAGEMANAGER->addFrameImage("SCHOOLBOY_walk", "Resource/IMG/character/enemy/scoolBoy/Walk.bmp", 1620, 444, 12, 2, true, RGB(255, 0, 255));					//�ȱ�
	IMAGEMANAGER->addFrameImage("SCHOOLBOY_wAttack", "Resource/IMG/character/enemy/scoolBoy/WAttack.bmp", 1830, 660, 5, 2, true, RGB(255, 0, 255));				//���� �ֵѱ�

	IMAGEMANAGER->addFrameImage("SCHOOLBOY_weaponSwing", "Resource/IMG/character/enemy/scoolBoy/weapon_swing.bmp", 5415, 438, 19, 2, true, RGB(255, 0, 255));	//���� �´� ����
	IMAGEMANAGER->addFrameImage("SCHOOLBOY_weaponHit", "Resource/IMG/character/enemy/scoolBoy/weaponHit.bmp", 5415, 438, 19, 2, true, RGB(255, 0, 255));		//���� ���� ����

	IMAGEMANAGER->addFrameImage("SCHOOLBOY_wIdle", "Resource/IMG/character/enemy/scoolBoy/WIdle.bmp", 1224, 552, 8, 2, true, RGB(255, 0, 255));					//���� �� ����
	IMAGEMANAGER->addFrameImage("SCHOOLBOY_wJump", "Resource/IMG/character/enemy/scoolBoy/WJump.bmp", 432, 468, 3, 2, true, RGB(255, 0, 255));					//���� ����
	IMAGEMANAGER->addFrameImage("SCHOOLBOY_wRun", "Resource/IMG/character/enemy/scoolBoy/WRun.bmp", 2250, 516, 10, 2, true, RGB(255, 0, 255));					//���� ��
	IMAGEMANAGER->addFrameImage("SCHOOLBOY_wThrow", "Resource/IMG/character/enemy/scoolBoy/WThrow.bmp", 1752, 564, 8, 2, true, RGB(255, 0, 255));				//���� ������
	IMAGEMANAGER->addFrameImage("SCHOOLBOY_wWalk", "Resource/IMG/character/enemy/scoolBoy/WWalk.bmp", 1572, 556, 12, 2, true, RGB(255, 0, 255));				//���� ��� �ȱ�



	//Resource/IMG/character/enemy/

#pragma endregion SCHOOLBOYIMAGE

	// �����   =========================================================================================================================
#pragma region SCHOOLGIRL

	//SCHOOLGIRLIMAGE

	IMAGEMANAGER->addFrameImage("SCHOOLGIRL_attack1", "Resource/IMG/character/enemy/schoolGirl/attack1.bmp", 2208, 354, 8, 2, true, RGB(255, 0, 255));				//����1 �ִ�������? 
	IMAGEMANAGER->addFrameImage("SCHOOLGIRL_backdown", "Resource/IMG/character/enemy/schoolGirl/backdown.bmp", 6939, 376, 27, 2, true, RGB(255, 0, 255));			//�Ѿ����� �Ͼ
	IMAGEMANAGER->addFrameImage("SCHOOLGIRL_begging", "Resource/IMG/character/enemy/schoolGirl/begging.bmp", 378, 336, 3, 2, true, RGB(255, 0, 255));				//�׺�
	IMAGEMANAGER->addFrameImage("SCHOOLGIRL_block", "Resource/IMG/character/enemy/schoolGirl/block.bmp", 351, 338, 3, 2, true, RGB(255, 0, 255));					//����
	IMAGEMANAGER->addFrameImage("SCHOOLGIRL_comboAttack1", "Resource/IMG/character/enemy/schoolGirl/ComboAttack1.bmp", 1239, 354, 7, 2, true, RGB(255, 0, 255));	//�޺� ����1
	IMAGEMANAGER->addFrameImage("SCHOOLGIRL_comboAttack2", "Resource/IMG/character/enemy/schoolGirl/ComboAttack2.bmp", 2208, 354, 8, 2, true, RGB(255, 0, 255));	//�޺� ����2
	IMAGEMANAGER->addFrameImage("SCHOOLGIRL_comboAttack3", "Resource/IMG/character/enemy/schoolGirl/ComboAttack3.bmp", 2412, 414, 12, 2, true, RGB(255, 0, 255));	//�޺� ����3

	IMAGEMANAGER->addFrameImage("SCHOOLGIRL_gethit", "Resource/IMG/character/enemy/schoolGirl/gethit.bmp", 1431, 360, 9, 2, true, RGB(255, 0, 255));				//�ǰݴ���
	IMAGEMANAGER->addFrameImage("SCHOOLGIRL_heldHit", "Resource/IMG/character/enemy/schoolGirl/HeldHit.bmp", 576, 336, 4, 2, true, RGB(255, 0, 255));				//������ �ǰݴ���
	IMAGEMANAGER->addFrameImage("SCHOOLGIRL_heldRelease", "Resource/IMG/character/enemy/schoolGirl/HeldRelease.bmp", 528, 360, 4, 2, true, RGB(255, 0, 255));		//������ ����
	IMAGEMANAGER->addFrameImage("SCHOOLGIRL_idle", "Resource/IMG/character/enemy/schoolGirl/idle.bmp", 1170, 354, 10, 2, true, RGB(255, 0, 255));					//�⺻
	IMAGEMANAGER->addFrameImage("SCHOOLGIRL_jump", "Resource/IMG/character/enemy/schoolGirl/jump.bmp", 342, 366, 3, 2, true, RGB(255, 0, 255));						//����
	IMAGEMANAGER->addFrameImage("SCHOOLGIRL_jumpAttack", "Resource/IMG/character/enemy/schoolGirl/jumpAttack.bmp", 1197, 354, 7, 2, true, RGB(255, 0, 255));		//���� ����
	IMAGEMANAGER->addFrameImage("SCHOOLGIRL_ladder", "Resource/IMG/character/enemy/schoolGirl/ladder.bmp", 594, 219, 6, 1, true, RGB(255, 0, 255));					//���ö󰡱�
	IMAGEMANAGER->addFrameImage("SCHOOLGIRL_run", "Resource/IMG/character/enemy/schoolGirl/run.bmp", 1470, 330, 10, 2, true, RGB(255, 0, 255));						//�޸���
	IMAGEMANAGER->addFrameImage("SCHOOLGIRL_stun", "Resource/IMG/character/enemy/schoolGirl/stun.bmp", 456, 324, 4, 2, true, RGB(255, 0, 255));						//����
	IMAGEMANAGER->addFrameImage("SCHOOLGIRL_transition", "Resource/IMG/character/enemy/schoolGirl/transition.bmp", 387, 168, 3, 1, true, RGB(255, 0, 255));			//���ö� �� ��
	IMAGEMANAGER->addFrameImage("SCHOOLGIRL_walk", "Resource/IMG/character/enemy/schoolGirl/walk.bmp", 1296, 372, 12, 2, true, RGB(255, 0, 255));					//�ȱ�
	IMAGEMANAGER->addFrameImage("SCHOOLGIRL_wAttack", "Resource/IMG/character/enemy/schoolGirl/WAttack.bmp", 1580, 558, 5, 2, true, RGB(255, 0, 255));				//���� ����

	IMAGEMANAGER->addFrameImage("SCHOOLGIRL_weapon_swing", "Resource/IMG/character/enemy/schoolGirl/weapon_swing.bmp", 4369, 336, 17, 2, true, RGB(255, 0, 255));	//���� ���� �ǰݴ��ҽ�
	IMAGEMANAGER->addFrameImage("SCHOOLGIRL_weaponHit", "Resource/IMG/character/enemy/schoolGirl/weaponHit.bmp", 4369, 336, 17, 2, true, RGB(255, 0, 255));			//���� �ǰݴ��ҽ�

	IMAGEMANAGER->addFrameImage("SCHOOLGIRL_wIdle", "Resource/IMG/character/enemy/schoolGirl/WIdle.bmp", 1950, 408, 10, 2, true, RGB(255, 0, 255));					//���� �⺻
	IMAGEMANAGER->addFrameImage("SCHOOLGIRL_wJump", "Resource/IMG/character/enemy/schoolGirl/WJump.bmp", 429, 450, 3, 2, true, RGB(255, 0, 255));					//���� ����
	IMAGEMANAGER->addFrameImage("SCHOOLGIRL_wRun", "Resource/IMG/character/enemy/schoolGirl/WRun.bmp", 1880, 458, 10, 2, true, RGB(255, 0, 255));					//���� �޸���
	IMAGEMANAGER->addFrameImage("SCHOOLGIRL_wThrow", "Resource/IMG/character/enemy/schoolGirl/WThrow.bmp", 1488, 540, 8, 2, true, RGB(255, 0, 255));				//���� ������
	IMAGEMANAGER->addFrameImage("SCHOOLGIRL_wWalk", "Resource/IMG/character/enemy/schoolGirl/WWalk.bmp", 2232, 502, 12, 2, true, RGB(255, 0, 255));					//���� �ȱ�

#pragma endregion SCHOOLGIRL

#pragma endregion ENEMYIMAGE

	//////////////////////////////////////////////////////////////////////////======UI======//////////////////////////////////////////////////////////////////////////////////
#pragma region UI

	//battle
	//���� HP ��
	IMAGEMANAGER->addImage("BATTLE_bossHPBack", "Resource/IMG/ui/battle/boss_HP_back.bmp", 689, 120, true, RGB(255, 0, 255));

	//���� HP ������
	IMAGEMANAGER->addImage("BATTLE_bossHPFrame", "Resource/IMG/ui/battle/boss_HP_frame.bmp", 898, 120, true, RGB(255, 0, 255));

	//���� HP ��
	IMAGEMANAGER->addImage("BATTLE_bossHPFront", "Resource/IMG/ui/battle/boss_HP_front.bmp", 689, 120, true, RGB(255, 0, 255));

	//����
	IMAGEMANAGER->addImage("BATTLE_coin", "Resource/IMG/ui/battle/coin.bmp", 36, 36, true, RGB(255, 0, 255));

	//HP ��ĭ
	IMAGEMANAGER->addImage("BATTLE_HP", "Resource/IMG/ui/battle/HP_Point.bmp", 25, 23, true, RGB(255, 0, 255));

	//�������� ȭ�� �� �Ʒ�
	IMAGEMANAGER->addImage("BATTLE_stageChainBottom", "Resource/IMG/ui/battle/Stage_UI_Chain_Bottom.bmp", 1600, 43, true, RGB(255, 0, 255));

	//�������� ȭ�� �� ����
	IMAGEMANAGER->addImage("BATTLE_stageChainLeft", "Resource/IMG/ui/battle/Stage_UI_Chain_Left.bmp", 42, 900, true, RGB(255, 0, 255));

	//�������� ȭ�� �� ������
	IMAGEMANAGER->addImage("BATTLE_stageChainRight", "Resource/IMG/ui/battle/Stage_UI_Chain_Right.bmp", 41, 900, true, RGB(255, 0, 255));

	//�������� ȭ�� �� ��
	IMAGEMANAGER->addImage("BATTLE_stageChainTop", "Resource/IMG/ui/battle/Stage_UI_Chain_Top.bmp", 1600, 43, true, RGB(255, 0, 255));

	//�������� ��ݽ� �ڹ���
	IMAGEMANAGER->addFrameImage("BATTLE_lockAppear", "Resource/IMG/ui/battle/Stage_UI_Lock_Appear.bmp", 650, 116, 7, 1, true, RGB(255, 0, 255));

	//�������� ��ݽ� �ڹ��� ����
	IMAGEMANAGER->addFrameImage("BATTLE_lockDamage1", "Resource/IMG/ui/battle/Stage_UI_Lock_Damage1.bmp", 650, 116, 7, 1, true, RGB(255, 0, 255));

	//�������� ��ݽ� �ڹ��� �� ����
	IMAGEMANAGER->addFrameImage("BATTLE_lockDamage2", "Resource/IMG/ui/battle/Stage_UI_Lock_Damage2.bmp", 650, 116, 7, 1, true, RGB(255, 0, 255));

	//�������� ��ݽ� �ڹ��� ��¥ ����
	IMAGEMANAGER->addFrameImage("BATTLE_lockDisappear", "Resource/IMG/ui/battle/Stage_UI_Lock_Disappear.bmp", 840, 130, 7, 1, true, RGB(255, 0, 255));

	//��Ʈ UI <- ���� �������� �� �����°� ������,.
	IMAGEMANAGER->addImage("BATTLE_Heart", "Resource/IMG/ui/battle/UI_heart.bmp", 6400, 3600, true, RGB(255, 0, 255));

	//�÷��̾� ������
	IMAGEMANAGER->addImage("BATTLE_playerPortrait", "Resource/IMG/ui/battle/UI_Kyoko_Portrait.bmp", 120, 135, true, RGB(255, 0, 255));

	//�÷��̾� UI��
	IMAGEMANAGER->addImage("BATTLE_playerBar", "Resource/IMG/ui/battle/UI_Player_bar.bmp", 414, 94, true, RGB(255, 0, 255));

	//���� ǥ��-�÷��̾� ����� ��
	IMAGEMANAGER->addImage("BATTLE_shopDoor1", "Resource/IMG/ui/battle/UI_Shop_Door1.bmp", 52, 45, true, RGB(255, 0, 255));

	//���� ǥ��-�÷��̾� �� ��
	IMAGEMANAGER->addImage("BATTLE_shopDoor2", "Resource/IMG/ui/battle/UI_Shop_Door2.bmp", 52, 45, true, RGB(255, 0, 255));

	//�� ��� ǥ��
	IMAGEMANAGER->addImage("BATTLE_lockedDoor", "Resource/IMG/ui/battle/UI_Locked_Door.bmp", 52, 76, true, RGB(255, 0, 255));

	//�� ����-�÷��̾� ����� ��
	IMAGEMANAGER->addImage("BATTLE_unlockDoor1", "Resource/IMG/ui/battle/UI_UnLocked_Door.bmp", 52, 76, true, RGB(255, 0, 255));

	//�� ����-�÷��̾� �� ��
	IMAGEMANAGER->addImage("BATTLE_unlockDoor2", "Resource/IMG/ui/battle/UI_UnLocked_Door22.bmp", 52, 76, true, RGB(255, 0, 255));



	//inven
	//�ڵ���
	IMAGEMANAGER->addImage("INVEN_phone", "Resource/IMG/ui/inven/phone.bmp", 480, 642, true, RGB(255, 0, 255));

	//�����
	IMAGEMANAGER->addImage("INVEN_bat", "Resource/IMG/ui/inven/ui_bat.bmp", 80, 79, true, RGB(255, 0, 255));



	//scene
	//��ŸƮ�� ���
	IMAGEMANAGER->addImage("SCENE_startSceneBackground", "Resource/IMG/ui/scene/StartScene_Background.bmp", 1280, 720, true, RGB(255, 0, 255));

	//��ŸƮ�� ������
	IMAGEMANAGER->addImage("SCENE_startSceneFrame", "Resource/IMG/ui/scene/StartScene_Frame.bmp", 1600, 900, true, RGB(255, 0, 255));

	//��ŸƮ�� ����
	IMAGEMANAGER->addImage("SCENE_startSceneKyoko", "Resource/IMG/ui/scene/StartScene_Kyoko.bmp", 672, 1024, true, RGB(255, 0, 255));

	//��ŸƮ�� �̻���
	IMAGEMANAGER->addImage("SCENE_startSceneMisako", "Resource/IMG/ui/scene/StartScene_Misako.bmp", 672, 1024, true, RGB(255, 0, 255));

	//��ŸƮ�� Ÿ��Ʋ(����)
	IMAGEMANAGER->addImage("SCENE_startSceneTitle", "Resource/IMG/ui/scene/StartScene_Title.bmp", 537, 308, true, RGB(255, 0, 255));

	//�ε���
	IMAGEMANAGER->addImage("SCENE_loadingScene", "Resource/IMG/ui/scene/LoadingScene_Background.bmp", 1280, 720, true, RGB(255, 0, 255));

	//�ε��� �����ϴ� ��������Ʈ
	IMAGEMANAGER->addFrameImage("SCENE_loadingSprite", "Resource/IMG/ui/scene/loadingSprite.bmp", 1152, 227, 4, 1, true, RGB(255, 0, 255));

	//���� ���
	IMAGEMANAGER->addImage("SCENE_shopBackground", "Resource/IMG/ui/scene/ShopScene_background.bmp", 1280, 720, true, RGB(255, 0, 255));

	//���� ���� ��ư
	IMAGEMANAGER->addImage("SCENE_shopBuyButton", "Resource/IMG/ui/scene/ShopScene_buyButton.bmp", 145, 92, true, RGB(255, 0, 255));

	//���� ������ ����������-����Ʈ
	IMAGEMANAGER->addImage("SCENE_shopList", "Resource/IMG/ui/scene/ShopScene_list.bmp", 403, 168, true, RGB(255, 0, 255));

	//���̾�α� �޹��
	IMAGEMANAGER->addImage("SCENE_dialogWindow", "Resource/IMG/ui/scene/dialogWindow.bmp", 1280, 150, true, RGB(255, 0, 255));

	//���� ���� ���-�̰� �����ؾߵɵ�!!!!!!!!!!!!!!!!!!!!!!!!
	//IMAGEMANAGER->addImage("SCENE_endScene", "Resource/IMG/ui/scene/endScene.bmp", 1280, 720, true, RGB(255, 0, 255));

	//���̾�α� �÷��̾�
	IMAGEMANAGER->addImage("SCENE_kyoko1", "Resource/IMG/ui/scene/kyoko_1.bmp", 386, 460, true, RGB(255, 0, 255));

	//���̾�α� �÷��̾�
	IMAGEMANAGER->addImage("SCENE_kyoko2", "Resource/IMG/ui/scene/kyoko_2.bmp", 386, 460, true, RGB(255, 0, 255));

	//���̾�α� �÷��̾�
	IMAGEMANAGER->addImage("SCENE_kyoko3", "Resource/IMG/ui/scene/kyoko_3.bmp", 386, 460, true, RGB(255, 0, 255));

	//���̾�α� �÷��̾� �̸�
	IMAGEMANAGER->addImage("SCENE_kyokoName", "Resource/IMG/ui/scene/kyoko_name.bmp", 200, 76, true, RGB(255, 0, 255));

	//���̾�α� ����
	IMAGEMANAGER->addImage("SCENE_misuzu1", "Resource/IMG/ui/scene/misuzu_1.bmp", 386, 460, true, RGB(255, 0, 255));

	//���̾�α� ����
	IMAGEMANAGER->addImage("SCENE_misuzu2", "Resource/IMG/ui/scene/misuzu_2.bmp", 386, 460, true, RGB(255, 0, 255));

	//���̾�α� ����
	IMAGEMANAGER->addImage("SCENE_misuzu3", "Resource/IMG/ui/scene/misuzu_3.bmp", 386, 460, true, RGB(255, 0, 255));

	//���̾�α� ���� �̸�
	IMAGEMANAGER->addImage("SCENE_misuzuName", "Resource/IMG/ui/scene/misuzu_name.bmp", 200, 76, true, RGB(255, 0, 255));

	//���̾�α� ��ŵ ǥ��-����
	IMAGEMANAGER->addImage("SCENE_skipOutlines1", "Resource/IMG/ui/scene/UI_skip_outlines_FULL.bmp", 206, 78, true, RGB(255, 0, 255));

	//���̾�α� ��ŵ ǥ��-ȭ��Ʈ
	IMAGEMANAGER->addImage("SCENE_skipOutlines2", "Resource/IMG/ui/scene/UI_skip_outlines_WHITE.bmp", 206, 78, true, RGB(255, 0, 255));

	//���̺� �ε�
	IMAGEMANAGER->addImage("SCENE_saveLoadClose1", "Resource/IMG/ui/scene/save_load_close.bmp", 365, 150, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("SCENE_saveLoadOpen1", "Resource/IMG/ui/scene/save_load_open.bmp", 365, 150, true, RGB(255, 0, 255));

	//���̺� �ε� ������
	IMAGEMANAGER->addImage("SCENE_saveLoadClose2", "Resource/IMG/ui/scene/save_load_close0.bmp", 365, 150, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("SCENE_saveLoadOpen2", "Resource/IMG/ui/scene/save_load_open0.bmp", 365, 150, true, RGB(255, 0, 255));

	//���̺� �ε� ��������1
	IMAGEMANAGER->addImage("SCENE_saveLoadClose3", "Resource/IMG/ui/scene/save_load_close1.bmp", 365, 150, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("SCENE_saveLoadOpen3", "Resource/IMG/ui/scene/save_load_open1.bmp", 365, 150, true, RGB(255, 0, 255));

	//ĳ���� ����Ʈ�� ��� �Ķ���
	IMAGEMANAGER->addImage("SCENE_selectSceneBackground1", "Resource/IMG/ui/scene/SelectScene_Background.bmp", 1280, 720, true, RGB(255, 0, 255));

	//ĳ���� ����Ʈ�� ��� �ʷϻ�
	IMAGEMANAGER->addImage("SCENE_selectSceneBackground2", "Resource/IMG/ui/scene/SelectScene_background2.bmp", 1280, 720, true, RGB(255, 0, 255));

	//����Ʈ�� ĳ���� �Ϸ���Ʈ
	IMAGEMANAGER->addImage("SCENE_selectSceneIllust", "Resource/IMG/ui/scene/SelectScene_illust.bmp", 996, 1705, true, RGB(255, 0, 255));

	//����Ʈ�� ���� �������� ��
	IMAGEMANAGER->addImage("SCENE_selectSceneKyoko1", "Resource/IMG/ui/scene/SelectScene_kyoko.bmp", 375, 675, true, RGB(255, 0, 255));
	//������ ��
	IMAGEMANAGER->addImage("SCENE_selectSceneKyoko2", "Resource/IMG/ui/scene/SelectScene_kyoko2.bmp", 375, 675, true, RGB(255, 0, 255));
	//�޹��
	IMAGEMANAGER->addImage("SCENE_selectSceneKyokoBackground", "Resource/IMG/ui/scene/SelectScene_kyoko_background.bmp", 360, 563, true, RGB(255, 0, 255));

	//����Ʈ�� �̻��� �������� ��
	IMAGEMANAGER->addImage("SCENE_selectSceneMisako1", "Resource/IMG/ui/scene/SelectScene_misako.bmp", 375, 675, true, RGB(255, 0, 255));
	//������ ��
	IMAGEMANAGER->addImage("SCENE_selectSceneMisako2", "Resource/IMG/ui/scene/SelectScene_misako2.bmp", 375, 675, true, RGB(255, 0, 255));
	//�޹��
	IMAGEMANAGER->addImage("SCENE_selectMisakoBackground", "Resource/IMG/ui/scene/SelectScene_misako_background.bmp", 360, 563, true, RGB(255, 0, 255));

	//����Ʈ�� �޴��� ��ư
	IMAGEMANAGER->addImage("SCENE_selectSceneManualButton", "Resource/IMG/ui/scene/SelectScene_manualButton.bmp", 650, 173, true, RGB(255, 0, 255));

#pragma endregion UI

	//////////////////////////////////////////////////////////////////////////======����Ʈ======//////////////////////////////////////////////////////////////////////////////
#pragma region EFFECTIMAGE

	//��� �ǰ� �⺻ ���
	EFFECTMANAGER->addEffect("EFFECT_attackBackground", "resources/IMG/effect/attack.bmp", 612, 196, 204, 196, 1, 5.0f, 100);
	//����
	EFFECTMANAGER->addEffect("EFFECT_stun", "resources/IMG/effect/stun.bmp", 420, 54, 70, 54, 1, 5.0f, 100);

	//���Ǳ� �ı�
	EFFECTMANAGER->addEffect("EFFECT_objBreak", "resources/IMG/effect/obj break.bmp", 3304, 248, 236, 248, 1, 5.0f, 100);
	//�ٴڱտ� 1��
	EFFECTMANAGER->addEffect("EFFECT_bossStand1", "resources/IMG/effect/Boss stand2.bmp", 3390, 144, 484, 144, 1, 5.0f, 100);
	//�ٴڱտ� 2��
	EFFECTMANAGER->addEffect("EFFECT_groundbreak", "resources/IMG/effect/groundbreak.bmp", 256, 128, 256, 128, 1, 5.0f, 100);
	//��� �ı�(����)
	EFFECTMANAGER->addEffect("EFFECT_bossEffect", "resources/IMG/effect/boss_effect5.bmp", 800, 90, 114, 90, 1, 5.0f, 100);
	//��� �ı�(���)
	EFFECTMANAGER->addEffect("EFFECT_dashAttack", "resources/IMG/effect/dashAttackEffect.bmp", 400, 45, 57, 45, 1, 5.0f, 100);
	//ȭ�� ����
	EFFECTMANAGER->addEffect("EFFECT_crush", "resources/IMG/effect/crush.bmp", 190, 193, 190, 193, 1, 5.0f, 100);

	//�÷��̾� ���� frameY(2)
	EFFECTMANAGER->addEffect("EFFECT_run", "resources/IMG/effect/run.bmp", 2544, 246, 212, 123, 1, 5.0f, 100);
	//���� ����
	EFFECTMANAGER->addEffect("EFFECT_runL", "resources/IMG/effect/runL.bmp", 2784, 126, 232, 126, 1, 5.0f, 100);
	//���� ����
	EFFECTMANAGER->addEffect("EFFECT_runR", "resources/IMG/effect/runR.bmp", 2544, 123, 212, 123, 1, 5.0f, 100);
	//�÷��̾� Ÿ��
	EFFECTMANAGER->addEffect("EFFECT_blueAttack", "resources/IMG/effect/blueAttack.bmp", 720, 80, 80, 80, 1, 5.0f, 100);
	//����� Ÿ��
	EFFECTMANAGER->addEffect("EFFECT_effectSpark", "resources/IMG/effect/effect_spark.bmp", 512, 128, 128, 128, 1, 5.0f, 100);
	//�÷��̾� ���
	EFFECTMANAGER->addEffect("EFFECT_bossHowling", "resources/IMG/effect/Boss howling.bmp", 1824, 165, 228, 165, 1, 5.0f, 100);
	//����Ʈ ����
	EFFECTMANAGER->addEffect("EFFECT_effecBlue", "resources/IMG/effect/effec_blue.bmp", 720, 80, 80, 80, 1, 5.0f, 100);

	//�÷��̾� �ν�
	EFFECTMANAGER->addEffect("EFFECT_point", "resources/IMG/effect/point.bmp", 560, 70, 70, 70, 1, 5.0f, 100);
	//�ֳʹ� Ÿ��1
	EFFECTMANAGER->addEffect("EFFECT_effectStar", "resources/IMG/effect/effect_star.bmp", 900, 60, 60, 60, 1, 5.0f, 100);
	//�ֳʹ� Ÿ��2
	EFFECTMANAGER->addEffect("EFFECT_star", "resources/IMG/effect/star.bmp", 1350, 90, 90, 90, 1, 5.0f, 100);
	//����� Ÿ��(��ø)
	EFFECTMANAGER->addEffect("EFFECT_spark", "resources/IMG/effect/spark.bmp", 512, 128, 128, 128, 1, 5.0f, 100);
	//�ֳʹ� �׺�
	EFFECTMANAGER->addEffect("EFFECT_beg", "resources/IMG/effect/beg.bmp", 368, 127, 184, 127, 1, 5.0f, 100);
	//���ͱ���
	EFFECTMANAGER->addEffect("EFFECT_shake", "resources/IMG/effect/shake.bmp", 268, 127, 134, 127, 1, 5.0f, 100);

	//���� ��ý�����
	EFFECTMANAGER->addEffect("EFFECT_bossDash", "resources/IMG/effect/Boss dash.bmp", 12480, 900, 1248, 900, 1, 5.0f, 100);
	//���� ��ý�����(��ø)
	EFFECTMANAGER->addEffect("EFFECT_explosion1", "resources/IMG/effect/explosion1.bmp", 12480, 900, 1248, 900, 1, 5.0f, 100);
	//���� Ÿ��
	EFFECTMANAGER->addEffect("EFFECT_explosion", "resources/IMG/effect/explosion.bmp", 1701, 247, 243, 247, 1, 5.0f, 100);
	//���� Ÿ��(��ø)
	EFFECTMANAGER->addEffect("EFFECT_explosion2", "resources/IMG/effect/explosion2.bmp", 1701, 247, 243, 247, 1, 5.0f, 100);
	//���� ���� ����
	EFFECTMANAGER->addEffect("EFFECT_bossMeteor", "resources/IMG/effect/Boss meteor2.bmp", 2424, 320, 404, 196, 1, 5.0f, 100);
	//���� ���� ���� frameY(2)
	EFFECTMANAGER->addEffect("EFFECT_bossMeteor1", "resources/IMG/effect/Boss meteor.bmp", 1620, 640, 405, 320, 1, 5.0f, 100);
	//���� ������� �ǰ�
	EFFECTMANAGER->addEffect("EFFECT_bossSmash", "resources/IMG/effect/Boss smash.bmp", 960, 89, 96, 89, 1, 0.5f, 100);
	//���� ������� �ǰ�(��ø)
	EFFECTMANAGER->addEffect("EFFECT_bossSmash1", "resources/IMG/effect/et_boom_big.bmp", 960, 89, 96, 89, 1, 5.0f, 100);
	//���� ���
	EFFECTMANAGER->addEffect("EFFECT_bossHowling1", "resources/IMG/effect/Boss howling2.bmp", 416, 208, 208, 208, 1, 5.0f, 100);
	//������ �Ͼ ��
	EFFECTMANAGER->addEffect("EFFECT_bossStand", "resources/IMG/effect/Boss stand.bmp", 607, 55, 76, 55, 1, 5.0f, 100);
	//���� ��Ʈ ������
	EFFECTMANAGER->addEffect("EFFECT_bossPhase", "resources/IMG/effect/Boss phase1.bmp", 300, 82, 100, 82, 1, 5.0f, 100);


	////��� �ǰ� �⺻ ���
	//EFFECTMANAGER->addEffect("EFFECT_attack", "Resource/IMG/effect/attack.bmp", 612, 196, 3, 1, true, RGB(255, 0, 255));

	////�ֳʹ� �׺�
	//EFFECTMANAGER->addEffect("EFFECT_beg", "Resource/IMG/effect/beg.bmp", 268, 127, 2, 1, true, RGB(255, 0, 255));
	////�÷��̾� Ÿ��
	//EFFECTMANAGER->addEffect("EFFECT_blueAttack", "Resource/IMG/effect/blueAttack.bmp", 720, 80, 9, 1, true, RGB(255, 0, 255));
	////���� ��ý�����
	//EFFECTMANAGER->addEffect("EFFECT_bossDash", "Resource/IMG/effect/Boss dash.bmp", 12480, 900, 10, 1, true, RGB(255, 0, 255));
	////�÷��̾� ���
	//EFFECTMANAGER->addEffect("EFFECT_bossHowling", "Resource/IMG/effect/Boss howling.bmp", 1821, 165, 8, 1, true, RGB(255, 0, 255));
	////���� ���
	//EFFECTMANAGER->addEffect("EFFECT_bossHowling2", "Resource/IMG/effect/Boss howling2.bmp", 416, 208, 2, 1, true, RGB(255, 0, 255));
	////���� ���� ���� frameY(2)
	//EFFECTMANAGER->addEffect("EFFECT_bossMeteor", "Resource/IMG/effect/Boss meteor.bmp", 1620, 640, 4, 2, true, RGB(255, 0, 255));
	////���� ���� ����
	//EFFECTMANAGER->addEffect("EFFECT_bossMeteor2", "Resource/IMG/effect/Boss meteor2.bmp", 2424, 320, 6, 1, true, RGB(255, 0, 255));
	////���� ��Ʈ ������
	//EFFECTMANAGER->addEffect("EFFECT_bossPhase1", "Resource/IMG/effect/Boss phase1.bmp", 299, 82, 3, 1, true, RGB(255, 0, 255));
	////���� ������� �ǰ�
	//EFFECTMANAGER->addEffect("EFFECT_bossSmash", "Resource/IMG/effect/Boss smash.bmp", 960, 89, 10, 1, true, RGB(255, 0, 255));
	////������ �Ͼ ��
	//EFFECTMANAGER->addEffect("EFFECT_bossStand", "Resource/IMG/effect/Boss stand.bmp", 607, 55, 8, 1, true, RGB(255, 0, 255));
	////�ٴڱտ� 1��
	//EFFECTMANAGER->addEffect("EFFECT_bossStand2", "Resource/IMG/effect/Boss stand2.bmp", 3390, 144, 7, 1, true, RGB(255, 0, 255));
	////��� �ı�(����)
	//EFFECTMANAGER->addEffect("EFFECT_boss_effect5", "Resource/IMG/effect/boss_effect5.bmp", 800, 90, 7, 1, true, RGB(255, 0, 255));
	////ȭ�� ����
	//EFFECTMANAGER->addEffect("EFFECT_crush", "Resource/IMG/effect/crush.bmp", 190, 193, 1, 1, true, RGB(255, 0, 255));
	////��� �ı�(���)
	//EFFECTMANAGER->addEffect("EFFECT_dashAttackEffect", "Resource/IMG/effect/dashAttackEffect.bmp", 400, 45, 7, 1, true, RGB(255, 0, 255));
	////����Ʈ ����
	//EFFECTMANAGER->addEffect("EFFECT_effecBlue", "Resource/IMG/effect/effec_blue.bmp", 720, 80, 9, 1, true, RGB(255, 0, 255));
	////����� Ÿ��
	//EFFECTMANAGER->addEffect("EFFECT_effectSpark", "Resource/IMG/effect/effect_spark.bmp", 512, 128, 4, 1, true, RGB(255, 0, 255));
	////�ֳʹ� Ÿ��1
	//EFFECTMANAGER->addEffect("EFFECT_effectStar", "Resource/IMG/effect/effect_star.bmp", 900, 60, 15, 1, true, RGB(255, 0, 255));
	////���� ������� �ǰ�(��ø)
	//EFFECTMANAGER->addEffect("EFFECT_etBoomBig", "Resource/IMG/effect/et_boom_big.bmp", 960, 89, 10, 1, true, RGB(255, 0, 255));
	////���� Ÿ��
	//EFFECTMANAGER->addEffect("EFFECT_explosion", "Resource/IMG/effect/explosion.bmp", 1701, 247, 7, 1, true, RGB(255, 0, 255));
	////���� ��ý�����(��ø)
	//EFFECTMANAGER->addEffect("EFFECT_explosion1", "Resource/IMG/effect/explosion1.bmp", 12480, 900, 10, 1, true, RGB(255, 0, 255));
	////���� Ÿ��(��ø)
	//EFFECTMANAGER->addEffect("EFFECT_explosion2", "Resource/IMG/effect/explosion2.bmp", 1701, 247, 7, 1, true, RGB(255, 0, 255));
	////�ٴڱտ� 2��
	//EFFECTMANAGER->addEffect("EFFECT_groundbreak", "Resource/IMG/effect/groundbreak.bmp", 256, 128, 1, 1, true, RGB(255, 0, 255));
	////���Ǳ� �ı�
	//EFFECTMANAGER->addEffect("EFFECT_objBreak", "Resource/IMG/effect/obj break.bmp", 3304, 248, 14, 1, true, RGB(255, 0, 255));
	////�÷��̾� �ν�
	//EFFECTMANAGER->addEffect("EFFECT_point", "Resource/IMG/effect/point.bmp", 560, 70, 8, 1, true, RGB(255, 0, 255));
	////�÷��̾� ���� frameY(2)
	//EFFECTMANAGER->addEffect("EFFECT_run", "Resource/IMG/effect/run.bmp", 2544, 246, 12, 2, true, RGB(255, 0, 255));
	////���� ����
	//EFFECTMANAGER->addEffect("EFFECT_runL", "Resource/IMG/effect/runL.bmp", 2784, 126, 12, 1, true, RGB(255, 0, 255));
	////���� ����
	//EFFECTMANAGER->addEffect("EFFECT_runR", "Resource/IMG/effect/runR.bmp", 2544, 123, 12, 1, true, RGB(255, 0, 255));
	////���ͱ���
	//EFFECTMANAGER->addEffect("EFFECT_shake", "Resource/IMG/effect/shake.bmp", 268, 127, 2, 1, true, RGB(255, 0, 255));
	////����� Ÿ��(��ø)
	//EFFECTMANAGER->addEffect("EFFECT_spark", "Resource/IMG/effect/spark.bmp", 512, 128, 4, 1, true, RGB(255, 0, 255));
	////�ֳʹ� Ÿ��2
	//EFFECTMANAGER->addEffect("EFFECT_star", "Resource/IMG/effect/star.bmp", 1350, 90, 15, 1, true, RGB(255, 0, 255));
	////����
	//EFFECTMANAGER->addEffect("EFFECT_stun", "Resource/IMG/effect/stun.bmp", 420, 54, 6, 1, true, RGB(255, 0, 255));



#pragma endregion EFFECTIMAGE

	//////////////////////////////////////////////////////////////////////////======ITEM======///////////////////////////////////////////////////////////////////////////////
#pragma region ITEM

	//�˷ο�
	IMAGEMANAGER->addImage("ITEM_aloe", "Resource/IMG/item/aloe.bmp", 50, 76, true, RGB(255, 0, 255));
	//�ܹ���
	IMAGEMANAGER->addImage("ITEM_hamburger", "Resource/IMG/item/hamburger.bmp", 64, 55, true, RGB(255, 0, 255));
	//���̽�ũ��
	IMAGEMANAGER->addImage("ITEM_icecream", "Resource/IMG/item/icecream.bmp", 55, 70, true, RGB(255, 0, 255));
	//���
	IMAGEMANAGER->addImage("ITEM_meat", "Resource/IMG/item/meat.bmp", 60, 51, true, RGB(255, 0, 255));
	//����Ƣ��
	IMAGEMANAGER->addImage("ITEM_tempura", "Resource/IMG/item/tempura.bmp", 58, 60, true, RGB(255, 0, 255));
	//���
	IMAGEMANAGER->addImage("ITEM_apple", "Resource/IMG/item/apple.bmp", 48, 50, true, RGB(255, 0, 255));

#pragma endregion ITEM

	//////////////////////////////////////////////////////////////////////////======OBJECT======/////////////////////////////////////////////////////////////////////////////
#pragma region OBJECT

	//������Ʈ
	//���
	IMAGEMANAGER->addImage("OBJECT_apple", "Resource/IMG/object/apple.bmp", 100, 100, true, RGB(255, 0, 255));
	//����
	IMAGEMANAGER->addImage("OBJECT_chili", "Resource/IMG/object/chili.bmp", 100, 100, true, RGB(255, 0, 255));
	//ġŲ
	IMAGEMANAGER->addImage("OBJECT_hen", "Resource/IMG/object/hen.bmp", 100, 100, true, RGB(255, 0, 255));
	//å��
	IMAGEMANAGER->addImage("OBJECT_desk", "Resource/IMG/object/desk.bmp", 147, 162, true, RGB(255, 0, 255));
	//å��迭1
	IMAGEMANAGER->addImage("OBJECT_desk1", "Resource/IMG/object/desk1.bmp", 1174, 203, true, RGB(255, 0, 255));
	//å��迭2
	IMAGEMANAGER->addImage("OBJECT_desk2", "Resource/IMG/object/desk2.bmp", 936, 138, true, RGB(255, 0, 255));
	//���� å��
	IMAGEMANAGER->addImage("OBJECT_teachers_desk", "Resource/IMG/object/teachers_desk.bmp", 83, 34, true, RGB(255, 0, 255));
	//���̺�
	IMAGEMANAGER->addImage("OBJECT_table", "Resource/IMG/object/table.bmp", 339, 162, true, RGB(255, 0, 255));
	//�������ҽ�
	IMAGEMANAGER->addImage("OBJECT_fence", "Resource/IMG/object/fence.bmp", 476, 71, true, RGB(255, 0, 255));
	//���(������)
	IMAGEMANAGER->addImage("OBJECT_RPillar", "Resource/IMG/object/stage02_pillar.bmp", 195, 864, true, RGB(255, 0, 255));
	//���(����)																					 
	IMAGEMANAGER->addImage("OBJECT_LPillar", "Resource/IMG/object/stage03_pillar.bmp", 195, 864, true, RGB(255, 0, 255));
	//��� ����1
	IMAGEMANAGER->addImage("OBJECT_particle1", "Resource/IMG/object/pillar_particle_1.bmp", 64, 64, true, RGB(255, 0, 255));
	//��� ����2																					 
	IMAGEMANAGER->addImage("OBJECT_particle2", "Resource/IMG/object/pillar_particle_2.bmp", 64, 64, true, RGB(255, 0, 255));
	//��� ����3																					
	IMAGEMANAGER->addImage("OBJECT_particle3", "Resource/IMG/object/pillar_particle_3.bmp", 64, 64, true, RGB(255, 0, 255));
	//����
	IMAGEMANAGER->addFrameImage("OBJECT_gold", "Resource/IMG/object/gold_coin_spin.bmp", 512, 512, 4, 4, true, RGB(255, 0, 255));
	//����
	IMAGEMANAGER->addFrameImage("OBJECT_money", "Resource/IMG/object/money_green.bmp", 576, 432, 4, 4, true, RGB(255, 0, 255));
	//�Ĺ� ���
	IMAGEMANAGER->addFrameImage("OBJECT_backPillar", "Resource/IMG/object/pillar.bmp", 390, 678, 2, 1, true, RGB(255, 0, 255));
	//���� ���
	IMAGEMANAGER->addFrameImage("OBJECT_firstPillar", "Resource/IMG/object/pillar_big.bmp", 390, 957, 2, 1, true, RGB(255, 0, 255));
	//�ҿ�
	IMAGEMANAGER->addFrameImage("OBJECT_pet", "Resource/IMG/object/pet.bmp", 576, 96, 6, 1, true, RGB(255, 0, 255));
	//�����
	IMAGEMANAGER->addFrameImage("OBJECT_bat", "Resource/IMG/object/bat.bmp", 179, 104, 1, 2, true, RGB(255, 0, 255));
	//���Ǳ�
	IMAGEMANAGER->addFrameImage("OBJECT_vendingMachine", "Resource/IMG/object/vendingMachine.bmp", 525, 260, 2, 1, true, RGB(255, 0, 255));

#pragma endregion OBJECT

	//////////////////////////////////////////////////////////////////////////======STAGE======/////////////////////////////////////////////////////////////////////////////
#pragma region STAGE

	//���� ���� �� ��������
	IMAGEMANAGER->addImage("STAGE_boss1", "Resource/IMG/stage/boss1.bmp", 3116, 1215, true, RGB(255, 0, 255));
	//���� ���� �� ��������
	IMAGEMANAGER->addImage("STAGE_boss2", "Resource/IMG/stage/boss2.bmp", 3116, 1215, true, RGB(255, 0, 255));
	//���� ���� �� ��������(�߰�)
	IMAGEMANAGER->addImage("STAGE_bossStage1", "Resource/IMG/stage/boss_stage.bmp", 2769, 1080, true, RGB(255, 0, 255));
	//���� ���� �� ��������(�߰�)
	IMAGEMANAGER->addImage("STAGE_bossStage2", "Resource/IMG/stage/boss_stage2.bmp", 2769, 1080, true, RGB(255, 0, 255));
	//���� ���� ����
	IMAGEMANAGER->addImage("STAGE_easy", "Resource/IMG/stage/easy.bmp", 2028, 678, true, RGB(255, 0, 255));
	//���� ���� ����(�߰�)
	IMAGEMANAGER->addImage("STAGE_stage1", "Resource/IMG/stage/stage01.bmp", 2520, 840, true, RGB(255, 0, 255));
	//��������(����)
	IMAGEMANAGER->addImage("STAGE_stage2", "Resource/IMG/stage/stage02.bmp", 2400, 864, true, RGB(255, 0, 255));
	//��������(������)
	IMAGEMANAGER->addImage("STAGE_stage3", "Resource/IMG/stage/stage03.bmp", 2400, 865, true, RGB(255, 0, 255));
	//������
	IMAGEMANAGER->addImage("STAGE_stage4", "Resource/IMG/stage/stage04.bmp", 2112, 864, true, RGB(255, 0, 255));
	//������
	IMAGEMANAGER->addImage("STAGE_hard", "Resource/IMG/stage/hard.bmp", 2328, 1428, true, RGB(255, 0, 255));
	//������
	IMAGEMANAGER->addImage("STAGE_normal", "Resource/IMG/stage/normal.bmp", 2865, 837, true, RGB(255, 0, 255));
	//������ �ȼ�(�߰���)
	IMAGEMANAGER->addImage("STAGE_bossPixel", "Resource/IMG/stage/boss_stage_pixel.bmp", 2769, 1080, true, RGB(255, 0, 255));
	//���� �ȼ�(�߰���)
	IMAGEMANAGER->addImage("STAGE_stagePixel1", "Resource/IMG/stage/stage01_pixel.bmp", 2520, 840, true, RGB(255, 0, 255));
	//����1 �ȼ�
	IMAGEMANAGER->addImage("STAGE_stagePixel2", "Resource/IMG/stage/stage02_pixel.bmp", 2400, 864, true, RGB(255, 0, 255));
	//����2 �ȼ�
	IMAGEMANAGER->addImage("STAGE_stage1Pixel3", "Resource/IMG/stage/stage03_pixel.bmp", 2400, 865, true, RGB(255, 0, 255));
	//������ �ȼ�
	IMAGEMANAGER->addImage("STAGE_stagePixel4", "Resource/IMG/stage/stage04_pixel.bmp", 2112, 864, true, RGB(255, 0, 255));
	//������ �ȼ�
	IMAGEMANAGER->addImage("STAGE_normalPixel", "Resource/IMG/stage/normal_pixel.bmp", 2865, 837, true, RGB(255, 0, 255));

	//�׽�Ʈ
	//IMAGEMANAGER->addImage("STAGE_stage1", "Resource/IMG/stage/stage01.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addImage("STAGE_stagePixel1", "Resource/IMG/stage/stage01_pixel.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));

#pragma endregion STAGE

#pragma endregion IMAGESOURCES
	KEYANIMANAGER->addCoordinateFrameAnimation("loading", "SCENE_loadingSprite", 0, 3, 10, false, true);
	_background = IMAGEMANAGER->findImage("SCENE_loadingScene");
	_loading = IMAGEMANAGER->findImage("SCENE_loadingSprite");
	_load = KEYANIMANAGER->findAnimation("loading");

	CreateThread(
		NULL,				//������ ���ȼӼ�(�ڽ������� �����Ҷ�)
		NULL,				//�������� ����ũ��(0�̸� ���ξ����� ����)
		threadFunction,		//����� �Լ�
		this,				//������ �Ű�����(this �� ������ �� Ŭ����)
		NULL,				//������ Ư��
		NULL);				//������ ID

	return S_OK;
}

void imageStorage::release()
{
}

void imageStorage::update()
{
	_load->resume();
	if (_currentCount >= 300)
	{

		SCENEMANAGER->changeScene("stage1");
	}
//	KEYANIMANAGER->update();
}
void imageStorage::render()
{
	_background->render(getMemDC());
	_loading->aniRender(getMemDC(), WINSIZEX - 300, WINSIZEY - 300, _load);
	//KEYANIMANAGER->render();
}

void imageStorage::playerImage()
{
}

void imageStorage::npcImage()
{
}

void imageStorage::enemyImage()
{
}

void imageStorage::effectImage()
{
}

void imageStorage::objectImage()
{
}

//�ε� �̸� �̹��� �ٷε� ��������
DWORD CALLBACK threadFunction(LPVOID lpParameter)
{
	imageStorage* loadingHelper = (imageStorage*)lpParameter;

	//�������� �׳� ���⿡ ����Ͻ� �̹����� ���� �߰��� �ϸ�˴ϴ�


	while (loadingHelper->_currentCount != 300)
	{

		//�̷��� ���ϸ� ���� �������� �ʾƿ�
		Sleep(1);
	
		loadingHelper->_currentCount++;
	}
	return 0;
}
