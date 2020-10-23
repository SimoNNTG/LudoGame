#include <stdio.h>
#include <iostream>
#include <string>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
//#include <allegro5/allegro_audio.h>
//#include <allegro5/allegro_acodec.h>
#include <allegro5/events.h>
#include "menu.h"

using namespace std;
#define WHITE al_map_rgb(255, 255, 255)
#define BLACK al_map_rgb(0, 0, 0)


int menu() {
	//ALLEGRO_COLOR back_color = al_map_rgb(106, 90, 205);

#define back_color al_map_rgb(230, 230, 25)

	ALLEGRO_DISPLAY* display = NULL;
	if (!al_init()) return -1;
	al_init_image_addon();
	display = al_create_display(1600, 900);
	if (!display)return -1;
	//	background = al_load_bitmap(BACKGROUND_FILE);
	//	if (!background)return -1;

	al_clear_to_color(al_map_rgb(0, 0, 0));
	al_install_keyboard();
	al_install_mouse();
	al_init_font_addon();
	al_init_ttf_addon();

	//wybór motywu
	int chosen_theme = choose_theme();
	//za³adowanie background
	refresh(chosen_theme);
	//wybranie iloœci graczy
	int n_players = choose_players(chosen_theme);
	if (n_players == 2) {
		Player player1, player2;
		Player* pl1 = &player1;		Player* pl2 = &player2;
		chose_avatar(chosen_theme, pl1);	write_nick(chosen_theme, pl1);
		chose_avatar(chosen_theme, pl2);	write_nick(chosen_theme, pl2);
	}
	else if (n_players == 3) {
		Player player1, player2, player3;
		Player* pl1 = &player1;		Player* pl2 = &player2;		Player* pl3 = &player3;
		chose_avatar(chosen_theme, pl1);	write_nick(chosen_theme, pl1);
		chose_avatar(chosen_theme, pl2);	write_nick(chosen_theme, pl2);
		chose_avatar(chosen_theme, pl3);	write_nick(chosen_theme, pl3);
	}
	else {
		Player player1, player2, player3, player4;
		Player* pl1 = &player1;		Player* pl2 = &player2;
		Player* pl3 = &player3;		Player* pl4 = &player4;
		chose_avatar(chosen_theme, pl1);	write_nick(chosen_theme, pl1);
		chose_avatar(chosen_theme, pl2);	write_nick(chosen_theme, pl2);
		chose_avatar(chosen_theme, pl3);	write_nick(chosen_theme, pl3);
		chose_avatar(chosen_theme, pl4);	write_nick(chosen_theme, pl4);

	}

	refresh(chosen_theme);
	al_rest(0.01);

	return n_players;
}


