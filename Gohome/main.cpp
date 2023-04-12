#include <SDL.h>
#include <bits/stdc++.h>
#include <SDL_image.h>
#include <SDL_ttf.h>


const int TILE_SIZE = 32;
const int MAP_WIDTH = 25;
const int MAP_HEIGHT = 20;


const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 640;


const int CHARACTER_SPEED = 13;
const int CHARACTER_WIDTH = 13;
const int CHARACTER_HEIGHT = 13;


bool enemy11_move_right = true;
bool enemy12_move_right = true;
bool enemy13_move_right = true;
bool enemy14_move_right = true;
bool enemy15_move_right = true;


bool enemy21_move_up = true;
bool enemy22_move_up = true;
bool enemy23_move_up = true;
bool enemy24_move_up = true;
bool enemy25_move_up = true;
bool enemy26_move_up = true;
bool enemy27_move_up = true;
bool enemy28_move_up = true;
bool enemy29_move_up = true;
bool enemy210_move_up = true;
bool enemy211_move_up = true;
bool enemy212_move_up = true;
bool enemy213_move_up = true;
bool enemy214_move_up = true;
bool enemy215_move_up = true;
bool enemy216_move_up = true;
bool enemy217_move_up = true;
bool enemy218_move_up = true;


bool enemy31_move_right = true;
bool enemy32_move_right = true;
bool enemy33_move_right = true;


