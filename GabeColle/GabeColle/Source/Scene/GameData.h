#pragma once

struct GameData
{
	// �X�e�[�W�N���A�ɂ�����������(�t���[����)
	int time;
	// �G���[�̐�(segmentationFault_m+nullPtrAccess_m+outOfMemory_m+addressOutOfBounds_m)
	int numOfError;
	// �������I�u�W�F�N�g�̐�
	int numOfDeletedObject;
	// �����X�R�A(���Z�ɂ�time��numOfError��numOfDeletedObject���g��)
	int totalScore;
};
