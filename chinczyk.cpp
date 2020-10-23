#include <stdio.h>
#include <cstdio>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_primitives.h>
#include <string>
#include <time.h>
#include <windows.h>
#include "menu.h"

#define BACKGROUND_FILE "C:/Users/szymo/OneDrive/Pulpit/Pliki/Projekty/C++ & others/LudoGame/background.png"
#define PAWN_BLUE_FILE "C:/Users/szymo/OneDrive/Pulpit/Pliki/Projekty/C++ & others/LudoGame/pawn_blue.png"
#define PAWN_BLUE_SCAL_FILE "C:/Users/szymo/OneDrive/Pulpit/Pliki/Projekty/C++ & others/LudoGame/pawn_blue_scal.png"
#define PAWN_GREEN_FILE "C:/Users/szymo/OneDrive/Pulpit/Pliki/Projekty/C++ & others/LudoGame/pawn_green.png"
#define PAWN_RED_FILE "C:/Users/szymo/OneDrive/Pulpit/Pliki/Projekty/C++ & others/LudoGame/pawn_red.png"
#define PAWN_YELLOW_FILE "C:/Users/szymo/OneDrive/Pulpit/Pliki/Projekty/C++ & others/LudoGame/pawn_yellow.png"
#define BUTTON_ROLL "C:/Users/szymo/OneDrive/Pulpit/Pliki/Projekty/C++ & others/LudoGame/roll.png"
int si = -1;
int scal[4][4] = { 0 };
int x = 300;
int y = 200;
int POZYCJE[41][2] = { {534 + x, 25 + y}, {534 + x, 72 + y}, {534 + x, 119 + y}, {534 + x, 166 + y}, {534 + x, 213 + y}, {581 + x, 213 + y},
{628 + x, 213 + y}, {675 + x, 213 + y},{722 + x, 213 + y}, {722 + x, 260 + y}, {722 + x, 307 + y}, {675 + x, 307 + y}, {628 + x, 307 + y},
{581 + x, 307 + y}, {534 + x, 307 + y}, {534 + x, 354 + y}, {534 + x, 401 + y}, {534 + x, 448 + y},{534 + x, 495 + y}, {487 + x, 495 + y},
{440 + x, 495 + y}, {440 + x, 448 + y}, {440 + x, 401 + y}, {440 + x, 354 + y}, {440 + x, 307 + y}, {393 + x, 307 + y}, {346 + x, 307 + y},
{299 + x, 307 + y}, {252 + x, 307 + y}, {252 + x, 260 + y}, {252 + x, 213 + y}, {299 + x, 213 + y}, {346 + x, 213 + y}, {393 + x, 213 + y},
{440 + x, 213 + y}, {440 + x, 166 + y}, {440 + x, 119 + y}, {440 + x, 72 + y},  {440 + x, 25 + y}, {487 + x, 25 + y} };
int BASE_BLUE[4][2] = { {487 + x, 72 + y}, {487 + x, 119 + y}, {487 + x, 166 + y}, {487 + x, 213 + y} };
int BASE_YELLOW[4][2] = { {675 + x, 260 + y}, {628 + x, 260 + y}, {581 + x, 260 + y}, {534 + x, 260 + y} };
int BASE_RED[4][2] = { {487 + x, 448 + y}, {487 + x, 401 + y}, {487 + x, 354 + y}, {487 + x, 307 + y} };
int BASE_GREEN[4][2] = { {299 + x, 260 + y}, {346 + x, 260 + y}, {393 + x, 260 + y}, {440 + x, 260 + y} };
int LOBBY_BLUE[4][2] = { {628 + x, 72 + y}, {628 + x, 119 + y}, {675 + x, 72 + y}, {675 + x, 119 + y} };
int LOBBY_GREEN[4][2] = { {299 + x, 72 + y}, {299 + x, 119 + y}, {346 + x, 72 + y}, {346 + x, 119 + y} };
int LOBBY_RED[4][2] = { {299 + x, 401 + y}, {299 + x, 448 + y}, {346 + x, 401 + y}, {346 + x, 448 + y} };
int LOBBY_YELLOW[4][2] = { {628 + x, 401 + y}, {628 + x, 448 + y}, {675 + x, 401 + y}, {675 + x, 448 + y} };
int BUTTON_ROLL_POS[2] = { 160, 400 };
ALLEGRO_BITMAP* background = NULL;
ALLEGRO_BITMAP* button_roll = NULL;
ALLEGRO_BITMAP* tlo = NULL;