int chose_avatar(int chosen_theme, Player* obj) {
	refresh(chosen_theme);
	ALLEGRO_FONT* font_menu = al_load_ttf_font("C:/Users/szymo/OneDrive/Pulpit/Pliki/Projekty/C++ & others/LudoGame/TYPEWR__.ttf", 50, 0);
	int av1_position[2] = { 50, 400 };
	int av2_postion[2] = { 450, 400 };
	int av3_position[2] = { 850, 400 };
	int av4_position[2] = { 1250, 400 };
	int x = 300;
	int y = 400;
	ALLEGRO_BITMAP* av1 = NULL;
	ALLEGRO_BITMAP* av2 = NULL;
	ALLEGRO_BITMAP* av3 = NULL;
	ALLEGRO_BITMAP* av4 = NULL;
	ALLEGRO_BITMAP* av11 = NULL;
	ALLEGRO_BITMAP* av12 = NULL;
	ALLEGRO_BITMAP* av13 = NULL;
	ALLEGRO_BITMAP* av14 = NULL;

	if (chosen_theme == 1) {
		av1 = al_load_bitmap("C:/Users/szymo/OneDrive/Pulpit/Pliki/Projekty/C++ & others/LudoGame/Rick.jpg");
		av2 = al_load_bitmap("C:/Users/szymo/OneDrive/Pulpit/Pliki/Projekty/C++ & others/LudoGame/Morty.jpg");
		av3 = al_load_bitmap("C:/Users/szymo/OneDrive/Pulpit/Pliki/Projekty/C++ & others/LudoGame/Summer.jpg");
		av4 = al_load_bitmap("C:/Users/szymo/OneDrive/Pulpit/Pliki/Projekty/C++ & others/LudoGame/Pan_Kupkazpupki.jpg");

		av11 = al_load_bitmap("C:/Users/szymo/OneDrive/Pulpit/Pliki/Projekty/C++ & others/LudoGame/Rick2.jpg");
		av12 = al_load_bitmap("C:/Users/szymo/OneDrive/Pulpit/Pliki/Projekty/C++ & others/LudoGame/Morty2.jpg");
		av13 = al_load_bitmap("C:/Users/szymo/OneDrive/Pulpit/Pliki/Projekty/C++ & others/LudoGame/Summer2.jpg");
		av14 = al_load_bitmap("C:/Users/szymo/OneDrive/Pulpit/Pliki/Projekty/C++ & others/LudoGame/Pan_Kupkazpupki2.jpg");

		char wybierz[50] = "WYBIERZ AVATARA";
		al_draw_text(font_menu, WHITE, 800, 300, ALLEGRO_ALIGN_CENTRE, wybierz);
		al_draw_bitmap(av1, av1_position[0], av1_position[1], 0);
		al_draw_bitmap(av2, av2_postion[0], av2_postion[1], 0);
		al_draw_bitmap(av3, av3_position[0], av3_position[1], 0);
		al_draw_bitmap(av4, av4_position[0], av4_position[1], 0);

		al_flip_display();
		al_rest(0.01);
	}
	else if (chosen_theme == 2) {
		av1 = al_load_bitmap("C:/Users/szymo/OneDrive/Pulpit/Pliki/Projekty/C++ & others/LudoGame/Frodo.jpeg");
		av2 = al_load_bitmap("C:/Users/szymo/OneDrive/Pulpit/Pliki/Projekty/C++ & others/LudoGame/Legolas.jpeg");
		av3 = al_load_bitmap("C:/Users/szymo/OneDrive/Pulpit/Pliki/Projekty/C++ & others/LudoGame/Gollum.jpeg");
		av4 = al_load_bitmap("C:/Users/szymo/OneDrive/Pulpit/Pliki/Projekty/C++ & others/LudoGame/Gandalf.jpeg");

		av11 = al_load_bitmap("C:/Users/szymo/OneDrive/Pulpit/Pliki/Projekty/C++ & others/LudoGame/Frodo2.jpeg");
		av12 = al_load_bitmap("C:/Users/szymo/OneDrive/Pulpit/Pliki/Projekty/C++ & others/LudoGame/Legolas2.jpeg");
		av13 = al_load_bitmap("C:/Users/szymo/OneDrive/Pulpit/Pliki/Projekty/C++ & others/LudoGame/Gollum2.jpeg");
		av14 = al_load_bitmap("C:/Users/szymo/OneDrive/Pulpit/Pliki/Projekty/C++ & others/LudoGame/Gandalf2.jpeg");

		char wybierz[50] = "WYBIERZ AVATARA";
		al_draw_text(font_menu, BLACK, 800, 75, ALLEGRO_ALIGN_CENTRE, wybierz);
		al_draw_bitmap(av1, av1_position[0], av1_position[1], 0);
		al_draw_bitmap(av2, av2_postion[0], av2_postion[1], 0);
		al_draw_bitmap(av3, av3_position[0], av3_position[1], 0);
		al_draw_bitmap(av4, av4_position[0], av4_position[1], 0);

		al_flip_display();
		al_rest(0.01);
	}
	else if (chosen_theme == 3) {
		av1 = al_load_bitmap("C:/Users/szymo/OneDrive/Pulpit/Pliki/Projekty/C++ & others/LudoGame/Geralt.jpeg");
		av2 = al_load_bitmap("C:/Users/szymo/OneDrive/Pulpit/Pliki/Projekty/C++ & others/LudoGame/Yen.jpeg");
		av3 = al_load_bitmap("C:/Users/szymo/OneDrive/Pulpit/Pliki/Projekty/C++ & others/LudoGame/Jaskier.jpeg");
		av4 = al_load_bitmap("C:/Users/szymo/OneDrive/Pulpit/Pliki/Projekty/C++ & others/LudoGame/Ciri.jpeg");

		av11 = al_load_bitmap("C:/Users/szymo/OneDrive/Pulpit/Pliki/Projekty/C++ & others/LudoGame/Geralt2.jpeg");
		av12 = al_load_bitmap("C:/Users/szymo/OneDrive/Pulpit/Pliki/Projekty/C++ & others/LudoGame/Yen2.jpeg");
		av13 = al_load_bitmap("C:/Users/szymo/OneDrive/Pulpit/Pliki/Projekty/C++ & others/LudoGame/Jaskier2.jpeg");
		av14 = al_load_bitmap("C:/Users/szymo/OneDrive/Pulpit/Pliki/Projekty/C++ & others/LudoGame/Ciri2.jpeg");

		char wybierz[50] = "WYBIERZ AVATARA";
		al_draw_text(font_menu, BLACK, 800, 75, ALLEGRO_ALIGN_CENTRE, wybierz);
		al_draw_bitmap(av1, av1_position[0], av1_position[1], 0);
		al_draw_bitmap(av2, av2_postion[0], av2_postion[1], 0);
		al_draw_bitmap(av3, av3_position[0], av3_position[1], 0);
		al_draw_bitmap(av4, av4_position[0], av4_position[1], 0);

		al_flip_display();
		al_rest(0.01);
	}

	ALLEGRO_MOUSE_STATE state;
	bool done = false;
	while (!done) {
		al_get_mouse_state(&state);
		if (state.buttons & 1) {
			//printf("Mouse position: (%d, %d)\n", state.x, state.y);
			if ((state.x >= av1_position[0] && state.x <= av1_position[0] + 300) &&
				(state.y >= av1_position[1] && state.y <= av1_position[1] + 400)) {
				obj->avatar1 = av11;
				obj->avatar = av1;
				al_destroy_bitmap(av2);
				al_destroy_bitmap(av3);
				al_destroy_bitmap(av4);
				return 1;

			}
			else if ((state.x >= av2_postion[0] && state.x <= av2_postion[0] + 300) &&
				(state.y >= av2_postion[1] && state.y <= av2_postion[1] + 400)) {
				obj->avatar1 = av12;
				obj->avatar = av2;
				al_destroy_bitmap(av1);
				al_destroy_bitmap(av3);
				al_destroy_bitmap(av4);
				return 1;
			}
			else if ((state.x >= av3_position[0] && state.x <= av3_position[0] + 300) &&
				(state.y >= av3_position[1] && state.y <= av3_position[1] + 400)) {
				obj->avatar1 = av13;
				obj->avatar = av3;
				al_destroy_bitmap(av1);
				al_destroy_bitmap(av2);
				al_destroy_bitmap(av4);
				return 1;
			}
			else if ((state.x >= av4_position[0] && state.x <= av4_position[0] + 300) &&
				(state.y >= av4_position[1] && state.y <= av4_position[1] + 400)) {
				obj->avatar1 = av14;
				obj->avatar = av4;
				al_destroy_bitmap(av1);
				al_destroy_bitmap(av2);
				al_destroy_bitmap(av3);
				return 1;
			}
			al_rest(0.01);
		}

	}
	return 0;
}

