#include <SDL.h>
#include <bits/stdc++.h>
#include <SDL_image.h>
#include <SDL_ttf.h>


const int TILE_SIZE = 32;
const int MAP_WIDTH = 25;
const int MAP_HEIGHT = 20;


const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 640;


const int CHARACTER_SPEED = 4;
const int CHARACTER_WIDTH = 20;
const int CHARACTER_HEIGHT = 20;

bool enemy11_move_right = true;
bool enemy12_move_right = true;


int tileMap[MAP_HEIGHT][MAP_WIDTH] = {
    { 5,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2 },
    { 2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2 },
    { 3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,4 },
    { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
    { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
    { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
    { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
    { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
    { 4,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3 },
    { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
    { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
    { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
    { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
    { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
    { 3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,4 },
    { 2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2 },
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



int main(int argc, char* argv[]) {
    
    const int FPS = 60;
    const int frameDelay = 1000 / FPS;
    Uint32 frameStart;
    int frameTime;
    
    
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window* window = SDL_CreateWindow("Go home", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    
    SDL_Surface* surface_home = IMG_Load("home.png");
    SDL_Surface* surface_ladder = IMG_Load("ladder.png");
    SDL_Surface* surface_rock = IMG_Load("rock.png");
    SDL_Surface* surface_grass = IMG_Load("grass.png");
    SDL_Surface* surface_dirt = IMG_Load("dirt.png");
    SDL_Surface* surface_water = IMG_Load("water.png");
    SDL_Surface* image_surface = IMG_Load("player.png");
    SDL_Surface* image_enemy11 = IMG_Load("enemy11.png");
    SDL_Surface* image_enemy12 = IMG_Load("enemy12.png");

    SDL_Texture* texture_home = SDL_CreateTextureFromSurface(renderer, surface_home);
    SDL_Texture* texture_ladder = SDL_CreateTextureFromSurface(renderer, surface_ladder);
    SDL_Texture* texture_rock = SDL_CreateTextureFromSurface(renderer, surface_rock);
    SDL_Texture* texture_grass = SDL_CreateTextureFromSurface(renderer, surface_grass);
    SDL_Texture* texture_dirt = SDL_CreateTextureFromSurface(renderer, surface_dirt);
    SDL_Texture* texture_water = SDL_CreateTextureFromSurface(renderer, surface_water);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, image_surface);
    SDL_Texture* texture_enemy11 = SDL_CreateTextureFromSurface(renderer, image_enemy11);
    SDL_Texture* texture_enemy12 = SDL_CreateTextureFromSurface(renderer, image_enemy12);

    SDL_FreeSurface(surface_home);
    SDL_FreeSurface(surface_ladder);
    SDL_FreeSurface(surface_rock);
    SDL_FreeSurface(surface_grass);
    SDL_FreeSurface(surface_dirt);
    SDL_FreeSurface(surface_water);
    SDL_FreeSurface(image_surface);
    SDL_FreeSurface(image_enemy11);
    SDL_FreeSurface(image_enemy12);

    SDL_Rect character = { 0 , 544 , 20, 20 };
    SDL_Rect enemy11 = { 0, 576, 20 , 20 };
    SDL_Rect enemy12 = { 800, 512, 20 , 20 };

    bool quit = false;
    SDL_Event event;
    while (!quit) {
        
        frameStart = SDL_GetTicks();

        while (SDL_PollEvent(&event) != 0) {
            if (event.type == SDL_QUIT) {
                quit = true;
            }
            //character move 
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





        if (enemy11_move_right) {
            enemy11.x += 5;
        }
        else {
            enemy11.x -= 5;
        }
        if (enemy11.x <= 32) {
            enemy11_move_right = true;
        }
        else if (enemy11.x >= 800) {
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
        else if (enemy12.x >= 800) {
            enemy12_move_right = false;
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
        SDL_RenderCopy(renderer, texture, nullptr, &character);
        SDL_RenderCopy(renderer, texture_enemy11, NULL, &enemy11);
        SDL_RenderCopy(renderer, texture_enemy12, NULL, &enemy12);

        if (checkCollision(character , enemy11)) {
            std::cout << "va cham con me no roi" << std::endl;
            quit = true;
        }
        if (checkCollision(character, enemy12)) {
            std::cout << "va cham con me no roi" << std::endl;
            quit = true;
        }



        SDL_RenderPresent(renderer);



        frameTime = SDL_GetTicks() - frameStart;
        if (frameDelay > frameTime) {
            SDL_Delay(frameDelay - frameTime);
        }
    }
    




    SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Game Over", "You have collided with the enemy!", NULL);




    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}