class Pionek {
public:
	int width = 30;
	int height = 30;
	int position;// -1 pozycja oznacza, ¿e jest w poczekalni, a -2, ¿e w domku
	int x, y;
	int start_x, start_y;
	std::string color = "";
	ALLEGRO_BITMAP* image = NULL;
	Pionek() {} //pusty konstruktor

	Pionek(int mX, int mY, int mPosition, std::string mColor) {
		x = mX;
		y = mY;
		start_x = mX;
		start_y = mY;
		position = mPosition;
		color = mColor;
	}
	void draw() {
		if (color == "blue") image = al_load_bitmap(PAWN_BLUE_FILE);
		if (color == "green") image = al_load_bitmap(PAWN_GREEN_FILE);
		if (color == "red") image = al_load_bitmap(PAWN_RED_FILE);
		if (color == "yellow") image = al_load_bitmap(PAWN_YELLOW_FILE);
		if (!image)
		{
			fprintf(stderr, "failed to load pawn bitmap!\n");
		}
		al_draw_bitmap(image, x, y, 0);
	}
	void skalowanko() {
		if (color == "blue") image = al_load_bitmap(PAWN_BLUE_SCAL_FILE);
		if (color == "green") image = al_load_bitmap(PAWN_GREEN_FILE);
		if (color == "red") image = al_load_bitmap(PAWN_RED_FILE);
		if (color == "yellow") image = al_load_bitmap(PAWN_YELLOW_FILE);
		al_draw_bitmap(image, x + 5, y + 5, 0);
		//al_draw_scaled_bitmap(image, x, y, 30, 30, x+3, y-3, 24, 24, 0);
	}
};
Pionek* tmp_positions[56];
Pionek red[4] = { Pionek(LOBBY_RED[0][0], LOBBY_RED[0][1], -1, "red"),
	Pionek(LOBBY_RED[1][0], LOBBY_RED[1][1], -1, "red"),
	Pionek(LOBBY_RED[2][0], LOBBY_RED[2][1], -1, "red"),
	Pionek(LOBBY_RED[3][0], LOBBY_RED[3][1], -1, "red"),
};

Pionek green[4] = { Pionek(LOBBY_GREEN[0][0], LOBBY_GREEN[0][1], -1, "green"),
	Pionek(LOBBY_GREEN[1][0], LOBBY_GREEN[1][1], -1, "green"),
	Pionek(LOBBY_GREEN[2][0], LOBBY_GREEN[2][1], -1, "green"),
	Pionek(LOBBY_GREEN[3][0], LOBBY_GREEN[3][1], -1, "green"),
};

Pionek blue[4] = { Pionek(LOBBY_BLUE[0][0], LOBBY_BLUE[0][1], -1, "blue"),
	Pionek(LOBBY_BLUE[1][0], LOBBY_BLUE[1][1], -1, "blue"),
	Pionek(LOBBY_BLUE[2][0], LOBBY_BLUE[2][1], -1, "blue"),
	Pionek(LOBBY_BLUE[3][0], LOBBY_BLUE[3][1], -1, "blue"),
};
Pionek yellow[4] = { Pionek(LOBBY_YELLOW[0][0], LOBBY_YELLOW[0][1], -1, "yellow"),
	Pionek(LOBBY_YELLOW[1][0], LOBBY_YELLOW[1][1], -1, "yellow"),
	Pionek(LOBBY_YELLOW[2][0], LOBBY_YELLOW[2][1], -1, "yellow"),
	Pionek(LOBBY_YELLOW[3][0], LOBBY_YELLOW[3][1], -1, "yellow"),
};

bool czyJestWPoczekalni(Pionek* player);
int losulosu();
void odswiezWidok();
void przesunPionek(Pionek* player, bool mode, int roll);
bool powinienSiePrzesunac(Pionek* player, int pos, int nr);
bool powinienSiePrzesunacDoDomu(Pionek* player, int pos, int roll, int base_pos);