int write_nick(int chosen_theme, Player* obj) {
	refresh(chosen_theme);
	ALLEGRO_FONT* font_avatar = al_load_ttf_font("C:/Users/szymo/OneDrive/Pulpit/Pliki/Projekty/C++ & others/LudoGame/TYPEWR__.ttf", 24, 0);
	ALLEGRO_FONT* font_menu = al_load_ttf_font("C:/Users/szymo/OneDrive/Pulpit/Pliki/Projekty/C++ & others/LudoGame/TYPEWR__.ttf", 50, 0);
	char napis[50] = "WPISZ SWOJ NICK";
	if (chosen_theme == 1) {
		al_draw_text(font_menu, WHITE, 800, 75, ALLEGRO_ALIGN_CENTRE, napis);
	}
	else al_draw_text(font_menu, BLACK, 800, 75, ALLEGRO_ALIGN_CENTRE, napis);
	ALLEGRO_BITMAP* av = obj->avatar;
	al_draw_bitmap(av, 650, 200, 0);
	ALLEGRO_BITMAP* white = al_load_bitmap("C:/Users/szymo/OneDrive/Pulpit/Pliki/Projekty/C++ & others/LudoGame/white_rectangular.jpg");
	al_draw_bitmap(white, 600, 650, 0);
	al_flip_display();

	ALLEGRO_KEYBOARD_STATE keystate;
	ALLEGRO_EVENT_QUEUE* event_queue = al_create_event_queue();
	al_register_event_source(event_queue, al_get_keyboard_event_source());

	bool done = false;
	char nick[20];
	int i = 0;

	while (!done && i < 19) {
		ALLEGRO_EVENT event;
		al_wait_for_event(event_queue, &event);
		if (event.type == ALLEGRO_EVENT_KEY_DOWN) {
			switch (event.keyboard.keycode)
			{
			case ALLEGRO_KEY_A:
				nick[i] = 'a'; i++;
				break;
			case ALLEGRO_KEY_B:
				nick[i] = 'b'; i++;
				break;
			case ALLEGRO_KEY_C:
				nick[i] = 'c'; i++;
				break;
			case ALLEGRO_KEY_D:
				nick[i] = 'd'; i++;
				break;
			case ALLEGRO_KEY_E:
				nick[i] = 'e'; i++;
				break;
			case ALLEGRO_KEY_F:
				nick[i] = 'f'; i++;
				break;
			case ALLEGRO_KEY_G:
				nick[i] = 'g'; i++;
				break;
			case ALLEGRO_KEY_H:
				nick[i] = 'h'; i++;
				break;
			case ALLEGRO_KEY_I:
				nick[i] = 'i'; i++;
				break;
			case ALLEGRO_KEY_J:
				nick[i] = 'j'; i++;
				break;
			case ALLEGRO_KEY_K:
				nick[i] = 'k'; i++;
				break;
			case ALLEGRO_KEY_L:
				nick[i] = 'l'; i++;
				break;
			case ALLEGRO_KEY_M:
				nick[i] = 'm'; i++;
				break;
			case ALLEGRO_KEY_N:
				nick[i] = 'n'; i++;
				break;
			case ALLEGRO_KEY_O:
				nick[i] = 'o'; i++;
				break;
			case ALLEGRO_KEY_P:
				nick[i] = 'p'; i++;
				break;
			case ALLEGRO_KEY_Q:
				nick[i] = 'q'; i++;
				break;
			case ALLEGRO_KEY_R:
				nick[i] = 'r'; i++;
				break;
			case ALLEGRO_KEY_S:
				nick[i] = 's'; i++;
				break;
			case ALLEGRO_KEY_T:
				nick[i] = 't'; i++;
				break;
			case ALLEGRO_KEY_U:
				nick[i] = 'u'; i++;
				break;
			case ALLEGRO_KEY_V:
				nick[i] = 'v'; i++;
				break;
			case ALLEGRO_KEY_W:
				nick[i] = 'w'; i++;
				break;
			case ALLEGRO_KEY_X:
				nick[i] = 'x'; i++;
				break;
			case ALLEGRO_KEY_Y:
				nick[i] = 'y'; i++;
				break;
			case ALLEGRO_KEY_Z:
				nick[i] = 'z'; i++;
				break;
			case ALLEGRO_KEY_BACKSPACE:
				i--;  nick[i] = '\000';
				break;
			case ALLEGRO_KEY_ESCAPE:
				done = true;
				break;
			case ALLEGRO_KEY_ENTER:
				done = true;
				break;
			}

			al_draw_bitmap(white, 600, 650, 0);
			al_draw_text(font_avatar, BLACK, 620, 660, ALLEGRO_ALIGN_LEFT, nick);
			al_flip_display();
			al_rest(0.01);
		}
	}

	al_flip_display();
	al_destroy_event_queue(event_queue);
	for (int i = 0; i < 20; i++) {
		if (nick[i] != '\0') {
			obj->nick[i] = nick[i];
		}
		else break;
	}

	al_rest(0.01);
	return 0;
}

