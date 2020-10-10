#include <iostream>

#include <pixel/pixel.hpp>
using namespace pixel;

int main() {
  Application app({.size = vu2d(500, 500), .name = "Lines",
  .on_launch = [] (Application& app) mutable -> pixel::rcode {
    app.CreateSprite("samples/test.png"); // This is relative to the directory you run the program from, watch out!

    return pixel::ok;
  },
  .on_update = [] (Application& app) mutable -> pixel::rcode {
    for (uint8_t i = 0; i < 50; i++) {
      app.DrawLine(
        vu2d(rand() % app.ScreenSize().x, rand() % app.ScreenSize().y),
				vu2d(rand() % app.ScreenSize().x, rand() % app.ScreenSize().y),
				RandPixel()
      );
    }

    app.DrawSprite(app.MousePos(), 0);

    if(app.KeyboardKey(Key::ESCAPE).pressed) {
			app.Close();
		}

    return pixel::ok;
  },
  .on_close = [] (Application& app) mutable -> pixel::rcode {
    return pixel::ok;
  }});

  app.Launch();

  return 0;
}