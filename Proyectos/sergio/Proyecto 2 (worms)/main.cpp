#include <bits/stdc++.h>
using namespace std;
#include "gfx.h"
#include "util.h"

int main() {
  int w = 500, h = 500;
  gfx_open(w, h, "Worms");
  gfx_clear();
  for (int i = 0; i < w; i++) {
    gfx_point(1, i);
    std::this_thread::sleep_for(std::chrono::seconds(1));
  }

  // while (true) {
  //   gfx_clear();
  //   for (int i = 0; i <= h; i++) {
  //     gfx_color(Util::random(0, 255), Util::random(0, 255), Util::random(0,
  //     255)); for (int j = 0; j <= w; j++) {
  //       gfx_point(j, j);
  //     }
  //   }
  //   gfx_flush();
  // 	std::this_thread::sleep_for(std::chrono::microseconds(1000000 / 100));
  // }
  return 0;
}