void refresh(int chosen_theme) {
#define rick_morty_b "C:/Users/szymo/OneDrive/Pulpit/Pliki/Projekty/C++ & others/LudoGame/rick_back2.jpg"
#define witcher_b "C:/Users/szymo/OneDrive/Pulpit/Pliki/Projekty/C++ & others/LudoGame/witcher_back2.jpg"
#define lord_rings_b "C:/Users/szymo/OneDrive/Pulpit/Pliki/Projekty/C++ & others/LudoGame/lord_back2.jpg"

	ALLEGRO_BITMAP* rick_b = NULL;
	ALLEGRO_BITMAP* witch_b = NULL;
	ALLEGRO_BITMAP* lord_b = NULL;

	rick_b = al_load_bitmap(rick_morty_b);
	witch_b = al_load_bitmap(witcher_b);
	lord_b = al_load_bitmap(lord_rings_b);
	switch (chosen_theme) {
	case 1:
		al_draw_bitmap(rick_b, 0, 0, 0);
		break;
	case 2:
		al_draw_bitmap(lord_b, 0, 0, 0);
		break;
	case 3:
		al_draw_bitmap(witch_b, 0, 0, 0);
		break;
	default: break;
	}
	al_flip_display();
}

int choose_players(int chosen_theme) {

#define B2 "C:/Users/szymo/OneDrive/Pulpit/Pliki/Projekty/C++ & others/LudoGame/button_2.png"
#define B3 "C:/Users/szymo/OneDrive/Pulpit/Pliki/Projekty/C++ & others/LudoGame/button_3.png"
#define B4 "C:/Users/szymo/OneDrive/Pulpit/Pliki/Projekty/C++ & others/LudoGame/button_4.png"

	ALLEGRO_BITMAP* b2 = NULL;
	ALLEGRO_BITMAP* b3 = NULL;
	ALLEGRO_BITMAP* b4 = NULL;
	ALLEGRO_FONT* font_menu = al_load_ttf_font("C:/Users/szymo/OneDrive/Pulpit/Pliki/Projekty/C++ & others/LudoGame/TYPEWR__.ttf", 50, 0);

	b2 = al_load_bitmap(B2);
	b3 = al_load_bitmap(B3);
	b4 = al_load_bitmap(B4);

	int by = 500;
	int b2x = 350;
	int b3x = 750;
	int b4x = 1150;
	char napis[50] = "WYBIERZ ILOSC GRACZY";
	switch (chosen_theme) {
	case 1:
		al_draw_text(font_menu, WHITE, 800, 700, ALLEGRO_ALIGN_CENTRE, napis);
		break;
	case 2:
		al_draw_text(font_menu, BLACK, 800, 75, ALLEGRO_ALIGN_CENTRE, napis);
		break;
	case 3:
		al_draw_text(font_menu, BLACK, 800, 75, ALLEGRO_ALIGN_CENTRE, napis);
		break;
	default: break;
	}

	al_draw_bitmap(b2, b2x, by, 0);
	al_draw_bitmap(b3, b3x, by, 0);
	al_draw_bitmap(b4, b4x, by, 0);

	// szerokoœæ 800, wysokoœæ 600

	al_flip_display();


	ALLEGRO_MOUSE_STATE state;
	bool done = false;
	while (!done) {
		al_get_mouse_state(&state);
		if (state.buttons & 1) {
			if ((state.x >= b2x && state.x <= b2x + 100) &&
				(state.y >= by && state.y <= by + 100)) {
				return 2;
			}
			else if ((state.x >= b3x && state.x <= b3x + 100) &&
				(state.y >= by && state.y <= by + 100)) {
				return 3;
			}
			else if ((state.x >= b4x && state.x <= b4x + 100) &&
				(state.y >= by && state.y <= by + 100)) {
				return 4;
			}

		}
		al_rest(0.01);
	}
	return 0;
}

