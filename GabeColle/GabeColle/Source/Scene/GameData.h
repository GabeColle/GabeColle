#pragma once

struct GameData
{
	// �X�e�[�W���܂��̓X�e�[�W�̔ԍ�
	// �e�X�g�p�f�[�^�������Ă���
	String stageName = L"\0";
	// �X�e�[�W�N���A�ɂ�����������(�t���[����)
	// �e�X�g�p�f�[�^�������Ă���
	int time = 0;
	// �G���[�̐�(segmentationFault_m+nullPtrAccess_m+outOfMemory_m+addressOutOfBounds_m)
	// �e�X�g�p�f�[�^�������Ă���
	int numOfError = 0;
	// �������I�u�W�F�N�g�̐�
	// �e�X�g�p�f�[�^�������Ă���
	int numOfDeletedObject = 0;
	// �����X�R�A(���Z�ɂ�time��numOfError��numOfDeletedObject���g��)
	// �e�X�g�p�f�[�^�������Ă���
	int totalScore = 0;
};
