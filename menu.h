#pragma once
#include <stdio.h>
#include <iostream>
#include <string>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/events.h>

using namespace std;

class Player  {
public:
	char nick[20];
	ALLEGRO_BITMAP* avatar = NULL;
	ALLEGRO_BITMAP* avatar1 = NULL;
};


int write_nick(int, Player *obj);
int choose_theme();
void refresh(int);
int choose_players(int);
int menu();
int chose_avatar(int, Player* obj);
void draw_avatars(Player* obj1, Player* obj2, Player *obj3, Player *obj4, int n);
void print_rolled(int n);
void print_who_now(int n, Player* obj);

/*
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
int BUTTON_ROLL_POS[2] = { 100, 100 };
*/