int choose_theme() {
#define main "C:/Users/szymo/OneDrive/Pulpit/Pliki/Projekty/C++ & others/LudoGame/main.jpg"

	ALLEGRO_BITMAP* main1 = NULL;
	ALLEGRO_FONT* font_menu = al_load_ttf_font("C:/Users/szymo/OneDrive/Pulpit/Pliki/Projekty/C++ & others/LudoGame/TYPEWR__.ttf", 50, 0);

	main1 = al_load_bitmap(main);

	char wybierz[18] = "WYBIERZ MOTYW GRY";
	al_draw_bitmap(main1, 0, 0, 0);
	al_draw_text(font_menu, WHITE, 800, 750, ALLEGRO_ALIGN_CENTRE, wybierz);

	al_flip_display();
	al_destroy_bitmap(main1);

	ALLEGRO_MOUSE_STATE state;
	bool done = false;
	while (!done) {
		al_get_mouse_state(&state);
		if (state.buttons & 1) {
			if ((state.x >= 0 && state.x <= 500) &&
				(state.y >= 0 && state.y <= 900)) {
				return 1;
			}
			else if ((state.x >= 501 && state.x <= 1067) &&
				(state.y >= 0 && state.y <= 900)) {
				return 2;
			}
			else if ((state.x >= 1068 && state.x <= 1600) &&
				(state.y >= 0 && state.y <= 900)) {
				return 3;
			}
		}
		al_rest(0.01);
	}
	return 0;
}

