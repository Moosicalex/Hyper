#include <chrono>
#include <SDL2\SDL.h>
#include <iostream>
#include "Hyper.h"
#include "Window.h"

using namespace std::chrono_literals;
using namespace std;

// we use a fixed timestep of 1 / (60 fps) = 16 milliseconds
constexpr std::chrono::nanoseconds timestep(16ms);

struct game_state {
  // this contains the state of your game, such as positions and velocities
};

bool handle_events() {
  // poll for events

  return false; // true if the user wants to quit the game
}

void update(game_state *) {
  // update game logic here
}

void render(game_state const &) {
  // render stuff here
}

game_state interpolate(game_state const & current, game_state const & previous, float alpha) {
  game_state interpolated_state;

  // interpolate between previous and current by alpha here

  return interpolated_state;
}

int WinMain(int argc, char **argv) {
  //--TODO-- make this it's own thread I think? Maybe look at a few tutorials
  // just to see if that's the smartest way to handle the window
  SDL_Window * window = createWindow(argc, argv);
  SDL_Event windowEvent;

  using clock = std::chrono::high_resolution_clock;

  std::chrono::nanoseconds lag(0ns);
  auto time_start = clock::now();
  bool quit_game = false;

  game_state current_state;
  game_state previous_state;

  while(!quit_game) {
    auto delta_time = clock::now() - time_start;
    time_start = clock::now();
    lag += std::chrono::duration_cast<std::chrono::nanoseconds>(delta_time);

    quit_game = handle_events();

    // update game logic as lag permits
    while(lag >= timestep) {
      printf("inLoop\n");
      lag -= timestep;

      previous_state = current_state;
      update(&current_state); // update at a fixed rate each time

      //--TODO-- Move this to a loop in createWindow
      //break out of window if x is clicked
      if(SDL_PollEvent(&windowEvent))
      {
          if(SDL_QUIT == windowEvent.type)
          {
              break;
          }
      }
    }

    // calculate how close or far we are from the next timestep
    auto alpha = (float) lag.count() / timestep.count();
    auto interpolated_state = interpolate(current_state, previous_state, alpha);

    render(interpolated_state);
  }

  /* Frees memory */
  SDL_DestroyWindow(window);
  
  /* Shuts down all SDL subsystems */
  SDL_Quit(); 
  //should never get here
  return 1;
}