Player* pl1 = NULL;	Player* pl2 = NULL;	Player* pl3 = NULL;	Player* pl4 = NULL;

int main(void) {
	ALLEGRO_DISPLAY* display = NULL;
	if (!al_init()) return 1;
	al_init_image_addon();
	display = al_create_display(1600, 900);
	if (!display)return -1;

	al_clear_to_color(al_map_rgb(0, 0, 0));
	al_install_keyboard();
	al_install_mouse();
	al_init_font_addon();
	al_init_ttf_addon();
	if (!al_install_audio()) { return 2; }
	if (!al_init_acodec_addon()) { return 3; }
	if (!al_reserve_samples(1)) { return 4; }

	//wybór motywu
	int chosen_theme = choose_theme();
	ALLEGRO_MOUSE_STATE state;
	al_get_mouse_state(&state);
	if (chosen_theme == 1) {
		ALLEGRO_SAMPLE* motyw_t = al_load_sample("C:/Users/szymo/OneDrive/Pulpit/Pliki/Projekty/C++ & others/LudoGame/rick-and-morty-evil-morty-theme-song-feewet-trap-remix.mp3");
		ALLEGRO_SAMPLE_INSTANCE* instance = al_create_sample_instance(motyw_t);
		if (!motyw_t || !instance) {
			printf("Setup error.\n");
			return 5;
		}
		ALLEGRO_SAMPLE_ID sample_id;
		if (!al_play_sample(motyw_t, 0.5, 0.0, 1.0, ALLEGRO_PLAYMODE_LOOP, &sample_id)) printf("Failed to play sample.\n");
		if (!al_play_sample_instance(instance)) printf("Failed to play sample instance.\n");
	}
	else if (chosen_theme == 2) {
		ALLEGRO_SAMPLE* motyw_t = al_load_sample("C:/Users/szymo/OneDrive/Pulpit/Pliki/Projekty/C++ & others/LudoGame/the-misty-mountains-cold-the-hobbit.mp3");
		ALLEGRO_SAMPLE_INSTANCE* instance = al_create_sample_instance(motyw_t);
		if (!motyw_t || !instance) {
			printf("Setup error.\n");
			return 5;
		}
		ALLEGRO_SAMPLE_ID sample_id;
		if (!al_play_sample(motyw_t, 0.5, 0.0, 1.0, ALLEGRO_PLAYMODE_LOOP, &sample_id)) printf("Failed to play sample.\n");
		if (!al_play_sample_instance(instance)) printf("Failed to play sample instance.\n");
	}
	else {
		ALLEGRO_SAMPLE* motyw_t = al_load_sample("C:/Users/szymo/OneDrive/Pulpit/Pliki/Projekty/C++ & others/LudoGame/the-witcher-3-wild-hunt-ost-sword-of-destiny-main-theme.mp3");
		ALLEGRO_SAMPLE_INSTANCE* instance = al_create_sample_instance(motyw_t);
		if (!motyw_t || !instance) {
			printf("Setup error.\n");
			return 5;
		}
		ALLEGRO_SAMPLE_ID sample_id;
		if (!al_play_sample(motyw_t, 0.5, 0.0, 1.0, ALLEGRO_PLAYMODE_LOOP, &sample_id)) printf("Failed to play sample.\n");
		if (!al_play_sample_instance(instance)) printf("Failed to play sample instance.\n");
	}

	//za³adowanie background
	refresh(chosen_theme);
	//wybranie iloœci graczy
	int n_players = choose_players(chosen_theme);
	if (n_players == 2) {
		Player player1, player2;
		pl1 = &player1;		 pl2 = &player2;
		chose_avatar(chosen_theme, pl1);	write_nick(chosen_theme, pl1);
		chose_avatar(chosen_theme, pl2);	write_nick(chosen_theme, pl2);
	}
	else if (n_players == 3) {
		Player player1, player2, player3;
		pl1 = &player1;		pl2 = &player2;		pl3 = &player3;
		chose_avatar(chosen_theme, pl1);	write_nick(chosen_theme, pl1);
		chose_avatar(chosen_theme, pl2);	write_nick(chosen_theme, pl2);
		chose_avatar(chosen_theme, pl3);	write_nick(chosen_theme, pl3);
	}
	else {
		Player player1, player2, player3, player4;
		pl1 = &player1;		pl2 = &player2;	pl3 = &player3;		pl4 = &player4;
		chose_avatar(chosen_theme, pl1);	write_nick(chosen_theme, pl1);
		chose_avatar(chosen_theme, pl2);	write_nick(chosen_theme, pl2);
		chose_avatar(chosen_theme, pl3);	write_nick(chosen_theme, pl3);
		chose_avatar(chosen_theme, pl4);	write_nick(chosen_theme, pl4);

	}

	refresh(chosen_theme);
	draw_avatars(pl1, pl2, pl3, pl4, n_players);
	al_rest(0.01);

	background = al_load_bitmap(BACKGROUND_FILE);
	if (!background)return -1;
	tlo = al_load_bitmap("C:/Users/szymo/OneDrive/Pulpit/Pliki/Projekty/C++ & others/LudoGame/tlo.png");

	for (int i = 0; i < 56; i++) {
		tmp_positions[i] = new Pionek(); //tmp_positions - tymczasowa pozycja
	}
	srand(time(NULL));
	int turn = 0;

	if (!display)return -1;
	background = al_load_bitmap(BACKGROUND_FILE);
	if (!background)return -1;
	button_roll = al_load_bitmap(BUTTON_ROLL);
	al_install_mouse();
	odswiezWidok();

	while (1) {
		//inicjalizacja
		Pionek* current_player;
		bool mode;
		int rolled;
		switch (n_players)
		{
		case 2:
			current_player = new Pionek();
			mode = true; //Czy wszystkie pionki gracza s¹ w lobby - true
			if (turn == 0) {
				current_player = blue;
				print_who_now(0, pl1);
			}
			else {
				current_player = yellow;
				print_who_now(1, pl2);
			}

			mode = czyJestWPoczekalni(current_player);
			rolled = losulosu();
			przesunPionek(current_player, mode, rolled);
			al_rest(0.01);
			odswiezWidok();
			if (rolled != 6) {
				turn++;
				if (turn > 1) turn = 0;
			}
			break;

		case 3:
			current_player = new Pionek();
			mode = true; //Czy wszystkie pionki gracza s¹ w lobby - true
			if (turn == 0) {
				current_player = blue;
				print_who_now(0, pl1);
			}
			else if (turn == 1) {
				current_player = yellow;
				print_who_now(1, pl2);
			}
			else {
				current_player = red;
				print_who_now(2, pl3);
			}

			mode = czyJestWPoczekalni(current_player);
			rolled = losulosu();
			przesunPionek(current_player, mode, rolled);
			al_rest(0.01);
			odswiezWidok();
			if (rolled != 6) {
				turn++;
				if (turn > 2) turn = 0;
			}
			break;

		case 4:
			current_player = new Pionek();
			mode = true; //Czy wszystkie pionki gracza s¹ w lobby - true
			if (turn == 0) {
				current_player = blue;
				print_who_now(0, pl1);
			}
			else if (turn == 1) {
				current_player = yellow;
				print_who_now(1, pl2);
			}
			else if (turn == 2) {
				current_player = red;
				print_who_now(2, pl3);
			}
			else {
				current_player = green;
				print_who_now(3, pl4);
			}

			mode = czyJestWPoczekalni(current_player);
			rolled = losulosu();
			przesunPionek(current_player, mode, rolled);
			al_rest(0.01);
			odswiezWidok();
			if (rolled != 6) {
				turn++;
				if (turn > 3) turn = 0;
			}
			break;
		}
	}
	//al_destroy_sample_instance(instance);
	//al_destroy_sample(motyw_t);
	al_destroy_display(display);
	al_destroy_bitmap(background);
	al_uninstall_system();
	return 0;
}