void draw_avatars(Player* obj1, Player* obj2, Player* obj3, Player* obj4, int n) {
	ALLEGRO_FONT* font_avatar = al_load_ttf_font("C:/Users/szymo/OneDrive/Pulpit/Pliki/Projekty/C++ & others/LudoGame/TYPEWR__.ttf", 22, 0);
	ALLEGRO_FONT* font_menu = al_load_ttf_font("C:/Users/szymo/OneDrive/Pulpit/Pliki/Projekty/C++ & others/LudoGame/TYPEWR__.ttf", 20, 0);
	char av_nick[20];
	for (int i = 0; i < 20; i++) {
		if (obj1->nick[i] != '\0') {
			av_nick[i] = obj1->nick[i];
		}
		else break;
	}

	int x = 10;
	int y = 155;
	int x1 = 1150;	int x2 = 50;
	int y1 = 130;	int y2 = 620;

	//al_draw_bitmap(av, 650, 200, 0);
	ALLEGRO_BITMAP* av_tlo = al_load_bitmap("C:/Users/szymo/OneDrive/Pulpit/Pliki/Projekty/C++ & others/LudoGame/av_tlo.png");


	if (n == 2) {
		ALLEGRO_BITMAP* av1 = obj1->avatar1;
		ALLEGRO_BITMAP* av2 = obj2->avatar1;
		al_draw_bitmap(av_tlo, x1, y1, 0); //player1
		al_draw_bitmap(av_tlo, x1, y2, 0);  //player 2

		al_draw_bitmap(av1, x1 + x, y1 + x, 0);
		al_draw_bitmap(av2, x1 + x, y2 + x, 0);

		al_draw_text(font_menu, BLACK, x1 + y, y1 + x, ALLEGRO_ALIGN_LEFT, "PLAYER 1");
		al_draw_text(font_menu, BLACK, x1 + y, y2 + x, ALLEGRO_ALIGN_LEFT, "PLAYER 2");

		al_draw_text(font_avatar, BLACK, x1 + y, y1 + 4 * x, ALLEGRO_ALIGN_LEFT, obj1->nick);
		al_draw_text(font_avatar, BLACK, x1 + y, y2 + 4 * x, ALLEGRO_ALIGN_LEFT, obj2->nick);
	}
	else if (n == 3) {
		ALLEGRO_BITMAP* av1 = obj1->avatar1;
		ALLEGRO_BITMAP* av2 = obj2->avatar1;
		ALLEGRO_BITMAP* av3 = obj3->avatar1;

		al_draw_bitmap(av_tlo, x1, y1, 0); //player1
		al_draw_bitmap(av_tlo, x1, y2, 0);  //player 2
		al_draw_bitmap(av_tlo, x2, y2, 0);  //player 3

		al_draw_bitmap(av1, x1 + x, y1 + x, 0);
		al_draw_bitmap(av2, x1 + x, y2 + x, 0);
		al_draw_bitmap(av3, x2 + x, y2 + x, 0);

		al_draw_text(font_menu, BLACK, x1 + y, y1 + x, ALLEGRO_ALIGN_LEFT, "PLAYER 1");
		al_draw_text(font_menu, BLACK, x1 + y, y2 + x, ALLEGRO_ALIGN_LEFT, "PLAYER 2");
		al_draw_text(font_menu, BLACK, x2 + y, y2 + x, ALLEGRO_ALIGN_LEFT, "PLAYER 3");

		al_draw_text(font_avatar, BLACK, x1 + y, y1 + 4 * x, ALLEGRO_ALIGN_LEFT, obj1->nick);
		al_draw_text(font_avatar, BLACK, x1 + y, y2 + 4 * x, ALLEGRO_ALIGN_LEFT, obj2->nick);
		al_draw_text(font_avatar, BLACK, x2 + y, y2 + 4 * x, ALLEGRO_ALIGN_LEFT, obj3->nick);

	}
	else if (n == 4) {
		ALLEGRO_BITMAP* av1 = obj1->avatar1;
		ALLEGRO_BITMAP* av2 = obj2->avatar1;
		ALLEGRO_BITMAP* av3 = obj3->avatar1;
		ALLEGRO_BITMAP* av4 = obj4->avatar1;

		al_draw_bitmap(av_tlo, x1, y1, 0); //player1
		al_draw_bitmap(av_tlo, x1, y2, 0);  //player 2
		al_draw_bitmap(av_tlo, x2, y2, 0);  //player 3
		al_draw_bitmap(av_tlo, x2, y1, 0);   //player 4

		al_draw_bitmap(av1, x1 + x, y1 + x, 0);
		al_draw_bitmap(av2, x1 + x, y2 + x, 0);
		al_draw_bitmap(av3, x2 + x, y2 + x, 0);
		al_draw_bitmap(av4, x2 + x, y1 + x, 0);

		al_draw_text(font_menu, BLACK, x1 + y, y1 + x, ALLEGRO_ALIGN_LEFT, "PLAYER 1");
		al_draw_text(font_menu, BLACK, x1 + y, y2 + x, ALLEGRO_ALIGN_LEFT, "PLAYER 2");
		al_draw_text(font_menu, BLACK, x2 + y, y2 + x, ALLEGRO_ALIGN_LEFT, "PLAYER 3");
		al_draw_text(font_menu, BLACK, x2 + y, y1 + x, ALLEGRO_ALIGN_LEFT, "PLAYER 4");

		al_draw_text(font_avatar, BLACK, x1 + y, y1 + 4 * x, ALLEGRO_ALIGN_LEFT, obj1->nick);
		al_draw_text(font_avatar, BLACK, x1 + y, y2 + 4 * x, ALLEGRO_ALIGN_LEFT, obj2->nick);
		al_draw_text(font_avatar, BLACK, x2 + y, y2 + 4 * x, ALLEGRO_ALIGN_LEFT, obj3->nick);
		al_draw_text(font_avatar, BLACK, x2 + y, y1 + 4 * x, ALLEGRO_ALIGN_LEFT, obj4->nick);
	}
	al_flip_display();
}

