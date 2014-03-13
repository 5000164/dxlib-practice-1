#include "common_header.h"

// ���C������
void MainProcess()
{
	///
	/// �ݒ�
	///

	// �w�i�F
	int background_color[] = { 30, 30, 30 };

	// �����F
	int font_color[] = { 230, 230, 230 };

	// �e�F
	int shadow_color[] = { 5, 5, 5 };

	// �t�H���g�T�C�Y
	int font_size = 18;

	// �s�̍���
	double line_height = 1.73;

	// �e�̃I�t�Z�b�g
	int shadow_offset_x = 0;
	int shadow_offset_y = 2;

	// �\���e�L�X�g
	char* text[] = { "���̃C�[�n�g�[���H��", "�����Ƃ��������A", "�Ăł���ɗ₽������������A", "���������X�ŏ���ꂽ�����[�I�s�A", "�x�O�̂��炬��Ђ��鑐�̔g�B" };

	// �z��̗v�f�����擾
	int text_length = sizeof(text) / sizeof(text[0]);

	// �e�L�X�g�\���J�n�ʒu
	int text_x;
	int text_y;

	// �w�i�`��p���
	int backscreen = MakeScreen(1024, 768, FALSE);



	///
	/// DX���C�u�����p
	///

	// �w�i�F�̃Z�b�g
	SetBackgroundColor(background_color[0], background_color[1], background_color[2]);

	// �����F���擾
	int font_color_dx = GetColor(font_color[0], font_color[1], font_color[2]);

	// �e�F���擾
	int shadow_color_dx = GetColor(shadow_color[0], shadow_color[1], shadow_color[2]);

	// �\������t�H���g�t�@�~���[�Z�b�g
	ChangeFont("�l�r �o�S�V�b�N");

	// �t�H���g�T�C�Y�̃Z�b�g
	SetFontSize(font_size);

	// �t�H���g�̕\���������Z�b�g
	ChangeFontType(DX_FONTTYPE_ANTIALIASING_8X8);



	///
	/// �w�i��`��
	///

	// �`����w�i�ɃZ�b�g
	SetDrawScreen(backscreen);

	// �w�i��������
	ClearDrawScreen();

	// �e�̕\���J�n�ʒu
	text_x = font_size;
	text_y = font_size + 2;

	// �e�̃x�[�X�ƂȂ镶�����`��
	for (int row = 0; row < 5; row++)
	{
		DrawString(text_x, text_y + ((font_size * line_height) * row), text[row], shadow_color_dx);
	}

	// �K�E�X�t�B���^�[���{���ĉe�ɂ���
	GraphFilter(backscreen, DX_GRAPH_FILTER_GAUSS, 8, 50);



	///
	/// �O�i��`��
	///

	// �`��Ώۂ�\��ʂɂ���
	SetDrawScreen(DX_SCREEN_FRONT);

	// �w�i��`��
	DrawGraph(0, 0, backscreen, FALSE);

	// �e�L�X�g�\���J�n�ʒu
	text_x = font_size;
	text_y = font_size;

	// ������̕`��
	for (int row = 0; row < 5; row++)
	{
		DrawString(text_x, text_y + ((font_size * line_height) * row), text[row], font_color_dx);
	}



	///
	/// ��r�ΏۂƂ��ăf�t�H���g�̕�����`��
	///

	// �t�H���g�̕\���������Z�b�g
	ChangeFontType(DX_FONTTYPE_NORMAL);

	// �e�L�X�g�\���J�n�ʒu
	text_x = font_size;
	text_y = 200;

	// ������̕`��
	for (int row = 0; row < 5; row++)
	{
		DrawString(text_x, text_y + ((font_size * line_height) * row), text[row], font_color_dx);
	}



	///
	/// �I������
	///

	// ���炩�̃L�[���͂ŏI��
	WaitKey();

	return;
}