void odswiezWidok() {
	al_draw_bitmap(background, 200 + x, y, 0);
	al_draw_bitmap(button_roll, BUTTON_ROLL_POS[0], BUTTON_ROLL_POS[1], 0);
	al_draw_bitmap(button_roll, BUTTON_ROLL_POS[0] + 1100, BUTTON_ROLL_POS[1], 0);
	al_draw_bitmap(tlo, 650, 50, 0);
	for (int i = 0; i < 4; i++) {
		if (scal[0][i] == 1)red[i].skalowanko();
		else red[i].draw();
		if (scal[1][i] == 1)green[i].skalowanko();
		else green[i].draw();
		if (scal[2][i] == 1)blue[i].skalowanko();
		else blue[i].draw();
		if (scal[3][i] == 1)yellow[i].skalowanko();
		else yellow[i].draw();
	}
	al_flip_display();
}

bool czyJestWPoczekalni(Pionek* player) {
	bool result = true;
	for (int i = 0; i < 4; i++) {
		if (player[i].position != -1)return false;
	}
	return result;
}

void przesunPionek(Pionek player[], bool mode, int roll) {
	ALLEGRO_MOUSE_STATE state;
	Pionek* pawn = NULL;
	int check_1 = 0;
	int check_2 = 0;
	bool done = false;
	if (mode && roll != 6) return;
	for (int i = 0; i < 4; i++) {
		if (player[i].position == -1)check_1++;
		if (player[i].position == -2)check_2++;
	}
	if ((check_1 == 3 && check_2 == 1 && roll != 6) || (check_1 == 2 && check_2 == 2 && roll != 6) || (check_1 == 1 && check_2 == 3 && roll != 6))return;
	//printf("\nWybierz pionek do przesuniecia");

	while (!done) {
		al_get_mouse_state(&state);
		if (state.buttons & 1) {
			for (int i = 0; i < 4; i++) {
				if ((state.x >= player[i].x && state.x <= player[i].x + player[i].width) &&
					(state.y >= player[i].y && state.y <= player[i].y + player[i].height)) {
					if (player[i].position == -2) continue;
					else if (player[i].position == -1 && roll == 6)  //sprawdza czy moze sie przesunac
					{
						if (player[i].color == "blue") {
							if (powinienSiePrzesunac(&player[i], 0, i)) continue;
						}
						else if (player[i].color == "yellow") {
							if (powinienSiePrzesunac(&player[i], 10, i)) continue;
						}
						else if (player[i].color == "red") {
							if (powinienSiePrzesunac(&player[i], 20, i)) continue;
						}
						else if (player[i].color == "green") {
							if (powinienSiePrzesunac(&player[i], 30, i)) continue;
						}
						if (player[i].position != -1) //zmiana pozycji pionka
						{
							player[i].x = POZYCJE[player[i].position][0];
							player[i].y = POZYCJE[player[i].position][1];
							done = true;
						}
					}
					else if (player[i].position != -1) // sprawdza co sie dzieje kiedy pionek nie jest w poczekalni
					{
						int next = 0;
						if (player[i].color == "blue" && player[i].position + roll >= 40) {
							if (powinienSiePrzesunacDoDomu(&player[i], 39, roll, 0))return;
							else continue;
						}
						else if (player[i].color == "yellow" && player[i].position + roll >= 10 && player[i].position <= 9) {
							if (powinienSiePrzesunacDoDomu(&player[i], 9, roll, 4)) return;
							else continue;
						}
						else if (player[i].color == "red" && player[i].position + roll >= 20 && player[i].position <= 19) {
							if (powinienSiePrzesunacDoDomu(&player[i], 19, roll, 8)) return;
							else continue;
						}
						else if (player[i].color == "green" && player[i].position + roll >= 30 && player[i].position <= 29) {
							if (powinienSiePrzesunacDoDomu(&player[i], 29, roll, 12)) return;
							else continue;
						}
						if (player[i].position + roll >= 40) {
							roll = roll - (40 - player[i].position);
							next = 0 + roll;
						}
						else {
							next = player[i].position + roll;
						}
						if (powinienSiePrzesunac(&player[i], next, i)) continue;
						if (player[i].position == next) //teleportacja
						{
							player[i].x = POZYCJE[next][0];
							player[i].y = POZYCJE[next][1];
							if (player[i].x == POZYCJE[2][0] && player[i].y == POZYCJE[2][1]) {
								player[i].x = POZYCJE[5][0];
								player[i].y = POZYCJE[5][1];
								player[i].position += 3;
							}
							else if (player[i].x == POZYCJE[12][0] && player[i].y == POZYCJE[12][1]) {
								player[i].x = POZYCJE[15][0];
								player[i].y = POZYCJE[15][1];
								player[i].position += 3;
							}
							else if (player[i].x == POZYCJE[22][0] && player[i].y == POZYCJE[22][1]) {
								player[i].x = POZYCJE[25][0];
								player[i].y = POZYCJE[25][1];
								player[i].position += 3;
							}
							else if (player[i].x == POZYCJE[32][0] && player[i].y == POZYCJE[32][1]) {
								player[i].x = POZYCJE[35][0];
								player[i].y = POZYCJE[35][1];
								player[i].position += 3;
							}
						}
						done = true;
					}
					else continue;
				}
			}
		}
		al_rest(0.01);
	}
}