void print_rolled(int n) {
	ALLEGRO_FONT* font_menu = al_load_ttf_font("C:/Users/szymo/OneDrive/Pulpit/Pliki/Projekty/C++ & others/LudoGame/TYPEWR__.ttf", 22, 0);
	ALLEGRO_FONT* font = al_load_ttf_font("C:/Users/szymo/OneDrive/Pulpit/Pliki/Projekty/C++ & others/LudoGame/TYPEWR__.ttf", 20, 0);
	al_draw_textf(font_menu, BLACK, 670, 102, ALLEGRO_ALIGN_LEFT, "WYRZUCONO:   %d", n);
	al_draw_text(font, BLACK, 670, 126, ALLEGRO_ALIGN_LEFT, "WYBIERZ PIONEK");
	al_flip_display();
}

void print_who_now(int n, Player* obj) {
	ALLEGRO_FONT* font_menu = al_load_ttf_font("C:/Users/szymo/OneDrive/Pulpit/Pliki/Projekty/C++ & others/LudoGame/TYPEWR__.ttf", 22, 0);
	ALLEGRO_FONT* font = al_load_ttf_font("C:/Users/szymo/OneDrive/Pulpit/Pliki/Projekty/C++ & others/LudoGame/TYPEWR__.ttf", 20, 0);
	char av_nick[20];
	for (int i = 0; i < 20; i++) {
		if (obj->nick[i] != '\0') {
			av_nick[i] = obj->nick[i];
		}
		else break;
	}
	al_draw_textf(font, BLACK, 670, 55, ALLEGRO_ALIGN_LEFT, "PLAYER %d:", n + 1);
	al_draw_text(font_menu, BLACK, 670, 76, ALLEGRO_ALIGN_LEFT, av_nick);
	al_flip_display();
}