#include <SDL2/SDL.h>
#include <iostream>

int main()
{
	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;

	SDL_Event event;

	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_CreateWindowAndRenderer(1280, 720, 0, &window, &renderer);

	// Create a rectangle
	SDL_Rect r{10, 10, 250, 250};


	bool running = true;
	while(running)
	{
		// eventListener?
		while(SDL_PollEvent(&event))
		{
			// If window X clicked, close the program
			if(event.type == SDL_QUIT)
				running = false;

			// Listen for key press (right arrow)
			if(event.type == SDL_KEYDOWN)
			{
				switch(event.key.keysym.sym)
				{
					case SDLK_RIGHT:
						std::cout << "key right_arrow was pressed" << std::endl;
						break;

					case SDLK_LEFT:
						std::cout << "key left_arrow was pressed" << std::endl;
						break;

					case SDLK_UP:
						std::cout << "key up_arrow was pressed" << std::endl;
						break;

					case SDLK_DOWN:
						std::cout << "key down_arrow was pressed" << std::endl;
						break;
				}
			}
			else if(event.type == SDL_KEYUP)
			{
				switch(event.key.keysym.sym)
				{
					case SDLK_RIGHT:
						std::cout << "key right_arrow was released" << std::endl;
						r.x += 10;
						break;

					case SDLK_LEFT:
						std::cout << "key left_arrow was released" << std::endl;
						r.x -= 10;
						break;

					case SDLK_UP:
						std::cout << "key up_arrow was released" << std::endl;
						r.y -= 10;
						break;

					case SDLK_DOWN:
						std::cout << "key down_arrow was released" << std::endl;
						r.y += 10;
						break;
				}
			}
		}

		// Draw a rectange r
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderClear(renderer);

		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderFillRect(renderer, &r);

		SDL_RenderPresent(renderer);
		SDL_Delay(10);
	}

	return 0;
}