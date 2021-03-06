#include "common_header.h"

// メイン処理
void MainProcess()
{
	///
	/// 設定
	///

	// 背景色
	int background_color[] = { 30, 30, 30 };

	// 文字色
	int font_color[] = { 230, 230, 230 };

	// 影色
	int shadow_color[] = { 5, 5, 5 };

	// フォントサイズ
	int font_size = 32;

	// 行の高さ
	double line_height = 1.73;

	// 影のオフセット
	int shadow_offset_x = 0;
	int shadow_offset_y = 2;

	// 表示テキスト
	char* text[] = { "あのイーハトーヴォの", "すきとおった風、", "夏でも底に冷たさをもつ青いそら、", "うつくしい森で飾られたモリーオ市、", "郊外のぎらぎらひかる草の波。" };

	// 配列の要素数を取得
	int text_length = sizeof(text) / sizeof(text[0]);

	// テキスト表示開始位置
	int text_x;
	int text_y;

	// 背景描画用画面
	int backscreen = MakeScreen(1024, 768, FALSE);



	///
	/// DXライブラリ用
	///

	// 背景色のセット
	SetBackgroundColor(background_color[0], background_color[1], background_color[2]);

	// 文字色を取得
	int font_color_dx = GetColor(font_color[0], font_color[1], font_color[2]);

	// 影色を取得
	int shadow_color_dx = GetColor(shadow_color[0], shadow_color[1], shadow_color[2]);

	// 表示するフォントファミリーセット
	ChangeFont("ＭＳ Ｐゴシック");

	// フォントサイズのセット
	SetFontSize(font_size);

	// フォントの表示方式をセット
	ChangeFontType(DX_FONTTYPE_ANTIALIASING_8X8);



	///
	/// 背景を描画
	///

	// 描画先を背景にセット
	SetDrawScreen(backscreen);

	// 背景を初期化
	ClearDrawScreen();

	// 影の表示開始位置
	text_x = font_size + shadow_offset_x;
	text_y = font_size + shadow_offset_y;

	// 影のベースとなる文字列を描画
	for (int row = 0; row < 5; row++)
	{
		DrawString(text_x, (int)(text_y + ((font_size * line_height) * row)), text[row], shadow_color_dx);
	}

	// ガウスフィルターを施して影にする
	GraphFilter(backscreen, DX_GRAPH_FILTER_GAUSS, 8, 50);



	///
	/// 前景を描画
	///

	// 描画対象を表画面にする
	SetDrawScreen(DX_SCREEN_FRONT);

	// 背景を描画
	DrawGraph(0, 0, backscreen, FALSE);

	// テキスト表示開始位置
	text_x = font_size;
	text_y = font_size;

	// 文字列の描画
	for (int row = 0; row < 5; row++)
	{
		DrawString(text_x, (int)(text_y + ((font_size * line_height) * row)), text[row], font_color_dx);
	}



	///
	/// 比較対象としてデフォルトの文字を描画
	///

	// フォントの表示方式をセット
	ChangeFontType(DX_FONTTYPE_NORMAL);

	// テキスト表示開始位置
	text_x = font_size;
	text_y = 350;

	// 文字列の描画
	for (int row = 0; row < 5; row++)
	{
		DrawString(text_x, (int)(text_y + ((font_size * line_height) * row)), text[row], font_color_dx);
	}



	///
	/// 終了処理
	///

	// 何らかのキー入力で終了
	WaitKey();

	return;
}