int tileMap[MAP_HEIGHT][MAP_WIDTH] = {
    { 3,3,3,3,3,3,3,3,3,3,3,5,2,2,2,2,2,2,2,2,2,2,2,2,2 },
    { 3,3,3,3,3,3,3,3,3,3,3,5,2,2,2,2,2,2,2,2,2,2,2,2,2 },
    { 3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3 },
    { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4 },
    { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
    { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
    { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
    { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
    { 3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3 },
    { 4,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
    { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
    { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
    { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
    { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
    { 3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3 },
    { 2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,4 },
    { 2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2 },
    { 2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2 },
    { 2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2 },
    { 2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2 }
};


bool checkCollision(SDL_Rect a, SDL_Rect b) {
    if (a.x + a.w >= b.x && b.x + b.w >= a.x && a.y + a.h >= b.y && b.y + b.h >= a.y) {
        return true;
    }
    return false;
}


void reset(SDL_Rect &c) {
    c.x = 0;
    c.y = 608;
}


void reset1(SDL_Rect &d) {
    d.x = 770 ;
    d.y = 416 ;
    
}


void reset2(SDL_Rect &e) {
    e.x = 0;
    e.y = 224;
}


void reset3(SDL_Rect& f) {
    f.x = 768;
    f.y = 32;
}



int main(int argc, char* argv[]) {
    
    const int FPS = 60;
    const int frameDelay = 1000 / FPS;
    Uint32 frameStart;
    int frameTime;

    SDL_Init(SDL_INIT_VIDEO);


    SDL_Window* window = SDL_CreateWindow("Go home", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);


    
    SDL_Surface* image_start = IMG_Load("start.png");


    //tang 1
    SDL_Surface* surface_home = IMG_Load("home.png");
    SDL_Surface* surface_ladder = IMG_Load("ladder.png");
    SDL_Surface* surface_rock = IMG_Load("rock.png");
    SDL_Surface* surface_grass = IMG_Load("grass.png");
    SDL_Surface* surface_dirt = IMG_Load("dirt.png");
    SDL_Surface* surface_water = IMG_Load("water.png");
    SDL_Surface* image_surface = IMG_Load("player.png");
    SDL_Surface* image_enemy11 = IMG_Load("enemy16.png");
    SDL_Surface* image_enemy12 = IMG_Load("enemy16.png");
    SDL_Surface* image_enemy13 = IMG_Load("enemy16.png");
    SDL_Surface* image_enemy14 = IMG_Load("enemy16.png");
    SDL_Surface* image_enemy15 = IMG_Load("enemy16.png");
    //tang 2
    SDL_Surface* image_enemy21 = IMG_Load("enemy16.png");
    SDL_Surface* image_enemy22 = IMG_Load("enemy16.png");
    SDL_Surface* image_enemy23 = IMG_Load("enemy16.png");
    SDL_Surface* image_enemy24 = IMG_Load("enemy16.png");
    SDL_Surface* image_enemy25 = IMG_Load("enemy16.png");
    SDL_Surface* image_enemy26 = IMG_Load("enemy16.png");
    SDL_Surface* image_enemy27 = IMG_Load("enemy16.png");
    SDL_Surface* image_enemy28 = IMG_Load("enemy16.png");
    SDL_Surface* image_enemy29 = IMG_Load("enemy16.png");
    SDL_Surface* image_enemy210 = IMG_Load("enemy16.png");
    SDL_Surface* image_enemy211 = IMG_Load("enemy16.png");
    SDL_Surface* image_enemy212 = IMG_Load("enemy16.png");
    SDL_Surface* image_enemy213 = IMG_Load("enemy16.png");
    SDL_Surface* image_enemy214 = IMG_Load("enemy16.png");
    SDL_Surface* image_enemy215 = IMG_Load("enemy16.png");
    SDL_Surface* image_enemy216 = IMG_Load("enemy16.png");
    SDL_Surface* image_enemy217 = IMG_Load("enemy16.png");
    SDL_Surface* image_enemy218 = IMG_Load("enemy16.png");
    //tang 3
    SDL_Surface* image_enemy31 = IMG_Load("enemy16.png");
    SDL_Surface* image_enemy32 = IMG_Load("enemy16.png");
    SDL_Surface* image_enemy33 = IMG_Load("enemy16.png");

    SDL_Texture* texture_home = SDL_CreateTextureFromSurface(renderer, surface_home);
    SDL_Texture* texture_ladder = SDL_CreateTextureFromSurface(renderer, surface_ladder);
    SDL_Texture* texture_rock = SDL_CreateTextureFromSurface(renderer, surface_rock);
    SDL_Texture* texture_grass = SDL_CreateTextureFromSurface(renderer, surface_grass);
    SDL_Texture* texture_dirt = SDL_CreateTextureFromSurface(renderer, surface_dirt);
    SDL_Texture* texture_water = SDL_CreateTextureFromSurface(renderer, surface_water);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, image_surface);
    SDL_Texture* texture_enemy11 = SDL_CreateTextureFromSurface(renderer, image_enemy11);
    SDL_Texture* texture_enemy12 = SDL_CreateTextureFromSurface(renderer, image_enemy12);
    SDL_Texture* texture_enemy13 = SDL_CreateTextureFromSurface(renderer, image_enemy13);
    SDL_Texture* texture_enemy14 = SDL_CreateTextureFromSurface(renderer, image_enemy14);
    SDL_Texture* texture_enemy15 = SDL_CreateTextureFromSurface(renderer, image_enemy15);
    SDL_Texture* texture_enemy21 = SDL_CreateTextureFromSurface(renderer, image_enemy21);
    SDL_Texture* texture_enemy22 = SDL_CreateTextureFromSurface(renderer, image_enemy22);
    SDL_Texture* texture_enemy23 = SDL_CreateTextureFromSurface(renderer, image_enemy23);
    SDL_Texture* texture_enemy24 = SDL_CreateTextureFromSurface(renderer, image_enemy24);
    SDL_Texture* texture_enemy25 = SDL_CreateTextureFromSurface(renderer, image_enemy25);
    SDL_Texture* texture_enemy26 = SDL_CreateTextureFromSurface(renderer, image_enemy26);
    SDL_Texture* texture_enemy27 = SDL_CreateTextureFromSurface(renderer, image_enemy27);
    SDL_Texture* texture_enemy28 = SDL_CreateTextureFromSurface(renderer, image_enemy28);
    SDL_Texture* texture_enemy29 = SDL_CreateTextureFromSurface(renderer, image_enemy29);
    SDL_Texture* texture_enemy210 = SDL_CreateTextureFromSurface(renderer, image_enemy210);
    SDL_Texture* texture_enemy211 = SDL_CreateTextureFromSurface(renderer, image_enemy211);
    SDL_Texture* texture_enemy212 = SDL_CreateTextureFromSurface(renderer, image_enemy212);
    SDL_Texture* texture_enemy213 = SDL_CreateTextureFromSurface(renderer, image_enemy213);
    SDL_Texture* texture_enemy214 = SDL_CreateTextureFromSurface(renderer, image_enemy214);
    SDL_Texture* texture_enemy215 = SDL_CreateTextureFromSurface(renderer, image_enemy215);
    SDL_Texture* texture_enemy216 = SDL_CreateTextureFromSurface(renderer, image_enemy216);
    SDL_Texture* texture_enemy217 = SDL_CreateTextureFromSurface(renderer, image_enemy217);
    SDL_Texture* texture_enemy218 = SDL_CreateTextureFromSurface(renderer, image_enemy218);
    SDL_Texture* texture_enemy31 = SDL_CreateTextureFromSurface(renderer, image_enemy31);
    SDL_Texture* texture_enemy32 = SDL_CreateTextureFromSurface(renderer, image_enemy32);
    SDL_Texture* texture_enemy33 = SDL_CreateTextureFromSurface(renderer, image_enemy33);
    


    SDL_Texture* texture_start = SDL_CreateTextureFromSurface(renderer, image_start);


    SDL_FreeSurface(surface_home);
    SDL_FreeSurface(surface_ladder);
    SDL_FreeSurface(surface_rock);
    SDL_FreeSurface(surface_grass);
    SDL_FreeSurface(surface_dirt);
    SDL_FreeSurface(surface_water);
    SDL_FreeSurface(image_surface);
    SDL_FreeSurface(image_enemy11);
    SDL_FreeSurface(image_enemy12);
    SDL_FreeSurface(image_enemy13);
    SDL_FreeSurface(image_enemy14);
    SDL_FreeSurface(image_enemy15);
    SDL_FreeSurface(image_enemy21);
    SDL_FreeSurface(image_enemy22);
    SDL_FreeSurface(image_enemy23);
    SDL_FreeSurface(image_enemy24);
    SDL_FreeSurface(image_enemy25);
    SDL_FreeSurface(image_enemy26);
    SDL_FreeSurface(image_enemy27);
    SDL_FreeSurface(image_enemy28);
    SDL_FreeSurface(image_enemy29);
    SDL_FreeSurface(image_enemy210);
    SDL_FreeSurface(image_enemy211);
    SDL_FreeSurface(image_enemy212);
    SDL_FreeSurface(image_enemy213);
    SDL_FreeSurface(image_enemy214);
    SDL_FreeSurface(image_enemy215);
    SDL_FreeSurface(image_enemy216);
    SDL_FreeSurface(image_enemy217);
    SDL_FreeSurface(image_enemy218);
    SDL_FreeSurface(image_enemy31);
    SDL_FreeSurface(image_enemy32);
    SDL_FreeSurface(image_enemy33);
    SDL_FreeSurface(image_start);

    SDL_Rect character = { 700 , 0 , CHARACTER_WIDTH , CHARACTER_HEIGHT };
    SDL_Rect enemy11 = { 0, 608 , 32 , 32 };
    SDL_Rect enemy12 = { 0, 544, 32 , 32 };
    SDL_Rect enemy13 = { 0, 480, 32 , 32 };
    SDL_Rect enemy14 = { 768 , 576, 32 , 32 };
    SDL_Rect enemy15 = { 768 , 512, 32 , 32 };
    SDL_Rect enemy21 = { 736 , 416, 32 , 32 };
    SDL_Rect enemy22 = { 672 , 416, 32 , 32 };
    SDL_Rect enemy23 = { 608 , 416, 32 , 32 };
    SDL_Rect enemy24 = { 544 , 416, 32 , 32 };
    SDL_Rect enemy25 = { 480 , 416, 32 , 32 };
    SDL_Rect enemy26 = { 416 , 416, 32 , 32 };
    SDL_Rect enemy27 = { 352 , 416, 32 , 32 };
    SDL_Rect enemy28 = { 288 , 416, 32 , 32 };
    SDL_Rect enemy29 = { 224 , 416, 32 , 32 };
    SDL_Rect enemy210 = { 160 , 416, 32 , 32 };
    SDL_Rect enemy211 = { 96 , 416, 32 , 32 };
    SDL_Rect enemy212 = { 32 , 416, 32 , 32 };
    SDL_Rect enemy213 = { 704 , 288, 32 , 32 };
    SDL_Rect enemy214 = { 576 , 288, 32 , 32 };
    SDL_Rect enemy215 = { 448, 288, 32 , 32 };
    SDL_Rect enemy216 = { 320 , 288, 32 , 32 };
    SDL_Rect enemy217 = { 192 , 288, 32 , 32 };
    SDL_Rect enemy218 = { 64 , 288, 32 , 32 };
    SDL_Rect enemy31 = { 32 , 96 , 32 , 96 };
    SDL_Rect enemy32 = { 32 , 128 , 32 , 96 };
    SDL_Rect enemy33 = { 32 , 160 , 32 , 96 };
    SDL_Rect rectstart = { 0 , 0 , 800 , 640 };
    
    
    SDL_Event event;

    bool quit = true;
    bool start = false;
    bool win = false;

    while (!start)
    {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_MOUSEBUTTONDOWN) {
                start = true;
                quit = false;
            }
        }
        SDL_RenderCopy(renderer, texture_start, NULL, &rectstart);
        SDL_RenderPresent(renderer);
    }


    while (!quit) {
        frameStart = SDL_GetTicks();


        while (SDL_PollEvent(&event) != 0) {
            
            if (event.type == SDL_QUIT) {
                quit = true;
            }
            else if (event.type == SDL_KEYDOWN) {
                switch (event.key.keysym.sym) {
                case SDLK_LEFT:
                    character.x -= CHARACTER_SPEED;
                    break;
                case SDLK_RIGHT:
                    character.x += CHARACTER_SPEED;
                    break;
                case SDLK_UP:
                    if (character.y >= 460) {
                        if (character.y <= 480) {
                            break;
                        }
                        else
                        {
                            character.y -= CHARACTER_SPEED;
                            break;
                        }
                    }
                    if (character.y < 460 && character.y >= 270 ) {
                        if (character.y <= 288) {
                            break;
                        }
                        else
                        {
                            character.y -= CHARACTER_SPEED;
                            break;
                        }
                    }
                    if (character.y < 270 && character.y >= 80 )  {
                        if (character.y <= 96) {
                            break;
                        }
                        else
                        {
                            character.y -= CHARACTER_SPEED;
                            break;
                        }
                    }
                    if (character.y < 80 ) {
                        character.y -= CHARACTER_SPEED;
                        break;
                    }
                case SDLK_DOWN:
                    if (character.y >= 460) {
                        character.y += CHARACTER_SPEED;
                        break;
                    }
                    if (character.y < 460 && character.y >= 270) {
                        if (character.y >= 428) {
                            break;
                        }
                        else {
                            character.y += CHARACTER_SPEED;
                            break;
                        }
                    }
                    if (character.y < 270 && character.y >= 80 ) {
                        if (character.y >= 236 ) {
                            break;
                        }
                        else {
                            character.y += CHARACTER_SPEED;
                            break;
                        }
                    }
                    if (character.y < 80 && character.y >= 0) {
                        if (character.y >= 44) {
                            break;
                        }
                        else {
                            character.y += CHARACTER_SPEED;
                            break;
                        }
                    }
                }
            }
        }
        //character limit
        if (character.x < 0) {
            character.x = 0;
        }
        if (character.x > SCREEN_WIDTH - CHARACTER_WIDTH) {
            character.x = SCREEN_WIDTH - CHARACTER_WIDTH;
        }
        if (character.y < 0) {
            character.y = 0;
        }
        if (character.y > SCREEN_HEIGHT - CHARACTER_HEIGHT) {
            character.y = SCREEN_HEIGHT - CHARACTER_HEIGHT;
        }
        if (character.y > 480 && character.y < 512 && character.x > 768) {
            character.y = character.y - 64;
        }
        if (character.y > 288 && character.y < 310  && character.x < 28 ) {
            character.y = character.y - 64;
        }
        if (character.y > 96  && character.y < 128 && character.x > 768) {
            character.y = character.y - 64;
        }
        if (character.y < 96 && character.x < 384) {
            quit = true;
            win = true;
        }




        if (enemy11_move_right) {
            enemy11.x += 5;
        }
        else {
            enemy11.x -= 5;
        }
        if (enemy11.x <= 32 ) {
            enemy11_move_right = true;
        }
        else if (enemy11.x >= 768) {
            enemy11_move_right = false;
        }



        if (enemy12_move_right) {
            enemy12.x += 5;
        }
        else {
            enemy12.x -= 5;
        }
        if (enemy12.x <= 32) {
            enemy12_move_right = true;
        }
        else if (enemy12.x >= 768) {
            enemy12_move_right = false;
        }




        if (enemy13_move_right) {
            enemy13.x += 5;
        }
        else {
            enemy13.x -= 5;
        }
        if (enemy13.x <= 32) {
            enemy13_move_right = true;
        }
        else if (enemy13.x >= 768) {
            enemy13_move_right = false;
        }


        if (enemy14_move_right) {
            enemy14.x += 5;
        }
        else {
            enemy14.x -= 5;
        }
        if (enemy14.x <= 32) {
            enemy14_move_right = true;
        }
        else if (enemy14.x >= 768) {
            enemy14_move_right = false;
        }



        if (enemy15_move_right) {
            enemy15.x += 5;
        }
        else {
            enemy15.x -= 5;
        }
        if (enemy15.x <= 32) {
            enemy15_move_right = true;
        }
        else if (enemy15.x >= 768) {
            enemy15_move_right = false;
        }


        if (enemy21_move_up) {
            enemy21.y -= 3;
        }
        else {
            enemy21.y += 3;
        }
        if (enemy21.y >= 416) {
            enemy21_move_up = true;
        }
        else if (enemy21.y <= 288) {
            enemy21_move_up = false;
        }



        if (enemy22_move_up) {
            enemy22.y -= 3;
        }
        else {
            enemy22.y += 3;
        }
        if (enemy22.y >= 416) {
            enemy22_move_up = true;
        }
        else if (enemy22.y <= 288) {
            enemy22_move_up = false;
        }



        if (enemy23_move_up) {
            enemy23.y -= 3;
        }
        else {
            enemy23.y += 3;
        }
        if (enemy23.y >= 416) {
            enemy23_move_up = true;
        }
        else if (enemy23.y <= 288) {
            enemy23_move_up = false;
        }



        if (enemy24_move_up) {
            enemy24.y -= 3;
        }
        else {
            enemy24.y += 3;
        }
        if (enemy24.y >= 416) {
            enemy24_move_up = true;
        }
        else if (enemy24.y <= 288) {
            enemy24_move_up = false;
        }



        if (enemy25_move_up) {
            enemy25.y -= 3;
        }
        else {
            enemy25.y += 3;
        }
        if (enemy25.y >= 416) {
            enemy25_move_up = true;
        }
        else if (enemy25.y <= 288) {
            enemy25_move_up = false;
        }


        if (enemy26_move_up) {
            enemy26.y -= 3;
        }
        else {
            enemy26.y += 3;
        }
        if (enemy26.y >= 416) {
            enemy26_move_up = true;
        }
        else if (enemy26.y <= 288) {
            enemy26_move_up = false;
        }



        if (enemy27_move_up) {
            enemy27.y -= 3;
        }
        else {
            enemy27.y += 3;
        }
        if (enemy27.y >= 416) {
            enemy27_move_up = true;
        }
        else if (enemy27.y <= 288) {
            enemy27_move_up = false;
        }



        if (enemy28_move_up) {
            enemy28.y -= 3;
        }
        else {
            enemy28.y += 3;
        }
        if (enemy28.y >= 416) {
            enemy28_move_up = true;
        }
        else if (enemy28.y <= 288) {
            enemy28_move_up = false;
        }



        if (enemy29_move_up) {
            enemy29.y -= 3;
        }
        else {
            enemy29.y += 3;
        }
        if (enemy29.y >= 416) {
            enemy29_move_up = true;
        }
        else if (enemy29.y <= 288) {
            enemy29_move_up = false;
        }



        if (enemy210_move_up) {
            enemy210.y -= 3;
        }
        else {
            enemy210.y += 3;
        }
        if (enemy210.y >= 416) {
            enemy210_move_up = true;
        }
        else if (enemy210.y <= 288) {
            enemy210_move_up = false;
        }




        if (enemy211_move_up) {
            enemy211.y -= 3;
        }
        else {
            enemy211.y += 3;
        }
        if (enemy211.y >= 416) {
            enemy211_move_up = true;
        }
        else if (enemy211.y <= 288) {
            enemy211_move_up = false;
        }



        if (enemy212_move_up) {
            enemy212.y -= 3;
        }
        else {
            enemy212.y += 3;
        }
        if (enemy212.y >= 416) {
            enemy212_move_up = true;
        }
        else if (enemy212.y <= 288) {
            enemy212_move_up = false;
        }



        if (enemy213_move_up) {
            enemy213.y -= 3;
        }
        else {
            enemy213.y += 3;
        }
        if (enemy213.y >= 416) {
            enemy213_move_up = true;
        }
        else if (enemy213.y <= 288) {
            enemy213_move_up = false;
        }


        if (enemy214_move_up) {
            enemy214.y -= 3;
        }
        else {
            enemy214.y += 3;
        }
        if (enemy214.y >= 416) {
            enemy214_move_up = true;
        }
        else if (enemy214.y <= 288) {
            enemy214_move_up = false;
        }



        if (enemy215_move_up) {
            enemy215.y -= 3;
        }
        else {
            enemy215.y += 3;
        }
        if (enemy215.y >= 416) {
            enemy215_move_up = true;
        }
        else if (enemy215.y <= 288) {
            enemy215_move_up = false;
        }



        if (enemy216_move_up) {
            enemy216.y -= 3;
        }
        else {
            enemy216.y += 3;
        }
        if (enemy216.y >= 416) {
            enemy216_move_up = true;
        }
        else if (enemy216.y <= 288) {
            enemy216_move_up = false;
        }



        if (enemy217_move_up) {
            enemy217.y -= 3;
        }
        else {
            enemy217.y += 3;
        }
        if (enemy217.y >= 416) {
            enemy217_move_up = true;
        }
        else if (enemy217.y <= 288) {
            enemy217_move_up = false;
        }



        if (enemy218_move_up) {
            enemy218.y -= 3;
        }
        else {
            enemy218.y += 3;
        }
        if (enemy218.y >= 416) {
            enemy218_move_up = true;
        }
        else if (enemy218.y <= 288) {
            enemy218_move_up = false;
        }


        if (enemy31_move_right) {
            enemy31.x += 8;
        }
        else {
            enemy31.x -= 8;
        }
        if (enemy31.x <= 32) {
            enemy31_move_right = true;
        }
        else if (enemy31.x >= 736) {
            enemy31_move_right = false;
        }



        if (enemy32_move_right) {
            enemy32.x += 6;
        }
        else {
            enemy32.x -= 6;
        }
        if (enemy32.x <= 32) {
            enemy32_move_right = true;
        }
        else if (enemy32.x >= 736) {
            enemy32_move_right = false;
        }



        if (enemy33_move_right) {
            enemy33.x += 4;
        }
        else {
            enemy33.x -= 4;
        }
        if (enemy33.x <= 32) {
            enemy33_move_right = true;
        }
        else if (enemy33.x >= 736) {
            enemy33_move_right = false;
        }


        // update trang thai game



        // set color cho renderer
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);


        SDL_RenderClear(renderer);

        // ve nhan vat  
        // ve map
        for (int row = 0; row < 20; row++) {
            for (int column = 0; column < 25; column++)
            {
                SDL_Rect rect;
                rect.x = column * 32 ;
                rect.y = row * 32 ;
                rect.w = 32;
                rect.h = 32;

                switch (tileMap[row][column])
                {
                case 0:
                    SDL_RenderCopy(renderer, texture_grass, NULL, &rect);
                    break;
                case 1:
                    SDL_RenderCopy(renderer, texture_dirt, NULL, &rect);
                    break;
                case 2:
                    SDL_RenderCopy(renderer, texture_water, NULL, &rect);
                    break;
                case 3:
                    SDL_RenderCopy(renderer, texture_rock, NULL, &rect);
                    break;
                case 4:
                    SDL_RenderCopy(renderer, texture_ladder, NULL, &rect);
                    break;
                case 5:
                    SDL_RenderCopy(renderer, texture_home, NULL, &rect);
                    break;
                }
            }
        }

        SDL_RenderCopy(renderer, texture, NULL, &character);
        SDL_RenderCopy(renderer, texture_enemy11, NULL, &enemy11);
        SDL_RenderCopy(renderer, texture_enemy12, NULL, &enemy12);
        SDL_RenderCopy(renderer, texture_enemy13, NULL, &enemy13);
        SDL_RenderCopy(renderer, texture_enemy14, NULL, &enemy14);
        SDL_RenderCopy(renderer, texture_enemy15, NULL, &enemy15);
        SDL_RenderCopy(renderer, texture_enemy21, NULL, &enemy21);
        SDL_RenderCopy(renderer, texture_enemy22, NULL, &enemy22);
        SDL_RenderCopy(renderer, texture_enemy23, NULL, &enemy23);
        SDL_RenderCopy(renderer, texture_enemy24, NULL, &enemy24);
        SDL_RenderCopy(renderer, texture_enemy25, NULL, &enemy25);
        SDL_RenderCopy(renderer, texture_enemy26, NULL, &enemy26);
        SDL_RenderCopy(renderer, texture_enemy27, NULL, &enemy27);
        SDL_RenderCopy(renderer, texture_enemy28, NULL, &enemy28);
        SDL_RenderCopy(renderer, texture_enemy29, NULL, &enemy29);
        SDL_RenderCopy(renderer, texture_enemy210, NULL, &enemy210);
        SDL_RenderCopy(renderer, texture_enemy211, NULL, &enemy211);
        SDL_RenderCopy(renderer, texture_enemy212, NULL, &enemy212);
        SDL_RenderCopy(renderer, texture_enemy213, NULL, &enemy213);
        SDL_RenderCopy(renderer, texture_enemy214, NULL, &enemy214);
        SDL_RenderCopy(renderer, texture_enemy215, NULL, &enemy215);
        SDL_RenderCopy(renderer, texture_enemy216, NULL, &enemy216);
        SDL_RenderCopy(renderer, texture_enemy217, NULL, &enemy217);
        SDL_RenderCopy(renderer, texture_enemy218, NULL, &enemy218);
        SDL_RenderCopy(renderer, texture_enemy31, NULL, &enemy31);
        SDL_RenderCopy(renderer, texture_enemy32, NULL, &enemy32);
        SDL_RenderCopy(renderer, texture_enemy33, NULL, &enemy33);


        if (checkCollision(character , enemy11)) {
            std::cout << "va cham" << std::endl;
            reset(character);
        }
        if (checkCollision(character, enemy12)) {
            std::cout << "va cham" << std::endl;
            reset(character);
        }
        if (checkCollision(character, enemy13)) {
            std::cout << "va cham" << std::endl;
            reset(character);
        }
        if (checkCollision(character, enemy14)) {
            std::cout << "va cham" << std::endl;
            reset(character);
        }
        if (checkCollision(character, enemy15)) {
            std::cout << "va cham" << std::endl;
            reset(character);
        }
        if (checkCollision(character, enemy21)) {
            std::cout << "va cham" << std::endl;
            reset1(character);
        }
        if (checkCollision(character, enemy22)) {
            std::cout << "va cham" << std::endl;
            reset1(character);
        }
        if (checkCollision(character, enemy23)) {
            std::cout << "va cham" << std::endl;
            reset1(character);
        }
        if (checkCollision(character, enemy24)) {
            std::cout << "va cham" << std::endl;
            reset1(character);
        }
        if (checkCollision(character, enemy25)) {
            std::cout << "va cham" << std::endl;
            reset1(character);
        }
        if (checkCollision(character, enemy26)) {
            std::cout << "va cham" << std::endl;
            reset1(character);
        }
        if (checkCollision(character, enemy27)) {
            std::cout << "va cham" << std::endl;
            reset1(character);
        }
        if (checkCollision(character, enemy28)) {
            std::cout << "va cham" << std::endl;
            reset1(character);
        }
        if (checkCollision(character, enemy29)) {
            std::cout << "va cham" << std::endl;
            reset1(character);
        }
        if (checkCollision(character, enemy210)) {
            std::cout << "va cham" << std::endl;
            reset1(character);
        }
        if (checkCollision(character, enemy211)) {
            std::cout << "va cham" << std::endl;
            reset1(character);
        }
        if (checkCollision(character, enemy212)) {
            std::cout << "va cham" << std::endl;
            reset1(character);
        }
        if (checkCollision(character, enemy213)) {
            std::cout << "va cham" << std::endl;
            reset1(character);
        }
        if (checkCollision(character, enemy214)) {
            std::cout << "va cham" << std::endl;
            reset1(character);
        }
        if (checkCollision(character, enemy215)) {
            std::cout << "va cham" << std::endl;
            reset1(character);
        }
        if (checkCollision(character, enemy216)) {
            std::cout << "va cham" << std::endl;
            reset1(character);
        }
        if (checkCollision(character, enemy217)) {
            std::cout << "va cham" << std::endl;
            reset1(character);
        }
        if (checkCollision(character, enemy218)) {
            std::cout << "va cham" << std::endl;
            reset1(character);
        }
        if (checkCollision(character, enemy31)) {
            std::cout << "va cham" << std::endl;
            reset2(character);
        }
        if (checkCollision(character, enemy32)) {
            std::cout << "va cham" << std::endl;
            reset2(character);
        }
        if (checkCollision(character, enemy33)) {
            std::cout << "va cham" << std::endl;
            reset2(character);
        }


        SDL_RenderPresent(renderer);


        frameTime = SDL_GetTicks() - frameStart;
        if (frameDelay > frameTime) {
            SDL_Delay(frameDelay - frameTime);
        }
    }


    while (win) {
        TTF_Init();
        TTF_Font* font = TTF_OpenFont("opensan.ttf", 36);
        SDL_Color textColor = { 255, 0, 0 };
        SDL_Surface* textSurface = TTF_RenderText_Solid(font, "You win!", textColor);
        SDL_Texture* textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, textTexture, NULL, NULL);
        SDL_RenderPresent(renderer);
        SDL_Delay(3000);
    }
    


    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;

}