bool powinienSiePrzesunac(Pionek* player, int pos, int nr) {
	if (tmp_positions[pos]->x == NULL) {
		if (player->position != -1)tmp_positions[player->position] = new Pionek();
		player->position = pos;
		tmp_positions[pos] = player;
	}
	else if (tmp_positions[pos]->color == player->color) {
		if (player->color == "red")si = 0;
		if (player->color == "green")si = 1;
		if (player->color == "blue")si = 2;
		if (player->color == "yellow")si = 3;
		scal[si][nr] = 1;
		tmp_positions[player->position] = new Pionek();
		player->position = pos;
		tmp_positions[pos] = player;
		si = -1;
		//return true;
	}
	else {
		tmp_positions[pos]->x = tmp_positions[pos]->start_x;
		tmp_positions[pos]->y = tmp_positions[pos]->start_y;
		tmp_positions[pos]->position = -1;
		if (player->position != -1)tmp_positions[player->position] = new Pionek();
		player->position = pos;
		tmp_positions[pos] = player;
	}
	return false;
}

bool powinienSiePrzesunacDoDomu(Pionek* player, int pos, int roll, int base_pos) {
	int i = roll + player->position;
	if (i > pos + 4) i = pos + 4;
	for (; i >= pos; i--) {
		if (tmp_positions[(40 + base_pos) + (i - pos - 1)]->x == NULL) {
			if (player->color == "blue") {
				player->x = BASE_BLUE[i - pos - 1][0];
				player->y = BASE_BLUE[i - pos - 1][1];
				tmp_positions[40 + (i - pos - 1)] = player;
			}
			else if (player->color == "yellow") {
				player->x = BASE_YELLOW[i - pos - 1][0];
				player->y = BASE_YELLOW[i - pos - 1][1];
				tmp_positions[44 + (i - pos - 1)] = player;
			}
			else if (player->color == "red") {
				player->x = BASE_RED[i - pos - 1][0];
				player->y = BASE_RED[i - pos - 1][1];
				tmp_positions[48 + (i - pos - 1)] = player;
			}
			else {
				player->x = BASE_GREEN[i - pos - 1][0];
				player->y = BASE_GREEN[i - pos - 1][1];
				tmp_positions[52 + (i - pos - 1)] = player;
			}

			player->position = -2;
			return true;
		}
	}
	return false;
}

int losulosu() {
	//printf("\n enter rolling");
	ALLEGRO_MOUSE_STATE state;
	bool done = false;
	while (!done) {
		al_get_mouse_state(&state);
		if (state.buttons & 1) {
			//printf("Mouse position: (%d, %d)\n", state.x, state.y);
			if ((state.x >= BUTTON_ROLL_POS[0] && state.x <= BUTTON_ROLL_POS[0] + 180) &&
				(state.y >= BUTTON_ROLL_POS[1] && state.y <= BUTTON_ROLL_POS[1] + 90)) {
				int rolled = rand() % 6 + 1;
				print_rolled(rolled);
				Sleep(500);
				//printf("rolled: %d\n", rolled);
				return rolled;
			}
			else if ((state.x >= BUTTON_ROLL_POS[0] + 1100 && state.x <= BUTTON_ROLL_POS[0] + 1280) &&
				(state.y >= BUTTON_ROLL_POS[1] && state.y <= BUTTON_ROLL_POS[1] + 90)) {
				int rolled = rand() % 6 + 1;
				print_rolled(rolled);
				Sleep(500);
				//printf("rolled: %d\n", rolled);
				return rolled;
			}
		}
		al_rest(0.01);
	}
	return 0;
}